hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_denoised_1_stencil() {
uint16_t _327 = _hw_input_global_wrapper_stencil_4 <max> _hw_input_global_wrapper_stencil_5;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// umaxa: self.in // umaxb: self.in o: _327 with obitwidth:16
uint16_t _328 = _hw_input_global_wrapper_stencil_3 <max> _327;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// umaxa: self.in // umaxb: _327 o: _328 with obitwidth:16
uint16_t _329 = _hw_input_global_wrapper_stencil_2 <max> _328;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// umaxa: self.in // umaxb: _328 o: _329 with obitwidth:16
uint16_t _330 = _hw_input_global_wrapper_stencil_1 <min> _329;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// umina: self.in // uminb: _329 o: _330 with obitwidth:16
// connected _330 to the output port
}

hcompute_b_b_stencil() {
// _denoised_1_stencil_1 added as input _denoised_1_stencil_1
// connected _denoised_1_stencil_1 to the output port
}

hcompute_g_gb_stencil() {
// _denoised_1_stencil_2 added as input _denoised_1_stencil_2
// connected _denoised_1_stencil_2 to the output port
}

hcompute_g_gr_stencil() {
// _denoised_1_stencil_3 added as input _denoised_1_stencil_3
// connected _denoised_1_stencil_3 to the output port
}

hcompute_r_r_stencil() {
// _denoised_1_stencil_4 added as input _denoised_1_stencil_4
// connected _denoised_1_stencil_4 to the output port
}

