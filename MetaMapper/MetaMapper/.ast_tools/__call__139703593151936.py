@name_outputs(lut_out=Bit)
def __call__(self, lut: LUT_t, bit0: Bit, bit1: Bit) -> Bit:
    i_0 = IDX_t([bit0, bit1])
    i_1 = i_0.zext(2)
    __0_return_0 = ((lut >> i_1) & 1)[0]
    return __0_return_0
