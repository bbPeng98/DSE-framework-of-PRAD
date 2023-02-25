hcompute_hw_kernel2_global_wrapper_stencil() {
// _hw_kernel2_stencil_1 added as input _hw_kernel2_stencil_1
// connected _hw_kernel2_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_kernel_global_wrapper_stencil() {
// _hw_kernel_stencil_1 added as input _hw_kernel_stencil_1
// connected _hw_kernel_stencil_1 to the output port
}

hcompute_conv1_stencil() {
uint16_t _946 = (uint16_t)(0);
// created const: const_p0__946 with name _946
// connected _946 to the output port
}

hcompute_conv1_stencil_1() {
uint16_t _954 = _hw_kernel_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
// _hw_kernel_global_wrapper_stencil_1 added as input _hw_kernel_global_wrapper_stencil_1
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// mula: self.in // mulb: self.in o: _954 with obitwidth:16
uint16_t _955 = _hw_kernel_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
// _hw_kernel_global_wrapper_stencil_2 added as input _hw_kernel_global_wrapper_stencil_2
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// mula: self.in // mulb: self.in o: _955 with obitwidth:16
uint16_t _956 = _hw_kernel_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
// _hw_kernel_global_wrapper_stencil_3 added as input _hw_kernel_global_wrapper_stencil_3
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// mula: self.in // mulb: self.in o: _956 with obitwidth:16
uint16_t _957 = _955 + _956;
// adda: _955 // addb: _956 o: _957 with obitwidth:16
uint16_t _958 = _conv1_stencil_1 + _957;
// _conv1_stencil_1 added as input _conv1_stencil_1
// adda: self.in // addb: _957 o: _958 with obitwidth:16
uint16_t _959 = _954 + _958;
// adda: _954 // addb: _958 o: _959 with obitwidth:16
// connected _959 to the output port
}

hcompute_conv1_stencil_2() {
uint16_t _981 = _hw_kernel_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
// _hw_kernel_global_wrapper_stencil_4 added as input _hw_kernel_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// mula: self.in // mulb: self.in o: _981 with obitwidth:16
uint16_t _982 = _hw_kernel_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
// _hw_kernel_global_wrapper_stencil_5 added as input _hw_kernel_global_wrapper_stencil_5
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// mula: self.in // mulb: self.in o: _982 with obitwidth:16
uint16_t _983 = _hw_kernel_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
// _hw_kernel_global_wrapper_stencil_6 added as input _hw_kernel_global_wrapper_stencil_6
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// mula: self.in // mulb: self.in o: _983 with obitwidth:16
uint16_t _984 = _982 + _983;
// adda: _982 // addb: _983 o: _984 with obitwidth:16
uint16_t _985 = _conv1_stencil_2 + _984;
// _conv1_stencil_2 added as input _conv1_stencil_2
// adda: self.in // addb: _984 o: _985 with obitwidth:16
uint16_t _986 = _981 + _985;
// adda: _981 // addb: _985 o: _986 with obitwidth:16
// connected _986 to the output port
}

hcompute_conv1_stencil_3() {
uint16_t _1008 = _hw_kernel_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
// _hw_kernel_global_wrapper_stencil_7 added as input _hw_kernel_global_wrapper_stencil_7
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// mula: self.in // mulb: self.in o: _1008 with obitwidth:16
uint16_t _1009 = _hw_kernel_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
// _hw_kernel_global_wrapper_stencil_8 added as input _hw_kernel_global_wrapper_stencil_8
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// mula: self.in // mulb: self.in o: _1009 with obitwidth:16
uint16_t _1010 = _hw_kernel_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
// _hw_kernel_global_wrapper_stencil_9 added as input _hw_kernel_global_wrapper_stencil_9
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// mula: self.in // mulb: self.in o: _1010 with obitwidth:16
uint16_t _1011 = _1009 + _1010;
// adda: _1009 // addb: _1010 o: _1011 with obitwidth:16
uint16_t _1012 = _conv1_stencil_3 + _1011;
// _conv1_stencil_3 added as input _conv1_stencil_3
// adda: self.in // addb: _1011 o: _1012 with obitwidth:16
uint16_t _1013 = _1008 + _1012;
// adda: _1008 // addb: _1012 o: _1013 with obitwidth:16
// connected _1013 to the output port
}

hcompute_conv2_stencil() {
uint16_t _1030 = (uint16_t)(0);
// created const: const_p0__1030 with name _1030
// connected _1030 to the output port
}