hcompute_demosaicked_1_stencil() {
uint32_t _496 = (uint32_t)(1);
int32_t _497 = _demosaicked_1_s0_y & _496;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__496 with name _496
// anda: self.in // andb: _496 o: _497 with obitwidth:32
bool _498 = _497 == 0;
// created const: const_p0_0 with name 0
// eqa: _497 // eqb: 0 o: _498 with obitwidth:1
int32_t _499 = _demosaicked_1_s0_x & _496;
// _demosaicked_1_s0_x added as input _demosaicked_1_s0_x
// created const: const_p1__496$1 with name _496
// anda: self.in // andb: _496 o: _499 with obitwidth:32
bool _500 = _499 == 0;
// created const: const_p0_0$1 with name 0
// eqa: _499 // eqb: 0 o: _500 with obitwidth:1
uint16_t _501 = _r_r_stencil_1 + _r_r_stencil_2;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_2 added as input _r_r_stencil_2
// adda: self.in // addb: self.in o: _501 with obitwidth:16
uint16_t _502 = (uint16_t)(1);
uint16_t _503 = _501 >> _502;
// created const: const_p1__502 with name _502
// lshra: _501 // lshrb: _502 o: _503 with obitwidth:16
uint16_t _504 = _g_gr_stencil_1 + _503;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// adda: self.in // addb: _503 o: _504 with obitwidth:16
[absd] uint16_t _505 = _g_gr_stencil_2 |-| _g_gr_stencil_1;
// _g_gr_stencil_2 added as input _g_gr_stencil_2
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// absda: self.in // absdb: self.in o: _505 with obitwidth:16
[absd] uint16_t _506 = _g_gb_stencil_1 |-| _g_gb_stencil_2;
// _g_gb_stencil_1 added as input _g_gb_stencil_1
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// absda: self.in // absdb: self.in o: _506 with obitwidth:16
bool _507 = _505 < _506;
// ulta: _505 // ultb: _506 o: _507 with obitwidth:1
uint16_t _508 = _g_gr_stencil_2 + _g_gr_stencil_1;
// _g_gr_stencil_2 added as input _g_gr_stencil_2
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// adda: self.in // addb: self.in o: _508 with obitwidth:16
uint16_t _509 = _508 >> _502;
// created const: const_p1__502$1 with name _502
// lshra: _508 // lshrb: _502 o: _509 with obitwidth:16
uint16_t _510 = _g_gb_stencil_1 + _g_gb_stencil_2;
// _g_gb_stencil_1 added as input _g_gb_stencil_1
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// adda: self.in // addb: self.in o: _510 with obitwidth:16
uint16_t _511 = _510 >> _502;
// created const: const_p1__502$2 with name _502
// lshra: _510 // lshrb: _502 o: _511 with obitwidth:16
uint16_t _512 = _507 ? _509 : _511;
// muxa: _507 // muxb: _509 // muxc: _511 o: _512
[absd] uint16_t _513 = _g_gr_stencil_1 |-| _g_gr_stencil_3;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// _g_gr_stencil_3 added as input _g_gr_stencil_3
// absda: self.in // absdb: self.in o: _513 with obitwidth:16
[absd] uint16_t _514 = _g_gb_stencil_3 |-| _g_gb_stencil_4;
// _g_gb_stencil_3 added as input _g_gb_stencil_3
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// absda: self.in // absdb: self.in o: _514 with obitwidth:16
bool _515 = _513 < _514;
// ulta: _513 // ultb: _514 o: _515 with obitwidth:1
uint16_t _516 = _g_gr_stencil_1 + _g_gr_stencil_3;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// _g_gr_stencil_3 added as input _g_gr_stencil_3
// adda: self.in // addb: self.in o: _516 with obitwidth:16
uint16_t _517 = _516 >> _502;
// created const: const_p1__502$3 with name _502
// lshra: _516 // lshrb: _502 o: _517 with obitwidth:16
uint16_t _518 = _g_gb_stencil_3 + _g_gb_stencil_4;
// _g_gb_stencil_3 added as input _g_gb_stencil_3
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// adda: self.in // addb: self.in o: _518 with obitwidth:16
uint16_t _519 = _518 >> _502;
// created const: const_p1__502$4 with name _502
// lshra: _518 // lshrb: _502 o: _519 with obitwidth:16
uint16_t _520 = _515 ? _517 : _519;
// muxa: _515 // muxb: _517 // muxc: _519 o: _520
uint16_t _521 = _512 + _520;
// adda: _512 // addb: _520 o: _521 with obitwidth:16
uint16_t _522 = _521 >> _502;
// created const: const_p1__502$5 with name _502
// lshra: _521 // lshrb: _502 o: _522 with obitwidth:16
uint16_t _523 = _504 - _522;
// suba: _504 // subb: _522 o: _523 with obitwidth:16
uint16_t _524 = _500 ? _523 : _r_r_stencil_1;
// _r_r_stencil_1 added as input _r_r_stencil_1
// muxa: _500 // muxb: _523 // muxc: self.in o: _524
[absd] uint16_t _525 = _r_r_stencil_1 |-| _r_r_stencil_3;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_3 added as input _r_r_stencil_3
// absda: self.in // absdb: self.in o: _525 with obitwidth:16
[absd] uint16_t _526 = _r_r_stencil_2 |-| _r_r_stencil_4;
// _r_r_stencil_2 added as input _r_r_stencil_2
// _r_r_stencil_4 added as input _r_r_stencil_4
// absda: self.in // absdb: self.in o: _526 with obitwidth:16
bool _527 = _525 < _526;
// ulta: _525 // ultb: _526 o: _527 with obitwidth:1
uint16_t _528 = _r_r_stencil_1 + _r_r_stencil_3;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_3 added as input _r_r_stencil_3
// adda: self.in // addb: self.in o: _528 with obitwidth:16
uint16_t _529 = _528 >> _502;
// created const: const_p1__502$6 with name _502
// lshra: _528 // lshrb: _502 o: _529 with obitwidth:16
[absd] uint16_t _530 = _g_gb_stencil_4 |-| _g_gb_stencil_2;
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// absda: self.in // absdb: self.in o: _530 with obitwidth:16
[absd] uint16_t _531 = _g_gr_stencil_4 |-| _g_gr_stencil_1;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// absda: self.in // absdb: self.in o: _531 with obitwidth:16
bool _532 = _530 < _531;
// ulta: _530 // ultb: _531 o: _532 with obitwidth:1
uint16_t _533 = _g_gb_stencil_2 + _g_gb_stencil_4;
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// adda: self.in // addb: self.in o: _533 with obitwidth:16
uint16_t _534 = _533 >> _502;
// created const: const_p1__502$7 with name _502
// lshra: _533 // lshrb: _502 o: _534 with obitwidth:16
uint16_t _535 = _g_gr_stencil_1 + _g_gr_stencil_4;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// adda: self.in // addb: self.in o: _535 with obitwidth:16
uint16_t _536 = _535 >> _502;
// created const: const_p1__502$8 with name _502
// lshra: _535 // lshrb: _502 o: _536 with obitwidth:16
uint16_t _537 = _532 ? _534 : _536;
// muxa: _532 // muxb: _534 // muxc: _536 o: _537
uint16_t _538 = _529 + _537;
// adda: _529 // addb: _537 o: _538 with obitwidth:16
[absd] uint16_t _539 = _g_gr_stencil_4 |-| _g_gr_stencil_5;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_5 added as input _g_gr_stencil_5
// absda: self.in // absdb: self.in o: _539 with obitwidth:16
[absd] uint16_t _540 = _g_gb_stencil_4 |-| _g_gb_stencil_5;
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// _g_gb_stencil_5 added as input _g_gb_stencil_5
// absda: self.in // absdb: self.in o: _540 with obitwidth:16
bool _541 = _539 < _540;
// ulta: _539 // ultb: _540 o: _541 with obitwidth:1
uint16_t _542 = _g_gr_stencil_4 + _g_gr_stencil_5;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_5 added as input _g_gr_stencil_5
// adda: self.in // addb: self.in o: _542 with obitwidth:16
uint16_t _543 = _542 >> _502;
// created const: const_p1__502$9 with name _502
// lshra: _542 // lshrb: _502 o: _543 with obitwidth:16
uint16_t _544 = _g_gb_stencil_4 + _g_gb_stencil_5;
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// _g_gb_stencil_5 added as input _g_gb_stencil_5
// adda: self.in // addb: self.in o: _544 with obitwidth:16
uint16_t _545 = _544 >> _502;
// created const: const_p1__502$10 with name _502
// lshra: _544 // lshrb: _502 o: _545 with obitwidth:16
uint16_t _546 = _541 ? _543 : _545;
// muxa: _541 // muxb: _543 // muxc: _545 o: _546
[absd] [absd] uint16_t _547 = _546 + _512;
// adda: _546 // addb: _512 o: _547 with obitwidth:16
uint16_t _548 = _547 >> _502;
// created const: const_p1__502$11 with name _502
// lshra: _547 // lshrb: _502 o: _548 with obitwidth:16
uint16_t _549 = _538 - _548;
// suba: _538 // subb: _548 o: _549 with obitwidth:16
uint16_t _550 = _r_r_stencil_2 + _r_r_stencil_4;
// _r_r_stencil_2 added as input _r_r_stencil_2
// _r_r_stencil_4 added as input _r_r_stencil_4
// adda: self.in // addb: self.in o: _550 with obitwidth:16
uint16_t _551 = _550 >> _502;
// created const: const_p1__502$12 with name _502
// lshra: _550 // lshrb: _502 o: _551 with obitwidth:16
[absd] [absd] uint16_t _552 = _551 + _537;
// adda: _551 // addb: _537 o: _552 with obitwidth:16
[absd] [absd] [absd] uint16_t _553 = _g_gr_stencil_6 |-| _g_gr_stencil_4;
// _g_gr_stencil_6 added as input _g_gr_stencil_6
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// absda: self.in // absdb: self.in o: _553 with obitwidth:16
[absd] uint16_t _554 = _g_gb_stencil_2 |-| _g_gb_stencil_6;
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// _g_gb_stencil_6 added as input _g_gb_stencil_6
// absda: self.in // absdb: self.in o: _554 with obitwidth:16
bool _555 = _553 < _554;
// ulta: _553 // ultb: _554 o: _555 with obitwidth:1
uint16_t _556 = _g_gr_stencil_4 + _g_gr_stencil_6;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_6 added as input _g_gr_stencil_6
// adda: self.in // addb: self.in o: _556 with obitwidth:16
uint16_t _557 = _556 >> _502;
// created const: const_p1__502$13 with name _502
// lshra: _556 // lshrb: _502 o: _557 with obitwidth:16
uint16_t _558 = _g_gb_stencil_2 + _g_gb_stencil_6;
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// _g_gb_stencil_6 added as input _g_gb_stencil_6
// adda: self.in // addb: self.in o: _558 with obitwidth:16
uint16_t _559 = _558 >> _502;
// created const: const_p1__502$14 with name _502
// lshra: _558 // lshrb: _502 o: _559 with obitwidth:16
uint16_t _560 = _555 ? _557 : _559;
// muxa: _555 // muxb: _557 // muxc: _559 o: _560
uint16_t _561 = _520 + _560;
// adda: _520 // addb: _560 o: _561 with obitwidth:16
uint16_t _562 = _561 >> _502;
// created const: const_p1__502$15 with name _502
// lshra: _561 // lshrb: _502 o: _562 with obitwidth:16
uint16_t _563 = _552 - _562;
// suba: _552 // subb: _562 o: _563 with obitwidth:16
uint16_t _564 = _527 ? _549 : _563;
// muxa: _527 // muxb: _549 // muxc: _563 o: _564
uint16_t _565 = _r_r_stencil_1 + _r_r_stencil_4;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_4 added as input _r_r_stencil_4
// adda: self.in // addb: self.in o: _565 with obitwidth:16
uint16_t _566 = _565 >> _502;
// created const: const_p1__502$16 with name _502
// lshra: _565 // lshrb: _502 o: _566 with obitwidth:16
uint16_t _567 = _g_gb_stencil_2 + _566;
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// adda: self.in // addb: _566 o: _567 with obitwidth:16
[absd] [absd] [absd] [absd] uint16_t _568 = _512 + _560;
// adda: _512 // addb: _560 o: _568 with obitwidth:16
uint16_t _569 = _568 >> _502;
// created const: const_p1__502$17 with name _502
// lshra: _568 // lshrb: _502 o: _569 with obitwidth:16
uint16_t _570 = _567 - _569;
// suba: _567 // subb: _569 o: _570 with obitwidth:16
uint16_t _571 = _500 ? _564 : _570;
// muxa: _500 // muxb: _564 // muxc: _570 o: _571
uint16_t _572 = _498 ? _524 : _571;
// muxa: _498 // muxb: _524 // muxc: _571 o: _572
[absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] // connected _572 to the output port
}

