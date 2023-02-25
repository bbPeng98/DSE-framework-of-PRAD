#include <fstream>
#include "unoptimized_harris.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_harris.txt");
  HWStream<hw_uint<16 > > padded16_stencil;
  HWStream<hw_uint<16 > > hw_output_stencil;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_padded16_global_wrapper_stencil[root = 0, padded16_global_wrapper_s0_y, padded16_global_wrapper_s0_x] -> padded16_stencil[padded16_global_wrapper_s0_y, padded16_global_wrapper_s0_x] : -3 <= padded16_global_wrapper_s0_y <= 60 and -3 <= padded16_global_wrapper_s0_x <= 60 }
  // read map: { padded16_stencil[i0, i1] -> op_hcompute_padded16_global_wrapper_stencil[root = 0, padded16_global_wrapper_s0_y = i0, padded16_global_wrapper_s0_x = i1] : -3 <= i0 <= 60 and -3 <= i1 <= 60 }
  // rng     : { op_hcompute_padded16_global_wrapper_stencil[root = 0, padded16_global_wrapper_s0_y, padded16_global_wrapper_s0_x] : -3 <= padded16_global_wrapper_s0_y <= 60 and -3 <= padded16_global_wrapper_s0_x <= 60 }
  // rng card: { 4096 }
  for (int i = 0; i < 4096; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    padded16_stencil.write(value);
  }

  unoptimized_harris(padded16_stencil, hw_output_stencil);
  for (int i = 0; i < 3364; i++) {
    auto actual = hw_output_stencil.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(padded16_stencil.is_empty());
  assert(hw_output_stencil.is_empty());
  return 0;
}
