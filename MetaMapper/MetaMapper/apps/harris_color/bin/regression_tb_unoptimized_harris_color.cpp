#include <fstream>
#include "unoptimized_harris_color.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_harris_color.txt");
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_0;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_1;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_2;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_3;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_4;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_5;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_6;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_7;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_0[-3 + hw_input_global_wrapper_s0_y, -3 + 2hw_input_global_wrapper_s0_x_x, 0] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_0[i0, i1, 0] -> op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 3 + i1 and -3 <= i0 <= 257 and -3 <= i1 <= 123 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_0.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_1[-3 + hw_input_global_wrapper_s0_y, -3 + 2hw_input_global_wrapper_s0_x_x, 1] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_1[i0, i1, 1] -> op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 3 + i1 and -3 <= i0 <= 257 and -3 <= i1 <= 123 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_1.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_2[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_2[-3 + hw_input_global_wrapper_s0_y, -3 + 2hw_input_global_wrapper_s0_x_x, 2] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_2[i0, i1, 2] -> op_hcompute_hw_input_global_wrapper_glb_stencil_2[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 3 + i1 and -3 <= i0 <= 257 and -3 <= i1 <= 123 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_2[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_2.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_3[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_3[-3 + hw_input_global_wrapper_s0_y, -2 + 2hw_input_global_wrapper_s0_x_x, 0] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_3[i0, i1, 0] -> op_hcompute_hw_input_global_wrapper_glb_stencil_3[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 2 + i1 and -3 <= i0 <= 257 and -2 <= i1 <= 124 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_3[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_3.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_4[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_4[-3 + hw_input_global_wrapper_s0_y, -2 + 2hw_input_global_wrapper_s0_x_x, 1] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_4[i0, i1, 1] -> op_hcompute_hw_input_global_wrapper_glb_stencil_4[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 2 + i1 and -3 <= i0 <= 257 and -2 <= i1 <= 124 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_4[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_4.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_5[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_5[-3 + hw_input_global_wrapper_s0_y, -2 + 2hw_input_global_wrapper_s0_x_x, 2] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // read map: { hw_input_stencil_clkwrk_5[i0, i1, 2] -> op_hcompute_hw_input_global_wrapper_glb_stencil_5[root = 0, hw_input_global_wrapper_s0_y = 3 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 2 + i1 and -3 <= i0 <= 257 and -2 <= i1 <= 124 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_5[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 260 and 0 <= hw_input_global_wrapper_s0_x_x <= 63 }
  // rng card: { 16704 }
  for (int i = 0; i < 16704; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_5.write(value);
  }

  unoptimized_harris_color(hw_input_stencil_clkwrk_0, hw_input_stencil_clkwrk_1, hw_input_stencil_clkwrk_2, hw_input_stencil_clkwrk_3, hw_input_stencil_clkwrk_4, hw_input_stencil_clkwrk_5, hw_output_global_wrapper_stencil_clkwrk_6, hw_output_global_wrapper_stencil_clkwrk_7);
  for (int i = 0; i < 15555; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_6.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 15555; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_7.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil_clkwrk_0.is_empty());
  assert(hw_input_stencil_clkwrk_1.is_empty());
  assert(hw_input_stencil_clkwrk_2.is_empty());
  assert(hw_input_stencil_clkwrk_3.is_empty());
  assert(hw_input_stencil_clkwrk_4.is_empty());
  assert(hw_input_stencil_clkwrk_5.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_6.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_7.is_empty());
  return 0;
}
