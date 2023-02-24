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
[, ], [, ] // produce conv.stencil
 for (int conv_s0_y = 0; conv_s0_y < 62; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 62; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _259;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 62; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 62; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _302 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _303 = (uint16_t)(11);
   uint16_t _304 = _302 * _303;
   uint16_t _305 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   int32_t _306 = _conv_s1_x + 2;
   uint16_t _307 = _hw_input_global_wrapper_stencil(_306, _conv_s1_y);
   uint16_t _308 = (uint16_t)(17);
   uint16_t _309 = _307 * _308;
   int32_t _310 = _conv_s1_y + 1;
   uint16_t _311 = _hw_input_global_wrapper_stencil(_conv_s1_x, _310);
   uint16_t _312 = (uint16_t)(12);
   uint16_t _313 = _311 * _312;
   uint16_t _314 = _hw_input_global_wrapper_stencil(_306, _310);
   uint16_t _315 = (uint16_t)(18);
   uint16_t _316 = _314 * _315;
   int32_t _317 = _conv_s1_y + 2;
   uint16_t _318 = _hw_input_global_wrapper_stencil(_conv_s1_x, _317);
   uint16_t _319 = (uint16_t)(13);
   uint16_t _320 = _318 * _319;
   uint16_t _321 = _hw_input_global_wrapper_stencil(_306, _317);
   uint16_t _322 = (uint16_t)(19);
   uint16_t _323 = _321 * _322;
   int32_t _324 = _conv_s1_x + 1;
   uint16_t _325 = _hw_input_global_wrapper_stencil(_324, _317);
   uint16_t _326 = (uint16_t)(16);
   uint16_t _327 = _325 * _326;
   uint16_t _328 = _323 + _327;
   uint16_t _329 = _320 + _328;
   uint16_t _330 = _316 + _329;
   uint16_t _331 = _313 + _330;
   uint16_t _332 = _309 + _331;
   uint16_t _333 = _305 + _332;
   uint16_t _334 = _304 + _333;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _334;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 62; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 62; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _335 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _335;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_3_3