hcompute_demosaicked_1_stencil_1() {
uint32_t _759 = (uint32_t)(1);
int32_t _760 = _demosaicked_1_s0_y_1 & _759;
// _demosaicked_1_s0_y_1 added as input _demosaicked_1_s0_y_1
// created const: const_p1__759 with name _759
// anda: self.in // andb: _759 o: _760 with obitwidth:32
bool _761 = _760 == 0;
// created const: const_p0_0$2 with name 0
// eqa: _760 // eqb: 0 o: _761 with obitwidth:1
int32_t _762 = _demosaicked_1_s0_x_1 & _759;
// _demosaicked_1_s0_x_1 added as input _demosaicked_1_s0_x_1
// created const: const_p1__759$1 with name _759
// anda: self.in // andb: _759 o: _762 with obitwidth:32
bool _763 = _762 == 0;
// created const: const_p0_0$3 with name 0
// eqa: _762 // eqb: 0 o: _763 with obitwidth:1
[absd] uint16_t _764 = _g_gr_stencil_8 |-| _g_gr_stencil_7;
// _g_gr_stencil_8 added as input _g_gr_stencil_8
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// absda: self.in // absdb: self.in o: _764 with obitwidth:16
[absd] uint16_t _765 = _g_gb_stencil_7 |-| _g_gb_stencil_8;
// _g_gb_stencil_7 added as input _g_gb_stencil_7
// _g_gb_stencil_8 added as input _g_gb_stencil_8
// absda: self.in // absdb: self.in o: _765 with obitwidth:16
bool _766 = _764 < _765;
// ulta: _764 // ultb: _765 o: _766 with obitwidth:1
uint16_t _767 = _g_gr_stencil_8 + _g_gr_stencil_7;
// _g_gr_stencil_8 added as input _g_gr_stencil_8
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// adda: self.in // addb: self.in o: _767 with obitwidth:16
uint16_t _768 = (uint16_t)(1);
uint16_t _769 = _767 >> _768;
// created const: const_p1__768 with name _768
// lshra: _767 // lshrb: _768 o: _769 with obitwidth:16
uint16_t _770 = _g_gb_stencil_7 + _g_gb_stencil_8;
// _g_gb_stencil_7 added as input _g_gb_stencil_7
// _g_gb_stencil_8 added as input _g_gb_stencil_8
// adda: self.in // addb: self.in o: _770 with obitwidth:16
uint16_t _771 = _770 >> _768;
// created const: const_p1__768$1 with name _768
// lshra: _770 // lshrb: _768 o: _771 with obitwidth:16
uint16_t _772 = _766 ? _769 : _771;
// muxa: _766 // muxb: _769 // muxc: _771 o: _772
uint16_t _773 = _763 ? _g_gr_stencil_7 : _772;
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// muxa: _763 // muxb: self.in // muxc: _772 o: _773
[absd] uint16_t _774 = _g_gb_stencil_9 |-| _g_gb_stencil_8;
// _g_gb_stencil_9 added as input _g_gb_stencil_9
// _g_gb_stencil_8 added as input _g_gb_stencil_8
// absda: self.in // absdb: self.in o: _774 with obitwidth:16
[absd] uint16_t _775 = _g_gr_stencil_9 |-| _g_gr_stencil_7;
// _g_gr_stencil_9 added as input _g_gr_stencil_9
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// absda: self.in // absdb: self.in o: _775 with obitwidth:16
bool _776 = _774 < _775;
// ulta: _774 // ultb: _775 o: _776 with obitwidth:1
uint16_t _777 = _g_gb_stencil_8 + _g_gb_stencil_9;
// _g_gb_stencil_8 added as input _g_gb_stencil_8
// _g_gb_stencil_9 added as input _g_gb_stencil_9
// adda: self.in // addb: self.in o: _777 with obitwidth:16
uint16_t _778 = _777 >> _768;
// created const: const_p1__768$2 with name _768
// lshra: _777 // lshrb: _768 o: _778 with obitwidth:16
uint16_t _779 = _g_gr_stencil_7 + _g_gr_stencil_9;
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// _g_gr_stencil_9 added as input _g_gr_stencil_9
// adda: self.in // addb: self.in o: _779 with obitwidth:16
uint16_t _780 = _779 >> _768;
// created const: const_p1__768$3 with name _768
// lshra: _779 // lshrb: _768 o: _780 with obitwidth:16
uint16_t _781 = _776 ? _778 : _780;
// muxa: _776 // muxb: _778 // muxc: _780 o: _781
uint16_t _782 = _763 ? _781 : _g_gb_stencil_8;
// _g_gb_stencil_8 added as input _g_gb_stencil_8
// muxa: _763 // muxb: _781 // muxc: self.in o: _782
uint16_t _783 = _761 ? _773 : _782;
// muxa: _761 // muxb: _773 // muxc: _782 o: _783
[absd] [absd] [absd] [absd] // connected _783 to the output port
}

