@name_outputs(out=Data)
def __call__(self, in1: Data, in0: Data) -> Data:
    mul_0 = Data32(SInt(in0).sext(16)) * Data32(SInt(in1).sext(16))
    __0_return_0 = Data(mul_0[8:24])
    return __0_return_0
