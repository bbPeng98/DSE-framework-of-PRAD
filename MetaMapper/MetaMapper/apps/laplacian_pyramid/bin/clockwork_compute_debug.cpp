hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_blur_unnormalized_stencil() {
uint16_t _408 = (uint16_t)(0);
// created const: const_p0__408 with name _408
// connected _408 to the output port
}

hcompute_blur_unnormalized_stencil_1() {
uint16_t _433 = (uint16_t)(3);
uint16_t _434 = _hw_input_global_wrapper_stencil_1 * _433;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p3__433 with name _433
// mula: self.in // mulb: _433 o: _434 with obitwidth:16
uint16_t _435 = (uint16_t)(21);
uint16_t _436 = _hw_input_global_wrapper_stencil_2 * _435;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p21__435 with name _435
// mula: self.in // mulb: _435 o: _436 with obitwidth:16
uint16_t _437 = _hw_input_global_wrapper_stencil_3 * _433;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p3__433$1 with name _433
// mula: self.in // mulb: _433 o: _437 with obitwidth:16
uint16_t _438 = _hw_input_global_wrapper_stencil_4 * _435;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// created const: const_p21__435$1 with name _435
// mula: self.in // mulb: _435 o: _438 with obitwidth:16
uint16_t _439 = (uint16_t)(7);
uint16_t _440 = _hw_input_global_wrapper_stencil_5 * _439;
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// created const: const_p7__439 with name _439
// mula: self.in // mulb: _439 o: _440 with obitwidth:16
uint16_t _441 = _hw_input_global_wrapper_stencil_8 * _439;
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// created const: const_p7__439$1 with name _439
// mula: self.in // mulb: _439 o: _441 with obitwidth:16
uint16_t _442 = _hw_input_global_wrapper_stencil_7 + _441;
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// adda: self.in // addb: _441 o: _442 with obitwidth:16
uint16_t _443 = _hw_input_global_wrapper_stencil_6 + _442;
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// adda: self.in // addb: _442 o: _443 with obitwidth:16
uint16_t _444 = _440 + _443;
// adda: _440 // addb: _443 o: _444 with obitwidth:16
uint16_t _445 = _444 * _433;
// created const: const_p3__433$2 with name _433
// mula: _444 // mulb: _433 o: _445 with obitwidth:16
uint16_t _446 = (uint16_t)(158);
uint16_t _447 = _hw_input_global_wrapper_stencil_9 * _446;
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// created const: const_p158__446 with name _446
// mula: self.in // mulb: _446 o: _447 with obitwidth:16
uint16_t _448 = _445 + _447;
// adda: _445 // addb: _447 o: _448 with obitwidth:16
uint16_t _449 = _438 + _448;
// adda: _438 // addb: _448 o: _449 with obitwidth:16
uint16_t _450 = _437 + _449;
// adda: _437 // addb: _449 o: _450 with obitwidth:16
uint16_t _451 = _436 + _450;
// adda: _436 // addb: _450 o: _451 with obitwidth:16
uint16_t _452 = _blur_unnormalized_stencil_1 + _451;
// _blur_unnormalized_stencil_1 added as input _blur_unnormalized_stencil_1
// adda: self.in // addb: _451 o: _452 with obitwidth:16
uint16_t _453 = _434 + _452;
// adda: _434 // addb: _452 o: _453 with obitwidth:16
// connected _453 to the output port
}

hcompute_l0_0_stencil() {
uint16_t _493 = (uint16_t)(8);
uint16_t _494 = _blur_unnormalized_stencil_2 >> _493;
// _blur_unnormalized_stencil_2 added as input _blur_unnormalized_stencil_2
// created const: const_p8__493 with name _493
// lshra: self.in // lshrb: _493 o: _494 with obitwidth:16
// connected _494 to the output port
}

hcompute_h0_0_stencil() {
uint16_t _501 = _hw_input_global_wrapper_stencil_10 - _l0_0_stencil_1;
// _hw_input_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_stencil_10
// _l0_0_stencil_1 added as input _l0_0_stencil_1
// suba: self.in // subb: self.in o: _501 with obitwidth:16
// connected _501 to the output port
}

hcompute_f1_0_stencil() {
// _l0_0_stencil_2 added as input _l0_0_stencil_2
// connected _l0_0_stencil_2 to the output port
}

hcompute_f1_blur_unnormalized_stencil() {
uint16_t _517 = (uint16_t)(0);
// created const: const_p0__517 with name _517
// connected _517 to the output port
}