hcompute_demosaicked_1_stencil_2() {
uint32_t _960 = (uint32_t)(1);
int32_t _961 = _demosaicked_1_s0_y_2 & _960;
// _demosaicked_1_s0_y_2 added as input _demosaicked_1_s0_y_2
// created const: const_p1__960 with name _960
// anda: self.in // andb: _960 o: _961 with obitwidth:32
bool _962 = _961 == 0;
// created const: const_p0_0$4 with name 0
// eqa: _961 // eqb: 0 o: _962 with obitwidth:1
int32_t _963 = _demosaicked_1_s0_x_2 & _960;
// _demosaicked_1_s0_x_2 added as input _demosaicked_1_s0_x_2
// created const: const_p1__960$1 with name _960
// anda: self.in // andb: _960 o: _963 with obitwidth:32
bool _964 = _963 == 0;
// created const: const_p0_0$5 with name 0
// eqa: _963 // eqb: 0 o: _964 with obitwidth:1
uint16_t _965 = _b_b_stencil_1 + _b_b_stencil_2;
// _b_b_stencil_1 added as input _b_b_stencil_1
// _b_b_stencil_2 added as input _b_b_stencil_2
// adda: self.in // addb: self.in o: _965 with obitwidth:16
uint16_t _966 = (uint16_t)(1);
uint16_t _967 = _965 >> _966;
// created const: const_p1__966 with name _966
// lshra: _965 // lshrb: _966 o: _967 with obitwidth:16
uint16_t _968 = _g_gr_stencil_10 + _967;
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// adda: self.in // addb: _967 o: _968 with obitwidth:16
[absd] uint16_t _969 = _g_gb_stencil_10 |-| _g_gb_stencil_11;
// _g_gb_stencil_10 added as input _g_gb_stencil_10
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// absda: self.in // absdb: self.in o: _969 with obitwidth:16
[absd] uint16_t _970 = _g_gr_stencil_11 |-| _g_gr_stencil_10;
// _g_gr_stencil_11 added as input _g_gr_stencil_11
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// absda: self.in // absdb: self.in o: _970 with obitwidth:16
bool _971 = _969 < _970;
// ulta: _969 // ultb: _970 o: _971 with obitwidth:1
uint16_t _972 = _g_gb_stencil_11 + _g_gb_stencil_10;
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// _g_gb_stencil_10 added as input _g_gb_stencil_10
// adda: self.in // addb: self.in o: _972 with obitwidth:16
uint16_t _973 = _972 >> _966;
// created const: const_p1__966$1 with name _966
// lshra: _972 // lshrb: _966 o: _973 with obitwidth:16
uint16_t _974 = _g_gr_stencil_10 + _g_gr_stencil_11;
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// _g_gr_stencil_11 added as input _g_gr_stencil_11
// adda: self.in // addb: self.in o: _974 with obitwidth:16
uint16_t _975 = _974 >> _966;
// created const: const_p1__966$2 with name _966
// lshra: _974 // lshrb: _966 o: _975 with obitwidth:16
uint16_t _976 = _971 ? _973 : _975;
// muxa: _971 // muxb: _973 // muxc: _975 o: _976
[absd] uint16_t _977 = _g_gb_stencil_12 |-| _g_gb_stencil_13;
// _g_gb_stencil_12 added as input _g_gb_stencil_12
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// absda: self.in // absdb: self.in o: _977 with obitwidth:16
[absd] uint16_t _978 = _g_gr_stencil_10 |-| _g_gr_stencil_12;
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// _g_gr_stencil_12 added as input _g_gr_stencil_12
// absda: self.in // absdb: self.in o: _978 with obitwidth:16
bool _979 = _977 < _978;
// ulta: _977 // ultb: _978 o: _979 with obitwidth:1
uint16_t _980 = _g_gb_stencil_13 + _g_gb_stencil_12;
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// _g_gb_stencil_12 added as input _g_gb_stencil_12
// adda: self.in // addb: self.in o: _980 with obitwidth:16
uint16_t _981 = _980 >> _966;
// created const: const_p1__966$3 with name _966
// lshra: _980 // lshrb: _966 o: _981 with obitwidth:16
uint16_t _982 = _g_gr_stencil_10 + _g_gr_stencil_12;
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// _g_gr_stencil_12 added as input _g_gr_stencil_12
// adda: self.in // addb: self.in o: _982 with obitwidth:16
uint16_t _983 = _982 >> _966;
// created const: const_p1__966$4 with name _966
// lshra: _982 // lshrb: _966 o: _983 with obitwidth:16
uint16_t _984 = _979 ? _981 : _983;
// muxa: _979 // muxb: _981 // muxc: _983 o: _984
uint16_t _985 = _976 + _984;
// adda: _976 // addb: _984 o: _985 with obitwidth:16
uint16_t _986 = _985 >> _966;
// created const: const_p1__966$5 with name _966
// lshra: _985 // lshrb: _966 o: _986 with obitwidth:16
uint16_t _987 = _968 - _986;
// suba: _968 // subb: _986 o: _987 with obitwidth:16
[absd] uint16_t _988 = _b_b_stencil_1 |-| _b_b_stencil_3;
// _b_b_stencil_1 added as input _b_b_stencil_1
// _b_b_stencil_3 added as input _b_b_stencil_3
// absda: self.in // absdb: self.in o: _988 with obitwidth:16
[absd] uint16_t _989 = _b_b_stencil_4 |-| _b_b_stencil_2;
// _b_b_stencil_4 added as input _b_b_stencil_4
// _b_b_stencil_2 added as input _b_b_stencil_2
// absda: self.in // absdb: self.in o: _989 with obitwidth:16
bool _990 = _988 < _989;
// ulta: _988 // ultb: _989 o: _990 with obitwidth:1
uint16_t _991 = _b_b_stencil_1 + _b_b_stencil_3;
// _b_b_stencil_1 added as input _b_b_stencil_1
// _b_b_stencil_3 added as input _b_b_stencil_3
// adda: self.in // addb: self.in o: _991 with obitwidth:16
uint16_t _992 = _991 >> _966;
// created const: const_p1__966$6 with name _966
// lshra: _991 // lshrb: _966 o: _992 with obitwidth:16
[absd] uint16_t _993 = _g_gr_stencil_13 |-| _g_gr_stencil_10;
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// absda: self.in // absdb: self.in o: _993 with obitwidth:16
[absd] uint16_t _994 = _g_gb_stencil_13 |-| _g_gb_stencil_11;
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// absda: self.in // absdb: self.in o: _994 with obitwidth:16
bool _995 = _993 < _994;
// ulta: _993 // ultb: _994 o: _995 with obitwidth:1
uint16_t _996 = _g_gr_stencil_13 + _g_gr_stencil_10;
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// _g_gr_stencil_10 added as input _g_gr_stencil_10
// adda: self.in // addb: self.in o: _996 with obitwidth:16
uint16_t _997 = _996 >> _966;
// created const: const_p1__966$7 with name _966
// lshra: _996 // lshrb: _966 o: _997 with obitwidth:16
uint16_t _998 = _g_gb_stencil_13 + _g_gb_stencil_11;
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// adda: self.in // addb: self.in o: _998 with obitwidth:16
uint16_t _999 = _998 >> _966;
// created const: const_p1__966$8 with name _966
// lshra: _998 // lshrb: _966 o: _999 with obitwidth:16
uint16_t _1000 = _995 ? _997 : _999;
// muxa: _995 // muxb: _997 // muxc: _999 o: _1000
uint16_t _1001 = _992 + _1000;
// adda: _992 // addb: _1000 o: _1001 with obitwidth:16
[absd] uint16_t _1002 = _g_gb_stencil_13 |-| _g_gb_stencil_14;
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// _g_gb_stencil_14 added as input _g_gb_stencil_14
// absda: self.in // absdb: self.in o: _1002 with obitwidth:16
[absd] uint16_t _1003 = _g_gr_stencil_13 |-| _g_gr_stencil_14;
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// _g_gr_stencil_14 added as input _g_gr_stencil_14
// absda: self.in // absdb: self.in o: _1003 with obitwidth:16
bool _1004 = _1002 < _1003;
// ulta: _1002 // ultb: _1003 o: _1004 with obitwidth:1
uint16_t _1005 = _g_gb_stencil_13 + _g_gb_stencil_14;
// _g_gb_stencil_13 added as input _g_gb_stencil_13
// _g_gb_stencil_14 added as input _g_gb_stencil_14
// adda: self.in // addb: self.in o: _1005 with obitwidth:16
uint16_t _1006 = _1005 >> _966;
// created const: const_p1__966$9 with name _966
// lshra: _1005 // lshrb: _966 o: _1006 with obitwidth:16
uint16_t _1007 = _g_gr_stencil_13 + _g_gr_stencil_14;
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// _g_gr_stencil_14 added as input _g_gr_stencil_14
// adda: self.in // addb: self.in o: _1007 with obitwidth:16
uint16_t _1008 = _1007 >> _966;
// created const: const_p1__966$10 with name _966
// lshra: _1007 // lshrb: _966 o: _1008 with obitwidth:16
uint16_t _1009 = _1004 ? _1006 : _1008;
// muxa: _1004 // muxb: _1006 // muxc: _1008 o: _1009
[absd] [absd] uint16_t _1010 = _1009 + _976;
// adda: _1009 // addb: _976 o: _1010 with obitwidth:16
uint16_t _1011 = _1010 >> _966;
// created const: const_p1__966$11 with name _966
// lshra: _1010 // lshrb: _966 o: _1011 with obitwidth:16
uint16_t _1012 = _1001 - _1011;
// suba: _1001 // subb: _1011 o: _1012 with obitwidth:16
uint16_t _1013 = _b_b_stencil_4 + _b_b_stencil_2;
// _b_b_stencil_4 added as input _b_b_stencil_4
// _b_b_stencil_2 added as input _b_b_stencil_2
// adda: self.in // addb: self.in o: _1013 with obitwidth:16
uint16_t _1014 = _1013 >> _966;
// created const: const_p1__966$12 with name _966
// lshra: _1013 // lshrb: _966 o: _1014 with obitwidth:16
[absd] [absd] uint16_t _1015 = _1014 + _1000;
// adda: _1014 // addb: _1000 o: _1015 with obitwidth:16
[absd] [absd] [absd] uint16_t _1016 = _g_gb_stencil_11 |-| _g_gb_stencil_15;
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// _g_gb_stencil_15 added as input _g_gb_stencil_15
// absda: self.in // absdb: self.in o: _1016 with obitwidth:16
[absd] uint16_t _1017 = _g_gr_stencil_15 |-| _g_gr_stencil_13;
// _g_gr_stencil_15 added as input _g_gr_stencil_15
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// absda: self.in // absdb: self.in o: _1017 with obitwidth:16
bool _1018 = _1016 < _1017;
// ulta: _1016 // ultb: _1017 o: _1018 with obitwidth:1
uint16_t _1019 = _g_gb_stencil_11 + _g_gb_stencil_15;
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// _g_gb_stencil_15 added as input _g_gb_stencil_15
// adda: self.in // addb: self.in o: _1019 with obitwidth:16
uint16_t _1020 = _1019 >> _966;
// created const: const_p1__966$13 with name _966
// lshra: _1019 // lshrb: _966 o: _1020 with obitwidth:16
uint16_t _1021 = _g_gr_stencil_13 + _g_gr_stencil_15;
// _g_gr_stencil_13 added as input _g_gr_stencil_13
// _g_gr_stencil_15 added as input _g_gr_stencil_15
// adda: self.in // addb: self.in o: _1021 with obitwidth:16
uint16_t _1022 = _1021 >> _966;
// created const: const_p1__966$14 with name _966
// lshra: _1021 // lshrb: _966 o: _1022 with obitwidth:16
uint16_t _1023 = _1018 ? _1020 : _1022;
// muxa: _1018 // muxb: _1020 // muxc: _1022 o: _1023
uint16_t _1024 = _984 + _1023;
// adda: _984 // addb: _1023 o: _1024 with obitwidth:16
uint16_t _1025 = _1024 >> _966;
// created const: const_p1__966$15 with name _966
// lshra: _1024 // lshrb: _966 o: _1025 with obitwidth:16
uint16_t _1026 = _1015 - _1025;
// suba: _1015 // subb: _1025 o: _1026 with obitwidth:16
uint16_t _1027 = _990 ? _1012 : _1026;
// muxa: _990 // muxb: _1012 // muxc: _1026 o: _1027
uint16_t _1028 = _964 ? _987 : _1027;
// muxa: _964 // muxb: _987 // muxc: _1027 o: _1028
uint16_t _1029 = _b_b_stencil_1 + _b_b_stencil_4;
// _b_b_stencil_1 added as input _b_b_stencil_1
// _b_b_stencil_4 added as input _b_b_stencil_4
// adda: self.in // addb: self.in o: _1029 with obitwidth:16
uint16_t _1030 = _1029 >> _966;
// created const: const_p1__966$16 with name _966
// lshra: _1029 // lshrb: _966 o: _1030 with obitwidth:16
uint16_t _1031 = _g_gb_stencil_11 + _1030;
// _g_gb_stencil_11 added as input _g_gb_stencil_11
// adda: self.in // addb: _1030 o: _1031 with obitwidth:16
[absd] [absd] [absd] [absd] uint16_t _1032 = _976 + _1023;
// adda: _976 // addb: _1023 o: _1032 with obitwidth:16
uint16_t _1033 = _1032 >> _966;
// created const: const_p1__966$17 with name _966
// lshra: _1032 // lshrb: _966 o: _1033 with obitwidth:16
uint16_t _1034 = _1031 - _1033;
// suba: _1031 // subb: _1033 o: _1034 with obitwidth:16
uint16_t _1035 = _964 ? _b_b_stencil_1 : _1034;
// _b_b_stencil_1 added as input _b_b_stencil_1
// muxa: _964 // muxb: self.in // muxc: _1034 o: _1035
uint16_t _1036 = _962 ? _1028 : _1035;
// muxa: _962 // muxb: _1028 // muxc: _1035 o: _1036
[absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] [absd] // connected _1036 to the output port
}

