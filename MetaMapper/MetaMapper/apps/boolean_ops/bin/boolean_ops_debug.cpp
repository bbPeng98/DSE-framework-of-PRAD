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
 Stencil<int16_t, 64, 64> &hw_output_stencil = arg_1;
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
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 64; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 64; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   int16_t _275 = (int16_t)(200);
   int16_t _276 = (int16_t)(0);
   uint16_t _277 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   uint16_t _278 = (uint16_t)(64);
   bool _279 = _277 < _278;
   uint16_t _280 = (uint16_t)(128);
   bool _281 = _280 <= _277;
   bool _282 = _279 || _281;
   bool _283 = _282 ^ _281;
   int16_t _284 = (int16_t)(_283 ? _275 : _276);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _284;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetboolean_ops