hcompute_f1_blur_unnormalized_stencil_1() {
uint16_t _542 = (uint16_t)(3);
uint16_t _543 = _f1_0_stencil_1 * _542;
// _f1_0_stencil_1 added as input _f1_0_stencil_1
// created const: const_p3__542 with name _542
// mula: self.in // mulb: _542 o: _543 with obitwidth:16
uint16_t _544 = (uint16_t)(21);
uint16_t _545 = _f1_0_stencil_2 * _544;
// _f1_0_stencil_2 added as input _f1_0_stencil_2
// created const: const_p21__544 with name _544
// mula: self.in // mulb: _544 o: _545 with obitwidth:16
uint16_t _546 = _f1_0_stencil_3 * _542;
// _f1_0_stencil_3 added as input _f1_0_stencil_3
// created const: const_p3__542$1 with name _542
// mula: self.in // mulb: _542 o: _546 with obitwidth:16
uint16_t _547 = _f1_0_stencil_4 * _544;
// _f1_0_stencil_4 added as input _f1_0_stencil_4
// created const: const_p21__544$1 with name _544
// mula: self.in // mulb: _544 o: _547 with obitwidth:16
uint16_t _548 = (uint16_t)(7);
uint16_t _549 = _f1_0_stencil_5 * _548;
// _f1_0_stencil_5 added as input _f1_0_stencil_5
// created const: const_p7__548 with name _548
// mula: self.in // mulb: _548 o: _549 with obitwidth:16
uint16_t _550 = _f1_0_stencil_8 * _548;
// _f1_0_stencil_8 added as input _f1_0_stencil_8
// created const: const_p7__548$1 with name _548
// mula: self.in // mulb: _548 o: _550 with obitwidth:16
uint16_t _551 = _f1_0_stencil_7 + _550;
// _f1_0_stencil_7 added as input _f1_0_stencil_7
// adda: self.in // addb: _550 o: _551 with obitwidth:16
uint16_t _552 = _f1_0_stencil_6 + _551;
// _f1_0_stencil_6 added as input _f1_0_stencil_6
// adda: self.in // addb: _551 o: _552 with obitwidth:16
uint16_t _553 = _549 + _552;
// adda: _549 // addb: _552 o: _553 with obitwidth:16
uint16_t _554 = _553 * _542;
// created const: const_p3__542$2 with name _542
// mula: _553 // mulb: _542 o: _554 with obitwidth:16
uint16_t _555 = (uint16_t)(158);
uint16_t _556 = _f1_0_stencil_9 * _555;
// _f1_0_stencil_9 added as input _f1_0_stencil_9
// created const: const_p158__555 with name _555
// mula: self.in // mulb: _555 o: _556 with obitwidth:16
uint16_t _557 = _554 + _556;
// adda: _554 // addb: _556 o: _557 with obitwidth:16
uint16_t _558 = _547 + _557;
// adda: _547 // addb: _557 o: _558 with obitwidth:16
uint16_t _559 = _546 + _558;
// adda: _546 // addb: _558 o: _559 with obitwidth:16
uint16_t _560 = _545 + _559;
// adda: _545 // addb: _559 o: _560 with obitwidth:16
uint16_t _561 = _f1_blur_unnormalized_stencil_1 + _560;
// _f1_blur_unnormalized_stencil_1 added as input _f1_blur_unnormalized_stencil_1
// adda: self.in // addb: _560 o: _561 with obitwidth:16
uint16_t _562 = _543 + _561;
// adda: _543 // addb: _561 o: _562 with obitwidth:16
// connected _562 to the output port
}

hcompute_l1_0_stencil() {
uint16_t _602 = (uint16_t)(8);
uint16_t _603 = _f1_blur_unnormalized_stencil_2 >> _602;
// _f1_blur_unnormalized_stencil_2 added as input _f1_blur_unnormalized_stencil_2
// created const: const_p8__602 with name _602
// lshra: self.in // lshrb: _602 o: _603 with obitwidth:16
// connected _603 to the output port
}

hcompute_h1_0_stencil() {
uint16_t _610 = _f1_0_stencil_10 - _l1_0_stencil_1;
// _f1_0_stencil_10 added as input _f1_0_stencil_10
// _l1_0_stencil_1 added as input _l1_0_stencil_1
// suba: self.in // subb: self.in o: _610 with obitwidth:16
// connected _610 to the output port
}

hcompute_f2_0_stencil() {
// _l1_0_stencil_2 added as input _l1_0_stencil_2
// connected _l1_0_stencil_2 to the output port
}

hcompute_f2_temp_stencil() {
// _f2_0_stencil_1 added as input _f2_0_stencil_1
// connected _f2_0_stencil_1 to the output port
}

hcompute_f2_temp_blur_unnormalized_stencil() {
uint16_t _635 = (uint16_t)(0);
// created const: const_p0__635 with name _635
// connected _635 to the output port
}

