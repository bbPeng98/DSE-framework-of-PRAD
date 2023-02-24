from peak.peak import Peak
from peak.features import family_closure, name_outputs

@family_closure
def LUT3_t_fc(family):
    LUT_t = family.BitVector[8]
    IDX_t = family.BitVector[3]
    return LUT_t, IDX_t

@family_closure
def LUT3_fc(family):
    Bit = family.Bit
    LUT_t, IDX_t = LUT3_t_fc(family)

    @family.assemble(locals(), globals())
    class LUT3(Peak):
        @name_outputs(lut_out=Bit)
        def __call__(self, lut: LUT_t, bit0: Bit, bit1: Bit, bit2: Bit) -> Bit:
            i = IDX_t([bit0, bit1, bit2])
            i = i.zext(5)
            return ((lut >> i) & 1)[0]
    return LUT3