hcompute_corrected_stencil() {
[cast]uint16_t _1203 = (uint16_t)(10000);
uint16_t _1204 = _demosaicked_1_stencil_1 <min> _1203;
// _demosaicked_1_stencil_1 added as input _demosaicked_1_stencil_1
// created const: const_p10000__1203 with name _1203
// umina: self.in // uminb: _1203 o: _1204 with obitwidth:16
int32_t _1205 = (int32_t)(_1204);
// renaming _1204 to _1205
// added/modified in wire_set: _1205 = _1204
int16_t _1206 = _1205 *m 549;
// created const: const_p549_549 with name 549
// mult_middlea: _1205 // mult_middleb: 549 o: _1206 with obitwidth:16
[cast]uint16_t _1207 = _demosaicked_1_stencil_2 <min> _1203;
// _demosaicked_1_stencil_2 added as input _demosaicked_1_stencil_2
// created const: const_p10000__1203$1 with name _1203
// umina: self.in // uminb: _1203 o: _1207 with obitwidth:16
int32_t _1208 = (int32_t)(_1207);
// renaming _1207 to _1208
// added/modified in wire_set: _1208 = _1207
int16_t _1209 = _1208 *m n103;
// created const: const_n103_n103 with name n103
// mult_middlea: _1208 // mult_middleb: n103 o: _1209 with obitwidth:16
int16_t _1210 = _1206 + _1209;
// adda: _1206 // addb: _1209 o: _1210 with obitwidth:16
[cast]uint16_t _1211 = _demosaicked_1_stencil_3 <min> _1203;
// _demosaicked_1_stencil_3 added as input _demosaicked_1_stencil_3
// created const: const_p10000__1203$2 with name _1203
// umina: self.in // uminb: _1203 o: _1211 with obitwidth:16
int32_t _1212 = (int32_t)(_1211);
// renaming _1211 to _1212
// added/modified in wire_set: _1212 = _1211
int16_t _1213 = _1212 *m 7;
// created const: const_p7_7 with name 7
// mult_middlea: _1212 // mult_middleb: 7 o: _1213 with obitwidth:16
int16_t _1214 = _1210 + _1213;
// adda: _1210 // addb: _1213 o: _1214 with obitwidth:16
int16_t _1215 = (int16_t)(-40);
int16_t _1216 = _1214 + _1215;
// created const: const_n40__1215 with name _1215
// adda: _1214 // addb: _1215 o: _1216 with obitwidth:16
[cast]// renaming _1204 to _1205
// added/modified in wire_set: _1205 = _1204
[cast]// renaming _1207 to _1208
// added/modified in wire_set: _1208 = _1207
[cast]// renaming _1211 to _1212
// added/modified in wire_set: _1212 = _1211
// connected _1216 to the output port
}

hcompute_corrected_stencil_1() {
[cast]uint16_t _1260 = (uint16_t)(10000);
uint16_t _1261 = _demosaicked_1_stencil_4 <min> _1260;
// _demosaicked_1_stencil_4 added as input _demosaicked_1_stencil_4
// created const: const_p10000__1260 with name _1260
// umina: self.in // uminb: _1260 o: _1261 with obitwidth:16
int32_t _1262 = (int32_t)(_1261);
// renaming _1261 to _1262
// added/modified in wire_set: _1262 = _1261
int16_t _1263 = _1262 *m n96;
// created const: const_n96_n96 with name n96
// mult_middlea: _1262 // mult_middleb: n96 o: _1263 with obitwidth:16
[cast]uint16_t _1264 = _demosaicked_1_stencil_5 <min> _1260;
// _demosaicked_1_stencil_5 added as input _demosaicked_1_stencil_5
// created const: const_p10000__1260$1 with name _1260
// umina: self.in // uminb: _1260 o: _1264 with obitwidth:16
int32_t _1265 = (int32_t)(_1264);
// renaming _1264 to _1265
// added/modified in wire_set: _1265 = _1264
int16_t _1266 = _1265 *m 373;
// created const: const_p373_373 with name 373
// mult_middlea: _1265 // mult_middleb: 373 o: _1266 with obitwidth:16
int16_t _1267 = _1263 + _1266;
// adda: _1263 // addb: _1266 o: _1267 with obitwidth:16
[cast]uint16_t _1268 = _demosaicked_1_stencil_6 <min> _1260;
// _demosaicked_1_stencil_6 added as input _demosaicked_1_stencil_6
// created const: const_p10000__1260$2 with name _1260
// umina: self.in // uminb: _1260 o: _1268 with obitwidth:16
int32_t _1269 = (int32_t)(_1268);
// renaming _1268 to _1269
// added/modified in wire_set: _1269 = _1268
int16_t _1270 = _1269 *m 62;
// created const: const_p62_62 with name 62
// mult_middlea: _1269 // mult_middleb: 62 o: _1270 with obitwidth:16
int16_t _1271 = _1267 + _1270;
// adda: _1267 // addb: _1270 o: _1271 with obitwidth:16
int16_t _1272 = (int16_t)(-29);
int16_t _1273 = _1271 + _1272;
// created const: const_n29__1272 with name _1272
// adda: _1271 // addb: _1272 o: _1273 with obitwidth:16
[cast]// renaming _1261 to _1262
// added/modified in wire_set: _1262 = _1261
[cast]// renaming _1264 to _1265
// added/modified in wire_set: _1265 = _1264
[cast]// renaming _1268 to _1269
// added/modified in wire_set: _1269 = _1268
// connected _1273 to the output port
}

