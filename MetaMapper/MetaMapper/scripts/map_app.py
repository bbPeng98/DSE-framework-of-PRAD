import glob
import sys
import importlib
import os
import json
from pathlib import Path
import delegator
from lassen.sim import PE_fc as lassen_fc_org

from metamapper.irs.coreir import gen_CoreIRNodes
import metamapper.coreir_util as cutil
import metamapper.peak_util as putil
from metamapper.node import Nodes
from metamapper import CoreIRContext
from metamapper.coreir_mapper import Mapper
from metamapper.common_passes import print_dag, gen_dag_img, Constant2CoreIRConstant
from peak.mapper import read_serialized_bindings

class _ArchCycles:
    def get(self, node):
        kind = node.kind()[0]
        if kind == "Rom" or kind == "FPRom":
            return 1
        elif kind == "global.PE" or kind == "global.my_PE_2input" or kind == "global.my_PE_3input":
            return pe_cycles
        return 0

#lassen_location = os.path.join(Path(__file__).parent.parent.parent.resolve(), "lassen")
#lassen_header = os.path.join(Path(__file__).parent.parent.resolve(), "libs/lassen_header.json")
lassen_location = "/home/dai-dirk/MetaMapper/MetaMapper/src/lassen"
lassen_header = "/home/dai-dirk/MetaMapper/MetaMapper/libs/lassen_header.json"
print("lassen_location: " + lassen_location)
print("lassen_header: " + lassen_header)
def gen_rrules(has_3input,pipelined=False):

    from lassen.my_PE_2input import my_PE_fc_2input as lassen_fc 
    from lassen.my_PE_3input import my_PE_fc_3input as lassen_fc_3
    c = CoreIRContext()
    if(has_3input == 0):
        cmod = putil.peak_to_coreir(lassen_fc)
    elif(has_3input == 1):
        cmod = putil.peak_to_coreir(lassen_fc_3)
    elif(has_3input == 2):
        cmod = putil.peak_to_coreir(lassen_fc_org)

    c.serialize_header(lassen_header, [cmod])
    # c.serialize_definitions(pe_def, [cmod])
    mapping_funcs = []
    rrules = []
    ops = []

    if pipelined:
        rrule_files = glob.glob(f'{lassen_location}/lassen/rewrite_rules/*_pipelined.json')
    else:
        rrule_files = glob.glob(f'{lassen_location}/lassen/rewrite_rules/*.json')
        rrule_files = [rrule_file for rrule_file in rrule_files if "pipelined" not in rrule_file]
    #print("rrule_files: " )
    #print(rrule_files)
    custom_rule_names = {"mult_middle": "commonlib.mult_middle", "fp_exp": "float.exp", "fp_div": "float.div", "fp_mux": "float.mux", "fp_mul":"float_DW.fp_mul", "fp_add":"float_DW.fp_add", "fp_sub":"float.sub"}

    for idx, rrule in enumerate(rrule_files):
        rule_name = Path(rrule).stem
        if ("fp" in rule_name and "pipelined" in rule_name) or rule_name.split("_pipelined")[0] in custom_rule_names:
            rule_name = rule_name.split("_pipelined")[0]
        if rule_name in custom_rule_names:
            ops.append(custom_rule_names[rule_name])
        else:
            ops.append(rule_name)
        peak_eq = importlib.import_module(f"lassen.rewrite_rules.rewrite_rules_alu.{rule_name}")
        ir_fc = getattr(peak_eq, rule_name + "_fc")
        mapping_funcs.append(ir_fc)

        with open(rrule, "r") as json_file:
            #print("here-------------")
            #print(rrule)
            rewrite_rule_in = json.load(json_file)
            #print("here-------------")
        if(has_3input == 0):
            rewrite_rule = read_serialized_bindings(rewrite_rule_in, ir_fc, lassen_fc)
        elif(has_3input == 1):
            rewrite_rule = read_serialized_bindings(rewrite_rule_in, ir_fc, lassen_fc_3)
        elif(has_3input == 2):
            rewrite_rule = read_serialized_bindings(rewrite_rule_in, ir_fc, lassen_fc_org)
        if False:
            counter_example = rewrite_rule.verify()
            assert counter_example == None, f"{rule_name} failed"
        #print("haha-------------")
        rrules.append(rewrite_rule)

    return rrules, ops


dir_path = os.path.dirname(os.path.realpath(__file__))
with open(f"{dir_path}/../src/lassen/lassen/args.json") as f:
    has_3input = json.load(f).get("has_3input")


pe_reg_instrs = {}
pe_reg_instrs["const"] = 0
pe_reg_instrs["bypass"] = 2
pe_reg_instrs["reg"] = 3

pe_port_to_reg = {}
pe_port_to_reg["data0"] = "rega"
pe_port_to_reg["data1"] = "regb"
if(has_3input ): # has_3input
    pe_port_to_reg["data2"] = "regc"


pe_reg_info = {}
pe_reg_info['instrs'] = pe_reg_instrs
pe_reg_info['port_to_reg'] = pe_port_to_reg

file_name = str(sys.argv[1])
if len(sys.argv) > 2:
    pe_cycles = int(sys.argv[2])
else:
    pe_cycles = 0

rrules, ops = gen_rrules(has_3input,pipelined = pe_cycles != 0)
verilog = False
app = os.path.basename(file_name).split(".json")[0]
output_dir = os.path.dirname(file_name)

c = CoreIRContext(reset=True)
cutil.load_libs(["float","commonlib","float_DW"])
CoreIRNodes = gen_CoreIRNodes(16)
# print(CoreIRNodes.coreir_modules)
# print(CoreIRNodes.dag_nodes)
cutil.load_from_json(file_name) #libraries=["lakelib"])
kernels = dict(c.global_namespace.modules)


ArchNodes = Nodes("Arch")
from lassen.my_PE_2input import my_PE_fc_2input as lassen_fc 
from lassen.my_PE_3input import my_PE_fc_3input as lassen_fc_3
if(has_3input == 1):
    putil.load_and_link_peak(
    ArchNodes,
    lassen_header,
    {"global.my_PE_3input": lassen_fc_3}
    )
elif has_3input == 0:  
    putil.load_and_link_peak(
    ArchNodes,
    lassen_header,
    {"global.my_PE_2input": lassen_fc}
    )
elif has_3input == 2:
    putil.load_and_link_peak(
    ArchNodes,
    lassen_header,
    {"global.PE": lassen_fc_org}
    )
# putil.load_and_link_peak(
#     ArchNodes,
#     lassen_header,
#     {"global.my_PE_3input": lassen_fc_3}
# )

mr = "memory.fprom2"
ArchNodes.add(mr, CoreIRNodes.peak_nodes[mr], CoreIRNodes.coreir_modules[mr], CoreIRNodes.dag_nodes[mr])

mapper = Mapper(CoreIRNodes, ArchNodes, lazy=False, ops = ops, rrules=rrules)

c.run_passes(["rungenerators", "deletedeadinstances"])
mods = []

for kname, kmod in kernels.items():
    print(f"Mapping kernel {kname}")
    dag = cutil.coreir_to_dag(CoreIRNodes, kmod, archnodes=ArchNodes)
    Constant2CoreIRConstant(CoreIRNodes).run(dag)

    mapped_dag = mapper.do_mapping(dag, kname=kname, node_cycles=_ArchCycles(), convert_unbound=False, prove_mapping=False, pe_reg_info=pe_reg_info)
    mod = cutil.dag_to_coreir(ArchNodes, mapped_dag, f"{kname}_mapped", convert_unbounds=verilog)
    mods.append(mod)

print(f"Total num PEs used: {mapper.num_pes}")
output_file = f"{output_dir}/{app}_mapped.json"
print(f"saving to {output_file}")
c.serialize_definitions(output_file, mods)

with open(f'{output_dir}/{app}_kernel_latencies.json', 'w') as outfile:
    json.dump(mapper.kernel_cycles, outfile)


