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
 Stencil<uint16_t, 62, 62, 3> &hw_output_stencil = arg_1;
[, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 64; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 64; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _317 = _hw_input_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _317;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ], [, ] // produce conv.stencil
 for (int conv_s0_z = 0; conv_s0_z < 3; conv_s0_z++)
 {
  for (int conv_s0_y = 0; conv_s0_y < 62; conv_s0_y++)
  {
   for (int conv_s0_x = 0; conv_s0_x < 62; conv_s0_x++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _320 = (uint16_t)(0);
    _conv_stencil(_conv_s0_x, _conv_s0_y, _conv_s0_z) = _320;
   } // for conv_s0_x
  } // for conv_s0_y
 } // for conv_s0_z
 for (int conv_s1_z = 0; conv_s1_z < 3; conv_s1_z++)
 {
  for (int conv_s1_y = 0; conv_s1_y < 62; conv_s1_y++)
  {
   for (int conv_s1_x = 0; conv_s1_x < 62; conv_s1_x++)
   {
#pragma HLS PIPELINE II=1
    int32_t kernela0[27];
    // produce kernela0
    int32_t _321 = _conv_s1_z * 9;
    int32_t _322 = _321 + 8;
    _kernela0[_322] = 0;
    _kernela0[0] = 11;
    _kernela0[3] = 12;
    _kernela0[6] = 13;
    _kernela0[1] = 14;
    _kernela0[4] = 0;
    _kernela0[7] = 16;
    _kernela0[2] = 17;
    _kernela0[5] = 18;
    _kernela0[8] = 19;
    _kernela0[9] = 21;
    _kernela0[12] = 22;
    _kernela0[15] = 23;
    _kernela0[10] = 24;
    _kernela0[13] = 2;
    _kernela0[16] = 26;
    _kernela0[11] = 27;
    _kernela0[14] = 28;
    _kernela0[17] = 29;
    _kernela0[18] = 31;
    _kernela0[21] = 32;
    _kernela0[24] = 33;
    _kernela0[19] = 34;
    _kernela0[22] = 3;
    _kernela0[25] = 36;
    _kernela0[20] = 37;
    _kernela0[23] = 38;
    _kernela0[26] = 39;
    // consume kernela0
    uint16_t _449 = _conv_stencil(_conv_s1_x, _conv_s1_y, _conv_s1_z);
    int32_t _450 = _conv_s1_z * 9;
    int32_t _451 = _kernela0[_450];
    uint16_t _452 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
    int32_t _453 = (int32_t)(_452);
    int32_t _454 = _451 * _453;
    uint16_t _455 = (uint16_t)(_454);
    uint16_t _456 = _449 + _455;
    int32_t _457 = _450 + 1;
    int32_t _458 = _kernela0[_457];
    int32_t _459 = _conv_s1_x + 1;
    uint16_t _460 = _hw_input_global_wrapper_stencil(_459, _conv_s1_y);
    int32_t _461 = (int32_t)(_460);
    int32_t _462 = _458 * _461;
    uint16_t _463 = (uint16_t)(_462);
    uint16_t _464 = _456 + _463;
    int32_t _465 = _450 + 2;
    int32_t _466 = _kernela0[_465];
    int32_t _467 = _conv_s1_x + 2;
    uint16_t _468 = _hw_input_global_wrapper_stencil(_467, _conv_s1_y);
    int32_t _469 = (int32_t)(_468);
    int32_t _470 = _466 * _469;
    uint16_t _471 = (uint16_t)(_470);
    uint16_t _472 = _464 + _471;
    int32_t _473 = _450 + 3;
    int32_t _474 = _kernela0[_473];
    int32_t _475 = _conv_s1_y + 1;
    uint16_t _476 = _hw_input_global_wrapper_stencil(_conv_s1_x, _475);
    int32_t _477 = (int32_t)(_476);
    int32_t _478 = _474 * _477;
    uint16_t _479 = (uint16_t)(_478);
    uint16_t _480 = _472 + _479;
    int32_t _481 = _450 + 4;
    int32_t _482 = _kernela0[_481];
    uint16_t _483 = _hw_input_global_wrapper_stencil(_459, _475);
    int32_t _484 = (int32_t)(_483);
    int32_t _485 = _482 * _484;
    uint16_t _486 = (uint16_t)(_485);
    uint16_t _487 = _480 + _486;
    int32_t _488 = _450 + 5;
    int32_t _489 = _kernela0[_488];
    uint16_t _490 = _hw_input_global_wrapper_stencil(_467, _475);
    int32_t _491 = (int32_t)(_490);
    int32_t _492 = _489 * _491;
    uint16_t _493 = (uint16_t)(_492);
    uint16_t _494 = _487 + _493;
    int32_t _495 = _450 + 6;
    int32_t _496 = _kernela0[_495];
    int32_t _497 = _conv_s1_y + 2;
    uint16_t _498 = _hw_input_global_wrapper_stencil(_conv_s1_x, _497);
    int32_t _499 = (int32_t)(_498);
    int32_t _500 = _496 * _499;
    uint16_t _501 = (uint16_t)(_500);
    uint16_t _502 = _494 + _501;
    int32_t _503 = _450 + 7;
    int32_t _504 = _kernela0[_503];
    uint16_t _505 = _hw_input_global_wrapper_stencil(_459, _497);
    int32_t _506 = (int32_t)(_505);
    int32_t _507 = _504 * _506;
    uint16_t _508 = (uint16_t)(_507);
    uint16_t _509 = _502 + _508;
    int32_t _510 = _450 + 8;
    int32_t _511 = _kernela0[_510];
    uint16_t _512 = _hw_input_global_wrapper_stencil(_467, _497);
    int32_t _513 = (int32_t)(_512);
    int32_t _514 = _511 * _513;
    uint16_t _515 = (uint16_t)(_514);
    uint16_t _516 = _509 + _515;
    _conv_stencil(_conv_s1_x, _conv_s1_y, _conv_s1_z) = _516;
   } // for conv_s1_x
  } // for conv_s1_y
 } // for conv_s1_z
 // consume conv.stencil
 for (int hw_output_s0_z = 0; hw_output_s0_z < 3; hw_output_s0_z++)
 {
  for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 62; hw_output_s0_y_yi++)
  {
   for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 62; hw_output_s0_x_xi++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _517 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_z);
    _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_z) = _517;
   } // for hw_output_s0_x_xi
  } // for hw_output_s0_y_yi
 } // for hw_output_s0_z
} // kernel hls_targetmulti_channel_conv

