)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_2 bundle=config
#pragma HLS INTERFACE s_axilite port=arg_3 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_3.value complete dim=0

 // alias the arguments
  Stencil<int16_t, 3, 1104, 2556> &hw_input_stencil = arg_1;
  Stencil<int16_t, 610, 2550> &hw_output_global_wrapper_stencil = arg_3;
[, ], [, ], [, ] // produce hw_input_global_wrapper.glb.stencil
 int32_t _330 = 0 + -3;
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 261; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x_x = 0; hw_input_global_wrapper_s0_x_x < 64; hw_input_global_wrapper_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _331 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _332 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _333 = _332 + 3;
   int32_t _334 = 0 * 61;
   int32_t _335 = _hw_input_global_wrapper_s0_x_x + _334;
   int32_t _336 = _335 * 2;
   int32_t _337 = _336 + -3;
   int16_t _338 = _hw_input_stencil(0, _337, _332);
   _hw_input_global_wrapper_glb_stencil(0, _331, _333) = _338;
   int32_t _339 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _340 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _341 = _340 + 3;
   int32_t _342 = 0 * 61;
   int32_t _343 = _hw_input_global_wrapper_s0_x_x + _342;
   int32_t _344 = _343 * 2;
   int32_t _345 = _344 + -3;
   int16_t _346 = _hw_input_stencil(1, _345, _340);
   _hw_input_global_wrapper_glb_stencil(1, _339, _341) = _346;
   int32_t _347 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _348 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _349 = _348 + 3;
   int32_t _350 = 0 * 61;
   int32_t _351 = _hw_input_global_wrapper_s0_x_x + _350;
   int32_t _352 = _351 * 2;
   int32_t _353 = _352 + -3;
   int16_t _354 = _hw_input_stencil(2, _353, _348);
   _hw_input_global_wrapper_glb_stencil(2, _347, _349) = _354;
   int32_t _355 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _356 = _355 + 1;
   int32_t _357 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _358 = _357 + 3;
   int32_t _359 = 0 * 61;
   int32_t _360 = _hw_input_global_wrapper_s0_x_x + _359;
   int32_t _361 = _360 * 2;
   int32_t _362 = _361 + -2;
   int16_t _363 = _hw_input_stencil(0, _362, _357);
   _hw_input_global_wrapper_glb_stencil(0, _356, _358) = _363;
   int32_t _364 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _365 = _364 + 1;
   int32_t _366 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _367 = _366 + 3;
   int32_t _368 = 0 * 61;
   int32_t _369 = _hw_input_global_wrapper_s0_x_x + _368;
   int32_t _370 = _369 * 2;
   int32_t _371 = _370 + -2;
   int16_t _372 = _hw_input_stencil(1, _371, _366);
   _hw_input_global_wrapper_glb_stencil(1, _365, _367) = _372;
   int32_t _373 = _hw_input_global_wrapper_s0_x_x * 2;
   int32_t _374 = _373 + 1;
   int32_t _375 = _hw_input_global_wrapper_s0_y + -3;
   int32_t _376 = _375 + 3;
   int32_t _377 = 0 * 61;
   int32_t _378 = _hw_input_global_wrapper_s0_x_x + _377;
   int32_t _379 = _378 * 2;
   int32_t _380 = _379 + -2;
   int16_t _381 = _hw_input_stencil(2, _380, _375);
   _hw_input_global_wrapper_glb_stencil(2, _374, _376) = _381;
  } // for hw_input_global_wrapper_s0_x_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.glb.stencil
[, ], [, ] // produce hw_output.glb.stencil
[, ], [, ], [, ] // produce hw_input_global_wrapper_global_wrapper.stencil
 int32_t _382 = 0 + -3;
 for (int hw_input_global_wrapper_global_wrapper_s0_y = 0; hw_input_global_wrapper_global_wrapper_s0_y < 261; hw_input_global_wrapper_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_global_wrapper_s0_x_x = 0; hw_input_global_wrapper_global_wrapper_s0_x_x < 64; hw_input_global_wrapper_global_wrapper_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _383 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _384 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _385 = _384 + 3;
   int16_t _386 = _hw_input_global_wrapper_glb_stencil(0, _383, _385);
   _hw_input_global_wrapper_global_wrapper_stencil(0, _383, _385) = _386;
   int32_t _387 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _388 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _389 = _388 + 3;
   int16_t _390 = _hw_input_global_wrapper_glb_stencil(1, _387, _389);
   _hw_input_global_wrapper_global_wrapper_stencil(1, _387, _389) = _390;
   int32_t _391 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _392 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _393 = _392 + 3;
   int16_t _394 = _hw_input_global_wrapper_glb_stencil(2, _391, _393);
   _hw_input_global_wrapper_global_wrapper_stencil(2, _391, _393) = _394;
   int32_t _395 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _396 = _395 + 1;
   int32_t _397 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _398 = _397 + 3;
   int16_t _399 = _hw_input_global_wrapper_glb_stencil(0, _396, _398);
   _hw_input_global_wrapper_global_wrapper_stencil(0, _396, _398) = _399;
   int32_t _400 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _401 = _400 + 1;
   int32_t _402 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _403 = _402 + 3;
   int16_t _404 = _hw_input_global_wrapper_glb_stencil(1, _401, _403);
   _hw_input_global_wrapper_global_wrapper_stencil(1, _401, _403) = _404;
   int32_t _405 = _hw_input_global_wrapper_global_wrapper_s0_x_x * 2;
   int32_t _406 = _405 + 1;
   int32_t _407 = _hw_input_global_wrapper_global_wrapper_s0_y + -3;
   int32_t _408 = _407 + 3;
   int16_t _409 = _hw_input_global_wrapper_glb_stencil(2, _406, _408);
   _hw_input_global_wrapper_global_wrapper_stencil(2, _406, _408) = _409;
  } // for hw_input_global_wrapper_global_wrapper_s0_x_x
 } // for hw_input_global_wrapper_global_wrapper_s0_y
 // consume hw_input_global_wrapper_global_wrapper.stencil
