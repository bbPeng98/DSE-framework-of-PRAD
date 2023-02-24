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
[, ], [, ] // produce brighten.stencil
 for (int brighten_s0_y = 0; brighten_s0_y < 64; brighten_s0_y++)
 {
  for (int brighten_s0_x = 0; brighten_s0_x < 64; brighten_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _261 = _hw_input_global_wrapper_stencil(_brighten_s0_x, _brighten_s0_y);
   uint16_t _262 = (uint16_t)(2);
   uint16_t _263 = _261 * _262;
   _brighten_stencil(_brighten_s0_x, _brighten_s0_y) = _263;
  } // for brighten_s0_x
 } // for brighten_s0_y
 // consume brighten.stencil
[, ], [, ] // produce blur.stencil
 for (int blur_s0_y = 0; blur_s0_y < 63; blur_s0_y++)
 {
  for (int blur_s0_x = 0; blur_s0_x < 63; blur_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _266 = (uint16_t)(0);
   _blur_stencil(_blur_s0_x, _blur_s0_y) = _266;
  } // for blur_s0_x
 } // for blur_s0_y
 for (int blur_s1_y = 0; blur_s1_y < 63; blur_s1_y++)
 {
  for (int blur_s1_x = 0; blur_s1_x < 63; blur_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _275 = _brighten_stencil(_blur_s1_x, _blur_s1_y);
   uint16_t _276 = _blur_stencil(_blur_s1_x, _blur_s1_y);
   int32_t _277 = _blur_s1_x + 1;
   uint16_t _278 = _brighten_stencil(_277, _blur_s1_y);
   int32_t _279 = _blur_s1_y + 1;
   uint16_t _280 = _brighten_stencil(_277, _279);
   uint16_t _281 = _brighten_stencil(_blur_s1_x, _279);
   uint16_t _282 = _280 + _281;
   uint16_t _283 = _278 + _282;
   uint16_t _284 = _276 + _283;
   uint16_t _285 = _275 + _284;
   _blur_stencil(_blur_s1_x, _blur_s1_y) = _285;
  } // for blur_s1_x
 } // for blur_s1_y
 // consume blur.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 63; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 63; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _290 = _blur_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   uint16_t _291 = (uint16_t)(2);
   uint16_t _292 = _290 >> _291;
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _292;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetbrighten_and_blur

