#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_kernel2_global_wrapper.stencil(hw_kernel2_global_wrapper_s0_z, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_y) = hw_kernel2.stencil(hw_kernel2_global_wrapper_s0_z, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_kernel2_global_wrapper_stencil(hw_uint<16>& hw_kernel2_stencil) {
  uint16_t _hw_kernel2_stencil_1 = (uint16_t) (hw_kernel2_stencil.extract<0, 15>());

  return _hw_kernel2_stencil_1;
}

//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_kernel_global_wrapper.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y) = hw_kernel.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_kernel_global_wrapper_stencil(hw_uint<16>& hw_kernel_stencil) {
  uint16_t _hw_kernel_stencil_1 = (uint16_t) (hw_kernel_stencil.extract<0, 15>());

  return _hw_kernel_stencil_1;
}

//store is: conv1.stencil(conv1_s0_x, conv1_s0_y, conv1_s0_w) = (uint16)0
hw_uint<16> hcompute_conv1_stencil() {
  uint16_t _945 = (uint16_t)(0);
  return _945;
}

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 0) = ((hw_kernel_global_wrapper.stencil(0, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 0) + ((hw_kernel_global_wrapper.stencil(2, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
hw_uint<16> hcompute_conv1_stencil_1(hw_uint<16>& conv1_stencil, hw_uint<48>& hw_input_global_wrapper_stencil, hw_uint<48>& hw_kernel_global_wrapper_stencil) {
  uint16_t _conv1_stencil_1 = (uint16_t) (conv1_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_2 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_3 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());

  uint16_t _hw_kernel_global_wrapper_stencil_1 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel_global_wrapper_stencil_2 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel_global_wrapper_stencil_3 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());

  uint16_t _948 = _hw_kernel_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
  uint16_t _949 = _hw_kernel_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
  uint16_t _950 = _hw_kernel_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
  uint16_t _951 = _949 + _950;
  uint16_t _952 = _conv1_stencil_1 + _951;
  uint16_t _953 = _948 + _952;
  return _953;
}

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 1) = ((hw_kernel_global_wrapper.stencil(0, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 1) + ((hw_kernel_global_wrapper.stencil(2, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
hw_uint<16> hcompute_conv1_stencil_2(hw_uint<16>& conv1_stencil, hw_uint<48>& hw_input_global_wrapper_stencil, hw_uint<48>& hw_kernel_global_wrapper_stencil) {
  uint16_t _conv1_stencil_2 = (uint16_t) (conv1_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_4 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_5 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_6 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());

  uint16_t _hw_kernel_global_wrapper_stencil_4 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel_global_wrapper_stencil_5 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel_global_wrapper_stencil_6 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());

  uint16_t _975 = _hw_kernel_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
  uint16_t _976 = _hw_kernel_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
  uint16_t _977 = _hw_kernel_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
  uint16_t _978 = _976 + _977;
  uint16_t _979 = _conv1_stencil_2 + _978;
  uint16_t _980 = _975 + _979;
  return _980;
}

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 2) = ((hw_kernel_global_wrapper.stencil(0, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 2) + ((hw_kernel_global_wrapper.stencil(2, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
hw_uint<16> hcompute_conv1_stencil_3(hw_uint<16>& conv1_stencil, hw_uint<48>& hw_input_global_wrapper_stencil, hw_uint<48>& hw_kernel_global_wrapper_stencil) {
  uint16_t _conv1_stencil_3 = (uint16_t) (conv1_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_7 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_8 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_9 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());

  uint16_t _hw_kernel_global_wrapper_stencil_7 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel_global_wrapper_stencil_8 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel_global_wrapper_stencil_9 = (uint16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());

  uint16_t _1002 = _hw_kernel_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
  uint16_t _1003 = _hw_kernel_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
  uint16_t _1004 = _hw_kernel_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
  uint16_t _1005 = _1003 + _1004;
  uint16_t _1006 = _conv1_stencil_3 + _1005;
  uint16_t _1007 = _1002 + _1006;
  return _1007;
}

//store is: conv2.stencil(conv2_s0_x, conv2_s0_y, conv2_s0_w) = (uint16)0
hw_uint<16> hcompute_conv2_stencil() {
  uint16_t _1029 = (uint16_t)(0);
  return _1029;
}

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 0) = ((hw_kernel2_global_wrapper.stencil(0, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 0) + ((hw_kernel2_global_wrapper.stencil(2, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
hw_uint<16> hcompute_conv2_stencil_1(hw_uint<48>& conv1_stencil, hw_uint<16>& conv2_stencil, hw_uint<48>& hw_kernel2_global_wrapper_stencil) {
  uint16_t _conv1_stencil_4 = (uint16_t) (conv1_stencil.extract<0, 15>());
  uint16_t _conv1_stencil_5 = (uint16_t) (conv1_stencil.extract<16, 31>());
  uint16_t _conv1_stencil_6 = (uint16_t) (conv1_stencil.extract<32, 47>());

  uint16_t _conv2_stencil_1 = (uint16_t) (conv2_stencil.extract<0, 15>());

  uint16_t _hw_kernel2_global_wrapper_stencil_1 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel2_global_wrapper_stencil_2 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel2_global_wrapper_stencil_3 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<32, 47>());

  uint16_t _1032 = _hw_kernel2_global_wrapper_stencil_1 * _conv1_stencil_4;
  uint16_t _1033 = _hw_kernel2_global_wrapper_stencil_2 * _conv1_stencil_5;
  uint16_t _1034 = _hw_kernel2_global_wrapper_stencil_3 * _conv1_stencil_6;
  uint16_t _1035 = _1033 + _1034;
  uint16_t _1036 = _conv2_stencil_1 + _1035;
  uint16_t _1037 = _1032 + _1036;
  return _1037;
}

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 1) = ((hw_kernel2_global_wrapper.stencil(0, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 1) + ((hw_kernel2_global_wrapper.stencil(2, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
hw_uint<16> hcompute_conv2_stencil_2(hw_uint<48>& conv1_stencil, hw_uint<16>& conv2_stencil, hw_uint<48>& hw_kernel2_global_wrapper_stencil) {
  uint16_t _conv1_stencil_7 = (uint16_t) (conv1_stencil.extract<0, 15>());
  uint16_t _conv1_stencil_8 = (uint16_t) (conv1_stencil.extract<16, 31>());
  uint16_t _conv1_stencil_9 = (uint16_t) (conv1_stencil.extract<32, 47>());

  uint16_t _conv2_stencil_2 = (uint16_t) (conv2_stencil.extract<0, 15>());

  uint16_t _hw_kernel2_global_wrapper_stencil_4 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel2_global_wrapper_stencil_5 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel2_global_wrapper_stencil_6 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<32, 47>());

  uint16_t _1059 = _hw_kernel2_global_wrapper_stencil_4 * _conv1_stencil_7;
  uint16_t _1060 = _hw_kernel2_global_wrapper_stencil_5 * _conv1_stencil_8;
  uint16_t _1061 = _hw_kernel2_global_wrapper_stencil_6 * _conv1_stencil_9;
  uint16_t _1062 = _1060 + _1061;
  uint16_t _1063 = _conv2_stencil_2 + _1062;
  uint16_t _1064 = _1059 + _1063;
  return _1064;
}

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 2) = ((hw_kernel2_global_wrapper.stencil(0, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 2) + ((hw_kernel2_global_wrapper.stencil(2, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
hw_uint<16> hcompute_conv2_stencil_3(hw_uint<48>& conv1_stencil, hw_uint<16>& conv2_stencil, hw_uint<48>& hw_kernel2_global_wrapper_stencil) {
  uint16_t _conv1_stencil_10 = (uint16_t) (conv1_stencil.extract<0, 15>());
  uint16_t _conv1_stencil_11 = (uint16_t) (conv1_stencil.extract<16, 31>());
  uint16_t _conv1_stencil_12 = (uint16_t) (conv1_stencil.extract<32, 47>());

  uint16_t _conv2_stencil_3 = (uint16_t) (conv2_stencil.extract<0, 15>());

  uint16_t _hw_kernel2_global_wrapper_stencil_7 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_kernel2_global_wrapper_stencil_8 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_kernel2_global_wrapper_stencil_9 = (uint16_t) (hw_kernel2_global_wrapper_stencil.extract<32, 47>());

  uint16_t _1086 = _hw_kernel2_global_wrapper_stencil_7 * _conv1_stencil_10;
  uint16_t _1087 = _hw_kernel2_global_wrapper_stencil_8 * _conv1_stencil_11;
  uint16_t _1088 = _hw_kernel2_global_wrapper_stencil_9 * _conv1_stencil_12;
  uint16_t _1089 = _1087 + _1088;
  uint16_t _1090 = _conv2_stencil_3 + _1089;
  uint16_t _1091 = _1086 + _1090;
  return _1091;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w) = conv2.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv2_stencil) {
  uint16_t _conv2_stencil_4 = (uint16_t) (conv2_stencil.extract<0, 15>());

  return _conv2_stencil_4;
}

