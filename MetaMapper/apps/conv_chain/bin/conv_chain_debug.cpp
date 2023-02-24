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
 Stencil<uint16_t, 58, 58> &hw_output_stencil = arg_1;
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
[, ], [, ] // produce conv0.stencil
 for (int conv0_s0_y = 0; conv0_s0_y < 62; conv0_s0_y++)
 {
  for (int conv0_s0_x = 0; conv0_s0_x < 62; conv0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv0_stencil(_conv0_s0_x, _conv0_s0_y) = _259;
  } // for conv0_s0_x
 } // for conv0_s0_y
 for (int conv0_s1_y = 0; conv0_s1_y < 62; conv0_s1_y++)
 {
  for (int conv0_s1_x_x = 0; conv0_s1_x_x < 62; conv0_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _312 = _hw_input_global_wrapper_stencil(_conv0_s1_x_x, _conv0_s1_y);
   uint16_t _313 = (uint16_t)(17);
   uint16_t _314 = _312 * _313;
   uint16_t _315 = _conv0_stencil(_conv0_s1_x_x, _conv0_s1_y);
   int32_t _316 = _conv0_s1_x_x + 1;
   uint16_t _317 = _hw_input_global_wrapper_stencil(_316, _conv0_s1_y);
   uint16_t _318 = (uint16_t)(7);
   uint16_t _319 = _317 * _318;
   int32_t _320 = _conv0_s1_x_x + 2;
   uint16_t _321 = _hw_input_global_wrapper_stencil(_320, _conv0_s1_y);
   uint16_t _322 = (uint16_t)(5);
   uint16_t _323 = _321 * _322;
   int32_t _324 = _conv0_s1_y + 1;
   uint16_t _325 = _hw_input_global_wrapper_stencil(_conv0_s1_x_x, _324);
   uint16_t _326 = (uint16_t)(4);
   uint16_t _327 = _325 * _326;
   uint16_t _328 = _hw_input_global_wrapper_stencil(_316, _324);
   uint16_t _329 = (uint16_t)(19);
   uint16_t _330 = _328 * _329;
   uint16_t _331 = _hw_input_global_wrapper_stencil(_320, _324);
   uint16_t _332 = (uint16_t)(21);
   uint16_t _333 = _331 * _332;
   int32_t _334 = _conv0_s1_y + 2;
   uint16_t _335 = _hw_input_global_wrapper_stencil(_conv0_s1_x_x, _334);
   uint16_t _336 = (uint16_t)(6);
   uint16_t _337 = _335 * _336;
   uint16_t _338 = _hw_input_global_wrapper_stencil(_320, _334);
   uint16_t _339 = (uint16_t)(15);
   uint16_t _340 = _338 * _339;
   uint16_t _341 = _hw_input_global_wrapper_stencil(_316, _334);
   uint16_t _342 = _341 * _326;
   uint16_t _343 = _340 + _342;
   uint16_t _344 = _337 + _343;
   uint16_t _345 = _333 + _344;
   uint16_t _346 = _330 + _345;
   uint16_t _347 = _327 + _346;
   uint16_t _348 = _323 + _347;
   uint16_t _349 = _319 + _348;
   uint16_t _350 = _315 + _349;
   uint16_t _351 = _314 + _350;
   _conv0_stencil(_conv0_s1_x_x, _conv0_s1_y) = _351;
  } // for conv0_s1_x_x
 } // for conv0_s1_y
 // consume conv0.stencil
