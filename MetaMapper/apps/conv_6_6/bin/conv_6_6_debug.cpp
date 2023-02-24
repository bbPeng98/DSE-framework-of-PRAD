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
 Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 59, 59> &hw_output_stencil = arg_1;
[, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 64; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 64; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _256 = _hw_input_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _256;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ] // produce conv.stencil
 for (int conv_s0_y = 0; conv_s0_y < 59; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 59; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _259;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 59; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 59; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _460 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _461 = (uint16_t)(11);
   uint16_t _462 = _460 * _461;
   uint16_t _463 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   int32_t _464 = _conv_s1_x + 1;
   uint16_t _465 = _hw_input_global_wrapper_stencil(_464, _conv_s1_y);
   uint16_t _466 = (uint16_t)(14);
   uint16_t _467 = _465 * _466;
   int32_t _468 = _conv_s1_x + 2;
   uint16_t _469 = _hw_input_global_wrapper_stencil(_468, _conv_s1_y);
   uint16_t _470 = (uint16_t)(17);
   uint16_t _471 = _469 * _470;
   int32_t _472 = _conv_s1_x + 3;
   uint16_t _473 = _hw_input_global_wrapper_stencil(_472, _conv_s1_y);
   uint16_t _474 = (uint16_t)(20);
   uint16_t _475 = _473 * _474;
   int32_t _476 = _conv_s1_x + 4;
   uint16_t _477 = _hw_input_global_wrapper_stencil(_476, _conv_s1_y);
   uint16_t _478 = (uint16_t)(30);
   uint16_t _479 = _477 * _478;
   int32_t _480 = _conv_s1_x + 5;
   uint16_t _481 = _hw_input_global_wrapper_stencil(_480, _conv_s1_y);
   uint16_t _482 = (uint16_t)(40);
   uint16_t _483 = _481 * _482;
   int32_t _484 = _conv_s1_y + 1;
   uint16_t _485 = _hw_input_global_wrapper_stencil(_conv_s1_x, _484);
   uint16_t _486 = (uint16_t)(12);
   uint16_t _487 = _485 * _486;
   uint16_t _488 = _hw_input_global_wrapper_stencil(_468, _484);
   uint16_t _489 = (uint16_t)(18);
   uint16_t _490 = _488 * _489;
   uint16_t _491 = _hw_input_global_wrapper_stencil(_472, _484);
   uint16_t _492 = (uint16_t)(29);
   uint16_t _493 = _491 * _492;
   uint16_t _494 = _hw_input_global_wrapper_stencil(_476, _484);
   uint16_t _495 = (uint16_t)(39);
   uint16_t _496 = _494 * _495;
   uint16_t _497 = _hw_input_global_wrapper_stencil(_480, _484);
   uint16_t _498 = (uint16_t)(49);
   uint16_t _499 = _497 * _498;
   int32_t _500 = _conv_s1_y + 2;
   uint16_t _501 = _hw_input_global_wrapper_stencil(_conv_s1_x, _500);
   uint16_t _502 = (uint16_t)(13);
   uint16_t _503 = _501 * _502;
   uint16_t _504 = _hw_input_global_wrapper_stencil(_464, _500);
   uint16_t _505 = (uint16_t)(16);
   uint16_t _506 = _504 * _505;
   uint16_t _507 = _hw_input_global_wrapper_stencil(_468, _500);
   uint16_t _508 = (uint16_t)(19);
   uint16_t _509 = _507 * _508;
   uint16_t _510 = _hw_input_global_wrapper_stencil(_472, _500);
   uint16_t _511 = (uint16_t)(22);
   uint16_t _512 = _510 * _511;
   uint16_t _513 = _hw_input_global_wrapper_stencil(_476, _500);
   uint16_t _514 = (uint16_t)(32);
   uint16_t _515 = _513 * _514;
   uint16_t _516 = _hw_input_global_wrapper_stencil(_480, _500);
   uint16_t _517 = (uint16_t)(42);
   uint16_t _518 = _516 * _517;
   int32_t _519 = _conv_s1_y + 3;
   uint16_t _520 = _hw_input_global_wrapper_stencil(_conv_s1_x, _519);
   uint16_t _521 = (uint16_t)(23);
   uint16_t _522 = _520 * _521;
   uint16_t _523 = _hw_input_global_wrapper_stencil(_464, _519);
   uint16_t _524 = (uint16_t)(21);
   uint16_t _525 = _523 * _524;
   uint16_t _526 = _hw_input_global_wrapper_stencil(_468, _519);
   uint16_t _527 = (uint16_t)(26);
   uint16_t _528 = _526 * _527;
   uint16_t _529 = _hw_input_global_wrapper_stencil(_472, _519);
   uint16_t _530 = (uint16_t)(24);
   uint16_t _531 = _529 * _530;
   uint16_t _532 = _hw_input_global_wrapper_stencil(_476, _519);
   uint16_t _533 = (uint16_t)(34);
   uint16_t _534 = _532 * _533;
   uint16_t _535 = _hw_input_global_wrapper_stencil(_480, _519);
   uint16_t _536 = (uint16_t)(44);
   uint16_t _537 = _535 * _536;
   int32_t _538 = _conv_s1_y + 4;
   uint16_t _539 = _hw_input_global_wrapper_stencil(_conv_s1_x, _538);
   uint16_t _540 = (uint16_t)(33);
   uint16_t _541 = _539 * _540;
   uint16_t _542 = _hw_input_global_wrapper_stencil(_464, _538);
   uint16_t _543 = (uint16_t)(31);
   uint16_t _544 = _542 * _543;
   uint16_t _545 = _hw_input_global_wrapper_stencil(_468, _538);
   uint16_t _546 = _545 * _514;
   uint16_t _547 = _hw_input_global_wrapper_stencil(_472, _538);
   uint16_t _548 = _547 * _533;
   uint16_t _549 = _hw_input_global_wrapper_stencil(_476, _538);
   uint16_t _550 = (uint16_t)(37);
   uint16_t _551 = _549 * _550;
   uint16_t _552 = _hw_input_global_wrapper_stencil(_480, _538);
   uint16_t _553 = (uint16_t)(47);
   uint16_t _554 = _552 * _553;
   int32_t _555 = _conv_s1_y + 5;
   uint16_t _556 = _hw_input_global_wrapper_stencil(_conv_s1_x, _555);
   uint16_t _557 = (uint16_t)(43);
   uint16_t _558 = _556 * _557;
   uint16_t _559 = _hw_input_global_wrapper_stencil(_464, _555);
   uint16_t _560 = (uint16_t)(41);
   uint16_t _561 = _559 * _560;
   uint16_t _562 = _hw_input_global_wrapper_stencil(_468, _555);
   uint16_t _563 = _562 * _517;
   uint16_t _564 = _hw_input_global_wrapper_stencil(_472, _555);
   uint16_t _565 = _564 * _536;
   uint16_t _566 = _hw_input_global_wrapper_stencil(_480, _555);
   uint16_t _567 = (uint16_t)(48);
   uint16_t _568 = _566 * _567;
   uint16_t _569 = _hw_input_global_wrapper_stencil(_476, _555);
   uint16_t _570 = _569 * _553;
   uint16_t _571 = _568 + _570;
   uint16_t _572 = _565 + _571;
   uint16_t _573 = _563 + _572;
   uint16_t _574 = _561 + _573;
   uint16_t _575 = _558 + _574;
   uint16_t _576 = _554 + _575;
   uint16_t _577 = _551 + _576;
   uint16_t _578 = _548 + _577;
   uint16_t _579 = _546 + _578;
   uint16_t _580 = _544 + _579;
   uint16_t _581 = _541 + _580;
   uint16_t _582 = _537 + _581;
   uint16_t _583 = _534 + _582;
   uint16_t _584 = _531 + _583;
   uint16_t _585 = _528 + _584;
   uint16_t _586 = _525 + _585;
   uint16_t _587 = _522 + _586;
   uint16_t _588 = _518 + _587;
   uint16_t _589 = _515 + _588;
   uint16_t _590 = _512 + _589;
   uint16_t _591 = _509 + _590;
   uint16_t _592 = _506 + _591;
   uint16_t _593 = _503 + _592;
   uint16_t _594 = _499 + _593;
   uint16_t _595 = _496 + _594;
   uint16_t _596 = _493 + _595;
   uint16_t _597 = _490 + _596;
   uint16_t _598 = _487 + _597;
   uint16_t _599 = _483 + _598;
   uint16_t _600 = _479 + _599;
   uint16_t _601 = _475 + _600;
   uint16_t _602 = _471 + _601;
   uint16_t _603 = _467 + _602;
   uint16_t _604 = _463 + _603;
   uint16_t _605 = _462 + _604;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _605;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 59; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 59; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _606 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _606;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_6_6

