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
 Stencil<int16_t, 64, 64> &hw_output_stencil = arg_1;
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
   int16_t _285 = (int16_t)(255);
   int16_t _286 = (int16_t)(0);
   int16_t _287 = _hw_input_global_wrapper_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   int16_t _288 = (int16_t)(100);
   bool _289 = _287 < _288;
   int16_t _290 = (int16_t)(-16);
   bool _291 = _290 < _287;
   bool _292 = _289 && _291;
   int16_t _293 = (int16_t)(42);
   bool _294 = _287 <= _293;
   bool _295 = _292 && _294;
   int16_t _296 = (int16_t)(-1);
   bool _297 = _296 <= _287;
   bool _298 = _295 && _297;
   int16_t _299 = (int16_t)(_298 ? _285 : _286);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _299;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetscomp

