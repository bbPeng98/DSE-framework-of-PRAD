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
 Stencil<int16_t, 4, 3, 3> &hw_filter_dw_stencil = arg_0;
 Stencil<int16_t, 3, 4> &hw_filter_pw_stencil = arg_1;
 Stencil<int16_t, 4, 30, 30> &hw_input_stencil = arg_2;
 Stencil<int16_t, 3, 28, 28> &hw_output_stencil = arg_3;
[, ], [, ], [, ] // produce hw_filter_dw_global_wrapper.stencil
 for (int hw_filter_dw_global_wrapper_s0_y = 0; hw_filter_dw_global_wrapper_s0_y < 3; hw_filter_dw_global_wrapper_s0_y++)
 {
  for (int hw_filter_dw_global_wrapper_s0_x = 0; hw_filter_dw_global_wrapper_s0_x < 3; hw_filter_dw_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _730 = _hw_filter_dw_stencil(0, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y);
   _hw_filter_dw_global_wrapper_stencil(0, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y) = _730;
   int16_t _731 = _hw_filter_dw_stencil(1, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y);
   _hw_filter_dw_global_wrapper_stencil(1, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y) = _731;
   int16_t _732 = _hw_filter_dw_stencil(2, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y);
   _hw_filter_dw_global_wrapper_stencil(2, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y) = _732;
   int16_t _733 = _hw_filter_dw_stencil(3, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y);
   _hw_filter_dw_global_wrapper_stencil(3, _hw_filter_dw_global_wrapper_s0_x, _hw_filter_dw_global_wrapper_s0_y) = _733;
  } // for hw_filter_dw_global_wrapper_s0_x
 } // for hw_filter_dw_global_wrapper_s0_y
 // consume hw_filter_dw_global_wrapper.stencil