hcompute_f2_temp_blur_unnormalized_stencil_1() {
uint16_t _660 = (uint16_t)(3);
uint16_t _661 = _f2_temp_stencil_1 * _660;
// _f2_temp_stencil_1 added as input _f2_temp_stencil_1
// created const: const_p3__660 with name _660
// mula: self.in // mulb: _660 o: _661 with obitwidth:16
uint16_t _662 = (uint16_t)(21);
uint16_t _663 = _f2_temp_stencil_2 * _662;
// _f2_temp_stencil_2 added as input _f2_temp_stencil_2
// created const: const_p21__662 with name _662
// mula: self.in // mulb: _662 o: _663 with obitwidth:16
uint16_t _664 = _f2_temp_stencil_3 * _660;
// _f2_temp_stencil_3 added as input _f2_temp_stencil_3
// created const: const_p3__660$1 with name _660
// mula: self.in // mulb: _660 o: _664 with obitwidth:16
uint16_t _665 = _f2_temp_stencil_4 * _662;
// _f2_temp_stencil_4 added as input _f2_temp_stencil_4
// created const: const_p21__662$1 with name _662
// mula: self.in // mulb: _662 o: _665 with obitwidth:16
uint16_t _666 = (uint16_t)(7);
uint16_t _667 = _f2_temp_stencil_5 * _666;
// _f2_temp_stencil_5 added as input _f2_temp_stencil_5
// created const: const_p7__666 with name _666
// mula: self.in // mulb: _666 o: _667 with obitwidth:16
uint16_t _668 = _f2_temp_stencil_8 * _666;
// _f2_temp_stencil_8 added as input _f2_temp_stencil_8
// created const: const_p7__666$1 with name _666
// mula: self.in // mulb: _666 o: _668 with obitwidth:16
uint16_t _669 = _f2_temp_stencil_7 + _668;
// _f2_temp_stencil_7 added as input _f2_temp_stencil_7
// adda: self.in // addb: _668 o: _669 with obitwidth:16
uint16_t _670 = _f2_temp_stencil_6 + _669;
// _f2_temp_stencil_6 added as input _f2_temp_stencil_6
// adda: self.in // addb: _669 o: _670 with obitwidth:16
uint16_t _671 = _667 + _670;
// adda: _667 // addb: _670 o: _671 with obitwidth:16
uint16_t _672 = _671 * _660;
// created const: const_p3__660$2 with name _660
// mula: _671 // mulb: _660 o: _672 with obitwidth:16
uint16_t _673 = (uint16_t)(158);
uint16_t _674 = _f2_temp_stencil_9 * _673;
// _f2_temp_stencil_9 added as input _f2_temp_stencil_9
// created const: const_p158__673 with name _673
// mula: self.in // mulb: _673 o: _674 with obitwidth:16
uint16_t _675 = _672 + _674;
// adda: _672 // addb: _674 o: _675 with obitwidth:16
uint16_t _676 = _665 + _675;
// adda: _665 // addb: _675 o: _676 with obitwidth:16
uint16_t _677 = _664 + _676;
// adda: _664 // addb: _676 o: _677 with obitwidth:16
uint16_t _678 = _663 + _677;
// adda: _663 // addb: _677 o: _678 with obitwidth:16
uint16_t _679 = _f2_temp_blur_unnormalized_stencil_1 + _678;
// _f2_temp_blur_unnormalized_stencil_1 added as input _f2_temp_blur_unnormalized_stencil_1
// adda: self.in // addb: _678 o: _679 with obitwidth:16
uint16_t _680 = _661 + _679;
// adda: _661 // addb: _679 o: _680 with obitwidth:16
// connected _680 to the output port
}

hcompute_l1_up_stencil() {
uint16_t _720 = (uint16_t)(8);
uint16_t _721 = _f2_temp_blur_unnormalized_stencil_2 >> _720;
// _f2_temp_blur_unnormalized_stencil_2 added as input _f2_temp_blur_unnormalized_stencil_2
// created const: const_p8__720 with name _720
// lshra: self.in // lshrb: _720 o: _721 with obitwidth:16
// connected _721 to the output port
}

hcompute_f1_up_stencil_1() {
uint16_t _728 = _l1_up_stencil_1 + _h1_0_stencil_1;
// _l1_up_stencil_1 added as input _l1_up_stencil_1
// _h1_0_stencil_1 added as input _h1_0_stencil_1
// adda: self.in // addb: self.in o: _728 with obitwidth:16
// connected _728 to the output port
}

hcompute_f1_temp_stencil() {
// _f1_up_stencil_1 added as input _f1_up_stencil_1
// connected _f1_up_stencil_1 to the output port
}

hcompute_f1_temp_blur_unnormalized_stencil() {
uint16_t _742 = (uint16_t)(0);
// created const: const_p0__742 with name _742
// connected _742 to the output port
}

