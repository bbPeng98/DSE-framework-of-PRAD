@name_outputs(res=DataPy, res_p=BitPy)
def __call__(
    self,
    inst: Const(Inst),
    data0: DataPy,
    data1: DataPy = Data(0),
    data2: DataPy = Data(0),
    bit0: Bit = Bit(0), \
    bit1: Bit = Bit(0), \
    bit2: Bit = Bit(0), \
    clk_en: Global(BitPy) = Bit(1)
) -> (DataPy, BitPy):


    ra_0, ra_rdata_0 = self.rega(inst.rega, inst.data0, data0, clk_en)
    rb_0, rb_rdata_0 = self.regb(inst.regb, inst.data1, data1, clk_en)
    rc_0, rc_rdata_0 = self.regc(inst.regc, inst.data2, data2, clk_en)

    #set default values to each of the op kinds
    #alu_op = ALU_t_c(ALU_t.Add)
    #fpu_op = FPU_t_c(FPU_t.FP_add)
    #fp_custom_op = FPCustom_t_c(FPCustom_t.FGetMant)
    #if inst.op.alu.match:
    #    alu_op = inst.op.alu.value
    #elif inst.op.fpu.match:
    #    fpu_op = inst.op.fpu.value
    #else: #inst.op.fp_custom.match:
    #    fp_custom_op = inst.op.fp_custom.value

    # calculate alu results
    #alu_res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rc, rd)

    #fpu_res, fpu_N, fpu_Z = self.fpu(fpu_op, ra, rb)

    #fpc_res, fpc_res_p, fpc_V = self.fp_custom(fp_custom_op, inst.signed, ra, rb)

    # Z = Bit(0)
    # N = Bit(0)
    # V = Bit(0)
    # res_p = Bit(0)
    # res = Data(0)
    # if inst.op.alu.match:
    #     Z = alu_Z
    #     N = alu_N
    #     V = alu_V
    #     res_p = alu_res_p
    #     res = alu_res
    # elif inst.op.fpu.match:
    #     N = fpu_N
    #     Z = fpu_Z
    #     res = fpu_res
    # else: #inst.op.fp_custom.match:
    #     V = fpc_V
    #     res_p = fpc_res_p
    #     res = fpc_res

    # calculate lut results
    rd_0, rd_rdata_0 = self.regd(inst.regd, inst.bit0, bit0, clk_en)
    re_0, re_rdata_0 = self.rege(inst.rege, inst.bit1, bit1, clk_en)
    rf_0, rf_rdata_0 = self.regf(inst.regf, inst.bit2, bit2, clk_en)
    res_0, alu_res_p_0, Z_0, N_0, C_0, V_0 = self.alu(inst.alu, inst.signed, ra_0, rb_0, rc_0, rd_0)
    lut_res_0 = self.lut(inst.lut, rd_0, re_0, rf_0)
    res_p_0 = self.cond(inst.cond, alu_res_p_0, lut_res_0, Z_0, N_0, C_0, V_0)
    __0_return_0 = res_0, res_p_0
    return __0_return_0