[, ], [, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 30; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 30; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _734 = _hw_input_stencil(0, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(0, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _734;
   int16_t _735 = _hw_input_stencil(1, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(1, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _735;
   int16_t _736 = _hw_input_stencil(2, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(2, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _736;
   int16_t _737 = _hw_input_stencil(3, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(3, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _737;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ], [, ] // produce dw_conv.stencil
 for (int dw_conv_s0_y = 0; dw_conv_s0_y < 28; dw_conv_s0_y++)
 {
  for (int dw_conv_s0_x = 0; dw_conv_s0_x < 28; dw_conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _740 = (int16_t)(0);
   _dw_conv_stencil(0, _dw_conv_s0_x, _dw_conv_s0_y) = _740;
   int16_t _743 = (int16_t)(0);
   _dw_conv_stencil(1, _dw_conv_s0_x, _dw_conv_s0_y) = _743;
   int16_t _746 = (int16_t)(0);
   _dw_conv_stencil(2, _dw_conv_s0_x, _dw_conv_s0_y) = _746;
   int16_t _749 = (int16_t)(0);
   _dw_conv_stencil(3, _dw_conv_s0_x, _dw_conv_s0_y) = _749;
  } // for dw_conv_s0_x
 } // for dw_conv_s0_y
 for (int dw_conv_s1_y = 0; dw_conv_s1_y < 28; dw_conv_s1_y++)
 {
  for (int dw_conv_s1_x = 0; dw_conv_s1_x < 28; dw_conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _786 = _hw_filter_dw_global_wrapper_stencil(0, 0, 0);
   int16_t _787 = _hw_input_global_wrapper_stencil(0, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _788 = _786 * _787;
   int16_t _789 = _dw_conv_stencil(0, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _790 = _hw_filter_dw_global_wrapper_stencil(0, 1, 0);
   int32_t _791 = _dw_conv_s1_x + 1;
   int16_t _792 = _hw_input_global_wrapper_stencil(0, _791, _dw_conv_s1_y);
   int16_t _793 = _790 * _792;
   int16_t _794 = _hw_filter_dw_global_wrapper_stencil(0, 2, 0);
   int32_t _795 = _dw_conv_s1_x + 2;
   int16_t _796 = _hw_input_global_wrapper_stencil(0, _795, _dw_conv_s1_y);
   int16_t _797 = _794 * _796;
   int16_t _798 = _hw_filter_dw_global_wrapper_stencil(0, 0, 1);
   int32_t _799 = _dw_conv_s1_y + 1;
   int16_t _800 = _hw_input_global_wrapper_stencil(0, _dw_conv_s1_x, _799);
   int16_t _801 = _798 * _800;
   int16_t _802 = _hw_filter_dw_global_wrapper_stencil(0, 1, 1);
   int16_t _803 = _hw_input_global_wrapper_stencil(0, _791, _799);
   int16_t _804 = _802 * _803;
   int16_t _805 = _hw_filter_dw_global_wrapper_stencil(0, 2, 1);
   int16_t _806 = _hw_input_global_wrapper_stencil(0, _795, _799);
   int16_t _807 = _805 * _806;
   int16_t _808 = _hw_filter_dw_global_wrapper_stencil(0, 0, 2);
   int32_t _809 = _dw_conv_s1_y + 2;
   int16_t _810 = _hw_input_global_wrapper_stencil(0, _dw_conv_s1_x, _809);
   int16_t _811 = _808 * _810;
   int16_t _812 = _hw_filter_dw_global_wrapper_stencil(0, 2, 2);
   int16_t _813 = _hw_input_global_wrapper_stencil(0, _795, _809);
   int16_t _814 = _812 * _813;
   int16_t _815 = _hw_filter_dw_global_wrapper_stencil(0, 1, 2);
   int16_t _816 = _hw_input_global_wrapper_stencil(0, _791, _809);
   int16_t _817 = _815 * _816;
   int16_t _818 = _814 + _817;
   int16_t _819 = _811 + _818;
   int16_t _820 = _807 + _819;
   int16_t _821 = _804 + _820;
   int16_t _822 = _801 + _821;
   int16_t _823 = _797 + _822;
   int16_t _824 = _793 + _823;
   int16_t _825 = _789 + _824;
   int16_t _826 = _788 + _825;
   _dw_conv_stencil(0, _dw_conv_s1_x, _dw_conv_s1_y) = _826;
   int16_t _863 = _hw_filter_dw_global_wrapper_stencil(1, 0, 0);
   int16_t _864 = _hw_input_global_wrapper_stencil(1, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _865 = _863 * _864;
   int16_t _866 = _dw_conv_stencil(1, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _867 = _hw_filter_dw_global_wrapper_stencil(1, 1, 0);
   int32_t _868 = _dw_conv_s1_x + 1;
   int16_t _869 = _hw_input_global_wrapper_stencil(1, _868, _dw_conv_s1_y);
   int16_t _870 = _867 * _869;
   int16_t _871 = _hw_filter_dw_global_wrapper_stencil(1, 2, 0);
   int32_t _872 = _dw_conv_s1_x + 2;
   int16_t _873 = _hw_input_global_wrapper_stencil(1, _872, _dw_conv_s1_y);
   int16_t _874 = _871 * _873;
   int16_t _875 = _hw_filter_dw_global_wrapper_stencil(1, 0, 1);
   int32_t _876 = _dw_conv_s1_y + 1;
   int16_t _877 = _hw_input_global_wrapper_stencil(1, _dw_conv_s1_x, _876);
   int16_t _878 = _875 * _877;
   int16_t _879 = _hw_filter_dw_global_wrapper_stencil(1, 1, 1);
   int16_t _880 = _hw_input_global_wrapper_stencil(1, _868, _876);
   int16_t _881 = _879 * _880;
   int16_t _882 = _hw_filter_dw_global_wrapper_stencil(1, 2, 1);
   int16_t _883 = _hw_input_global_wrapper_stencil(1, _872, _876);
   int16_t _884 = _882 * _883;
   int16_t _885 = _hw_filter_dw_global_wrapper_stencil(1, 0, 2);
   int32_t _886 = _dw_conv_s1_y + 2;
   int16_t _887 = _hw_input_global_wrapper_stencil(1, _dw_conv_s1_x, _886);
   int16_t _888 = _885 * _887;
   int16_t _889 = _hw_filter_dw_global_wrapper_stencil(1, 2, 2);
   int16_t _890 = _hw_input_global_wrapper_stencil(1, _872, _886);
   int16_t _891 = _889 * _890;
   int16_t _892 = _hw_filter_dw_global_wrapper_stencil(1, 1, 2);
   int16_t _893 = _hw_input_global_wrapper_stencil(1, _868, _886);
   int16_t _894 = _892 * _893;
   int16_t _895 = _891 + _894;
   int16_t _896 = _888 + _895;
   int16_t _897 = _884 + _896;
   int16_t _898 = _881 + _897;
   int16_t _899 = _878 + _898;
   int16_t _900 = _874 + _899;
   int16_t _901 = _870 + _900;
   int16_t _902 = _866 + _901;
   int16_t _903 = _865 + _902;
   _dw_conv_stencil(1, _dw_conv_s1_x, _dw_conv_s1_y) = _903;
   int16_t _940 = _hw_filter_dw_global_wrapper_stencil(2, 0, 0);
   int16_t _941 = _hw_input_global_wrapper_stencil(2, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _942 = _940 * _941;
   int16_t _943 = _dw_conv_stencil(2, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _944 = _hw_filter_dw_global_wrapper_stencil(2, 1, 0);
   int32_t _945 = _dw_conv_s1_x + 1;
   int16_t _946 = _hw_input_global_wrapper_stencil(2, _945, _dw_conv_s1_y);
   int16_t _947 = _944 * _946;
   int16_t _948 = _hw_filter_dw_global_wrapper_stencil(2, 2, 0);
   int32_t _949 = _dw_conv_s1_x + 2;
   int16_t _950 = _hw_input_global_wrapper_stencil(2, _949, _dw_conv_s1_y);
   int16_t _951 = _948 * _950;
   int16_t _952 = _hw_filter_dw_global_wrapper_stencil(2, 0, 1);
   int32_t _953 = _dw_conv_s1_y + 1;
   int16_t _954 = _hw_input_global_wrapper_stencil(2, _dw_conv_s1_x, _953);
   int16_t _955 = _952 * _954;
   int16_t _956 = _hw_filter_dw_global_wrapper_stencil(2, 1, 1);
   int16_t _957 = _hw_input_global_wrapper_stencil(2, _945, _953);
   int16_t _958 = _956 * _957;
   int16_t _959 = _hw_filter_dw_global_wrapper_stencil(2, 2, 1);
   int16_t _960 = _hw_input_global_wrapper_stencil(2, _949, _953);
   int16_t _961 = _959 * _960;
   int16_t _962 = _hw_filter_dw_global_wrapper_stencil(2, 0, 2);
   int32_t _963 = _dw_conv_s1_y + 2;
   int16_t _964 = _hw_input_global_wrapper_stencil(2, _dw_conv_s1_x, _963);
   int16_t _965 = _962 * _964;
   int16_t _966 = _hw_filter_dw_global_wrapper_stencil(2, 2, 2);
   int16_t _967 = _hw_input_global_wrapper_stencil(2, _949, _963);
   int16_t _968 = _966 * _967;
   int16_t _969 = _hw_filter_dw_global_wrapper_stencil(2, 1, 2);
   int16_t _970 = _hw_input_global_wrapper_stencil(2, _945, _963);
   int16_t _971 = _969 * _970;
   int16_t _972 = _968 + _971;
   int16_t _973 = _965 + _972;
   int16_t _974 = _961 + _973;
   int16_t _975 = _958 + _974;
   int16_t _976 = _955 + _975;
   int16_t _977 = _951 + _976;
   int16_t _978 = _947 + _977;
   int16_t _979 = _943 + _978;
   int16_t _980 = _942 + _979;
   _dw_conv_stencil(2, _dw_conv_s1_x, _dw_conv_s1_y) = _980;
   int16_t _1017 = _hw_filter_dw_global_wrapper_stencil(3, 0, 0);
   int16_t _1018 = _hw_input_global_wrapper_stencil(3, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _1019 = _1017 * _1018;
   int16_t _1020 = _dw_conv_stencil(3, _dw_conv_s1_x, _dw_conv_s1_y);
   int16_t _1021 = _hw_filter_dw_global_wrapper_stencil(3, 1, 0);
   int32_t _1022 = _dw_conv_s1_x + 1;
   int16_t _1023 = _hw_input_global_wrapper_stencil(3, _1022, _dw_conv_s1_y);
   int16_t _1024 = _1021 * _1023;
   int16_t _1025 = _hw_filter_dw_global_wrapper_stencil(3, 2, 0);
   int32_t _1026 = _dw_conv_s1_x + 2;
   int16_t _1027 = _hw_input_global_wrapper_stencil(3, _1026, _dw_conv_s1_y);
   int16_t _1028 = _1025 * _1027;
   int16_t _1029 = _hw_filter_dw_global_wrapper_stencil(3, 0, 1);
   int32_t _1030 = _dw_conv_s1_y + 1;
   int16_t _1031 = _hw_input_global_wrapper_stencil(3, _dw_conv_s1_x, _1030);
   int16_t _1032 = _1029 * _1031;
   int16_t _1033 = _hw_filter_dw_global_wrapper_stencil(3, 1, 1);
   int16_t _1034 = _hw_input_global_wrapper_stencil(3, _1022, _1030);
   int16_t _1035 = _1033 * _1034;
   int16_t _1036 = _hw_filter_dw_global_wrapper_stencil(3, 2, 1);
   int16_t _1037 = _hw_input_global_wrapper_stencil(3, _1026, _1030);
   int16_t _1038 = _1036 * _1037;
   int16_t _1039 = _hw_filter_dw_global_wrapper_stencil(3, 0, 2);
   int32_t _1040 = _dw_conv_s1_y + 2;
   int16_t _1041 = _hw_input_global_wrapper_stencil(3, _dw_conv_s1_x, _1040);
   int16_t _1042 = _1039 * _1041;
   int16_t _1043 = _hw_filter_dw_global_wrapper_stencil(3, 2, 2);
   int16_t _1044 = _hw_input_global_wrapper_stencil(3, _1026, _1040);
   int16_t _1045 = _1043 * _1044;
   int16_t _1046 = _hw_filter_dw_global_wrapper_stencil(3, 1, 2);
   int16_t _1047 = _hw_input_global_wrapper_stencil(3, _1022, _1040);
   int16_t _1048 = _1046 * _1047;
   int16_t _1049 = _1045 + _1048;
   int16_t _1050 = _1042 + _1049;
   int16_t _1051 = _1038 + _1050;
   int16_t _1052 = _1035 + _1051;
   int16_t _1053 = _1032 + _1052;
   int16_t _1054 = _1028 + _1053;
   int16_t _1055 = _1024 + _1054;
   int16_t _1056 = _1020 + _1055;
   int16_t _1057 = _1019 + _1056;
   _dw_conv_stencil(3, _dw_conv_s1_x, _dw_conv_s1_y) = _1057;
  } // for dw_conv_s1_x
 } // for dw_conv_s1_y
 // consume dw_conv.stencil
[, ], [, ] // produce hw_filter_pw_global_wrapper.stencil
 for (int hw_filter_pw_global_wrapper_s0_c = 0; hw_filter_pw_global_wrapper_s0_c < 4; hw_filter_pw_global_wrapper_s0_c++)
 {
  for (int hw_filter_pw_global_wrapper_s0_k = 0; hw_filter_pw_global_wrapper_s0_k < 3; hw_filter_pw_global_wrapper_s0_k++)
  {
#pragma HLS PIPELINE II=1
   int16_t _1058 = _hw_filter_pw_stencil(_hw_filter_pw_global_wrapper_s0_k, _hw_filter_pw_global_wrapper_s0_c);
   _hw_filter_pw_global_wrapper_stencil(_hw_filter_pw_global_wrapper_s0_k, _hw_filter_pw_global_wrapper_s0_c) = _1058;
  } // for hw_filter_pw_global_wrapper_s0_k
 } // for hw_filter_pw_global_wrapper_s0_c
 // consume hw_filter_pw_global_wrapper.stencil
[, ], [, ], [, ] // produce pw_conv_reduction.stencil
 for (int pw_conv_reduction_s0_y = 0; pw_conv_reduction_s0_y < 28; pw_conv_reduction_s0_y++)
 {
  for (int pw_conv_reduction_s0_x = 0; pw_conv_reduction_s0_x < 28; pw_conv_reduction_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _1061 = (int16_t)(0);
   _pw_conv_reduction_stencil(0, _pw_conv_reduction_s0_x, _pw_conv_reduction_s0_y) = _1061;
   int16_t _1064 = (int16_t)(0);
   _pw_conv_reduction_stencil(1, _pw_conv_reduction_s0_x, _pw_conv_reduction_s0_y) = _1064;
   int16_t _1067 = (int16_t)(0);
   _pw_conv_reduction_stencil(2, _pw_conv_reduction_s0_x, _pw_conv_reduction_s0_y) = _1067;
  } // for pw_conv_reduction_s0_x
 } // for pw_conv_reduction_s0_y
 for (int pw_conv_reduction_s1_y = 0; pw_conv_reduction_s1_y < 28; pw_conv_reduction_s1_y++)
 {
  for (int pw_conv_reduction_s1_x = 0; pw_conv_reduction_s1_x < 28; pw_conv_reduction_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _1084 = _hw_filter_pw_global_wrapper_stencil(0, 0);
   int16_t _1085 = _dw_conv_stencil(0, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1086 = _1084 * _1085;
   int16_t _1087 = _pw_conv_reduction_stencil(0, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1088 = _hw_filter_pw_global_wrapper_stencil(0, 1);
   int16_t _1089 = _dw_conv_stencil(1, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1090 = _1088 * _1089;
   int16_t _1091 = _hw_filter_pw_global_wrapper_stencil(0, 3);
   int16_t _1092 = _dw_conv_stencil(3, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1093 = _1091 * _1092;
   int16_t _1094 = _hw_filter_pw_global_wrapper_stencil(0, 2);
   int16_t _1095 = _dw_conv_stencil(2, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1096 = _1094 * _1095;
   int16_t _1097 = _1093 + _1096;
   int16_t _1098 = _1090 + _1097;
   int16_t _1099 = _1087 + _1098;
   int16_t _1100 = _1086 + _1099;
   _pw_conv_reduction_stencil(0, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y) = _1100;
   int16_t _1117 = _hw_filter_pw_global_wrapper_stencil(1, 0);
   int16_t _1118 = _dw_conv_stencil(0, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1119 = _1117 * _1118;
   int16_t _1120 = _pw_conv_reduction_stencil(1, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1121 = _hw_filter_pw_global_wrapper_stencil(1, 1);
   int16_t _1122 = _dw_conv_stencil(1, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1123 = _1121 * _1122;
   int16_t _1124 = _hw_filter_pw_global_wrapper_stencil(1, 3);
   int16_t _1125 = _dw_conv_stencil(3, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1126 = _1124 * _1125;
   int16_t _1127 = _hw_filter_pw_global_wrapper_stencil(1, 2);
   int16_t _1128 = _dw_conv_stencil(2, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1129 = _1127 * _1128;
   int16_t _1130 = _1126 + _1129;
   int16_t _1131 = _1123 + _1130;
   int16_t _1132 = _1120 + _1131;
   int16_t _1133 = _1119 + _1132;
   _pw_conv_reduction_stencil(1, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y) = _1133;
   int16_t _1150 = _hw_filter_pw_global_wrapper_stencil(2, 0);
   int16_t _1151 = _dw_conv_stencil(0, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1152 = _1150 * _1151;
   int16_t _1153 = _pw_conv_reduction_stencil(2, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1154 = _hw_filter_pw_global_wrapper_stencil(2, 1);
   int16_t _1155 = _dw_conv_stencil(1, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1156 = _1154 * _1155;
   int16_t _1157 = _hw_filter_pw_global_wrapper_stencil(2, 3);
   int16_t _1158 = _dw_conv_stencil(3, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1159 = _1157 * _1158;
   int16_t _1160 = _hw_filter_pw_global_wrapper_stencil(2, 2);
   int16_t _1161 = _dw_conv_stencil(2, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y);
   int16_t _1162 = _1160 * _1161;
   int16_t _1163 = _1159 + _1162;
   int16_t _1164 = _1156 + _1163;
   int16_t _1165 = _1153 + _1164;
   int16_t _1166 = _1152 + _1165;
   _pw_conv_reduction_stencil(2, _pw_conv_reduction_s1_x, _pw_conv_reduction_s1_y) = _1166;
  } // for pw_conv_reduction_s1_x
 } // for pw_conv_reduction_s1_y
 // consume pw_conv_reduction.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   int16_t _1167 = _pw_conv_reduction_stencil(0, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(0, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1167;
   int16_t _1168 = _pw_conv_reduction_stencil(1, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(1, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1168;
   int16_t _1169 = _pw_conv_reduction_stencil(2, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(2, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1169;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetmobilenet

