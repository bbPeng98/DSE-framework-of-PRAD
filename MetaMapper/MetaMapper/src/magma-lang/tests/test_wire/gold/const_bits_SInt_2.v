// Module `Buf` defined externally
module coreir_const #(
    parameter width = 1,
    parameter value = 1
) (
    output [width-1:0] out
);
  assign out = value;
endmodule

module main (
    output [1:0] O
);
wire [1:0] Buf_inst0_O;
wire [1:0] const_1_2_out;
Buf Buf_inst0 (
    .I(const_1_2_out),
    .O(Buf_inst0_O)
);
coreir_const #(
    .value(2'h1),
    .width(2)
) const_1_2 (
    .out(const_1_2_out)
);
assign O = Buf_inst0_O;
endmodule

