#include <fstream>
#include "unoptimized_resnet_block.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_resnet_block.txt");
  HWStream<hw_uint<16 > > hw_input_stencil;
  HWStream<hw_uint<16 > > hw_kernel2_stencil;
  HWStream<hw_uint<16 > > hw_kernel_stencil;
  HWStream<hw_uint<16 > > hw_output_stencil;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_z] -> hw_input_stencil[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_z] : 0 <= hw_input_global_wrapper_s0_y <= 31 and 0 <= hw_input_global_wrapper_s0_x <= 31 and 0 <= hw_input_global_wrapper_s0_z <= 2 }
  // read map: { hw_input_stencil[i0, i1, i2] -> op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1, hw_input_global_wrapper_s0_z = i2] : 0 <= i0 <= 31 and 0 <= i1 <= 31 and 0 <= i2 <= 2 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_z] : 0 <= hw_input_global_wrapper_s0_y <= 31 and 0 <= hw_input_global_wrapper_s0_x <= 31 and 0 <= hw_input_global_wrapper_s0_z <= 2 }
  // rng card: { 3072 }
  for (int i = 0; i < 3072; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil.write(value);
  }

  // cmap    : { op_hcompute_hw_kernel2_global_wrapper_stencil[root = 0, hw_kernel2_global_wrapper_s0_y, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_z] -> hw_kernel2_stencil[hw_kernel2_global_wrapper_s0_y, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_z] : 0 <= hw_kernel2_global_wrapper_s0_y <= 2 and 0 <= hw_kernel2_global_wrapper_s0_x <= 2 and 0 <= hw_kernel2_global_wrapper_s0_w <= 2 and 0 <= hw_kernel2_global_wrapper_s0_z <= 2 }
  // read map: { hw_kernel2_stencil[i0, i1, i2, i3] -> op_hcompute_hw_kernel2_global_wrapper_stencil[root = 0, hw_kernel2_global_wrapper_s0_y = i0, hw_kernel2_global_wrapper_s0_x = i1, hw_kernel2_global_wrapper_s0_w = i2, hw_kernel2_global_wrapper_s0_z = i3] : 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 2 and 0 <= i3 <= 2 }
  // rng     : { op_hcompute_hw_kernel2_global_wrapper_stencil[root = 0, hw_kernel2_global_wrapper_s0_y, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_z] : 0 <= hw_kernel2_global_wrapper_s0_y <= 2 and 0 <= hw_kernel2_global_wrapper_s0_x <= 2 and 0 <= hw_kernel2_global_wrapper_s0_w <= 2 and 0 <= hw_kernel2_global_wrapper_s0_z <= 2 }
  // rng card: { 81 }
  for (int i = 0; i < 81; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_kernel2_stencil.write(value);
  }

  // cmap    : { op_hcompute_hw_kernel_global_wrapper_stencil[root = 0, hw_kernel_global_wrapper_s0_y, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_z] -> hw_kernel_stencil[hw_kernel_global_wrapper_s0_y, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_z] : 0 <= hw_kernel_global_wrapper_s0_y <= 2 and 0 <= hw_kernel_global_wrapper_s0_x <= 2 and 0 <= hw_kernel_global_wrapper_s0_w <= 2 and 0 <= hw_kernel_global_wrapper_s0_z <= 2 }
  // read map: { hw_kernel_stencil[i0, i1, i2, i3] -> op_hcompute_hw_kernel_global_wrapper_stencil[root = 0, hw_kernel_global_wrapper_s0_y = i0, hw_kernel_global_wrapper_s0_x = i1, hw_kernel_global_wrapper_s0_w = i2, hw_kernel_global_wrapper_s0_z = i3] : 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 2 and 0 <= i3 <= 2 }
  // rng     : { op_hcompute_hw_kernel_global_wrapper_stencil[root = 0, hw_kernel_global_wrapper_s0_y, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_z] : 0 <= hw_kernel_global_wrapper_s0_y <= 2 and 0 <= hw_kernel_global_wrapper_s0_x <= 2 and 0 <= hw_kernel_global_wrapper_s0_w <= 2 and 0 <= hw_kernel_global_wrapper_s0_z <= 2 }
  // rng card: { 81 }
  for (int i = 0; i < 81; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_kernel_stencil.write(value);
  }

  unoptimized_resnet_block(hw_input_stencil, hw_kernel2_stencil, hw_kernel_stencil, hw_output_stencil);
  for (int i = 0; i < 2352; i++) {
    auto actual = hw_output_stencil.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil.is_empty());
  assert(hw_kernel2_stencil.is_empty());
  assert(hw_kernel_stencil.is_empty());
  assert(hw_output_stencil.is_empty());
  return 0;
}
