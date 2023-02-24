# ==============================================================================
# RTL for TLX
# ==============================================================================

set soc_tlx_files [concat \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog//nic400_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/amib_M1_m/verilog/nic400_amib_M1_m_chan_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/amib_M1_m/verilog/nic400_amib_M1_m_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_bypass_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_capt_nosync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_capt_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_comb_and2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_comb_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_comb_or2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_comb_or3_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_corrupt_gry_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_launch_gry_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/cdc_blocks/verilog/nic400_cdc_random_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_chan_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_master_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_r_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_r_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_r_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_r_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_slave_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_w_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_w_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_w_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/ib_M1_m_ib/verilog/nic400_ib_M1_m_ib_w_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_clk_m_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_clk_s_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_dl_fwd_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_dl_rev_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_pl_fwd_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_cd_pl_rev_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_master_pwr_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/nic400/verilog/nic400_slave_pwr_M1_m_tlx_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/reg_slice/verilog/nic400_ful_regd_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/reg_slice/verilog/nic400_fwd_regd_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/reg_slice/verilog/nic400_rev_regd_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_fifo_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_flow_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_flow_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_ar_flow_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_fifo_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_flow_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_flow_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_aw_flow_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_fifo_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_flow_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_flow_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_b_flow_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_cdc_air_corrupt_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_chan_slice_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_dl_fwd_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_dl_rev_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_fwd_clk_buf_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_link_reg_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_master_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_pl_fwd_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_pl_rev_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_fifo_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_flow_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_flow_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_r_flow_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_rev_clk_buf_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_slave_domain_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_fifo_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_fifo_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_fifo_wr_mux2_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_fifo_wr_mux_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_fifo_wr_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_flow_rd_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_flow_sync_tlx_AhaIntegration.v \
  inputs/rtl/aham3soc_armip/logical/nic400_tlx_AhaIntegration/tlx_M1_m_tlx/verilog/nic400_tlx_M1_m_tlx_w_flow_wr_tlx_AhaIntegration.v \
]