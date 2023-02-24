)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_0.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_2 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_2.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_3 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_3.value complete dim=0

 // alias the arguments
 Stencil<uint16_t, 3, 32, 32> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 3, 3, 3, 3> &hw_kernel_stencil = arg_1;
 Stencil<uint16_t, 3, 3, 3, 3> &hw_kernel2_stencil = arg_2;
 Stencil<uint16_t, 28, 28, 3> &hw_output_stencil = arg_3;
[, ], [, ], [, ], [, ] // produce hw_kernel2_global_wrapper.stencil
 for (int hw_kernel2_global_wrapper_s0_y = 0; hw_kernel2_global_wrapper_s0_y < 3; hw_kernel2_global_wrapper_s0_y++)
 {
  for (int hw_kernel2_global_wrapper_s0_x = 0; hw_kernel2_global_wrapper_s0_x < 3; hw_kernel2_global_wrapper_s0_x++)
  {
   for (int hw_kernel2_global_wrapper_s0_w = 0; hw_kernel2_global_wrapper_s0_w < 3; hw_kernel2_global_wrapper_s0_w++)
   {
    for (int hw_kernel2_global_wrapper_s0_z = 0; hw_kernel2_global_wrapper_s0_z < 3; hw_kernel2_global_wrapper_s0_z++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _942 = _hw_kernel2_stencil(_hw_kernel2_global_wrapper_s0_z, _hw_kernel2_global_wrapper_s0_w, _hw_kernel2_global_wrapper_s0_x, _hw_kernel2_global_wrapper_s0_y);
     _hw_kernel2_global_wrapper_stencil(_hw_kernel2_global_wrapper_s0_z, _hw_kernel2_global_wrapper_s0_w, _hw_kernel2_global_wrapper_s0_x, _hw_kernel2_global_wrapper_s0_y) = _942;
    } // for hw_kernel2_global_wrapper_s0_z
   } // for hw_kernel2_global_wrapper_s0_w
  } // for hw_kernel2_global_wrapper_s0_x
 } // for hw_kernel2_global_wrapper_s0_y
 // consume hw_kernel2_global_wrapper.stencil
[, ], [, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 32; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 32; hw_input_global_wrapper_s0_x++)
  {
   for (int hw_input_global_wrapper_s0_z = 0; hw_input_global_wrapper_s0_z < 3; hw_input_global_wrapper_s0_z++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _943 = _hw_input_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
    _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _943;
   } // for hw_input_global_wrapper_s0_z
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ], [, ], [, ] // produce hw_kernel_global_wrapper.stencil
 for (int hw_kernel_global_wrapper_s0_y = 0; hw_kernel_global_wrapper_s0_y < 3; hw_kernel_global_wrapper_s0_y++)
 {
  for (int hw_kernel_global_wrapper_s0_x = 0; hw_kernel_global_wrapper_s0_x < 3; hw_kernel_global_wrapper_s0_x++)
  {
   for (int hw_kernel_global_wrapper_s0_w = 0; hw_kernel_global_wrapper_s0_w < 3; hw_kernel_global_wrapper_s0_w++)
   {
    for (int hw_kernel_global_wrapper_s0_z = 0; hw_kernel_global_wrapper_s0_z < 3; hw_kernel_global_wrapper_s0_z++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _944 = _hw_kernel_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y);
     _hw_kernel_global_wrapper_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y) = _944;
    } // for hw_kernel_global_wrapper_s0_z
   } // for hw_kernel_global_wrapper_s0_w
  } // for hw_kernel_global_wrapper_s0_x
 } // for hw_kernel_global_wrapper_s0_y
 // consume hw_kernel_global_wrapper.stencil
