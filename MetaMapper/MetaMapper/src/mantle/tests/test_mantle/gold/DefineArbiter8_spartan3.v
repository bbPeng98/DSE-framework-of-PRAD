module Add8_cin0 (input [7:0] I0, input [7:0] I1, output [7:0] O);
wire  LUT2_inst0_O;
wire  MUXCY_inst0_O;
wire  XORCY_inst0_O;
wire  LUT2_inst1_O;
wire  MUXCY_inst1_O;
wire  XORCY_inst1_O;
wire  LUT2_inst2_O;
wire  MUXCY_inst2_O;
wire  XORCY_inst2_O;
wire  LUT2_inst3_O;
wire  MUXCY_inst3_O;
wire  XORCY_inst3_O;
wire  LUT2_inst4_O;
wire  MUXCY_inst4_O;
wire  XORCY_inst4_O;
wire  LUT2_inst5_O;
wire  MUXCY_inst5_O;
wire  XORCY_inst5_O;
wire  LUT2_inst6_O;
wire  MUXCY_inst6_O;
wire  XORCY_inst6_O;
wire  LUT2_inst7_O;
wire  MUXCY_inst7_O;
wire  XORCY_inst7_O;
LUT2 #(.INIT(4'h6)) LUT2_inst0 (.I0(I0[0]), .I1(I1[0]), .O(LUT2_inst0_O));
MUXCY MUXCY_inst0 (.DI(I0[0]), .CI(1'b0), .S(LUT2_inst0_O), .O(MUXCY_inst0_O));
XORCY XORCY_inst0 (.LI(LUT2_inst0_O), .CI(1'b0), .O(XORCY_inst0_O));
LUT2 #(.INIT(4'h6)) LUT2_inst1 (.I0(I0[1]), .I1(I1[1]), .O(LUT2_inst1_O));
MUXCY MUXCY_inst1 (.DI(I0[1]), .CI(MUXCY_inst0_O), .S(LUT2_inst1_O), .O(MUXCY_inst1_O));
XORCY XORCY_inst1 (.LI(LUT2_inst1_O), .CI(MUXCY_inst0_O), .O(XORCY_inst1_O));
LUT2 #(.INIT(4'h6)) LUT2_inst2 (.I0(I0[2]), .I1(I1[2]), .O(LUT2_inst2_O));
MUXCY MUXCY_inst2 (.DI(I0[2]), .CI(MUXCY_inst1_O), .S(LUT2_inst2_O), .O(MUXCY_inst2_O));
XORCY XORCY_inst2 (.LI(LUT2_inst2_O), .CI(MUXCY_inst1_O), .O(XORCY_inst2_O));
LUT2 #(.INIT(4'h6)) LUT2_inst3 (.I0(I0[3]), .I1(I1[3]), .O(LUT2_inst3_O));
MUXCY MUXCY_inst3 (.DI(I0[3]), .CI(MUXCY_inst2_O), .S(LUT2_inst3_O), .O(MUXCY_inst3_O));
XORCY XORCY_inst3 (.LI(LUT2_inst3_O), .CI(MUXCY_inst2_O), .O(XORCY_inst3_O));
LUT2 #(.INIT(4'h6)) LUT2_inst4 (.I0(I0[4]), .I1(I1[4]), .O(LUT2_inst4_O));
MUXCY MUXCY_inst4 (.DI(I0[4]), .CI(MUXCY_inst3_O), .S(LUT2_inst4_O), .O(MUXCY_inst4_O));
XORCY XORCY_inst4 (.LI(LUT2_inst4_O), .CI(MUXCY_inst3_O), .O(XORCY_inst4_O));
LUT2 #(.INIT(4'h6)) LUT2_inst5 (.I0(I0[5]), .I1(I1[5]), .O(LUT2_inst5_O));
MUXCY MUXCY_inst5 (.DI(I0[5]), .CI(MUXCY_inst4_O), .S(LUT2_inst5_O), .O(MUXCY_inst5_O));
XORCY XORCY_inst5 (.LI(LUT2_inst5_O), .CI(MUXCY_inst4_O), .O(XORCY_inst5_O));
LUT2 #(.INIT(4'h6)) LUT2_inst6 (.I0(I0[6]), .I1(I1[6]), .O(LUT2_inst6_O));
MUXCY MUXCY_inst6 (.DI(I0[6]), .CI(MUXCY_inst5_O), .S(LUT2_inst6_O), .O(MUXCY_inst6_O));
XORCY XORCY_inst6 (.LI(LUT2_inst6_O), .CI(MUXCY_inst5_O), .O(XORCY_inst6_O));
LUT2 #(.INIT(4'h6)) LUT2_inst7 (.I0(I0[7]), .I1(I1[7]), .O(LUT2_inst7_O));
MUXCY MUXCY_inst7 (.DI(I0[7]), .CI(MUXCY_inst6_O), .S(LUT2_inst7_O), .O(MUXCY_inst7_O));
XORCY XORCY_inst7 (.LI(LUT2_inst7_O), .CI(MUXCY_inst6_O), .O(XORCY_inst7_O));
assign O = {XORCY_inst7_O,XORCY_inst6_O,XORCY_inst5_O,XORCY_inst4_O,XORCY_inst3_O,XORCY_inst2_O,XORCY_inst1_O,XORCY_inst0_O};
endmodule

module Arbiter8 (input [7:0] I, output [7:0] O);
wire [7:0] Add8_cin0_inst0_O;
wire  LUT2_inst0_O;
wire  LUT2_inst1_O;
wire  LUT2_inst2_O;
wire  LUT2_inst3_O;
wire  LUT2_inst4_O;
wire  LUT2_inst5_O;
wire  LUT2_inst6_O;
wire  LUT2_inst7_O;
Add8_cin0 Add8_cin0_inst0 (.I0(I), .I1(8'd255'), .O(Add8_cin0_inst0_O));
LUT2 #(.INIT(4'h2)) LUT2_inst0 (.I0(I[0]), .I1(Add8_cin0_inst0_O[0]), .O(LUT2_inst0_O));
LUT2 #(.INIT(4'h2)) LUT2_inst1 (.I0(I[1]), .I1(Add8_cin0_inst0_O[1]), .O(LUT2_inst1_O));
LUT2 #(.INIT(4'h2)) LUT2_inst2 (.I0(I[2]), .I1(Add8_cin0_inst0_O[2]), .O(LUT2_inst2_O));
LUT2 #(.INIT(4'h2)) LUT2_inst3 (.I0(I[3]), .I1(Add8_cin0_inst0_O[3]), .O(LUT2_inst3_O));
LUT2 #(.INIT(4'h2)) LUT2_inst4 (.I0(I[4]), .I1(Add8_cin0_inst0_O[4]), .O(LUT2_inst4_O));
LUT2 #(.INIT(4'h2)) LUT2_inst5 (.I0(I[5]), .I1(Add8_cin0_inst0_O[5]), .O(LUT2_inst5_O));
LUT2 #(.INIT(4'h2)) LUT2_inst6 (.I0(I[6]), .I1(Add8_cin0_inst0_O[6]), .O(LUT2_inst6_O));
LUT2 #(.INIT(4'h2)) LUT2_inst7 (.I0(I[7]), .I1(Add8_cin0_inst0_O[7]), .O(LUT2_inst7_O));
assign O = {LUT2_inst7_O,LUT2_inst6_O,LUT2_inst5_O,LUT2_inst4_O,LUT2_inst3_O,LUT2_inst2_O,LUT2_inst1_O,LUT2_inst0_O};
endmodule