[, ], [, ] // produce gray.stencil
 int32_t _410 = 0 + -3;
 for (int gray_s0_y = 0; gray_s0_y < 261; gray_s0_y++)
 {
  for (int gray_s0_x_x = 0; gray_s0_x_x < 64; gray_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _437 = _gray_s0_x_x * 2;
   int32_t _438 = _gray_s0_y + -3;
   int32_t _439 = _438 + 3;
   int16_t _440 = _hw_input_global_wrapper_global_wrapper_stencil(1, _437, _439);
   uint16_t _441 = (uint16_t)(_440);
   uint16_t _442 = (uint16_t)(150);
   uint16_t _443 = _441 * _442;
   int16_t _444 = _hw_input_global_wrapper_global_wrapper_stencil(2, _437, _439);
   uint16_t _445 = (uint16_t)(_444);
   uint16_t _446 = (uint16_t)(29);
   uint16_t _447 = _445 * _446;
   int16_t _448 = _hw_input_global_wrapper_global_wrapper_stencil(0, _437, _439);
   uint16_t _449 = (uint16_t)(_448);
   uint16_t _450 = (uint16_t)(77);
   uint16_t _451 = _449 * _450;
   uint16_t _452 = _447 + _451;
   uint16_t _453 = _443 + _452;
   uint16_t _454 = (uint16_t)(8);
   uint16_t _455 = _453 >> _454;
   _gray_stencil(_437, _439) = _455;
   int32_t _482 = _gray_s0_x_x * 2;
   int32_t _483 = _482 + 1;
   int32_t _484 = _gray_s0_y + -3;
   int32_t _485 = _484 + 3;
   int16_t _486 = _hw_input_global_wrapper_global_wrapper_stencil(1, _483, _485);
   uint16_t _487 = (uint16_t)(_486);
   uint16_t _488 = (uint16_t)(150);
   uint16_t _489 = _487 * _488;
   int16_t _490 = _hw_input_global_wrapper_global_wrapper_stencil(2, _483, _485);
   uint16_t _491 = (uint16_t)(_490);
   uint16_t _492 = (uint16_t)(29);
   uint16_t _493 = _491 * _492;
   int16_t _494 = _hw_input_global_wrapper_global_wrapper_stencil(0, _483, _485);
   uint16_t _495 = (uint16_t)(_494);
   uint16_t _496 = (uint16_t)(77);
   uint16_t _497 = _495 * _496;
   uint16_t _498 = _493 + _497;
   uint16_t _499 = _489 + _498;
   uint16_t _500 = (uint16_t)(8);
   uint16_t _501 = _499 >> _500;
   _gray_stencil(_483, _485) = _501;
  } // for gray_s0_x_x
 } // for gray_s0_y
 // consume gray.stencil
[, ], [, ] // produce grad_x_unclamp.stencil
 int32_t _502 = 0 + -2;
 for (int grad_x_unclamp_s0_y = 0; grad_x_unclamp_s0_y < 259; grad_x_unclamp_s0_y++)
 {
  for (int grad_x_unclamp_s0_x_x = 0; grad_x_unclamp_s0_x_x < 63; grad_x_unclamp_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _505 = _grad_x_unclamp_s0_x_x * 2;
   int32_t _506 = _grad_x_unclamp_s0_y + -2;
   int32_t _507 = _506 + 2;
   int16_t _508 = (int16_t)(0);
   _grad_x_unclamp_stencil(_505, _507) = _508;
   int32_t _511 = _grad_x_unclamp_s0_x_x * 2;
   int32_t _512 = _511 + 1;
   int32_t _513 = _grad_x_unclamp_s0_y + -2;
   int32_t _514 = _513 + 2;
   int16_t _515 = (int16_t)(0);
   _grad_x_unclamp_stencil(_512, _514) = _515;
  } // for grad_x_unclamp_s0_x_x
 } // for grad_x_unclamp_s0_y
 int32_t _516 = 0 + -2;
 for (int grad_x_unclamp_s1_y = 0; grad_x_unclamp_s1_y < 259; grad_x_unclamp_s1_y++)
 {
  for (int grad_x_unclamp_s1_x_x = 0; grad_x_unclamp_s1_x_x < 63; grad_x_unclamp_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _547 = _grad_x_unclamp_s1_x_x * 2;
   int32_t _548 = _grad_x_unclamp_s1_y + -2;
   int32_t _549 = _548 + 2;
   int16_t _550 = _grad_x_unclamp_stencil(_547, _549);
   int32_t _551 = _547 + 2;
   int32_t _552 = _548 + 3;
   uint16_t _553 = _gray_stencil(_551, _552);
   int16_t _554 = (int16_t)(_553);
   int16_t _555 = (int16_t)(2);
   int16_t _556 = _554 * _555;
   int16_t _557 = _550 + _556;
   uint16_t _558 = _gray_stencil(_547, _549);
   int16_t _559 = (int16_t)(_558);
   int16_t _560 = _557 - _559;
   uint16_t _561 = _gray_stencil(_551, _549);
   int16_t _562 = (int16_t)(_561);
   int16_t _563 = _560 + _562;
   uint16_t _564 = _gray_stencil(_547, _552);
   int16_t _565 = (int16_t)(_564);
   int16_t _566 = _565 * _555;
   int16_t _567 = _563 - _566;
   int32_t _568 = _548 + 4;
   uint16_t _569 = _gray_stencil(_547, _568);
   int16_t _570 = (int16_t)(_569);
   int16_t _571 = _567 - _570;
   uint16_t _572 = _gray_stencil(_551, _568);
   int16_t _573 = (int16_t)(_572);
   int16_t _574 = _571 + _573;
   _grad_x_unclamp_stencil(_547, _549) = _574;
   int32_t _605 = _grad_x_unclamp_s1_x_x * 2;
   int32_t _606 = _605 + 1;
   int32_t _607 = _grad_x_unclamp_s1_y + -2;
   int32_t _608 = _607 + 2;
   int16_t _609 = _grad_x_unclamp_stencil(_606, _608);
   int32_t _610 = _605 + 3;
   int32_t _611 = _607 + 3;
   uint16_t _612 = _gray_stencil(_610, _611);
   int16_t _613 = (int16_t)(_612);
   int16_t _614 = (int16_t)(2);
   int16_t _615 = _613 * _614;
   int16_t _616 = _609 + _615;
   uint16_t _617 = _gray_stencil(_606, _608);
   int16_t _618 = (int16_t)(_617);
   int16_t _619 = _616 - _618;
   uint16_t _620 = _gray_stencil(_610, _608);
   int16_t _621 = (int16_t)(_620);
   int16_t _622 = _619 + _621;
   uint16_t _623 = _gray_stencil(_606, _611);
   int16_t _624 = (int16_t)(_623);
   int16_t _625 = _624 * _614;
   int16_t _626 = _622 - _625;
   int32_t _627 = _607 + 4;
   uint16_t _628 = _gray_stencil(_606, _627);
   int16_t _629 = (int16_t)(_628);
   int16_t _630 = _626 - _629;
   uint16_t _631 = _gray_stencil(_610, _627);
   int16_t _632 = (int16_t)(_631);
   int16_t _633 = _630 + _632;
   _grad_x_unclamp_stencil(_606, _608) = _633;
  } // for grad_x_unclamp_s1_x_x
 } // for grad_x_unclamp_s1_y
 // consume grad_x_unclamp.stencil
