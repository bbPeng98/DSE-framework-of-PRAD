from peak import Peak, name_outputs, family_closure, Const
from peak.mapper.utils import rebind_type
from .common import DATAWIDTH, BFloat16_fc
from .my_alu import my_ALU_t
from hwtypes.adt import Enum
from hwtypes import BitVector, Bit as BitPy
# simulate the PE ALU
#
#   inputs
#
#   alu is the ALU operations
#   signed is whether the inputs are unsigned or signed
#   a, b - 16-bit operands
#   d - 1-bit operatnd
#
#
#   returns res, res_p, Z, N, C, V
#
#   res - 16-bit result
#   res_p - 1-bit result
#   Z (result is 0)
#   N (result is negative)
#   C (carry generated)
#   V (overflow generated)

"""
Whether the operation is unsigned (0) or signed (1)
"""
class Signed_t(Enum):
    unsigned = 0
    signed = 1

def overflow(a, b, res):
    msb_a = a[-1]
    msb_b = b[-1]
    N = res[-1]
    return (msb_a & msb_b & ~N) | (~msb_a & ~msb_b & N)

@family_closure
def my_ALU_fc_3(family):

    Data = family.BitVector[DATAWIDTH]
    Bit = family.Bit
    SInt = family.Signed
    SData = SInt[DATAWIDTH]
    UInt = family.Unsigned
    UData = UInt[DATAWIDTH]
    UData32 = UInt[32]

    DataPy = BitVector[DATAWIDTH]


    @family.assemble(locals(), globals(), set_port_names=True)
    class my_ALU_3(Peak):
        @name_outputs(res=Data, res_p=Bit, Z=Bit, N=Bit, C=Bit, V=Bit)
        def __call__(self, alu: Const(my_ALU_t), signed_: Const(Signed_t), a: DataPy, b: DataPy, c: DataPy, d: BitPy) -> (DataPy, BitPy, BitPy, BitPy, BitPy, BitPy):
            if signed_ == Signed_t.signed:
                a_s = SData(a)
                b_s = SData(b)
                mula, mulb = UData32(a_s.sext(16)), UData32(b_s.sext(16))
                gte_pred = a_s >= b_s
                lte_pred = a_s <= b_s
                abs_pred = a_s >= SData(0)
                shr = Data(a_s >> b_s)
            else: #signed_ == Signed_t.unsigned:
                a_u = UData(a)
                b_u = UData(b)
                mula, mulb = a_u.zext(16), b_u.zext(16)
                gte_pred = a_u >= b_u
                lte_pred = a_u <= b_u
                abs_pred = Bit(1) # a_u >= UData(0)
                shr = Data(a_u >> b_u)
            mul = mula * mulb
            
            # CROP: min-max or max-min
            max_ab = gte_pred.ite(a, b)
            min_ab = lte_pred.ite(a, b)
            if signed_ == Signed_t.signed:
                gte_c = SData(min_ab) >= SData(c)
            else: #signed_ == Signed_t.unsigned:
                gte_c = UData(min_ab) >= UData(c)
            crop_abc = gte_c.ite(min_ab, c)
            

            Cin = Bit(0)
       


            # second adder
            # 1st input

          
            # 2nd input
            
    

            # mulshift
            if signed_ == Signed_t.signed:
                mulshift = Data(SData(mul[:16]) >> SData(c))
            else: #signed_ == Signed_t.unsigned:
                mulshift = Data(UData(mul[:16]) >> UData(c))
            

            C = Bit(0)
            V = Bit(0)
            res, res_p = Data(0x5555), Bit(0)     

            if(alu == my_ALU_t.Sub):
                b = ~b 
                Cin = Bit(1)

            if(alu == my_ALU_t.Sbc):
                b = ~b 
                Cin = d

            if(alu == my_ALU_t.Adc):
                Cin = d

            if(alu == my_ALU_t.TSA):
                b = ~b
                Cin = Bit(1)
            if(alu == my_ALU_t.TSS):
                b = ~b
                Cin = Bit(1)
            adder_res, adder_C = UData(a).adc(UData(b), Cin)
            adder2_in0 = mul[:16]
            if(alu == my_ALU_t.TAA):
                adder2_in0 = adder_res
            if(alu == my_ALU_t.TAS):
                adder2_in0 = adder_res
            if(alu == my_ALU_t.TSA):
                adder2_in0 = adder_res
            if(alu == my_ALU_t.TSS):
                adder2_in0 = adder_res
            adder2_in1 = c
            Cin2 = Bit(0)
            if(alu == my_ALU_t.MULSUB):
                adder2_in1 = ~c
                Cin2 = Bit(1)
            if(alu == my_ALU_t.TAS):
                adder2_in1 = ~c
                Cin2 = Bit(1)
            if(alu == my_ALU_t.TSS):
                adder2_in1 = ~c
                Cin2 = Bit(1)
            adder2_res, adder2_C = UData(adder2_in0).adc(adder2_in1, Cin2)
            if(alu == my_ALU_t.Add):
                res, C = adder_res, adder_C
                V = overflow(a, b, res)
                res_p = C
            if(alu == my_ALU_t.Sub):
                res, C = adder_res, adder_C
                V = overflow(a, b, res)
                res_p = C
            if(alu == my_ALU_t.Adc):
                res, C = adder_res, adder_C
                V = overflow(a, b, res)
                res_p = C
            if(alu == my_ALU_t.Sbc):
                res, C = adder_res, adder_C
                V = overflow(a, b, res)
                res_p = C
            if(alu == my_ALU_t.Mult0):
                res, C, V = mul[:16], Bit(0), Bit(0)  # wrong C, V
                res_p = C
            if(alu == my_ALU_t.Mult1):
                res, C, V = mul[8:24], Bit(0), Bit(0)  # wrong C, V
                res_p = C
            if(alu == my_ALU_t.Mult2):
                res, C, V = mul[16:32], Bit(0), Bit(0)  # wrong C, V
                res_p = C
            if(alu == my_ALU_t.GTE_Max):
                res, res_p = max_ab, gte_pred
            if(alu == my_ALU_t.LTE_Min):
                res, res_p = min_ab, lte_pred
            if(alu == my_ALU_t.Abs):
                res, res_p = abs_pred.ite(a, UInt[16](-SInt[16](a))), Bit(a[-1])
            if(alu == my_ALU_t.Sel):
                res, res_p = d.ite(a, b), Bit(0)
            if(alu == my_ALU_t.And):
                res, res_p = a & b, Bit(0)
            if(alu == my_ALU_t.Or):
                res, res_p = a | b, Bit(0)
            if(alu == my_ALU_t.XOr):
                res, res_p = a ^ b, Bit(0)
            if(alu == my_ALU_t.SHR):
                res, res_p = shr, Bit(0)
            if(alu == my_ALU_t.SHL):
                res, res_p = a << b, Bit(0)
            if(alu == my_ALU_t.MULADD):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.MULSUB):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.TAA):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.TSA):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.TAS):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.TSS):
                res, res_p = adder2_res, Bit(0)
            if(alu == my_ALU_t.CROP):
                res, res_p = crop_abc, Bit(0)
            if(alu == my_ALU_t.MULSHR):
                res, res_p = mulshift, Bit(0)
            N = Bit(res[-1])
            Z = (res == SData(0))
            return res, res_p, Z, N, C, V
    return my_ALU_3