hcompute_conv2_stencil_1() {
uint16_t _1038 = _hw_kernel2_global_wrapper_stencil_1 * _conv1_stencil_4;
// _hw_kernel2_global_wrapper_stencil_1 added as input _hw_kernel2_global_wrapper_stencil_1
// _conv1_stencil_4 added as input _conv1_stencil_4
// mula: self.in // mulb: self.in o: _1038 with obitwidth:16
uint16_t _1039 = _hw_kernel2_global_wrapper_stencil_2 * _conv1_stencil_5;
// _hw_kernel2_global_wrapper_stencil_2 added as input _hw_kernel2_global_wrapper_stencil_2
// _conv1_stencil_5 added as input _conv1_stencil_5
// mula: self.in // mulb: self.in o: _1039 with obitwidth:16
uint16_t _1040 = _hw_kernel2_global_wrapper_stencil_3 * _conv1_stencil_6;
// _hw_kernel2_global_wrapper_stencil_3 added as input _hw_kernel2_global_wrapper_stencil_3
// _conv1_stencil_6 added as input _conv1_stencil_6
// mula: self.in // mulb: self.in o: _1040 with obitwidth:16
uint16_t _1041 = _1039 + _1040;
// adda: _1039 // addb: _1040 o: _1041 with obitwidth:16
uint16_t _1042 = _conv2_stencil_1 + _1041;
// _conv2_stencil_1 added as input _conv2_stencil_1
// adda: self.in // addb: _1041 o: _1042 with obitwidth:16
uint16_t _1043 = _1038 + _1042;
// adda: _1038 // addb: _1042 o: _1043 with obitwidth:16
// connected _1043 to the output port
}

hcompute_conv2_stencil_2() {
uint16_t _1065 = _hw_kernel2_global_wrapper_stencil_4 * _conv1_stencil_7;
// _hw_kernel2_global_wrapper_stencil_4 added as input _hw_kernel2_global_wrapper_stencil_4
// _conv1_stencil_7 added as input _conv1_stencil_7
// mula: self.in // mulb: self.in o: _1065 with obitwidth:16
uint16_t _1066 = _hw_kernel2_global_wrapper_stencil_5 * _conv1_stencil_8;
// _hw_kernel2_global_wrapper_stencil_5 added as input _hw_kernel2_global_wrapper_stencil_5
// _conv1_stencil_8 added as input _conv1_stencil_8
// mula: self.in // mulb: self.in o: _1066 with obitwidth:16
uint16_t _1067 = _hw_kernel2_global_wrapper_stencil_6 * _conv1_stencil_9;
// _hw_kernel2_global_wrapper_stencil_6 added as input _hw_kernel2_global_wrapper_stencil_6
// _conv1_stencil_9 added as input _conv1_stencil_9
// mula: self.in // mulb: self.in o: _1067 with obitwidth:16
uint16_t _1068 = _1066 + _1067;
// adda: _1066 // addb: _1067 o: _1068 with obitwidth:16
uint16_t _1069 = _conv2_stencil_2 + _1068;
// _conv2_stencil_2 added as input _conv2_stencil_2
// adda: self.in // addb: _1068 o: _1069 with obitwidth:16
uint16_t _1070 = _1065 + _1069;
// adda: _1065 // addb: _1069 o: _1070 with obitwidth:16
// connected _1070 to the output port
}

hcompute_conv2_stencil_3() {
uint16_t _1092 = _hw_kernel2_global_wrapper_stencil_7 * _conv1_stencil_10;
// _hw_kernel2_global_wrapper_stencil_7 added as input _hw_kernel2_global_wrapper_stencil_7
// _conv1_stencil_10 added as input _conv1_stencil_10
// mula: self.in // mulb: self.in o: _1092 with obitwidth:16
uint16_t _1093 = _hw_kernel2_global_wrapper_stencil_8 * _conv1_stencil_11;
// _hw_kernel2_global_wrapper_stencil_8 added as input _hw_kernel2_global_wrapper_stencil_8
// _conv1_stencil_11 added as input _conv1_stencil_11
// mula: self.in // mulb: self.in o: _1093 with obitwidth:16
uint16_t _1094 = _hw_kernel2_global_wrapper_stencil_9 * _conv1_stencil_12;
// _hw_kernel2_global_wrapper_stencil_9 added as input _hw_kernel2_global_wrapper_stencil_9
// _conv1_stencil_12 added as input _conv1_stencil_12
// mula: self.in // mulb: self.in o: _1094 with obitwidth:16
uint16_t _1095 = _1093 + _1094;
// adda: _1093 // addb: _1094 o: _1095 with obitwidth:16
uint16_t _1096 = _conv2_stencil_3 + _1095;
// _conv2_stencil_3 added as input _conv2_stencil_3
// adda: self.in // addb: _1095 o: _1096 with obitwidth:16
uint16_t _1097 = _1092 + _1096;
// adda: _1092 // addb: _1096 o: _1097 with obitwidth:16
// connected _1097 to the output port
}

hcompute_hw_output_stencil() {
// _conv2_stencil_4 added as input _conv2_stencil_4
// connected _conv2_stencil_4 to the output port
}

