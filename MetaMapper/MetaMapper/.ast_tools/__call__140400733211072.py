def __call__(self, inst: Const(Inst), \
    data0: Data, data1: Data = Data(0), \
    bit0: Bit = Bit(0), \
    bit1: Bit = Bit(0), \
    bit2: Bit = Bit(0), \
    clk_en: Global(Bit) = Bit(1), \
    config_addr : Data8 = Data8(0), \
    config_data : Data32 = Data32(0), \
    config_en : Bit = Bit(0) \
) -> (Data, Bit):
    # Simulate one clock cycle


    data0_addr_0 = (config_addr[:3] == BitVector[3](DATA0_ADDR))
    data1_addr_0 = (config_addr[:3] == BitVector[3](DATA1_ADDR))
    bit012_addr_0 = (config_addr[:3] == BitVector[3](BIT012_ADDR))


    ra_0, ra_rdata_0 = self.rega(inst.rega, inst.data0, data0, clk_en)
    rb_0, rb_rdata_0 = self.regb(inst.regb, inst.data1, data1, clk_en)

    # rd, rd_rdata = self.regd(inst.regd, inst.bit0, bit0, clk_en)
    # re, re_rdata = self.rege(inst.rege, inst.bit1, bit1, clk_en)
    # rf, rf_rdata = self.regf(inst.regf, inst.bit2, bit2, clk_en)

    # #Calculate read_config_data
    # read_config_data = bit012_addr.ite(
    #     BV1(rd_rdata).concat(BV1(re_rdata)).concat(BV1(rf_rdata)).concat(BitVector[32-3](0)),
    #     ra_rdata.concat(rb_rdata)
    # )

    # calculate alu results
    # alu_res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rd)


    rd_0, rd_rdata_0 = self.regd(inst.regd, inst.bit0, bit0, clk_en)
    re_0, re_rdata_0 = self.rege(inst.rege, inst.bit1, bit1, clk_en)
    rf_0, rf_rdata_0 = self.regf(inst.regf, inst.bit2, bit2, clk_en)
    alu_res_0, alu_res_p_0, Z_0, N_0, C_0, V_0 = self.alu(inst.alu, inst.signed, ra_0, rb_0, rd_0)
    lut_res_0 = self.lut(inst.lut, rd_0, re_0, rf_0)
    res_p_0 = self.cond(inst.cond, alu_res_p_0, lut_res_0, Z_0, N_0, C_0, V_0)
    __0_return_0 = alu_res_0, res_p_0
    return __0_return_0
