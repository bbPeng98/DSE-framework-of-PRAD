module addr_gen_2_16 (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic mux_sel,
  input logic restart,
  input logic rst_n,
  input logic [15:0] starting_addr,
  input logic step,
  input logic [1:0] [15:0] strides,
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
endmodule   // addr_gen_2_16

module addr_gen_2_5 (
  input logic clk,
  input logic clk_en,
  input logic flush,
  input logic mux_sel,
  input logic restart,
  input logic rst_n,
  input logic [4:0] starting_addr,
  input logic step,
  input logic [1:0] [4:0] strides,
  output logic [4:0] addr_out
);

logic [4:0] calc_addr;
logic [4:0] current_addr;
logic [4:0] strt_addr;
assign strt_addr = starting_addr;
assign addr_out = calc_addr;
assign calc_addr = strt_addr + current_addr;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    current_addr <= 5'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      current_addr <= 5'h0;
    end
    else if (step) begin
      if (restart) begin
        current_addr <= 5'h0;
      end
      else current_addr <= current_addr + strides[mux_sel];
    end
  end
end
endmodule   // addr_gen_2_5

module for_loop_2_16 #(
  parameter CONFIG_WIDTH = 5'h10,
  parameter ITERATOR_SUPPORT = 2'h2
)
(
  input logic clk,
  input logic clk_en,
  input logic [1:0] dimensionality,
  input logic flush,
  input logic [1:0] [15:0] ranges,
  input logic rst_n,
  input logic step,
  output logic mux_sel_out,
  output logic restart
);

