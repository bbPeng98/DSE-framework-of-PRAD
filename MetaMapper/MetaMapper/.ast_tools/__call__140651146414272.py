@name_outputs(out=Data)
def __call__(self, in1 : Data, in0 : Data) -> Data:
    mul_0 = Data32(in0) * Data32(in1)
    res_0 = mul_0 >> 8
    __0_return_0 = Data(res_0[0:16])
    return __0_return_0
