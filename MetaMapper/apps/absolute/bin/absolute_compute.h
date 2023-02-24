#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  int16_t _hw_input_stencil_1 = (int16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = absd(int16(abs((hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) + (int16)-100))), (int16)30)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& hw_input_global_wrapper_stencil) {
  int16_t _hw_input_global_wrapper_stencil_1 = (int16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());

  int16_t _257 = (int16_t)(30);
  int16_t _258 = (int16_t)(-100);
  int16_t _259 = _hw_input_global_wrapper_stencil_1 + _258;
  int16_t _260 = (int16_t)(0);
  int16_t _261 = _260 - _259;
  bool _262 = _259 > _260;
  int16_t _263 = (int16_t)(_262 ? _259 : _261);
  uint16_t _264 = (uint16_t)(_263);
  uint16_t _265 = _264;
  int16_t _266 = (int16_t)(_265);
  int16_t _267 = _257 - _266;
  int16_t _268 = _266 - _257;
  bool _269 = _266 < _257;
  int16_t _270 = (int16_t)(_269 ? _267 : _268);
  uint16_t _271 = (uint16_t)(_270);
  uint16_t _272 = _271;
  return _272;
}

