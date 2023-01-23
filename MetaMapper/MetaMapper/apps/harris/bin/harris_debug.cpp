)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_0.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0

 // alias the arguments
 Stencil<int16_t, 64, 64> &padded16_stencil = arg_0;
 Stencil<int16_t, 58, 58> &hw_output_stencil = arg_1;
[, ], [, ] // produce padded16_global_wrapper.stencil
 for (int padded16_global_wrapper_s0_y = -3; padded16_global_wrapper_s0_y < 61; padded16_global_wrapper_s0_y++)
 {
  for (int padded16_global_wrapper_s0_x = -3; padded16_global_wrapper_s0_x < 61; padded16_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _260 = _padded16_global_wrapper_s0_x + 3;
   int32_t _261 = _padded16_global_wrapper_s0_y + 3;
   int16_t _262 = _padded16_stencil(_padded16_global_wrapper_s0_x, _padded16_global_wrapper_s0_y);
   _padded16_global_wrapper_stencil(_260, _261) = _262;
  } // for padded16_global_wrapper_s0_x
 } // for padded16_global_wrapper_s0_y
 // consume padded16_global_wrapper.stencil
[, ], [, ] // produce grad_x_unclamp.stencil
 for (int grad_x_unclamp_s0_y = -2; grad_x_unclamp_s0_y < 60; grad_x_unclamp_s0_y++)
 {
  for (int grad_x_unclamp_s0_x = -2; grad_x_unclamp_s0_x < 60; grad_x_unclamp_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _265 = _grad_x_unclamp_s0_x + 2;
   int32_t _266 = _grad_x_unclamp_s0_y + 2;
   int16_t _267 = (int16_t)(0);
   _grad_x_unclamp_stencil(_265, _266) = _267;
  } // for grad_x_unclamp_s0_x
 } // for grad_x_unclamp_s0_y
 for (int grad_x_unclamp_s1_y = -2; grad_x_unclamp_s1_y < 60; grad_x_unclamp_s1_y++)
 {
  for (int grad_x_unclamp_s1_x = -2; grad_x_unclamp_s1_x < 60; grad_x_unclamp_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _286 = _grad_x_unclamp_s1_x + 2;
   int32_t _287 = _grad_x_unclamp_s1_y + 2;
   int16_t _288 = _grad_x_unclamp_stencil(_286, _287);
   int32_t _289 = _grad_x_unclamp_s1_x + 4;
   int16_t _290 = _padded16_global_wrapper_stencil(_289, _287);
   int32_t _291 = _grad_x_unclamp_s1_y + 4;
   int16_t _292 = _padded16_global_wrapper_stencil(_289, _291);
   int32_t _293 = _grad_x_unclamp_s1_y + 3;
   int16_t _294 = _padded16_global_wrapper_stencil(_289, _293);
   int16_t _295 = (int16_t)(2);
   int16_t _296 = _294 * _295;
   int16_t _297 = _292 + _296;
   int16_t _298 = _290 + _297;
   int16_t _299 = _288 + _298;
   int16_t _300 = _padded16_global_wrapper_stencil(_286, _287);
   int16_t _301 = _299 - _300;
   int16_t _302 = _padded16_global_wrapper_stencil(_286, _293);
   int16_t _303 = _302 * _295;
   int16_t _304 = _301 - _303;
   int16_t _305 = _padded16_global_wrapper_stencil(_286, _291);
   int16_t _306 = _304 - _305;
   _grad_x_unclamp_stencil(_286, _287) = _306;
  } // for grad_x_unclamp_s1_x
 } // for grad_x_unclamp_s1_y
 // consume grad_x_unclamp.stencil