[, ], [, ] // produce lxx.stencil
 int32_t _634 = 0 + -2;
 for (int lxx_s0_y = 0; lxx_s0_y < 259; lxx_s0_y++)
 {
  for (int lxx_s0_x_x = 0; lxx_s0_x_x < 63; lxx_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _649 = _lxx_s0_x_x * 2;
   int32_t _650 = _lxx_s0_y + -2;
   int32_t _651 = _650 + 2;
   int16_t _652 = _grad_x_unclamp_stencil(_649, _651);
   int16_t _653 = (int16_t)(180);
   int16_t _654 = ::halide_cpp_min(_652, _653);
   int16_t _655 = (int16_t)(-180);
   int16_t _656 = ::halide_cpp_max(_654, _655);
   int16_t _657 = _656 * _656;
   int16_t _658 = (int16_t)(6);
   int16_t _659 = _657 >> _658;
   _lxx_stencil(_649, _651) = _659;
   int32_t _674 = _lxx_s0_x_x * 2;
   int32_t _675 = _674 + 1;
   int32_t _676 = _lxx_s0_y + -2;
   int32_t _677 = _676 + 2;
   int16_t _678 = _grad_x_unclamp_stencil(_675, _677);
   int16_t _679 = (int16_t)(180);
   int16_t _680 = ::halide_cpp_min(_678, _679);
   int16_t _681 = (int16_t)(-180);
   int16_t _682 = ::halide_cpp_max(_680, _681);
   int16_t _683 = _682 * _682;
   int16_t _684 = (int16_t)(6);
   int16_t _685 = _683 >> _684;
   _lxx_stencil(_675, _677) = _685;
  } // for lxx_s0_x_x
 } // for lxx_s0_y
 // consume lxx.stencil
