module Chain (
  input logic [1:0] accessor_output,
  input logic [1:0] [15:0] chain_data_in,
  input logic chain_en,
  input logic clk_en,
  input logic [1:0] [15:0] curr_tile_data_out,
  input logic flush,
  output logic [1:0] [15:0] data_out_tile
);

always_comb begin
  if (accessor_output[0]) begin
    data_out_tile[0] = curr_tile_data_out[0];
  end
  else if (chain_en) begin
    data_out_tile[0] = chain_data_in[0];
  end
  else data_out_tile[0] = 16'h0;
  if (accessor_output[1]) begin
    data_out_tile[1] = curr_tile_data_out[1];
  end
  else if (chain_en) begin
    data_out_tile[1] = chain_data_in[1];
  end
  else data_out_tile[1] = 16'h0;
end
endmodule   // Chain

module LakeTop (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [31:0] config_data_in,
  input logic [1:0] config_en,
  input logic config_read,
  input logic config_write,
  input logic flush,
  input logic [0:0] [15:0] input_width_16_num_0,
  input logic [0:0] [15:0] input_width_16_num_1,
  input logic [0:0] [15:0] input_width_16_num_2,
  input logic [0:0] [15:0] input_width_16_num_3,
  input logic input_width_1_num_0,
  input logic input_width_1_num_1,
  input logic [3:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality,
  input logic [5:0] [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges,
  input logic mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides,
  input logic [15:0] mem_ctrl_strg_fifo_flat_strg_fifo_inst_fifo_depth,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_1,
  input logic [2:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality,
  input logic [2:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges,
  input logic [2:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality,
  input logic [2:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges,
  input logic [5:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding,
  input logic [5:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_1,
  input logic [1:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_0,
  input logic [1:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_1,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr,
  input logic [5:0] [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr,
  input logic [5:0] [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality,
  input logic [5:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality,
  input logic [5:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality,
  input logic [5:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality,
  input logic [5:0] [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides,
  input logic [1:0] mode,
  input logic rst_n,
  input logic tile_en,
  output logic [1:0] [31:0] config_data_out,
  output logic [0:0] [15:0] output_width_16_num_0,
  output logic [0:0] [15:0] output_width_16_num_1,
  output logic output_width_1_num_0,
  output logic output_width_1_num_1,
  output logic output_width_1_num_2,
  output logic output_width_1_num_3
);

logic [15:0] config_data_in_shrt;
logic [1:0][15:0] config_data_out_shrt;
logic [8:0] config_seq_addr_out;
logic config_seq_clk_en;
logic [0:0][3:0][15:0] config_seq_rd_data_stg;
logic config_seq_ren_out;
logic config_seq_wen_out;
logic [3:0][15:0] config_seq_wr_data;
logic gclk;
logic mem_ctrl_stencil_valid_flat_clk;
logic mem_ctrl_stencil_valid_flat_stencil_valid_f_;
logic [0:0][8:0] mem_ctrl_strg_fifo_flat_addr_out_lifted;
logic mem_ctrl_strg_fifo_flat_clk;
logic [0:0][3:0][15:0] mem_ctrl_strg_fifo_flat_data_from_strg_lifted;
logic [0:0][15:0] mem_ctrl_strg_fifo_flat_data_out_f_;
logic [0:0][3:0][15:0] mem_ctrl_strg_fifo_flat_data_to_strg_lifted;
logic mem_ctrl_strg_fifo_flat_empty_f_;
logic mem_ctrl_strg_fifo_flat_full_f_;
logic mem_ctrl_strg_fifo_flat_ren_to_strg_lifted;
logic mem_ctrl_strg_fifo_flat_valid_out_f_;
logic mem_ctrl_strg_fifo_flat_wen_to_strg_lifted;
logic [0:0][8:0] mem_ctrl_strg_ram_flat_addr_out_lifted;
logic mem_ctrl_strg_ram_flat_clk;
logic [0:0][3:0][15:0] mem_ctrl_strg_ram_flat_data_from_strg_lifted;
logic [0:0][15:0] mem_ctrl_strg_ram_flat_data_out_f_;
logic [0:0][3:0][15:0] mem_ctrl_strg_ram_flat_data_to_strg_lifted;
logic mem_ctrl_strg_ram_flat_ready_f_;
logic mem_ctrl_strg_ram_flat_ren_to_strg_lifted;
logic mem_ctrl_strg_ram_flat_valid_out_f_;
logic mem_ctrl_strg_ram_flat_wen_to_strg_lifted;
logic mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_0;
logic mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_1;
logic [8:0] mem_ctrl_strg_ub_vec_flat_addr_out_lifted;
logic mem_ctrl_strg_ub_vec_flat_clk;
logic [3:0][15:0] mem_ctrl_strg_ub_vec_flat_data_from_strg_lifted;
logic [0:0][15:0] mem_ctrl_strg_ub_vec_flat_data_out_f_0;
logic [0:0][15:0] mem_ctrl_strg_ub_vec_flat_data_out_f_1;
logic [3:0][15:0] mem_ctrl_strg_ub_vec_flat_data_to_strg_lifted;
logic mem_ctrl_strg_ub_vec_flat_ren_to_strg_lifted;
logic mem_ctrl_strg_ub_vec_flat_wen_to_strg_lifted;
logic memory_0_clk_en;
logic [63:0] memory_0_data_in_p0;
logic [63:0] memory_0_data_out_p0;
logic [8:0] memory_0_read_addr_p0;
logic memory_0_read_enable_p0;
logic [8:0] memory_0_write_addr_p0;
logic memory_0_write_enable_p0;
assign gclk = clk & tile_en;
assign mem_ctrl_strg_ub_vec_flat_clk = gclk & (mode == 2'h0);
assign mem_ctrl_strg_fifo_flat_clk = gclk & (mode == 2'h1);
assign mem_ctrl_strg_ram_flat_clk = gclk & (mode == 2'h2);
assign mem_ctrl_stencil_valid_flat_clk = gclk;
always_comb begin
  output_width_16_num_0 = 16'h0;
  if (mode == 2'h0) begin
    output_width_16_num_0 = mem_ctrl_strg_ub_vec_flat_data_out_f_0;
  end
  else if (mode == 2'h1) begin
    output_width_16_num_0 = mem_ctrl_strg_fifo_flat_data_out_f_;
  end
  else if (mode == 2'h2) begin
    output_width_16_num_0 = mem_ctrl_strg_ram_flat_data_out_f_;
  end
end
always_comb begin
  output_width_16_num_1 = 16'h0;
  output_width_16_num_1 = mem_ctrl_strg_ub_vec_flat_data_out_f_1;
end
always_comb begin
  output_width_1_num_0 = 1'h0;
  if (mode == 2'h0) begin
    output_width_1_num_0 = mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_0;
  end
  else if (mode == 2'h1) begin
    output_width_1_num_0 = mem_ctrl_strg_fifo_flat_empty_f_;
  end
  else if (mode == 2'h2) begin
    output_width_1_num_0 = mem_ctrl_strg_ram_flat_ready_f_;
  end
end
always_comb begin
  output_width_1_num_1 = 1'h0;
  if (mode == 2'h0) begin
    output_width_1_num_1 = mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_1;
  end
  else if (mode == 2'h1) begin
    output_width_1_num_1 = mem_ctrl_strg_fifo_flat_full_f_;
  end
  else if (mode == 2'h2) begin
    output_width_1_num_1 = mem_ctrl_strg_ram_flat_valid_out_f_;
  end
end
always_comb begin
  output_width_1_num_2 = 1'h0;
  output_width_1_num_2 = mem_ctrl_strg_fifo_flat_valid_out_f_;
end
always_comb begin
  output_width_1_num_3 = 1'h0;
  output_width_1_num_3 = mem_ctrl_stencil_valid_flat_stencil_valid_f_;
end
always_comb begin
  memory_0_data_in_p0 = 64'h0;
  memory_0_write_addr_p0 = 9'h0;
  memory_0_write_enable_p0 = 1'h0;
  memory_0_read_addr_p0 = 9'h0;
  memory_0_read_enable_p0 = 1'h0;
  if (|config_en) begin
    memory_0_data_in_p0 = config_seq_wr_data;
    memory_0_write_addr_p0 = config_seq_addr_out;
    memory_0_write_enable_p0 = config_seq_wen_out;
    memory_0_read_addr_p0 = config_seq_addr_out;
    memory_0_read_enable_p0 = config_seq_ren_out;
  end
  else if (mode == 2'h0) begin
    memory_0_data_in_p0 = mem_ctrl_strg_ub_vec_flat_data_to_strg_lifted;
    memory_0_write_addr_p0 = mem_ctrl_strg_ub_vec_flat_addr_out_lifted;
    memory_0_write_enable_p0 = mem_ctrl_strg_ub_vec_flat_wen_to_strg_lifted;
    memory_0_read_addr_p0 = mem_ctrl_strg_ub_vec_flat_addr_out_lifted;
    memory_0_read_enable_p0 = mem_ctrl_strg_ub_vec_flat_ren_to_strg_lifted;
  end
  else if (mode == 2'h1) begin
    memory_0_data_in_p0 = mem_ctrl_strg_fifo_flat_data_to_strg_lifted;
    memory_0_write_addr_p0 = mem_ctrl_strg_fifo_flat_addr_out_lifted;
    memory_0_write_enable_p0 = mem_ctrl_strg_fifo_flat_wen_to_strg_lifted;
    memory_0_read_addr_p0 = mem_ctrl_strg_fifo_flat_addr_out_lifted;
    memory_0_read_enable_p0 = mem_ctrl_strg_fifo_flat_ren_to_strg_lifted;
  end
  else if (mode == 2'h2) begin
    memory_0_data_in_p0 = mem_ctrl_strg_ram_flat_data_to_strg_lifted;
    memory_0_write_addr_p0 = mem_ctrl_strg_ram_flat_addr_out_lifted;
    memory_0_write_enable_p0 = mem_ctrl_strg_ram_flat_wen_to_strg_lifted;
    memory_0_read_addr_p0 = mem_ctrl_strg_ram_flat_addr_out_lifted;
    memory_0_read_enable_p0 = mem_ctrl_strg_ram_flat_ren_to_strg_lifted;
  end
end
always_comb begin
  mem_ctrl_strg_ub_vec_flat_data_from_strg_lifted = memory_0_data_out_p0;
  mem_ctrl_strg_fifo_flat_data_from_strg_lifted = memory_0_data_out_p0;
  mem_ctrl_strg_ram_flat_data_from_strg_lifted = memory_0_data_out_p0;
  config_seq_rd_data_stg = memory_0_data_out_p0;
end
assign config_data_in_shrt = config_data_in[15:0];
assign config_data_out[0] = 32'(config_data_out_shrt[0]);
assign config_data_out[1] = 32'(config_data_out_shrt[1]);
assign config_seq_clk_en = clk_en | (|config_en);
assign memory_0_clk_en = clk_en | (|config_en);
strg_ub_vec_flat mem_ctrl_strg_ub_vec_flat (
  .chain_data_in_f_0(input_width_16_num_0),
  .chain_data_in_f_1(input_width_16_num_1),
  .clk(mem_ctrl_strg_ub_vec_flat_clk),
  .clk_en(clk_en),
  .data_from_strg_lifted(mem_ctrl_strg_ub_vec_flat_data_from_strg_lifted),
  .data_in_f_0(input_width_16_num_2),
  .data_in_f_1(input_width_16_num_3),
  .flush(flush),
  .rst_n(rst_n),
  .strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr),
  .strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides),
  .strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr),
  .strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides),
  .strg_ub_vec_inst_agg_only_delay_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_0),
  .strg_ub_vec_inst_agg_only_delay_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_1),
  .strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality),
  .strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges),
  .strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality),
  .strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges),
  .strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding),
  .strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding),
  .strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr),
  .strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr),
  .strg_ub_vec_inst_agg_sram_shared_delay_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_0),
  .strg_ub_vec_inst_agg_sram_shared_delay_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_1),
  .strg_ub_vec_inst_agg_sram_shared_mode_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_0),
  .strg_ub_vec_inst_agg_sram_shared_mode_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_1),
  .strg_ub_vec_inst_chain_chain_en(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en),
  .strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr),
  .strg_ub_vec_inst_sram_only_output_addr_gen_0_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides),
  .strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr),
  .strg_ub_vec_inst_sram_only_output_addr_gen_1_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides),
  .strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality),
  .strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges),
  .strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality),
  .strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides),
  .strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality),
  .strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges),
  .strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality),
  .strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges),
  .strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides),
  .strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides),
  .strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides),
  .strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr),
  .strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides),
  .accessor_output_f_b_0(mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_0),
  .accessor_output_f_b_1(mem_ctrl_strg_ub_vec_flat_accessor_output_f_b_1),
  .addr_out_lifted(mem_ctrl_strg_ub_vec_flat_addr_out_lifted),
  .data_out_f_0(mem_ctrl_strg_ub_vec_flat_data_out_f_0),
  .data_out_f_1(mem_ctrl_strg_ub_vec_flat_data_out_f_1),
  .data_to_strg_lifted(mem_ctrl_strg_ub_vec_flat_data_to_strg_lifted),
  .ren_to_strg_lifted(mem_ctrl_strg_ub_vec_flat_ren_to_strg_lifted),
  .wen_to_strg_lifted(mem_ctrl_strg_ub_vec_flat_wen_to_strg_lifted)
);

strg_fifo_flat mem_ctrl_strg_fifo_flat (
  .clk(mem_ctrl_strg_fifo_flat_clk),
  .clk_en(clk_en),
  .data_from_strg_lifted(mem_ctrl_strg_fifo_flat_data_from_strg_lifted),
  .data_in_f_(input_width_16_num_0),
  .flush(flush),
  .pop_f_(input_width_1_num_0),
  .push_f_(input_width_1_num_1),
  .rst_n(rst_n),
  .strg_fifo_inst_fifo_depth(mem_ctrl_strg_fifo_flat_strg_fifo_inst_fifo_depth),
  .addr_out_lifted(mem_ctrl_strg_fifo_flat_addr_out_lifted),
  .data_out_f_(mem_ctrl_strg_fifo_flat_data_out_f_),
  .data_to_strg_lifted(mem_ctrl_strg_fifo_flat_data_to_strg_lifted),
  .empty_f_(mem_ctrl_strg_fifo_flat_empty_f_),
  .full_f_(mem_ctrl_strg_fifo_flat_full_f_),
  .ren_to_strg_lifted(mem_ctrl_strg_fifo_flat_ren_to_strg_lifted),
  .valid_out_f_(mem_ctrl_strg_fifo_flat_valid_out_f_),
  .wen_to_strg_lifted(mem_ctrl_strg_fifo_flat_wen_to_strg_lifted)
);

strg_ram_flat mem_ctrl_strg_ram_flat (
  .clk(mem_ctrl_strg_ram_flat_clk),
  .clk_en(clk_en),
  .data_from_strg_lifted(mem_ctrl_strg_ram_flat_data_from_strg_lifted),
  .data_in_f_(input_width_16_num_0),
  .flush(flush),
  .rd_addr_in_f_(input_width_16_num_1),
  .ren_f_(input_width_1_num_0),
  .rst_n(rst_n),
  .wen_f_(input_width_1_num_1),
  .wr_addr_in_f_(input_width_16_num_2),
  .addr_out_lifted(mem_ctrl_strg_ram_flat_addr_out_lifted),
  .data_out_f_(mem_ctrl_strg_ram_flat_data_out_f_),
  .data_to_strg_lifted(mem_ctrl_strg_ram_flat_data_to_strg_lifted),
  .ready_f_(mem_ctrl_strg_ram_flat_ready_f_),
  .ren_to_strg_lifted(mem_ctrl_strg_ram_flat_ren_to_strg_lifted),
  .valid_out_f_(mem_ctrl_strg_ram_flat_valid_out_f_),
  .wen_to_strg_lifted(mem_ctrl_strg_ram_flat_wen_to_strg_lifted)
);

