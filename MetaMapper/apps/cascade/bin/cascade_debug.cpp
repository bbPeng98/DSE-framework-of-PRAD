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
[, ], [, ] // produce conv1.stencil
 for (int conv1_s0_y = 0; conv1_s0_y < 62; conv1_s0_y++)
 {
  for (int conv1_s0_x = 0; conv1_s0_x < 62; conv1_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv1_stencil(_conv1_s0_x, _conv1_s0_y) = _259;
  } // for conv1_s0_x
 } // for conv1_s0_y
 for (int conv1_s1_y = 0; conv1_s1_y < 62; conv1_s1_y++)
 {
  for (int conv1_s1_x = 0; conv1_s1_x < 62; conv1_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _292 = _hw_input_global_wrapper_stencil(_conv1_s1_x, _conv1_s1_y);
   uint16_t _293 = _conv1_stencil(_conv1_s1_x, _conv1_s1_y);
   int32_t _294 = _conv1_s1_x + 1;
   uint16_t _295 = _hw_input_global_wrapper_stencil(_294, _conv1_s1_y);
   uint16_t _296 = (uint16_t)(2);
   uint16_t _297 = _295 * _296;
   int32_t _298 = _conv1_s1_x + 2;
   uint16_t _299 = _hw_input_global_wrapper_stencil(_298, _conv1_s1_y);
   int32_t _300 = _conv1_s1_y + 1;
   uint16_t _301 = _hw_input_global_wrapper_stencil(_conv1_s1_x, _300);
   uint16_t _302 = _301 * _296;
   uint16_t _303 = _hw_input_global_wrapper_stencil(_294, _300);
   uint16_t _304 = (uint16_t)(4);
   uint16_t _305 = _303 * _304;
   uint16_t _306 = _hw_input_global_wrapper_stencil(_298, _300);
   uint16_t _307 = _306 * _296;
   int32_t _308 = _conv1_s1_y + 2;
   uint16_t _309 = _hw_input_global_wrapper_stencil(_conv1_s1_x, _308);
   uint16_t _310 = _hw_input_global_wrapper_stencil(_298, _308);
   uint16_t _311 = _hw_input_global_wrapper_stencil(_294, _308);
   uint16_t _312 = _311 * _296;
   uint16_t _313 = _310 + _312;
   uint16_t _314 = _309 + _313;
   uint16_t _315 = _307 + _314;
   uint16_t _316 = _305 + _315;
   uint16_t _317 = _302 + _316;
   uint16_t _318 = _299 + _317;
   uint16_t _319 = _297 + _318;
   uint16_t _320 = _293 + _319;
   uint16_t _321 = _292 + _320;
   _conv1_stencil(_conv1_s1_x, _conv1_s1_y) = _321;
  } // for conv1_s1_x
 } // for conv1_s1_y
 // consume conv1.stencil
[, ], [, ] // produce conv1_shift.stencil
 for (int conv1_shift_s0_y = 0; conv1_shift_s0_y < 62; conv1_shift_s0_y++)
 {
  for (int conv1_shift_s0_x = 0; conv1_shift_s0_x < 62; conv1_shift_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _326 = _conv1_stencil(_conv1_shift_s0_x, _conv1_shift_s0_y);
   uint16_t _327 = (uint16_t)(4);
   uint16_t _328 = _326 >> _327;
   _conv1_shift_stencil(_conv1_shift_s0_x, _conv1_shift_s0_y) = _328;
  } // for conv1_shift_s0_x
 } // for conv1_shift_s0_y
 // consume conv1_shift.stencil
[, ], [, ] // produce conv2.stencil
 for (int conv2_s0_y = 0; conv2_s0_y < 60; conv2_s0_y++)
 {
  for (int conv2_s0_x = 0; conv2_s0_x < 60; conv2_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _331 = (uint16_t)(0);
   _conv2_stencil(_conv2_s0_x, _conv2_s0_y) = _331;
  } // for conv2_s0_x
 } // for conv2_s0_y
 for (int conv2_s1_y = 0; conv2_s1_y < 60; conv2_s1_y++)
 {
  for (int conv2_s1_x = 0; conv2_s1_x < 60; conv2_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _364 = _conv1_shift_stencil(_conv2_s1_x, _conv2_s1_y);
   uint16_t _365 = _conv2_stencil(_conv2_s1_x, _conv2_s1_y);
   int32_t _366 = _conv2_s1_x + 1;
   uint16_t _367 = _conv1_shift_stencil(_366, _conv2_s1_y);
   uint16_t _368 = (uint16_t)(2);
   uint16_t _369 = _367 * _368;
   int32_t _370 = _conv2_s1_x + 2;
   uint16_t _371 = _conv1_shift_stencil(_370, _conv2_s1_y);
   int32_t _372 = _conv2_s1_y + 1;
   uint16_t _373 = _conv1_shift_stencil(_conv2_s1_x, _372);
   uint16_t _374 = _373 * _368;
   uint16_t _375 = _conv1_shift_stencil(_366, _372);
   uint16_t _376 = (uint16_t)(4);
   uint16_t _377 = _375 * _376;
   uint16_t _378 = _conv1_shift_stencil(_370, _372);
   uint16_t _379 = _378 * _368;
   int32_t _380 = _conv2_s1_y + 2;
   uint16_t _381 = _conv1_shift_stencil(_conv2_s1_x, _380);
   uint16_t _382 = _conv1_shift_stencil(_370, _380);
   uint16_t _383 = _conv1_shift_stencil(_366, _380);
   uint16_t _384 = _383 * _368;
   uint16_t _385 = _382 + _384;
   uint16_t _386 = _381 + _385;
   uint16_t _387 = _379 + _386;
   uint16_t _388 = _377 + _387;
   uint16_t _389 = _374 + _388;
   uint16_t _390 = _371 + _389;
   uint16_t _391 = _369 + _390;
   uint16_t _392 = _365 + _391;
   uint16_t _393 = _364 + _392;
   _conv2_stencil(_conv2_s1_x, _conv2_s1_y) = _393;
  } // for conv2_s1_x
 } // for conv2_s1_y
 // consume conv2.stencil
 for (int hw_output_s0_y_xo = 0; hw_output_s0_y_xo < 60; hw_output_s0_y_xo++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 60; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _398 = _conv2_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_xo);
   uint16_t _399 = (uint16_t)(4);
   uint16_t _400 = _398 >> _399;
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_xo) = _400;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_xo
} // kernel hls_targetcascade