[, ], [, ] // produce lgxx.stencil
 int32_t _686 = 0 + -1;
 for (int lgxx_s0_y = 0; lgxx_s0_y < 257; lgxx_s0_y++)
 {
  for (int lgxx_s0_x_x = 0; lgxx_s0_x_x < 62; lgxx_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _689 = _lgxx_s0_x_x * 2;
   int32_t _690 = _lgxx_s0_y + -1;
   int32_t _691 = _690 + 1;
   int16_t _692 = (int16_t)(0);
   _lgxx_stencil(_689, _691) = _692;
   int32_t _695 = _lgxx_s0_x_x * 2;
   int32_t _696 = _695 + 1;
   int32_t _697 = _lgxx_s0_y + -1;
   int32_t _698 = _697 + 1;
   int16_t _699 = (int16_t)(0);
   _lgxx_stencil(_696, _698) = _699;
  } // for lgxx_s0_x_x
 } // for lgxx_s0_y
 int32_t _700 = 0 + -1;
 for (int lgxx_s1_y = 0; lgxx_s1_y < 257; lgxx_s1_y++)
 {
  for (int lgxx_s1_x_x = 0; lgxx_s1_x_x < 62; lgxx_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _719 = _lgxx_s1_x_x * 2;
   int32_t _720 = _lgxx_s1_y + -1;
   int32_t _721 = _720 + 1;
   int16_t _722 = _lxx_stencil(_719, _721);
   int16_t _723 = _lgxx_stencil(_719, _721);
   int32_t _724 = _719 + 1;
   int16_t _725 = _lxx_stencil(_724, _721);
   int32_t _726 = _719 + 2;
   int16_t _727 = _lxx_stencil(_726, _721);
   int32_t _728 = _720 + 2;
   int16_t _729 = _lxx_stencil(_719, _728);
   int16_t _730 = _lxx_stencil(_724, _728);
   int16_t _731 = _lxx_stencil(_726, _728);
   int32_t _732 = _720 + 3;
   int16_t _733 = _lxx_stencil(_719, _732);
   int16_t _734 = _lxx_stencil(_726, _732);
   int16_t _735 = _lxx_stencil(_724, _732);
   int16_t _736 = _734 + _735;
   int16_t _737 = _733 + _736;
   int16_t _738 = _731 + _737;
   int16_t _739 = _730 + _738;
   int16_t _740 = _729 + _739;
   int16_t _741 = _727 + _740;
   int16_t _742 = _725 + _741;
   int16_t _743 = _723 + _742;
   int16_t _744 = _722 + _743;
   _lgxx_stencil(_719, _721) = _744;
   int32_t _763 = _lgxx_s1_x_x * 2;
   int32_t _764 = _763 + 1;
   int32_t _765 = _lgxx_s1_y + -1;
   int32_t _766 = _765 + 1;
   int16_t _767 = _lxx_stencil(_764, _766);
   int16_t _768 = _lgxx_stencil(_764, _766);
   int32_t _769 = _763 + 2;
   int16_t _770 = _lxx_stencil(_769, _766);
   int32_t _771 = _763 + 3;
   int16_t _772 = _lxx_stencil(_771, _766);
   int32_t _773 = _765 + 2;
   int16_t _774 = _lxx_stencil(_764, _773);
   int16_t _775 = _lxx_stencil(_769, _773);
   int16_t _776 = _lxx_stencil(_771, _773);
   int32_t _777 = _765 + 3;
   int16_t _778 = _lxx_stencil(_764, _777);
   int16_t _779 = _lxx_stencil(_771, _777);
   int16_t _780 = _lxx_stencil(_769, _777);
   int16_t _781 = _779 + _780;
   int16_t _782 = _778 + _781;
   int16_t _783 = _776 + _782;
   int16_t _784 = _775 + _783;
   int16_t _785 = _774 + _784;
   int16_t _786 = _772 + _785;
   int16_t _787 = _770 + _786;
   int16_t _788 = _768 + _787;
   int16_t _789 = _767 + _788;
   _lgxx_stencil(_764, _766) = _789;
  } // for lgxx_s1_x_x
 } // for lgxx_s1_y
 // consume lgxx.stencil
[, ], [, ] // produce grad_y_unclamp.stencil
 int32_t _790 = 0 + -2;
 for (int grad_y_unclamp_s0_y = 0; grad_y_unclamp_s0_y < 259; grad_y_unclamp_s0_y++)
 {
  for (int grad_y_unclamp_s0_x_x = 0; grad_y_unclamp_s0_x_x < 63; grad_y_unclamp_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _793 = _grad_y_unclamp_s0_x_x * 2;
   int32_t _794 = _grad_y_unclamp_s0_y + -2;
   int32_t _795 = _794 + 2;
   int16_t _796 = (int16_t)(0);
   _grad_y_unclamp_stencil(_793, _795) = _796;
   int32_t _799 = _grad_y_unclamp_s0_x_x * 2;
   int32_t _800 = _799 + 1;
   int32_t _801 = _grad_y_unclamp_s0_y + -2;
   int32_t _802 = _801 + 2;
   int16_t _803 = (int16_t)(0);
   _grad_y_unclamp_stencil(_800, _802) = _803;
  } // for grad_y_unclamp_s0_x_x
 } // for grad_y_unclamp_s0_y
 int32_t _804 = 0 + -2;
 for (int grad_y_unclamp_s1_y = 0; grad_y_unclamp_s1_y < 259; grad_y_unclamp_s1_y++)
 {
  for (int grad_y_unclamp_s1_x_x = 0; grad_y_unclamp_s1_x_x < 63; grad_y_unclamp_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _835 = _grad_y_unclamp_s1_x_x * 2;
   int32_t _836 = _grad_y_unclamp_s1_y + -2;
   int32_t _837 = _836 + 2;
   int16_t _838 = _grad_y_unclamp_stencil(_835, _837);
   int32_t _839 = _835 + 1;
   int32_t _840 = _836 + 4;
   uint16_t _841 = _gray_stencil(_839, _840);
   int16_t _842 = (int16_t)(_841);
   int16_t _843 = (int16_t)(2);
   int16_t _844 = _842 * _843;
   int16_t _845 = _838 + _844;
   uint16_t _846 = _gray_stencil(_835, _837);
   int16_t _847 = (int16_t)(_846);
   int16_t _848 = _845 - _847;
   uint16_t _849 = _gray_stencil(_839, _837);
   int16_t _850 = (int16_t)(_849);
   int16_t _851 = _850 * _843;
   int16_t _852 = _848 - _851;
   int32_t _853 = _835 + 2;
   uint16_t _854 = _gray_stencil(_853, _837);
   int16_t _855 = (int16_t)(_854);
   int16_t _856 = _852 - _855;
   uint16_t _857 = _gray_stencil(_835, _840);
   int16_t _858 = (int16_t)(_857);
   int16_t _859 = _856 + _858;
   uint16_t _860 = _gray_stencil(_853, _840);
   int16_t _861 = (int16_t)(_860);
   int16_t _862 = _859 + _861;
   _grad_y_unclamp_stencil(_835, _837) = _862;
   int32_t _893 = _grad_y_unclamp_s1_x_x * 2;
   int32_t _894 = _893 + 1;
   int32_t _895 = _grad_y_unclamp_s1_y + -2;
   int32_t _896 = _895 + 2;
   int16_t _897 = _grad_y_unclamp_stencil(_894, _896);
   int32_t _898 = _893 + 2;
   int32_t _899 = _895 + 4;
   uint16_t _900 = _gray_stencil(_898, _899);
   int16_t _901 = (int16_t)(_900);
   int16_t _902 = (int16_t)(2);
   int16_t _903 = _901 * _902;
   int16_t _904 = _897 + _903;
   uint16_t _905 = _gray_stencil(_894, _896);
   int16_t _906 = (int16_t)(_905);
   int16_t _907 = _904 - _906;
   uint16_t _908 = _gray_stencil(_898, _896);
   int16_t _909 = (int16_t)(_908);
   int16_t _910 = _909 * _902;
   int16_t _911 = _907 - _910;
   int32_t _912 = _893 + 3;
   uint16_t _913 = _gray_stencil(_912, _896);
   int16_t _914 = (int16_t)(_913);
   int16_t _915 = _911 - _914;
   uint16_t _916 = _gray_stencil(_894, _899);
   int16_t _917 = (int16_t)(_916);
   int16_t _918 = _915 + _917;
   uint16_t _919 = _gray_stencil(_912, _899);
   int16_t _920 = (int16_t)(_919);
   int16_t _921 = _918 + _920;
   _grad_y_unclamp_stencil(_894, _896) = _921;
  } // for grad_y_unclamp_s1_x_x
 } // for grad_y_unclamp_s1_y
 // consume grad_y_unclamp.stencil