[, ], [, ], [, ] // produce conv1.stencil
 for (int conv1_s0_y = 0; conv1_s0_y < 30; conv1_s0_y++)
 {
  for (int conv1_s0_x = 0; conv1_s0_x < 30; conv1_s0_x++)
  {
   for (int conv1_s0_w = 0; conv1_s0_w < 3; conv1_s0_w++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _947 = (uint16_t)(0);
    _conv1_stencil(_conv1_s0_x, _conv1_s0_y, _conv1_s0_w) = _947;
   } // for conv1_s0_w
  } // for conv1_s0_x
 } // for conv1_s0_y
 for (int conv1_s1_r_y = 0; conv1_s1_r_y < 3; conv1_s1_r_y++)
 {
  for (int conv1_s1_r_x = 0; conv1_s1_r_x < 3; conv1_s1_r_x++)
  {
   for (int conv1_s1_y = 0; conv1_s1_y < 30; conv1_s1_y++)
   {
    for (int conv1_s1_x = 0; conv1_s1_x < 30; conv1_s1_x++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _960 = _hw_kernel_global_wrapper_stencil(0, 0, _conv1_s1_r_x, _conv1_s1_r_y);
     int32_t _961 = _conv1_s1_r_x + _conv1_s1_x;
     int32_t _962 = _conv1_s1_r_y + _conv1_s1_y;
     uint16_t _963 = _hw_input_global_wrapper_stencil(0, _961, _962);
     uint16_t _964 = _960 * _963;
     uint16_t _965 = _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 0);
     uint16_t _966 = _hw_kernel_global_wrapper_stencil(2, 0, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _967 = _hw_input_global_wrapper_stencil(2, _961, _962);
     uint16_t _968 = _966 * _967;
     uint16_t _969 = _hw_kernel_global_wrapper_stencil(1, 0, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _970 = _hw_input_global_wrapper_stencil(1, _961, _962);
     uint16_t _971 = _969 * _970;
     uint16_t _972 = _968 + _971;
     uint16_t _973 = _965 + _972;
     uint16_t _974 = _964 + _973;
     _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 0) = _974;
     uint16_t _987 = _hw_kernel_global_wrapper_stencil(0, 1, _conv1_s1_r_x, _conv1_s1_r_y);
     int32_t _988 = _conv1_s1_r_x + _conv1_s1_x;
     int32_t _989 = _conv1_s1_r_y + _conv1_s1_y;
     uint16_t _990 = _hw_input_global_wrapper_stencil(0, _988, _989);
     uint16_t _991 = _987 * _990;
     uint16_t _992 = _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 1);
     uint16_t _993 = _hw_kernel_global_wrapper_stencil(2, 1, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _994 = _hw_input_global_wrapper_stencil(2, _988, _989);
     uint16_t _995 = _993 * _994;
     uint16_t _996 = _hw_kernel_global_wrapper_stencil(1, 1, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _997 = _hw_input_global_wrapper_stencil(1, _988, _989);
     uint16_t _998 = _996 * _997;
     uint16_t _999 = _995 + _998;
     uint16_t _1000 = _992 + _999;
     uint16_t _1001 = _991 + _1000;
     _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 1) = _1001;
     uint16_t _1014 = _hw_kernel_global_wrapper_stencil(0, 2, _conv1_s1_r_x, _conv1_s1_r_y);
     int32_t _1015 = _conv1_s1_r_x + _conv1_s1_x;
     int32_t _1016 = _conv1_s1_r_y + _conv1_s1_y;
     uint16_t _1017 = _hw_input_global_wrapper_stencil(0, _1015, _1016);
     uint16_t _1018 = _1014 * _1017;
     uint16_t _1019 = _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 2);
     uint16_t _1020 = _hw_kernel_global_wrapper_stencil(2, 2, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _1021 = _hw_input_global_wrapper_stencil(2, _1015, _1016);
     uint16_t _1022 = _1020 * _1021;
     uint16_t _1023 = _hw_kernel_global_wrapper_stencil(1, 2, _conv1_s1_r_x, _conv1_s1_r_y);
     uint16_t _1024 = _hw_input_global_wrapper_stencil(1, _1015, _1016);
     uint16_t _1025 = _1023 * _1024;
     uint16_t _1026 = _1022 + _1025;
     uint16_t _1027 = _1019 + _1026;
     uint16_t _1028 = _1018 + _1027;
     _conv1_stencil(_conv1_s1_x, _conv1_s1_y, 2) = _1028;
    } // for conv1_s1_x
   } // for conv1_s1_y
  } // for conv1_s1_r_x
 } // for conv1_s1_r_y
 // consume conv1.stencil
