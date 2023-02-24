from peak.peak import Peak,Const
from peak.features import family_closure, name_outputs
from lassen.common import *
from lassen.mode import gen_register_mode, gen_bit_mode
from lassen.lut import LUT_fc
from lassen.lut_1 import LUT1_fc
from lassen.lut_2 import LUT2_fc
from lassen.lut_3 import LUT3_fc
from lassen.lut_4 import LUT4_fc
from lassen.lut_5 import LUT5_fc
from lassen.lut_6 import LUT6_fc

#from .float.fpu import FPU_fc
#from .float.float_custom import FPCustom_fc
from lassen.cond import Cond_fc
from lassen.template_alu_3input import my_ALU_fc_3
from lassen.my_isa_3 import my_Inst_fc_3
from hwtypes import TypeFamily
from hwtypes import BitVector, Bit as BitPy
import os
import json

@family_closure
def my_PE_fc_3input(family: TypeFamily):
    dir_path = os.path.dirname(os.path.realpath(__file__))
    with open(f"{dir_path}/args.json") as f:
        lut_n = json.load(f).get("lut_n")
        #print(lut_n)
    # for lut_n in args.item
    # lut_n = lut_n.items()["lut_n"]

    #Hack
    def BV1(bit):
        return bit.ite(family.BitVector[1](1), family.BitVector[1](0))
    Data = family.BitVector[DATAWIDTH]
    Data8 = family.BitVector[8]
    Data32 = family.BitVector[32]
    Data48 = family.BitVector[48]
    Bit = family.Bit

    DataPy = BitVector[DATAWIDTH]
    Data8Py = BitVector[8]
    Data32Py = BitVector[32]
    Data48Py = BitVector[48]

    DataReg = gen_register_mode(DATAWIDTH, 0)(family)
    BitReg = gen_bit_mode(0)(family)


    ALU = my_ALU_fc_3(family)
    #FPU = FPU_fc(family)
    #FPCustom = FPCustom_fc(family)

    Cond = Cond_fc(family)

    # if lut_n == 1:
    #   LUT = LUT1_fc(family)
    # elif lut_n == 2:
    #   LUT = LUT2_fc(family)
    # elif lut_n == 3:
    #   LUT = LUT3_fc(family)
    # elif lut_n == 4:
    #   LUT = LUT4_fc(family)
    # elif lut_n == 5:
    #   LUT = LUT5_fc(family)
    # elif lut_n == 6:
    #   LUT = LUT6_fc(family)
    LUT = LUT3_fc(family)
    Inst = my_Inst_fc_3(family)
    #ALU_t_c = family.get_constructor(ALU_t)
    #FPU_t_c = family.get_constructor(FPU_t)
    #FPCustom_t_c = family.get_constructor(FPCustom_t) 

    @family.assemble(locals(), globals(), set_port_names=False)
    class my_PE_3input(Peak):
        def __init__(self):

            # Data registers
            self.rega: DataReg = DataReg()
            self.regb: DataReg = DataReg()
            self.regc: DataReg = DataReg()

            # Bit Registers
            # self.regd: BitReg = BitReg()
            # self.rege: BitReg = BitReg()
            # self.regf: BitReg = BitReg()
            # self.regg: BitReg = BitReg()
            # self.regh: BitReg = BitReg()
            # self.regi: BitReg = BitReg()

            self.regd: BitReg = BitReg()
            self.rege: BitReg = BitReg()
            self.regf: BitReg = BitReg()
            #Execution
            self.alu: ALU = ALU()
            #self.fpu: FPU = FPU()
            #self.fp_custom: FPCustom = FPCustom()

            #Lut
            self.lut: LUT = LUT()
            
            #Condition code
            self.cond: Cond = Cond()

        @name_outputs(res=DataPy, res_p=BitPy)
        def __call__(
            self,
            inst: Const(Inst),
            data0: DataPy,
            data1: DataPy = Data(0),
            data2: DataPy = Data(0),
            bit0: Bit = Bit(0), \
            bit1: Bit = Bit(0), \
            bit2: Bit = Bit(0), \
            clk_en: Global(BitPy) = Bit(1)
        ) -> (DataPy, BitPy):

      
            ra, ra_rdata = self.rega(inst.rega, inst.data0, data0, clk_en)
            rb, rb_rdata = self.regb(inst.regb, inst.data1, data1, clk_en)
            rc, rc_rdata = self.regc(inst.regc, inst.data2, data2, clk_en)

            #set default values to each of the op kinds
            #alu_op = ALU_t_c(ALU_t.Add)
            #fpu_op = FPU_t_c(FPU_t.FP_add)
            #fp_custom_op = FPCustom_t_c(FPCustom_t.FGetMant)
            #if inst.op.alu.match:
            #    alu_op = inst.op.alu.value
            #elif inst.op.fpu.match:
            #    fpu_op = inst.op.fpu.value
            #else: #inst.op.fp_custom.match:
            #    fp_custom_op = inst.op.fp_custom.value

            # calculate alu results
            #alu_res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rc, rd)

            #fpu_res, fpu_N, fpu_Z = self.fpu(fpu_op, ra, rb)

            #fpc_res, fpc_res_p, fpc_V = self.fp_custom(fp_custom_op, inst.signed, ra, rb)

            # Z = Bit(0)
            # N = Bit(0)
            # V = Bit(0)
            # res_p = Bit(0)
            # res = Data(0)
            # if inst.op.alu.match:
            #     Z = alu_Z
            #     N = alu_N
            #     V = alu_V
            #     res_p = alu_res_p
            #     res = alu_res
            # elif inst.op.fpu.match:
            #     N = fpu_N
            #     Z = fpu_Z
            #     res = fpu_res
            # else: #inst.op.fp_custom.match:
            #     V = fpc_V
            #     res_p = fpc_res_p
            #     res = fpc_res

            # calculate lut results
            rd, rd_rdata = self.regd(inst.regd, inst.bit0, bit0, clk_en)
            re, re_rdata = self.rege(inst.rege, inst.bit1, bit1, clk_en)
            rf, rf_rdata = self.regf(inst.regf, inst.bit2, bit2, clk_en)
            res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rc, rd)
            lut_res = self.lut(inst.lut, rd, re, rf)
            res_p = self.cond(inst.cond, alu_res_p, lut_res, Z, N, C, V)
            return res, res_p

    return my_PE_3input