[, ], [, ] // produce lxy.stencil
 int32_t _922 = 0 + -2;
 for (int lxy_s0_y = 0; lxy_s0_y < 259; lxy_s0_y++)
 {
  for (int lxy_s0_x_x = 0; lxy_s0_x_x < 63; lxy_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _941 = _lxy_s0_x_x * 2;
   int32_t _942 = _lxy_s0_y + -2;
   int32_t _943 = _942 + 2;
   int16_t _944 = _grad_x_unclamp_stencil(_941, _943);
   int16_t _945 = (int16_t)(180);
   int16_t _946 = ::halide_cpp_min(_944, _945);
   int16_t _947 = (int16_t)(-180);
   int16_t _948 = ::halide_cpp_max(_946, _947);
   int16_t _949 = _grad_y_unclamp_stencil(_941, _943);
   int16_t _950 = ::halide_cpp_min(_949, _945);
   int16_t _951 = ::halide_cpp_max(_950, _947);
   int16_t _952 = _948 * _951;
   int16_t _953 = (int16_t)(6);
   int16_t _954 = _952 >> _953;
   _lxy_stencil(_941, _943) = _954;
   int32_t _973 = _lxy_s0_x_x * 2;
   int32_t _974 = _973 + 1;
   int32_t _975 = _lxy_s0_y + -2;
   int32_t _976 = _975 + 2;
   int16_t _977 = _grad_x_unclamp_stencil(_974, _976);
   int16_t _978 = (int16_t)(180);
   int16_t _979 = ::halide_cpp_min(_977, _978);
   int16_t _980 = (int16_t)(-180);
   int16_t _981 = ::halide_cpp_max(_979, _980);
   int16_t _982 = _grad_y_unclamp_stencil(_974, _976);
   int16_t _983 = ::halide_cpp_min(_982, _978);
   int16_t _984 = ::halide_cpp_max(_983, _980);
   int16_t _985 = _981 * _984;
   int16_t _986 = (int16_t)(6);
   int16_t _987 = _985 >> _986;
   _lxy_stencil(_974, _976) = _987;
  } // for lxy_s0_x_x
 } // for lxy_s0_y
 // consume lxy.stencil
[, ], [, ] // produce lgxy.stencil
 int32_t _988 = 0 + -1;
 for (int lgxy_s0_y = 0; lgxy_s0_y < 257; lgxy_s0_y++)
 {
  for (int lgxy_s0_x_x = 0; lgxy_s0_x_x < 62; lgxy_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _991 = _lgxy_s0_x_x * 2;
   int32_t _992 = _lgxy_s0_y + -1;
   int32_t _993 = _992 + 1;
   int16_t _994 = (int16_t)(0);
   _lgxy_stencil(_991, _993) = _994;
   int32_t _997 = _lgxy_s0_x_x * 2;
   int32_t _998 = _997 + 1;
   int32_t _999 = _lgxy_s0_y + -1;
   int32_t _1000 = _999 + 1;
   int16_t _1001 = (int16_t)(0);
   _lgxy_stencil(_998, _1000) = _1001;
  } // for lgxy_s0_x_x
 } // for lgxy_s0_y
 int32_t _1002 = 0 + -1;
 for (int lgxy_s1_y = 0; lgxy_s1_y < 257; lgxy_s1_y++)
 {
  for (int lgxy_s1_x_x = 0; lgxy_s1_x_x < 62; lgxy_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1021 = _lgxy_s1_x_x * 2;
   int32_t _1022 = _lgxy_s1_y + -1;
   int32_t _1023 = _1022 + 1;
   int16_t _1024 = _lxy_stencil(_1021, _1023);
   int16_t _1025 = _lgxy_stencil(_1021, _1023);
   int32_t _1026 = _1021 + 1;
   int16_t _1027 = _lxy_stencil(_1026, _1023);
   int32_t _1028 = _1021 + 2;
   int16_t _1029 = _lxy_stencil(_1028, _1023);
   int32_t _1030 = _1022 + 2;
   int16_t _1031 = _lxy_stencil(_1021, _1030);
   int16_t _1032 = _lxy_stencil(_1026, _1030);
   int16_t _1033 = _lxy_stencil(_1028, _1030);
   int32_t _1034 = _1022 + 3;
   int16_t _1035 = _lxy_stencil(_1021, _1034);
   int16_t _1036 = _lxy_stencil(_1028, _1034);
   int16_t _1037 = _lxy_stencil(_1026, _1034);
   int16_t _1038 = _1036 + _1037;
   int16_t _1039 = _1035 + _1038;
   int16_t _1040 = _1033 + _1039;
   int16_t _1041 = _1032 + _1040;
   int16_t _1042 = _1031 + _1041;
   int16_t _1043 = _1029 + _1042;
   int16_t _1044 = _1027 + _1043;
   int16_t _1045 = _1025 + _1044;
   int16_t _1046 = _1024 + _1045;
   _lgxy_stencil(_1021, _1023) = _1046;
   int32_t _1065 = _lgxy_s1_x_x * 2;
   int32_t _1066 = _1065 + 1;
   int32_t _1067 = _lgxy_s1_y + -1;
   int32_t _1068 = _1067 + 1;
   int16_t _1069 = _lxy_stencil(_1066, _1068);
   int16_t _1070 = _lgxy_stencil(_1066, _1068);
   int32_t _1071 = _1065 + 2;
   int16_t _1072 = _lxy_stencil(_1071, _1068);
   int32_t _1073 = _1065 + 3;
   int16_t _1074 = _lxy_stencil(_1073, _1068);
   int32_t _1075 = _1067 + 2;
   int16_t _1076 = _lxy_stencil(_1066, _1075);
   int16_t _1077 = _lxy_stencil(_1071, _1075);
   int16_t _1078 = _lxy_stencil(_1073, _1075);
   int32_t _1079 = _1067 + 3;
   int16_t _1080 = _lxy_stencil(_1066, _1079);
   int16_t _1081 = _lxy_stencil(_1073, _1079);
   int16_t _1082 = _lxy_stencil(_1071, _1079);
   int16_t _1083 = _1081 + _1082;
   int16_t _1084 = _1080 + _1083;
   int16_t _1085 = _1078 + _1084;
   int16_t _1086 = _1077 + _1085;
   int16_t _1087 = _1076 + _1086;
   int16_t _1088 = _1074 + _1087;
   int16_t _1089 = _1072 + _1088;
   int16_t _1090 = _1070 + _1089;
   int16_t _1091 = _1069 + _1090;
   _lgxy_stencil(_1066, _1068) = _1091;
  } // for lgxy_s1_x_x
 } // for lgxy_s1_y
 // consume lgxy.stencil