[, ], [, ] // produce lxx.stencil
 for (int lxx_s0_y = -2; lxx_s0_y < 60; lxx_s0_y++)
 {
  for (int lxx_s0_x = -2; lxx_s0_x < 60; lxx_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _321 = _lxx_s0_x + 2;
   int32_t _322 = _lxx_s0_y + 2;
   int16_t _323 = _grad_x_unclamp_stencil(_321, _322);
   int16_t _324 = (int16_t)(180);
   int16_t _325 = ::halide_cpp_min(_323, _324);
   int16_t _326 = (int16_t)(-180);
   int16_t _327 = ::halide_cpp_max(_325, _326);
   int16_t _328 = _327 * _327;
   int16_t _329 = (int16_t)(6);
   int16_t _330 = _328 >> _329;
   _lxx_stencil(_321, _322) = _330;
  } // for lxx_s0_x
 } // for lxx_s0_y
 // consume lxx.stencil
[, ], [, ] // produce lgxx.stencil
 for (int lgxx_s0_y = -1; lgxx_s0_y < 59; lgxx_s0_y++)
 {
  for (int lgxx_s0_x = -1; lgxx_s0_x < 59; lgxx_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _333 = _lgxx_s0_x + 1;
   int32_t _334 = _lgxx_s0_y + 1;
   int16_t _335 = (int16_t)(0);
   _lgxx_stencil(_333, _334) = _335;
  } // for lgxx_s0_x
 } // for lgxx_s0_y
 for (int lgxx_s1_y = -1; lgxx_s1_y < 59; lgxx_s1_y++)
 {
  for (int lgxx_s1_x = -1; lgxx_s1_x < 59; lgxx_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _354 = _lgxx_s1_x + 1;
   int32_t _355 = _lgxx_s1_y + 1;
   int16_t _356 = _lxx_stencil(_354, _355);
   int16_t _357 = _lgxx_stencil(_354, _355);
   int32_t _358 = _lgxx_s1_x + 2;
   int16_t _359 = _lxx_stencil(_358, _355);
   int32_t _360 = _lgxx_s1_x + 3;
   int16_t _361 = _lxx_stencil(_360, _355);
   int32_t _362 = _lgxx_s1_y + 2;
   int16_t _363 = _lxx_stencil(_354, _362);
   int16_t _364 = _lxx_stencil(_358, _362);
   int16_t _365 = _lxx_stencil(_360, _362);
   int32_t _366 = _lgxx_s1_y + 3;
   int16_t _367 = _lxx_stencil(_354, _366);
   int16_t _368 = _lxx_stencil(_360, _366);
   int16_t _369 = _lxx_stencil(_358, _366);
   int16_t _370 = _368 + _369;
   int16_t _371 = _367 + _370;
   int16_t _372 = _365 + _371;
   int16_t _373 = _364 + _372;
   int16_t _374 = _363 + _373;
   int16_t _375 = _361 + _374;
   int16_t _376 = _359 + _375;
   int16_t _377 = _357 + _376;
   int16_t _378 = _356 + _377;
   _lgxx_stencil(_354, _355) = _378;
  } // for lgxx_s1_x
 } // for lgxx_s1_y
 // consume lgxx.stencil
