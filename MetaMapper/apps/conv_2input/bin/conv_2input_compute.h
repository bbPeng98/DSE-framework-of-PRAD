#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: hw_weight_global_wrapper.stencil(hw_weight_global_wrapper_s0_x, hw_weight_global_wrapper_s0_y) = hw_weight.stencil(hw_weight_global_wrapper_s0_x, hw_weight_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_weight_global_wrapper_stencil(hw_uint<16>& hw_weight_stencil) {
  uint16_t _hw_weight_stencil_1 = (uint16_t) (hw_weight_stencil.extract<0, 15>());

  return _hw_weight_stencil_1;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y) = (uint16)0
hw_uint<16> hcompute_conv_stencil() {
  uint16_t _392 = (uint16_t)(0);
  return _392;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y) = ((hw_weight_global_wrapper.stencil(0, 0)*hw_input_global_wrapper.stencil(conv_s1_x, conv_s1_y)) + (conv.stencil(conv_s1_x, conv_s1_y) + ((hw_weight_global_wrapper.stencil(1, 0)*hw_input_global_wrapper.stencil((conv_s1_x + 1), conv_s1_y)) + ((hw_weight_global_wrapper.stencil(2, 0)*hw_input_global_wrapper.stencil((conv_s1_x + 2), conv_s1_y)) + ((hw_weight_global_wrapper.stencil(0, 1)*hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(1, 1)*hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(2, 1)*hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(0, 2)*hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 2))) + ((hw_weight_global_wrapper.stencil(2, 2)*hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 2))) + (hw_weight_global_wrapper.stencil(1, 2)*hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 2))))))))))))
hw_uint<16> hcompute_conv_stencil_1(hw_uint<16>& conv_stencil, hw_uint<144>& hw_input_global_wrapper_stencil, hw_uint<144>& hw_weight_global_wrapper_stencil) {
  uint16_t _conv_stencil_1 = (uint16_t) (conv_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_2 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_3 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  uint16_t _hw_input_global_wrapper_stencil_4 = (uint16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  uint16_t _hw_input_global_wrapper_stencil_5 = (uint16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  uint16_t _hw_input_global_wrapper_stencil_6 = (uint16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  uint16_t _hw_input_global_wrapper_stencil_7 = (uint16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  uint16_t _hw_input_global_wrapper_stencil_8 = (uint16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());
  uint16_t _hw_input_global_wrapper_stencil_9 = (uint16_t) (hw_input_global_wrapper_stencil.extract<128, 143>());

  uint16_t _hw_weight_global_wrapper_stencil_1 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_weight_global_wrapper_stencil_2 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_weight_global_wrapper_stencil_3 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<32, 47>());
  uint16_t _hw_weight_global_wrapper_stencil_4 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<48, 63>());
  uint16_t _hw_weight_global_wrapper_stencil_5 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<64, 79>());
  uint16_t _hw_weight_global_wrapper_stencil_6 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<80, 95>());
  uint16_t _hw_weight_global_wrapper_stencil_7 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<96, 111>());
  uint16_t _hw_weight_global_wrapper_stencil_8 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<112, 127>());
  uint16_t _hw_weight_global_wrapper_stencil_9 = (uint16_t) (hw_weight_global_wrapper_stencil.extract<128, 143>());

  uint16_t _395 = _hw_weight_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
  uint16_t _396 = _hw_weight_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
  uint16_t _397 = _hw_weight_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
  uint16_t _398 = _hw_weight_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
  uint16_t _399 = _hw_weight_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
  uint16_t _400 = _hw_weight_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
  uint16_t _401 = _hw_weight_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
  uint16_t _402 = _hw_weight_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
  uint16_t _403 = _hw_weight_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
  uint16_t _404 = _402 + _403;
  uint16_t _405 = _401 + _404;
  uint16_t _406 = _400 + _405;
  uint16_t _407 = _399 + _406;
  uint16_t _408 = _398 + _407;
  uint16_t _409 = _397 + _408;
  uint16_t _410 = _396 + _409;
  uint16_t _411 = _conv_stencil_1 + _410;
  uint16_t _412 = _395 + _411;
  return _412;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv_stencil) {
  uint16_t _conv_stencil_2 = (uint16_t) (conv_stencil.extract<0, 15>());

  return _conv_stencil_2;
}

