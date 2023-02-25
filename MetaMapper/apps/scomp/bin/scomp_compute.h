#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  int16_t _hw_input_stencil_1 = (int16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = select(((((hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) < (int16)100) && ((int16)-16 < hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi))) && (hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) <= (int16)42)) && ((int16)-1 <= hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi))), (int16)255, (int16)0)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& hw_input_global_wrapper_stencil) {
  int16_t _hw_input_global_wrapper_stencil_1 = (int16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());

  int16_t _257 = (int16_t)(255);
  int16_t _258 = (int16_t)(0);
  int16_t _259 = (int16_t)(100);
  bool _260 = _hw_input_global_wrapper_stencil_1 < _259;
  int16_t _261 = (int16_t)(-16);
  bool _262 = _261 < _hw_input_global_wrapper_stencil_1;
  bool _263 = _260 && _262;
  int16_t _264 = (int16_t)(42);
  bool _265 = _hw_input_global_wrapper_stencil_1 <= _264;
  bool _266 = _263 && _265;
  int16_t _267 = (int16_t)(-1);
  bool _268 = _267 <= _hw_input_global_wrapper_stencil_1;
  bool _269 = _266 && _268;
  int16_t _270 = (int16_t)(_269 ? _257 : _258);
  return _270;
}