hcompute_corrected_stencil_2() {
[cast]uint16_t _1317 = (uint16_t)(10000);
uint16_t _1318 = _demosaicked_1_stencil_7 <min> _1317;
// _demosaicked_1_stencil_7 added as input _demosaicked_1_stencil_7
// created const: const_p10000__1317 with name _1317
// umina: self.in // uminb: _1317 o: _1318 with obitwidth:16
int32_t _1319 = (int32_t)(_1318);
// renaming _1318 to _1319
// added/modified in wire_set: _1319 = _1318
int16_t _1320 = _1319 *m n31;
// created const: const_n31_n31 with name n31
// mult_middlea: _1319 // mult_middleb: n31 o: _1320 with obitwidth:16
[cast]uint16_t _1321 = _demosaicked_1_stencil_8 <min> _1317;
// _demosaicked_1_stencil_8 added as input _demosaicked_1_stencil_8
// created const: const_p10000__1317$1 with name _1317
// umina: self.in // uminb: _1317 o: _1321 with obitwidth:16
int32_t _1322 = (int32_t)(_1321);
// renaming _1321 to _1322
// added/modified in wire_set: _1322 = _1321
int16_t _1323 = _1322 *m n261;
// created const: const_n261_n261 with name n261
// mult_middlea: _1322 // mult_middleb: n261 o: _1323 with obitwidth:16
int16_t _1324 = _1320 + _1323;
// adda: _1320 // addb: _1323 o: _1324 with obitwidth:16
[cast]uint16_t _1325 = _demosaicked_1_stencil_9 <min> _1317;
// _demosaicked_1_stencil_9 added as input _demosaicked_1_stencil_9
// created const: const_p10000__1317$2 with name _1317
// umina: self.in // uminb: _1317 o: _1325 with obitwidth:16
int32_t _1326 = (int32_t)(_1325);
// renaming _1325 to _1326
// added/modified in wire_set: _1326 = _1325
int16_t _1327 = _1326 *m 883;
// created const: const_p883_883 with name 883
// mult_middlea: _1326 // mult_middleb: 883 o: _1327 with obitwidth:16
int16_t _1328 = _1324 + _1327;
// adda: _1324 // addb: _1327 o: _1328 with obitwidth:16
int16_t _1329 = (int16_t)(-22);
int16_t _1330 = _1328 + _1329;
// created const: const_n22__1329 with name _1329
// adda: _1328 // addb: _1329 o: _1330 with obitwidth:16
[cast]// renaming _1318 to _1319
// added/modified in wire_set: _1319 = _1318
[cast]// renaming _1321 to _1322
// added/modified in wire_set: _1322 = _1321
[cast]// renaming _1325 to _1326
// added/modified in wire_set: _1326 = _1325
// connected _1330 to the output port
}

