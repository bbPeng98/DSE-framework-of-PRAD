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
 Stencil<int16_t, 64, 64> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 64, 64> &hw_output_stencil = arg_1;
[, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 64; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 64; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int16_t _256 = _hw_input_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _256;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 64; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 64; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   int16_t _279 = (int16_t)(30);
   int16_t _280 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   int16_t _281 = (int16_t)(-100);
   int16_t _282 = _280 + _281;
   int16_t _283 = (int16_t)(0);
   int16_t _284 = _283 - _282;
   bool _285 = _282 > _283;
   int16_t _286 = (int16_t)(_285 ? _282 : _284);
   uint16_t _287 = (uint16_t)(_286);
   uint16_t _288 = _287;
   int16_t _289 = (int16_t)(_288);
   int16_t _290 = _279 - _289;
   int16_t _291 = _289 - _279;
   bool _292 = _289 < _279;
   int16_t _293 = (int16_t)(_292 ? _290 : _291);
   uint16_t _294 = (uint16_t)(_293);
   uint16_t _295 = _294;
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _295;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetabsolute

