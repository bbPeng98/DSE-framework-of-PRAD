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
 Stencil<int16_t, 8, 30, 30> &hw_input_stencil = arg_0;
 Stencil<int16_t, 8, 3, 3, 3> &hw_kernel_stencil = arg_1;
 Stencil<int16_t, 28, 28, 3> &hw_output_stencil = arg_2;
[, ], [, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = 0; hw_input_global_wrapper_s0_y < 30; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = 0; hw_input_global_wrapper_s0_x < 30; hw_input_global_wrapper_s0_x++)
  {
   for (int hw_input_global_wrapper_s0_z = 0; hw_input_global_wrapper_s0_z < 8; hw_input_global_wrapper_s0_z++)
   {
#pragma HLS PIPELINE II=1
    int16_t _669 = _hw_input_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
    _hw_input_global_wrapper_stencil(_hw_input_global_wrapper_s0_z, _hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y) = _669;
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
    for (int hw_kernel_global_wrapper_s0_z = 0; hw_kernel_global_wrapper_s0_z < 8; hw_kernel_global_wrapper_s0_z++)
    {
#pragma HLS PIPELINE II=1
     int16_t _670 = _hw_kernel_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y);
     _hw_kernel_global_wrapper_stencil(_hw_kernel_global_wrapper_s0_z, _hw_kernel_global_wrapper_s0_w, _hw_kernel_global_wrapper_s0_x, _hw_kernel_global_wrapper_s0_y) = _670;
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
   int16_t _673 = (int16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 0) = _673;
   int16_t _676 = (int16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 1) = _676;
   int16_t _679 = (int16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y, 2) = _679;
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
     int16_t _712 = _hw_kernel_global_wrapper_stencil(0, 0, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _713 = _conv_s1_r_x + _conv_s1_x;
     int32_t _714 = _conv_s1_r_y + _conv_s1_y;
     int16_t _715 = _hw_input_global_wrapper_stencil(0, _713, _714);
     int16_t _716 = _712 * _715;
     int16_t _717 = _conv_stencil(_conv_s1_x, _conv_s1_y, 0);
     int16_t _718 = _hw_kernel_global_wrapper_stencil(1, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _719 = _hw_input_global_wrapper_stencil(1, _713, _714);
     int16_t _720 = _718 * _719;
     int16_t _721 = _hw_kernel_global_wrapper_stencil(2, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _722 = _hw_input_global_wrapper_stencil(2, _713, _714);
     int16_t _723 = _721 * _722;
     int16_t _724 = _hw_kernel_global_wrapper_stencil(3, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _725 = _hw_input_global_wrapper_stencil(3, _713, _714);
     int16_t _726 = _724 * _725;
     int16_t _727 = _hw_kernel_global_wrapper_stencil(4, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _728 = _hw_input_global_wrapper_stencil(4, _713, _714);
     int16_t _729 = _727 * _728;
     int16_t _730 = _hw_kernel_global_wrapper_stencil(5, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _731 = _hw_input_global_wrapper_stencil(5, _713, _714);
     int16_t _732 = _730 * _731;
     int16_t _733 = _hw_kernel_global_wrapper_stencil(7, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _734 = _hw_input_global_wrapper_stencil(7, _713, _714);
     int16_t _735 = _733 * _734;
     int16_t _736 = _hw_kernel_global_wrapper_stencil(6, 0, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _737 = _hw_input_global_wrapper_stencil(6, _713, _714);
     int16_t _738 = _736 * _737;
     int16_t _739 = _735 + _738;
     int16_t _740 = _732 + _739;
     int16_t _741 = _729 + _740;
     int16_t _742 = _726 + _741;
     int16_t _743 = _723 + _742;
     int16_t _744 = _720 + _743;
     int16_t _745 = _717 + _744;
     int16_t _746 = _716 + _745;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 0) = _746;
     int16_t _779 = _hw_kernel_global_wrapper_stencil(0, 1, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _780 = _conv_s1_r_x + _conv_s1_x;
     int32_t _781 = _conv_s1_r_y + _conv_s1_y;
     int16_t _782 = _hw_input_global_wrapper_stencil(0, _780, _781);
     int16_t _783 = _779 * _782;
     int16_t _784 = _conv_stencil(_conv_s1_x, _conv_s1_y, 1);
     int16_t _785 = _hw_kernel_global_wrapper_stencil(1, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _786 = _hw_input_global_wrapper_stencil(1, _780, _781);
     int16_t _787 = _785 * _786;
     int16_t _788 = _hw_kernel_global_wrapper_stencil(2, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _789 = _hw_input_global_wrapper_stencil(2, _780, _781);
     int16_t _790 = _788 * _789;
     int16_t _791 = _hw_kernel_global_wrapper_stencil(3, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _792 = _hw_input_global_wrapper_stencil(3, _780, _781);
     int16_t _793 = _791 * _792;
     int16_t _794 = _hw_kernel_global_wrapper_stencil(4, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _795 = _hw_input_global_wrapper_stencil(4, _780, _781);
     int16_t _796 = _794 * _795;
     int16_t _797 = _hw_kernel_global_wrapper_stencil(5, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _798 = _hw_input_global_wrapper_stencil(5, _780, _781);
     int16_t _799 = _797 * _798;
     int16_t _800 = _hw_kernel_global_wrapper_stencil(7, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _801 = _hw_input_global_wrapper_stencil(7, _780, _781);
     int16_t _802 = _800 * _801;
     int16_t _803 = _hw_kernel_global_wrapper_stencil(6, 1, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _804 = _hw_input_global_wrapper_stencil(6, _780, _781);
     int16_t _805 = _803 * _804;
     int16_t _806 = _802 + _805;
     int16_t _807 = _799 + _806;
     int16_t _808 = _796 + _807;
     int16_t _809 = _793 + _808;
     int16_t _810 = _790 + _809;
     int16_t _811 = _787 + _810;
     int16_t _812 = _784 + _811;
     int16_t _813 = _783 + _812;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 1) = _813;
     int16_t _846 = _hw_kernel_global_wrapper_stencil(0, 2, _conv_s1_r_x, _conv_s1_r_y);
     int32_t _847 = _conv_s1_r_x + _conv_s1_x;
     int32_t _848 = _conv_s1_r_y + _conv_s1_y;
     int16_t _849 = _hw_input_global_wrapper_stencil(0, _847, _848);
     int16_t _850 = _846 * _849;
     int16_t _851 = _conv_stencil(_conv_s1_x, _conv_s1_y, 2);
     int16_t _852 = _hw_kernel_global_wrapper_stencil(1, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _853 = _hw_input_global_wrapper_stencil(1, _847, _848);
     int16_t _854 = _852 * _853;
     int16_t _855 = _hw_kernel_global_wrapper_stencil(2, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _856 = _hw_input_global_wrapper_stencil(2, _847, _848);
     int16_t _857 = _855 * _856;
     int16_t _858 = _hw_kernel_global_wrapper_stencil(3, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _859 = _hw_input_global_wrapper_stencil(3, _847, _848);
     int16_t _860 = _858 * _859;
     int16_t _861 = _hw_kernel_global_wrapper_stencil(4, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _862 = _hw_input_global_wrapper_stencil(4, _847, _848);
     int16_t _863 = _861 * _862;
     int16_t _864 = _hw_kernel_global_wrapper_stencil(5, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _865 = _hw_input_global_wrapper_stencil(5, _847, _848);
     int16_t _866 = _864 * _865;
     int16_t _867 = _hw_kernel_global_wrapper_stencil(7, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _868 = _hw_input_global_wrapper_stencil(7, _847, _848);
     int16_t _869 = _867 * _868;
     int16_t _870 = _hw_kernel_global_wrapper_stencil(6, 2, _conv_s1_r_x, _conv_s1_r_y);
     int16_t _871 = _hw_input_global_wrapper_stencil(6, _847, _848);
     int16_t _872 = _870 * _871;
     int16_t _873 = _869 + _872;
     int16_t _874 = _866 + _873;
     int16_t _875 = _863 + _874;
     int16_t _876 = _860 + _875;
     int16_t _877 = _857 + _876;
     int16_t _878 = _854 + _877;
     int16_t _879 = _851 + _878;
     int16_t _880 = _850 + _879;
     _conv_stencil(_conv_s1_x, _conv_s1_y, 2) = _880;
    } // for conv_s1_x
   } // for conv_s1_y
  } // for conv_s1_r_x
 } // for conv_s1_r_y
 // consume conv.stencil
 for (int hw_output_s0_w = 0; hw_output_s0_w < 3; hw_output_s0_w++)
 {
  for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 28; hw_output_s0_y_yi++)
  {
   for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 28; hw_output_s0_x_xi++)
   {
#pragma HLS PIPELINE II=1
    int16_t _885 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_w);
    int16_t _886 = (int16_t)(0);
    int16_t _887 = ::halide_cpp_max(_885, _886);
    _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi, _hw_output_s0_w) = _887;
   } // for hw_output_s0_x_xi
  } // for hw_output_s0_y_yi
 } // for hw_output_s0_w
} // kernel hls_targetresnet_pond_layer