hcompute_curved_stencil() {
// adding coreir inst curvea0
[cast]int16_t _3409 = (int16_t)(1023);
int16_t _3410 = _corrected_stencil_1 <smin> _3409;
// _corrected_stencil_1 added as input _corrected_stencil_1
// created const: const_p1023__3409 with name _3409
// smina: self.in // sminb: _3409 o: _3410 with obitwidth:16
int16_t _3411 = (int16_t)(0);
int16_t _3412 = _3410 <smax> _3411;
// created const: const_p0__3411 with name _3411
// smaxa: _3410 // smaxb: _3411 o: _3412 with obitwidth:16
uint16_t _3413 = (uint16_t)(_3412);
// renaming _3412 to _3413
// added/modified in wire_set: _3413 = _3412
uint16_t _3414 = ((uint16_t *)_curvea0)[_3413][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0
[cast]// renaming _3412 to _3413
// added/modified in wire_set: _3413 = _3412
// loading from rom curvea0 with gen memory.rom2
// connected _3414 to the output port
}

hcompute_curved_stencil_1() {
// adding coreir inst curvea0
[cast]int16_t _4454 = (int16_t)(1023);
int16_t _4455 = _corrected_stencil_2 <smin> _4454;
// _corrected_stencil_2 added as input _corrected_stencil_2
// created const: const_p1023__4454 with name _4454
// smina: self.in // sminb: _4454 o: _4455 with obitwidth:16
int16_t _4456 = (int16_t)(0);
int16_t _4457 = _4455 <smax> _4456;
// created const: const_p0__4456 with name _4456
// smaxa: _4455 // smaxb: _4456 o: _4457 with obitwidth:16
uint16_t _4458 = (uint16_t)(_4457);
// renaming _4457 to _4458
// added/modified in wire_set: _4458 = _4457
uint16_t _4459 = ((uint16_t *)_curvea0)[_4458][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$1
[cast]// renaming _4457 to _4458
// added/modified in wire_set: _4458 = _4457
// loading from rom curvea0 with gen memory.rom2
// connected _4459 to the output port
}

hcompute_curved_stencil_2() {
// adding coreir inst curvea0
[cast]int16_t _5499 = (int16_t)(1023);
int16_t _5500 = _corrected_stencil_3 <smin> _5499;
// _corrected_stencil_3 added as input _corrected_stencil_3
// created const: const_p1023__5499 with name _5499
// smina: self.in // sminb: _5499 o: _5500 with obitwidth:16
int16_t _5501 = (int16_t)(0);
int16_t _5502 = _5500 <smax> _5501;
// created const: const_p0__5501 with name _5501
// smaxa: _5500 // smaxb: _5501 o: _5502 with obitwidth:16
uint16_t _5503 = (uint16_t)(_5502);
// renaming _5502 to _5503
// added/modified in wire_set: _5503 = _5502
uint16_t _5504 = ((uint16_t *)_curvea0)[_5503][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$2
[cast]// renaming _5502 to _5503
// added/modified in wire_set: _5503 = _5502
// loading from rom curvea0 with gen memory.rom2
// connected _5504 to the output port
}

hcompute_hw_output_stencil() {
// _curved_stencil_1 added as input _curved_stencil_1
// connected _curved_stencil_1 to the output port
}

hcompute_hw_output_stencil_1() {
// _curved_stencil_2 added as input _curved_stencil_2
// connected _curved_stencil_2 to the output port
}

hcompute_hw_output_stencil_2() {
// _curved_stencil_3 added as input _curved_stencil_3
// connected _curved_stencil_3 to the output port
}

