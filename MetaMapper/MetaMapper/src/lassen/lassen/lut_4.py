from peak.peak import Peak
from peak.features import family_closure, name_outputs

@family_closure
def LUT4_t_fc(family):
    LUT_t = family.BitVector[16]
    IDX_t = family.BitVector[4]
    return LUT_t, IDX_t

@family_closure
def LUT4_fc(family):
    Bit = family.Bit
    LUT_t, IDX_t = LUT4_t_fc(family)

    @family.assemble(locals(), globals())
    class LUT4(Peak):
        @name_outputs(lut_out=Bit)
        def __call__(self, lut: LUT_t, bit0: Bit, bit1: Bit, bit2: Bit, bit3: Bit) -> Bit:
            i = IDX_t([bit0, bit1, bit2, bit3])
            i = i.zext(12)
            return ((lut >> i) & 1)[0]
    return LUT4
