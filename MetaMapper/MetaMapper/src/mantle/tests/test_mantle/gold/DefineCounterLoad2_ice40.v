module FullAdder (input  I0, input  I1, input  CIN, output  O, output  COUT);
wire  SB_LUT4_inst0_O;
wire  SB_CARRY_inst0_CO;
SB_LUT4 #(.LUT_INIT(16'h9696)) SB_LUT4_inst0 (.I0(I0), .I1(I1), .I2(CIN), .I3(1'b0), .O(SB_LUT4_inst0_O));
SB_CARRY SB_CARRY_inst0 (.I0(I0), .I1(I1), .CI(CIN), .CO(SB_CARRY_inst0_CO));
assign O = SB_LUT4_inst0_O;
assign COUT = SB_CARRY_inst0_CO;
endmodule

module Add2_COUT (input [1:0] I0, input [1:0] I1, output [1:0] O, output  COUT);
wire  FullAdder_inst0_O;
wire  FullAdder_inst0_COUT;
wire  FullAdder_inst1_O;
wire  FullAdder_inst1_COUT;
FullAdder FullAdder_inst0 (.I0(I0[0]), .I1(I1[0]), .CIN(1'b0), .O(FullAdder_inst0_O), .COUT(FullAdder_inst0_COUT));
FullAdder FullAdder_inst1 (.I0(I0[1]), .I1(I1[1]), .CIN(FullAdder_inst0_COUT), .O(FullAdder_inst1_O), .COUT(FullAdder_inst1_COUT));
assign O = {FullAdder_inst1_O,FullAdder_inst0_O};
assign COUT = FullAdder_inst1_COUT;
endmodule

module Mux2 (input [1:0] I, input  S, output  O);
wire  SB_LUT4_inst0_O;
SB_LUT4 #(.LUT_INIT(16'hCACA)) SB_LUT4_inst0 (.I0(I[0]), .I1(I[1]), .I2(S), .I3(1'b0), .O(SB_LUT4_inst0_O));
assign O = SB_LUT4_inst0_O;
endmodule

module Mux2x2 (input [1:0] I0, input [1:0] I1, input  S, output [1:0] O);
wire  Mux2_inst0_O;
wire  Mux2_inst1_O;
Mux2 Mux2_inst0 (.I({I1[0],I0[0]}), .S(S), .O(Mux2_inst0_O));
Mux2 Mux2_inst1 (.I({I1[1],I0[1]}), .S(S), .O(Mux2_inst1_O));
assign O = {Mux2_inst1_O,Mux2_inst0_O};
endmodule

module Register2 (input [1:0] I, output [1:0] O, input  CLK);
wire  SB_DFF_inst0_Q;
wire  SB_DFF_inst1_Q;
SB_DFF SB_DFF_inst0 (.C(CLK), .D(I[0]), .Q(SB_DFF_inst0_Q));
SB_DFF SB_DFF_inst1 (.C(CLK), .D(I[1]), .Q(SB_DFF_inst1_Q));
assign O = {SB_DFF_inst1_Q,SB_DFF_inst0_Q};
endmodule

module CounterLoad2_COUT (input [1:0] DATA, input  LOAD, output [1:0] O, output  COUT, input  CLK);
wire [1:0] Add2_COUT_inst0_O;
wire  Add2_COUT_inst0_COUT;
wire [1:0] Mux2x2_inst0_O;
wire [1:0] Register2_inst0_O;
Add2_COUT Add2_COUT_inst0 (.I0(Register2_inst0_O), .I1(2'd1'), .O(Add2_COUT_inst0_O), .COUT(Add2_COUT_inst0_COUT));
Mux2x2 Mux2x2_inst0 (.I0(Add2_COUT_inst0_O), .I1(DATA), .S(LOAD), .O(Mux2x2_inst0_O));
Register2 Register2_inst0 (.I(Mux2x2_inst0_O), .O(Register2_inst0_O), .CLK(CLK));
assign O = Register2_inst0_O;
assign COUT = Add2_COUT_inst0_COUT;
endmodule

