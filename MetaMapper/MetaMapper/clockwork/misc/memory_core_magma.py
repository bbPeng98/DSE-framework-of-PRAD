import magma
import mantle
import collections
from canal.interconnect import Interconnect
from gemstone.common.configurable import ConfigurationType, \
    ConfigRegister, _generate_config_register
from gemstone.common.core import ConfigurableCore, CoreFeature, PnRTag
from gemstone.common.mux_wrapper import MuxWrapper
from gemstone.generator.const import Const
from gemstone.generator.from_magma import FromMagma
from gemstone.generator.from_verilog import FromVerilog
from memory_core import memory_core_genesis2
from typing import List
from lake.top.lake_top import LakeTop
from lake.passes.passes import change_sram_port_names
from lake.passes.passes import lift_config_reg
from lake.utils.sram_macro import SRAMMacroInfo
from lake.top.extract_tile_info import *
import math
import kratos as kts

ControllerInfo = collections.namedtuple('ControllerInfo',
                                        'dim extent cyc_stride data_stride cyc_strt data_strt')


def config_mem_tile(interconnect: Interconnect, full_cfg, new_config_data, x_place, y_place, mcore_cfg):
    for config_reg, val, feat in new_config_data:
        full_cfg.append((interconnect.get_config_addr(
                         mcore_cfg.get_reg_index(config_reg),
                         feat, x_place, y_place), val))


def chain_pass(interconnect: Interconnect):  # pragma: nocover
    for (x, y) in interconnect.tile_circuits:
        tile = interconnect.tile_circuits[(x, y)]
        tile_core = tile.core
        if isinstance(tile_core, MemCore):
            # lift ports up
            lift_mem_ports(tile, tile_core)

            previous_tile = interconnect.tile_circuits[(x, y - 1)]
            if not isinstance(previous_tile.core, MemCore):
                interconnect.wire(Const(0), tile.ports.chain_valid_in)
                interconnect.wire(Const(0), tile.ports.chain_data_in)
            else:
                interconnect.wire(previous_tile.ports.chain_valid_out,
                                  tile.ports.chain_valid_in)
                interconnect.wire(previous_tile.ports.chain_data_out,
                                  tile.ports.chain_data_in)


def transform_strides_and_ranges(ranges, strides, dimensionality):
    assert len(ranges) == len(strides), "Strides and ranges should be same length..."
    tform_ranges = [range_item - 2 for range_item in ranges[0:dimensionality]]
    range_sub_1 = [range_item - 1 for range_item in ranges]
    tform_strides = [strides[0]]
    offset = 0
    for i in range(dimensionality - 1):
        offset -= (range_sub_1[i] * strides[i])
        tform_strides.append(strides[i + 1] + offset)
    for j in range(len(ranges) - dimensionality):
        tform_strides.append(0)
        tform_ranges.append(0)
    return (tform_ranges, tform_strides)


def lift_mem_ports(tile, tile_core):  # pragma: nocover
    ports = ["chain_wen_in", "chain_valid_out", "chain_in", "chain_out"]
    for port in ports:
        lift_mem_core_ports(port, tile, tile_core)


def lift_mem_core_ports(port, tile, tile_core):  # pragma: nocover
    tile.add_port(port, tile_core.ports[port].base_type())
    tile.wire(tile.ports[port], tile_core.ports[port])


def get_pond(use_sram_stub=1):
    return MemCore(data_width=16,  # CGRA Params
                   mem_width=16,
                   mem_depth=32,
                   banks=1,
                   input_iterator_support=2,  # Addr Controllers
                   output_iterator_support=2,
                   input_config_width=16,
                   output_config_width=16,
                   interconnect_input_ports=2,  # Connection to int
                   interconnect_output_ports=2,
                   mem_input_ports=1,
                   mem_output_ports=1,
                   use_sram_stub=use_sram_stub,
                   read_delay=0,  # Cycle delay in read (SRAM vs Register File)
                   rw_same_cycle=True,  # Does the memory allow r+w in same cycle?
                   agg_height=0,
                   max_agg_schedule=16,
                   input_max_port_sched=16,
                   output_max_port_sched=16,
                   align_input=0,
                   max_line_length=128,
                   max_tb_height=1,
                   tb_range_max=1024,
                   tb_range_inner_max=16,
                   tb_sched_max=16,
                   max_tb_stride=15,
                   num_tb=0,
                   tb_iterator_support=2,
                   multiwrite=1,
                   max_prefetch=8,
                   config_data_width=32,
                   config_addr_width=8,
                   num_tiles=1,
                   remove_tb=True,
                   app_ctrl_depth_width=16,
                   fifo_mode=False,
                   add_clk_enable=True,
                   add_flush=True,
                   core_reset_pos=False,
                   stcl_valid_iter=4,
                   override_name="Pond")


