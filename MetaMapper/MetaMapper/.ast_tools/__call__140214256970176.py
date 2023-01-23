@name_outputs(alu_res=Data, res_p=Bit, read_config_data=Data32)
def __call__(self, inst: Const(Inst), \
    data0: Data, data1: Data = Data(0), \
    bit0: Bit = Bit(0), bit1: Bit = Bit(0), bit2: Bit = Bit(0), \
    clk_en: Global(Bit) = Bit(1), \
    config_addr : Data8 = Data8(0), \
    config_data : Data32 = Data32(0), \
    config_en : Bit = Bit(0) \
) -> (Data, Bit, Data32):
    # Simulate one clock cycle


    data0_addr_0 = (config_addr[:3] == BitVector[3](DATA0_ADDR))
    data1_addr_0 = (config_addr[:3] == BitVector[3](DATA1_ADDR))
    bit012_addr_0 = (config_addr[:3] == BitVector[3](BIT012_ADDR))

    #ra
    ra_we_0 = (data0_addr_0 & config_en)
    ra_config_wdata_0 = config_data[DATA_START:DATA_START+DATA_WIDTH]

    #rb
    rb_we_0 = (data1_addr_0 & config_en)
    rb_config_wdata_0 = config_data[DATA_START:DATA_START+DATA_WIDTH]

    #rd
    rd_we_0 = (bit012_addr_0 & config_en)
    rd_config_wdata_0 = config_data[BIT0_START]

    #re
    re_we_0 = rd_we_0
    re_config_wdata_0 = config_data[BIT1_START]

    #rf
    rf_we_0 = rd_we_0
    rf_config_wdata_0 = config_data[BIT2_START]
    ra_0, ra_rdata_0 = self.rega(inst.rega, inst.data0, data0, clk_en)
    rb_0, rb_rdata_0 = self.regb(inst.regb, inst.data1, data1, clk_en)

    rd_0, rd_rdata_0 = self.regd(inst.regd, inst.bit0, bit0, clk_en)
    re_0, re_rdata_0 = self.rege(inst.rege, inst.bit1, bit1, clk_en)
    rf_0, rf_rdata_0 = self.regf(inst.regf, inst.bit2, bit2, clk_en)

    #Calculate read_config_data
    read_config_data_0 = bit012_addr_0.ite(
        BV1(rd_rdata_0).concat(BV1(re_rdata_0)).concat(BV1(rf_rdata_0)).concat(BitVector[32-3](0)),
        ra_rdata_0.concat(rb_rdata_0)
    )

    # calculate alu results
    alu_res_0, alu_res_p_0, Z_0, N_0, C_0, V_0 = self.alu(inst.alu, inst.signed, ra_0, rb_0, rd_0)

    # calculate lut results
    lut_res_0 = self.lut(inst.lut, rd_0, re_0, rf_0)   #调用类函数

    # calculate 1-bit result
    res_p_0 = self.cond(inst.cond, alu_res_p_0, lut_res_0, Z_0, N_0, C_0, V_0)

    # return 16-bit result, 1-bit result
    __0_return_0 = alu_res_0, res_p_0, read_config_data_0
    return __0_return_0
