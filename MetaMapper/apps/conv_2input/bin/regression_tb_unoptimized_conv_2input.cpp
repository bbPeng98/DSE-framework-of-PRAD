#include <fstream>
#include "unoptimized_conv_2input.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_conv_2input.txt");
  HWStream<hw_uint<16 > > hw_input_stencil;
  HWStream<hw_uint<16 > > hw_weight_stencil;
  HWStream<hw_uint<16 > > hw_output_stencil;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 63 and 0 <= hw_input_global_wrapper_s0_x <= 63 }
  // read map: { hw_input_stencil[i0, i1] -> op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : 0 <= i0 <= 63 and 0 <= i1 <= 63 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 63 and 0 <= hw_input_global_wrapper_s0_x <= 63 }
  // rng card: { 4096 }
  for (int i = 0; i < 4096; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil.write(value);
  }

  // cmap    : { op_hcompute_hw_weight_global_wrapper_stencil[root = 0, hw_weight_global_wrapper_s0_y, hw_weight_global_wrapper_s0_x] -> hw_weight_stencil[hw_weight_global_wrapper_s0_y, hw_weight_global_wrapper_s0_x] : 0 <= hw_weight_global_wrapper_s0_y <= 2 and 0 <= hw_weight_global_wrapper_s0_x <= 2 }
  // read map: { hw_weight_stencil[i0, i1] -> op_hcompute_hw_weight_global_wrapper_stencil[root = 0, hw_weight_global_wrapper_s0_y = i0, hw_weight_global_wrapper_s0_x = i1] : 0 <= i0 <= 2 and 0 <= i1 <= 2 }
  // rng     : { op_hcompute_hw_weight_global_wrapper_stencil[root = 0, hw_weight_global_wrapper_s0_y, hw_weight_global_wrapper_s0_x] : 0 <= hw_weight_global_wrapper_s0_y <= 2 and 0 <= hw_weight_global_wrapper_s0_x <= 2 }
  // rng card: { 9 }
  for (int i = 0; i < 9; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_weight_stencil.write(value);
  }

  unoptimized_conv_2input(hw_input_stencil, hw_weight_stencil, hw_output_stencil);
  for (int i = 0; i < 3844; i++) {
    auto actual = hw_output_stencil.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil.is_empty());
  assert(hw_weight_stencil.is_empty());
  assert(hw_output_stencil.is_empty());
  return 0;
}
