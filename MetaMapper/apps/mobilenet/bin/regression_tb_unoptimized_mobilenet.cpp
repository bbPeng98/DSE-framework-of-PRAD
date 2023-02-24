#include <fstream>
#include "unoptimized_mobilenet.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_mobilenet.txt");
  HWStream<hw_uint<16 > > hw_filter_dw_stencil_clkwrk_0;
  HWStream<hw_uint<16 > > hw_filter_dw_stencil_clkwrk_1;
  HWStream<hw_uint<16 > > hw_filter_dw_stencil_clkwrk_2;
  HWStream<hw_uint<16 > > hw_filter_dw_stencil_clkwrk_3;
  HWStream<hw_uint<16 > > hw_filter_pw_stencil;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_4;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_5;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_6;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_7;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_10;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_8;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_9;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_filter_dw_global_wrapper_stencil[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] -> hw_filter_dw_stencil_clkwrk_0[hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x, 0] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // read map: { hw_filter_dw_stencil_clkwrk_0[i0, i1, 0] -> op_hcompute_hw_filter_dw_global_wrapper_stencil[root = 0, hw_filter_dw_global_wrapper_s0_y = i0, hw_filter_dw_global_wrapper_s0_x = i1] : 0 <= i0 <= 2 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_filter_dw_global_wrapper_stencil[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // rng card: { 9 }
  for (int i = 0; i < 9; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_filter_dw_stencil_clkwrk_0.write(value);
  }

  // cmap    : { op_hcompute_hw_filter_dw_global_wrapper_stencil_1[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] -> hw_filter_dw_stencil_clkwrk_1[hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x, 1] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // read map: { hw_filter_dw_stencil_clkwrk_1[i0, i1, 1] -> op_hcompute_hw_filter_dw_global_wrapper_stencil_1[root = 0, hw_filter_dw_global_wrapper_s0_y = i0, hw_filter_dw_global_wrapper_s0_x = i1] : 0 <= i0 <= 2 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_filter_dw_global_wrapper_stencil_1[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // rng card: { 9 }
  for (int i = 0; i < 9; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_filter_dw_stencil_clkwrk_1.write(value);
  }

  // cmap    : { op_hcompute_hw_filter_dw_global_wrapper_stencil_2[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] -> hw_filter_dw_stencil_clkwrk_2[hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x, 2] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // read map: { hw_filter_dw_stencil_clkwrk_2[i0, i1, 2] -> op_hcompute_hw_filter_dw_global_wrapper_stencil_2[root = 0, hw_filter_dw_global_wrapper_s0_y = i0, hw_filter_dw_global_wrapper_s0_x = i1] : 0 <= i0 <= 2 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_filter_dw_global_wrapper_stencil_2[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // rng card: { 9 }
  for (int i = 0; i < 9; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_filter_dw_stencil_clkwrk_2.write(value);
  }

  // cmap    : { op_hcompute_hw_filter_dw_global_wrapper_stencil_3[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] -> hw_filter_dw_stencil_clkwrk_3[hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x, 3] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // read map: { hw_filter_dw_stencil_clkwrk_3[i0, i1, 3] -> op_hcompute_hw_filter_dw_global_wrapper_stencil_3[root = 0, hw_filter_dw_global_wrapper_s0_y = i0, hw_filter_dw_global_wrapper_s0_x = i1] : 0 <= i0 <= 2 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_filter_dw_global_wrapper_stencil_3[root = 0, hw_filter_dw_global_wrapper_s0_y, hw_filter_dw_global_wrapper_s0_x] : 0 <= hw_filter_dw_global_wrapper_s0_y <= 2 and 0 <= hw_filter_dw_global_wrapper_s0_x <= 2 }
  // rng card: { 9 }
  for (int i = 0; i < 9; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_filter_dw_stencil_clkwrk_3.write(value);
  }

  // cmap    : { op_hcompute_hw_filter_pw_global_wrapper_stencil[root = 0, hw_filter_pw_global_wrapper_s0_c, hw_filter_pw_global_wrapper_s0_k] -> hw_filter_pw_stencil[hw_filter_pw_global_wrapper_s0_c, hw_filter_pw_global_wrapper_s0_k] : 0 <= hw_filter_pw_global_wrapper_s0_c <= 3 and 0 <= hw_filter_pw_global_wrapper_s0_k <= 2 }
  // read map: { hw_filter_pw_stencil[i0, i1] -> op_hcompute_hw_filter_pw_global_wrapper_stencil[root = 0, hw_filter_pw_global_wrapper_s0_c = i0, hw_filter_pw_global_wrapper_s0_k = i1] : 0 <= i0 <= 3 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_filter_pw_global_wrapper_stencil[root = 0, hw_filter_pw_global_wrapper_s0_c, hw_filter_pw_global_wrapper_s0_k] : 0 <= hw_filter_pw_global_wrapper_s0_c <= 3 and 0 <= hw_filter_pw_global_wrapper_s0_k <= 2 }
  // rng card: { 12 }
  for (int i = 0; i < 12; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_filter_pw_stencil.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil_clkwrk_4[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, 0] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // read map: { hw_input_stencil_clkwrk_4[i0, i1, 0] -> op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : 0 <= i0 <= 29 and 0 <= i1 <= 29 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // rng card: { 900 }
  for (int i = 0; i < 900; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_4.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil_clkwrk_5[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, 1] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // read map: { hw_input_stencil_clkwrk_5[i0, i1, 1] -> op_hcompute_hw_input_global_wrapper_stencil_1[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : 0 <= i0 <= 29 and 0 <= i1 <= 29 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // rng card: { 900 }
  for (int i = 0; i < 900; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_5.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil_2[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil_clkwrk_6[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, 2] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // read map: { hw_input_stencil_clkwrk_6[i0, i1, 2] -> op_hcompute_hw_input_global_wrapper_stencil_2[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : 0 <= i0 <= 29 and 0 <= i1 <= 29 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil_2[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // rng card: { 900 }
  for (int i = 0; i < 900; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_6.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil_3[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil_clkwrk_7[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, 3] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // read map: { hw_input_stencil_clkwrk_7[i0, i1, 3] -> op_hcompute_hw_input_global_wrapper_stencil_3[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : 0 <= i0 <= 29 and 0 <= i1 <= 29 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil_3[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 29 and 0 <= hw_input_global_wrapper_s0_x <= 29 }
  // rng card: { 900 }
  for (int i = 0; i < 900; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_7.write(value);
  }

  unoptimized_mobilenet(hw_filter_dw_stencil_clkwrk_0, hw_filter_dw_stencil_clkwrk_1, hw_filter_dw_stencil_clkwrk_2, hw_filter_dw_stencil_clkwrk_3, hw_filter_pw_stencil, hw_input_stencil_clkwrk_4, hw_input_stencil_clkwrk_5, hw_input_stencil_clkwrk_6, hw_input_stencil_clkwrk_7, hw_output_stencil_clkwrk_10, hw_output_stencil_clkwrk_8, hw_output_stencil_clkwrk_9);
  for (int i = 0; i < 784; i++) {
    auto actual = hw_output_stencil_clkwrk_10.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 784; i++) {
    auto actual = hw_output_stencil_clkwrk_8.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 784; i++) {
    auto actual = hw_output_stencil_clkwrk_9.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_filter_dw_stencil_clkwrk_0.is_empty());
  assert(hw_filter_dw_stencil_clkwrk_1.is_empty());
  assert(hw_filter_dw_stencil_clkwrk_2.is_empty());
  assert(hw_filter_dw_stencil_clkwrk_3.is_empty());
  assert(hw_filter_pw_stencil.is_empty());
  assert(hw_input_stencil_clkwrk_4.is_empty());
  assert(hw_input_stencil_clkwrk_5.is_empty());
  assert(hw_input_stencil_clkwrk_6.is_empty());
  assert(hw_input_stencil_clkwrk_7.is_empty());
  assert(hw_output_stencil_clkwrk_10.is_empty());
  assert(hw_output_stencil_clkwrk_8.is_empty());
  assert(hw_output_stencil_clkwrk_9.is_empty());
  return 0;
}
