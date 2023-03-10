module corebit_and (
    input in0,
    input in1,
    output out
);
  assign out = in0 & in1;
endmodule

module TestBinary (
    input I0,
    input I1,
    output O
);
wire magma_Bit_and_inst0_out;
corebit_and magma_Bit_and_inst0 (
    .in0(I0),
    .in1(I1),
    .out(magma_Bit_and_inst0_out)
);
assign O = magma_Bit_and_inst0_out;
endmodule

