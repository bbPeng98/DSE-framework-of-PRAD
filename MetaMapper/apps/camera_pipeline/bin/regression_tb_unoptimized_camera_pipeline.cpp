#include <fstream>
#include "unoptimized_camera_pipeline.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_camera_pipeline.txt");
  HWStream<hw_uint<16 > > hw_input_stencil;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_0;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_1;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_2;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : -4 <= hw_input_global_wrapper_s0_y <= 59 and -4 <= hw_input_global_wrapper_s0_x <= 59 }
  // read map: { hw_input_stencil[i0, i1] -> op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : -4 <= i0 <= 59 and -4 <= i1 <= 59 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : -4 <= hw_input_global_wrapper_s0_y <= 59 and -4 <= hw_input_global_wrapper_s0_x <= 59 }
  // rng card: { 4096 }
  for (int i = 0; i < 4096; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil.write(value);
  }

  unoptimized_camera_pipeline(hw_input_stencil, hw_output_stencil_clkwrk_0, hw_output_stencil_clkwrk_1, hw_output_stencil_clkwrk_2);
  for (int i = 0; i < 3136; i++) {
    auto actual = hw_output_stencil_clkwrk_0.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 3136; i++) {
    auto actual = hw_output_stencil_clkwrk_1.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 3136; i++) {
    auto actual = hw_output_stencil_clkwrk_2.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil.is_empty());
  assert(hw_output_stencil_clkwrk_0.is_empty());
  assert(hw_output_stencil_clkwrk_1.is_empty());
  assert(hw_output_stencil_clkwrk_2.is_empty());
  return 0;
}