stencil_valid_flat mem_ctrl_stencil_valid_flat (
  .clk(mem_ctrl_stencil_valid_flat_clk),
  .clk_en(clk_en),
  .flush(flush),
  .rst_n(rst_n),
  .stencil_valid_inst_loops_stencil_valid_dimensionality(mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality),
  .stencil_valid_inst_loops_stencil_valid_ranges(mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges),
  .stencil_valid_inst_stencil_valid_sched_gen_enable(mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable),
  .stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr(mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr),
  .stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides(mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides),
  .stencil_valid_f_(mem_ctrl_stencil_valid_flat_stencil_valid_f_)
);

sram_sp__0 memory_0 (
  .clk(gclk),
  .clk_en(memory_0_clk_en),
  .data_in_p0(memory_0_data_in_p0),
  .flush(flush),
  .read_addr_p0(memory_0_read_addr_p0),
  .read_enable_p0(memory_0_read_enable_p0),
  .write_addr_p0(memory_0_write_addr_p0),
  .write_enable_p0(memory_0_write_enable_p0),
  .data_out_p0(memory_0_data_out_p0)
);

storage_config_seq config_seq (
  .clk(gclk),
  .clk_en(config_seq_clk_en),
  .config_addr_in(config_addr_in),
  .config_data_in(config_data_in_shrt),
  .config_en(config_en),
  .config_rd(config_read),
  .config_wr(config_write),
  .flush(flush),
  .rd_data_stg(config_seq_rd_data_stg),
  .rst_n(rst_n),
  .addr_out(config_seq_addr_out),
  .rd_data_out(config_data_out_shrt),
  .ren_out(config_seq_ren_out),
  .wen_out(config_seq_wen_out),
  .wr_data(config_seq_wr_data)
);

endmodule   // LakeTop

