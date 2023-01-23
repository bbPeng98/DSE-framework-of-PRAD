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
    N_0 = Bit(res_4[-1])
    Z_0 = (res_4 == SData(0))
    __0_return_0 = res_4, res_p_4, Z_0, N_0, C_4, V_4
    return __0_return_0
