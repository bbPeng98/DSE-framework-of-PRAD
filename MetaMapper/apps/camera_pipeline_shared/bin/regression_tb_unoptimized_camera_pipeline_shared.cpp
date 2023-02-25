#include <fstream>
#include "unoptimized_camera_pipeline_shared.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_camera_pipeline_shared.txt");
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_0;
  HWStream<hw_uint<16 > > hw_input_stencil_clkwrk_1;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_2;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_3;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_4;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_5;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_6;
  HWStream<hw_uint<16 > > hw_output_global_wrapper_stencil_clkwrk_7;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_0[-4 + hw_input_global_wrapper_s0_y, -4 + 2hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 191 and 0 <= hw_input_global_wrapper_s0_x_x <= 127 }
  // read map: { hw_input_stencil_clkwrk_0[i0, i1] -> op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y = 4 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 4 + i1 and -4 <= i0 <= 187 and -4 <= i1 <= 250 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 191 and 0 <= hw_input_global_wrapper_s0_x_x <= 127 }
  // rng card: { 24576 }
  for (int i = 0; i < 24576; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_0.write(value);
  }

  // cmap    : { op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] -> hw_input_stencil_clkwrk_1[-4 + hw_input_global_wrapper_s0_y, -3 + 2hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 191 and 0 <= hw_input_global_wrapper_s0_x_x <= 127 }
  // read map: { hw_input_stencil_clkwrk_1[i0, i1] -> op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y = 4 + i0, hw_input_global_wrapper_s0_x_x] : 2hw_input_global_wrapper_s0_x_x = 3 + i1 and -4 <= i0 <= 187 and -3 <= i1 <= 251 }
  // rng     : { op_hcompute_hw_input_global_wrapper_glb_stencil_1[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x_x] : 0 <= hw_input_global_wrapper_s0_y <= 191 and 0 <= hw_input_global_wrapper_s0_x_x <= 127 }
  // rng card: { 24576 }
  for (int i = 0; i < 24576; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil_clkwrk_1.write(value);
  }

  unoptimized_camera_pipeline_shared(hw_input_stencil_clkwrk_0, hw_input_stencil_clkwrk_1, hw_output_global_wrapper_stencil_clkwrk_2, hw_output_global_wrapper_stencil_clkwrk_3, hw_output_global_wrapper_stencil_clkwrk_4, hw_output_global_wrapper_stencil_clkwrk_5, hw_output_global_wrapper_stencil_clkwrk_6, hw_output_global_wrapper_stencil_clkwrk_7);
  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_2.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_3.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_4.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_5.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_6.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 22816; i++) {
    auto actual = hw_output_global_wrapper_stencil_clkwrk_7.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil_clkwrk_0.is_empty());
  assert(hw_input_stencil_clkwrk_1.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_2.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_3.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_4.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_5.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_6.is_empty());
  assert(hw_output_global_wrapper_stencil_clkwrk_7.is_empty());
  return 0;
}