module LakeTop_W (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [31:0] config_data_in,
  input logic [1:0] config_en,
  input logic config_read,
  input logic config_write,
  input logic flush,
  input logic [0:0] [15:0] input_width_16_num_0,
  input logic [0:0] [15:0] input_width_16_num_1,
  input logic [0:0] [15:0] input_width_16_num_2,
  input logic [0:0] [15:0] input_width_16_num_3,
  input logic input_width_1_num_0,
  input logic input_width_1_num_1,
  input logic [3:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_0,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_1,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_2,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_3,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_4,
  input logic [9:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_5,
  input logic mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_5,
  input logic [15:0] mem_ctrl_strg_fifo_flat_strg_fifo_inst_fifo_depth,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_1,
  input logic [2:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_2,
  input logic [2:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_2,
  input logic [5:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding,
  input logic [5:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_1,
  input logic [1:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_0,
  input logic [1:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_1,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_0,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_1,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_2,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_3,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_4,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_5,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_0,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_1,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_2,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_3,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_4,
  input logic [8:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_2,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_3,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_4,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_2,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_3,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_4,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_2,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_3,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_4,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_0,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_1,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_2,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_3,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_4,
  input logic [9:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_5,
  input logic mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_0,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_1,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_2,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_3,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_4,
  input logic [15:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_5,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_0,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_1,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_2,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_3,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_4,
  input logic [3:0] mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_5,
  input logic [1:0] mode,
  input logic rst_n,
  input logic tile_en,
  output logic [31:0] config_data_out_0,
  output logic [31:0] config_data_out_1,
  output logic [0:0] [15:0] output_width_16_num_0,
  output logic [0:0] [15:0] output_width_16_num_1,
  output logic output_width_1_num_0,
  output logic output_width_1_num_1,
  output logic output_width_1_num_2,
  output logic output_width_1_num_3
);

logic [1:0][31:0] LakeTop_config_data_out;
logic [5:0][9:0] LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges;
logic [5:0][15:0] LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides;
logic [2:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges;
logic [2:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges;
logic [5:0][8:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides;
logic [5:0][8:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides;
logic [5:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges;
logic [5:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides;
logic [5:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges;
logic [5:0][9:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides;
logic [5:0][15:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides;
logic [5:0][3:0] LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides;
assign config_data_out_0 = LakeTop_config_data_out[0];
assign config_data_out_1 = LakeTop_config_data_out[1];
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[0] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_0;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[1] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_1;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[2] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_2;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[3] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_3;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[4] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_4;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges[5] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_5;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[0] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[1] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[2] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[3] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[4] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides[5] = mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_5;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[0] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_0;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[1] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_1;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[2] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_2;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[3] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_3;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[4] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_4;
assign LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides[5] = mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_5;
LakeTop LakeTop (
  .clk(clk),
  .clk_en(clk_en),
  .config_addr_in(config_addr_in),
  .config_data_in(config_data_in),
  .config_en(config_en),
  .config_read(config_read),
  .config_write(config_write),
  .flush(flush),
  .input_width_16_num_0(input_width_16_num_0),
  .input_width_16_num_1(input_width_16_num_1),
  .input_width_16_num_2(input_width_16_num_2),
  .input_width_16_num_3(input_width_16_num_3),
  .input_width_1_num_0(input_width_1_num_0),
  .input_width_1_num_1(input_width_1_num_1),
  .mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality(mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality),
  .mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges(LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges),
  .mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable(mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable),
  .mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr(mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr),
  .mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides(LakeTop_mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides),
  .mem_ctrl_strg_fifo_flat_strg_fifo_inst_fifo_depth(mem_ctrl_strg_fifo_flat_strg_fifo_inst_fifo_depth),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_0),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_delay_1),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_0),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_delay_1),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_0(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_0),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_1(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_mode_1),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr(mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr),
  .mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides(LakeTop_mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides),
  .mode(mode),
  .rst_n(rst_n),
  .tile_en(tile_en),
  .config_data_out(LakeTop_config_data_out),
  .output_width_16_num_0(output_width_16_num_0),
  .output_width_16_num_1(output_width_16_num_1),
  .output_width_1_num_0(output_width_1_num_0),
  .output_width_1_num_1(output_width_1_num_1),
  .output_width_1_num_2(output_width_1_num_2),
  .output_width_1_num_3(output_width_1_num_3)
);

endmodule   // LakeTop_W

module addr_gen_6_16 (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic [2:0] mux_sel,
  input logic restart,
  input logic rst_n,
  input logic [15:0] starting_addr,
  input logic step,
  input logic [5:0] [15:0] strides,
  output logic [15:0] addr_out
);

logic [15:0] calc_addr;
logic [15:0] current_addr;
logic [15:0] strt_addr;
assign strt_addr = starting_addr;
assign addr_out = calc_addr;
assign calc_addr = strt_addr + current_addr;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    current_addr <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      current_addr <= 16'h0;
    end
    else if (step) begin
      if (restart) begin
        current_addr <= 16'h0;
      end
      else current_addr <= current_addr + strides[mux_sel];
    end
  end
end
endmodule   // addr_gen_6_16

module addr_gen_6_4 (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic [2:0] mux_sel,
  input logic restart,
  input logic rst_n,
  input logic [3:0] starting_addr,
  input logic step,
  input logic [5:0] [3:0] strides,
  output logic [3:0] addr_out
);

logic [3:0] calc_addr;
logic [3:0] current_addr;
logic [3:0] strt_addr;
assign strt_addr = starting_addr;
assign addr_out = calc_addr;
assign calc_addr = strt_addr + current_addr;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    current_addr <= 4'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      current_addr <= 4'h0;
    end
    else if (step) begin
      if (restart) begin
        current_addr <= 4'h0;
      end
      else current_addr <= current_addr + strides[mux_sel];
    end
  end
end
endmodule   // addr_gen_6_4

module addr_gen_6_9 (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic [2:0] mux_sel,
  input logic restart,
  input logic rst_n,
  input logic [8:0] starting_addr,
  input logic step,
  input logic [5:0] [8:0] strides,
  output logic [8:0] addr_out
);

logic [8:0] calc_addr;
logic [8:0] current_addr;
logic [8:0] strt_addr;
assign strt_addr = starting_addr;
assign addr_out = calc_addr;
assign calc_addr = strt_addr + current_addr;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    current_addr <= 9'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      current_addr <= 9'h0;
    end
    else if (step) begin
      if (restart) begin
        current_addr <= 9'h0;
      end
      else current_addr <= current_addr + strides[mux_sel];
    end
  end
end
endmodule   // addr_gen_6_9

module agg_sram_shared_addr_gen (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic [1:0] mode,
  input logic rst_n,
  input logic [1:0] sram_read,
  input logic [1:0] [8:0] sram_read_addr,
  input logic [8:0] starting_addr,
  input logic step,
  output logic [8:0] addr_out
);

logic [3:0][8:0] addr_fifo;
logic [8:0] addr_fifo_in;
logic [8:0] addr_fifo_out;
logic addr_fifo_wr_en;
logic [8:0] lin_addr_cnter;
logic [1:0] rd_ptr;
logic [1:0] wr_ptr;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    lin_addr_cnter <= 9'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      lin_addr_cnter <= 9'h0;
    end
    else if (mode[1] == 1'h0) begin
      if (step) begin
        if (lin_addr_cnter == 9'h1FF) begin
          lin_addr_cnter <= 9'h0;
        end
        else lin_addr_cnter <= lin_addr_cnter + 9'h1;
      end
    end
  end
end
assign addr_fifo_wr_en = mode[0] ? sram_read[1]: sram_read[0];
assign addr_fifo_in = mode[0] ? sram_read_addr[1]: sram_read_addr[0];

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wr_ptr <= 2'h0;
    rd_ptr <= 2'h0;
    addr_fifo <= 36'h0;
    addr_fifo_out <= 9'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      wr_ptr <= 2'h0;
      rd_ptr <= 2'h0;
      addr_fifo <= 36'h0;
      addr_fifo_out <= 9'h0;
    end
    else if (mode[1] == 1'h1) begin
      if (addr_fifo_wr_en) begin
        wr_ptr <= wr_ptr + 2'h1;
        addr_fifo[wr_ptr] <= addr_fifo_in;
      end
      if (step) begin
        rd_ptr <= rd_ptr + 2'h1;
      end
      addr_fifo_out <= addr_fifo[rd_ptr];
    end
  end
end
assign addr_out = mode[1] ? addr_fifo_out: lin_addr_cnter + starting_addr;
endmodule   // agg_sram_shared_addr_gen

module agg_sram_shared_sched_gen (
  input logic [5:0] agg_read_padding,
  input logic agg_write,
  input logic [1:0] agg_write_addr_l2b,
  input logic [2:0] agg_write_mux_sel,
  input logic agg_write_restart,
  input logic clk,
  input logic clk_en,
  input logic [3:0] delay,
  input logic flush,
  input logic [1:0] mode,
  input logic rst_n,
  input logic [1:0] sram_read,
  output logic valid_output
);

logic agg_write_4_r;
logic [5:0] pad_cnt;
logic pad_cnt_en;
logic [15:0] shifter;
logic shifter_in;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    agg_write_4_r <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      agg_write_4_r <= 1'h0;
    end
    else if (mode[1] == 1'h0) begin
      agg_write_4_r <= agg_write & (&agg_write_addr_l2b);
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    pad_cnt_en <= 1'h0;
    pad_cnt <= 6'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      pad_cnt_en <= 1'h0;
      pad_cnt <= 6'h0;
    end
    else if ((mode[1] == 1'h0) & (agg_read_padding != 6'h0)) begin
      if (agg_write & ((agg_write_mux_sel != 3'h0) | agg_write_restart)) begin
        pad_cnt_en <= 1'h1;
      end
      else if (pad_cnt == agg_read_padding) begin
        pad_cnt_en <= 1'h0;
      end
      if (pad_cnt == agg_read_padding) begin
        pad_cnt <= 6'h0;
      end
      else if (pad_cnt_en | (agg_write & ((agg_write_mux_sel != 3'h0) | agg_write_restart))) begin
        pad_cnt <= pad_cnt + 6'h1;
      end
    end
  end
end
always_comb begin
  if (mode[1] == 1'h0) begin
    shifter_in = 1'h0;
  end
  else shifter_in = mode[0] ? sram_read[1]: sram_read[0];
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    shifter <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      shifter <= 16'h0;
    end
    else if (mode[1] != 1'h0) begin
      shifter <= {shifter[14:0], shifter_in};
    end
  end
end
always_comb begin
  if (mode[1] == 1'h0) begin
    if (agg_read_padding != 6'h0) begin
      valid_output = (agg_read_padding == pad_cnt) | agg_write_4_r;
    end
    else valid_output = agg_write_4_r;
  end
  else valid_output = shifter[delay];
end
endmodule   // agg_sram_shared_sched_gen

module for_loop_3_10 #(
  parameter CONFIG_WIDTH = 5'hA,
  parameter ITERATOR_SUPPORT = 3'h3
)
(
  input logic clk,
  input logic clk_en,
  input logic [2:0] dimensionality,
  input logic flush,
  input logic [2:0] [9:0] ranges,
  input logic rst_n,
  input logic step,
  output logic [1:0] mux_sel_out,
  output logic restart
);

logic [2:0] clear;
logic [2:0][9:0] dim_counter;
logic done;
logic [2:0] inc;
logic [9:0] inced_cnt;
logic [2:0] max_value;
logic maxed_value;
logic [1:0] mux_sel;
assign mux_sel_out = mux_sel;
assign inced_cnt = dim_counter[mux_sel] + 10'h1;
assign maxed_value = (dim_counter[mux_sel] == ranges[mux_sel]) & inc[mux_sel];
always_comb begin
  mux_sel = 2'h0;
  done = 1'h0;
  if (~done) begin
    if ((~max_value[0]) & (dimensionality > 3'h0)) begin
      mux_sel = 2'h0;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[1]) & (dimensionality > 3'h1)) begin
      mux_sel = 2'h1;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[2]) & (dimensionality > 3'h2)) begin
      mux_sel = 2'h2;
      done = 1'h1;
    end
  end
end
always_comb begin
  clear[0] = 1'h0;
  if (((mux_sel > 2'h0) | (~done)) & step) begin
    clear[0] = 1'h1;
  end
end
always_comb begin
  inc[0] = 1'h0;
  if ((5'h0 == 5'h0) & step & (dimensionality > 3'h0)) begin
    inc[0] = 1'h1;
  end
  else if ((mux_sel == 2'h0) & step & (dimensionality > 3'h0)) begin
    inc[0] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[0] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[0] <= 10'h0;
    end
    else if (clear[0]) begin
      dim_counter[0] <= 10'h0;
    end
    else if (inc[0]) begin
      dim_counter[0] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[0] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[0] <= 1'h0;
    end
    else if (clear[0]) begin
      max_value[0] <= 1'h0;
    end
    else if (inc[0]) begin
      max_value[0] <= maxed_value;
    end
  end
end
always_comb begin
  clear[1] = 1'h0;
  if (((mux_sel > 2'h1) | (~done)) & step) begin
    clear[1] = 1'h1;
  end
end
always_comb begin
  inc[1] = 1'h0;
  if ((5'h1 == 5'h0) & step & (dimensionality > 3'h1)) begin
    inc[1] = 1'h1;
  end
  else if ((mux_sel == 2'h1) & step & (dimensionality > 3'h1)) begin
    inc[1] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[1] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[1] <= 10'h0;
    end
    else if (clear[1]) begin
      dim_counter[1] <= 10'h0;
    end
    else if (inc[1]) begin
      dim_counter[1] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[1] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[1] <= 1'h0;
    end
    else if (clear[1]) begin
      max_value[1] <= 1'h0;
    end
    else if (inc[1]) begin
      max_value[1] <= maxed_value;
    end
  end
end
always_comb begin
  clear[2] = 1'h0;
  if (((mux_sel > 2'h2) | (~done)) & step) begin
    clear[2] = 1'h1;
  end
end
always_comb begin
  inc[2] = 1'h0;
  if ((5'h2 == 5'h0) & step & (dimensionality > 3'h2)) begin
    inc[2] = 1'h1;
  end
  else if ((mux_sel == 2'h2) & step & (dimensionality > 3'h2)) begin
    inc[2] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[2] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[2] <= 10'h0;
    end
    else if (clear[2]) begin
      dim_counter[2] <= 10'h0;
    end
    else if (inc[2]) begin
      dim_counter[2] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[2] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[2] <= 1'h0;
    end
    else if (clear[2]) begin
      max_value[2] <= 1'h0;
    end
    else if (inc[2]) begin
      max_value[2] <= maxed_value;
    end
  end
end
assign restart = step & (~done);
endmodule   // for_loop_3_10

module for_loop_6_10 #(
  parameter CONFIG_WIDTH = 5'hA,
  parameter ITERATOR_SUPPORT = 4'h6
)
(
  input logic clk,
  input logic clk_en,
  input logic [3:0] dimensionality,
  input logic flush,
  input logic [5:0] [9:0] ranges,
  input logic rst_n,
  input logic step,
  output logic [2:0] mux_sel_out,
  output logic restart
);

logic [5:0] clear;
logic [5:0][9:0] dim_counter;
logic done;
logic [5:0] inc;
logic [9:0] inced_cnt;
logic [5:0] max_value;
logic maxed_value;
logic [2:0] mux_sel;
assign mux_sel_out = mux_sel;
assign inced_cnt = dim_counter[mux_sel] + 10'h1;
assign maxed_value = (dim_counter[mux_sel] == ranges[mux_sel]) & inc[mux_sel];
always_comb begin
  mux_sel = 3'h0;
  done = 1'h0;
  if (~done) begin
    if ((~max_value[0]) & (dimensionality > 4'h0)) begin
      mux_sel = 3'h0;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[1]) & (dimensionality > 4'h1)) begin
      mux_sel = 3'h1;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[2]) & (dimensionality > 4'h2)) begin
      mux_sel = 3'h2;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[3]) & (dimensionality > 4'h3)) begin
      mux_sel = 3'h3;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[4]) & (dimensionality > 4'h4)) begin
      mux_sel = 3'h4;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[5]) & (dimensionality > 4'h5)) begin
      mux_sel = 3'h5;
      done = 1'h1;
    end
  end
end
always_comb begin
  clear[0] = 1'h0;
  if (((mux_sel > 3'h0) | (~done)) & step) begin
    clear[0] = 1'h1;
  end
end
always_comb begin
  inc[0] = 1'h0;
  if ((5'h0 == 5'h0) & step & (dimensionality > 4'h0)) begin
    inc[0] = 1'h1;
  end
  else if ((mux_sel == 3'h0) & step & (dimensionality > 4'h0)) begin
    inc[0] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[0] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[0] <= 10'h0;
    end
    else if (clear[0]) begin
      dim_counter[0] <= 10'h0;
    end
    else if (inc[0]) begin
      dim_counter[0] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[0] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[0] <= 1'h0;
    end
    else if (clear[0]) begin
      max_value[0] <= 1'h0;
    end
    else if (inc[0]) begin
      max_value[0] <= maxed_value;
    end
  end
end
always_comb begin
  clear[1] = 1'h0;
  if (((mux_sel > 3'h1) | (~done)) & step) begin
    clear[1] = 1'h1;
  end
end
always_comb begin
  inc[1] = 1'h0;
  if ((5'h1 == 5'h0) & step & (dimensionality > 4'h1)) begin
    inc[1] = 1'h1;
  end
  else if ((mux_sel == 3'h1) & step & (dimensionality > 4'h1)) begin
    inc[1] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[1] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[1] <= 10'h0;
    end
    else if (clear[1]) begin
      dim_counter[1] <= 10'h0;
    end
    else if (inc[1]) begin
      dim_counter[1] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[1] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[1] <= 1'h0;
    end
    else if (clear[1]) begin
      max_value[1] <= 1'h0;
    end
    else if (inc[1]) begin
      max_value[1] <= maxed_value;
    end
  end
end
always_comb begin
  clear[2] = 1'h0;
  if (((mux_sel > 3'h2) | (~done)) & step) begin
    clear[2] = 1'h1;
  end
end
always_comb begin
  inc[2] = 1'h0;
  if ((5'h2 == 5'h0) & step & (dimensionality > 4'h2)) begin
    inc[2] = 1'h1;
  end
  else if ((mux_sel == 3'h2) & step & (dimensionality > 4'h2)) begin
    inc[2] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[2] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[2] <= 10'h0;
    end
    else if (clear[2]) begin
      dim_counter[2] <= 10'h0;
    end
    else if (inc[2]) begin
      dim_counter[2] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[2] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[2] <= 1'h0;
    end
    else if (clear[2]) begin
      max_value[2] <= 1'h0;
    end
    else if (inc[2]) begin
      max_value[2] <= maxed_value;
    end
  end
end
always_comb begin
  clear[3] = 1'h0;
  if (((mux_sel > 3'h3) | (~done)) & step) begin
    clear[3] = 1'h1;
  end
end
always_comb begin
  inc[3] = 1'h0;
  if ((5'h3 == 5'h0) & step & (dimensionality > 4'h3)) begin
    inc[3] = 1'h1;
  end
  else if ((mux_sel == 3'h3) & step & (dimensionality > 4'h3)) begin
    inc[3] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[3] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[3] <= 10'h0;
    end
    else if (clear[3]) begin
      dim_counter[3] <= 10'h0;
    end
    else if (inc[3]) begin
      dim_counter[3] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[3] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[3] <= 1'h0;
    end
    else if (clear[3]) begin
      max_value[3] <= 1'h0;
    end
    else if (inc[3]) begin
      max_value[3] <= maxed_value;
    end
  end
end
always_comb begin
  clear[4] = 1'h0;
  if (((mux_sel > 3'h4) | (~done)) & step) begin
    clear[4] = 1'h1;
  end
end
always_comb begin
  inc[4] = 1'h0;
  if ((5'h4 == 5'h0) & step & (dimensionality > 4'h4)) begin
    inc[4] = 1'h1;
  end
  else if ((mux_sel == 3'h4) & step & (dimensionality > 4'h4)) begin
    inc[4] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[4] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[4] <= 10'h0;
    end
    else if (clear[4]) begin
      dim_counter[4] <= 10'h0;
    end
    else if (inc[4]) begin
      dim_counter[4] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[4] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[4] <= 1'h0;
    end
    else if (clear[4]) begin
      max_value[4] <= 1'h0;
    end
    else if (inc[4]) begin
      max_value[4] <= maxed_value;
    end
  end
end
always_comb begin
  clear[5] = 1'h0;
  if (((mux_sel > 3'h5) | (~done)) & step) begin
    clear[5] = 1'h1;
  end
end
always_comb begin
  inc[5] = 1'h0;
  if ((5'h5 == 5'h0) & step & (dimensionality > 4'h5)) begin
    inc[5] = 1'h1;
  end
  else if ((mux_sel == 3'h5) & step & (dimensionality > 4'h5)) begin
    inc[5] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[5] <= 10'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[5] <= 10'h0;
    end
    else if (clear[5]) begin
      dim_counter[5] <= 10'h0;
    end
    else if (inc[5]) begin
      dim_counter[5] <= inced_cnt;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    max_value[5] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      max_value[5] <= 1'h0;
    end
    else if (clear[5]) begin
      max_value[5] <= 1'h0;
    end
    else if (inc[5]) begin
      max_value[5] <= maxed_value;
    end
  end
end
assign restart = step & (~done);
endmodule   // for_loop_6_10

module reg_fifo_d_4_w_1 #(
  parameter data_width = 16'h10
)
(
  input logic clk,
  input logic clk_en,
  input logic [0:0] [data_width-1:0] data_in,
  input logic flush,
  input logic [2:0] num_load,
  input logic [3:0][0:0] [data_width-1:0] parallel_in,
  input logic parallel_load,
  input logic parallel_read,
  input logic pop,
  input logic push,
  input logic rst_n,
  output logic [0:0] [data_width-1:0] data_out,
  output logic empty,
  output logic full,
  output logic [3:0][0:0] [data_width-1:0] parallel_out,
  output logic [1:0] rd_ptr_out,
  output logic valid
);

logic [2:0] num_items;
logic passthru;
logic [1:0] rd_ptr;
logic read;
logic [3:0][0:0][data_width-1:0] reg_array;
logic [1:0] wr_ptr;
logic write;
assign rd_ptr_out = rd_ptr;
assign full = num_items == 3'h4;
assign empty = num_items == 3'h0;
assign read = pop & (~passthru) & (~empty);
assign passthru = pop & push & empty;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    num_items <= 3'h0;
  end
  else if (flush) begin
    num_items <= 3'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      if (num_load == 3'h0) begin
        num_items <= 3'(push);
      end
      else num_items <= num_load;
    end
    else if (parallel_read) begin
      if (push) begin
        num_items <= 3'h1;
      end
      else num_items <= 3'h0;
    end
    else if (write & (~read)) begin
      num_items <= num_items + 3'h1;
    end
    else if ((~write) & read) begin
      num_items <= num_items - 3'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    reg_array <= 64'h0;
  end
  else if (flush) begin
    reg_array <= 64'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      reg_array <= parallel_in;
    end
    else if (write) begin
      if (parallel_read) begin
        reg_array[0] <= data_in;
      end
      else reg_array[wr_ptr] <= data_in;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wr_ptr <= 2'h0;
  end
  else if (flush) begin
    wr_ptr <= 2'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      wr_ptr <= num_load[1:0];
    end
    else if (parallel_read) begin
      if (push) begin
        wr_ptr <= 2'h1;
      end
      else wr_ptr <= 2'h0;
    end
    else if (write) begin
      wr_ptr <= wr_ptr + 2'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    rd_ptr <= 2'h0;
  end
  else if (flush) begin
    rd_ptr <= 2'h0;
  end
  else if (clk_en) begin
    if (parallel_load | parallel_read) begin
      rd_ptr <= 2'h0;
    end
    else if (read) begin
      rd_ptr <= rd_ptr + 2'h1;
    end
  end
end
assign parallel_out = reg_array;
assign write = push & (~passthru) & ((~full) | pop | parallel_read);
always_comb begin
  if (passthru) begin
    data_out = data_in;
  end
  else data_out = reg_array[rd_ptr];
end
always_comb begin
  valid = pop & ((~empty) | passthru);
end
endmodule   // reg_fifo_d_4_w_1

module reg_fifo_d_4_w_1_unq0 #(
  parameter data_width = 16'h10
)
(
  input logic clk,
  input logic clk_en,
  input logic [0:0] [data_width-1:0] data_in,
  input logic flush,
  input logic [2:0] num_load,
  input logic [3:0][0:0] [data_width-1:0] parallel_in,
  input logic parallel_load,
  input logic parallel_read,
  input logic pop,
  input logic push,
  input logic rst_n,
  output logic [0:0] [data_width-1:0] data_out,
  output logic empty,
  output logic full,
  output logic [3:0][0:0] [data_width-1:0] parallel_out,
  output logic valid
);

logic [2:0] num_items;
logic passthru;
logic [1:0] rd_ptr;
logic read;
logic [3:0][0:0][data_width-1:0] reg_array;
logic [1:0] wr_ptr;
logic write;
assign full = num_items == 3'h4;
assign empty = num_items == 3'h0;
assign read = pop & (~passthru) & (~empty);
assign passthru = pop & push & empty;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    num_items <= 3'h0;
  end
  else if (flush) begin
    num_items <= 3'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      if (num_load == 3'h0) begin
        num_items <= 3'(push);
      end
      else num_items <= num_load;
    end
    else if (parallel_read) begin
      if (push) begin
        num_items <= 3'h1;
      end
      else num_items <= 3'h0;
    end
    else if (write & (~read)) begin
      num_items <= num_items + 3'h1;
    end
    else if ((~write) & read) begin
      num_items <= num_items - 3'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    reg_array <= 64'h0;
  end
  else if (flush) begin
    reg_array <= 64'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      reg_array <= parallel_in;
    end
    else if (write) begin
      if (parallel_read) begin
        reg_array[0] <= data_in;
      end
      else reg_array[wr_ptr] <= data_in;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wr_ptr <= 2'h0;
  end
  else if (flush) begin
    wr_ptr <= 2'h0;
  end
  else if (clk_en) begin
    if (parallel_load) begin
      wr_ptr <= num_load[1:0];
    end
    else if (parallel_read) begin
      if (push) begin
        wr_ptr <= 2'h1;
      end
      else wr_ptr <= 2'h0;
    end
    else if (write) begin
      wr_ptr <= wr_ptr + 2'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    rd_ptr <= 2'h0;
  end
  else if (flush) begin
    rd_ptr <= 2'h0;
  end
  else if (clk_en) begin
    if (parallel_load | parallel_read) begin
      rd_ptr <= 2'h0;
    end
    else if (read) begin
      rd_ptr <= rd_ptr + 2'h1;
    end
  end
end
assign parallel_out = reg_array;
assign write = push & (~passthru) & ((~full) | pop | parallel_read);
always_comb begin
  if (passthru) begin
    data_out = data_in;
  end
  else data_out = reg_array[rd_ptr];
end
always_comb begin
  valid = pop & ((~empty) | passthru);
end
endmodule   // reg_fifo_d_4_w_1_unq0

module sched_gen_6_16 (
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic enable,
  input logic finished,
  input logic flush,
  input logic [2:0] mux_sel,
  input logic rst_n,
  input logic [15:0] sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] sched_addr_gen_strides,
  output logic valid_output
);

logic [15:0] addr_out;
logic valid_gate;
logic valid_gate_inv;
logic valid_out;
assign valid_gate = ~valid_gate_inv;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    valid_gate_inv <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      valid_gate_inv <= 1'h0;
    end
    else if (finished) begin
      valid_gate_inv <= 1'h1;
    end
  end
end
always_comb begin
  valid_out = (cycle_count == addr_out) & valid_gate & enable;
end
always_comb begin
  valid_output = valid_out;
end
addr_gen_6_16 sched_addr_gen (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(mux_sel),
  .restart(1'h0),
  .rst_n(rst_n),
  .starting_addr(sched_addr_gen_starting_addr),
  .step(valid_out),
  .strides(sched_addr_gen_strides),
  .addr_out(addr_out)
);

endmodule   // sched_gen_6_16

module sram_sp__0 (
  input logic clk,
  input logic clk_en,
  input logic [63:0] data_in_p0,
  input logic flush,
  input logic [8:0] read_addr_p0,
  input logic read_enable_p0,
  input logic [8:0] write_addr_p0,
  input logic write_enable_p0,
  output logic [63:0] data_out_p0
);

logic [63:0] data_array [511:0];

always_ff @(posedge clk) begin
  if (clk_en) begin
    if (write_enable_p0 == 1'h1) begin
      data_array[write_addr_p0] <= data_in_p0;
    end
    else if (read_enable_p0) begin
      data_out_p0 <= data_array[read_addr_p0];
    end
  end
end
endmodule   // sram_sp__0

module stencil_valid (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic [3:0] loops_stencil_valid_dimensionality,
  input logic [5:0] [9:0] loops_stencil_valid_ranges,
  input logic rst_n,
  input logic stencil_valid_sched_gen_enable,
  input logic [15:0] stencil_valid_sched_gen_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] stencil_valid_sched_gen_sched_addr_gen_strides,
  output logic stencil_valid
);

logic [15:0] cycle_count;
logic flushed;
logic [2:0] loops_stencil_valid_mux_sel_out;
logic loops_stencil_valid_restart;
logic stencil_valid_internal;
assign stencil_valid = stencil_valid_internal & flushed;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    cycle_count <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      cycle_count <= 16'h0;
    end
    else if (flushed) begin
      cycle_count <= cycle_count + 16'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    flushed <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      flushed <= 1'h1;
    end
  end
end
for_loop_6_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(4'h6))
loops_stencil_valid (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_stencil_valid_dimensionality),
  .flush(flush),
  .ranges(loops_stencil_valid_ranges),
  .rst_n(rst_n),
  .step(stencil_valid_internal),
  .mux_sel_out(loops_stencil_valid_mux_sel_out),
  .restart(loops_stencil_valid_restart)
);

sched_gen_6_16 stencil_valid_sched_gen (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(stencil_valid_sched_gen_enable),
  .finished(loops_stencil_valid_restart),
  .flush(flush),
  .mux_sel(loops_stencil_valid_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(stencil_valid_sched_gen_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(stencil_valid_sched_gen_sched_addr_gen_strides),
  .valid_output(stencil_valid_internal)
);

endmodule   // stencil_valid

module stencil_valid_flat (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic rst_n,
  input logic [3:0] stencil_valid_inst_loops_stencil_valid_dimensionality,
  input logic [5:0] [9:0] stencil_valid_inst_loops_stencil_valid_ranges,
  input logic stencil_valid_inst_stencil_valid_sched_gen_enable,
  input logic [15:0] stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides,
  output logic stencil_valid_f_
);

stencil_valid stencil_valid_inst (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .loops_stencil_valid_dimensionality(stencil_valid_inst_loops_stencil_valid_dimensionality),
  .loops_stencil_valid_ranges(stencil_valid_inst_loops_stencil_valid_ranges),
  .rst_n(rst_n),
  .stencil_valid_sched_gen_enable(stencil_valid_inst_stencil_valid_sched_gen_enable),
  .stencil_valid_sched_gen_sched_addr_gen_starting_addr(stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr),
  .stencil_valid_sched_gen_sched_addr_gen_strides(stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides),
  .stencil_valid(stencil_valid_f_)
);

endmodule   // stencil_valid_flat

module storage_config_seq (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [15:0] config_data_in,
  input logic [1:0] config_en,
  input logic config_rd,
  input logic config_wr,
  input logic flush,
  input logic [0:0][3:0] [15:0] rd_data_stg,
  input logic rst_n,
  output logic [8:0] addr_out,
  output logic [1:0] [15:0] rd_data_out,
  output logic ren_out,
  output logic wen_out,
  output logic [3:0] [15:0] wr_data
);

logic [1:0] cnt;
logic [2:0][15:0] data_wr_reg;
logic [1:0] rd_cnt;
logic rd_valid;
logic [1:0] reduce_en;
logic set_to_addr;
assign reduce_en[0] = |config_en[0];
assign reduce_en[1] = |config_en[1];
always_comb begin
  set_to_addr = 1'h0;
  for (int unsigned i = 0; i < 2; i += 1) begin
      if (reduce_en[1'(i)]) begin
        set_to_addr = 1'(i);
      end
    end
end
assign addr_out = {set_to_addr, config_addr_in};

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    cnt <= 2'h0;
  end
  else if (flush) begin
    cnt <= 2'h0;
  end
  else if (config_wr & (|config_en)) begin
    cnt <= cnt + 2'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    rd_valid <= 1'h0;
  end
  else if (flush) begin
    rd_valid <= 1'h0;
  end
  else rd_valid <= config_rd & (|config_en);
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    rd_cnt <= 2'h0;
  end
  else if (flush) begin
    rd_cnt <= 2'h0;
  end
  else if (rd_valid & (~(config_rd & (|config_en)))) begin
    rd_cnt <= rd_cnt + 2'h1;
  end
end
assign rd_data_out[0] = rd_data_stg[0][rd_cnt];
assign rd_data_out[1] = rd_data_stg[0][rd_cnt];

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    data_wr_reg <= 48'h0;
  end
  else if (flush) begin
    data_wr_reg <= 48'h0;
  end
  else if (config_wr & (cnt < 2'h3)) begin
    data_wr_reg[cnt] <= config_data_in;
  end
end
assign wr_data[0] = data_wr_reg[0];
assign wr_data[1] = data_wr_reg[1];
assign wr_data[2] = data_wr_reg[2];
assign wr_data[3] = config_data_in;
assign wen_out = config_wr & (cnt == 2'h3);
assign ren_out = config_rd;
endmodule   // storage_config_seq

module strg_fifo (
  input logic clk,
  input logic clk_en,
  input logic [0:0][3:0] [15:0] data_from_strg,
  input logic [15:0] data_in,
  input logic [15:0] fifo_depth,
  input logic flush,
  input logic pop,
  input logic push,
  input logic rst_n,
  output logic [0:0] [8:0] addr_out,
  output logic [15:0] data_out,
  output logic [0:0][3:0] [15:0] data_to_strg,
  output logic empty,
  output logic full,
  output logic ren_to_strg,
  output logic valid_out,
  output logic wen_to_strg
);

logic [15:0] back_data_in;
logic [15:0] back_data_out;
logic back_empty;
logic back_full;
logic [2:0] back_num_load;
logic [2:0] back_occ;
logic [3:0][0:0][15:0] back_par_in;
logic back_pl;
logic back_pop;
logic back_push;
logic [0:0][15:0] back_rf_data_in;
logic [0:0][15:0] back_rf_data_out;
logic back_rf_parallel_load;
logic back_valid;
logic curr_bank_rd;
logic curr_bank_wr;
logic [3:0][15:0] front_combined;
logic [15:0] front_data_out;
logic front_empty;
logic front_full;
logic [2:0] front_occ;
logic [3:0][0:0][15:0] front_par_out;
logic front_par_read;
logic front_pop;
logic front_push;
logic [1:0] front_rd_ptr;
logic [0:0][15:0] front_rf_data_in;
logic [0:0][15:0] front_rf_data_out;
logic front_valid;
logic fw_is_1;
logic [15:0] num_items;
logic [15:0] num_words_mem;
logic prev_bank_rd;
logic queued_write;
logic [0:0][8:0] ren_addr;
logic ren_delay;
logic [0:0][8:0] wen_addr;
logic [0:0][3:0][15:0] write_queue;
assign curr_bank_wr = 1'h0;
assign curr_bank_rd = 1'h0;
assign front_push = push & ((~full) | pop);
assign front_rf_data_in[0] = data_in;
assign front_data_out = front_rf_data_out[0];
assign fw_is_1 = 1'h0;
assign back_pop = pop & ((~empty) | push);
assign back_rf_parallel_load = back_pl & (|back_num_load);
assign back_rf_data_in[0] = back_data_in;
assign back_data_out = back_rf_data_out[0];
always_comb begin
  wen_to_strg = ((~ren_to_strg) | 1'h0) & (queued_write | ((front_occ == 3'h4) & push &
      (~front_pop) & (curr_bank_wr == 1'h0)));
end
always_comb begin
  ren_to_strg = ((back_occ == 3'h1) | fw_is_1) & (curr_bank_rd == 1'h0) & (pop | ((back_occ ==
      3'h0) & (back_num_load == 3'h0))) & ((num_words_mem > 16'h1) | ((num_words_mem
      == 16'h1) & (~back_pl)));
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    ren_delay <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      ren_delay <= 1'h0;
    end
    else ren_delay <= |ren_to_strg;
  end
end
assign back_pl = ren_delay;
assign front_combined[0] = front_par_out[front_rd_ptr + 2'h0];
assign front_combined[1] = front_par_out[front_rd_ptr + 2'h1];
assign front_combined[2] = front_par_out[front_rd_ptr + 2'h2];
assign front_combined[3] = front_par_out[front_rd_ptr + 2'h3];
assign data_to_strg[0] = queued_write ? write_queue[0]: front_combined;
assign back_data_in = front_data_out;
assign back_push = front_valid;
always_comb begin
  front_pop = ((num_words_mem == 16'h0) | ((num_words_mem == 16'h1) & back_pl)) & ((~back_pl)
      | (back_pl & (back_num_load == 3'h0))) & ((~(back_occ == 3'h4)) | pop) &
      ((~(front_occ == 3'h0)) | push);
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    write_queue[0] <= 64'h0;
    queued_write <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      write_queue[0] <= 64'h0;
      queued_write <= 1'h0;
    end
    else if (front_par_read & (~wen_to_strg) & (curr_bank_wr == 1'h0)) begin
      write_queue[0] <= front_combined;
      queued_write <= 1'h1;
    end
    else if (wen_to_strg) begin
      queued_write <= 1'h0;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    num_words_mem <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      num_words_mem <= 16'h0;
    end
    else if ((~back_pl) & front_par_read) begin
      num_words_mem <= num_words_mem + 16'h1;
    end
    else if (back_pl & (~front_par_read)) begin
      num_words_mem <= num_words_mem - 16'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    front_occ <= 3'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      front_occ <= 3'h0;
    end
    else if (front_par_read) begin
      if (front_push) begin
        front_occ <= 3'h1;
      end
      else front_occ <= 3'h0;
    end
    else if (front_push & (~front_pop)) begin
      front_occ <= front_occ + 3'h1;
    end
    else if ((~front_push) & front_pop) begin
      front_occ <= front_occ - 3'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    back_occ <= 3'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      back_occ <= 3'h0;
    end
    else if (back_pl) begin
      if (back_num_load == 3'h0) begin
        back_occ <= 3'(back_push);
      end
      else back_occ <= back_num_load;
    end
    else if (back_push & (~back_pop)) begin
      back_occ <= back_occ + 3'h1;
    end
    else if ((~back_push) & back_pop) begin
      back_occ <= back_occ - 3'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    prev_bank_rd <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      prev_bank_rd <= 1'h0;
    end
    else prev_bank_rd <= curr_bank_rd;
  end
end
assign back_par_in[0] = (back_num_load == 3'h4) ? data_from_strg[prev_bank_rd][0]:
    data_from_strg[prev_bank_rd][1];
assign back_par_in[1] = (back_num_load == 3'h4) ? data_from_strg[prev_bank_rd][1]:
    data_from_strg[prev_bank_rd][2];
assign back_par_in[2] = (back_num_load == 3'h4) ? data_from_strg[prev_bank_rd][2]:
    data_from_strg[prev_bank_rd][3];
assign back_par_in[3] = (back_num_load == 3'h4) ? data_from_strg[prev_bank_rd][3]: 16'h0;
always_comb begin
  front_par_read = (front_occ == 3'h4) & push & (~front_pop);
end
always_comb begin
  if (back_pl) begin
    back_num_load = pop ? 3'h3: 3'h4;
  end
  else back_num_load = 3'h0;
end
assign data_out = back_pl ? data_from_strg[prev_bank_rd][0]: back_data_out;
assign valid_out = back_pl ? pop: back_valid;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wen_addr[0] <= 9'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      wen_addr[0] <= 9'h0;
    end
    else if (wen_to_strg) begin
      wen_addr[0] <= wen_addr[0] + 9'h1;
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    ren_addr[0] <= 9'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      ren_addr[0] <= 9'h0;
    end
    else if (ren_to_strg) begin
      ren_addr[0] <= ren_addr[0] + 9'h1;
    end
  end
end
assign addr_out[0] = wen_to_strg ? wen_addr[0]: ren_addr[0];
always_comb begin
  num_items = 16'(num_words_mem * 16'h4) + 16'(front_occ) + 16'(back_occ);
end
assign empty = num_items == 16'h0;
assign full = fifo_depth == num_items;
reg_fifo_d_4_w_1 #(
  .data_width(16'h10))
front_rf (
  .clk(clk),
  .clk_en(clk_en),
  .data_in(front_rf_data_in),
  .flush(flush),
  .num_load(3'h0),
  .parallel_in(64'h0),
  .parallel_load(1'h0),
  .parallel_read(front_par_read),
  .pop(front_pop),
  .push(front_push),
  .rst_n(rst_n),
  .data_out(front_rf_data_out),
  .empty(front_empty),
  .full(front_full),
  .parallel_out(front_par_out),
  .rd_ptr_out(front_rd_ptr),
  .valid(front_valid)
);

reg_fifo_d_4_w_1_unq0 #(
  .data_width(16'h10))
back_rf (
  .clk(clk),
  .clk_en(clk_en),
  .data_in(back_rf_data_in),
  .flush(flush),
  .num_load(back_num_load),
  .parallel_in(back_par_in),
  .parallel_load(back_rf_parallel_load),
  .parallel_read(1'h0),
  .pop(back_pop),
  .push(back_push),
  .rst_n(rst_n),
  .data_out(back_rf_data_out),
  .empty(back_empty),
  .full(back_full),
  .valid(back_valid)
);

endmodule   // strg_fifo

module strg_fifo_flat (
  input logic clk,
  input logic clk_en,
  input logic [0:0][3:0] [15:0] data_from_strg_lifted,
  input logic [0:0] [15:0] data_in_f_,
  input logic flush,
  input logic pop_f_,
  input logic push_f_,
  input logic rst_n,
  input logic [15:0] strg_fifo_inst_fifo_depth,
  output logic [0:0] [8:0] addr_out_lifted,
  output logic [0:0] [15:0] data_out_f_,
  output logic [0:0][3:0] [15:0] data_to_strg_lifted,
  output logic empty_f_,
  output logic full_f_,
  output logic ren_to_strg_lifted,
  output logic valid_out_f_,
  output logic wen_to_strg_lifted
);

logic [0:0][15:0] data_in_f__intercept;
logic [0:0][15:0] data_out_f__intercept;
logic [15:0] strg_fifo_inst_data_out;
assign data_in_f__intercept = data_in_f_;
assign data_out_f__intercept[0] = strg_fifo_inst_data_out;
assign data_out_f_ = data_out_f__intercept;
strg_fifo strg_fifo_inst (
  .clk(clk),
  .clk_en(clk_en),
  .data_from_strg(data_from_strg_lifted),
  .data_in(data_in_f__intercept[0]),
  .fifo_depth(strg_fifo_inst_fifo_depth),
  .flush(flush),
  .pop(pop_f_),
  .push(push_f_),
  .rst_n(rst_n),
  .addr_out(addr_out_lifted),
  .data_out(strg_fifo_inst_data_out),
  .data_to_strg(data_to_strg_lifted),
  .empty(empty_f_),
  .full(full_f_),
  .ren_to_strg(ren_to_strg_lifted),
  .valid_out(valid_out_f_),
  .wen_to_strg(wen_to_strg_lifted)
);

endmodule   // strg_fifo_flat

module strg_ram (
  input logic clk,
  input logic clk_en,
  input logic [0:0][3:0] [15:0] data_from_strg,
  input logic [15:0] data_in,
  input logic flush,
  input logic [15:0] rd_addr_in,
  input logic ren,
  input logic rst_n,
  input logic wen,
  input logic [15:0] wr_addr_in,
  output logic [0:0] [8:0] addr_out,
  output logic [15:0] data_out,
  output logic [0:0][3:0] [15:0] data_to_strg,
  output logic ready,
  output logic ren_to_strg,
  output logic valid_out,
  output logic wen_to_strg
);

typedef enum logic[1:0] {
  IDLE = 2'h0,
  MODIFY = 2'h1,
  READ = 2'h2,
  _DEFAULT = 2'h3
} r_w_seq_state;
logic [15:0] addr_to_write;
logic [3:0][15:0] data_combined;
logic [15:0] data_to_write;
r_w_seq_state r_w_seq_current_state;
r_w_seq_state r_w_seq_next_state;
logic [15:0] rd_addr;
logic rd_bank;
logic rd_valid;
logic read_gate;
logic [15:0] wr_addr;
logic write_gate;
assign wr_addr = wr_addr_in;
assign rd_addr = wr_addr_in;
assign rd_bank = 1'h0;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    rd_valid <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      rd_valid <= 1'h0;
    end
    else rd_valid <= ren & (~wen);
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    data_to_write <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      data_to_write <= 16'h0;
    end
    else data_to_write <= data_in;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    addr_to_write <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      addr_to_write <= 16'h0;
    end
    else addr_to_write <= wr_addr;
  end
end
assign data_to_strg[0] = data_combined;
assign ren_to_strg = (wen | ren) & read_gate;
assign wen_to_strg = write_gate;
always_comb begin
  addr_out[0] = rd_addr[10:2];
  if (wen & (~write_gate)) begin
    addr_out[0] = wr_addr[10:2];
  end
  else if (write_gate) begin
    addr_out[0] = addr_to_write[10:2];
  end
end
always_comb begin
  if (addr_to_write[1:0] == 2'h0) begin
    data_combined[0] = data_to_write;
  end
  else data_combined[0] = data_from_strg[rd_bank][0];
end
always_comb begin
  if (addr_to_write[1:0] == 2'h1) begin
    data_combined[1] = data_to_write;
  end
  else data_combined[1] = data_from_strg[rd_bank][1];
end
always_comb begin
  if (addr_to_write[1:0] == 2'h2) begin
    data_combined[2] = data_to_write;
  end
  else data_combined[2] = data_from_strg[rd_bank][2];
end
always_comb begin
  if (addr_to_write[1:0] == 2'h3) begin
    data_combined[3] = data_to_write;
  end
  else data_combined[3] = data_from_strg[rd_bank][3];
end

always_ff @(posedge clk, negedge rst_n) begin
  if (!rst_n) begin
    r_w_seq_current_state <= IDLE;
  end
  else r_w_seq_current_state <= r_w_seq_next_state;
end
always_comb begin
  r_w_seq_next_state = r_w_seq_current_state;
  unique case (r_w_seq_current_state)
    IDLE: begin
        if ((~wen) & (~ren)) begin
          r_w_seq_next_state = IDLE;
        end
        else if (ren & (~wen)) begin
          r_w_seq_next_state = READ;
        end
        else if (wen) begin
          r_w_seq_next_state = MODIFY;
        end
      end
    MODIFY: begin
        if (1'h1) begin
          r_w_seq_next_state = IDLE;
        end
      end
    READ: begin
        if ((~wen) & (~ren)) begin
          r_w_seq_next_state = IDLE;
        end
        else if (ren & (~wen)) begin
          r_w_seq_next_state = READ;
        end
        else if (wen) begin
          r_w_seq_next_state = MODIFY;
        end
      end
    _DEFAULT: begin
        if (1'h1) begin
          r_w_seq_next_state = _DEFAULT;
        end
      end
    default: begin end
  endcase
end
always_comb begin
  unique case (r_w_seq_current_state)
    IDLE: begin :r_w_seq_IDLE_Output
        ready = 1'h1;
        valid_out = 1'h0;
        data_out = 16'h0;
        write_gate = 1'h0;
        read_gate = 1'h1;
      end :r_w_seq_IDLE_Output
    MODIFY: begin :r_w_seq_MODIFY_Output
        ready = 1'h0;
        valid_out = 1'h0;
        data_out = 16'h0;
        write_gate = 1'h1;
        read_gate = 1'h0;
      end :r_w_seq_MODIFY_Output
    READ: begin :r_w_seq_READ_Output
        ready = 1'h1;
        valid_out = 1'h1;
        data_out = data_from_strg[rd_bank][addr_to_write[1:0]];
        write_gate = 1'h0;
        read_gate = 1'h1;
      end :r_w_seq_READ_Output
    _DEFAULT: begin :r_w_seq__DEFAULT_Output
        ready = 1'h0;
        valid_out = 1'h0;
        data_out = 16'h0;
        write_gate = 1'h0;
        read_gate = 1'h0;
      end :r_w_seq__DEFAULT_Output
    default: begin end
  endcase
end
endmodule   // strg_ram

module strg_ram_flat (
  input logic clk,
  input logic clk_en,
  input logic [0:0][3:0] [15:0] data_from_strg_lifted,
  input logic [0:0] [15:0] data_in_f_,
  input logic flush,
  input logic [0:0] [15:0] rd_addr_in_f_,
  input logic ren_f_,
  input logic rst_n,
  input logic wen_f_,
  input logic [0:0] [15:0] wr_addr_in_f_,
  output logic [0:0] [8:0] addr_out_lifted,
  output logic [0:0] [15:0] data_out_f_,
  output logic [0:0][3:0] [15:0] data_to_strg_lifted,
  output logic ready_f_,
  output logic ren_to_strg_lifted,
  output logic valid_out_f_,
  output logic wen_to_strg_lifted
);

logic [0:0][15:0] data_in_f__intercept;
logic [0:0][15:0] data_out_f__intercept;
logic [0:0][15:0] rd_addr_in_f__intercept;
logic [15:0] strg_ram_inst_data_out;
logic [0:0][15:0] wr_addr_in_f__intercept;
assign wr_addr_in_f__intercept = wr_addr_in_f_;
assign data_in_f__intercept = data_in_f_;
assign rd_addr_in_f__intercept = rd_addr_in_f_;
assign data_out_f__intercept[0] = strg_ram_inst_data_out;
assign data_out_f_ = data_out_f__intercept;
strg_ram strg_ram_inst (
  .clk(clk),
  .clk_en(clk_en),
  .data_from_strg(data_from_strg_lifted),
  .data_in(data_in_f__intercept[0]),
  .flush(flush),
  .rd_addr_in(rd_addr_in_f__intercept[0]),
  .ren(ren_f_),
  .rst_n(rst_n),
  .wen(wen_f_),
  .wr_addr_in(wr_addr_in_f__intercept[0]),
  .addr_out(addr_out_lifted),
  .data_out(strg_ram_inst_data_out),
  .data_to_strg(data_to_strg_lifted),
  .ready(ready_f_),
  .ren_to_strg(ren_to_strg_lifted),
  .valid_out(valid_out_f_),
  .wen_to_strg(wen_to_strg_lifted)
);

endmodule   // strg_ram_flat

module strg_ub_agg_only (
  input logic [1:0] agg_read,
  input logic [3:0] agg_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] agg_write_addr_gen_0_strides,
  input logic [3:0] agg_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] agg_write_addr_gen_1_strides,
  input logic agg_write_sched_gen_0_enable,
  input logic [15:0] agg_write_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] agg_write_sched_gen_0_sched_addr_gen_strides,
  input logic agg_write_sched_gen_1_enable,
  input logic [15:0] agg_write_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] agg_write_sched_gen_1_sched_addr_gen_strides,
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic [1:0] [15:0] data_in,
  input logic [3:0] delay_0,
  input logic [3:0] delay_1,
  input logic flush,
  input logic [2:0] loops_in2buf_0_dimensionality,
  input logic [2:0] [9:0] loops_in2buf_0_ranges,
  input logic [2:0] loops_in2buf_1_dimensionality,
  input logic [2:0] [9:0] loops_in2buf_1_ranges,
  input logic rst_n,
  input logic [1:0] [8:0] sram_read_addr_in,
  input logic [1:0] [3:0] tb_read_addr_in,
  input logic [1:0] tb_read_in,
  input logic [1:0] [1:0] update_mode_in,
  output logic [1:0][3:0] [15:0] agg_data_out,
  output logic [1:0] [1:0] agg_write_addr_l2b_out,
  output logic [1:0] [2:0] agg_write_mux_sel_out,
  output logic [1:0] agg_write_out,
  output logic [1:0] agg_write_restart_out
);

logic [1:0][3:0][3:0][15:0] agg;
logic [1:0][1:0] agg_read_addr;
logic [1:0][7:0] agg_read_addr_gen_out;
logic [1:0][1:0] agg_read_addr_in;
logic [1:0] agg_write;
logic [1:0][3:0] agg_write_addr;
logic [3:0] agg_write_addr_gen_0_addr_out;
logic [3:0] agg_write_addr_gen_1_addr_out;
logic agg_write_sched_gen_0_valid_output;
logic agg_write_sched_gen_1_valid_output;
logic [2:0] fl_mux_sel_0;
logic [2:0] fl_mux_sel_1;
logic [1:0] loops_in2buf_0_mux_sel_out;
logic loops_in2buf_0_restart;
logic [1:0] loops_in2buf_1_mux_sel_out;
logic loops_in2buf_1_restart;
logic [1:0] mode_0;
logic [1:0] mode_1;
logic [2:0] rd_ptr_0;
logic [2:0] rd_ptr_1;
logic [3:0] tb_addr_0;
logic [3:0] tb_addr_1;
logic [3:0] tb_addr_delayed_0;
logic [3:0] tb_addr_delayed_1;
logic [7:0][3:0] tb_addr_fifo_0;
logic [7:0][3:0] tb_addr_fifo_1;
logic tb_read_0;
logic tb_read_1;
logic tb_read_delayed_0;
logic tb_read_delayed_1;
logic [15:0] tb_read_shift_0;
logic [15:0] tb_read_shift_1;
logic [3:0] tb_shared_addr_0;
logic [3:0] tb_shared_addr_1;
logic tb_shared_wen_0;
logic tb_shared_wen_1;
logic [2:0] wr_ptr_0;
logic [2:0] wr_ptr_1;
assign agg_write_out = agg_write;
assign mode_0 = update_mode_in[0];
assign agg_write_addr_l2b_out[0] = agg_write_addr[0][1:0];
assign tb_read_0 = mode_0[0] ? tb_read_in[1]: tb_read_in[0];
assign tb_addr_0 = mode_0[0] ? tb_read_addr_in[1]: tb_read_addr_in[0];

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wr_ptr_0 <= 3'h0;
    rd_ptr_0 <= 3'h0;
    tb_read_shift_0 <= 16'h0;
    tb_addr_fifo_0 <= 32'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      wr_ptr_0 <= 3'h0;
      rd_ptr_0 <= 3'h0;
      tb_read_shift_0 <= 16'h0;
      tb_addr_fifo_0 <= 32'h0;
    end
    else if ((mode_0[1] == 1'h1) & (delay_0 > 4'h0)) begin
      tb_read_shift_0 <= {tb_read_shift_0[14:1], tb_read_0, 1'h0};
      if (tb_read_0) begin
        tb_addr_fifo_0[wr_ptr_0] <= tb_addr_0;
        wr_ptr_0 <= wr_ptr_0 + 3'h1;
      end
      if (tb_read_delayed_0) begin
        rd_ptr_0 <= rd_ptr_0 + 3'h1;
      end
    end
  end
end
assign tb_read_delayed_0 = tb_read_shift_0[delay_0];
assign tb_addr_delayed_0 = tb_addr_fifo_0[rd_ptr_0];
assign tb_shared_wen_0 = (delay_0 > 4'h0) ? tb_read_delayed_0: tb_read_0;
assign tb_shared_addr_0 = (delay_0 > 4'h0) ? tb_addr_delayed_0: tb_addr_0;
assign fl_mux_sel_0[1:0] = loops_in2buf_0_mux_sel_out;
assign fl_mux_sel_0[2] = 1'h0;
assign agg_write_mux_sel_out[0] = fl_mux_sel_0;
assign agg_write_restart_out[0] = loops_in2buf_0_restart;
assign agg_write_addr[0] = mode_0[1] ? tb_shared_addr_0: agg_write_addr_gen_0_addr_out;
assign agg_write[0] = mode_0[1] ? tb_shared_wen_0: agg_write_sched_gen_0_valid_output;

always_ff @(posedge clk) begin
  if (clk_en) begin
    if (agg_write[0]) begin
      agg[0][agg_write_addr[0][3:2]][agg_write_addr[0][1:0]] <= data_in[0];
    end
  end
end
assign agg_read_addr_in[0] = sram_read_addr_in[0][1:0];
assign agg_read_addr_gen_out[0][1:0] = agg_read_addr_in[0];
assign agg_read_addr_gen_out[0][7:2] = 6'h0;
assign agg_read_addr[0] = agg_read_addr_gen_out[0][1:0];
always_comb begin
  agg_data_out[0] = agg[0][agg_read_addr[0]];
end
assign mode_1 = update_mode_in[1];
assign agg_write_addr_l2b_out[1] = agg_write_addr[1][1:0];
assign tb_read_1 = mode_1[0] ? tb_read_in[1]: tb_read_in[0];
assign tb_addr_1 = mode_1[0] ? tb_read_addr_in[1]: tb_read_addr_in[0];

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    wr_ptr_1 <= 3'h0;
    rd_ptr_1 <= 3'h0;
    tb_read_shift_1 <= 16'h0;
    tb_addr_fifo_1 <= 32'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      wr_ptr_1 <= 3'h0;
      rd_ptr_1 <= 3'h0;
      tb_read_shift_1 <= 16'h0;
      tb_addr_fifo_1 <= 32'h0;
    end
    else if ((mode_1[1] == 1'h1) & (delay_1 > 4'h0)) begin
      tb_read_shift_1 <= {tb_read_shift_1[14:1], tb_read_1, 1'h0};
      if (tb_read_1) begin
        tb_addr_fifo_1[wr_ptr_1] <= tb_addr_1;
        wr_ptr_1 <= wr_ptr_1 + 3'h1;
      end
      if (tb_read_delayed_1) begin
        rd_ptr_1 <= rd_ptr_1 + 3'h1;
      end
    end
  end
end
assign tb_read_delayed_1 = tb_read_shift_1[delay_1];
assign tb_addr_delayed_1 = tb_addr_fifo_1[rd_ptr_1];
assign tb_shared_wen_1 = (delay_1 > 4'h0) ? tb_read_delayed_1: tb_read_1;
assign tb_shared_addr_1 = (delay_1 > 4'h0) ? tb_addr_delayed_1: tb_addr_1;
assign fl_mux_sel_1[1:0] = loops_in2buf_1_mux_sel_out;
assign fl_mux_sel_1[2] = 1'h0;
assign agg_write_mux_sel_out[1] = fl_mux_sel_1;
assign agg_write_restart_out[1] = loops_in2buf_1_restart;
assign agg_write_addr[1] = mode_1[1] ? tb_shared_addr_1: agg_write_addr_gen_1_addr_out;
assign agg_write[1] = mode_1[1] ? tb_shared_wen_1: agg_write_sched_gen_1_valid_output;

always_ff @(posedge clk) begin
  if (clk_en) begin
    if (agg_write[1]) begin
      agg[1][agg_write_addr[1][3:2]][agg_write_addr[1][1:0]] <= data_in[1];
    end
  end
end
assign agg_read_addr_in[1] = sram_read_addr_in[1][1:0];
assign agg_read_addr_gen_out[1][1:0] = agg_read_addr_in[1];
assign agg_read_addr_gen_out[1][7:2] = 6'h0;
assign agg_read_addr[1] = agg_read_addr_gen_out[1][1:0];
always_comb begin
  agg_data_out[1] = agg[1][agg_read_addr[1]];
end
for_loop_3_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(3'h3))
loops_in2buf_0 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_in2buf_0_dimensionality),
  .flush(flush),
  .ranges(loops_in2buf_0_ranges),
  .rst_n(rst_n),
  .step(agg_write[0]),
  .mux_sel_out(loops_in2buf_0_mux_sel_out),
  .restart(loops_in2buf_0_restart)
);

addr_gen_6_4 agg_write_addr_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(fl_mux_sel_0),
  .restart(loops_in2buf_0_restart),
  .rst_n(rst_n),
  .starting_addr(agg_write_addr_gen_0_starting_addr),
  .step(agg_write[0]),
  .strides(agg_write_addr_gen_0_strides),
  .addr_out(agg_write_addr_gen_0_addr_out)
);

sched_gen_6_16 agg_write_sched_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(agg_write_sched_gen_0_enable),
  .finished(loops_in2buf_0_restart),
  .flush(flush),
  .mux_sel(fl_mux_sel_0),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(agg_write_sched_gen_0_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(agg_write_sched_gen_0_sched_addr_gen_strides),
  .valid_output(agg_write_sched_gen_0_valid_output)
);

for_loop_3_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(3'h3))
loops_in2buf_1 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_in2buf_1_dimensionality),
  .flush(flush),
  .ranges(loops_in2buf_1_ranges),
  .rst_n(rst_n),
  .step(agg_write[1]),
  .mux_sel_out(loops_in2buf_1_mux_sel_out),
  .restart(loops_in2buf_1_restart)
);

addr_gen_6_4 agg_write_addr_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(fl_mux_sel_1),
  .restart(loops_in2buf_1_restart),
  .rst_n(rst_n),
  .starting_addr(agg_write_addr_gen_1_starting_addr),
  .step(agg_write[1]),
  .strides(agg_write_addr_gen_1_strides),
  .addr_out(agg_write_addr_gen_1_addr_out)
);

sched_gen_6_16 agg_write_sched_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(agg_write_sched_gen_1_enable),
  .finished(loops_in2buf_1_restart),
  .flush(flush),
  .mux_sel(fl_mux_sel_1),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(agg_write_sched_gen_1_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(agg_write_sched_gen_1_sched_addr_gen_strides),
  .valid_output(agg_write_sched_gen_1_valid_output)
);

endmodule   // strg_ub_agg_only

module strg_ub_agg_sram_shared (
  input logic [5:0] agg_read_sched_gen_0_agg_read_padding,
  input logic [5:0] agg_read_sched_gen_1_agg_read_padding,
  input logic [8:0] agg_sram_shared_addr_gen_0_starting_addr,
  input logic [8:0] agg_sram_shared_addr_gen_1_starting_addr,
  input logic [1:0] [1:0] agg_write_addr_l2b_in,
  input logic [1:0] agg_write_in,
  input logic [1:0] [2:0] agg_write_mux_sel_in,
  input logic [1:0] agg_write_restart_in,
  input logic clk,
  input logic clk_en,
  input logic [3:0] delay_0,
  input logic [3:0] delay_1,
  input logic flush,
  input logic [1:0] mode_0,
  input logic [1:0] mode_1,
  input logic rst_n,
  input logic [1:0] [8:0] sram_read_addr_in,
  input logic [1:0] sram_read_in,
  output logic [1:0] agg_read_out,
  output logic [1:0] [8:0] agg_sram_shared_addr_out,
  output logic [1:0] [1:0] update_mode_out
);

logic [1:0] agg_read;
logic agg_read_sched_gen_0_valid_output;
logic agg_read_sched_gen_1_valid_output;
logic [8:0] agg_sram_shared_addr_gen_0_addr_out;
logic [8:0] agg_sram_shared_addr_gen_1_addr_out;
assign agg_read_out = agg_read;
assign update_mode_out[0] = mode_0;
assign agg_read[0] = agg_read_sched_gen_0_valid_output;
assign agg_sram_shared_addr_out[0] = agg_sram_shared_addr_gen_0_addr_out;
assign update_mode_out[1] = mode_1;
assign agg_read[1] = agg_read_sched_gen_1_valid_output;
assign agg_sram_shared_addr_out[1] = agg_sram_shared_addr_gen_1_addr_out;
agg_sram_shared_sched_gen agg_read_sched_gen_0 (
  .agg_read_padding(agg_read_sched_gen_0_agg_read_padding),
  .agg_write(agg_write_in[0]),
  .agg_write_addr_l2b(agg_write_addr_l2b_in[0]),
  .agg_write_mux_sel(agg_write_mux_sel_in[0]),
  .agg_write_restart(agg_write_restart_in[0]),
  .clk(clk),
  .clk_en(clk_en),
  .delay(delay_0),
  .flush(flush),
  .mode(mode_0),
  .rst_n(rst_n),
  .sram_read(sram_read_in),
  .valid_output(agg_read_sched_gen_0_valid_output)
);

agg_sram_shared_addr_gen agg_sram_shared_addr_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mode(mode_0),
  .rst_n(rst_n),
  .sram_read(sram_read_in),
  .sram_read_addr(sram_read_addr_in),
  .starting_addr(agg_sram_shared_addr_gen_0_starting_addr),
  .step(agg_read[0]),
  .addr_out(agg_sram_shared_addr_gen_0_addr_out)
);

agg_sram_shared_sched_gen agg_read_sched_gen_1 (
  .agg_read_padding(agg_read_sched_gen_1_agg_read_padding),
  .agg_write(agg_write_in[1]),
  .agg_write_addr_l2b(agg_write_addr_l2b_in[1]),
  .agg_write_mux_sel(agg_write_mux_sel_in[1]),
  .agg_write_restart(agg_write_restart_in[1]),
  .clk(clk),
  .clk_en(clk_en),
  .delay(delay_1),
  .flush(flush),
  .mode(mode_1),
  .rst_n(rst_n),
  .sram_read(sram_read_in),
  .valid_output(agg_read_sched_gen_1_valid_output)
);

agg_sram_shared_addr_gen agg_sram_shared_addr_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mode(mode_1),
  .rst_n(rst_n),
  .sram_read(sram_read_in),
  .sram_read_addr(sram_read_addr_in),
  .starting_addr(agg_sram_shared_addr_gen_1_starting_addr),
  .step(agg_read[1]),
  .addr_out(agg_sram_shared_addr_gen_1_addr_out)
);

endmodule   // strg_ub_agg_sram_shared

module strg_ub_sram_only (
  input logic [1:0][3:0] [15:0] agg_data_out,
  input logic [1:0] agg_read,
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic flush,
  input logic [1:0] [2:0] loops_sram2tb_mux_sel,
  input logic [1:0] loops_sram2tb_restart,
  input logic [8:0] output_addr_gen_0_starting_addr,
  input logic [5:0] [8:0] output_addr_gen_0_strides,
  input logic [8:0] output_addr_gen_1_starting_addr,
  input logic [5:0] [8:0] output_addr_gen_1_strides,
  input logic rst_n,
  input logic [1:0] [8:0] sram_read_addr_in,
  input logic [1:0] t_read,
  output logic [8:0] addr_to_sram,
  output logic cen_to_sram,
  output logic [3:0] [15:0] data_to_sram,
  output logic [1:0] [8:0] sram_read_addr_out,
  output logic wen_to_sram
);

logic [8:0] addr;
logic [3:0][15:0] decode_ret_agg_read_agg_data_out;
logic [15:0] decode_ret_agg_read_s_write_addr;
logic [15:0] decode_ret_t_read_s_read_addr;
logic decode_sel_done_agg_read_agg_data_out;
logic decode_sel_done_agg_read_s_write_addr;
logic decode_sel_done_t_read_s_read_addr;
logic [8:0] output_addr_gen_0_addr_out;
logic [8:0] output_addr_gen_1_addr_out;
logic read;
logic [1:0][15:0] s_read_addr;
logic [1:0][15:0] s_write_addr;
logic [3:0][15:0] sram_write_data;
logic write;
assign s_write_addr[0][8:0] = sram_read_addr_in[0];
assign s_write_addr[0][15:9] = 7'h0;
assign s_write_addr[1][8:0] = sram_read_addr_in[1];
assign s_write_addr[1][15:9] = 7'h0;
assign s_read_addr[0][8:0] = output_addr_gen_0_addr_out;
assign s_read_addr[0][15:9] = 7'h0;
assign sram_read_addr_out[0] = output_addr_gen_0_addr_out;
assign s_read_addr[1][8:0] = output_addr_gen_1_addr_out;
assign s_read_addr[1][15:9] = 7'h0;
assign sram_read_addr_out[1] = output_addr_gen_1_addr_out;
assign data_to_sram = sram_write_data;
assign wen_to_sram = write;
always_comb begin
  decode_sel_done_agg_read_s_write_addr = 1'h0;
  decode_ret_agg_read_s_write_addr = 16'h0;
  for (int unsigned i = 0; i < 2; i += 1) begin
      if ((~decode_sel_done_agg_read_s_write_addr) & agg_read[1'(i)]) begin
        decode_ret_agg_read_s_write_addr = s_write_addr[1'(i)];
        decode_sel_done_agg_read_s_write_addr = 1'h1;
      end
    end
end
always_comb begin
  decode_sel_done_t_read_s_read_addr = 1'h0;
  decode_ret_t_read_s_read_addr = 16'h0;
  for (int unsigned i = 0; i < 2; i += 1) begin
      if ((~decode_sel_done_t_read_s_read_addr) & t_read[1'(i)]) begin
        decode_ret_t_read_s_read_addr = s_read_addr[1'(i)];
        decode_sel_done_t_read_s_read_addr = 1'h1;
      end
    end
end
assign cen_to_sram = write | read;
assign addr_to_sram = addr;
always_comb begin
  if (write) begin
    addr = decode_ret_agg_read_s_write_addr[8:0];
  end
  else addr = decode_ret_t_read_s_read_addr[8:0];
end
assign write = |agg_read;
assign read = |t_read;
always_comb begin
  decode_sel_done_agg_read_agg_data_out = 1'h0;
  decode_ret_agg_read_agg_data_out = 64'h0;
  for (int unsigned i = 0; i < 2; i += 1) begin
      if ((~decode_sel_done_agg_read_agg_data_out) & agg_read[1'(i)]) begin
        decode_ret_agg_read_agg_data_out = agg_data_out[1'(i)];
        decode_sel_done_agg_read_agg_data_out = 1'h1;
      end
    end
end
assign sram_write_data = decode_ret_agg_read_agg_data_out;
addr_gen_6_9 output_addr_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(loops_sram2tb_mux_sel[0]),
  .restart(loops_sram2tb_restart[0]),
  .rst_n(rst_n),
  .starting_addr(output_addr_gen_0_starting_addr),
  .step(t_read[0]),
  .strides(output_addr_gen_0_strides),
  .addr_out(output_addr_gen_0_addr_out)
);

addr_gen_6_9 output_addr_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(loops_sram2tb_mux_sel[1]),
  .restart(loops_sram2tb_restart[1]),
  .rst_n(rst_n),
  .starting_addr(output_addr_gen_1_starting_addr),
  .step(t_read[1]),
  .strides(output_addr_gen_1_strides),
  .addr_out(output_addr_gen_1_addr_out)
);

endmodule   // strg_ub_sram_only

module strg_ub_sram_tb_shared (
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic flush,
  input logic [3:0] loops_buf2out_autovec_read_0_dimensionality,
  input logic [5:0] [9:0] loops_buf2out_autovec_read_0_ranges,
  input logic [3:0] loops_buf2out_autovec_read_1_dimensionality,
  input logic [5:0] [9:0] loops_buf2out_autovec_read_1_ranges,
  input logic output_sched_gen_0_enable,
  input logic [15:0] output_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] output_sched_gen_0_sched_addr_gen_strides,
  input logic output_sched_gen_1_enable,
  input logic [15:0] output_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] output_sched_gen_1_sched_addr_gen_strides,
  input logic rst_n,
  output logic [1:0] [2:0] loops_sram2tb_mux_sel,
  output logic [1:0] loops_sram2tb_restart,
  output logic [1:0] t_read_out
);

logic [2:0] loops_buf2out_autovec_read_0_mux_sel_out;
logic loops_buf2out_autovec_read_0_restart;
logic [2:0] loops_buf2out_autovec_read_1_mux_sel_out;
logic loops_buf2out_autovec_read_1_restart;
logic output_sched_gen_0_valid_output;
logic output_sched_gen_1_valid_output;
logic [1:0] t_read;
assign t_read_out = t_read;
assign loops_sram2tb_mux_sel[0] = loops_buf2out_autovec_read_0_mux_sel_out;
assign loops_sram2tb_restart[0] = loops_buf2out_autovec_read_0_restart;
assign t_read[0] = output_sched_gen_0_valid_output;
assign loops_sram2tb_mux_sel[1] = loops_buf2out_autovec_read_1_mux_sel_out;
assign loops_sram2tb_restart[1] = loops_buf2out_autovec_read_1_restart;
assign t_read[1] = output_sched_gen_1_valid_output;
for_loop_6_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(4'h6))
loops_buf2out_autovec_read_0 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_buf2out_autovec_read_0_dimensionality),
  .flush(flush),
  .ranges(loops_buf2out_autovec_read_0_ranges),
  .rst_n(rst_n),
  .step(t_read[0]),
  .mux_sel_out(loops_buf2out_autovec_read_0_mux_sel_out),
  .restart(loops_buf2out_autovec_read_0_restart)
);

sched_gen_6_16 output_sched_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(output_sched_gen_0_enable),
  .finished(loops_buf2out_autovec_read_0_restart),
  .flush(flush),
  .mux_sel(loops_buf2out_autovec_read_0_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(output_sched_gen_0_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(output_sched_gen_0_sched_addr_gen_strides),
  .valid_output(output_sched_gen_0_valid_output)
);

for_loop_6_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(4'h6))
loops_buf2out_autovec_read_1 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_buf2out_autovec_read_1_dimensionality),
  .flush(flush),
  .ranges(loops_buf2out_autovec_read_1_ranges),
  .rst_n(rst_n),
  .step(t_read[1]),
  .mux_sel_out(loops_buf2out_autovec_read_1_mux_sel_out),
  .restart(loops_buf2out_autovec_read_1_restart)
);

sched_gen_6_16 output_sched_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(output_sched_gen_1_enable),
  .finished(loops_buf2out_autovec_read_1_restart),
  .flush(flush),
  .mux_sel(loops_buf2out_autovec_read_1_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(output_sched_gen_1_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(output_sched_gen_1_sched_addr_gen_strides),
  .valid_output(output_sched_gen_1_valid_output)
);

endmodule   // strg_ub_sram_tb_shared

module strg_ub_tb_only (
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic flush,
  input logic [3:0] loops_buf2out_read_0_dimensionality,
  input logic [5:0] [9:0] loops_buf2out_read_0_ranges,
  input logic [3:0] loops_buf2out_read_1_dimensionality,
  input logic [5:0] [9:0] loops_buf2out_read_1_ranges,
  input logic [1:0] [2:0] loops_sram2tb_mux_sel,
  input logic [1:0] loops_sram2tb_restart,
  input logic rst_n,
  input logic [3:0] [15:0] sram_read_data,
  input logic [1:0] t_read,
  input logic [3:0] tb_read_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] tb_read_addr_gen_0_strides,
  input logic [3:0] tb_read_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] tb_read_addr_gen_1_strides,
  input logic tb_read_sched_gen_0_enable,
  input logic [15:0] tb_read_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] tb_read_sched_gen_0_sched_addr_gen_strides,
  input logic tb_read_sched_gen_1_enable,
  input logic [15:0] tb_read_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] tb_read_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] tb_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] tb_write_addr_gen_0_strides,
  input logic [3:0] tb_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] tb_write_addr_gen_1_strides,
  output logic [1:0] accessor_output,
  output logic [1:0] [15:0] data_out,
  output logic [1:0] [3:0] tb_read_addr_out,
  output logic [1:0] tb_read_out
);

logic [2:0] loops_buf2out_read_0_mux_sel_out;
logic loops_buf2out_read_0_restart;
logic [2:0] loops_buf2out_read_1_mux_sel_out;
logic loops_buf2out_read_1_restart;
logic [1:0][2:0] mux_sel_d1;
logic [1:0] restart_d1;
logic [1:0] t_read_d1;
logic [1:0][1:0][3:0][15:0] tb;
logic [1:0] tb_read;
logic [1:0][2:0] tb_read_addr;
logic [3:0] tb_read_addr_gen_0_addr_out;
logic [3:0] tb_read_addr_gen_1_addr_out;
logic tb_read_sched_gen_0_valid_output;
logic tb_read_sched_gen_1_valid_output;
logic [1:0][2:0] tb_write_addr;
logic [3:0] tb_write_addr_gen_0_addr_out;
logic [3:0] tb_write_addr_gen_1_addr_out;
assign accessor_output = tb_read;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    t_read_d1[0] <= 1'h0;
    mux_sel_d1[0] <= 3'h0;
    restart_d1[0] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      t_read_d1[0] <= 1'h0;
      mux_sel_d1[0] <= 3'h0;
      restart_d1[0] <= 1'h0;
    end
    else begin
      t_read_d1[0] <= t_read[0];
      mux_sel_d1[0] <= loops_sram2tb_mux_sel[0];
      restart_d1[0] <= loops_sram2tb_restart[0];
    end
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    t_read_d1[1] <= 1'h0;
    mux_sel_d1[1] <= 3'h0;
    restart_d1[1] <= 1'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      t_read_d1[1] <= 1'h0;
      mux_sel_d1[1] <= 3'h0;
      restart_d1[1] <= 1'h0;
    end
    else begin
      t_read_d1[1] <= t_read[1];
      mux_sel_d1[1] <= loops_sram2tb_mux_sel[1];
      restart_d1[1] <= loops_sram2tb_restart[1];
    end
  end
end
assign tb_write_addr[0] = tb_write_addr_gen_0_addr_out[2:0];

always_ff @(posedge clk) begin
  if (clk_en) begin
    if (t_read_d1[0]) begin
      tb[0][tb_write_addr[0][0]] <= sram_read_data;
    end
  end
end
assign tb_read_addr[0] = tb_read_addr_gen_0_addr_out[2:0];
assign tb_read_addr_out[0] = tb_read_addr_gen_0_addr_out;
assign tb_read[0] = tb_read_sched_gen_0_valid_output;
always_comb begin
  data_out[0] = tb[0][tb_read_addr[0][2]][tb_read_addr[0][1:0]];
end
assign tb_write_addr[1] = tb_write_addr_gen_1_addr_out[2:0];

always_ff @(posedge clk) begin
  if (clk_en) begin
    if (t_read_d1[1]) begin
      tb[1][tb_write_addr[1][0]] <= sram_read_data;
    end
  end
end
assign tb_read_addr[1] = tb_read_addr_gen_1_addr_out[2:0];
assign tb_read_addr_out[1] = tb_read_addr_gen_1_addr_out;
assign tb_read[1] = tb_read_sched_gen_1_valid_output;
always_comb begin
  data_out[1] = tb[1][tb_read_addr[1][2]][tb_read_addr[1][1:0]];
end
assign tb_read_out = tb_read;
addr_gen_6_4 tb_write_addr_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(mux_sel_d1[0]),
  .restart(restart_d1[0]),
  .rst_n(rst_n),
  .starting_addr(tb_write_addr_gen_0_starting_addr),
  .step(t_read_d1[0]),
  .strides(tb_write_addr_gen_0_strides),
  .addr_out(tb_write_addr_gen_0_addr_out)
);

for_loop_6_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(4'h6))
loops_buf2out_read_0 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_buf2out_read_0_dimensionality),
  .flush(flush),
  .ranges(loops_buf2out_read_0_ranges),
  .rst_n(rst_n),
  .step(tb_read[0]),
  .mux_sel_out(loops_buf2out_read_0_mux_sel_out),
  .restart(loops_buf2out_read_0_restart)
);

addr_gen_6_4 tb_read_addr_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(loops_buf2out_read_0_mux_sel_out),
  .restart(loops_buf2out_read_0_restart),
  .rst_n(rst_n),
  .starting_addr(tb_read_addr_gen_0_starting_addr),
  .step(tb_read[0]),
  .strides(tb_read_addr_gen_0_strides),
  .addr_out(tb_read_addr_gen_0_addr_out)
);

sched_gen_6_16 tb_read_sched_gen_0 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(tb_read_sched_gen_0_enable),
  .finished(loops_buf2out_read_0_restart),
  .flush(flush),
  .mux_sel(loops_buf2out_read_0_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(tb_read_sched_gen_0_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(tb_read_sched_gen_0_sched_addr_gen_strides),
  .valid_output(tb_read_sched_gen_0_valid_output)
);

addr_gen_6_4 tb_write_addr_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(mux_sel_d1[1]),
  .restart(restart_d1[1]),
  .rst_n(rst_n),
  .starting_addr(tb_write_addr_gen_1_starting_addr),
  .step(t_read_d1[1]),
  .strides(tb_write_addr_gen_1_strides),
  .addr_out(tb_write_addr_gen_1_addr_out)
);

for_loop_6_10 #(
  .CONFIG_WIDTH(5'hA),
  .ITERATOR_SUPPORT(4'h6))
loops_buf2out_read_1 (
  .clk(clk),
  .clk_en(clk_en),
  .dimensionality(loops_buf2out_read_1_dimensionality),
  .flush(flush),
  .ranges(loops_buf2out_read_1_ranges),
  .rst_n(rst_n),
  .step(tb_read[1]),
  .mux_sel_out(loops_buf2out_read_1_mux_sel_out),
  .restart(loops_buf2out_read_1_restart)
);

addr_gen_6_4 tb_read_addr_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(loops_buf2out_read_1_mux_sel_out),
  .restart(loops_buf2out_read_1_restart),
  .rst_n(rst_n),
  .starting_addr(tb_read_addr_gen_1_starting_addr),
  .step(tb_read[1]),
  .strides(tb_read_addr_gen_1_strides),
  .addr_out(tb_read_addr_gen_1_addr_out)
);

sched_gen_6_16 tb_read_sched_gen_1 (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(tb_read_sched_gen_1_enable),
  .finished(loops_buf2out_read_1_restart),
  .flush(flush),
  .mux_sel(loops_buf2out_read_1_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(tb_read_sched_gen_1_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(tb_read_sched_gen_1_sched_addr_gen_strides),
  .valid_output(tb_read_sched_gen_1_valid_output)
);

endmodule   // strg_ub_tb_only

module strg_ub_vec (
  input logic [3:0] agg_only_agg_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] agg_only_agg_write_addr_gen_0_strides,
  input logic [3:0] agg_only_agg_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] agg_only_agg_write_addr_gen_1_strides,
  input logic agg_only_agg_write_sched_gen_0_enable,
  input logic [15:0] agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] agg_only_agg_write_sched_gen_0_sched_addr_gen_strides,
  input logic agg_only_agg_write_sched_gen_1_enable,
  input logic [15:0] agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] agg_only_agg_write_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] agg_only_delay_0,
  input logic [3:0] agg_only_delay_1,
  input logic [2:0] agg_only_loops_in2buf_0_dimensionality,
  input logic [2:0] [9:0] agg_only_loops_in2buf_0_ranges,
  input logic [2:0] agg_only_loops_in2buf_1_dimensionality,
  input logic [2:0] [9:0] agg_only_loops_in2buf_1_ranges,
  input logic [5:0] agg_sram_shared_agg_read_sched_gen_0_agg_read_padding,
  input logic [5:0] agg_sram_shared_agg_read_sched_gen_1_agg_read_padding,
  input logic [8:0] agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr,
  input logic [8:0] agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr,
  input logic [3:0] agg_sram_shared_delay_0,
  input logic [3:0] agg_sram_shared_delay_1,
  input logic [1:0] agg_sram_shared_mode_0,
  input logic [1:0] agg_sram_shared_mode_1,
  input logic chain_chain_en,
  input logic [1:0] [15:0] chain_data_in,
  input logic clk,
  input logic clk_en,
  input logic [3:0] [15:0] data_from_strg,
  input logic [1:0] [15:0] data_in,
  input logic flush,
  input logic rst_n,
  input logic [8:0] sram_only_output_addr_gen_0_starting_addr,
  input logic [5:0] [8:0] sram_only_output_addr_gen_0_strides,
  input logic [8:0] sram_only_output_addr_gen_1_starting_addr,
  input logic [5:0] [8:0] sram_only_output_addr_gen_1_strides,
  input logic [3:0] sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality,
  input logic [5:0] [9:0] sram_tb_shared_loops_buf2out_autovec_read_0_ranges,
  input logic [3:0] sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality,
  input logic [5:0] [9:0] sram_tb_shared_loops_buf2out_autovec_read_1_ranges,
  input logic sram_tb_shared_output_sched_gen_0_enable,
  input logic [15:0] sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides,
  input logic sram_tb_shared_output_sched_gen_1_enable,
  input logic [15:0] sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] tb_only_loops_buf2out_read_0_dimensionality,
  input logic [5:0] [9:0] tb_only_loops_buf2out_read_0_ranges,
  input logic [3:0] tb_only_loops_buf2out_read_1_dimensionality,
  input logic [5:0] [9:0] tb_only_loops_buf2out_read_1_ranges,
  input logic [3:0] tb_only_tb_read_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] tb_only_tb_read_addr_gen_0_strides,
  input logic [3:0] tb_only_tb_read_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] tb_only_tb_read_addr_gen_1_strides,
  input logic tb_only_tb_read_sched_gen_0_enable,
  input logic [15:0] tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] tb_only_tb_read_sched_gen_0_sched_addr_gen_strides,
  input logic tb_only_tb_read_sched_gen_1_enable,
  input logic [15:0] tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] tb_only_tb_read_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] tb_only_tb_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] tb_only_tb_write_addr_gen_0_strides,
  input logic [3:0] tb_only_tb_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] tb_only_tb_write_addr_gen_1_strides,
  output logic [1:0] accessor_output,
  output logic [8:0] addr_out,
  output logic [1:0] [15:0] data_out,
  output logic [3:0] [15:0] data_to_strg,
  output logic ren_to_strg,
  output logic wen_to_strg
);

logic [1:0] accessor_output_int;
logic [1:0][3:0][15:0] agg_only_agg_data_out;
logic [1:0] agg_only_agg_read;
logic [1:0][1:0] agg_only_agg_write_addr_l2b_out;
logic [1:0][2:0] agg_only_agg_write_mux_sel_out;
logic [1:0] agg_only_agg_write_out;
logic [1:0] agg_only_agg_write_restart_out;
logic [1:0][8:0] agg_only_sram_read_addr_in;
logic [1:0][3:0] agg_only_tb_read_addr_in;
logic [1:0] agg_only_tb_read_in;
logic [1:0][1:0] agg_only_update_mode_in;
logic [1:0] agg_sram_shared_agg_read_out;
logic [1:0][8:0] agg_sram_shared_agg_sram_shared_addr_out;
logic [1:0][8:0] agg_sram_shared_sram_read_addr_in;
logic [1:0] agg_sram_shared_sram_read_in;
logic [15:0] cycle_count;
logic [1:0][15:0] data_out_int;
logic [1:0][2:0] sram_only_loops_sram2tb_mux_sel;
logic [1:0] sram_only_loops_sram2tb_restart;
logic [1:0] sram_only_t_read;
logic [1:0][2:0] sram_tb_shared_loops_sram2tb_mux_sel;
logic [1:0] sram_tb_shared_loops_sram2tb_restart;
logic [1:0] sram_tb_shared_t_read_out;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    cycle_count <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      cycle_count <= 16'h0;
    end
    else if (1'h1) begin
      cycle_count <= cycle_count + 16'h1;
    end
  end
end
assign agg_only_agg_read = agg_sram_shared_agg_read_out;
assign agg_only_sram_read_addr_in = agg_sram_shared_agg_sram_shared_addr_out;
assign agg_sram_shared_sram_read_in = sram_tb_shared_t_read_out;
assign sram_only_loops_sram2tb_mux_sel = sram_tb_shared_loops_sram2tb_mux_sel;
assign sram_only_loops_sram2tb_restart = sram_tb_shared_loops_sram2tb_restart;
assign sram_only_t_read = sram_tb_shared_t_read_out;
assign ren_to_strg = |sram_tb_shared_t_read_out;
assign accessor_output = accessor_output_int;
strg_ub_agg_only agg_only (
  .agg_read(agg_only_agg_read),
  .agg_write_addr_gen_0_starting_addr(agg_only_agg_write_addr_gen_0_starting_addr),
  .agg_write_addr_gen_0_strides(agg_only_agg_write_addr_gen_0_strides),
  .agg_write_addr_gen_1_starting_addr(agg_only_agg_write_addr_gen_1_starting_addr),
  .agg_write_addr_gen_1_strides(agg_only_agg_write_addr_gen_1_strides),
  .agg_write_sched_gen_0_enable(agg_only_agg_write_sched_gen_0_enable),
  .agg_write_sched_gen_0_sched_addr_gen_starting_addr(agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr),
  .agg_write_sched_gen_0_sched_addr_gen_strides(agg_only_agg_write_sched_gen_0_sched_addr_gen_strides),
  .agg_write_sched_gen_1_enable(agg_only_agg_write_sched_gen_1_enable),
  .agg_write_sched_gen_1_sched_addr_gen_starting_addr(agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr),
  .agg_write_sched_gen_1_sched_addr_gen_strides(agg_only_agg_write_sched_gen_1_sched_addr_gen_strides),
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .data_in(data_in),
  .delay_0(agg_only_delay_0),
  .delay_1(agg_only_delay_1),
  .flush(flush),
  .loops_in2buf_0_dimensionality(agg_only_loops_in2buf_0_dimensionality),
  .loops_in2buf_0_ranges(agg_only_loops_in2buf_0_ranges),
  .loops_in2buf_1_dimensionality(agg_only_loops_in2buf_1_dimensionality),
  .loops_in2buf_1_ranges(agg_only_loops_in2buf_1_ranges),
  .rst_n(rst_n),
  .sram_read_addr_in(agg_only_sram_read_addr_in),
  .tb_read_addr_in(agg_only_tb_read_addr_in),
  .tb_read_in(agg_only_tb_read_in),
  .update_mode_in(agg_only_update_mode_in),
  .agg_data_out(agg_only_agg_data_out),
  .agg_write_addr_l2b_out(agg_only_agg_write_addr_l2b_out),
  .agg_write_mux_sel_out(agg_only_agg_write_mux_sel_out),
  .agg_write_out(agg_only_agg_write_out),
  .agg_write_restart_out(agg_only_agg_write_restart_out)
);

strg_ub_agg_sram_shared agg_sram_shared (
  .agg_read_sched_gen_0_agg_read_padding(agg_sram_shared_agg_read_sched_gen_0_agg_read_padding),
  .agg_read_sched_gen_1_agg_read_padding(agg_sram_shared_agg_read_sched_gen_1_agg_read_padding),
  .agg_sram_shared_addr_gen_0_starting_addr(agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr),
  .agg_sram_shared_addr_gen_1_starting_addr(agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr),
  .agg_write_addr_l2b_in(agg_only_agg_write_addr_l2b_out),
  .agg_write_in(agg_only_agg_write_out),
  .agg_write_mux_sel_in(agg_only_agg_write_mux_sel_out),
  .agg_write_restart_in(agg_only_agg_write_restart_out),
  .clk(clk),
  .clk_en(clk_en),
  .delay_0(agg_sram_shared_delay_0),
  .delay_1(agg_sram_shared_delay_1),
  .flush(flush),
  .mode_0(agg_sram_shared_mode_0),
  .mode_1(agg_sram_shared_mode_1),
  .rst_n(rst_n),
  .sram_read_addr_in(agg_sram_shared_sram_read_addr_in),
  .sram_read_in(agg_sram_shared_sram_read_in),
  .agg_read_out(agg_sram_shared_agg_read_out),
  .agg_sram_shared_addr_out(agg_sram_shared_agg_sram_shared_addr_out),
  .update_mode_out(agg_only_update_mode_in)
);

strg_ub_sram_only sram_only (
  .agg_data_out(agg_only_agg_data_out),
  .agg_read(agg_sram_shared_agg_read_out),
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .flush(flush),
  .loops_sram2tb_mux_sel(sram_only_loops_sram2tb_mux_sel),
  .loops_sram2tb_restart(sram_only_loops_sram2tb_restart),
  .output_addr_gen_0_starting_addr(sram_only_output_addr_gen_0_starting_addr),
  .output_addr_gen_0_strides(sram_only_output_addr_gen_0_strides),
  .output_addr_gen_1_starting_addr(sram_only_output_addr_gen_1_starting_addr),
  .output_addr_gen_1_strides(sram_only_output_addr_gen_1_strides),
  .rst_n(rst_n),
  .sram_read_addr_in(agg_sram_shared_agg_sram_shared_addr_out),
  .t_read(sram_only_t_read),
  .addr_to_sram(addr_out),
  .data_to_sram(data_to_strg),
  .sram_read_addr_out(agg_sram_shared_sram_read_addr_in),
  .wen_to_sram(wen_to_strg)
);

strg_ub_sram_tb_shared sram_tb_shared (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .flush(flush),
  .loops_buf2out_autovec_read_0_dimensionality(sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality),
  .loops_buf2out_autovec_read_0_ranges(sram_tb_shared_loops_buf2out_autovec_read_0_ranges),
  .loops_buf2out_autovec_read_1_dimensionality(sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality),
  .loops_buf2out_autovec_read_1_ranges(sram_tb_shared_loops_buf2out_autovec_read_1_ranges),
  .output_sched_gen_0_enable(sram_tb_shared_output_sched_gen_0_enable),
  .output_sched_gen_0_sched_addr_gen_starting_addr(sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr),
  .output_sched_gen_0_sched_addr_gen_strides(sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides),
  .output_sched_gen_1_enable(sram_tb_shared_output_sched_gen_1_enable),
  .output_sched_gen_1_sched_addr_gen_starting_addr(sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr),
  .output_sched_gen_1_sched_addr_gen_strides(sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides),
  .rst_n(rst_n),
  .loops_sram2tb_mux_sel(sram_tb_shared_loops_sram2tb_mux_sel),
  .loops_sram2tb_restart(sram_tb_shared_loops_sram2tb_restart),
  .t_read_out(sram_tb_shared_t_read_out)
);

strg_ub_tb_only tb_only (
  .clk(clk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .flush(flush),
  .loops_buf2out_read_0_dimensionality(tb_only_loops_buf2out_read_0_dimensionality),
  .loops_buf2out_read_0_ranges(tb_only_loops_buf2out_read_0_ranges),
  .loops_buf2out_read_1_dimensionality(tb_only_loops_buf2out_read_1_dimensionality),
  .loops_buf2out_read_1_ranges(tb_only_loops_buf2out_read_1_ranges),
  .loops_sram2tb_mux_sel(sram_tb_shared_loops_sram2tb_mux_sel),
  .loops_sram2tb_restart(sram_tb_shared_loops_sram2tb_restart),
  .rst_n(rst_n),
  .sram_read_data(data_from_strg),
  .t_read(sram_tb_shared_t_read_out),
  .tb_read_addr_gen_0_starting_addr(tb_only_tb_read_addr_gen_0_starting_addr),
  .tb_read_addr_gen_0_strides(tb_only_tb_read_addr_gen_0_strides),
  .tb_read_addr_gen_1_starting_addr(tb_only_tb_read_addr_gen_1_starting_addr),
  .tb_read_addr_gen_1_strides(tb_only_tb_read_addr_gen_1_strides),
  .tb_read_sched_gen_0_enable(tb_only_tb_read_sched_gen_0_enable),
  .tb_read_sched_gen_0_sched_addr_gen_starting_addr(tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr),
  .tb_read_sched_gen_0_sched_addr_gen_strides(tb_only_tb_read_sched_gen_0_sched_addr_gen_strides),
  .tb_read_sched_gen_1_enable(tb_only_tb_read_sched_gen_1_enable),
  .tb_read_sched_gen_1_sched_addr_gen_starting_addr(tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr),
  .tb_read_sched_gen_1_sched_addr_gen_strides(tb_only_tb_read_sched_gen_1_sched_addr_gen_strides),
  .tb_write_addr_gen_0_starting_addr(tb_only_tb_write_addr_gen_0_starting_addr),
  .tb_write_addr_gen_0_strides(tb_only_tb_write_addr_gen_0_strides),
  .tb_write_addr_gen_1_starting_addr(tb_only_tb_write_addr_gen_1_starting_addr),
  .tb_write_addr_gen_1_strides(tb_only_tb_write_addr_gen_1_strides),
  .accessor_output(accessor_output_int),
  .data_out(data_out_int),
  .tb_read_addr_out(agg_only_tb_read_addr_in),
  .tb_read_out(agg_only_tb_read_in)
);

Chain chain (
  .accessor_output(accessor_output_int),
  .chain_data_in(chain_data_in),
  .chain_en(chain_chain_en),
  .clk_en(clk_en),
  .curr_tile_data_out(data_out_int),
  .flush(flush),
  .data_out_tile(data_out)
);

endmodule   // strg_ub_vec

module strg_ub_vec_flat (
  input logic [0:0] [15:0] chain_data_in_f_0,
  input logic [0:0] [15:0] chain_data_in_f_1,
  input logic clk,
  input logic clk_en,
  input logic [3:0] [15:0] data_from_strg_lifted,
  input logic [0:0] [15:0] data_in_f_0,
  input logic [0:0] [15:0] data_in_f_1,
  input logic flush,
  input logic rst_n,
  input logic [3:0] strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides,
  input logic [3:0] strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides,
  input logic strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable,
  input logic [15:0] strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides,
  input logic strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable,
  input logic [15:0] strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] strg_ub_vec_inst_agg_only_delay_0,
  input logic [3:0] strg_ub_vec_inst_agg_only_delay_1,
  input logic [2:0] strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality,
  input logic [2:0] [9:0] strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges,
  input logic [2:0] strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality,
  input logic [2:0] [9:0] strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges,
  input logic [5:0] strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding,
  input logic [5:0] strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding,
  input logic [8:0] strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr,
  input logic [8:0] strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr,
  input logic [3:0] strg_ub_vec_inst_agg_sram_shared_delay_0,
  input logic [3:0] strg_ub_vec_inst_agg_sram_shared_delay_1,
  input logic [1:0] strg_ub_vec_inst_agg_sram_shared_mode_0,
  input logic [1:0] strg_ub_vec_inst_agg_sram_shared_mode_1,
  input logic strg_ub_vec_inst_chain_chain_en,
  input logic [8:0] strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr,
  input logic [5:0] [8:0] strg_ub_vec_inst_sram_only_output_addr_gen_0_strides,
  input logic [8:0] strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr,
  input logic [5:0] [8:0] strg_ub_vec_inst_sram_only_output_addr_gen_1_strides,
  input logic [3:0] strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality,
  input logic [5:0] [9:0] strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges,
  input logic [3:0] strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality,
  input logic [5:0] [9:0] strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges,
  input logic strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable,
  input logic [15:0] strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides,
  input logic strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable,
  input logic [15:0] strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality,
  input logic [5:0] [9:0] strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges,
  input logic [3:0] strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality,
  input logic [5:0] [9:0] strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges,
  input logic [3:0] strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides,
  input logic [3:0] strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides,
  input logic strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable,
  input logic [15:0] strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides,
  input logic strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable,
  input logic [15:0] strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr,
  input logic [5:0] [15:0] strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides,
  input logic [3:0] strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides,
  input logic [3:0] strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr,
  input logic [5:0] [3:0] strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides,
  output logic accessor_output_f_b_0,
  output logic accessor_output_f_b_1,
  output logic [8:0] addr_out_lifted,
  output logic [0:0] [15:0] data_out_f_0,
  output logic [0:0] [15:0] data_out_f_1,
  output logic [3:0] [15:0] data_to_strg_lifted,
  output logic ren_to_strg_lifted,
  output logic wen_to_strg_lifted
);

logic [1:0] strg_ub_vec_inst_accessor_output;
logic [1:0][15:0] strg_ub_vec_inst_chain_data_in;
logic [1:0][15:0] strg_ub_vec_inst_data_in;
logic [1:0][15:0] strg_ub_vec_inst_data_out;
assign strg_ub_vec_inst_data_in[0] = data_in_f_0;
assign strg_ub_vec_inst_data_in[1] = data_in_f_1;
assign strg_ub_vec_inst_chain_data_in[0] = chain_data_in_f_0;
assign strg_ub_vec_inst_chain_data_in[1] = chain_data_in_f_1;
assign data_out_f_0 = strg_ub_vec_inst_data_out[0];
assign data_out_f_1 = strg_ub_vec_inst_data_out[1];
assign accessor_output_f_b_0 = strg_ub_vec_inst_accessor_output[0];
assign accessor_output_f_b_1 = strg_ub_vec_inst_accessor_output[1];
strg_ub_vec strg_ub_vec_inst (
  .agg_only_agg_write_addr_gen_0_starting_addr(strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr),
  .agg_only_agg_write_addr_gen_0_strides(strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides),
  .agg_only_agg_write_addr_gen_1_starting_addr(strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr),
  .agg_only_agg_write_addr_gen_1_strides(strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides),
  .agg_only_agg_write_sched_gen_0_enable(strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable),
  .agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr(strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr),
  .agg_only_agg_write_sched_gen_0_sched_addr_gen_strides(strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides),
  .agg_only_agg_write_sched_gen_1_enable(strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable),
  .agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr(strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr),
  .agg_only_agg_write_sched_gen_1_sched_addr_gen_strides(strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides),
  .agg_only_delay_0(strg_ub_vec_inst_agg_only_delay_0),
  .agg_only_delay_1(strg_ub_vec_inst_agg_only_delay_1),
  .agg_only_loops_in2buf_0_dimensionality(strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality),
  .agg_only_loops_in2buf_0_ranges(strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges),
  .agg_only_loops_in2buf_1_dimensionality(strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality),
  .agg_only_loops_in2buf_1_ranges(strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges),
  .agg_sram_shared_agg_read_sched_gen_0_agg_read_padding(strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_agg_read_padding),
  .agg_sram_shared_agg_read_sched_gen_1_agg_read_padding(strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_agg_read_padding),
  .agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr(strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_0_starting_addr),
  .agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr(strg_ub_vec_inst_agg_sram_shared_agg_sram_shared_addr_gen_1_starting_addr),
  .agg_sram_shared_delay_0(strg_ub_vec_inst_agg_sram_shared_delay_0),
  .agg_sram_shared_delay_1(strg_ub_vec_inst_agg_sram_shared_delay_1),
  .agg_sram_shared_mode_0(strg_ub_vec_inst_agg_sram_shared_mode_0),
  .agg_sram_shared_mode_1(strg_ub_vec_inst_agg_sram_shared_mode_1),
  .chain_chain_en(strg_ub_vec_inst_chain_chain_en),
  .chain_data_in(strg_ub_vec_inst_chain_data_in),
  .clk(clk),
  .clk_en(clk_en),
  .data_from_strg(data_from_strg_lifted),
  .data_in(strg_ub_vec_inst_data_in),
  .flush(flush),
  .rst_n(rst_n),
  .sram_only_output_addr_gen_0_starting_addr(strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr),
  .sram_only_output_addr_gen_0_strides(strg_ub_vec_inst_sram_only_output_addr_gen_0_strides),
  .sram_only_output_addr_gen_1_starting_addr(strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr),
  .sram_only_output_addr_gen_1_strides(strg_ub_vec_inst_sram_only_output_addr_gen_1_strides),
  .sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality(strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality),
  .sram_tb_shared_loops_buf2out_autovec_read_0_ranges(strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges),
  .sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality(strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality),
  .sram_tb_shared_loops_buf2out_autovec_read_1_ranges(strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges),
  .sram_tb_shared_output_sched_gen_0_enable(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable),
  .sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr),
  .sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides),
  .sram_tb_shared_output_sched_gen_1_enable(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable),
  .sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr),
  .sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides(strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides),
  .tb_only_loops_buf2out_read_0_dimensionality(strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality),
  .tb_only_loops_buf2out_read_0_ranges(strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges),
  .tb_only_loops_buf2out_read_1_dimensionality(strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality),
  .tb_only_loops_buf2out_read_1_ranges(strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges),
  .tb_only_tb_read_addr_gen_0_starting_addr(strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr),
  .tb_only_tb_read_addr_gen_0_strides(strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides),
  .tb_only_tb_read_addr_gen_1_starting_addr(strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr),
  .tb_only_tb_read_addr_gen_1_strides(strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides),
  .tb_only_tb_read_sched_gen_0_enable(strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable),
  .tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr(strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr),
  .tb_only_tb_read_sched_gen_0_sched_addr_gen_strides(strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides),
  .tb_only_tb_read_sched_gen_1_enable(strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable),
  .tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr(strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr),
  .tb_only_tb_read_sched_gen_1_sched_addr_gen_strides(strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides),
  .tb_only_tb_write_addr_gen_0_starting_addr(strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr),
  .tb_only_tb_write_addr_gen_0_strides(strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides),
  .tb_only_tb_write_addr_gen_1_starting_addr(strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr),
  .tb_only_tb_write_addr_gen_1_strides(strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides),
  .accessor_output(strg_ub_vec_inst_accessor_output),
  .addr_out(addr_out_lifted),
  .data_out(strg_ub_vec_inst_data_out),
  .data_to_strg(data_to_strg_lifted),
  .ren_to_strg(ren_to_strg_lifted),
  .wen_to_strg(wen_to_strg_lifted)
);

endmodule   // strg_ub_vec_flat

