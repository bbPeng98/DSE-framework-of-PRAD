@name_outputs(res=Data, res_p=Bit, Z=Bit, N=Bit, C=Bit, V=Bit)
def __call__(self, alu: Const(my_ALU_t), signed_: Const(Signed_t), a: DataPy, b: DataPy, c: DataPy, d: BitPy) -> (DataPy, BitPy, BitPy, BitPy, BitPy, BitPy):
    _cond_0 = signed_ == Signed_t.signed
    a_s_0 = SData(a)
    b_s_0 = SData(b)
    mula_0, mulb_0 = UData32(a_s_0.sext(16)), UData32(b_s_0.sext(16))
    gte_pred_0 = a_s_0 >= b_s_0
    lte_pred_0 = a_s_0 <= b_s_0
    abs_pred_0 = a_s_0 >= SData(0)
    shr_0 = Data(a_s_0 >> b_s_0)
    a_u_0 = UData(a)
    b_u_0 = UData(b)
    mula_1, mulb_1 = a_u_0.zext(16), b_u_0.zext(16)
    gte_pred_1 = a_u_0 >= b_u_0
    lte_pred_1 = a_u_0 <= b_u_0
    abs_pred_1 = Bit(1) # a_u >= UData(0)
    shr_1 = Data(a_u_0 >> b_u_0)
    abs_pred_2 = __phi(_cond_0, abs_pred_0, abs_pred_1)
    gte_pred_2 = __phi(_cond_0, gte_pred_0, gte_pred_1)
    lte_pred_2 = __phi(_cond_0, lte_pred_0, lte_pred_1)
    mula_2 = __phi(_cond_0, mula_0, mula_1)
    mulb_2 = __phi(_cond_0, mulb_0, mulb_1)
    shr_2 = __phi(_cond_0, shr_0, shr_1)
    mul_0 = mula_2 * mulb_2

    # CROP: min-max or max-min
    max_ab_0 = gte_pred_2.ite(a, b)
    min_ab_0 = lte_pred_2.ite(a, b)
    _cond_1 = signed_ == Signed_t.signed
    gte_c_0 = SData(min_ab_0) >= SData(c)
    gte_c_1 = UData(min_ab_0) >= UData(c)
    gte_c_2 = __phi(_cond_1, gte_c_0, gte_c_1)
    crop_abc_0 = gte_c_2.ite(min_ab_0, c)


    Cin_0 = Bit(0)
    _cond_2 = signed_ == Signed_t.signed
    mulshift_0 = Data(SData(mul_0[:16]) >> SData(c))
    mulshift_1 = Data(UData(mul_0[:16]) >> UData(c))
    mulshift_2 = __phi(_cond_2, mulshift_0, mulshift_1)


    C_0 = Bit(0)
    V_0 = Bit(0)
    res_0, res_p_0 = Data(0x5555), Bit(0)     
    _cond_3 = (alu == my_ALU_t.TSA)
    b_0 = ~b
    Cin_1 = Bit(1)
    Cin_2 = __phi(_cond_3, Cin_1, Cin_0)
    b_1 = __phi(_cond_3, b_0, b)
    _cond_4 = (alu == my_ALU_t.TSS)
    b_2 = ~b_1
    Cin_3 = Bit(1)
    Cin_4 = __phi(_cond_4, Cin_3, Cin_2)
    b_3 = __phi(_cond_4, b_2, b_1)
    adder_res_0, adder_C_0 = UData(a).adc(UData(b_3), Cin_4)
    adder2_in0_0 = mul_0[:16]
    _cond_5 = (alu == my_ALU_t.TAA)
    adder2_in0_1 = adder_res_0
    adder2_in0_2 = __phi(_cond_5, adder2_in0_1, adder2_in0_0)
    _cond_6 = (alu == my_ALU_t.TAS)
    adder2_in0_3 = adder_res_0
    adder2_in0_4 = __phi(_cond_6, adder2_in0_3, adder2_in0_2)
    _cond_7 = (alu == my_ALU_t.TSA)
    adder2_in0_5 = adder_res_0
    adder2_in0_6 = __phi(_cond_7, adder2_in0_5, adder2_in0_4)
    _cond_8 = (alu == my_ALU_t.TSS)
    adder2_in0_7 = adder_res_0
    adder2_in0_8 = __phi(_cond_8, adder2_in0_7, adder2_in0_6)
    adder2_in1_0 = c
    Cin2_0 = Bit(0)
    _cond_9 = (alu == my_ALU_t.TAS)
    adder2_in1_1 = ~c
    Cin2_1 = Bit(1)
    Cin2_2 = __phi(_cond_9, Cin2_1, Cin2_0)
    adder2_in1_2 = __phi(_cond_9, adder2_in1_1, adder2_in1_0)
    _cond_10 = (alu == my_ALU_t.TSS)
    adder2_in1_3 = ~c
    Cin2_3 = Bit(1)
    Cin2_4 = __phi(_cond_10, Cin2_3, Cin2_2)
    adder2_in1_4 = __phi(_cond_10, adder2_in1_3, adder2_in1_2)
    adder2_res_0, adder2_C_0 = UData(adder2_in0_8).adc(adder2_in1_4, Cin2_4)
    _cond_11 = (alu == my_ALU_t.Add)
    res_1, C_1 = adder_res_0, adder_C_0
    V_1 = overflow(a, b_3, res_1)
    res_p_1 = C_1
    C_2 = __phi(_cond_11, C_1, C_0)
    V_2 = __phi(_cond_11, V_1, V_0)
    res_2 = __phi(_cond_11, res_1, res_0)
    res_p_2 = __phi(_cond_11, res_p_1, res_p_0)
    _cond_12 = (alu == my_ALU_t.MULADD)
    res_3, res_p_3 = adder2_res_0, Bit(0)
    res_4 = __phi(_cond_12, res_3, res_2)
    res_p_4 = __phi(_cond_12, res_p_3, res_p_2)
    _cond_13 = (alu == my_ALU_t.TAA)
    res_5, res_p_5 = adder2_res_0, Bit(0)
    res_6 = __phi(_cond_13, res_5, res_4)
    res_p_6 = __phi(_cond_13, res_p_5, res_p_4)
    _cond_14 = (alu == my_ALU_t.TSA)
    res_7, res_p_7 = adder2_res_0, Bit(0)
    res_8 = __phi(_cond_14, res_7, res_6)
    res_p_8 = __phi(_cond_14, res_p_7, res_p_6)
    _cond_15 = (alu == my_ALU_t.TAS)
    res_9, res_p_9 = adder2_res_0, Bit(0)
    res_10 = __phi(_cond_15, res_9, res_8)
    res_p_10 = __phi(_cond_15, res_p_9, res_p_8)
    _cond_16 = (alu == my_ALU_t.TSS)
    res_11, res_p_11 = adder2_res_0, Bit(0)
    res_12 = __phi(_cond_16, res_11, res_10)
    res_p_12 = __phi(_cond_16, res_p_11, res_p_10)
    N_0 = Bit(res_12[-1])
    Z_0 = (res_12 == SData(0))
    __0_return_0 = res_12, res_p_12, Z_0, N_0, C_2, V_2
    return __0_return_0
