var s_op_hcompute_conv0_stencil, integer;
var s_op_hcompute_conv0_stencil_1, integer;
var s_op_hcompute_conv1_stencil, integer;
var s_op_hcompute_conv1_stencil_1, integer;
var s_op_hcompute_conv2_stencil, integer;
var s_op_hcompute_conv2_stencil_1, integer;
var s_op_hcompute_hw_input_global_wrapper_stencil, integer;
var s_op_hcompute_hw_output_stencil, integer;
s.t. c0 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + -1>= 0;
s.t. c1 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 1*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c2 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + -1*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c3 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 1*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c4 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + -1*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c5 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 1*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c6 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + -1*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c7 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 1*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c8 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + -1*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c9 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 1*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c10 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + -1*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c11 : -1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + 1*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c12 : 1*s_op_hcompute_conv0_stencil_1 + 0*s_op_hcompute_conv0_stencil + -1*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c13 : -1*s_op_hcompute_conv0_stencil_1 + 1*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
s.t. c14 : 1*s_op_hcompute_conv0_stencil_1 + -1*s_op_hcompute_conv0_stencil + 0*s_op_hcompute_conv1_stencil_1 + 0*s_op_hcompute_hw_output_stencil + 0*s_op_hcompute_conv2_stencil_1 + 0*s_op_hcompute_hw_input_global_wrapper_stencil + 0*s_op_hcompute_conv2_stencil + 0*s_op_hcompute_conv1_stencil + 0>= 0;
minimize obj: 1*s_op_hcompute_conv0_stencil + 1*s_op_hcompute_conv0_stencil_1 + 1*s_op_hcompute_conv1_stencil + 1*s_op_hcompute_conv1_stencil_1 + 1*s_op_hcompute_conv2_stencil + 1*s_op_hcompute_conv2_stencil_1 + 1*s_op_hcompute_hw_input_global_wrapper_stencil + 1*s_op_hcompute_hw_output_stencil;
solve;printf "s_op_hcompute_conv0_stencil = %d\n", s_op_hcompute_conv0_stencil;
printf "s_op_hcompute_conv0_stencil_1 = %d\n", s_op_hcompute_conv0_stencil_1;
printf "s_op_hcompute_conv1_stencil = %d\n", s_op_hcompute_conv1_stencil;
printf "s_op_hcompute_conv1_stencil_1 = %d\n", s_op_hcompute_conv1_stencil_1;
printf "s_op_hcompute_conv2_stencil = %d\n", s_op_hcompute_conv2_stencil;
printf "s_op_hcompute_conv2_stencil_1 = %d\n", s_op_hcompute_conv2_stencil_1;
printf "s_op_hcompute_hw_input_global_wrapper_stencil = %d\n", s_op_hcompute_hw_input_global_wrapper_stencil;
printf "s_op_hcompute_hw_output_stencil = %d\n", s_op_hcompute_hw_output_stencil;
end;
