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
 Stencil<uint16_t, 58, 58> &hw_output_stencil = arg_1;
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
 for (int conv_s0_y = 0; conv_s0_y < 58; conv_s0_y++)
 {
  for (int conv_s0_x = 0; conv_s0_x < 58; conv_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _259 = (uint16_t)(0);
   _conv_stencil(_conv_s0_x, _conv_s0_y) = _259;
  } // for conv_s0_x
 } // for conv_s0_y
 for (int conv_s1_y = 0; conv_s1_y < 58; conv_s1_y++)
 {
  for (int conv_s1_x = 0; conv_s1_x < 58; conv_s1_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _528 = _hw_input_global_wrapper_stencil(_conv_s1_x, _conv_s1_y);
   uint16_t _529 = (uint16_t)(11);
   uint16_t _530 = _528 * _529;
   uint16_t _531 = _conv_stencil(_conv_s1_x, _conv_s1_y);
   int32_t _532 = _conv_s1_x + 1;
   uint16_t _533 = _hw_input_global_wrapper_stencil(_532, _conv_s1_y);
   uint16_t _534 = (uint16_t)(14);
   uint16_t _535 = _533 * _534;
   int32_t _536 = _conv_s1_x + 2;
   uint16_t _537 = _hw_input_global_wrapper_stencil(_536, _conv_s1_y);
   uint16_t _538 = (uint16_t)(17);
   uint16_t _539 = _537 * _538;
   int32_t _540 = _conv_s1_x + 3;
   uint16_t _541 = _hw_input_global_wrapper_stencil(_540, _conv_s1_y);
   uint16_t _542 = (uint16_t)(20);
   uint16_t _543 = _541 * _542;
   int32_t _544 = _conv_s1_x + 4;
   uint16_t _545 = _hw_input_global_wrapper_stencil(_544, _conv_s1_y);
   uint16_t _546 = (uint16_t)(30);
   uint16_t _547 = _545 * _546;
   int32_t _548 = _conv_s1_x + 5;
   uint16_t _549 = _hw_input_global_wrapper_stencil(_548, _conv_s1_y);
   uint16_t _550 = (uint16_t)(40);
   uint16_t _551 = _549 * _550;
   int32_t _552 = _conv_s1_x + 6;
   uint16_t _553 = _hw_input_global_wrapper_stencil(_552, _conv_s1_y);
   uint16_t _554 = (uint16_t)(50);
   uint16_t _555 = _553 * _554;
   int32_t _556 = _conv_s1_y + 1;
   uint16_t _557 = _hw_input_global_wrapper_stencil(_conv_s1_x, _556);
   uint16_t _558 = (uint16_t)(12);
   uint16_t _559 = _557 * _558;
   uint16_t _560 = _hw_input_global_wrapper_stencil(_536, _556);
   uint16_t _561 = (uint16_t)(18);
   uint16_t _562 = _560 * _561;
   uint16_t _563 = _hw_input_global_wrapper_stencil(_540, _556);
   uint16_t _564 = (uint16_t)(29);
   uint16_t _565 = _563 * _564;
   uint16_t _566 = _hw_input_global_wrapper_stencil(_544, _556);
   uint16_t _567 = (uint16_t)(39);
   uint16_t _568 = _566 * _567;
   uint16_t _569 = _hw_input_global_wrapper_stencil(_548, _556);
   uint16_t _570 = (uint16_t)(49);
   uint16_t _571 = _569 * _570;
   uint16_t _572 = _hw_input_global_wrapper_stencil(_552, _556);
   uint16_t _573 = (uint16_t)(59);
   uint16_t _574 = _572 * _573;
   int32_t _575 = _conv_s1_y + 2;
   uint16_t _576 = _hw_input_global_wrapper_stencil(_conv_s1_x, _575);
   uint16_t _577 = (uint16_t)(13);
   uint16_t _578 = _576 * _577;
   uint16_t _579 = _hw_input_global_wrapper_stencil(_532, _575);
   uint16_t _580 = (uint16_t)(16);
   uint16_t _581 = _579 * _580;
   uint16_t _582 = _hw_input_global_wrapper_stencil(_536, _575);
   uint16_t _583 = (uint16_t)(19);
   uint16_t _584 = _582 * _583;
   uint16_t _585 = _hw_input_global_wrapper_stencil(_540, _575);
   uint16_t _586 = (uint16_t)(22);
   uint16_t _587 = _585 * _586;
   uint16_t _588 = _hw_input_global_wrapper_stencil(_544, _575);
   uint16_t _589 = (uint16_t)(32);
   uint16_t _590 = _588 * _589;
   uint16_t _591 = _hw_input_global_wrapper_stencil(_548, _575);
   uint16_t _592 = (uint16_t)(42);
   uint16_t _593 = _591 * _592;
   uint16_t _594 = _hw_input_global_wrapper_stencil(_552, _575);
   uint16_t _595 = (uint16_t)(52);
   uint16_t _596 = _594 * _595;
   int32_t _597 = _conv_s1_y + 3;
   uint16_t _598 = _hw_input_global_wrapper_stencil(_conv_s1_x, _597);
   uint16_t _599 = (uint16_t)(23);
   uint16_t _600 = _598 * _599;
   uint16_t _601 = _hw_input_global_wrapper_stencil(_532, _597);
   uint16_t _602 = (uint16_t)(21);
   uint16_t _603 = _601 * _602;
   uint16_t _604 = _hw_input_global_wrapper_stencil(_536, _597);
   uint16_t _605 = (uint16_t)(26);
   uint16_t _606 = _604 * _605;
   uint16_t _607 = _hw_input_global_wrapper_stencil(_540, _597);
   uint16_t _608 = (uint16_t)(24);
   uint16_t _609 = _607 * _608;
   uint16_t _610 = _hw_input_global_wrapper_stencil(_544, _597);
   uint16_t _611 = (uint16_t)(34);
   uint16_t _612 = _610 * _611;
   uint16_t _613 = _hw_input_global_wrapper_stencil(_548, _597);
   uint16_t _614 = (uint16_t)(44);
   uint16_t _615 = _613 * _614;
   uint16_t _616 = _hw_input_global_wrapper_stencil(_552, _597);
   uint16_t _617 = (uint16_t)(54);
   uint16_t _618 = _616 * _617;
   int32_t _619 = _conv_s1_y + 4;
   uint16_t _620 = _hw_input_global_wrapper_stencil(_conv_s1_x, _619);
   uint16_t _621 = (uint16_t)(33);
   uint16_t _622 = _620 * _621;
   uint16_t _623 = _hw_input_global_wrapper_stencil(_532, _619);
   uint16_t _624 = (uint16_t)(31);
   uint16_t _625 = _623 * _624;
   uint16_t _626 = _hw_input_global_wrapper_stencil(_536, _619);
   uint16_t _627 = _626 * _589;
   uint16_t _628 = _hw_input_global_wrapper_stencil(_540, _619);
   uint16_t _629 = _628 * _611;
   uint16_t _630 = _hw_input_global_wrapper_stencil(_544, _619);
   uint16_t _631 = (uint16_t)(37);
   uint16_t _632 = _630 * _631;
   uint16_t _633 = _hw_input_global_wrapper_stencil(_548, _619);
   uint16_t _634 = (uint16_t)(47);
   uint16_t _635 = _633 * _634;
   uint16_t _636 = _hw_input_global_wrapper_stencil(_552, _619);
   uint16_t _637 = (uint16_t)(57);
   uint16_t _638 = _636 * _637;
   int32_t _639 = _conv_s1_y + 5;
   uint16_t _640 = _hw_input_global_wrapper_stencil(_conv_s1_x, _639);
   uint16_t _641 = (uint16_t)(43);
   uint16_t _642 = _640 * _641;
   uint16_t _643 = _hw_input_global_wrapper_stencil(_532, _639);
   uint16_t _644 = (uint16_t)(41);
   uint16_t _645 = _643 * _644;
   uint16_t _646 = _hw_input_global_wrapper_stencil(_536, _639);
   uint16_t _647 = _646 * _592;
   uint16_t _648 = _hw_input_global_wrapper_stencil(_540, _639);
   uint16_t _649 = _648 * _614;
   uint16_t _650 = _hw_input_global_wrapper_stencil(_544, _639);
   uint16_t _651 = _650 * _634;
   uint16_t _652 = _hw_input_global_wrapper_stencil(_548, _639);
   uint16_t _653 = (uint16_t)(48);
   uint16_t _654 = _652 * _653;
   uint16_t _655 = _hw_input_global_wrapper_stencil(_552, _639);
   uint16_t _656 = (uint16_t)(58);
   uint16_t _657 = _655 * _656;
   int32_t _658 = _conv_s1_y + 6;
   uint16_t _659 = _hw_input_global_wrapper_stencil(_conv_s1_x, _658);
   uint16_t _660 = (uint16_t)(53);
   uint16_t _661 = _659 * _660;
   uint16_t _662 = _hw_input_global_wrapper_stencil(_532, _658);
   uint16_t _663 = (uint16_t)(51);
   uint16_t _664 = _662 * _663;
   uint16_t _665 = _hw_input_global_wrapper_stencil(_536, _658);
   uint16_t _666 = _665 * _595;
   uint16_t _667 = _hw_input_global_wrapper_stencil(_540, _658);
   uint16_t _668 = _667 * _617;
   uint16_t _669 = _hw_input_global_wrapper_stencil(_544, _658);
   uint16_t _670 = _669 * _637;
   uint16_t _671 = _hw_input_global_wrapper_stencil(_552, _658);
   uint16_t _672 = _671 * _617;
   uint16_t _673 = _hw_input_global_wrapper_stencil(_548, _658);
   uint16_t _674 = _673 * _656;
   uint16_t _675 = _672 + _674;
   uint16_t _676 = _670 + _675;
   uint16_t _677 = _668 + _676;
   uint16_t _678 = _666 + _677;
   uint16_t _679 = _664 + _678;
   uint16_t _680 = _661 + _679;
   uint16_t _681 = _657 + _680;
   uint16_t _682 = _654 + _681;
   uint16_t _683 = _651 + _682;
   uint16_t _684 = _649 + _683;
   uint16_t _685 = _647 + _684;
   uint16_t _686 = _645 + _685;
   uint16_t _687 = _642 + _686;
   uint16_t _688 = _638 + _687;
   uint16_t _689 = _635 + _688;
   uint16_t _690 = _632 + _689;
   uint16_t _691 = _629 + _690;
   uint16_t _692 = _627 + _691;
   uint16_t _693 = _625 + _692;
   uint16_t _694 = _622 + _693;
   uint16_t _695 = _618 + _694;
   uint16_t _696 = _615 + _695;
   uint16_t _697 = _612 + _696;
   uint16_t _698 = _609 + _697;
   uint16_t _699 = _606 + _698;
   uint16_t _700 = _603 + _699;
   uint16_t _701 = _600 + _700;
   uint16_t _702 = _596 + _701;
   uint16_t _703 = _593 + _702;
   uint16_t _704 = _590 + _703;
   uint16_t _705 = _587 + _704;
   uint16_t _706 = _584 + _705;
   uint16_t _707 = _581 + _706;
   uint16_t _708 = _578 + _707;
   uint16_t _709 = _574 + _708;
   uint16_t _710 = _571 + _709;
   uint16_t _711 = _568 + _710;
   uint16_t _712 = _565 + _711;
   uint16_t _713 = _562 + _712;
   uint16_t _714 = _559 + _713;
   uint16_t _715 = _555 + _714;
   uint16_t _716 = _551 + _715;
   uint16_t _717 = _547 + _716;
   uint16_t _718 = _543 + _717;
   uint16_t _719 = _539 + _718;
   uint16_t _720 = _535 + _719;
   uint16_t _721 = _531 + _720;
   uint16_t _722 = _530 + _721;
   _conv_stencil(_conv_s1_x, _conv_s1_y) = _722;
  } // for conv_s1_x
 } // for conv_s1_y
 // consume conv.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 58; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 58; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _723 = _conv_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _723;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv_7_7