class MemCore(ConfigurableCore):
    __circuit_cache = {}

    def __init__(self,
                 data_width=16,  # CGRA Params
                 mem_width=16,
                 mem_depth=256,
                 banks=1,
                 input_iterator_support=6,  # Addr Controllers
                 output_iterator_support=6,
                 input_config_width=16,
                 output_config_width=16,
                 interconnect_input_ports=1,  # Connection to int
                 interconnect_output_ports=1,
                 mem_input_ports=1,
                 mem_output_ports=1,
                 use_sram_stub=True,
                 sram_macro_info=SRAMMacroInfo(),
                 read_delay=1,  # Cycle delay in read (SRAM vs Register File)
                 rw_same_cycle=True,  # Does the memory allow r+w in same cycle?
                 agg_height=4,
                 tb_sched_max=16,
                 config_data_width=32,
                 config_addr_width=8,
                 num_tiles=1,
                 remove_tb=False,
                 fifo_mode=False,
                 add_clk_enable=True,
                 add_flush=True,
                 override_name=None):

        # name
        if override_name:
            self.__name = override_name + "Core"
            lake_name = override_name
        else:
            self.__name = "MemCore"
            lake_name = "LakeTop"

        super().__init__(config_addr_width, config_data_width)

        # Capture everything to the tile object
        self.data_width = data_width
        self.mem_width = mem_width
        self.mem_depth = mem_depth
        self.banks = banks
        self.fw_int = int(self.mem_width / self.data_width)
        self.input_iterator_support = input_iterator_support
        self.output_iterator_support = output_iterator_support
        self.input_config_width = input_config_width
        self.output_config_width = output_config_width
        self.interconnect_input_ports = interconnect_input_ports
        self.interconnect_output_ports = interconnect_output_ports
        self.mem_input_ports = mem_input_ports
        self.mem_output_ports = mem_output_ports
        self.use_sram_stub = use_sram_stub
        self.sram_macro_info = sram_macro_info
        self.read_delay = read_delay
        self.rw_same_cycle = rw_same_cycle
        self.agg_height = agg_height
        self.config_data_width = config_data_width
        self.config_addr_width = config_addr_width
        self.num_tiles = num_tiles
        self.remove_tb = remove_tb
        self.fifo_mode = fifo_mode
        self.add_clk_enable = add_clk_enable
        self.add_flush = add_flush
        # self.app_ctrl_depth_width = app_ctrl_depth_width
        # self.stcl_valid_iter = stcl_valid_iter

        # Typedefs for ease
        TData = magma.Bits[self.data_width]
        TBit = magma.Bits[1]

        self.__inputs = []
        self.__outputs = []

        # cache_key = (self.data_width, self.mem_width, self.mem_depth, self.banks,
        #              self.input_iterator_support, self.output_iterator_support,
        #              self.interconnect_input_ports, self.interconnect_output_ports,
        #              self.use_sram_stub, self.sram_macro_info, self.read_delay,
        #              self.rw_same_cycle, self.agg_height, self.max_agg_schedule,
        #              self.input_max_port_sched, self.output_max_port_sched,
        #              self.align_input, self.max_line_length, self.max_tb_height,
        #              self.tb_range_max, self.tb_sched_max, self.max_tb_stride,
        #              self.num_tb, self.tb_iterator_support, self.multiwrite,
        #              self.max_prefetch, self.config_data_width, self.config_addr_width,
        #              self.num_tiles, self.remove_tb, self.fifo_mode, self.stcl_valid_iter,
        #              self.add_clk_enable, self.add_flush, self.app_ctrl_depth_width)

        cache_key = (self.data_width, self.mem_width, self.mem_depth, self.banks,
                     self.input_iterator_support, self.output_iterator_support,
                     self.interconnect_input_ports, self.interconnect_output_ports,
                     self.use_sram_stub, self.sram_macro_info, self.read_delay,
                     self.rw_same_cycle, self.agg_height, self.config_data_width, self.config_addr_width,
                     self.num_tiles, self.remove_tb, self.fifo_mode,
                     self.add_clk_enable, self.add_flush)

        # Check for circuit caching
        if cache_key not in MemCore.__circuit_cache:

            # Instantiate core object here - will only use the object representation to
            # query for information. The circuit representation will be cached and retrieved
            # in the following steps.
            # lt_dut = LakeTop(data_width=self.data_width,
            #                  mem_width=self.mem_width,
            #                  mem_depth=self.mem_depth,
            #                  banks=self.banks,
            #                  input_iterator_support=self.input_iterator_support,
            #                  output_iterator_support=self.output_iterator_support,
            #                  input_config_width=self.input_config_width,
            #                  output_config_width=self.output_config_width,
            #                  interconnect_input_ports=self.interconnect_input_ports,
            #                  interconnect_output_ports=self.interconnect_output_ports,
            #                  use_sram_stub=self.use_sram_stub,
            #                  sram_macro_info=self.sram_macro_info,
            #                  read_delay=self.read_delay,
            #                  rw_same_cycle=self.rw_same_cycle,
            #                  agg_height=self.agg_height,
            #                  max_agg_schedule=self.max_agg_schedule,
            #                  input_max_port_sched=self.input_max_port_sched,
            #                  output_max_port_sched=self.output_max_port_sched,
            #                  align_input=self.align_input,
            #                  max_line_length=self.max_line_length,
            #                  max_tb_height=self.max_tb_height,
            #                  tb_range_max=self.tb_range_max,
            #                  tb_range_inner_max=self.tb_range_inner_max,
            #                  tb_sched_max=self.tb_sched_max,
            #                  max_tb_stride=self.max_tb_stride,
            #                  num_tb=self.num_tb,
            #                  tb_iterator_support=self.tb_iterator_support,
            #                  multiwrite=self.multiwrite,
            #                  max_prefetch=self.max_prefetch,
            #                  config_data_width=self.config_data_width,
            #                  config_addr_width=self.config_addr_width,
            #                  num_tiles=self.num_tiles,
            #                  app_ctrl_depth_width=self.app_ctrl_depth_width,
            #                  remove_tb=self.remove_tb,
            #                  fifo_mode=self.fifo_mode,
            #                  add_clk_enable=self.add_clk_enable,
            #                  add_flush=self.add_flush,
            #                  stcl_valid_iter=self.stcl_valid_iter)

            lt_dut = LakeTop(data_width=self.data_width,
                             mem_width=self.mem_width,
                             mem_depth=self.mem_depth,
                             banks=self.banks,
                             input_iterator_support=self.input_iterator_support,
                             output_iterator_support=self.output_iterator_support,
                             input_config_width=self.input_config_width,
                             output_config_width=self.output_config_width,
                             interconnect_input_ports=self.interconnect_input_ports,
                             interconnect_output_ports=self.interconnect_output_ports,
                             use_sram_stub=self.use_sram_stub,
                             sram_macro_info=self.sram_macro_info,
                             read_delay=self.read_delay,
                             rw_same_cycle=self.rw_same_cycle,
                             agg_height=self.agg_height,
                             config_data_width=self.config_data_width,
                             config_addr_width=self.config_addr_width,
                             num_tiles=self.num_tiles,
                             remove_tb=self.remove_tb,
                             fifo_mode=self.fifo_mode,
                             add_clk_enable=self.add_clk_enable,
                             add_flush=self.add_flush,
                             name=lake_name,
                             gen_addr=False)

            change_sram_port_pass = change_sram_port_names(use_sram_stub, sram_macro_info)
            circ = kts.util.to_magma(lt_dut,
                                     flatten_array=True,
                                     check_multiple_driver=False,
                                     optimize_if=False,
                                     check_flip_flop_always_ff=False,
                                     additional_passes={"change_sram_port": change_sram_port_pass})
            MemCore.__circuit_cache[cache_key] = (circ, lt_dut)
        else:
            circ, lt_dut = MemCore.__circuit_cache[cache_key]

        # Save as underlying circuit object
        self.underlying = FromMagma(circ)

        # Enumerate input and output ports
        # (clk and reset are assumed)
        core_interface = get_interface(lt_dut)
        cfgs = extract_top_config(lt_dut)
        assert len(cfgs) > 0, "No configs?"

        # We basically add in the configuration bus differently
        # than the other ports...
        skip_names = ["config_data_in",
                      "config_write",
                      "config_addr_in",
                      "config_data_out",
                      "config_read",
                      "config_en",
                      "clk_en"]

        # Create a list of signals that will be able to be
        # hardwired to a constant at runtime...
        control_signals = []
        # The rest of the signals to wire to the underlying representation...
        other_signals = []

        # for port_name, port_size, port_width, is_ctrl, port_dir, explicit_array in core_interface:
        for io_info in core_interface:
            if io_info.port_name in skip_names:
                continue
            ind_ports = io_info.port_width
            intf_type = TBit
            # For our purposes, an explicit array means the inner data HAS to be 16 bits
            if io_info.expl_arr:
                ind_ports = io_info.port_size[0]
                intf_type = TData
            dir_type = magma.In
            app_list = self.__inputs
            if io_info.port_dir == "PortDirection.Out":
                dir_type = magma.Out
                app_list = self.__outputs
            if ind_ports > 1:
                for i in range(ind_ports):
                    self.add_port(f"{io_info.port_name}_{i}", dir_type(intf_type))
                    app_list.append(self.ports[f"{io_info.port_name}_{i}"])
            else:
                self.add_port(io_info.port_name, dir_type(intf_type))
                app_list.append(self.ports[io_info.port_name])

            # classify each signal for wiring to underlying representation...
            if io_info.is_ctrl:
                control_signals.append((io_info.port_name, io_info.port_width))
            else:
                if ind_ports > 1:
                    for i in range(ind_ports):
                        other_signals.append((f"{io_info.port_name}_{i}",
                                              io_info.port_dir,
                                              io_info.expl_arr,
                                              i,
                                              io_info.port_name))
                else:
                    other_signals.append((io_info.port_name,
                                          io_info.port_dir,
                                          io_info.expl_arr,
                                          0,
                                          io_info.port_name))

        assert(len(self.__outputs) > 0)

        # We call clk_en stall at this level for legacy reasons????
        self.add_ports(
            stall=magma.In(TBit),
        )

        self.chain_idx_bits = max(1, kts.clog2(self.num_tiles))

        # put a 1-bit register and a mux to select the control signals
        for control_signal, width in control_signals:
            if width == 1:
                mux = MuxWrapper(2, 1, name=f"{control_signal}_sel")
                reg_value_name = f"{control_signal}_reg_value"
                reg_sel_name = f"{control_signal}_reg_sel"
                self.add_config(reg_value_name, 1)
                self.add_config(reg_sel_name, 1)
                self.wire(mux.ports.I[0], self.ports[control_signal])
                self.wire(mux.ports.I[1], self.registers[reg_value_name].ports.O)
                self.wire(mux.ports.S, self.registers[reg_sel_name].ports.O)
                # 0 is the default wire, which takes from the routing network
                self.wire(mux.ports.O[0], self.underlying.ports[control_signal][0])
            else:
                for i in range(width):
                    mux = MuxWrapper(2, 1, name=f"{control_signal}_{i}_sel")
                    reg_value_name = f"{control_signal}_{i}_reg_value"
                    reg_sel_name = f"{control_signal}_{i}_reg_sel"
                    self.add_config(reg_value_name, 1)
                    self.add_config(reg_sel_name, 1)
                    self.wire(mux.ports.I[0], self.ports[f"{control_signal}_{i}"])
                    self.wire(mux.ports.I[1], self.registers[reg_value_name].ports.O)
                    self.wire(mux.ports.S, self.registers[reg_sel_name].ports.O)
                    # 0 is the default wire, which takes from the routing network
                    self.wire(mux.ports.O[0], self.underlying.ports[control_signal][i])

        # Wire the other signals up...
        for pname, pdir, expl_arr, ind, uname in other_signals:
            # If we are in an explicit array moment, use the given wire name...
            if expl_arr is False:
                # And if not, use the index
                self.wire(self.ports[pname][0], self.underlying.ports[uname][ind])
            else:
                self.wire(self.ports[pname], self.underlying.ports[pname])

        # CLK, RESET, and STALL PER STANDARD PROCEDURE

        # Need to invert this
        self.resetInverter = FromMagma(mantle.DefineInvert(1))
        self.wire(self.resetInverter.ports.I[0], self.ports.reset)
        self.wire(self.resetInverter.ports.O[0], self.underlying.ports.rst_n)
        self.wire(self.ports.clk, self.underlying.ports.clk)

        # Mem core uses clk_en (essentially active low stall)
        self.stallInverter = FromMagma(mantle.DefineInvert(1))
        self.wire(self.stallInverter.ports.I, self.ports.stall)
        self.wire(self.stallInverter.ports.O[0], self.underlying.ports.clk_en[0])

        # we have six? features in total
        # 0:    TILE
        # 1:    TILE
        # 1-4:  SMEM
        # Feature 0: Tile
        self.__features: List[CoreFeature] = [self]
        # Features 1-4: SRAM
        self.num_sram_features = lt_dut.total_sets
        for sram_index in range(self.num_sram_features):
            core_feature = CoreFeature(self, sram_index + 1)
            self.__features.append(core_feature)

        # Wire the config
        for idx, core_feature in enumerate(self.__features):
            if(idx > 0):
                self.add_port(f"config_{idx}",
                              magma.In(ConfigurationType(self.config_addr_width, self.config_data_width)))
                # port aliasing
                core_feature.ports["config"] = self.ports[f"config_{idx}"]
        self.add_port("config", magma.In(ConfigurationType(self.config_addr_width, self.config_data_width)))

        # or the signal up
        t = ConfigurationType(self.config_addr_width, self.config_data_width)
        t_names = ["config_addr", "config_data"]
        or_gates = {}
        for t_name in t_names:
            port_type = t[t_name]
            or_gate = FromMagma(mantle.DefineOr(len(self.__features),
                                                len(port_type)))
            or_gate.instance_name = f"OR_{t_name}_FEATURE"
            for idx, core_feature in enumerate(self.__features):
                self.wire(or_gate.ports[f"I{idx}"],
                          core_feature.ports.config[t_name])
            or_gates[t_name] = or_gate

        self.wire(or_gates["config_addr"].ports.O,
                  self.underlying.ports.config_addr_in[0:self.config_addr_width])
        self.wire(or_gates["config_data"].ports.O,
                  self.underlying.ports.config_data_in)

        # read data out
        for idx, core_feature in enumerate(self.__features):
            if(idx > 0):
                # self.add_port(f"read_config_data_{idx}",
                self.add_port(f"read_config_data_{idx}",
                              magma.Out(magma.Bits[self.config_data_width]))
                # port aliasing
                core_feature.ports["read_config_data"] = \
                    self.ports[f"read_config_data_{idx}"]

        # MEM Config
        configurations = []
        # merged_configs = []
        skip_cfgs = []

        for cfg_info in cfgs:
            if cfg_info.port_name in skip_cfgs:
                continue
            if cfg_info.expl_arr:
                if cfg_info.port_size[0] > 1:
                    for i in range(cfg_info.port_size[0]):
                        configurations.append((f"{cfg_info.port_name}_{i}", cfg_info.port_width))
                else:
                    configurations.append((cfg_info.port_name, cfg_info.port_width))
            else:
                configurations.append((cfg_info.port_name, cfg_info.port_width))

        # Do all the stuff for the main config
        main_feature = self.__features[0]
        for config_reg_name, width in configurations:
            main_feature.add_config(config_reg_name, width)
            if(width == 1):
                self.wire(main_feature.registers[config_reg_name].ports.O[0],
                          self.underlying.ports[config_reg_name][0])
            else:
                self.wire(main_feature.registers[config_reg_name].ports.O,
                          self.underlying.ports[config_reg_name])

        # SRAM
        # These should also account for num features
        # or_all_cfg_rd = FromMagma(mantle.DefineOr(4, 1))
        or_all_cfg_rd = FromMagma(mantle.DefineOr(self.num_sram_features, 1))
        or_all_cfg_rd.instance_name = f"OR_CONFIG_WR_SRAM"
        or_all_cfg_wr = FromMagma(mantle.DefineOr(self.num_sram_features, 1))
        or_all_cfg_wr.instance_name = f"OR_CONFIG_RD_SRAM"
        for sram_index in range(self.num_sram_features):
            core_feature = self.__features[sram_index + 1]
            self.add_port(f"config_en_{sram_index}", magma.In(magma.Bit))
            # port aliasing
            core_feature.ports["config_en"] = \
                self.ports[f"config_en_{sram_index}"]
            # Sort of a temp hack - the name is just config_data_out
            if self.num_sram_features == 1:
                self.wire(core_feature.ports.read_config_data,
                          self.underlying.ports["config_data_out"])
            else:
                self.wire(core_feature.ports.read_config_data,
                          self.underlying.ports[f"config_data_out_{sram_index}"])
            # also need to wire the sram signal
            # the config enable is the OR of the rd+wr
            or_gate_en = FromMagma(mantle.DefineOr(2, 1))
            or_gate_en.instance_name = f"OR_CONFIG_EN_SRAM_{sram_index}"

            self.wire(or_gate_en.ports.I0, core_feature.ports.config.write)
            self.wire(or_gate_en.ports.I1, core_feature.ports.config.read)
            self.wire(core_feature.ports.config_en,
                      self.underlying.ports["config_en"][sram_index])
            # Still connect to the OR of all the config rd/wr
            self.wire(core_feature.ports.config.write,
                      or_all_cfg_wr.ports[f"I{sram_index}"])
            self.wire(core_feature.ports.config.read,
                      or_all_cfg_rd.ports[f"I{sram_index}"])

        self.wire(or_all_cfg_rd.ports.O[0], self.underlying.ports.config_read[0])
        self.wire(or_all_cfg_wr.ports.O[0], self.underlying.ports.config_write[0])
        self._setup_config()

        conf_names = list(self.registers.keys())
        conf_names.sort()
        with open("mem_cfg.txt", "w+") as cfg_dump:
            for idx, reg in enumerate(conf_names):
                write_line = f"(\"{reg}\", 0),  # {self.registers[reg].width}\n"
                cfg_dump.write(write_line)
        with open("mem_synth.txt", "w+") as cfg_dump:
            for idx, reg in enumerate(conf_names):
                write_line = f"{reg}\n"
                cfg_dump.write(write_line)

    def get_reg_index(self, register_name):
        conf_names = list(self.registers.keys())
        conf_names.sort()
        idx = conf_names.index(register_name)
        return idx

    def get_config_bitstream(self, instr):
        configs = []
        if "content" in instr:
            # this is SRAM content
            content = instr["content"]
            for addr, data in enumerate(content):
                if (not isinstance(data, int)) and len(data) == 2:
                    addr, data = data
                feat_addr = addr // 256 + 1
                addr = (addr % 256) >> 2
                configs.append((addr, feat_addr, data))

        # unified buffer buffer stuff
        if "is_ub" in instr and instr["is_ub"]:
            depth = instr["range_0"]
            instr["depth"] = depth
            print("configure ub to have depth", depth)
        if "depth" in instr:
            print("configuring unified buffer", instr)
            # unified buffer
            # configure as row buffer
            depth = int(instr["depth"])
            config_mem = [("strg_ub_app_ctrl_input_port_0", 0),
                          ("strg_ub_app_ctrl_read_depth_0", depth),
                          ("strg_ub_app_ctrl_write_depth_wo_0", depth),
                          ("strg_ub_app_ctrl_write_depth_ss_0", depth),
                          ("enable_chain_input", 0),
                          ("enable_chain_output", 0),
                          ("strg_ub_app_ctrl_coarse_input_port_0", 0),
                          ("strg_ub_app_ctrl_coarse_read_depth_0", 8),
                          ("strg_ub_app_ctrl_coarse_write_depth_wo_0", 8),
                          ("strg_ub_app_ctrl_coarse_write_depth_ss_0", 8),
                          ("strg_ub_input_addr_ctrl_address_gen_0_dimensionality", 2),
                          ("strg_ub_input_addr_ctrl_address_gen_0_ranges_0", 512),
                          ("strg_ub_input_addr_ctrl_address_gen_0_ranges_1", 512),
                          ("strg_ub_input_addr_ctrl_address_gen_0_starting_addr", 0),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_0", 1),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_1", 512),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_2", 0),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_3", 0),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_4", 0),
                          ("strg_ub_input_addr_ctrl_address_gen_0_strides_5", 0),
                          ("strg_ub_output_addr_ctrl_address_gen_0_dimensionality", 2),
                          ("strg_ub_output_addr_ctrl_address_gen_0_ranges_0", 512),
                          ("strg_ub_output_addr_ctrl_address_gen_0_ranges_1", 512),
                          ("strg_ub_output_addr_ctrl_address_gen_0_starting_addr", 0),
                          ("strg_ub_output_addr_ctrl_address_gen_0_strides_0", 1),
                          ("strg_ub_output_addr_ctrl_address_gen_0_strides_1", 512),
                          ("strg_ub_sync_grp_sync_group_0", 1),
                          ("strg_ub_tba_0_tb_0_range_outer", depth),
                          ("strg_ub_tba_0_tb_0_starting_addr", 0),
                          ("strg_ub_tba_0_tb_0_stride", 1),
                          ("strg_ub_tba_0_tb_0_dimensionality", 1),
                          ("strg_ub_agg_align_0_line_length", depth),
                          ("strg_ub_tba_0_tb_0_indices_0", 0),
                          ("strg_ub_tba_0_tb_0_indices_1", 1),
                          ("strg_ub_tba_0_tb_0_indices_2", 2),
                          ("strg_ub_tba_0_tb_0_indices_3", 3),
                          ("strg_ub_tba_0_tb_0_range_inner", 4),
                          ("strg_ub_tba_0_tb_0_tb_height", 1),
                          ("strg_ub_rate_matched_0", 1),
                          ("tile_en", 1),
                          ("mode", 0)]
            config_mem += [("strg_ub_pre_fetch_0_input_latency", 2)]
            if "is_ub" in instr and instr["is_ub"]:
                stencil_width = int(instr["stencil_width"])
                config_mem += [("strg_ub_app_ctrl_ranges_0", depth),
                               ("strg_ub_app_ctrl_threshold_0", stencil_width - 1)]
            for name, v in config_mem:
                configs += [(self.get_reg_index(name), v)]
            # gate config signals
            conf_names = ["chain_valid_in_0_reg_sel", "chain_valid_in_1_reg_sel",
                          "wen_in_1_reg_sel"]
            for conf_name in conf_names:
                configs += [(self.get_reg_index(conf_name), 1)]
        else:
            config_mem = [("tile_en", 1),
                          ("mode", 0)]
            # for now config it as sram
            # config_mem = [("tile_en", 1),
                          # ("mode", 2),
                          # ("wen_in_0_reg_sel", 1),
                          # ("wen_in_1_reg_sel", 1)]
            for name, v in config_mem:
                configs = [(self.get_reg_index(name), v)] + configs
        print(configs)
        return configs

    def search_for_config(self, cfg_file, key):
        lines = cfg_file
        matches = [l for l in lines if key in l]
        return int(matches[0].split(',')[1])

    def extract_controller(self, file_path):
        file_lines = None
        with open(file_path) as ctrl_f:
            file_lines = ctrl_f.readlines()
        dim = self.search_for_config(file_lines, 'dimensionality')
        cyc_strt = self.search_for_config(file_lines, 'cycle_starting_addr')
        data_strt = self.search_for_config(file_lines, 'data_starting_addr')
        ranges = []
        cyc_strides = []
        data_strides = []
        for i in range(dim):
            ranges.append(self.search_for_config(file_lines, f"extent_{i}"))
            cyc_strides.append(self.search_for_config(file_lines, f"cycle_stride_{i}"))
            data_strides.append(self.search_for_config(file_lines, f"data_stride_{i}"))
        ctrl_info = ControllerInfo(dim=dim,
                                   cyc_strt=cyc_strt,
                                   data_strt=data_strt,
                                   extent=ranges,
                                   cyc_stride=cyc_strides,
                                   data_stride=data_strides)
        return ctrl_info

    def map_controller(self, controller, name):
        ctrl_dim = controller.dim
        ctrl_ranges = controller.extent
        ctrl_cyc_strides = controller.cyc_stride
        ctrl_data_strides = controller.data_stride
        ctrl_cyc_strt = controller.cyc_strt
        ctrl_data_strt = controller.data_strt

        print(f"extracted controller for: {name}")
        print(f"dim: {ctrl_dim}")
        print(f"range: {ctrl_ranges}")
        print(f"sched stride: {ctrl_cyc_strides}")
        print(f"data stride: {ctrl_data_strides}")
        print(f"sched start: {ctrl_cyc_strt}")
        print(f"data start: {ctrl_data_strt}")

        # Now transforms ranges and strides
        (tform_extent, tform_cyc_strides) = transform_strides_and_ranges(ctrl_ranges, ctrl_cyc_strides, ctrl_dim)
        (tform_extent, tform_data_strides) = transform_strides_and_ranges(ctrl_ranges, ctrl_data_strides, ctrl_dim)

        # Basically give a starting margin for everything...
        garnet_delay = 59

        mapped_ctrl = ControllerInfo(dim=ctrl_dim,
                                     cyc_strt=ctrl_cyc_strt + garnet_delay,
                                     data_strt=ctrl_data_strt,
                                     extent=tform_extent,
                                     cyc_stride=tform_cyc_strides,
                                     data_stride=tform_data_strides)

        return mapped_ctrl

    def get_static_bitstream(self, config_path):

        write_path = config_path + "/in2buf.csv"
        read_path = config_path + "/buf2out.csv"

        write_cfg = self.extract_controller(write_path)
        read_cfg = self.extract_controller(read_path)

        wr_map = self.map_controller(write_cfg, "SRAM WRITES")
        rd_map = self.map_controller(read_cfg, "SRAM READS")

        # Set configuration...
        config_simple = [
            ("strg_ub_sram_read_loops_dimensionality", rd_map.dim),  # 4
            ("strg_ub_sram_read_addr_gen_starting_addr", rd_map.data_strt),  # 16
            ("strg_ub_sram_read_sched_gen_sched_addr_gen_starting_addr", rd_map.cyc_strt),  # 16
            ("strg_ub_sram_write_loops_dimensionality", wr_map.dim),  # 4
            ("strg_ub_sram_write_addr_gen_starting_addr", wr_map.data_strt),  # 16
            ("strg_ub_sram_write_sched_gen_sched_addr_gen_starting_addr", wr_map.cyc_strt),  # 16

            # Chaining
            ("chain_idx_input", 0),  # 1
            ("chain_idx_output", 0),  # 1
            ("enable_chain_input", 0),  # 1
            ("enable_chain_output", 0),  # 1
            ("chain_valid_in_reg_sel", 1),  # 1
            ("chain_valid_in_reg_value", 0),  # 1

            # Control Signals...
            ("flush_reg_sel", 1),  # 1
            ("flush_reg_value", 0),  # 1
            ("ren_in_reg_sel", 1),  # 1
            ("ren_in_reg_value", 0),  # 1
            ("wen_in_reg_sel", 1),  # 1
            ("wen_in_reg_value", 0),  # 1

            # Set the mode and activate the tile...
            ("mode", 0),  # 2
            ("tile_en", 1),  # 1
        ]

        for i in range(rd_map.dim):
            config_simple.append((f"strg_ub_sram_read_loops_ranges_{i}", rd_map.extent[i]))
            config_simple.append((f"strg_ub_sram_read_addr_gen_strides_{i}", rd_map.data_stride[i]))
            config_simple.append((f"strg_ub_sram_read_sched_gen_sched_addr_gen_strides_{i}", rd_map.cyc_stride[i]))

        for i in range(wr_map.dim):
            config_simple.append((f"strg_ub_sram_write_loops_ranges_{i}", wr_map.extent[i]))
            config_simple.append((f"strg_ub_sram_write_addr_gen_strides_{i}", wr_map.data_stride[i]))
            config_simple.append((f"strg_ub_sram_write_sched_gen_sched_addr_gen_strides_{i}", wr_map.cyc_stride[i]))

        return config_simple

    def instruction_type(self):
        raise NotImplementedError()  # pragma: nocover

    def inputs(self):
        return self.__inputs

    def outputs(self):
        return self.__outputs

    def features(self):
        return self.__features

    def name(self):
        return self.__name

    def pnr_info(self):
        return PnRTag("m", self.DEFAULT_PRIORITY - 1, self.DEFAULT_PRIORITY)


if __name__ == "__main__":
    mc = get_pond()
