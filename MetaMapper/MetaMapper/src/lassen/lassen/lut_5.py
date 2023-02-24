from peak.peak import Peak
from peak.features import family_closure, name_outputs

@family_closure
def LUT5_t_fc(family):
    LUT_t = family.BitVector[32]
    IDX_t = family.BitVector[5]
    return LUT_t, IDX_t

@family_closure
def LUT5_fc(family):
    Bit = family.Bit
    LUT_t, IDX_t = LUT5_t_fc(family)

    @family.assemble(locals(), globals())
    class LUT5(Peak):
        @name_outputs(lut_out=Bit)
        def __call__(self, lut: LUT_t, bit0: Bit, bit1: Bit, bit2: Bit, bit3: Bit, bit4: Bit) -> Bit:
            i = IDX_t([bit0, bit1, bit2, bit3, bit4])
            i = i.zext(27)
            return ((lut >> i) & 1)[0]
    return LUT5

