#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  int16_t _hw_input_stencil_1 = (int16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_kernel_global_wrapper.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y) = hw_kernel.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_kernel_global_wrapper_stencil(hw_uint<16>& hw_kernel_stencil) {
  int16_t _hw_kernel_stencil_1 = (int16_t) (hw_kernel_stencil.extract<0, 15>());

  return _hw_kernel_stencil_1;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y, 0) = (int16)0
hw_uint<16> hcompute_conv_stencil() {
  int16_t _671 = (int16_t)(0);
  return _671;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y, 1) = (int16)0
hw_uint<16> hcompute_conv_stencil_1() {
  int16_t _674 = (int16_t)(0);
  return _674;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y, 2) = (int16)0
hw_uint<16> hcompute_conv_stencil_2() {
  int16_t _677 = (int16_t)(0);
  return _677;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y, 0) = ((hw_kernel_global_wrapper.stencil(0, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (conv.stencil(conv_s1_x, conv_s1_y, 0) + ((hw_kernel_global_wrapper.stencil(1, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(2, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(3, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(3, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(4, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(4, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(5, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(5, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(7, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(7, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (hw_kernel_global_wrapper.stencil(6, 0, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(6, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y)))))))))))
hw_uint<16> hcompute_conv_stencil_3(hw_uint<16>& conv_stencil, hw_uint<128>& hw_input_global_wrapper_stencil, hw_uint<128>& hw_kernel_global_wrapper_stencil) {
  int16_t _conv_stencil_1 = (int16_t) (conv_stencil.extract<0, 15>());

  int16_t _hw_input_global_wrapper_stencil_1 = (int16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_input_global_wrapper_stencil_2 = (int16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_input_global_wrapper_stencil_3 = (int16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_input_global_wrapper_stencil_4 = (int16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_input_global_wrapper_stencil_5 = (int16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_input_global_wrapper_stencil_6 = (int16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_input_global_wrapper_stencil_7 = (int16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_input_global_wrapper_stencil_8 = (int16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());

  int16_t _hw_kernel_global_wrapper_stencil_1 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_kernel_global_wrapper_stencil_2 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_kernel_global_wrapper_stencil_3 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_kernel_global_wrapper_stencil_4 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_kernel_global_wrapper_stencil_5 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_kernel_global_wrapper_stencil_6 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_kernel_global_wrapper_stencil_7 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_kernel_global_wrapper_stencil_8 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<112, 127>());

  int16_t _680 = _hw_kernel_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
  int16_t _681 = _hw_kernel_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
  int16_t _682 = _hw_kernel_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
  int16_t _683 = _hw_kernel_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
  int16_t _684 = _hw_kernel_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
  int16_t _685 = _hw_kernel_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
  int16_t _686 = _hw_kernel_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
  int16_t _687 = _hw_kernel_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
  int16_t _688 = _686 + _687;
  int16_t _689 = _685 + _688;
  int16_t _690 = _684 + _689;
  int16_t _691 = _683 + _690;
  int16_t _692 = _682 + _691;
  int16_t _693 = _681 + _692;
  int16_t _694 = _conv_stencil_1 + _693;
  int16_t _695 = _680 + _694;
  return _695;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y, 1) = ((hw_kernel_global_wrapper.stencil(0, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (conv.stencil(conv_s1_x, conv_s1_y, 1) + ((hw_kernel_global_wrapper.stencil(1, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(2, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(3, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(3, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(4, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(4, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(5, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(5, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(7, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(7, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (hw_kernel_global_wrapper.stencil(6, 1, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(6, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y)))))))))))
hw_uint<16> hcompute_conv_stencil_4(hw_uint<16>& conv_stencil, hw_uint<128>& hw_input_global_wrapper_stencil, hw_uint<128>& hw_kernel_global_wrapper_stencil) {
  int16_t _conv_stencil_2 = (int16_t) (conv_stencil.extract<0, 15>());

  int16_t _hw_input_global_wrapper_stencil_10 = (int16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_input_global_wrapper_stencil_11 = (int16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_input_global_wrapper_stencil_12 = (int16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_input_global_wrapper_stencil_13 = (int16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_input_global_wrapper_stencil_14 = (int16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_input_global_wrapper_stencil_15 = (int16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_input_global_wrapper_stencil_16 = (int16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_input_global_wrapper_stencil_9 = (int16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());

  int16_t _hw_kernel_global_wrapper_stencil_10 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_kernel_global_wrapper_stencil_11 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_kernel_global_wrapper_stencil_12 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_kernel_global_wrapper_stencil_13 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_kernel_global_wrapper_stencil_14 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_kernel_global_wrapper_stencil_15 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_kernel_global_wrapper_stencil_16 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_kernel_global_wrapper_stencil_9 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<112, 127>());

  int16_t _747 = _hw_kernel_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
  int16_t _748 = _hw_kernel_global_wrapper_stencil_10 * _hw_input_global_wrapper_stencil_10;
  int16_t _749 = _hw_kernel_global_wrapper_stencil_11 * _hw_input_global_wrapper_stencil_11;
  int16_t _750 = _hw_kernel_global_wrapper_stencil_12 * _hw_input_global_wrapper_stencil_12;
  int16_t _751 = _hw_kernel_global_wrapper_stencil_13 * _hw_input_global_wrapper_stencil_13;
  int16_t _752 = _hw_kernel_global_wrapper_stencil_14 * _hw_input_global_wrapper_stencil_14;
  int16_t _753 = _hw_kernel_global_wrapper_stencil_15 * _hw_input_global_wrapper_stencil_15;
  int16_t _754 = _hw_kernel_global_wrapper_stencil_16 * _hw_input_global_wrapper_stencil_16;
  int16_t _755 = _753 + _754;
  int16_t _756 = _752 + _755;
  int16_t _757 = _751 + _756;
  int16_t _758 = _750 + _757;
  int16_t _759 = _749 + _758;
  int16_t _760 = _748 + _759;
  int16_t _761 = _conv_stencil_2 + _760;
  int16_t _762 = _747 + _761;
  return _762;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y, 2) = ((hw_kernel_global_wrapper.stencil(0, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (conv.stencil(conv_s1_x, conv_s1_y, 2) + ((hw_kernel_global_wrapper.stencil(1, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(2, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(3, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(3, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(4, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(4, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(5, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(5, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + ((hw_kernel_global_wrapper.stencil(7, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(7, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y))) + (hw_kernel_global_wrapper.stencil(6, 2, conv_s1_r_x, conv_s1_r_y)*hw_input_global_wrapper.stencil(6, (conv_s1_r_x + conv_s1_x), (conv_s1_r_y + conv_s1_y)))))))))))
hw_uint<16> hcompute_conv_stencil_5(hw_uint<16>& conv_stencil, hw_uint<128>& hw_input_global_wrapper_stencil, hw_uint<128>& hw_kernel_global_wrapper_stencil) {
  int16_t _conv_stencil_3 = (int16_t) (conv_stencil.extract<0, 15>());

  int16_t _hw_input_global_wrapper_stencil_17 = (int16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_input_global_wrapper_stencil_18 = (int16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_input_global_wrapper_stencil_19 = (int16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_input_global_wrapper_stencil_20 = (int16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_input_global_wrapper_stencil_21 = (int16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_input_global_wrapper_stencil_22 = (int16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_input_global_wrapper_stencil_23 = (int16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_input_global_wrapper_stencil_24 = (int16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());

  int16_t _hw_kernel_global_wrapper_stencil_17 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<0, 15>());
  int16_t _hw_kernel_global_wrapper_stencil_18 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<16, 31>());
  int16_t _hw_kernel_global_wrapper_stencil_19 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<32, 47>());
  int16_t _hw_kernel_global_wrapper_stencil_20 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<48, 63>());
  int16_t _hw_kernel_global_wrapper_stencil_21 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<64, 79>());
  int16_t _hw_kernel_global_wrapper_stencil_22 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<80, 95>());
  int16_t _hw_kernel_global_wrapper_stencil_23 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<96, 111>());
  int16_t _hw_kernel_global_wrapper_stencil_24 = (int16_t) (hw_kernel_global_wrapper_stencil.extract<112, 127>());

  int16_t _814 = _hw_kernel_global_wrapper_stencil_17 * _hw_input_global_wrapper_stencil_17;
  int16_t _815 = _hw_kernel_global_wrapper_stencil_18 * _hw_input_global_wrapper_stencil_18;
  int16_t _816 = _hw_kernel_global_wrapper_stencil_19 * _hw_input_global_wrapper_stencil_19;
  int16_t _817 = _hw_kernel_global_wrapper_stencil_20 * _hw_input_global_wrapper_stencil_20;
  int16_t _818 = _hw_kernel_global_wrapper_stencil_21 * _hw_input_global_wrapper_stencil_21;
  int16_t _819 = _hw_kernel_global_wrapper_stencil_22 * _hw_input_global_wrapper_stencil_22;
  int16_t _820 = _hw_kernel_global_wrapper_stencil_23 * _hw_input_global_wrapper_stencil_23;
  int16_t _821 = _hw_kernel_global_wrapper_stencil_24 * _hw_input_global_wrapper_stencil_24;
  int16_t _822 = _820 + _821;
  int16_t _823 = _819 + _822;
  int16_t _824 = _818 + _823;
  int16_t _825 = _817 + _824;
  int16_t _826 = _816 + _825;
  int16_t _827 = _815 + _826;
  int16_t _828 = _conv_stencil_3 + _827;
  int16_t _829 = _814 + _828;
  return _829;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w) = max(conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w), (int16)0)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv_stencil) {
  int16_t _conv_stencil_4 = (int16_t) (conv_stencil.extract<0, 15>());

  int16_t _881 = (int16_t)(0);
  int16_t _882 = max(_conv_stencil_4, _881);
  return _882;
}

