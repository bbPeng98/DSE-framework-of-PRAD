)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_0.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_2 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_2.value complete dim=0

 // alias the arguments
 Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 3, 3> &hw_weight_stencil = arg_1;
 Stencil<uint16_t, 62, 62> &hw_output_stencil = arg_2;
[, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 64; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 64; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _390 = _hw_input_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _390;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ] // produce hw_weight_global_wrapper.stencil
 for (int hw_weight_global_wrapper_s0_y = 0; hw_weight_global_wrapper_s0_y < 3; hw_weight_global_wrapper_s0_y++)
 {
  for (int hw_weight_global_wrapper_s0_x = 0; hw_weight_global_wrapper_s0_x < 3; hw_weight_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _391 = _hw_weight_stencil(_hw_weight_global_wrapper_s0_x, _hw_weight_global_wrapper_s0_y);
   _hw_weight_global_wrapper_stencil(_hw_weight_global_wrapper_s0_x, _hw_weight_global_wrapper_s0_y) = _391;
  } // for hw_weight_global_wrapper_s0_x
 } // for hw_weight_global_wrapper_s0_y
 // consume hw_weight_global_wrapper.stencil
[, ], [, ] // produce conv.stencil
 for (int conv_s0_y = 0; conv_s0_y < 62; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 62; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _394 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _394;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 62; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 62; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _431 = _hw_weight_global_wrapper_stencil(0, 0);
   uint16_t _432 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _433 = _431 * _432;
   uint16_t _434 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _435 = _hw_weight_global_wrapper_stencil(1, 0);
   int32_t _436 = _conv_s1_x + 1;
   uint16_t _437 = _hw_input_global_wrapper_stencil(_436, _conv_s1_y);
   uint16_t _438 = _435 * _437;
   uint16_t _439 = _hw_weight_global_wrapper_stencil(2, 0);
   int32_t _440 = _conv_s1_x + 2;
   uint16_t _441 = _hw_input_global_wrapper_stencil(_440, _conv_s1_y);
   uint16_t _442 = _439 * _441;
   uint16_t _443 = _hw_weight_global_wrapper_stencil(0, 1);
   int32_t _444 = _conv_s1_y + 1;
   uint16_t _445 = _hw_input_global_wrapper_stencil(_conv_s1_x, _444);
   uint16_t _446 = _443 * _445;
   uint16_t _447 = _hw_weight_global_wrapper_stencil(1, 1);
   uint16_t _448 = _hw_input_global_wrapper_stencil(_436, _444);
   uint16_t _449 = _447 * _448;
   uint16_t _450 = _hw_weight_global_wrapper_stencil(2, 1);
   uint16_t _451 = _hw_input_global_wrapper_stencil(_440, _444);
   uint16_t _452 = _450 * _451;
   uint16_t _453 = _hw_weight_global_wrapper_stencil(0, 2);
   int32_t _454 = _conv_s1_y + 2;
   uint16_t _455 = _hw_input_global_wrapper_stencil(_conv_s1_x, _454);
   uint16_t _456 = _453 * _455;
   uint16_t _457 = _hw_weight_global_wrapper_stencil(2, 2);
   uint16_t _458 = _hw_input_global_wrapper_stencil(_440, _454);
   uint16_t _459 = _457 * _458;
   uint16_t _460 = _hw_weight_global_wrapper_stencil(1, 2);
   uint16_t _461 = _hw_input_global_wrapper_stencil(_436, _454);
   uint16_t _462 = _460 * _461;
   uint16_t _463 = _459 + _462;
   uint16_t _464 = _456 + _463;
   uint16_t _465 = _452 + _464;
   uint16_t _466 = _449 + _465;
   uint16_t _467 = _446 + _466;
   uint16_t _468 = _442 + _467;
   uint16_t _469 = _438 + _468;
   uint16_t _470 = _434 + _469;
   uint16_t _471 = _433 + _470;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _471;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 62; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 62; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _472 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _472;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_2input

