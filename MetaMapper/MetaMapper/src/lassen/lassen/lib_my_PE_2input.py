from peak.peak import Peak,Const
from peak.features import family_closure, name_outputs
from functools import lru_cache
#import magma as m

from lassen.common import *
from lassen.mode import gen_register_mode, gen_bit_mode
from lassen.lut import LUT_fc
from lassen.lut_1 import LUT1_fc
from lassen.lut_2 import LUT2_fc
from lassen.lut_3 import LUT3_fc
from lassen.lut_4 import LUT4_fc
from lassen.lut_5 import LUT5_fc
from lassen.lut_6 import LUT6_fc
from lassen.template_alu_2input import my_ALU_fc
from lassen.cond import Cond_fc
from lassen.my_isa import my_Inst_fc
import json
import os

@family_closure
def my_PE_fc_2input(family):
    BitVector = family.BitVector
    dir_path = os.path.dirname(os.path.realpath(__file__))
    with open(f"{dir_path}/args.json") as f:
        lut_n = json.load(f).get("lut_n")
        #print(lut_n)

    #Hack
    def BV1(bit):
        return bit.ite(family.BitVector[1](1), family.BitVector[1](0))
    Data = family.BitVector[DATAWIDTH]
    UData = family.Unsigned[DATAWIDTH]
    Data8 = family.BitVector[8]
    Data32 = family.BitVector[32]
    Bit = family.Bit

    DataReg = gen_register_mode(DATAWIDTH, 0)(family)
    BitReg = gen_bit_mode(0)(family)

    ALU = my_ALU_fc(family)
    Cond = Cond_fc(family)
    # if lut_n == 1:
    #     LUT = LUT1_fc(family)
    # elif lut_n == 2:
    #     LUT = LUT2_fc(family)
    # elif lut_n == 3:
    #     LUT = LUT3_fc(family)
    # elif lut_n == 4:
    #     LUT = LUT4_fc(family)
    # elif lut_n == 5:
    #     LUT = LUT5_fc(family)
    # elif lut_n == 6:
    #     LUT = LUT6_fc(family)
    Inst = my_Inst_fc(family)

    @family.assemble(locals(), globals())
    class my_PE_2input(Peak):
        def __init__(self):

            # Data registers
            self.rega: DataReg = DataReg()
            self.regb: DataReg = DataReg()

            # Bit Registers
            # self.regd: BitReg = BitReg()
            # self.rege: BitReg = BitReg()
            # self.regf: BitReg = BitReg()
            # self.regg: BitReg = BitReg()
            # self.regh: BitReg = BitReg()
            # self.regi: BitReg = BitReg()
            #need generate bit registers

            #ALU
            self.alu: ALU = ALU()

            #Condition code
            self.cond: Cond = Cond()

            #Lut
            self.lut: LUT = LUT()

        @name_outputs(res=Data, res_p=Bit)
        def __call__(self, inst: Const(Inst), \
            data0: Data, data1: Data = Data(0), \
            clk_en: Global(Bit) = Bit(1), \
            config_addr : Data8 = Data8(0), \
            config_data : Data32 = Data32(0), \
            config_en : Bit = Bit(0) \
        ) -> (Data, Bit):
            # Simulate one clock cycle


            data0_addr = (config_addr[:3] == BitVector[3](DATA0_ADDR))
            data1_addr = (config_addr[:3] == BitVector[3](DATA1_ADDR))
            bit012_addr = (config_addr[:3] == BitVector[3](BIT012_ADDR))

            
            ra, ra_rdata = self.rega(inst.rega, inst.data0, data0, clk_en)
            rb, rb_rdata = self.regb(inst.regb, inst.data1, data1, clk_en)

            # rd, rd_rdata = self.regd(inst.regd, inst.bit0, bit0, clk_en)
            # re, re_rdata = self.rege(inst.rege, inst.bit1, bit1, clk_en)
            # rf, rf_rdata = self.regf(inst.regf, inst.bit2, bit2, clk_en)

            # #Calculate read_config_data
            # read_config_data = bit012_addr.ite(
            #     BV1(rd_rdata).concat(BV1(re_rdata)).concat(BV1(rf_rdata)).concat(BitVector[32-3](0)),
            #     ra_rdata.concat(rb_rdata)
            # )

            # calculate alu results
            # alu_res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rd)