[, ], [, ], [, ] // produce conv2.stencil
 for (int conv2_s0_y = 0; conv2_s0_y < 28; conv2_s0_y++)
 {
  for (int conv2_s0_x = 0; conv2_s0_x < 28; conv2_s0_x++)
  {
   for (int conv2_s0_w = 0; conv2_s0_w < 3; conv2_s0_w++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _1031 = (uint16_t)(0);
    _conv2_stencil(_conv2_s0_x, _conv2_s0_y, _conv2_s0_w) = _1031;
   } // for conv2_s0_w
  } // for conv2_s0_x
 } // for conv2_s0_y
 for (int conv2_s1_r2_0_y = 0; conv2_s1_r2_0_y < 3; conv2_s1_r2_0_y++)
 {
  for (int conv2_s1_r2_0_x = 0; conv2_s1_r2_0_x < 3; conv2_s1_r2_0_x++)
  {
   for (int conv2_s1_y = 0; conv2_s1_y < 28; conv2_s1_y++)
   {
    for (int conv2_s1_x = 0; conv2_s1_x < 28; conv2_s1_x++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _1044 = _hw_kernel2_global_wrapper_stencil(0, 0, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     int32_t _1045 = _conv2_s1_r2_0_x + _conv2_s1_x;
     int32_t _1046 = _conv2_s1_r2_0_y + _conv2_s1_y;
     uint16_t _1047 = _conv1_stencil(_1045, _1046, 0);
     uint16_t _1048 = _1044 * _1047;
     uint16_t _1049 = _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 0);
     uint16_t _1050 = _hw_kernel2_global_wrapper_stencil(2, 0, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1051 = _conv1_stencil(_1045, _1046, 2);
     uint16_t _1052 = _1050 * _1051;
     uint16_t _1053 = _hw_kernel2_global_wrapper_stencil(1, 0, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1054 = _conv1_stencil(_1045, _1046, 1);
     uint16_t _1055 = _1053 * _1054;
     uint16_t _1056 = _1052 + _1055;
     uint16_t _1057 = _1049 + _1056;
     uint16_t _1058 = _1048 + _1057;
     _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 0) = _1058;
     uint16_t _1071 = _hw_kernel2_global_wrapper_stencil(0, 1, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     int32_t _1072 = _conv2_s1_r2_0_x + _conv2_s1_x;
     int32_t _1073 = _conv2_s1_r2_0_y + _conv2_s1_y;
     uint16_t _1074 = _conv1_stencil(_1072, _1073, 0);
     uint16_t _1075 = _1071 * _1074;
     uint16_t _1076 = _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 1);
     uint16_t _1077 = _hw_kernel2_global_wrapper_stencil(2, 1, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1078 = _conv1_stencil(_1072, _1073, 2);
     uint16_t _1079 = _1077 * _1078;
     uint16_t _1080 = _hw_kernel2_global_wrapper_stencil(1, 1, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1081 = _conv1_stencil(_1072, _1073, 1);
     uint16_t _1082 = _1080 * _1081;
     uint16_t _1083 = _1079 + _1082;
     uint16_t _1084 = _1076 + _1083;
     uint16_t _1085 = _1075 + _1084;
     _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 1) = _1085;
     uint16_t _1098 = _hw_kernel2_global_wrapper_stencil(0, 2, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     int32_t _1099 = _conv2_s1_r2_0_x + _conv2_s1_x;
     int32_t _1100 = _conv2_s1_r2_0_y + _conv2_s1_y;
     uint16_t _1101 = _conv1_stencil(_1099, _1100, 0);
     uint16_t _1102 = _1098 * _1101;
     uint16_t _1103 = _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 2);
     uint16_t _1104 = _hw_kernel2_global_wrapper_stencil(2, 2, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1105 = _conv1_stencil(_1099, _1100, 2);
     uint16_t _1106 = _1104 * _1105;
     uint16_t _1107 = _hw_kernel2_global_wrapper_stencil(1, 2, _conv2_s1_r2_0_x, _conv2_s1_r2_0_y);
     uint16_t _1108 = _conv1_stencil(_1099, _1100, 1);
     uint16_t _1109 = _1107 * _1108;
     uint16_t _1110 = _1106 + _1109;
     uint16_t _1111 = _1103 + _1110;
     uint16_t _1112 = _1102 + _1111;
     _conv2_stencil(_conv2_s1_x, _conv2_s1_y, 2) = _1112;
    } // for conv2_s1_x
   } // for conv2_s1_y
  } // for conv2_s1_r2_0_x
 } // for conv2_s1_r2_0_y
 // consume conv2.stencil
 for (int hw_output_s0_w = 0; hw_output_s0_w < 3; hw_output_s0_w++)
 {
  for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
  {
   for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _1113 = _conv2_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_w);
    _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_w) = _1113;
   } // for hw_output_s0_x_xi
  } // for hw_output_s0_y_yi
 } // for hw_output_s0_w
} // kernel hls_targetresnet_block