[, ], [, ] // produce grad_y_unclamp.stencil
 for (int grad_y_unclamp_s0_y = -2; grad_y_unclamp_s0_y < 60; grad_y_unclamp_s0_y++)
 {
  for (int grad_y_unclamp_s0_x = -2; grad_y_unclamp_s0_x < 60; grad_y_unclamp_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _381 = _grad_y_unclamp_s0_x + 2;
   int32_t _382 = _grad_y_unclamp_s0_y + 2;
   int16_t _383 = (int16_t)(0);
   _grad_y_unclamp_stencil(_381, _382) = _383;
  } // for grad_y_unclamp_s0_x
 } // for grad_y_unclamp_s0_y
 for (int grad_y_unclamp_s1_y = -2; grad_y_unclamp_s1_y < 60; grad_y_unclamp_s1_y++)
 {
  for (int grad_y_unclamp_s1_x = -2; grad_y_unclamp_s1_x < 60; grad_y_unclamp_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _402 = _grad_y_unclamp_s1_x + 2;
   int32_t _403 = _grad_y_unclamp_s1_y + 2;
   int16_t _404 = _grad_y_unclamp_stencil(_402, _403);
   int32_t _405 = _grad_y_unclamp_s1_y + 4;
   int16_t _406 = _padded16_global_wrapper_stencil(_402, _405);
   int32_t _407 = _grad_y_unclamp_s1_x + 4;
   int16_t _408 = _padded16_global_wrapper_stencil(_407, _405);
   int32_t _409 = _grad_y_unclamp_s1_x + 3;
   int16_t _410 = _padded16_global_wrapper_stencil(_409, _405);
   int16_t _411 = (int16_t)(2);
   int16_t _412 = _410 * _411;
   int16_t _413 = _408 + _412;
   int16_t _414 = _406 + _413;
   int16_t _415 = _404 + _414;
   int16_t _416 = _padded16_global_wrapper_stencil(_402, _403);
   int16_t _417 = _415 - _416;
   int16_t _418 = _padded16_global_wrapper_stencil(_409, _403);
   int16_t _419 = _418 * _411;
   int16_t _420 = _417 - _419;
   int16_t _421 = _padded16_global_wrapper_stencil(_407, _403);
   int16_t _422 = _420 - _421;
   _grad_y_unclamp_stencil(_402, _403) = _422;
  } // for grad_y_unclamp_s1_x
 } // for grad_y_unclamp_s1_y
 // consume grad_y_unclamp.stencil
[, ], [, ] // produce lxy.stencil
 for (int lxy_s0_y = -2; lxy_s0_y < 60; lxy_s0_y++)
 {
  for (int lxy_s0_x = -2; lxy_s0_x < 60; lxy_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _441 = _lxy_s0_x + 2;
   int32_t _442 = _lxy_s0_y + 2;
   int16_t _443 = _grad_x_unclamp_stencil(_441, _442);
   int16_t _444 = (int16_t)(180);
   int16_t _445 = ::halide_cpp_min(_443, _444);
   int16_t _446 = (int16_t)(-180);
   int16_t _447 = ::halide_cpp_max(_445, _446);
   int16_t _448 = _grad_y_unclamp_stencil(_441, _442);
   int16_t _449 = ::halide_cpp_min(_448, _444);
   int16_t _450 = ::halide_cpp_max(_449, _446);
   int16_t _451 = _447 * _450;
   int16_t _452 = (int16_t)(6);
   int16_t _453 = _451 >> _452;
   _lxy_stencil(_441, _442) = _453;
  } // for lxy_s0_x
 } // for lxy_s0_y
 // consume lxy.stencil
[, ], [, ] // produce lgxy.stencil
 for (int lgxy_s0_y = -1; lgxy_s0_y < 59; lgxy_s0_y++)
 {
  for (int lgxy_s0_x = -1; lgxy_s0_x < 59; lgxy_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _456 = _lgxy_s0_x + 1;
   int32_t _457 = _lgxy_s0_y + 1;
   int16_t _458 = (int16_t)(0);
   _lgxy_stencil(_456, _457) = _458;
  } // for lgxy_s0_x
 } // for lgxy_s0_y
 for (int lgxy_s1_y = -1; lgxy_s1_y < 59; lgxy_s1_y++)
 {
  for (int lgxy_s1_x = -1; lgxy_s1_x < 59; lgxy_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _477 = _lgxy_s1_x + 1;
   int32_t _478 = _lgxy_s1_y + 1;
   int16_t _479 = _lxy_stencil(_477, _478);
   int16_t _480 = _lgxy_stencil(_477, _478);
   int32_t _481 = _lgxy_s1_x + 2;
   int16_t _482 = _lxy_stencil(_481, _478);
   int32_t _483 = _lgxy_s1_x + 3;
   int16_t _484 = _lxy_stencil(_483, _478);
   int32_t _485 = _lgxy_s1_y + 2;
   int16_t _486 = _lxy_stencil(_477, _485);
   int16_t _487 = _lxy_stencil(_481, _485);
   int16_t _488 = _lxy_stencil(_483, _485);
   int32_t _489 = _lgxy_s1_y + 3;
   int16_t _490 = _lxy_stencil(_477, _489);
   int16_t _491 = _lxy_stencil(_483, _489);
   int16_t _492 = _lxy_stencil(_481, _489);
   int16_t _493 = _491 + _492;
   int16_t _494 = _490 + _493;
   int16_t _495 = _488 + _494;
   int16_t _496 = _487 + _495;
   int16_t _497 = _486 + _496;
   int16_t _498 = _484 + _497;
   int16_t _499 = _482 + _498;
   int16_t _500 = _480 + _499;
   int16_t _501 = _479 + _500;
   _lgxy_stencil(_477, _478) = _501;
  } // for lgxy_s1_x
 } // for lgxy_s1_y
 // consume lgxy.stencil