[, ], [, ] // produce conv1.stencil
 for (int conv1_s0_y = 0; conv1_s0_y < 60; conv1_s0_y++)
 {
  for (int conv1_s0_x = 0; conv1_s0_x < 60; conv1_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _354 = (uint16_t)(0);
   _conv1_stencil(_conv1_s0_x, _conv1_s0_y) = _354;
  } // for conv1_s0_x
 } // for conv1_s0_y
 for (int conv1_s1_y = 0; conv1_s1_y < 60; conv1_s1_y++)
 {
  for (int conv1_s1_x_x = 0; conv1_s1_x_x < 60; conv1_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _407 = _conv0_stencil(_conv1_s1_x_x, _conv1_s1_y);
   uint16_t _408 = (uint16_t)(17);
   uint16_t _409 = _407 * _408;
   uint16_t _410 = _conv1_stencil(_conv1_s1_x_x, _conv1_s1_y);
   int32_t _411 = _conv1_s1_x_x + 1;
   uint16_t _412 = _conv0_stencil(_411, _conv1_s1_y);
   uint16_t _413 = (uint16_t)(7);
   uint16_t _414 = _412 * _413;
   int32_t _415 = _conv1_s1_x_x + 2;
   uint16_t _416 = _conv0_stencil(_415, _conv1_s1_y);
   uint16_t _417 = (uint16_t)(5);
   uint16_t _418 = _416 * _417;
   int32_t _419 = _conv1_s1_y + 1;
   uint16_t _420 = _conv0_stencil(_conv1_s1_x_x, _419);
   uint16_t _421 = (uint16_t)(4);
   uint16_t _422 = _420 * _421;
   uint16_t _423 = _conv0_stencil(_411, _419);
   uint16_t _424 = (uint16_t)(19);
   uint16_t _425 = _423 * _424;
   uint16_t _426 = _conv0_stencil(_415, _419);
   uint16_t _427 = (uint16_t)(21);
   uint16_t _428 = _426 * _427;
   int32_t _429 = _conv1_s1_y + 2;
   uint16_t _430 = _conv0_stencil(_conv1_s1_x_x, _429);
   uint16_t _431 = (uint16_t)(6);
   uint16_t _432 = _430 * _431;
   uint16_t _433 = _conv0_stencil(_415, _429);
   uint16_t _434 = (uint16_t)(15);
   uint16_t _435 = _433 * _434;
   uint16_t _436 = _conv0_stencil(_411, _429);
   uint16_t _437 = _436 * _421;
   uint16_t _438 = _435 + _437;
   uint16_t _439 = _432 + _438;
   uint16_t _440 = _428 + _439;
   uint16_t _441 = _425 + _440;
   uint16_t _442 = _422 + _441;
   uint16_t _443 = _418 + _442;
   uint16_t _444 = _414 + _443;
   uint16_t _445 = _410 + _444;
   uint16_t _446 = _409 + _445;
   _conv1_stencil(_conv1_s1_x_x, _conv1_s1_y) = _446;
  } // for conv1_s1_x_x
 } // for conv1_s1_y
 // consume conv1.stencil
[, ], [, ] // produce conv2.stencil
 for (int conv2_s0_y = 0; conv2_s0_y < 58; conv2_s0_y++)
 {
  for (int conv2_s0_x = 0; conv2_s0_x < 58; conv2_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _449 = (uint16_t)(0);
   _conv2_stencil(_conv2_s0_x, _conv2_s0_y) = _449;
  } // for conv2_s0_x
 } // for conv2_s0_y
 for (int conv2_s1_y = 0; conv2_s1_y < 58; conv2_s1_y++)
 {
  for (int conv2_s1_x_x = 0; conv2_s1_x_x < 58; conv2_s1_x_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _502 = _conv1_stencil(_conv2_s1_x_x, _conv2_s1_y);
   uint16_t _503 = (uint16_t)(17);
   uint16_t _504 = _502 * _503;
   uint16_t _505 = _conv2_stencil(_conv2_s1_x_x, _conv2_s1_y);
   int32_t _506 = _conv2_s1_x_x + 1;
   uint16_t _507 = _conv1_stencil(_506, _conv2_s1_y);
   uint16_t _508 = (uint16_t)(7);
   uint16_t _509 = _507 * _508;
   int32_t _510 = _conv2_s1_x_x + 2;
   uint16_t _511 = _conv1_stencil(_510, _conv2_s1_y);
   uint16_t _512 = (uint16_t)(5);
   uint16_t _513 = _511 * _512;
   int32_t _514 = _conv2_s1_y + 1;
   uint16_t _515 = _conv1_stencil(_conv2_s1_x_x, _514);
   uint16_t _516 = (uint16_t)(4);
   uint16_t _517 = _515 * _516;
   uint16_t _518 = _conv1_stencil(_506, _514);
   uint16_t _519 = (uint16_t)(19);
   uint16_t _520 = _518 * _519;
   uint16_t _521 = _conv1_stencil(_510, _514);
   uint16_t _522 = (uint16_t)(21);
   uint16_t _523 = _521 * _522;
   int32_t _524 = _conv2_s1_y + 2;
   uint16_t _525 = _conv1_stencil(_conv2_s1_x_x, _524);
   uint16_t _526 = (uint16_t)(6);
   uint16_t _527 = _525 * _526;
   uint16_t _528 = _conv1_stencil(_510, _524);
   uint16_t _529 = (uint16_t)(15);
   uint16_t _530 = _528 * _529;
   uint16_t _531 = _conv1_stencil(_506, _524);
   uint16_t _532 = _531 * _516;
   uint16_t _533 = _530 + _532;
   uint16_t _534 = _527 + _533;
   uint16_t _535 = _523 + _534;
   uint16_t _536 = _520 + _535;
   uint16_t _537 = _517 + _536;
   uint16_t _538 = _513 + _537;
   uint16_t _539 = _509 + _538;
   uint16_t _540 = _505 + _539;
   uint16_t _541 = _504 + _540;
   _conv2_stencil(_conv2_s1_x_x, _conv2_s1_y) = _541;
  } // for conv2_s1_x_x
 } // for conv2_s1_y
 // consume conv2.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 58; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 58; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _542 = _conv2_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _542;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_chain

