#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y, conv_s0_z) = (uint16)0
hw_uint<16> hcompute_conv_stencil() {
  uint16_t _318 = (uint16_t)(0);
  return _318;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y, conv_s1_z) = (((((((((conv.stencil(conv_s1_x, conv_s1_y, conv_s1_z) + uint16((kernela0[(conv_s1_z*9)]*int32(hw_input_global_wrapper.stencil(conv_s1_x, conv_s1_y))))) + uint16((kernela0[((conv_s1_z*9) + 1)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 1), conv_s1_y))))) + uint16((kernela0[((conv_s1_z*9) + 2)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 2), conv_s1_y))))) + uint16((kernela0[((conv_s1_z*9) + 3)]*int32(hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 1)))))) + uint16((kernela0[((conv_s1_z*9) + 4)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 1)))))) + uint16((kernela0[((conv_s1_z*9) + 5)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 1)))))) + uint16((kernela0[((conv_s1_z*9) + 6)]*int32(hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 2)))))) + uint16((kernela0[((conv_s1_z*9) + 7)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 2)))))) + uint16((kernela0[((conv_s1_z*9) + 8)]*int32(hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 2))))))
hw_uint<16> hcompute_conv_stencil_1(hw_uint<16>& conv_stencil, hw_uint<144>& hw_input_global_wrapper_stencil, const int _conv_s1_z) {
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

  int32_t _kernela0[27];
  // produce kernela0
  int32_t _323 = _conv_s1_z * 9;
  int32_t _324 = _323 + 8;
  _kernela0[_324] = 0;
  _kernela0[0] = 11;
  _kernela0[3] = 12;
  _kernela0[6] = 13;
  _kernela0[1] = 14;
  _kernela0[4] = 0;
  _kernela0[7] = 16;
  _kernela0[2] = 17;
  _kernela0[5] = 18;
  _kernela0[8] = 19;
  _kernela0[9] = 21;
  _kernela0[12] = 22;
  _kernela0[15] = 23;
  _kernela0[10] = 24;
  _kernela0[13] = 2;
  _kernela0[16] = 26;
  _kernela0[11] = 27;
  _kernela0[14] = 28;
  _kernela0[17] = 29;
  _kernela0[18] = 31;
  _kernela0[21] = 32;
  _kernela0[24] = 33;
  _kernela0[19] = 34;
  _kernela0[22] = 3;
  _kernela0[25] = 36;
  _kernela0[20] = 37;
  _kernela0[23] = 38;
  _kernela0[26] = 39;

  int32_t _341 = _conv_s1_z * 9;
  int32_t _342 = ((const int32_t *)_kernela0)[_341];
  int32_t _343 = (int32_t)(_hw_input_global_wrapper_stencil_1);
  int32_t _344 = _342 * _343;
  uint16_t _345 = (uint16_t)(_344);
  uint16_t _346 = _conv_stencil_1 + _345;
  int32_t _347 = _341 + 1;
  int32_t _348 = ((const int32_t *)_kernela0)[_347];
  int32_t _349 = (int32_t)(_hw_input_global_wrapper_stencil_2);
  int32_t _350 = _348 * _349;
  uint16_t _351 = (uint16_t)(_350);
  uint16_t _352 = _346 + _351;
  int32_t _353 = _341 + 2;
  int32_t _354 = ((const int32_t *)_kernela0)[_353];
  int32_t _355 = (int32_t)(_hw_input_global_wrapper_stencil_3);
  int32_t _356 = _354 * _355;
  uint16_t _357 = (uint16_t)(_356);
  uint16_t _358 = _352 + _357;
  int32_t _359 = _341 + 3;
  int32_t _360 = ((const int32_t *)_kernela0)[_359];
  int32_t _361 = (int32_t)(_hw_input_global_wrapper_stencil_4);
  int32_t _362 = _360 * _361;
  uint16_t _363 = (uint16_t)(_362);
  uint16_t _364 = _358 + _363;
  int32_t _365 = _341 + 4;
  int32_t _366 = ((const int32_t *)_kernela0)[_365];
  int32_t _367 = (int32_t)(_hw_input_global_wrapper_stencil_5);
  int32_t _368 = _366 * _367;
  uint16_t _369 = (uint16_t)(_368);
  uint16_t _370 = _364 + _369;
  int32_t _371 = _341 + 5;
  int32_t _372 = ((const int32_t *)_kernela0)[_371];
  int32_t _373 = (int32_t)(_hw_input_global_wrapper_stencil_6);
  int32_t _374 = _372 * _373;
  uint16_t _375 = (uint16_t)(_374);
  uint16_t _376 = _370 + _375;
  int32_t _377 = _341 + 6;
  int32_t _378 = ((const int32_t *)_kernela0)[_377];
  int32_t _379 = (int32_t)(_hw_input_global_wrapper_stencil_7);
  int32_t _380 = _378 * _379;
  uint16_t _381 = (uint16_t)(_380);
  uint16_t _382 = _376 + _381;
  int32_t _383 = _341 + 7;
  int32_t _384 = ((const int32_t *)_kernela0)[_383];
  int32_t _385 = (int32_t)(_hw_input_global_wrapper_stencil_8);
  int32_t _386 = _384 * _385;
  uint16_t _387 = (uint16_t)(_386);
  uint16_t _388 = _382 + _387;
  int32_t _389 = _341 + 8;
  int32_t _390 = ((const int32_t *)_kernela0)[_389];
  int32_t _391 = (int32_t)(_hw_input_global_wrapper_stencil_9);
  int32_t _392 = _390 * _391;
  uint16_t _393 = (uint16_t)(_392);
  uint16_t _394 = _388 + _393;
  return _394;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_z) = conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_z)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv_stencil) {
  uint16_t _conv_stencil_2 = (uint16_t) (conv_stencil.extract<0, 15>());

  return _conv_stencil_2;
}

