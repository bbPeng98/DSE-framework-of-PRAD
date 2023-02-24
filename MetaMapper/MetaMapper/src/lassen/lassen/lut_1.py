from peak.peak import Peak
from peak.features import family_closure, name_outputs

@family_closure
def LUT1_t_fc(family):
    LUT_t = family.BitVector[2]
    IDX_t = family.BitVector[1]
    return LUT_t, IDX_t

@family_closure
def LUT1_fc(family):
    Bit = family.Bit
    LUT_t, IDX_t = LUT1_t_fc(family)

    @family.assemble(locals(), globals())
    class LUT1(Peak):
        @name_outputs(lut_out=Bit)
        def __call__(self, lut: LUT_t, bit0: Bit) -> Bit:
            i = IDX_t(bit0)
            i = i.zext(1)
            return ((lut >> i) & 1)[0]
    return LUT1