[, ], [, ] // produce lyy.stencil
 for (int lyy_s0_y = -2; lyy_s0_y < 60; lyy_s0_y++)
 {
  for (int lyy_s0_x = -2; lyy_s0_x < 60; lyy_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _516 = _lyy_s0_x + 2;
   int32_t _517 = _lyy_s0_y + 2;
   int16_t _518 = _grad_y_unclamp_stencil(_516, _517);
   int16_t _519 = (int16_t)(180);
   int16_t _520 = ::halide_cpp_min(_518, _519);
   int16_t _521 = (int16_t)(-180);
   int16_t _522 = ::halide_cpp_max(_520, _521);
   int16_t _523 = _522 * _522;
   int16_t _524 = (int16_t)(6);
   int16_t _525 = _523 >> _524;
   _lyy_stencil(_516, _517) = _525;
  } // for lyy_s0_x
 } // for lyy_s0_y
 // consume lyy.stencil
[, ], [, ] // produce lgyy.stencil
 for (int lgyy_s0_y = -1; lgyy_s0_y < 59; lgyy_s0_y++)
 {
  for (int lgyy_s0_x = -1; lgyy_s0_x < 59; lgyy_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _528 = _lgyy_s0_x + 1;
   int32_t _529 = _lgyy_s0_y + 1;
   int16_t _530 = (int16_t)(0);
   _lgyy_stencil(_528, _529) = _530;
  } // for lgyy_s0_x
 } // for lgyy_s0_y
 for (int lgyy_s1_y = -1; lgyy_s1_y < 59; lgyy_s1_y++)
 {
  for (int lgyy_s1_x = -1; lgyy_s1_x < 59; lgyy_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _549 = _lgyy_s1_x + 1;
   int32_t _550 = _lgyy_s1_y + 1;
   int16_t _551 = _lyy_stencil(_549, _550);
   int16_t _552 = _lgyy_stencil(_549, _550);
   int32_t _553 = _lgyy_s1_x + 2;
   int16_t _554 = _lyy_stencil(_553, _550);
   int32_t _555 = _lgyy_s1_x + 3;
   int16_t _556 = _lyy_stencil(_555, _550);
   int32_t _557 = _lgyy_s1_y + 2;
   int16_t _558 = _lyy_stencil(_549, _557);
   int16_t _559 = _lyy_stencil(_553, _557);
   int16_t _560 = _lyy_stencil(_555, _557);
   int32_t _561 = _lgyy_s1_y + 3;
   int16_t _562 = _lyy_stencil(_549, _561);
   int16_t _563 = _lyy_stencil(_555, _561);
   int16_t _564 = _lyy_stencil(_553, _561);
   int16_t _565 = _563 + _564;
   int16_t _566 = _562 + _565;
   int16_t _567 = _560 + _566;
   int16_t _568 = _559 + _567;
   int16_t _569 = _558 + _568;
   int16_t _570 = _556 + _569;
   int16_t _571 = _554 + _570;
   int16_t _572 = _552 + _571;
   int16_t _573 = _551 + _572;
   _lgyy_stencil(_549, _550) = _573;
  } // for lgyy_s1_x
 } // for lgyy_s1_y
 // consume lgyy.stencil