[, ], [, ] // produce lyy.stencil
 int32_t _1092 = 0 + -2;
 for (int lyy_s0_y = 0; lyy_s0_y < 259; lyy_s0_y++)
 {
  for (int lyy_s0_x_x = 0; lyy_s0_x_x < 63; lyy_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1107 = _lyy_s0_x_x * 2;
   int32_t _1108 = _lyy_s0_y + -2;
   int32_t _1109 = _1108 + 2;
   int16_t _1110 = _grad_y_unclamp_stencil(_1107, _1109);
   int16_t _1111 = (int16_t)(180);
   int16_t _1112 = ::halide_cpp_min(_1110, _1111);
   int16_t _1113 = (int16_t)(-180);
   int16_t _1114 = ::halide_cpp_max(_1112, _1113);
   int16_t _1115 = _1114 * _1114;
   int16_t _1116 = (int16_t)(6);
   int16_t _1117 = _1115 >> _1116;
   _lyy_stencil(_1107, _1109) = _1117;
   int32_t _1132 = _lyy_s0_x_x * 2;
   int32_t _1133 = _1132 + 1;
   int32_t _1134 = _lyy_s0_y + -2;
   int32_t _1135 = _1134 + 2;
   int16_t _1136 = _grad_y_unclamp_stencil(_1133, _1135);
   int16_t _1137 = (int16_t)(180);
   int16_t _1138 = ::halide_cpp_min(_1136, _1137);
   int16_t _1139 = (int16_t)(-180);
   int16_t _1140 = ::halide_cpp_max(_1138, _1139);
   int16_t _1141 = _1140 * _1140;
   int16_t _1142 = (int16_t)(6);
   int16_t _1143 = _1141 >> _1142;
   _lyy_stencil(_1133, _1135) = _1143;
  } // for lyy_s0_x_x
 } // for lyy_s0_y
 // consume lyy.stencil
