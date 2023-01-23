#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  uint16_t _hw_input_stencil_1 = (uint16_t) (hw_input_stencil.extract<0, 15>());

  return _hw_input_stencil_1;
}

//store is: conv.stencil(conv_s0_x, conv_s0_y) = (uint16)0
hw_uint<16> hcompute_conv_stencil() {
  uint16_t _257 = (uint16_t)(0);
  return _257;
}

//store is: conv.stencil(conv_s1_x, conv_s1_y) = ((hw_input_global_wrapper.stencil(conv_s1_x, conv_s1_y)*(uint16)11) + (conv.stencil(conv_s1_x, conv_s1_y) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), conv_s1_y)*(uint16)14) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), conv_s1_y)*(uint16)17) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), conv_s1_y)*(uint16)20) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), conv_s1_y)*(uint16)30) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), conv_s1_y)*(uint16)40) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), conv_s1_y)*(uint16)50) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 1))*(uint16)12) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 1))*(uint16)18) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 1))*(uint16)29) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 1))*(uint16)39) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 1))*(uint16)49) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 1))*(uint16)59) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 2))*(uint16)13) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 2))*(uint16)16) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 2))*(uint16)19) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 2))*(uint16)22) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 2))*(uint16)32) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 2))*(uint16)42) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 2))*(uint16)52) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 3))*(uint16)23) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 3))*(uint16)21) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 3))*(uint16)26) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 3))*(uint16)24) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 3))*(uint16)34) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 3))*(uint16)44) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 3))*(uint16)54) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 4))*(uint16)33) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 4))*(uint16)31) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 4))*(uint16)32) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 4))*(uint16)34) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 4))*(uint16)37) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 4))*(uint16)47) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 4))*(uint16)57) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 5))*(uint16)43) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 5))*(uint16)41) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 5))*(uint16)42) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 5))*(uint16)44) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 5))*(uint16)47) + ((hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 5))*(uint16)48) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 5))*(uint16)58) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 6))*(uint16)53) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 6))*(uint16)51) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 6))*(uint16)52) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 6))*(uint16)54) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 6))*(uint16)57) + ((hw_input_global_wrapper.stencil((conv_s1_x + 6), (conv_s1_y + 6))*(uint16)54) + (hw_input_global_wrapper.stencil((conv_s1_x + 5), (conv_s1_y + 6))*(uint16)58)))))))))))))))))))))))))))))))))))))))))))))))))
hw_uint<16> hcompute_conv_stencil_1(hw_uint<16>& conv_stencil, hw_uint<768>& hw_input_global_wrapper_stencil) {
  uint16_t _conv_stencil_1 = (uint16_t) (conv_stencil.extract<0, 15>());

  uint16_t _hw_input_global_wrapper_stencil_1 = (uint16_t) (hw_input_global_wrapper_stencil.extract<0, 15>());
  uint16_t _hw_input_global_wrapper_stencil_10 = (uint16_t) (hw_input_global_wrapper_stencil.extract<16, 31>());
  uint16_t _hw_input_global_wrapper_stencil_11 = (uint16_t) (hw_input_global_wrapper_stencil.extract<32, 47>());
  uint16_t _hw_input_global_wrapper_stencil_12 = (uint16_t) (hw_input_global_wrapper_stencil.extract<48, 63>());
  uint16_t _hw_input_global_wrapper_stencil_13 = (uint16_t) (hw_input_global_wrapper_stencil.extract<64, 79>());
  uint16_t _hw_input_global_wrapper_stencil_14 = (uint16_t) (hw_input_global_wrapper_stencil.extract<80, 95>());
  uint16_t _hw_input_global_wrapper_stencil_15 = (uint16_t) (hw_input_global_wrapper_stencil.extract<96, 111>());
  uint16_t _hw_input_global_wrapper_stencil_16 = (uint16_t) (hw_input_global_wrapper_stencil.extract<112, 127>());
  uint16_t _hw_input_global_wrapper_stencil_17 = (uint16_t) (hw_input_global_wrapper_stencil.extract<128, 143>());
  uint16_t _hw_input_global_wrapper_stencil_18 = (uint16_t) (hw_input_global_wrapper_stencil.extract<144, 159>());
  uint16_t _hw_input_global_wrapper_stencil_19 = (uint16_t) (hw_input_global_wrapper_stencil.extract<160, 175>());
  uint16_t _hw_input_global_wrapper_stencil_2 = (uint16_t) (hw_input_global_wrapper_stencil.extract<176, 191>());
  uint16_t _hw_input_global_wrapper_stencil_20 = (uint16_t) (hw_input_global_wrapper_stencil.extract<192, 207>());
  uint16_t _hw_input_global_wrapper_stencil_21 = (uint16_t) (hw_input_global_wrapper_stencil.extract<208, 223>());
  uint16_t _hw_input_global_wrapper_stencil_22 = (uint16_t) (hw_input_global_wrapper_stencil.extract<224, 239>());
  uint16_t _hw_input_global_wrapper_stencil_23 = (uint16_t) (hw_input_global_wrapper_stencil.extract<240, 255>());
  uint16_t _hw_input_global_wrapper_stencil_24 = (uint16_t) (hw_input_global_wrapper_stencil.extract<256, 271>());
  uint16_t _hw_input_global_wrapper_stencil_25 = (uint16_t) (hw_input_global_wrapper_stencil.extract<272, 287>());
  uint16_t _hw_input_global_wrapper_stencil_26 = (uint16_t) (hw_input_global_wrapper_stencil.extract<288, 303>());
  uint16_t _hw_input_global_wrapper_stencil_27 = (uint16_t) (hw_input_global_wrapper_stencil.extract<304, 319>());
  uint16_t _hw_input_global_wrapper_stencil_28 = (uint16_t) (hw_input_global_wrapper_stencil.extract<320, 335>());
  uint16_t _hw_input_global_wrapper_stencil_29 = (uint16_t) (hw_input_global_wrapper_stencil.extract<336, 351>());
  uint16_t _hw_input_global_wrapper_stencil_3 = (uint16_t) (hw_input_global_wrapper_stencil.extract<352, 367>());
  uint16_t _hw_input_global_wrapper_stencil_30 = (uint16_t) (hw_input_global_wrapper_stencil.extract<368, 383>());
  uint16_t _hw_input_global_wrapper_stencil_31 = (uint16_t) (hw_input_global_wrapper_stencil.extract<384, 399>());
  uint16_t _hw_input_global_wrapper_stencil_32 = (uint16_t) (hw_input_global_wrapper_stencil.extract<400, 415>());
  uint16_t _hw_input_global_wrapper_stencil_33 = (uint16_t) (hw_input_global_wrapper_stencil.extract<416, 431>());
  uint16_t _hw_input_global_wrapper_stencil_34 = (uint16_t) (hw_input_global_wrapper_stencil.extract<432, 447>());
  uint16_t _hw_input_global_wrapper_stencil_35 = (uint16_t) (hw_input_global_wrapper_stencil.extract<448, 463>());
  uint16_t _hw_input_global_wrapper_stencil_36 = (uint16_t) (hw_input_global_wrapper_stencil.extract<464, 479>());
  uint16_t _hw_input_global_wrapper_stencil_37 = (uint16_t) (hw_input_global_wrapper_stencil.extract<480, 495>());
  uint16_t _hw_input_global_wrapper_stencil_38 = (uint16_t) (hw_input_global_wrapper_stencil.extract<496, 511>());
  uint16_t _hw_input_global_wrapper_stencil_39 = (uint16_t) (hw_input_global_wrapper_stencil.extract<512, 527>());
  uint16_t _hw_input_global_wrapper_stencil_4 = (uint16_t) (hw_input_global_wrapper_stencil.extract<528, 543>());
  uint16_t _hw_input_global_wrapper_stencil_40 = (uint16_t) (hw_input_global_wrapper_stencil.extract<544, 559>());
  uint16_t _hw_input_global_wrapper_stencil_41 = (uint16_t) (hw_input_global_wrapper_stencil.extract<560, 575>());
  uint16_t _hw_input_global_wrapper_stencil_42 = (uint16_t) (hw_input_global_wrapper_stencil.extract<576, 591>());
  uint16_t _hw_input_global_wrapper_stencil_43 = (uint16_t) (hw_input_global_wrapper_stencil.extract<592, 607>());
  uint16_t _hw_input_global_wrapper_stencil_44 = (uint16_t) (hw_input_global_wrapper_stencil.extract<608, 623>());
  uint16_t _hw_input_global_wrapper_stencil_45 = (uint16_t) (hw_input_global_wrapper_stencil.extract<624, 639>());
  uint16_t _hw_input_global_wrapper_stencil_46 = (uint16_t) (hw_input_global_wrapper_stencil.extract<640, 655>());
  uint16_t _hw_input_global_wrapper_stencil_47 = (uint16_t) (hw_input_global_wrapper_stencil.extract<656, 671>());
  uint16_t _hw_input_global_wrapper_stencil_48 = (uint16_t) (hw_input_global_wrapper_stencil.extract<672, 687>());
  uint16_t _hw_input_global_wrapper_stencil_5 = (uint16_t) (hw_input_global_wrapper_stencil.extract<688, 703>());
  uint16_t _hw_input_global_wrapper_stencil_6 = (uint16_t) (hw_input_global_wrapper_stencil.extract<704, 719>());
  uint16_t _hw_input_global_wrapper_stencil_7 = (uint16_t) (hw_input_global_wrapper_stencil.extract<720, 735>());
  uint16_t _hw_input_global_wrapper_stencil_8 = (uint16_t) (hw_input_global_wrapper_stencil.extract<736, 751>());
  uint16_t _hw_input_global_wrapper_stencil_9 = (uint16_t) (hw_input_global_wrapper_stencil.extract<752, 767>());

  uint16_t _260 = (uint16_t)(11);
  uint16_t _261 = _hw_input_global_wrapper_stencil_1 * _260;
  uint16_t _262 = (uint16_t)(14);
  uint16_t _263 = _hw_input_global_wrapper_stencil_2 * _262;
  uint16_t _264 = (uint16_t)(17);
  uint16_t _265 = _hw_input_global_wrapper_stencil_3 * _264;
  uint16_t _266 = (uint16_t)(20);
  uint16_t _267 = _hw_input_global_wrapper_stencil_4 * _266;
  uint16_t _268 = (uint16_t)(30);
  uint16_t _269 = _hw_input_global_wrapper_stencil_5 * _268;
  uint16_t _270 = (uint16_t)(40);
  uint16_t _271 = _hw_input_global_wrapper_stencil_6 * _270;
  uint16_t _272 = (uint16_t)(50);
  uint16_t _273 = _hw_input_global_wrapper_stencil_7 * _272;
  uint16_t _274 = (uint16_t)(12);
  uint16_t _275 = _hw_input_global_wrapper_stencil_8 * _274;
  uint16_t _276 = (uint16_t)(18);
  uint16_t _277 = _hw_input_global_wrapper_stencil_9 * _276;
  uint16_t _278 = (uint16_t)(29);
  uint16_t _279 = _hw_input_global_wrapper_stencil_10 * _278;
  uint16_t _280 = (uint16_t)(39);
  uint16_t _281 = _hw_input_global_wrapper_stencil_11 * _280;
  uint16_t _282 = (uint16_t)(49);
  uint16_t _283 = _hw_input_global_wrapper_stencil_12 * _282;
  uint16_t _284 = (uint16_t)(59);
  uint16_t _285 = _hw_input_global_wrapper_stencil_13 * _284;
  uint16_t _286 = (uint16_t)(13);
  uint16_t _287 = _hw_input_global_wrapper_stencil_14 * _286;
  uint16_t _288 = (uint16_t)(16);
  uint16_t _289 = _hw_input_global_wrapper_stencil_15 * _288;
  uint16_t _290 = (uint16_t)(19);
  uint16_t _291 = _hw_input_global_wrapper_stencil_16 * _290;
  uint16_t _292 = (uint16_t)(22);
  uint16_t _293 = _hw_input_global_wrapper_stencil_17 * _292;
  uint16_t _294 = (uint16_t)(32);
  uint16_t _295 = _hw_input_global_wrapper_stencil_18 * _294;
  uint16_t _296 = (uint16_t)(42);
  uint16_t _297 = _hw_input_global_wrapper_stencil_19 * _296;
  uint16_t _298 = (uint16_t)(52);
  uint16_t _299 = _hw_input_global_wrapper_stencil_20 * _298;
  uint16_t _300 = (uint16_t)(23);
  uint16_t _301 = _hw_input_global_wrapper_stencil_21 * _300;
  uint16_t _302 = (uint16_t)(21);
  uint16_t _303 = _hw_input_global_wrapper_stencil_22 * _302;
  uint16_t _304 = (uint16_t)(26);
  uint16_t _305 = _hw_input_global_wrapper_stencil_23 * _304;
  uint16_t _306 = (uint16_t)(24);
  uint16_t _307 = _hw_input_global_wrapper_stencil_24 * _306;
  uint16_t _308 = (uint16_t)(34);
  uint16_t _309 = _hw_input_global_wrapper_stencil_25 * _308;
  uint16_t _310 = (uint16_t)(44);
  uint16_t _311 = _hw_input_global_wrapper_stencil_26 * _310;
  uint16_t _312 = (uint16_t)(54);
  uint16_t _313 = _hw_input_global_wrapper_stencil_27 * _312;
  uint16_t _314 = (uint16_t)(33);
  uint16_t _315 = _hw_input_global_wrapper_stencil_28 * _314;
  uint16_t _316 = (uint16_t)(31);
  uint16_t _317 = _hw_input_global_wrapper_stencil_29 * _316;
  uint16_t _318 = _hw_input_global_wrapper_stencil_30 * _294;
  uint16_t _319 = _hw_input_global_wrapper_stencil_31 * _308;
  uint16_t _320 = (uint16_t)(37);
  uint16_t _321 = _hw_input_global_wrapper_stencil_32 * _320;
  uint16_t _322 = (uint16_t)(47);
  uint16_t _323 = _hw_input_global_wrapper_stencil_33 * _322;
  uint16_t _324 = (uint16_t)(57);
  uint16_t _325 = _hw_input_global_wrapper_stencil_34 * _324;
  uint16_t _326 = (uint16_t)(43);
  uint16_t _327 = _hw_input_global_wrapper_stencil_35 * _326;
  uint16_t _328 = (uint16_t)(41);
  uint16_t _329 = _hw_input_global_wrapper_stencil_36 * _328;
  uint16_t _330 = _hw_input_global_wrapper_stencil_37 * _296;
  uint16_t _331 = _hw_input_global_wrapper_stencil_38 * _310;
  uint16_t _332 = _hw_input_global_wrapper_stencil_39 * _322;
  uint16_t _333 = (uint16_t)(48);
  uint16_t _334 = _hw_input_global_wrapper_stencil_40 * _333;
  uint16_t _335 = (uint16_t)(58);
  uint16_t _336 = _hw_input_global_wrapper_stencil_41 * _335;
  uint16_t _337 = (uint16_t)(53);
  uint16_t _338 = _hw_input_global_wrapper_stencil_42 * _337;
  uint16_t _339 = (uint16_t)(51);
  uint16_t _340 = _hw_input_global_wrapper_stencil_43 * _339;
  uint16_t _341 = _hw_input_global_wrapper_stencil_44 * _298;
  uint16_t _342 = _hw_input_global_wrapper_stencil_45 * _312;
  uint16_t _343 = _hw_input_global_wrapper_stencil_46 * _324;
  uint16_t _344 = _hw_input_global_wrapper_stencil_47 * _312;
  uint16_t _345 = _hw_input_global_wrapper_stencil_48 * _335;
  uint16_t _346 = _344 + _345;
  uint16_t _347 = _343 + _346;
  uint16_t _348 = _342 + _347;
  uint16_t _349 = _341 + _348;
  uint16_t _350 = _340 + _349;
  uint16_t _351 = _338 + _350;
  uint16_t _352 = _336 + _351;
  uint16_t _353 = _334 + _352;
  uint16_t _354 = _332 + _353;
  uint16_t _355 = _331 + _354;
  uint16_t _356 = _330 + _355;
  uint16_t _357 = _329 + _356;
  uint16_t _358 = _327 + _357;
  uint16_t _359 = _325 + _358;
  uint16_t _360 = _323 + _359;
  uint16_t _361 = _321 + _360;
  uint16_t _362 = _319 + _361;
  uint16_t _363 = _318 + _362;
  uint16_t _364 = _317 + _363;
  uint16_t _365 = _315 + _364;
  uint16_t _366 = _313 + _365;
  uint16_t _367 = _311 + _366;
  uint16_t _368 = _309 + _367;
  uint16_t _369 = _307 + _368;
  uint16_t _370 = _305 + _369;
  uint16_t _371 = _303 + _370;
  uint16_t _372 = _301 + _371;
  uint16_t _373 = _299 + _372;
  uint16_t _374 = _297 + _373;
  uint16_t _375 = _295 + _374;
  uint16_t _376 = _293 + _375;
  uint16_t _377 = _291 + _376;
  uint16_t _378 = _289 + _377;
  uint16_t _379 = _287 + _378;
  uint16_t _380 = _285 + _379;
  uint16_t _381 = _283 + _380;
  uint16_t _382 = _281 + _381;
  uint16_t _383 = _279 + _382;
  uint16_t _384 = _277 + _383;
  uint16_t _385 = _275 + _384;
  uint16_t _386 = _273 + _385;
  uint16_t _387 = _271 + _386;
  uint16_t _388 = _269 + _387;
  uint16_t _389 = _267 + _388;
  uint16_t _390 = _265 + _389;
  uint16_t _391 = _263 + _390;
  uint16_t _392 = _conv_stencil_1 + _391;
  uint16_t _393 = _261 + _392;
  return _393;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& conv_stencil) {
  uint16_t _conv_stencil_2 = (uint16_t) (conv_stencil.extract<0, 15>());

  return _conv_stencil_2;
}

