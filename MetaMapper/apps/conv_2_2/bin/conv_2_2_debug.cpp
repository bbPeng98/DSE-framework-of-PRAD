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
 Stencil<uint16_t, 63, 63> &hw_output_stencil = arg_1;
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
 for (int conv_s0_y = 0; conv_s0_y < 63; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 63; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _259;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 63; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 63; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _278 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _279 = (uint16_t)(11);
   uint16_t _280 = _278 * _279;
   uint16_t _281 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   int32_t _282 = _conv_s1_y + 1;
   uint16_t _283 = _hw_input_global_wrapper_stencil(_conv_s1_x, _282);
   uint16_t _284 = (uint16_t)(12);
   uint16_t _285 = _283 * _284;
   int32_t _286 = _conv_s1_x + 1;
   uint16_t _287 = _hw_input_global_wrapper_stencil(_286, _conv_s1_y);
   uint16_t _288 = (uint16_t)(14);
   uint16_t _289 = _287 * _288;
   uint16_t _290 = _285 + _289;
   uint16_t _291 = _281 + _290;
   uint16_t _292 = _280 + _291;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _292;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 63; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 63; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _293 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _293;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_2_2

