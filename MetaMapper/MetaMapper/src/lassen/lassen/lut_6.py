from peak.peak import Peak
from peak.features import family_closure, name_outputs

@family_closure
def LUT6_t_fc(family):
    LUT_t = family.BitVector[64]
    IDX_t = family.BitVector[6]
    return LUT_t, IDX_t

@family_closure
def LUT6_fc(family):
    Bit = family.Bit
    LUT_t, IDX_t = LUT6_t_fc(family)

    @family.assemble(locals(), globals())
    class LUT6(Peak):
        @name_outputs(lut_out=Bit)
        def __call__(self, lut: LUT_t, bit0: Bit, bit1: Bit, bit2: Bit, bit3: Bit, bit4: Bit, bit5: Bit) -> Bit:
            i = IDX_t([bit0, bit1, bit2, bit3, bit4, bit5])
            i = i.zext(58)
            return ((lut >> i) & 1)[0]
    return LUT6

