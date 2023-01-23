@name_outputs(lut_out=Bit)
def __call__(self, lut: LUT_t, bit0: Bit) -> Bit:
    i_0 = IDX_t(bit0)
    i_1 = i_0.zext(1)
    __0_return_0 = ((lut >> i_1) & 1)[0]
    return __0_return_0
