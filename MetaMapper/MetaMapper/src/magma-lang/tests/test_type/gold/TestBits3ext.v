module corebit_const #(
    parameter value = 1
) (
    output out
);
  assign out = value;
endmodule

module TestExt (
    input [2:0] I,
    output [5:0] O
);
wire bit_const_0_None_out;
corebit_const #(
    .value(1'b0)
) bit_const_0_None (
    .out(bit_const_0_None_out)
);
assign O = {bit_const_0_None_out,bit_const_0_None_out,bit_const_0_None_out,I};
endmodule

