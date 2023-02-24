#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: brighten.stencil(brighten_s0_x, brighten_s0_y) = (hw_input_global_wrapper.stencil(brighten_s0_x, brighten_s0_y)*(uint16)2)
hw_uint<16> hcompute_brighten_stencil(hw_uint<16>& hw_input_global_wrapper_stencil) {
  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());

  uint16_t _257 = (uint16_t)(2);
  uint16_t _258 = _hw_input_global_wrapper_stencil_1 * _257;
  return _258;
}

//store is: blur.stencil(blur_s0_x, blur_s0_y) = (uint16)0
hw_uint<16> hcompute_blur_stencil() {
  uint16_t _264 = (uint16_t)(0);
  return _264;
}

//store is: blur.stencil(blur_s1_x, blur_s1_y) = (brighten.stencil(blur_s1_x, blur_s1_y) + (blur.stencil(blur_s1_x, blur_s1_y) + (brighten.stencil((blur_s1_x + 1), blur_s1_y) + (brighten.stencil((blur_s1_x + 1), (blur_s1_y + 1)) + brighten.stencil(blur_s1_x, (blur_s1_y + 1))))))
hw_uint<16> hcompute_blur_stencil_1(hw_uint<16>& blur_stencil, hw_uint<64>& brighten_stencil) {
  uint16_t _blur_stencil_1 = (uint16_t) (blur_stencil.extract<0, 15>());

  uint16_t _brighten_stencil_1 = (uint16_t) (brighten_stencil.extract<0, 15>());
  uint16_t _brighten_stencil_2 = (uint16_t) (brighten_stencil.extract<16, 31>());
  uint16_t _brighten_stencil_3 = (uint16_t) (brighten_stencil.extract<32, 47>());
  uint16_t _brighten_stencil_4 = (uint16_t) (brighten_stencil.extract<48, 63>());

  uint16_t _267 = _brighten_stencil_3 + _brighten_stencil_4;
  uint16_t _268 = _brighten_stencil_2 + _267;
  uint16_t _269 = _blur_stencil_1 + _268;
  uint16_t _270 = _brighten_stencil_1 + _269;
  return _270;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = (blur.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)/(uint16)4)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& blur_stencil) {
  uint16_t _blur_stencil_2 = (uint16_t) (blur_stencil.extract<0, 15>());

  uint16_t _286 = (uint16_t)(2);
  uint16_t _287 = _blur_stencil_2 >> _286;
  return _287;
}