[, ], [, ] // produce cim.stencil
 for (int cim_s0_y = -1; cim_s0_y < 59; cim_s0_y++)
 {
  for (int cim_s0_x = -1; cim_s0_x < 59; cim_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _598 = _cim_s0_x + 1;
   int32_t _599 = _cim_s0_y + 1;
   int16_t _600 = _lgxx_stencil(_598, _599);
   int16_t _601 = (int16_t)(6);
   int16_t _602 = _600 >> _601;
   int16_t _603 = _lgyy_stencil(_598, _599);
   int16_t _604 = _603 >> _601;
   int16_t _605 = _602 * _604;
   int16_t _606 = _lgxy_stencil(_598, _599);
   int16_t _607 = _606 >> _601;
   int16_t _608 = _607 * _607;
   int16_t _609 = _605 - _608;
   int16_t _610 = _602 + _604;
   int16_t _611 = _610 * _610;
   int16_t _612 = (int16_t)(4);
   int16_t _613 = _611 >> _612;
   int16_t _614 = _609 - _613;
   _cim_stencil(_598, _599) = _614;
  } // for cim_s0_x
 } // for cim_s0_y
 // consume cim.stencil
[, ], [, ] // produce cim_output.stencil
 for (int cim_output_s0_y = 0; cim_output_s0_y < 58; cim_output_s0_y++)
 {
  for (int cim_output_s0_x = 0; cim_output_s0_x < 58; cim_output_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _655 = _cim_stencil(_cim_output_s0_x, _cim_output_s0_y);
   int32_t _656 = _cim_output_s0_x + 1;
   int32_t _657 = _cim_output_s0_y + 1;
   int16_t _658 = _cim_stencil(_656, _657);
   bool _659 = _655 < _658;
   int16_t _660 = _cim_stencil(_656, _cim_output_s0_y);
   bool _661 = _660 < _658;
   bool _662 = _659 && _661;
   int32_t _663 = _cim_output_s0_x + 2;
   int16_t _664 = _cim_stencil(_663, _cim_output_s0_y);
   bool _665 = _664 < _658;
   bool _666 = _662 && _665;
   int16_t _667 = _cim_stencil(_cim_output_s0_x, _657);
   bool _668 = _667 < _658;
   bool _669 = _666 && _668;
   int16_t _670 = _cim_stencil(_663, _657);
   bool _671 = _670 < _658;
   bool _672 = _669 && _671;
   int32_t _673 = _cim_output_s0_y + 2;
   int16_t _674 = _cim_stencil(_cim_output_s0_x, _673);
   bool _675 = _674 < _658;
   bool _676 = _672 && _675;
   int16_t _677 = _cim_stencil(_656, _673);
   bool _678 = _677 < _658;
   bool _679 = _676 && _678;
   int16_t _680 = _cim_stencil(_663, _673);
   bool _681 = _680 < _658;
   bool _682 = _679 && _681;
   int16_t _683 = (int16_t)(1);
   bool _684 = _683 <= _658;
   bool _685 = _682 && _684;
   int32_t _686 = (int32_t)(_685 ? 255 : 0);
   int16_t _687 = (int16_t)(_686);
   _cim_output_stencil(_cim_output_s0_x, _cim_output_s0_y) = _687;
  } // for cim_output_s0_x
 } // for cim_output_s0_y
 // consume cim_output.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 58; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 58; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   int16_t _688 = _cim_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _688;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetharris

