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
 Stencil<uint16_t, 4, 30, 30> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 4, 3, 3, 3> &hw_kernel_stencil = arg_1;
 Stencil<uint16_t, 28, 28, 3> &hw_output_stencil = arg_2;
[, ], [, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 30; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 30; hw_input_global_wrapper_s0_x++)
  {
   for (int hw_input_global_wrapper_s0_z = 0; hw_input_global_wrapper_s0_z < 4; hw_input_global_wrapper_s0_z++)
   {
#pragma HLS PIPELINE II=1
    uint16_t _664 = _hw_input_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
    _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _664;
   } // for hw_input_global_wrapper_s0_z
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ], [, ], [, ] // produce hw_kernel_global_wrapper.stencil
 for (int hw_kernel_global_wrapper_s0_y = 0; hw_kernel_global_wrapper_s0_y < 3; hw_kernel_global_wrapper_s0_y++)
 {
  for (int hw_kernel_global_wrapper_s0_x = 0; hw_kernel_global_wrapper_s0_x < 3; hw_kernel_global_wrapper_s0_x++)
  {
   for (int hw_kernel_global_wrapper_s0_w = 0; hw_kernel_global_wrapper_s0_w < 3; hw_kernel_global_wrapper_s0_w++)
   {
    for (int hw_kernel_global_wrapper_s0_z = 0; hw_kernel_global_wrapper_s0_z < 4; hw_kernel_global_wrapper_s0_z++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _665 = _hw_kernel_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y);
     _hw_kernel_global_wrapper_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y) = _665;
    } // for hw_kernel_global_wrapper_s0_z
   } // for hw_kernel_global_wrapper_s0_w
  } // for hw_kernel_global_wrapper_s0_x
 } // for hw_kernel_global_wrapper_s0_y
 // consume hw_kernel_global_wrapper.stencil
[, ], [, ], [, ] // produce conv.stencil
 for (int conv_s0_y = 0; conv_s0_y < 28; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 28; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _668 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 0) = _668;
   uint16_t _671 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 1) = _671;
   uint16_t _674 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 2) = _674;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_r_y = 0; conv_s1_r_y < 3; conv_s1_r_y++)
 {
  for (int conv_s1_r_x = 0; conv_s1_r_x < 3; conv_s1_r_x++)
  {
   for (int conv_s1_y = 0; conv_s1_y < 28; conv_s1_y++)
   {
    for (int conv_s1_x = 0; conv_s1_x < 28; conv_s1_x++)
    {
#pragma HLS PIPELINE II=1
     uint16_t _691 = _hw_kernel_global_wrapper_stencil(0, 0, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _692 = _conv_s1_r_x + _conv_s1_x;
     int32_t _693 = _conv_s1_r_y + _conv_s1_y;
     uint16_t _694 = _hw_input_global_wrapper_stencil(0, _692, _693);
     uint16_t _695 = _691 * _694;
     uint16_t _696 = _conv_stencil(_conv_s1_x, _conv_s1_y, 0);
     uint16_t _697 = _hw_kernel_global_wrapper_stencil(1, 0, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _698 = _hw_input_global_wrapper_stencil(1, _692, _693);
     uint16_t _699 = _697 * _698;
     uint16_t _700 = _hw_kernel_global_wrapper_stencil(3, 0, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _701 = _hw_input_global_wrapper_stencil(3, _692, _693);
     uint16_t _702 = _700 * _701;
     uint16_t _703 = _hw_kernel_global_wrapper_stencil(2, 0, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _704 = _hw_input_global_wrapper_stencil(2, _692, _693);
     uint16_t _705 = _703 * _704;
     uint16_t _706 = _702 + _705;
     uint16_t _707 = _699 + _706;
     uint16_t _708 = _696 + _707;
     uint16_t _709 = _695 + _708;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 0) = _709;
     uint16_t _726 = _hw_kernel_global_wrapper_stencil(0, 1, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _727 = _conv_s1_r_x + _conv_s1_x;
     int32_t _728 = _conv_s1_r_y + _conv_s1_y;
     uint16_t _729 = _hw_input_global_wrapper_stencil(0, _727, _728);
     uint16_t _730 = _726 * _729;
     uint16_t _731 = _conv_stencil(_conv_s1_x, _conv_s1_y, 1);
     uint16_t _732 = _hw_kernel_global_wrapper_stencil(1, 1, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _733 = _hw_input_global_wrapper_stencil(1, _727, _728);
     uint16_t _734 = _732 * _733;
     uint16_t _735 = _hw_kernel_global_wrapper_stencil(3, 1, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _736 = _hw_input_global_wrapper_stencil(3, _727, _728);
     uint16_t _737 = _735 * _736;
     uint16_t _738 = _hw_kernel_global_wrapper_stencil(2, 1, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _739 = _hw_input_global_wrapper_stencil(2, _727, _728);
     uint16_t _740 = _738 * _739;
     uint16_t _741 = _737 + _740;
     uint16_t _742 = _734 + _741;
     uint16_t _743 = _731 + _742;
     uint16_t _744 = _730 + _743;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 1) = _744;
     uint16_t _761 = _hw_kernel_global_wrapper_stencil(0, 2, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _762 = _conv_s1_r_x + _conv_s1_x;
     int32_t _763 = _conv_s1_r_y + _conv_s1_y;
     uint16_t _764 = _hw_input_global_wrapper_stencil(0, _762, _763);
     uint16_t _765 = _761 * _764;
     uint16_t _766 = _conv_stencil(_conv_s1_x, _conv_s1_y, 2);
     uint16_t _767 = _hw_kernel_global_wrapper_stencil(1, 2, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _768 = _hw_input_global_wrapper_stencil(1, _762, _763);
     uint16_t _769 = _767 * _768;
     uint16_t _770 = _hw_kernel_global_wrapper_stencil(3, 2, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _771 = _hw_input_global_wrapper_stencil(3, _762, _763);
     uint16_t _772 = _770 * _771;
     uint16_t _773 = _hw_kernel_global_wrapper_stencil(2, 2, _conv_s1_r_x, _conv_s1_r_y);
     uint16_t _774 = _hw_input_global_wrapper_stencil(2, _762, _763);
     uint16_t _775 = _773 * _774;
     uint16_t _776 = _772 + _775;
     uint16_t _777 = _769 + _776;
     uint16_t _778 = _766 + _777;
     uint16_t _779 = _765 + _778;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 2) = _779;
    } // for conv_s1_x
   } // for conv_s1_y
  } // for conv_s1_r_x
 } // for conv_s1_r_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _780 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, 0);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, 0) = _780;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _781 = _conv_stencil(_hw_output_s0_x_xi_1, _hw_output_s0_y_yi_1, 1);
   _hw_output_stencil(_hw_output_s0_x_xi_1, _hw_output_s0_y_yi_1, 1) = _781;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _782 = _conv_stencil(_hw_output_s0_x_xi_2, _hw_output_s0_y_yi_2, 2);
   _hw_output_stencil(_hw_output_s0_x_xi_2, _hw_output_s0_y_yi_2, 2) = _782;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetresnet

