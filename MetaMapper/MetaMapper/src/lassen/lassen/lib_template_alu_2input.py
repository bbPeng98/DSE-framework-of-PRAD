from cgi import print_arguments
from select import PIPE_BUF
from sys import flags
from threading import local
from time import perf_counter
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
def my_ALU_fc(family):

    Data = family.BitVector[DATAWIDTH]
    Bit = family.Bit
    SInt = family.Signed
    SData = SInt[DATAWIDTH]
    UInt = family.Unsigned
    UData = UInt[DATAWIDTH]
    UData32 = UInt[32]

    DataPy = BitVector[DATAWIDTH]
    #BitPy = Bit[1]


    @family.assemble(locals(), globals(), set_port_names=True)
    class my_ALU(Peak):
        @name_outputs(res=Data, res_p=Bit, Z=Bit, N=Bit, C=Bit, V=Bit)
        def __call__(self, alu: Const(my_ALU_t), signed_: Const(Signed_t), a: DataPy, b: DataPy, d: BitPy) -> (DataPy, BitPy, BitPy, BitPy, BitPy, BitPy):
            
           
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
            
            # # CROP: min-max or max-min
            max_ab = gte_pred.ite(a, b)
            min_ab = lte_pred.ite(a, b)
            # if signed_ == Signed_t.signed:
            #     gte_c = SData(min_ab) >= SData(c)
            # else: #signed_ == Signed_t.unsigned:
            #     gte_c = UData(min_ab) >= UData(c)
            # crop_abc = gte_c.ite(min_ab, c)
            

            Cin = Bit(0)
            C = Bit(0)
            V = Bit(0)
            res, res_p = Data(0x5555), Bit(0)



