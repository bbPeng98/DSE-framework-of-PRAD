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
 Stencil<uint16_t, 62, 62> &hw_output_stencil = arg_1;
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
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 62; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 62; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
[, ], [, ]   // produce conv.stencil
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(0, 0) = _259;
   uint16_t _314 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   uint16_t _315 = (uint16_t)(11);
   uint16_t _316 = _314 * _315;
   uint16_t _317 = _conv_stencil(0, 0);
   int32_t _318 = _hw_output_s0_x_xi + 1;
   uint16_t _319 = _hw_input_global_wrapper_stencil(_318, _hw_output_s0_y_yi);
   uint16_t _320 = (uint16_t)(14);
   uint16_t _321 = _319 * _320;
   int32_t _322 = _hw_output_s0_x_xi + 2;
   uint16_t _323 = _hw_input_global_wrapper_stencil(_322, _hw_output_s0_y_yi);
   uint16_t _324 = (uint16_t)(17);
   uint16_t _325 = _323 * _324;
   int32_t _326 = _hw_output_s0_y_yi + 1;
   uint16_t _327 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _326);
   uint16_t _328 = (uint16_t)(12);
   uint16_t _329 = _327 * _328;
   uint16_t _330 = _hw_input_global_wrapper_stencil(_318, _326);
   uint16_t _331 = (uint16_t)(255);
   uint16_t _332 = _330 * _331;
   uint16_t _333 = _hw_input_global_wrapper_stencil(_322, _326);
   uint16_t _334 = (uint16_t)(18);
   uint16_t _335 = _333 * _334;
   int32_t _336 = _hw_output_s0_y_yi + 2;
   uint16_t _337 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _336);
   uint16_t _338 = (uint16_t)(13);
   uint16_t _339 = _337 * _338;
   uint16_t _340 = _hw_input_global_wrapper_stencil(_322, _336);
   uint16_t _341 = (uint16_t)(19);
   uint16_t _342 = _340 * _341;
   uint16_t _343 = _hw_input_global_wrapper_stencil(_318, _336);
   uint16_t _344 = (uint16_t)(16);
   uint16_t _345 = _343 * _344;
   uint16_t _346 = _342 + _345;
   uint16_t _347 = _339 + _346;
   uint16_t _348 = _335 + _347;
   uint16_t _349 = _332 + _348;
   uint16_t _350 = _329 + _349;
   uint16_t _351 = _325 + _350;
   uint16_t _352 = _321 + _351;
   uint16_t _353 = _317 + _352;
   uint16_t _354 = _316 + _353;
   _conv_stencil(0, 0) = _354;
   // consume conv.stencil
   uint16_t _355 = _conv_stencil(0, 0);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _355;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetmem_unbuffered