[, ], [, ] // produce lgyy.stencil
 int32_t _1144 = 0 + -1;
 for (int lgyy_s0_y = 0; lgyy_s0_y < 257; lgyy_s0_y++)
 {
  for (int lgyy_s0_x_x = 0; lgyy_s0_x_x < 62; lgyy_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1147 = _lgyy_s0_x_x * 2;
   int32_t _1148 = _lgyy_s0_y + -1;
   int32_t _1149 = _1148 + 1;
   int16_t _1150 = (int16_t)(0);
   _lgyy_stencil(_1147, _1149) = _1150;
   int32_t _1153 = _lgyy_s0_x_x * 2;
   int32_t _1154 = _1153 + 1;
   int32_t _1155 = _lgyy_s0_y + -1;
   int32_t _1156 = _1155 + 1;
   int16_t _1157 = (int16_t)(0);
   _lgyy_stencil(_1154, _1156) = _1157;
  } // for lgyy_s0_x_x
 } // for lgyy_s0_y
 int32_t _1158 = 0 + -1;
 for (int lgyy_s1_y = 0; lgyy_s1_y < 257; lgyy_s1_y++)
 {
  for (int lgyy_s1_x_x = 0; lgyy_s1_x_x < 62; lgyy_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1177 = _lgyy_s1_x_x * 2;
   int32_t _1178 = _lgyy_s1_y + -1;
   int32_t _1179 = _1178 + 1;
   int16_t _1180 = _lyy_stencil(_1177, _1179);
   int16_t _1181 = _lgyy_stencil(_1177, _1179);
   int32_t _1182 = _1177 + 1;
   int16_t _1183 = _lyy_stencil(_1182, _1179);
   int32_t _1184 = _1177 + 2;
   int16_t _1185 = _lyy_stencil(_1184, _1179);
   int32_t _1186 = _1178 + 2;
   int16_t _1187 = _lyy_stencil(_1177, _1186);
   int16_t _1188 = _lyy_stencil(_1182, _1186);
   int16_t _1189 = _lyy_stencil(_1184, _1186);
   int32_t _1190 = _1178 + 3;
   int16_t _1191 = _lyy_stencil(_1177, _1190);
   int16_t _1192 = _lyy_stencil(_1184, _1190);
   int16_t _1193 = _lyy_stencil(_1182, _1190);
   int16_t _1194 = _1192 + _1193;
   int16_t _1195 = _1191 + _1194;
   int16_t _1196 = _1189 + _1195;
   int16_t _1197 = _1188 + _1196;
   int16_t _1198 = _1187 + _1197;
   int16_t _1199 = _1185 + _1198;
   int16_t _1200 = _1183 + _1199;
   int16_t _1201 = _1181 + _1200;
   int16_t _1202 = _1180 + _1201;
   _lgyy_stencil(_1177, _1179) = _1202;
   int32_t _1221 = _lgyy_s1_x_x * 2;
   int32_t _1222 = _1221 + 1;
   int32_t _1223 = _lgyy_s1_y + -1;
   int32_t _1224 = _1223 + 1;
   int16_t _1225 = _lyy_stencil(_1222, _1224);
   int16_t _1226 = _lgyy_stencil(_1222, _1224);
   int32_t _1227 = _1221 + 2;
   int16_t _1228 = _lyy_stencil(_1227, _1224);
   int32_t _1229 = _1221 + 3;
   int16_t _1230 = _lyy_stencil(_1229, _1224);
   int32_t _1231 = _1223 + 2;
   int16_t _1232 = _lyy_stencil(_1222, _1231);
   int16_t _1233 = _lyy_stencil(_1227, _1231);
   int16_t _1234 = _lyy_stencil(_1229, _1231);
   int32_t _1235 = _1223 + 3;
   int16_t _1236 = _lyy_stencil(_1222, _1235);
   int16_t _1237 = _lyy_stencil(_1229, _1235);
   int16_t _1238 = _lyy_stencil(_1227, _1235);
   int16_t _1239 = _1237 + _1238;
   int16_t _1240 = _1236 + _1239;
   int16_t _1241 = _1234 + _1240;
   int16_t _1242 = _1233 + _1241;
   int16_t _1243 = _1232 + _1242;
   int16_t _1244 = _1230 + _1243;
   int16_t _1245 = _1228 + _1244;
   int16_t _1246 = _1226 + _1245;
   int16_t _1247 = _1225 + _1246;
   _lgyy_stencil(_1222, _1224) = _1247;
  } // for lgyy_s1_x_x
 } // for lgyy_s1_y
 // consume lgyy.stencil
