#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = select(bitwise_xor(((hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) < (uint16)64) || ((uint16)128 <= hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi))), ((uint16)128 <= hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi))), (int16)200, (int16)0)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& hw_input_global_wrapper_stencil) {
  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());

  int16_t _257 = (int16_t)(200);
  int16_t _258 = (int16_t)(0);
  uint16_t _259 = (uint16_t)(64);
  bool _260 = _hw_input_global_wrapper_stencil_1 < _259;
  uint16_t _261 = (uint16_t)(128);
  bool _262 = _261 <= _hw_input_global_wrapper_stencil_1;
  bool _263 = _260 || _262;
  bool _264 = _263 ^ _262;
  int16_t _265 = (int16_t)(_264 ? _257 : _258);
  return _265;
}

