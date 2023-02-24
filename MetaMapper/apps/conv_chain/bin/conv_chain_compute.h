#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: conv0.stencil(conv0_s0_x, conv0_s0_y) = (uint16)0
hw_uint<16> hcompute_conv0_stencil() {
  uint16_t _257 = (uint16_t)(0);
  return _257;
}

//store is: conv0.stencil(conv0_s1_x_x, conv0_s1_y) = ((hw_input_global_wrapper.stencil(conv0_s1_x_x, conv0_s1_y)*(uint16)17) + (conv0.stencil(conv0_s1_x_x, conv0_s1_y) + ((hw_input_global_wrapper.stencil((conv0_s1_x_x + 1), conv0_s1_y)*(uint16)7) + ((hw_input_global_wrapper.stencil((conv0_s1_x_x + 2), conv0_s1_y)*(uint16)5) + ((hw_input_global_wrapper.stencil(conv0_s1_x_x, (conv0_s1_y + 1))*(uint16)4) + ((hw_input_global_wrapper.stencil((conv0_s1_x_x + 1), (conv0_s1_y + 1))*(uint16)19) + ((hw_input_global_wrapper.stencil((conv0_s1_x_x + 2), (conv0_s1_y + 1))*(uint16)21) + ((hw_input_global_wrapper.stencil(conv0_s1_x_x, (conv0_s1_y + 2))*(uint16)6) + ((hw_input_global_wrapper.stencil((conv0_s1_x_x + 2), (conv0_s1_y + 2))*(uint16)15) + (hw_input_global_wrapper.stencil((conv0_s1_x_x + 1), (conv0_s1_y + 2))*(uint16)4))))))))))
hw_uint<16> hcompute_conv0_stencil_1(hw_uint<16>& conv0_stencil, hw_uint<144>& hw_input_global_wrapper_stencil) {
  uint16_t _conv0_stencil_1 = (uint16_t) (conv0_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_2 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_3 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  uint16_t _hw_input_global_wrapper_stencil_4 = (uint16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  uint16_t _hw_input_global_wrapper_stencil_5 = (uint16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  uint16_t _hw_input_global_wrapper_stencil_6 = (uint16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  uint16_t _hw_input_global_wrapper_stencil_7 = (uint16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  uint16_t _hw_input_global_wrapper_stencil_8 = (uint16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());
  uint16_t _hw_input_global_wrapper_stencil_9 = (uint16_t) (hw_input_global_wrapper_stencil.extract<128, 143>());

  uint16_t _260 = (uint16_t)(17);
  uint16_t _261 = _hw_input_global_wrapper_stencil_1 * _260;
  uint16_t _262 = (uint16_t)(7);
  uint16_t _263 = _hw_input_global_wrapper_stencil_2 * _262;
  uint16_t _264 = (uint16_t)(5);
  uint16_t _265 = _hw_input_global_wrapper_stencil_3 * _264;
  uint16_t _266 = (uint16_t)(4);
  uint16_t _267 = _hw_input_global_wrapper_stencil_4 * _266;
  uint16_t _268 = (uint16_t)(19);
  uint16_t _269 = _hw_input_global_wrapper_stencil_5 * _268;
  uint16_t _270 = (uint16_t)(21);
  uint16_t _271 = _hw_input_global_wrapper_stencil_6 * _270;
  uint16_t _272 = (uint16_t)(6);
  uint16_t _273 = _hw_input_global_wrapper_stencil_7 * _272;
  uint16_t _274 = (uint16_t)(15);
  uint16_t _275 = _hw_input_global_wrapper_stencil_8 * _274;
  uint16_t _276 = _hw_input_global_wrapper_stencil_9 * _266;
  uint16_t _277 = _275 + _276;
  uint16_t _278 = _273 + _277;
  uint16_t _279 = _271 + _278;
  uint16_t _280 = _269 + _279;
  uint16_t _281 = _267 + _280;
  uint16_t _282 = _265 + _281;
  uint16_t _283 = _263 + _282;
  uint16_t _284 = _conv0_stencil_1 + _283;
  uint16_t _285 = _261 + _284;
  return _285;
}

//store is: conv1.stencil(conv1_s0_x, conv1_s0_y) = (uint16)0
hw_uint<16> hcompute_conv1_stencil() {
  uint16_t _352 = (uint16_t)(0);
  return _352;
}

//store is: conv1.stencil(conv1_s1_x_x, conv1_s1_y) = ((conv0.stencil(conv1_s1_x_x, conv1_s1_y)*(uint16)17) + (conv1.stencil(conv1_s1_x_x, conv1_s1_y) + ((conv0.stencil((conv1_s1_x_x + 1), conv1_s1_y)*(uint16)7) + ((conv0.stencil((conv1_s1_x_x + 2), conv1_s1_y)*(uint16)5) + ((conv0.stencil(conv1_s1_x_x, (conv1_s1_y + 1))*(uint16)4) + ((conv0.stencil((conv1_s1_x_x + 1), (conv1_s1_y + 1))*(uint16)19) + ((conv0.stencil((conv1_s1_x_x + 2), (conv1_s1_y + 1))*(uint16)21) + ((conv0.stencil(conv1_s1_x_x, (conv1_s1_y + 2))*(uint16)6) + ((conv0.stencil((conv1_s1_x_x + 2), (conv1_s1_y + 2))*(uint16)15) + (conv0.stencil((conv1_s1_x_x + 1), (conv1_s1_y + 2))*(uint16)4))))))))))
hw_uint<16> hcompute_conv1_stencil_1(hw_uint<144>& conv0_stencil, hw_uint<16>& conv1_stencil) {
  uint16_t _conv0_stencil_10 = (uint16_t) (conv0_stencil.extract<0, 15>());
  uint16_t _conv0_stencil_2 = (uint16_t) (conv0_stencil.extract<16, 31>());
  uint16_t _conv0_stencil_3 = (uint16_t) (conv0_stencil.extract<32, 47>());
  uint16_t _conv0_stencil_4 = (uint16_t) (conv0_stencil.extract<48, 63>());
  uint16_t _conv0_stencil_5 = (uint16_t) (conv0_stencil.extract<64, 79>());
  uint16_t _conv0_stencil_6 = (uint16_t) (conv0_stencil.extract<80, 95>());
  uint16_t _conv0_stencil_7 = (uint16_t) (conv0_stencil.extract<96, 111>());
  uint16_t _conv0_stencil_8 = (uint16_t) (conv0_stencil.extract<112, 127>());
  uint16_t _conv0_stencil_9 = (uint16_t) (conv0_stencil.extract<128, 143>());

  uint16_t _conv1_stencil_1 = (uint16_t) (conv1_stencil.extract<0, 15>());

  uint16_t _355 = (uint16_t)(17);
  uint16_t _356 = _conv0_stencil_2 * _355;
  uint16_t _357 = (uint16_t)(7);
  uint16_t _358 = _conv0_stencil_3 * _357;
  uint16_t _359 = (uint16_t)(5);
  uint16_t _360 = _conv0_stencil_4 * _359;
  uint16_t _361 = (uint16_t)(4);
  uint16_t _362 = _conv0_stencil_5 * _361;
  uint16_t _363 = (uint16_t)(19);
  uint16_t _364 = _conv0_stencil_6 * _363;
  uint16_t _365 = (uint16_t)(21);
  uint16_t _366 = _conv0_stencil_7 * _365;
  uint16_t _367 = (uint16_t)(6);
  uint16_t _368 = _conv0_stencil_8 * _367;
  uint16_t _369 = (uint16_t)(15);
  uint16_t _370 = _conv0_stencil_9 * _369;
  uint16_t _371 = _conv0_stencil_10 * _361;
  uint16_t _372 = _370 + _371;
  uint16_t _373 = _368 + _372;
  uint16_t _374 = _366 + _373;
  uint16_t _375 = _364 + _374;
  uint16_t _376 = _362 + _375;
  uint16_t _377 = _360 + _376;
  uint16_t _378 = _358 + _377;
  uint16_t _379 = _conv1_stencil_1 + _378;
  uint16_t _380 = _356 + _379;
  return _380;
}

//store is: conv2.stencil(conv2_s0_x, conv2_s0_y) = (uint16)0
hw_uint<16> hcompute_conv2_stencil() {
  uint16_t _447 = (uint16_t)(0);
  return _447;
}

//store is: conv2.stencil(conv2_s1_x_x, conv2_s1_y) = ((conv1.stencil(conv2_s1_x_x, conv2_s1_y)*(uint16)17) + (conv2.stencil(conv2_s1_x_x, conv2_s1_y) + ((conv1.stencil((conv2_s1_x_x + 1), conv2_s1_y)*(uint16)7) + ((conv1.stencil((conv2_s1_x_x + 2), conv2_s1_y)*(uint16)5) + ((conv1.stencil(conv2_s1_x_x, (conv2_s1_y + 1))*(uint16)4) + ((conv1.stencil((conv2_s1_x_x + 1), (conv2_s1_y + 1))*(uint16)19) + ((conv1.stencil((conv2_s1_x_x + 2), (conv2_s1_y + 1))*(uint16)21) + ((conv1.stencil(conv2_s1_x_x, (conv2_s1_y + 2))*(uint16)6) + ((conv1.stencil((conv2_s1_x_x + 2), (conv2_s1_y + 2))*(uint16)15) + (conv1.stencil((conv2_s1_x_x + 1), (conv2_s1_y + 2))*(uint16)4))))))))))
hw_uint<16> hcompute_conv2_stencil_1(hw_uint<144>& conv1_stencil, hw_uint<16>& conv2_stencil) {
  uint16_t _conv1_stencil_10 = (uint16_t) (conv1_stencil.extract<0, 15>());
  uint16_t _conv1_stencil_2 = (uint16_t) (conv1_stencil.extract<16, 31>());
  uint16_t _conv1_stencil_3 = (uint16_t) (conv1_stencil.extract<32, 47>());
  uint16_t _conv1_stencil_4 = (uint16_t) (conv1_stencil.extract<48, 63>());
  uint16_t _conv1_stencil_5 = (uint16_t) (conv1_stencil.extract<64, 79>());
  uint16_t _conv1_stencil_6 = (uint16_t) (conv1_stencil.extract<80, 95>());
  uint16_t _conv1_stencil_7 = (uint16_t) (conv1_stencil.extract<96, 111>());
  uint16_t _conv1_stencil_8 = (uint16_t) (conv1_stencil.extract<112, 127>());
  uint16_t _conv1_stencil_9 = (uint16_t) (conv1_stencil.extract<128, 143>());

  uint16_t _conv2_stencil_1 = (uint16_t) (conv2_stencil.extract<0, 15>());

  uint16_t _450 = (uint16_t)(17);
  uint16_t _451 = _conv1_stencil_2 * _450;
  uint16_t _452 = (uint16_t)(7);
  uint16_t _453 = _conv1_stencil_3 * _452;
  uint16_t _454 = (uint16_t)(5);
  uint16_t _455 = _conv1_stencil_4 * _454;
  uint16_t _456 = (uint16_t)(4);
  uint16_t _457 = _conv1_stencil_5 * _456;
  uint16_t _458 = (uint16_t)(19);
  uint16_t _459 = _conv1_stencil_6 * _458;
  uint16_t _460 = (uint16_t)(21);
  uint16_t _461 = _conv1_stencil_7 * _460;
  uint16_t _462 = (uint16_t)(6);
  uint16_t _463 = _conv1_stencil_8 * _462;
  uint16_t _464 = (uint16_t)(15);
  uint16_t _465 = _conv1_stencil_9 * _464;
  uint16_t _466 = _conv1_stencil_10 * _456;
  uint16_t _467 = _465 + _466;
  uint16_t _468 = _463 + _467;
  uint16_t _469 = _461 + _468;
  uint16_t _470 = _459 + _469;
  uint16_t _471 = _457 + _470;
  uint16_t _472 = _455 + _471;
  uint16_t _473 = _453 + _472;
  uint16_t _474 = _conv2_stencil_1 + _473;
  uint16_t _475 = _451 + _474;
  return _475;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = conv2.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv2_stencil) {
  uint16_t _conv2_stencil_2 = (uint16_t) (conv2_stencil.extract<0, 15>());

  return _conv2_stencil_2;
}

