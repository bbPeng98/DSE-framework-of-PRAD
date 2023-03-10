// Module `AddPrim` defined externally
module _Add (
    input [7:0] I0,
    input [7:0] I1,
    output [7:0] O
);
wire [7:0] AddPrim_inst0_O;
AddPrim AddPrim_inst0 (
    .I0(I0),
    .I1(I1),
    .O(AddPrim_inst0_O)
);
assign O = AddPrim_inst0_O;
endmodule