[, ], [, ] // produce cim.stencil
 int32_t _1248 = 0 + -1;
 for (int cim_s0_y = 0; cim_s0_y < 257; cim_s0_y++)
 {
  for (int cim_s0_x_x = 0; cim_s0_x_x < 62; cim_s0_x_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1273 = _cim_s0_x_x * 2;
   int32_t _1274 = _cim_s0_y + -1;
   int32_t _1275 = _1274 + 1;
   int16_t _1276 = _lgxx_stencil(_1273, _1275);
   int16_t _1277 = (int16_t)(6);
   int16_t _1278 = _1276 >> _1277;
   int16_t _1279 = _lgyy_stencil(_1273, _1275);
   int16_t _1280 = _1279 >> _1277;
   int16_t _1281 = _1278 * _1280;
   int16_t _1282 = _lgxy_stencil(_1273, _1275);
   int16_t _1283 = _1282 >> _1277;
   int16_t _1284 = _1283 * _1283;
   int16_t _1285 = _1281 - _1284;
   int16_t _1286 = _1278 + _1280;
   int16_t _1287 = _1286 * _1286;
   int16_t _1288 = (int16_t)(4);
   int16_t _1289 = _1287 >> _1288;
   int16_t _1290 = _1285 - _1289;
   _cim_stencil(_1273, _1275) = _1290;
   int32_t _1315 = _cim_s0_x_x * 2;
   int32_t _1316 = _1315 + 1;
   int32_t _1317 = _cim_s0_y + -1;
   int32_t _1318 = _1317 + 1;
   int16_t _1319 = _lgxx_stencil(_1316, _1318);
   int16_t _1320 = (int16_t)(6);
   int16_t _1321 = _1319 >> _1320;
   int16_t _1322 = _lgyy_stencil(_1316, _1318);
   int16_t _1323 = _1322 >> _1320;
   int16_t _1324 = _1321 * _1323;
   int16_t _1325 = _lgxy_stencil(_1316, _1318);
   int16_t _1326 = _1325 >> _1320;
   int16_t _1327 = _1326 * _1326;
   int16_t _1328 = _1324 - _1327;
   int16_t _1329 = _1321 + _1323;
   int16_t _1330 = _1329 * _1329;
   int16_t _1331 = (int16_t)(4);
   int16_t _1332 = _1330 >> _1331;
   int16_t _1333 = _1328 - _1332;
   _cim_stencil(_1316, _1318) = _1333;
  } // for cim_s0_x_x
 } // for cim_s0_y
 // consume cim.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 255; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi_xi = 0; hw_output_s0_x_xi_xi < 61; hw_output_s0_x_xi_xi++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1376 = _hw_output_s0_x_xi_xi * 2;
   int16_t _1377 = (int16_t)(255);
   int16_t _1378 = (int16_t)(0);
   int16_t _1379 = _cim_stencil(_1376, _hw_output_s0_y_yi);
   int32_t _1380 = _1376 + 1;
   int32_t _1381 = _hw_output_s0_y_yi + 1;
   int16_t _1382 = _cim_stencil(_1380, _1381);
   bool _1383 = _1379 < _1382;
   int16_t _1384 = _cim_stencil(_1380, _hw_output_s0_y_yi);
   bool _1385 = _1384 < _1382;
   bool _1386 = _1383 && _1385;
   int32_t _1387 = _1376 + 2;
   int16_t _1388 = _cim_stencil(_1387, _hw_output_s0_y_yi);
   bool _1389 = _1388 < _1382;
   bool _1390 = _1386 && _1389;
   int16_t _1391 = _cim_stencil(_1376, _1381);
   bool _1392 = _1391 < _1382;
   bool _1393 = _1390 && _1392;
   int16_t _1394 = _cim_stencil(_1387, _1381);
   bool _1395 = _1394 < _1382;
   bool _1396 = _1393 && _1395;
   int32_t _1397 = _hw_output_s0_y_yi + 2;
   int16_t _1398 = _cim_stencil(_1376, _1397);
   bool _1399 = _1398 < _1382;
   bool _1400 = _1396 && _1399;
   int16_t _1401 = _cim_stencil(_1380, _1397);
   bool _1402 = _1401 < _1382;
   bool _1403 = _1400 && _1402;
   int16_t _1404 = _cim_stencil(_1387, _1397);
   bool _1405 = _1404 < _1382;
   bool _1406 = _1403 && _1405;
   int16_t _1407 = (int16_t)(1);
   bool _1408 = _1407 <= _1382;
   bool _1409 = _1406 && _1408;
   int16_t _1410 = (int16_t)(_1409 ? _1377 : _1378);
   _hw_output_glb_stencil(_1376, _hw_output_s0_y_yi) = _1410;
   int32_t _1453 = _hw_output_s0_x_xi_xi * 2;
   int32_t _1454 = _1453 + 1;
   int16_t _1455 = (int16_t)(255);
   int16_t _1456 = (int16_t)(0);
   int16_t _1457 = _cim_stencil(_1454, _hw_output_s0_y_yi);
   int32_t _1458 = _1453 + 2;
   int32_t _1459 = _hw_output_s0_y_yi + 1;
   int16_t _1460 = _cim_stencil(_1458, _1459);
   bool _1461 = _1457 < _1460;
   int16_t _1462 = _cim_stencil(_1458, _hw_output_s0_y_yi);
   bool _1463 = _1462 < _1460;
   bool _1464 = _1461 && _1463;
   int32_t _1465 = _1453 + 3;
   int16_t _1466 = _cim_stencil(_1465, _hw_output_s0_y_yi);
   bool _1467 = _1466 < _1460;
   bool _1468 = _1464 && _1467;
   int16_t _1469 = _cim_stencil(_1454, _1459);
   bool _1470 = _1469 < _1460;
   bool _1471 = _1468 && _1470;
   int16_t _1472 = _cim_stencil(_1465, _1459);
   bool _1473 = _1472 < _1460;
   bool _1474 = _1471 && _1473;
   int32_t _1475 = _hw_output_s0_y_yi + 2;
   int16_t _1476 = _cim_stencil(_1454, _1475);
   bool _1477 = _1476 < _1460;
   bool _1478 = _1474 && _1477;
   int16_t _1479 = _cim_stencil(_1458, _1475);
   bool _1480 = _1479 < _1460;
   bool _1481 = _1478 && _1480;
   int16_t _1482 = _cim_stencil(_1465, _1475);
   bool _1483 = _1482 < _1460;
   bool _1484 = _1481 && _1483;
   int16_t _1485 = (int16_t)(1);
   bool _1486 = _1485 <= _1460;
   bool _1487 = _1484 && _1486;
   int16_t _1488 = (int16_t)(_1487 ? _1455 : _1456);
   _hw_output_glb_stencil(_1454, _hw_output_s0_y_yi) = _1488;
  } // for hw_output_s0_x_xi_xi
 } // for hw_output_s0_y_yi
 // consume hw_output.glb.stencil
 for (int hw_output_global_wrapper_s0_y_yi = 0; hw_output_global_wrapper_s0_y_yi < 255; hw_output_global_wrapper_s0_y_yi++)
 {
  for (int hw_output_global_wrapper_s0_x_xi_xi = 0; hw_output_global_wrapper_s0_x_xi_xi < 61; hw_output_global_wrapper_s0_x_xi_xi++)
  {
#pragma HLS PIPELINE II=1
   int32_t _1489 = 0 * 61;
   int32_t _1490 = _hw_output_global_wrapper_s0_x_xi_xi + _1489;
   int32_t _1491 = _1490 * 2;
   int32_t _1492 = _hw_output_global_wrapper_s0_y_yi + 0;
   int32_t _1493 = _hw_output_global_wrapper_s0_x_xi_xi * 2;
   int16_t _1494 = _hw_output_glb_stencil(_1493, _hw_output_global_wrapper_s0_y_yi);
   _hw_output_global_wrapper_stencil(_1491, _1492) = _1494;
   int32_t _1495 = 0 * 61;
   int32_t _1496 = _hw_output_global_wrapper_s0_x_xi_xi + _1495;
   int32_t _1497 = _1496 * 2;
   int32_t _1498 = _1497 + 1;
   int32_t _1499 = _hw_output_global_wrapper_s0_y_yi + 0;
   int32_t _1500 = _hw_output_global_wrapper_s0_x_xi_xi * 2;
   int32_t _1501 = _1500 + 1;
   int16_t _1502 = _hw_output_glb_stencil(_1501, _hw_output_global_wrapper_s0_y_yi);
   _hw_output_global_wrapper_stencil(_1498, _1499) = _1502;
  } // for hw_output_global_wrapper_s0_x_xi_xi
 } // for hw_output_global_wrapper_s0_y_yi
} // kernel hls_targetharris_color