logic [1:0] clear;
logic [1:0][15:0] dim_counter;
logic done;
logic [1:0] inc;
logic [15:0] inced_cnt;
logic [1:0] max_value;
logic maxed_value;
logic mux_sel;
assign mux_sel_out = mux_sel;
assign inced_cnt = dim_counter[mux_sel] + 16'h1;
assign maxed_value = (dim_counter[mux_sel] == ranges[mux_sel]) & inc[mux_sel];
always_comb begin
  mux_sel = 1'h0;
  done = 1'h0;
  if (~done) begin
    if ((~max_value[0]) & (dimensionality > 2'h0)) begin
      mux_sel = 1'h0;
      done = 1'h1;
    end
  end
  if (~done) begin
    if ((~max_value[1]) & (dimensionality > 2'h1)) begin
      mux_sel = 1'h1;
      done = 1'h1;
    end
  end
end
always_comb begin
  clear[0] = 1'h0;
  if (((mux_sel > 1'h0) | (~done)) & step) begin
    clear[0] = 1'h1;
  end
end
always_comb begin
  inc[0] = 1'h0;
  if ((5'h0 == 5'h0) & step & (dimensionality > 2'h0)) begin
    inc[0] = 1'h1;
  end
  else if ((mux_sel == 1'h0) & step & (dimensionality > 2'h0)) begin
    inc[0] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[0] <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[0] <= 16'h0;
    end
    else if (clear[0]) begin
      dim_counter[0] <= 16'h0;
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
  if (((mux_sel > 1'h1) | (~done)) & step) begin
    clear[1] = 1'h1;
  end
end
always_comb begin
  inc[1] = 1'h0;
  if ((5'h1 == 5'h0) & step & (dimensionality > 2'h1)) begin
    inc[1] = 1'h1;
  end
  else if ((mux_sel == 1'h1) & step & (dimensionality > 2'h1)) begin
    inc[1] = 1'h1;
  end
end

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    dim_counter[1] <= 16'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      dim_counter[1] <= 16'h0;
    end
    else if (clear[1]) begin
      dim_counter[1] <= 16'h0;
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
assign restart = step & (~done);
endmodule   // for_loop_2_16

module pond (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [31:0] config_data_in,
  input logic config_en,
  input logic config_read,
  input logic config_write,
  input logic [0:0] [15:0] data_in_pond,
  input logic flush,
  input logic [4:0] rf_read_addr_0_starting_addr,
  input logic [1:0] [4:0] rf_read_addr_0_strides,
  input logic [1:0] rf_read_iter_0_dimensionality,
  input logic [1:0] [15:0] rf_read_iter_0_ranges,
  input logic rf_read_sched_0_enable,
  input logic [15:0] rf_read_sched_0_sched_addr_gen_starting_addr,
  input logic [1:0] [15:0] rf_read_sched_0_sched_addr_gen_strides,
  input logic [4:0] rf_write_addr_0_starting_addr,
  input logic [1:0] [4:0] rf_write_addr_0_strides,
  input logic [1:0] rf_write_iter_0_dimensionality,
  input logic [1:0] [15:0] rf_write_iter_0_ranges,
  input logic rf_write_sched_0_enable,
  input logic [15:0] rf_write_sched_0_sched_addr_gen_starting_addr,
  input logic [1:0] [15:0] rf_write_sched_0_sched_addr_gen_strides,
  input logic rst_n,
  input logic tile_en,
  output logic [0:0] [31:0] config_data_out,
  output logic [0:0] [15:0] data_out_pond,
  output logic valid_out_pond
);

logic cfg_seq_clk;
logic [15:0] config_data_in_shrt;
logic [0:0][15:0] config_data_out_shrt;
logic config_seq_clk_en;
logic [15:0] cycle_count;
logic gclk;
logic [4:0] mem_addr_cfg;
logic [0:0][15:0] mem_data_cfg;
logic [0:0][15:0] mem_data_in;
logic [0:0][15:0] mem_data_out;
logic [0:0][4:0] mem_read_addr;
logic [0:0][4:0] mem_write_addr;
logic read;
logic [0:0][4:0] read_addr;
logic [4:0] rf_read_addr_0_addr_out;
logic rf_read_iter_0_mux_sel_out;
logic rf_read_iter_0_restart;
logic rf_read_sched_0_valid_output;
logic [4:0] rf_write_addr_0_addr_out;
logic rf_write_iter_0_mux_sel_out;
logic rf_write_iter_0_restart;
logic rf_write_sched_0_valid_output;
logic [0:0][15:0] s_mem_data_in;
logic [0:0][4:0] s_mem_read_addr;
logic [0:0][4:0] s_mem_write_addr;
logic t_read;
logic t_write;
logic write;
logic [0:0][4:0] write_addr;
logic write_rf;
assign gclk = clk & tile_en;

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
assign data_out_pond[0] = mem_data_out[0];
assign valid_out_pond = t_read;
assign write_addr[0] = rf_write_addr_0_addr_out;
assign t_write = rf_write_sched_0_valid_output;
assign read_addr[0] = rf_read_addr_0_addr_out;
assign t_read = rf_read_sched_0_valid_output;
assign write = |t_write;
assign mem_write_addr[0] = s_mem_write_addr[0];
assign mem_data_in[0] = s_mem_data_in[0];
assign read = |t_read;
assign mem_read_addr[0] = s_mem_read_addr[0];
assign config_data_in_shrt = config_data_in[15:0];
assign config_data_out[0] = 32'(config_data_out_shrt[0]);
assign cfg_seq_clk = gclk;
assign config_seq_clk_en = clk_en | (|config_en);
assign write_rf = (|config_en) ? config_write: write;
assign s_mem_data_in[0] = (|config_en) ? mem_data_cfg: data_in_pond[0];
assign s_mem_write_addr[0] = (|config_en) ? mem_addr_cfg: write_addr[0];
assign s_mem_read_addr[0] = (|config_en) ? mem_addr_cfg: read_addr[0];
for_loop_2_16 #(
  .CONFIG_WIDTH(5'h10),
  .ITERATOR_SUPPORT(2'h2))
rf_write_iter_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .dimensionality(rf_write_iter_0_dimensionality),
  .flush(flush),
  .ranges(rf_write_iter_0_ranges),
  .rst_n(rst_n),
  .step(t_write),
  .mux_sel_out(rf_write_iter_0_mux_sel_out),
  .restart(rf_write_iter_0_restart)
);

addr_gen_2_5 rf_write_addr_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(rf_write_iter_0_mux_sel_out),
  .restart(rf_write_iter_0_restart),
  .rst_n(rst_n),
  .starting_addr(rf_write_addr_0_starting_addr),
  .step(t_write),
  .strides(rf_write_addr_0_strides),
  .addr_out(rf_write_addr_0_addr_out)
);

sched_gen_2_16 rf_write_sched_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(rf_write_sched_0_enable),
  .finished(rf_write_iter_0_restart),
  .flush(flush),
  .mux_sel(rf_write_iter_0_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(rf_write_sched_0_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(rf_write_sched_0_sched_addr_gen_strides),
  .valid_output(rf_write_sched_0_valid_output)
);

for_loop_2_16 #(
  .CONFIG_WIDTH(5'h10),
  .ITERATOR_SUPPORT(2'h2))
rf_read_iter_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .dimensionality(rf_read_iter_0_dimensionality),
  .flush(flush),
  .ranges(rf_read_iter_0_ranges),
  .rst_n(rst_n),
  .step(t_read),
  .mux_sel_out(rf_read_iter_0_mux_sel_out),
  .restart(rf_read_iter_0_restart)
);

addr_gen_2_5 rf_read_addr_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .flush(flush),
  .mux_sel(rf_read_iter_0_mux_sel_out),
  .restart(rf_read_iter_0_restart),
  .rst_n(rst_n),
  .starting_addr(rf_read_addr_0_starting_addr),
  .step(t_read),
  .strides(rf_read_addr_0_strides),
  .addr_out(rf_read_addr_0_addr_out)
);

sched_gen_2_16 rf_read_sched_0 (
  .clk(gclk),
  .clk_en(clk_en),
  .cycle_count(cycle_count),
  .enable(rf_read_sched_0_enable),
  .finished(rf_read_iter_0_restart),
  .flush(flush),
  .mux_sel(rf_read_iter_0_mux_sel_out),
  .rst_n(rst_n),
  .sched_addr_gen_starting_addr(rf_read_sched_0_sched_addr_gen_starting_addr),
  .sched_addr_gen_strides(rf_read_sched_0_sched_addr_gen_strides),
  .valid_output(rf_read_sched_0_valid_output)
);

storage_config_seq_unq0 config_seq (
  .clk(cfg_seq_clk),
  .clk_en(config_seq_clk_en),
  .config_addr_in(config_addr_in),
  .config_data_in(config_data_in_shrt),
  .config_en(config_en),
  .config_rd(config_read),
  .config_wr(config_write),
  .flush(flush),
  .rd_data_stg(mem_data_out),
  .rst_n(rst_n),
  .addr_out(mem_addr_cfg),
  .rd_data_out(config_data_out_shrt),
  .wr_data(mem_data_cfg)
);

register_file rf (
  .clk(gclk),
  .clk_en(clk_en),
  .data_in(mem_data_in),
  .flush(flush),
  .rd_addr(mem_read_addr[0]),
  .rst_n(rst_n),
  .wen(write_rf),
  .wr_addr(mem_write_addr[0]),
  .data_out(mem_data_out)
);

endmodule   // pond

module pond_W (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [31:0] config_data_in,
  input logic config_en,
  input logic config_read,
  input logic config_write,
  input logic [0:0] [15:0] data_in_pond,
  input logic flush,
  input logic [4:0] rf_read_addr_0_starting_addr,
  input logic [4:0] rf_read_addr_0_strides_0,
  input logic [4:0] rf_read_addr_0_strides_1,
  input logic [1:0] rf_read_iter_0_dimensionality,
  input logic [15:0] rf_read_iter_0_ranges_0,
  input logic [15:0] rf_read_iter_0_ranges_1,
  input logic rf_read_sched_0_enable,
  input logic [15:0] rf_read_sched_0_sched_addr_gen_starting_addr,
  input logic [15:0] rf_read_sched_0_sched_addr_gen_strides_0,
  input logic [15:0] rf_read_sched_0_sched_addr_gen_strides_1,
  input logic [4:0] rf_write_addr_0_starting_addr,
  input logic [4:0] rf_write_addr_0_strides_0,
  input logic [4:0] rf_write_addr_0_strides_1,
  input logic [1:0] rf_write_iter_0_dimensionality,
  input logic [15:0] rf_write_iter_0_ranges_0,
  input logic [15:0] rf_write_iter_0_ranges_1,
  input logic rf_write_sched_0_enable,
  input logic [15:0] rf_write_sched_0_sched_addr_gen_starting_addr,
  input logic [15:0] rf_write_sched_0_sched_addr_gen_strides_0,
  input logic [15:0] rf_write_sched_0_sched_addr_gen_strides_1,
  input logic rst_n,
  input logic tile_en,
  output logic [0:0] [31:0] config_data_out,
  output logic [0:0] [15:0] data_out_pond,
  output logic valid_out_pond
);

logic [1:0][4:0] pond_rf_read_addr_0_strides;
logic [1:0][15:0] pond_rf_read_iter_0_ranges;
logic [1:0][15:0] pond_rf_read_sched_0_sched_addr_gen_strides;
logic [1:0][4:0] pond_rf_write_addr_0_strides;
logic [1:0][15:0] pond_rf_write_iter_0_ranges;
logic [1:0][15:0] pond_rf_write_sched_0_sched_addr_gen_strides;
assign pond_rf_read_addr_0_strides[0] = rf_read_addr_0_strides_0;
assign pond_rf_read_addr_0_strides[1] = rf_read_addr_0_strides_1;
assign pond_rf_read_iter_0_ranges[0] = rf_read_iter_0_ranges_0;
assign pond_rf_read_iter_0_ranges[1] = rf_read_iter_0_ranges_1;
assign pond_rf_read_sched_0_sched_addr_gen_strides[0] = rf_read_sched_0_sched_addr_gen_strides_0;
assign pond_rf_read_sched_0_sched_addr_gen_strides[1] = rf_read_sched_0_sched_addr_gen_strides_1;
assign pond_rf_write_addr_0_strides[0] = rf_write_addr_0_strides_0;
assign pond_rf_write_addr_0_strides[1] = rf_write_addr_0_strides_1;
assign pond_rf_write_iter_0_ranges[0] = rf_write_iter_0_ranges_0;
assign pond_rf_write_iter_0_ranges[1] = rf_write_iter_0_ranges_1;
assign pond_rf_write_sched_0_sched_addr_gen_strides[0] = rf_write_sched_0_sched_addr_gen_strides_0;
assign pond_rf_write_sched_0_sched_addr_gen_strides[1] = rf_write_sched_0_sched_addr_gen_strides_1;
pond pond (
  .clk(clk),
  .clk_en(clk_en),
  .config_addr_in(config_addr_in),
  .config_data_in(config_data_in),
  .config_en(config_en),
  .config_read(config_read),
  .config_write(config_write),
  .data_in_pond(data_in_pond),
  .flush(flush),
  .rf_read_addr_0_starting_addr(rf_read_addr_0_starting_addr),
  .rf_read_addr_0_strides(pond_rf_read_addr_0_strides),
  .rf_read_iter_0_dimensionality(rf_read_iter_0_dimensionality),
  .rf_read_iter_0_ranges(pond_rf_read_iter_0_ranges),
  .rf_read_sched_0_enable(rf_read_sched_0_enable),
  .rf_read_sched_0_sched_addr_gen_starting_addr(rf_read_sched_0_sched_addr_gen_starting_addr),
  .rf_read_sched_0_sched_addr_gen_strides(pond_rf_read_sched_0_sched_addr_gen_strides),
  .rf_write_addr_0_starting_addr(rf_write_addr_0_starting_addr),
  .rf_write_addr_0_strides(pond_rf_write_addr_0_strides),
  .rf_write_iter_0_dimensionality(rf_write_iter_0_dimensionality),
  .rf_write_iter_0_ranges(pond_rf_write_iter_0_ranges),
  .rf_write_sched_0_enable(rf_write_sched_0_enable),
  .rf_write_sched_0_sched_addr_gen_starting_addr(rf_write_sched_0_sched_addr_gen_starting_addr),
  .rf_write_sched_0_sched_addr_gen_strides(pond_rf_write_sched_0_sched_addr_gen_strides),
  .rst_n(rst_n),
  .tile_en(tile_en),
  .config_data_out(config_data_out),
  .data_out_pond(data_out_pond),
  .valid_out_pond(valid_out_pond)
);

endmodule   // pond_W

module register_file (
  input logic clk,
  input logic clk_en,
  input logic [0:0] [15:0] data_in,
  input logic flush,
  input logic [4:0] rd_addr,
  input logic rst_n,
  input logic wen,
  input logic [4:0] wr_addr,
  output logic [0:0] [15:0] data_out
);

logic [31:0][0:0][15:0] data_array;

always_ff @(posedge clk, negedge rst_n) begin
  if (~rst_n) begin
    data_array <= 512'h0;
  end
  else if (clk_en) begin
    if (flush) begin
      data_array <= 512'h0;
    end
    else if (wen) begin
      data_array[wr_addr] <= data_in;
    end
  end
end
always_comb begin
  data_out = data_array[rd_addr];
end
endmodule   // register_file

module sched_gen_2_16 (
  input logic clk,
  input logic clk_en,
  input logic [15:0] cycle_count,
  input logic enable,
  input logic finished,
  input logic flush,
  input logic mux_sel,
  input logic rst_n,
  input logic [15:0] sched_addr_gen_starting_addr,
  input logic [1:0] [15:0] sched_addr_gen_strides,
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
addr_gen_2_16 sched_addr_gen (
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

endmodule   // sched_gen_2_16

module storage_config_seq_unq0 (
  input logic clk,
  input logic clk_en,
  input logic [7:0] config_addr_in,
  input logic [15:0] config_data_in,
  input logic config_en,
  input logic config_rd,
  input logic config_wr,
  input logic flush,
  input logic [0:0][0:0] [15:0] rd_data_stg,
  input logic rst_n,
  output logic [4:0] addr_out,
  output logic [0:0] [15:0] rd_data_out,
  output logic ren_out,
  output logic wen_out,
  output logic [0:0] [15:0] wr_data
);

assign addr_out = config_addr_in[4:0];
assign wr_data[0] = config_data_in;
assign rd_data_out[0] = rd_data_stg[0];
assign wen_out = config_wr;
assign ren_out = config_rd;
endmodule   // storage_config_seq_unq0

