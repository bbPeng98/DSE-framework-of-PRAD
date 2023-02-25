// Generated by CIRCT circtorg-0.0.0-1018-g3a39b339f
module simple_bind_asserts(
  input I,
        O,
        CLK);

  wire _magma_inline_wire0 = O;
  wire _magma_inline_wire1 = I;
  assert property (@(posedge CLK) _magma_inline_wire1 |-> ##1 _magma_inline_wire0);
endmodule

module simple_bind(
  input  I,
         CLK,
  output O);

  reg Register_inst0;
  always_ff @(posedge CLK)
    Register_inst0 <= I;
  initial
    Register_inst0 = 1'h0;
  /* This instance is elsewhere emitted as a bind statement.
    simple_bind_asserts simple_bind_asserts_inst (
      .I   (I),
      .O   (Register_inst0),
      .CLK (CLK)
    );
  */
  assign O = Register_inst0;
endmodule


// ----- 8< ----- FILE "bindfile" ----- 8< -----

bind simple_bind simple_bind_asserts simple_bind_asserts_inst (
  .I   (I),
  .O   (Register_inst0),
  .CLK (CLK)
);