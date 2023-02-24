#include <fstream>
#include "unoptimized_laplacian_pyramid.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_laplacian_pyramid.txt");
  HWStream<hw_uint<16 > > hw_input_stencil;
  HWStream<hw_uint<16 > > hw_output_stencil;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : -7 <= hw_input_global_wrapper_s0_y <= 67 and -7 <= hw_input_global_wrapper_s0_x <= 67 }
  // read map: { hw_input_stencil[i0, i1] -> op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y = i0, hw_input_global_wrapper_s0_x = i1] : -7 <= i0 <= 67 and -7 <= i1 <= 67 }
  // rng     : { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : -7 <= hw_input_global_wrapper_s0_y <= 67 and -7 <= hw_input_global_wrapper_s0_x <= 67 }
  // rng card: { 5625 }
  for (int i = 0; i < 5625; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    hw_input_stencil.write(value);
  }

  unoptimized_laplacian_pyramid(hw_input_stencil, hw_output_stencil);
  for (int i = 0; i < 4096; i++) {
    auto actual = hw_output_stencil.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(hw_input_stencil.is_empty());
  assert(hw_output_stencil.is_empty());
  return 0;
}
