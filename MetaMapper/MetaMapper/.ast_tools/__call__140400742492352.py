@name_outputs(res=Data, res_p=Bit, Z=Bit, N=Bit, C=Bit, V=Bit)
def __call__(self, alu: Const(my_ALU_t), signed_: Const(Signed_t), a: DataPy, b: DataPy, d: BitPy) -> (DataPy, BitPy, BitPy, BitPy, BitPy, BitPy):
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

    # # CROP: min-max or max-min
    max_ab_0 = gte_pred_2.ite(a, b)
    min_ab_0 = lte_pred_2.ite(a, b)
    # if signed_ == Signed_t.signed:
    #     gte_c = SData(min_ab) >= SData(c)
    # else: #signed_ == Signed_t.unsigned:
    #     gte_c = UData(min_ab) >= UData(c)
    # crop_abc = gte_c.ite(min_ab, c)


    Cin_0 = Bit(0)
    C_0 = Bit(0)
    V_0 = Bit(0)
    res_0, res_p_0 = Data(0x5555), Bit(0)
    _cond_1 = (alu == my_ALU_t.Sub)
    b_0 = ~b 
    Cin_1 = Bit(1)
    Cin_2 = __phi(_cond_1, Cin_1, Cin_0)
    b_1 = __phi(_cond_1, b_0, b)
    _cond_2 = (alu == my_ALU_t.Sbc)
    b_2 = ~b_1 
    Cin_3 = d
    Cin_4 = __phi(_cond_2, Cin_3, Cin_2)
    b_3 = __phi(_cond_2, b_2, b_1)
    _cond_3 = (alu == my_ALU_t.Adc)
    Cin_5 = d
    Cin_6 = __phi(_cond_3, Cin_5, Cin_4)

    adder_res_0, adder_C_0 = UData(a).adc(UData(b_3), Cin_6)
    _cond_4 = (alu == my_ALU_t.Add)
    res_1, C_1 = adder_res_0, adder_C_0
    V_1 = overflow(a, b_3, res_1)
    res_p_1 = C_1
    C_2 = __phi(_cond_4, C_1, C_0)
    V_2 = __phi(_cond_4, V_1, V_0)
    res_2 = __phi(_cond_4, res_1, res_0)
    res_p_2 = __phi(_cond_4, res_p_1, res_p_0)
    _cond_5 = (alu == my_ALU_t.Sub)
    res_3, C_3 = adder_res_0, adder_C_0
    V_3 = overflow(a, b_3, res_3)
    res_p_3 = C_3
    C_4 = __phi(_cond_5, C_3, C_2)
    V_4 = __phi(_cond_5, V_3, V_2)
    res_4 = __phi(_cond_5, res_3, res_2)
    res_p_4 = __phi(_cond_5, res_p_3, res_p_2)
    _cond_6 = (alu == my_ALU_t.Adc)
    res_5, C_5 = adder_res_0, adder_C_0
    V_5 = overflow(a, b_3, res_5)
    res_p_5 = C_5
    C_6 = __phi(_cond_6, C_5, C_4)
    V_6 = __phi(_cond_6, V_5, V_4)
    res_6 = __phi(_cond_6, res_5, res_4)
    res_p_6 = __phi(_cond_6, res_p_5, res_p_4)
    _cond_7 = (alu == my_ALU_t.Sbc)
    res_7, C_7 = adder_res_0, adder_C_0
    V_7 = overflow(a, b_3, res_7)
    res_p_7 = C_7
    C_8 = __phi(_cond_7, C_7, C_6)
    V_8 = __phi(_cond_7, V_7, V_6)
    res_8 = __phi(_cond_7, res_7, res_6)
    res_p_8 = __phi(_cond_7, res_p_7, res_p_6)
    _cond_8 = (alu == my_ALU_t.Mult0)
    res_9, C_9, V_9 = mul_0[:16], Bit(0), Bit(0)  # wrong C, V
    res_p_9 = C_9
    C_10 = __phi(_cond_8, C_9, C_8)
    V_10 = __phi(_cond_8, V_9, V_8)
    res_10 = __phi(_cond_8, res_9, res_8)
    res_p_10 = __phi(_cond_8, res_p_9, res_p_8)
    _cond_9 = (alu == my_ALU_t.Mult1)
    res_11, C_11, V_11 = mul_0[8:24], Bit(0), Bit(0)  # wrong C, V
    res_p_11 = C_11
    C_12 = __phi(_cond_9, C_11, C_10)
    V_12 = __phi(_cond_9, V_11, V_10)
    res_12 = __phi(_cond_9, res_11, res_10)
    res_p_12 = __phi(_cond_9, res_p_11, res_p_10)
    _cond_10 = (alu == my_ALU_t.Mult2)
    res_13, C_13, V_13 = mul_0[16:32], Bit(0), Bit(0)  # wrong C, V
    res_p_13 = C_13
    C_14 = __phi(_cond_10, C_13, C_12)
    V_14 = __phi(_cond_10, V_13, V_12)
    res_14 = __phi(_cond_10, res_13, res_12)
    res_p_14 = __phi(_cond_10, res_p_13, res_p_12)
    _cond_11 = (alu == my_ALU_t.GTE_Max)
    res_15, res_p_15 = max_ab_0, gte_pred_2
    res_16 = __phi(_cond_11, res_15, res_14)
    res_p_16 = __phi(_cond_11, res_p_15, res_p_14)
    _cond_12 = (alu == my_ALU_t.LTE_Min)
    res_17, res_p_17 = min_ab_0, lte_pred_2
    res_18 = __phi(_cond_12, res_17, res_16)
    res_p_18 = __phi(_cond_12, res_p_17, res_p_16)
    _cond_13 = (alu == my_ALU_t.Abs)
    res_19, res_p_19 = abs_pred_2.ite(a, UInt[16](-SInt[16](a))), Bit(a[-1])
    res_20 = __phi(_cond_13, res_19, res_18)
    res_p_20 = __phi(_cond_13, res_p_19, res_p_18)
    _cond_14 = (alu == my_ALU_t.Sel)
    res_21, res_p_21 = d.ite(a, b_3), Bit(0)
    res_22 = __phi(_cond_14, res_21, res_20)
    res_p_22 = __phi(_cond_14, res_p_21, res_p_20)
    _cond_15 = (alu == my_ALU_t.And)
    res_23, res_p_23 = a & b_3, Bit(0)
    res_24 = __phi(_cond_15, res_23, res_22)
    res_p_24 = __phi(_cond_15, res_p_23, res_p_22)
    _cond_16 = (alu == my_ALU_t.Or)
    res_25, res_p_25 = a | b_3, Bit(0)
    res_26 = __phi(_cond_16, res_25, res_24)
    res_p_26 = __phi(_cond_16, res_p_25, res_p_24)
    _cond_17 = (alu == my_ALU_t.XOr)
    res_27, res_p_27 = a ^ b_3, Bit(0)
    res_28 = __phi(_cond_17, res_27, res_26)
    res_p_28 = __phi(_cond_17, res_p_27, res_p_26)
    _cond_18 = (alu == my_ALU_t.SHR)
    res_29, res_p_29 = shr_2, Bit(0)
    res_30 = __phi(_cond_18, res_29, res_28)
    res_p_30 = __phi(_cond_18, res_p_29, res_p_28)
    _cond_19 = (alu == my_ALU_t.SHL)
    res_31, res_p_31 = a << b_3, Bit(0)
    res_32 = __phi(_cond_19, res_31, res_30)
    res_p_32 = __phi(_cond_19, res_p_31, res_p_30)
    N_0 = Bit(res_32[-1])
    Z_0 = (res_32 == SData(0))
    __0_return_0 = res_32, res_p_32, Z_0, N_0, C_14, V_14
    return __0_return_0
