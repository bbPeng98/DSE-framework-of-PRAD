module Add8_cout (input [7:0] I0, input [7:0] I1, output [7:0] O, output  COUT);
wire  LUT6_2_inst0_O5;
wire  LUT6_2_inst0_O6;
wire  MUXCY_inst0_O;
wire  XORCY_inst0_O;
wire  LUT6_2_inst1_O5;
wire  LUT6_2_inst1_O6;
wire  MUXCY_inst1_O;
wire  XORCY_inst1_O;
wire  LUT6_2_inst2_O5;
wire  LUT6_2_inst2_O6;
wire  MUXCY_inst2_O;
wire  XORCY_inst2_O;
wire  LUT6_2_inst3_O5;
wire  LUT6_2_inst3_O6;
wire  MUXCY_inst3_O;
wire  XORCY_inst3_O;
wire  LUT6_2_inst4_O5;
wire  LUT6_2_inst4_O6;
wire  MUXCY_inst4_O;
wire  XORCY_inst4_O;
wire  LUT6_2_inst5_O5;
wire  LUT6_2_inst5_O6;
wire  MUXCY_inst5_O;
wire  XORCY_inst5_O;
wire  LUT6_2_inst6_O5;
wire  LUT6_2_inst6_O6;
wire  MUXCY_inst6_O;
wire  XORCY_inst6_O;
wire  LUT6_2_inst7_O5;
wire  LUT6_2_inst7_O6;
wire  MUXCY_inst7_O;
wire  XORCY_inst7_O;
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst0 (.I0(I0[0]), .I1(I1[0]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst0_O5), .O6(LUT6_2_inst0_O6));
MUXCY MUXCY_inst0 (.DI(LUT6_2_inst0_O5), .CI(1'b0), .S(LUT6_2_inst0_O6), .O(MUXCY_inst0_O));
XORCY XORCY_inst0 (.LI(LUT6_2_inst0_O6), .CI(1'b0), .O(XORCY_inst0_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst1 (.I0(I0[1]), .I1(I1[1]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst1_O5), .O6(LUT6_2_inst1_O6));
MUXCY MUXCY_inst1 (.DI(LUT6_2_inst1_O5), .CI(MUXCY_inst0_O), .S(LUT6_2_inst1_O6), .O(MUXCY_inst1_O));
XORCY XORCY_inst1 (.LI(LUT6_2_inst1_O6), .CI(MUXCY_inst0_O), .O(XORCY_inst1_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst2 (.I0(I0[2]), .I1(I1[2]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst2_O5), .O6(LUT6_2_inst2_O6));
MUXCY MUXCY_inst2 (.DI(LUT6_2_inst2_O5), .CI(MUXCY_inst1_O), .S(LUT6_2_inst2_O6), .O(MUXCY_inst2_O));
XORCY XORCY_inst2 (.LI(LUT6_2_inst2_O6), .CI(MUXCY_inst1_O), .O(XORCY_inst2_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst3 (.I0(I0[3]), .I1(I1[3]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst3_O5), .O6(LUT6_2_inst3_O6));
MUXCY MUXCY_inst3 (.DI(LUT6_2_inst3_O5), .CI(MUXCY_inst2_O), .S(LUT6_2_inst3_O6), .O(MUXCY_inst3_O));
XORCY XORCY_inst3 (.LI(LUT6_2_inst3_O6), .CI(MUXCY_inst2_O), .O(XORCY_inst3_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst4 (.I0(I0[4]), .I1(I1[4]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst4_O5), .O6(LUT6_2_inst4_O6));
MUXCY MUXCY_inst4 (.DI(LUT6_2_inst4_O5), .CI(MUXCY_inst3_O), .S(LUT6_2_inst4_O6), .O(MUXCY_inst4_O));
XORCY XORCY_inst4 (.LI(LUT6_2_inst4_O6), .CI(MUXCY_inst3_O), .O(XORCY_inst4_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst5 (.I0(I0[5]), .I1(I1[5]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst5_O5), .O6(LUT6_2_inst5_O6));
MUXCY MUXCY_inst5 (.DI(LUT6_2_inst5_O5), .CI(MUXCY_inst4_O), .S(LUT6_2_inst5_O6), .O(MUXCY_inst5_O));
XORCY XORCY_inst5 (.LI(LUT6_2_inst5_O6), .CI(MUXCY_inst4_O), .O(XORCY_inst5_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst6 (.I0(I0[6]), .I1(I1[6]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst6_O5), .O6(LUT6_2_inst6_O6));
MUXCY MUXCY_inst6 (.DI(LUT6_2_inst6_O5), .CI(MUXCY_inst5_O), .S(LUT6_2_inst6_O6), .O(MUXCY_inst6_O));
XORCY XORCY_inst6 (.LI(LUT6_2_inst6_O6), .CI(MUXCY_inst5_O), .O(XORCY_inst6_O));
LUT6_2 #(.INIT(64'h66666666AAAAAAAA)) LUT6_2_inst7 (.I0(I0[7]), .I1(I1[7]), .I2(1'b0), .I3(1'b0), .I4(1'b0), .I5(1'b1), .O5(LUT6_2_inst7_O5), .O6(LUT6_2_inst7_O6));
MUXCY MUXCY_inst7 (.DI(LUT6_2_inst7_O5), .CI(MUXCY_inst6_O), .S(LUT6_2_inst7_O6), .O(MUXCY_inst7_O));
XORCY XORCY_inst7 (.LI(LUT6_2_inst7_O6), .CI(MUXCY_inst6_O), .O(XORCY_inst7_O));
assign O = {XORCY_inst7_O,XORCY_inst6_O,XORCY_inst5_O,XORCY_inst4_O,XORCY_inst3_O,XORCY_inst2_O,XORCY_inst1_O,XORCY_inst0_O};
assign COUT = MUXCY_inst7_O;
endmodule

module Mux2 (input [1:0] I, input  S, output  O);
wire  LUT3_inst0_O;
LUT3 #(.INIT(8'hCA)) LUT3_inst0 (.I0(I[0]), .I1(I[1]), .I2(S), .O(LUT3_inst0_O));
assign O = LUT3_inst0_O;
endmodule

module Mux2x8 (input [7:0] I0, input [7:0] I1, input  S, output [7:0] O);
wire  Mux2_inst0_O;
wire  Mux2_inst1_O;
wire  Mux2_inst2_O;
wire  Mux2_inst3_O;
wire  Mux2_inst4_O;
wire  Mux2_inst5_O;
wire  Mux2_inst6_O;
wire  Mux2_inst7_O;
Mux2 Mux2_inst0 (.I({I1[0],I0[0]}), .S(S), .O(Mux2_inst0_O));
Mux2 Mux2_inst1 (.I({I1[1],I0[1]}), .S(S), .O(Mux2_inst1_O));
Mux2 Mux2_inst2 (.I({I1[2],I0[2]}), .S(S), .O(Mux2_inst2_O));
Mux2 Mux2_inst3 (.I({I1[3],I0[3]}), .S(S), .O(Mux2_inst3_O));
Mux2 Mux2_inst4 (.I({I1[4],I0[4]}), .S(S), .O(Mux2_inst4_O));
Mux2 Mux2_inst5 (.I({I1[5],I0[5]}), .S(S), .O(Mux2_inst5_O));
Mux2 Mux2_inst6 (.I({I1[6],I0[6]}), .S(S), .O(Mux2_inst6_O));
Mux2 Mux2_inst7 (.I({I1[7],I0[7]}), .S(S), .O(Mux2_inst7_O));
assign O = {Mux2_inst7_O,Mux2_inst6_O,Mux2_inst5_O,Mux2_inst4_O,Mux2_inst3_O,Mux2_inst2_O,Mux2_inst1_O,Mux2_inst0_O};
endmodule

module Register8 (input [7:0] I, output [7:0] O, input  CLK);
wire  FDRSE_inst0_Q;
wire  FDRSE_inst1_Q;
wire  FDRSE_inst2_Q;
wire  FDRSE_inst3_Q;
wire  FDRSE_inst4_Q;
wire  FDRSE_inst5_Q;
wire  FDRSE_inst6_Q;
wire  FDRSE_inst7_Q;
FDRSE #(.INIT(1'h0)) FDRSE_inst0 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[0]), .Q(FDRSE_inst0_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst1 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[1]), .Q(FDRSE_inst1_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst2 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[2]), .Q(FDRSE_inst2_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst3 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[3]), .Q(FDRSE_inst3_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst4 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[4]), .Q(FDRSE_inst4_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst5 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[5]), .Q(FDRSE_inst5_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst6 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[6]), .Q(FDRSE_inst6_Q));
FDRSE #(.INIT(1'h0)) FDRSE_inst7 (.C(CLK), .CE(1'b1), .R(1'b0), .S(1'b0), .D(I[7]), .Q(FDRSE_inst7_Q));
assign O = {FDRSE_inst7_Q,FDRSE_inst6_Q,FDRSE_inst5_Q,FDRSE_inst4_Q,FDRSE_inst3_Q,FDRSE_inst2_Q,FDRSE_inst1_Q,FDRSE_inst0_Q};
endmodule

module CounterLoad8_COUT (input [7:0] DATA, input  LOAD, output [7:0] O, output  COUT, input  CLK);
wire [7:0] Add8_cout_inst0_O;
wire  Add8_cout_inst0_COUT;
wire [7:0] Mux2x8_inst0_O;
wire [7:0] Register8_inst0_O;
Add8_cout Add8_cout_inst0 (.I0(Register8_inst0_O), .I1(8'd1'), .O(Add8_cout_inst0_O), .COUT(Add8_cout_inst0_COUT));
Mux2x8 Mux2x8_inst0 (.I0(Add8_cout_inst0_O), .I1(DATA), .S(LOAD), .O(Mux2x8_inst0_O));
Register8 Register8_inst0 (.I(Mux2x8_inst0_O), .O(Register8_inst0_O), .CLK(CLK));
assign O = Register8_inst0_O;
assign COUT = Add8_cout_inst0_COUT;
endmodule

