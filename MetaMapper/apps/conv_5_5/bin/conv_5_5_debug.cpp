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
 Stencil<uint16_t, 60, 60> &hw_output_stencil = arg_1;
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
 for (int conv_s0_y = 0; conv_s0_y < 60; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 60; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _259;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 60; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 60; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _400 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _401 = (uint16_t)(11);
   uint16_t _402 = _400 * _401;
   uint16_t _403 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   int32_t _404 = _conv_s1_x + 1;
   uint16_t _405 = _hw_input_global_wrapper_stencil(_404, _conv_s1_y);
   uint16_t _406 = (uint16_t)(14);
   uint16_t _407 = _405 * _406;
   int32_t _408 = _conv_s1_x + 2;
   uint16_t _409 = _hw_input_global_wrapper_stencil(_408, _conv_s1_y);
   uint16_t _410 = (uint16_t)(17);
   uint16_t _411 = _409 * _410;
   int32_t _412 = _conv_s1_x + 3;
   uint16_t _413 = _hw_input_global_wrapper_stencil(_412, _conv_s1_y);
   uint16_t _414 = (uint16_t)(20);
   uint16_t _415 = _413 * _414;
   int32_t _416 = _conv_s1_x + 4;
   uint16_t _417 = _hw_input_global_wrapper_stencil(_416, _conv_s1_y);
   uint16_t _418 = (uint16_t)(30);
   uint16_t _419 = _417 * _418;
   int32_t _420 = _conv_s1_y + 1;
   uint16_t _421 = _hw_input_global_wrapper_stencil(_conv_s1_x, _420);
   uint16_t _422 = (uint16_t)(12);
   uint16_t _423 = _421 * _422;
   uint16_t _424 = _hw_input_global_wrapper_stencil(_408, _420);
   uint16_t _425 = (uint16_t)(18);
   uint16_t _426 = _424 * _425;
   uint16_t _427 = _hw_input_global_wrapper_stencil(_412, _420);
   uint16_t _428 = (uint16_t)(29);
   uint16_t _429 = _427 * _428;
   uint16_t _430 = _hw_input_global_wrapper_stencil(_416, _420);
   uint16_t _431 = (uint16_t)(39);
   uint16_t _432 = _430 * _431;
   int32_t _433 = _conv_s1_y + 2;
   uint16_t _434 = _hw_input_global_wrapper_stencil(_conv_s1_x, _433);
   uint16_t _435 = (uint16_t)(13);
   uint16_t _436 = _434 * _435;
   uint16_t _437 = _hw_input_global_wrapper_stencil(_404, _433);
   uint16_t _438 = (uint16_t)(16);
   uint16_t _439 = _437 * _438;
   uint16_t _440 = _hw_input_global_wrapper_stencil(_408, _433);
   uint16_t _441 = (uint16_t)(19);
   uint16_t _442 = _440 * _441;
   uint16_t _443 = _hw_input_global_wrapper_stencil(_412, _433);
   uint16_t _444 = (uint16_t)(22);
   uint16_t _445 = _443 * _444;
   uint16_t _446 = _hw_input_global_wrapper_stencil(_416, _433);
   uint16_t _447 = (uint16_t)(32);
   uint16_t _448 = _446 * _447;
   int32_t _449 = _conv_s1_y + 3;
   uint16_t _450 = _hw_input_global_wrapper_stencil(_conv_s1_x, _449);
   uint16_t _451 = (uint16_t)(23);
   uint16_t _452 = _450 * _451;
   uint16_t _453 = _hw_input_global_wrapper_stencil(_404, _449);
   uint16_t _454 = (uint16_t)(21);
   uint16_t _455 = _453 * _454;
   uint16_t _456 = _hw_input_global_wrapper_stencil(_408, _449);
   uint16_t _457 = (uint16_t)(26);
   uint16_t _458 = _456 * _457;
   uint16_t _459 = _hw_input_global_wrapper_stencil(_412, _449);
   uint16_t _460 = (uint16_t)(24);
   uint16_t _461 = _459 * _460;
   uint16_t _462 = _hw_input_global_wrapper_stencil(_416, _449);
   uint16_t _463 = (uint16_t)(34);
   uint16_t _464 = _462 * _463;
   int32_t _465 = _conv_s1_y + 4;
   uint16_t _466 = _hw_input_global_wrapper_stencil(_conv_s1_x, _465);
   uint16_t _467 = (uint16_t)(33);
   uint16_t _468 = _466 * _467;
   uint16_t _469 = _hw_input_global_wrapper_stencil(_404, _465);
   uint16_t _470 = (uint16_t)(31);
   uint16_t _471 = _469 * _470;
   uint16_t _472 = _hw_input_global_wrapper_stencil(_408, _465);
   uint16_t _473 = _472 * _447;
   uint16_t _474 = _hw_input_global_wrapper_stencil(_416, _465);
   uint16_t _475 = (uint16_t)(37);
   uint16_t _476 = _474 * _475;
   uint16_t _477 = _hw_input_global_wrapper_stencil(_412, _465);
   uint16_t _478 = _477 * _463;
   uint16_t _479 = _476 + _478;
   uint16_t _480 = _473 + _479;
   uint16_t _481 = _471 + _480;
   uint16_t _482 = _468 + _481;
   uint16_t _483 = _464 + _482;
   uint16_t _484 = _461 + _483;
   uint16_t _485 = _458 + _484;
   uint16_t _486 = _455 + _485;
   uint16_t _487 = _452 + _486;
   uint16_t _488 = _448 + _487;
   uint16_t _489 = _445 + _488;
   uint16_t _490 = _442 + _489;
   uint16_t _491 = _439 + _490;
   uint16_t _492 = _436 + _491;
   uint16_t _493 = _432 + _492;
   uint16_t _494 = _429 + _493;
   uint16_t _495 = _426 + _494;
   uint16_t _496 = _423 + _495;
   uint16_t _497 = _419 + _496;
   uint16_t _498 = _415 + _497;
   uint16_t _499 = _411 + _498;
   uint16_t _500 = _407 + _499;
   uint16_t _501 = _403 + _500;
   uint16_t _502 = _402 + _501;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _502;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 60; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 60; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _503 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _503;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_5_5

