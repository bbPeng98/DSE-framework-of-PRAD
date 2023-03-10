from peak import Peak, name_outputs, family_closure
# from .common import DATAWIDTH
import magma
from peak.family import AbstractFamily
from .isa import Signed_t

@family_closure
def LTE_fc(family : AbstractFamily):
    def LTE_bw(width):

        Data = family.BitVector[width]
        Bit = family.Bit
        UInt = family.Unsigned
        SInt = family.Signed
        UData = UInt[width]
        SData = SInt[width]

        @family.assemble(locals(), globals())
        class LTE(Peak):
            @name_outputs(res=Data, res_p=Bit, Z=Bit, N=Bit, C=Bit, V=Bit)
            def __call__(self, signed_: Signed_t, a: Data, b: Data) -> (Data, Bit, Bit, Bit, Bit, Bit):
                
                if signed_ == Signed_t.signed:
                    a_s = SData(a)
                    b_s = SData(b)
                    
                    lte_pred = a_s <= b_s

                else: #if signed_ == Signed_t.unsigned:
                    a_u = UData(a)
                    b_u = UData(b)
                    
                    lte_pred = a_u <= b_u

                res, res_p = lte_pred.ite(a, b), lte_pred
                V = Bit(0)
                C = Bit(0)
                N = Bit(res[-1])
                Z = (res == 0)

                return res, res_p, Z, N, C, V

        return LTE
    return LTE_bw