hcompute_f1_temp_blur_unnormalized_stencil_1() {
uint16_t _767 = (uint16_t)(3);
uint16_t _768 = _f1_temp_stencil_1 * _767;
// _f1_temp_stencil_1 added as input _f1_temp_stencil_1
// created const: const_p3__767 with name _767
// mula: self.in // mulb: _767 o: _768 with obitwidth:16
uint16_t _769 = (uint16_t)(21);
uint16_t _770 = _f1_temp_stencil_2 * _769;
// _f1_temp_stencil_2 added as input _f1_temp_stencil_2
// created const: const_p21__769 with name _769
// mula: self.in // mulb: _769 o: _770 with obitwidth:16
uint16_t _771 = _f1_temp_stencil_3 * _767;
// _f1_temp_stencil_3 added as input _f1_temp_stencil_3
// created const: const_p3__767$1 with name _767
// mula: self.in // mulb: _767 o: _771 with obitwidth:16
uint16_t _772 = _f1_temp_stencil_4 * _769;
// _f1_temp_stencil_4 added as input _f1_temp_stencil_4
// created const: const_p21__769$1 with name _769
// mula: self.in // mulb: _769 o: _772 with obitwidth:16
uint16_t _773 = (uint16_t)(7);
uint16_t _774 = _f1_temp_stencil_5 * _773;
// _f1_temp_stencil_5 added as input _f1_temp_stencil_5
// created const: const_p7__773 with name _773
// mula: self.in // mulb: _773 o: _774 with obitwidth:16
uint16_t _775 = _f1_temp_stencil_8 * _773;
// _f1_temp_stencil_8 added as input _f1_temp_stencil_8
// created const: const_p7__773$1 with name _773
// mula: self.in // mulb: _773 o: _775 with obitwidth:16
uint16_t _776 = _f1_temp_stencil_7 + _775;
// _f1_temp_stencil_7 added as input _f1_temp_stencil_7
// adda: self.in // addb: _775 o: _776 with obitwidth:16
uint16_t _777 = _f1_temp_stencil_6 + _776;
// _f1_temp_stencil_6 added as input _f1_temp_stencil_6
// adda: self.in // addb: _776 o: _777 with obitwidth:16
uint16_t _778 = _774 + _777;
// adda: _774 // addb: _777 o: _778 with obitwidth:16
uint16_t _779 = _778 * _767;
// created const: const_p3__767$2 with name _767
// mula: _778 // mulb: _767 o: _779 with obitwidth:16
uint16_t _780 = (uint16_t)(158);
uint16_t _781 = _f1_temp_stencil_9 * _780;
// _f1_temp_stencil_9 added as input _f1_temp_stencil_9
// created const: const_p158__780 with name _780
// mula: self.in // mulb: _780 o: _781 with obitwidth:16
uint16_t _782 = _779 + _781;
// adda: _779 // addb: _781 o: _782 with obitwidth:16
uint16_t _783 = _772 + _782;
// adda: _772 // addb: _782 o: _783 with obitwidth:16
uint16_t _784 = _771 + _783;
// adda: _771 // addb: _783 o: _784 with obitwidth:16
uint16_t _785 = _770 + _784;
// adda: _770 // addb: _784 o: _785 with obitwidth:16
uint16_t _786 = _f1_temp_blur_unnormalized_stencil_1 + _785;
// _f1_temp_blur_unnormalized_stencil_1 added as input _f1_temp_blur_unnormalized_stencil_1
// adda: self.in // addb: _785 o: _786 with obitwidth:16
uint16_t _787 = _768 + _786;
// adda: _768 // addb: _786 o: _787 with obitwidth:16
// connected _787 to the output port
}

hcompute_l0_up_stencil() {
uint16_t _827 = (uint16_t)(8);
uint16_t _828 = _f1_temp_blur_unnormalized_stencil_2 >> _827;
// _f1_temp_blur_unnormalized_stencil_2 added as input _f1_temp_blur_unnormalized_stencil_2
// created const: const_p8__827 with name _827
// lshra: self.in // lshrb: _827 o: _828 with obitwidth:16
// connected _828 to the output port
}

hcompute_f0_up_stencil() {
uint16_t _833 = _l0_up_stencil_1 + _h0_0_stencil_1;
// _l0_up_stencil_1 added as input _l0_up_stencil_1
// _h0_0_stencil_1 added as input _h0_0_stencil_1
// adda: self.in // addb: self.in o: _833 with obitwidth:16
// connected _833 to the output port
}

hcompute_hw_output_stencil() {
// _f0_up_stencil_1 added as input _f0_up_stencil_1
// connected _f0_up_stencil_1 to the output port
}

