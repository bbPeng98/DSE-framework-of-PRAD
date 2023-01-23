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



    adder_res_0, adder_C_0 = UData(a).adc(UData(b), Cin_0)
    _cond_1 = (alu == my_ALU_t.Add)
    res_1, C_1 = adder_res_0, adder_C_0
    V_1 = overflow(a, b, res_1)
    res_p_1 = C_1
    C_2 = __phi(_cond_1, C_1, C_0)
    V_2 = __phi(_cond_1, V_1, V_0)
    res_2 = __phi(_cond_1, res_1, res_0)
    res_p_2 = __phi(_cond_1, res_p_1, res_p_0)
    _cond_2 = (alu == my_ALU_t.Mult0)
    res_3, C_3, V_3 = mul_0[:16], Bit(0), Bit(0)  # wrong C, V
    res_p_3 = C_3
    C_4 = __phi(_cond_2, C_3, C_2)
    V_4 = __phi(_cond_2, V_3, V_2)
    res_4 = __phi(_cond_2, res_3, res_2)
    res_p_4 = __phi(_cond_2, res_p_3, res_p_2)
    _cond_3 = (alu == my_ALU_t.Mult1)
    res_5, C_5, V_5 = mul_0[16:32], Bit(0), Bit(0)  # wrong C, V
    res_p_5 = C_5
    C_6 = __phi(_cond_3, C_5, C_4)
    V_6 = __phi(_cond_3, V_5, V_4)
    res_6 = __phi(_cond_3, res_5, res_4)
    res_p_6 = __phi(_cond_3, res_p_5, res_p_4)
    _cond_4 = (alu == my_ALU_t.Mult2)
    res_7, C_7, V_7 = mul_0[16:32], Bit(0), Bit(0)  # wrong C, V
    res_p_7 = C_7
    C_8 = __phi(_cond_4, C_7, C_6)
    V_8 = __phi(_cond_4, V_7, V_6)
    res_8 = __phi(_cond_4, res_7, res_6)
    res_p_8 = __phi(_cond_4, res_p_7, res_p_6)
    _cond_5 = (alu == my_ALU_t.Abs)
    res_9, res_p_9 = abs_pred_2.ite(a, UInt[16](-SInt[16](a))), Bit(a[-1])
    res_10 = __phi(_cond_5, res_9, res_8)
    res_p_10 = __phi(_cond_5, res_p_9, res_p_8)
    _cond_6 = (alu == my_ALU_t.And)
    res_11, res_p_11 = a & b, Bit(0)
    res_12 = __phi(_cond_6, res_11, res_10)
    res_p_12 = __phi(_cond_6, res_p_11, res_p_10)
    _cond_7 = (alu == my_ALU_t.Or)
    res_13, res_p_13 = a | b, Bit(0)
    res_14 = __phi(_cond_7, res_13, res_12)
    res_p_14 = __phi(_cond_7, res_p_13, res_p_12)
    _cond_8 = (alu == my_ALU_t.XOr)
    res_15, res_p_15 = a ^ b, Bit(0)
    res_16 = __phi(_cond_8, res_15, res_14)
    res_p_16 = __phi(_cond_8, res_p_15, res_p_14)
    _cond_9 = (alu == my_ALU_t.SHR)
    res_17, res_p_17 = shr_2, Bit(0)
    res_18 = __phi(_cond_9, res_17, res_16)
    res_p_18 = __phi(_cond_9, res_p_17, res_p_16)
    _cond_10 = (alu == my_ALU_t.SHL)
    res_19, res_p_19 = a << b, Bit(0)
    res_20 = __phi(_cond_10, res_19, res_18)
    res_p_20 = __phi(_cond_10, res_p_19, res_p_18)
    N_0 = Bit(res_20[-1])
    Z_0 = (res_20 == SData(0))
    __0_return_0 = res_20, res_p_20, Z_0, N_0, C_8, V_8
    return __0_return_0
