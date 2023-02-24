hcompute_hw_input_global_wrapper_glb_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_glb_stencil_1() {
// _hw_input_stencil_2 added as input _hw_input_stencil_2
// connected _hw_input_stencil_2 to the output port
}

hcompute_hw_input_global_wrapper_glb_stencil_2() {
// _hw_input_stencil_3 added as input _hw_input_stencil_3
// connected _hw_input_stencil_3 to the output port
}

hcompute_hw_input_global_wrapper_glb_stencil_3() {
// _hw_input_stencil_4 added as input _hw_input_stencil_4
// connected _hw_input_stencil_4 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil() {
// _hw_input_global_wrapper_glb_stencil_1 added as input _hw_input_global_wrapper_glb_stencil_1
// connected _hw_input_global_wrapper_glb_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil_1() {
// _hw_input_global_wrapper_glb_stencil_2 added as input _hw_input_global_wrapper_glb_stencil_2
// connected _hw_input_global_wrapper_glb_stencil_2 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil_2() {
// _hw_input_global_wrapper_glb_stencil_3 added as input _hw_input_global_wrapper_glb_stencil_3
// connected _hw_input_global_wrapper_glb_stencil_3 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil_3() {
// _hw_input_global_wrapper_glb_stencil_4 added as input _hw_input_global_wrapper_glb_stencil_4
// connected _hw_input_global_wrapper_glb_stencil_4 to the output port
}

hcompute_denoised_1_stencil() {
uint16_t _376 = _hw_input_global_wrapper_global_wrapper_stencil_4 <max> _hw_input_global_wrapper_global_wrapper_stencil_5;
// _hw_input_global_wrapper_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_global_wrapper_stencil_4
// _hw_input_global_wrapper_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_global_wrapper_stencil_5
// umaxa: self.in // umaxb: self.in o: _376 with obitwidth:16
uint16_t _377 = _hw_input_global_wrapper_global_wrapper_stencil_3 <max> _376;
// _hw_input_global_wrapper_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_global_wrapper_stencil_3
// umaxa: self.in // umaxb: _376 o: _377 with obitwidth:16
uint16_t _378 = _hw_input_global_wrapper_global_wrapper_stencil_2 <max> _377;
// _hw_input_global_wrapper_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_global_wrapper_stencil_2
// umaxa: self.in // umaxb: _377 o: _378 with obitwidth:16
uint16_t _379 = _hw_input_global_wrapper_global_wrapper_stencil_1 <min> _378;
// _hw_input_global_wrapper_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_global_wrapper_stencil_1
// umina: self.in // uminb: _378 o: _379 with obitwidth:16
// connected _379 to the output port
}

hcompute_denoised_1_stencil_1() {
uint16_t _399 = _hw_input_global_wrapper_global_wrapper_stencil_9 <max> _hw_input_global_wrapper_global_wrapper_stencil_10;
// _hw_input_global_wrapper_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_global_wrapper_stencil_9
// _hw_input_global_wrapper_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_global_wrapper_stencil_10
// umaxa: self.in // umaxb: self.in o: _399 with obitwidth:16
uint16_t _400 = _hw_input_global_wrapper_global_wrapper_stencil_8 <max> _399;
// _hw_input_global_wrapper_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_global_wrapper_stencil_8
// umaxa: self.in // umaxb: _399 o: _400 with obitwidth:16
uint16_t _401 = _hw_input_global_wrapper_global_wrapper_stencil_7 <max> _400;
// _hw_input_global_wrapper_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_global_wrapper_stencil_7
// umaxa: self.in // umaxb: _400 o: _401 with obitwidth:16
uint16_t _402 = _hw_input_global_wrapper_global_wrapper_stencil_6 <min> _401;
// _hw_input_global_wrapper_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_global_wrapper_stencil_6
// umina: self.in // uminb: _401 o: _402 with obitwidth:16
// connected _402 to the output port
}

hcompute_denoised_1_stencil_2() {
uint16_t _423 = _hw_input_global_wrapper_global_wrapper_stencil_14 <max> _hw_input_global_wrapper_global_wrapper_stencil_15;
// _hw_input_global_wrapper_global_wrapper_stencil_14 added as input _hw_input_global_wrapper_global_wrapper_stencil_14
// _hw_input_global_wrapper_global_wrapper_stencil_15 added as input _hw_input_global_wrapper_global_wrapper_stencil_15
// umaxa: self.in // umaxb: self.in o: _423 with obitwidth:16
uint16_t _424 = _hw_input_global_wrapper_global_wrapper_stencil_13 <max> _423;
// _hw_input_global_wrapper_global_wrapper_stencil_13 added as input _hw_input_global_wrapper_global_wrapper_stencil_13
// umaxa: self.in // umaxb: _423 o: _424 with obitwidth:16
uint16_t _425 = _hw_input_global_wrapper_global_wrapper_stencil_12 <max> _424;
// _hw_input_global_wrapper_global_wrapper_stencil_12 added as input _hw_input_global_wrapper_global_wrapper_stencil_12
// umaxa: self.in // umaxb: _424 o: _425 with obitwidth:16
uint16_t _426 = _hw_input_global_wrapper_global_wrapper_stencil_11 <min> _425;
// _hw_input_global_wrapper_global_wrapper_stencil_11 added as input _hw_input_global_wrapper_global_wrapper_stencil_11
// umina: self.in // uminb: _425 o: _426 with obitwidth:16
// connected _426 to the output port
}

hcompute_denoised_1_stencil_3() {
uint16_t _447 = _hw_input_global_wrapper_global_wrapper_stencil_19 <max> _hw_input_global_wrapper_global_wrapper_stencil_20;
// _hw_input_global_wrapper_global_wrapper_stencil_19 added as input _hw_input_global_wrapper_global_wrapper_stencil_19
// _hw_input_global_wrapper_global_wrapper_stencil_20 added as input _hw_input_global_wrapper_global_wrapper_stencil_20
// umaxa: self.in // umaxb: self.in o: _447 with obitwidth:16
uint16_t _448 = _hw_input_global_wrapper_global_wrapper_stencil_18 <max> _447;
// _hw_input_global_wrapper_global_wrapper_stencil_18 added as input _hw_input_global_wrapper_global_wrapper_stencil_18
// umaxa: self.in // umaxb: _447 o: _448 with obitwidth:16
uint16_t _449 = _hw_input_global_wrapper_global_wrapper_stencil_17 <max> _448;
// _hw_input_global_wrapper_global_wrapper_stencil_17 added as input _hw_input_global_wrapper_global_wrapper_stencil_17
// umaxa: self.in // umaxb: _448 o: _449 with obitwidth:16
uint16_t _450 = _hw_input_global_wrapper_global_wrapper_stencil_16 <min> _449;
// _hw_input_global_wrapper_global_wrapper_stencil_16 added as input _hw_input_global_wrapper_global_wrapper_stencil_16
// umina: self.in // uminb: _449 o: _450 with obitwidth:16
// connected _450 to the output port
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

hcompute_g_b_stencil() {
[absd] uint16_t _505 = _g_gb_stencil_1 |-| _g_gb_stencil_2;
// _g_gb_stencil_1 added as input _g_gb_stencil_1
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// absda: self.in // absdb: self.in o: _505 with obitwidth:16
[absd] uint16_t _506 = _g_gr_stencil_1 |-| _g_gr_stencil_2;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// _g_gr_stencil_2 added as input _g_gr_stencil_2
// absda: self.in // absdb: self.in o: _506 with obitwidth:16
bool _507 = _505 < _506;
// ulta: _505 // ultb: _506 o: _507 with obitwidth:1
uint16_t _508 = _g_gb_stencil_1 + _g_gb_stencil_2;
// _g_gb_stencil_1 added as input _g_gb_stencil_1
// _g_gb_stencil_2 added as input _g_gb_stencil_2
// adda: self.in // addb: self.in o: _508 with obitwidth:16
uint16_t _509 = (uint16_t)(1);
uint16_t _510 = _508 >> _509;
// created const: const_p1__509 with name _509
// lshra: _508 // lshrb: _509 o: _510 with obitwidth:16
uint16_t _511 = _g_gr_stencil_1 + _g_gr_stencil_2;
// _g_gr_stencil_1 added as input _g_gr_stencil_1
// _g_gr_stencil_2 added as input _g_gr_stencil_2
// adda: self.in // addb: self.in o: _511 with obitwidth:16
uint16_t _512 = _511 >> _509;
// created const: const_p1__509$1 with name _509
// lshra: _511 // lshrb: _509 o: _512 with obitwidth:16
uint16_t _513 = _507 ? _510 : _512;
// muxa: _507 // muxb: _510 // muxc: _512 o: _513
[absd] [absd] // connected _513 to the output port
}

hcompute_b_gb_stencil() {
uint16_t _545 = _b_b_stencil_1 + _b_b_stencil_2;
// _b_b_stencil_1 added as input _b_b_stencil_1
// _b_b_stencil_2 added as input _b_b_stencil_2
// adda: self.in // addb: self.in o: _545 with obitwidth:16
uint16_t _546 = (uint16_t)(1);
uint16_t _547 = _545 >> _546;
// created const: const_p1__546 with name _546
// lshra: _545 // lshrb: _546 o: _547 with obitwidth:16
uint16_t _548 = _g_gb_stencil_3 + _547;
// _g_gb_stencil_3 added as input _g_gb_stencil_3
// adda: self.in // addb: _547 o: _548 with obitwidth:16
uint16_t _549 = _g_b_stencil_1 + _g_b_stencil_2;
// _g_b_stencil_1 added as input _g_b_stencil_1
// _g_b_stencil_2 added as input _g_b_stencil_2
// adda: self.in // addb: self.in o: _549 with obitwidth:16
uint16_t _550 = _549 >> _546;
// created const: const_p1__546$1 with name _546
// lshra: _549 // lshrb: _546 o: _550 with obitwidth:16
uint16_t _551 = _548 - _550;
// suba: _548 // subb: _550 o: _551 with obitwidth:16
// connected _551 to the output port
}

hcompute_b_gr_stencil() {
uint16_t _573 = _b_b_stencil_3 + _b_b_stencil_4;
// _b_b_stencil_3 added as input _b_b_stencil_3
// _b_b_stencil_4 added as input _b_b_stencil_4
// adda: self.in // addb: self.in o: _573 with obitwidth:16
uint16_t _574 = (uint16_t)(1);
uint16_t _575 = _573 >> _574;
// created const: const_p1__574 with name _574
// lshra: _573 // lshrb: _574 o: _575 with obitwidth:16
uint16_t _576 = _g_gr_stencil_3 + _575;
// _g_gr_stencil_3 added as input _g_gr_stencil_3
// adda: self.in // addb: _575 o: _576 with obitwidth:16
uint16_t _577 = _g_b_stencil_3 + _g_b_stencil_4;
// _g_b_stencil_3 added as input _g_b_stencil_3
// _g_b_stencil_4 added as input _g_b_stencil_4
// adda: self.in // addb: self.in o: _577 with obitwidth:16
uint16_t _578 = _577 >> _574;
// created const: const_p1__574$1 with name _574
// lshra: _577 // lshrb: _574 o: _578 with obitwidth:16
uint16_t _579 = _576 - _578;
// suba: _576 // subb: _578 o: _579 with obitwidth:16
// connected _579 to the output port
}

hcompute_g_r_stencil() {
[absd] uint16_t _611 = _g_gr_stencil_4 |-| _g_gr_stencil_5;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_5 added as input _g_gr_stencil_5
// absda: self.in // absdb: self.in o: _611 with obitwidth:16
[absd] uint16_t _612 = _g_gb_stencil_4 |-| _g_gb_stencil_5;
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// _g_gb_stencil_5 added as input _g_gb_stencil_5
// absda: self.in // absdb: self.in o: _612 with obitwidth:16
bool _613 = _611 < _612;
// ulta: _611 // ultb: _612 o: _613 with obitwidth:1
uint16_t _614 = _g_gr_stencil_4 + _g_gr_stencil_5;
// _g_gr_stencil_4 added as input _g_gr_stencil_4
// _g_gr_stencil_5 added as input _g_gr_stencil_5
// adda: self.in // addb: self.in o: _614 with obitwidth:16
uint16_t _615 = (uint16_t)(1);
uint16_t _616 = _614 >> _615;
// created const: const_p1__615 with name _615
// lshra: _614 // lshrb: _615 o: _616 with obitwidth:16
uint16_t _617 = _g_gb_stencil_4 + _g_gb_stencil_5;
// _g_gb_stencil_4 added as input _g_gb_stencil_4
// _g_gb_stencil_5 added as input _g_gb_stencil_5
// adda: self.in // addb: self.in o: _617 with obitwidth:16
uint16_t _618 = _617 >> _615;
// created const: const_p1__615$1 with name _615
// lshra: _617 // lshrb: _615 o: _618 with obitwidth:16
uint16_t _619 = _613 ? _616 : _618;
// muxa: _613 // muxb: _616 // muxc: _618 o: _619
[absd] [absd] // connected _619 to the output port
}

hcompute_b_r_stencil() {
[absd] uint16_t _669 = _b_b_stencil_5 |-| _b_b_stencil_6;
// _b_b_stencil_5 added as input _b_b_stencil_5
// _b_b_stencil_6 added as input _b_b_stencil_6
// absda: self.in // absdb: self.in o: _669 with obitwidth:16
[absd] uint16_t _670 = _b_b_stencil_7 |-| _b_b_stencil_8;
// _b_b_stencil_7 added as input _b_b_stencil_7
// _b_b_stencil_8 added as input _b_b_stencil_8
// absda: self.in // absdb: self.in o: _670 with obitwidth:16
bool _671 = _669 < _670;
// ulta: _669 // ultb: _670 o: _671 with obitwidth:1
uint16_t _672 = _b_b_stencil_5 + _b_b_stencil_6;
// _b_b_stencil_5 added as input _b_b_stencil_5
// _b_b_stencil_6 added as input _b_b_stencil_6
// adda: self.in // addb: self.in o: _672 with obitwidth:16
uint16_t _673 = (uint16_t)(1);
uint16_t _674 = _672 >> _673;
// created const: const_p1__673 with name _673
// lshra: _672 // lshrb: _673 o: _674 with obitwidth:16
uint16_t _675 = _g_r_stencil_1 + _674;
// _g_r_stencil_1 added as input _g_r_stencil_1
// adda: self.in // addb: _674 o: _675 with obitwidth:16
uint16_t _676 = _g_b_stencil_5 + _g_b_stencil_6;
// _g_b_stencil_5 added as input _g_b_stencil_5
// _g_b_stencil_6 added as input _g_b_stencil_6
// adda: self.in // addb: self.in o: _676 with obitwidth:16
uint16_t _677 = _676 >> _673;
// created const: const_p1__673$1 with name _673
// lshra: _676 // lshrb: _673 o: _677 with obitwidth:16
uint16_t _678 = _675 - _677;
// suba: _675 // subb: _677 o: _678 with obitwidth:16
uint16_t _679 = _b_b_stencil_7 + _b_b_stencil_8;
// _b_b_stencil_7 added as input _b_b_stencil_7
// _b_b_stencil_8 added as input _b_b_stencil_8
// adda: self.in // addb: self.in o: _679 with obitwidth:16
uint16_t _680 = _679 >> _673;
// created const: const_p1__673$2 with name _673
// lshra: _679 // lshrb: _673 o: _680 with obitwidth:16
uint16_t _681 = _g_r_stencil_1 + _680;
// _g_r_stencil_1 added as input _g_r_stencil_1
// adda: self.in // addb: _680 o: _681 with obitwidth:16
uint16_t _682 = _g_b_stencil_7 + _g_b_stencil_8;
// _g_b_stencil_7 added as input _g_b_stencil_7
// _g_b_stencil_8 added as input _g_b_stencil_8
// adda: self.in // addb: self.in o: _682 with obitwidth:16
uint16_t _683 = _682 >> _673;
// created const: const_p1__673$3 with name _673
// lshra: _682 // lshrb: _673 o: _683 with obitwidth:16
uint16_t _684 = _681 - _683;
// suba: _681 // subb: _683 o: _684 with obitwidth:16
uint16_t _685 = _671 ? _678 : _684;
// muxa: _671 // muxb: _678 // muxc: _684 o: _685
[absd] [absd] // connected _685 to the output port
}

hcompute_r_r_stencil() {
// _denoised_1_stencil_4 added as input _denoised_1_stencil_4
// connected _denoised_1_stencil_4 to the output port
}

hcompute_r_b_stencil() {
[absd] uint16_t _753 = _r_r_stencil_1 |-| _r_r_stencil_2;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_2 added as input _r_r_stencil_2
// absda: self.in // absdb: self.in o: _753 with obitwidth:16
[absd] uint16_t _754 = _r_r_stencil_3 |-| _r_r_stencil_4;
// _r_r_stencil_3 added as input _r_r_stencil_3
// _r_r_stencil_4 added as input _r_r_stencil_4
// absda: self.in // absdb: self.in o: _754 with obitwidth:16
bool _755 = _753 < _754;
// ulta: _753 // ultb: _754 o: _755 with obitwidth:1
uint16_t _756 = _r_r_stencil_1 + _r_r_stencil_2;
// _r_r_stencil_1 added as input _r_r_stencil_1
// _r_r_stencil_2 added as input _r_r_stencil_2
// adda: self.in // addb: self.in o: _756 with obitwidth:16
uint16_t _757 = (uint16_t)(1);
uint16_t _758 = _756 >> _757;
// created const: const_p1__757 with name _757
// lshra: _756 // lshrb: _757 o: _758 with obitwidth:16
uint16_t _759 = _g_b_stencil_9 + _758;
// _g_b_stencil_9 added as input _g_b_stencil_9
// adda: self.in // addb: _758 o: _759 with obitwidth:16
uint16_t _760 = _g_r_stencil_2 + _g_r_stencil_3;
// _g_r_stencil_2 added as input _g_r_stencil_2
// _g_r_stencil_3 added as input _g_r_stencil_3
// adda: self.in // addb: self.in o: _760 with obitwidth:16
uint16_t _761 = _760 >> _757;
// created const: const_p1__757$1 with name _757
// lshra: _760 // lshrb: _757 o: _761 with obitwidth:16
uint16_t _762 = _759 - _761;
// suba: _759 // subb: _761 o: _762 with obitwidth:16
uint16_t _763 = _r_r_stencil_3 + _r_r_stencil_4;
// _r_r_stencil_3 added as input _r_r_stencil_3
// _r_r_stencil_4 added as input _r_r_stencil_4
// adda: self.in // addb: self.in o: _763 with obitwidth:16
uint16_t _764 = _763 >> _757;
// created const: const_p1__757$2 with name _757
// lshra: _763 // lshrb: _757 o: _764 with obitwidth:16
uint16_t _765 = _g_b_stencil_9 + _764;
// _g_b_stencil_9 added as input _g_b_stencil_9
// adda: self.in // addb: _764 o: _765 with obitwidth:16
uint16_t _766 = _g_r_stencil_4 + _g_r_stencil_5;
// _g_r_stencil_4 added as input _g_r_stencil_4
// _g_r_stencil_5 added as input _g_r_stencil_5
// adda: self.in // addb: self.in o: _766 with obitwidth:16
uint16_t _767 = _766 >> _757;
// created const: const_p1__757$3 with name _757
// lshra: _766 // lshrb: _757 o: _767 with obitwidth:16
uint16_t _768 = _765 - _767;
// suba: _765 // subb: _767 o: _768 with obitwidth:16
uint16_t _769 = _755 ? _762 : _768;
// muxa: _755 // muxb: _762 // muxc: _768 o: _769
[absd] [absd] // connected _769 to the output port
}

hcompute_r_gb_stencil() {
uint16_t _813 = _r_r_stencil_5 + _r_r_stencil_6;
// _r_r_stencil_5 added as input _r_r_stencil_5
// _r_r_stencil_6 added as input _r_r_stencil_6
// adda: self.in // addb: self.in o: _813 with obitwidth:16
uint16_t _814 = (uint16_t)(1);
uint16_t _815 = _813 >> _814;
// created const: const_p1__814 with name _814
// lshra: _813 // lshrb: _814 o: _815 with obitwidth:16
uint16_t _816 = _g_gb_stencil_6 + _815;
// _g_gb_stencil_6 added as input _g_gb_stencil_6
// adda: self.in // addb: _815 o: _816 with obitwidth:16
uint16_t _817 = _g_r_stencil_6 + _g_r_stencil_7;
// _g_r_stencil_6 added as input _g_r_stencil_6
// _g_r_stencil_7 added as input _g_r_stencil_7
// adda: self.in // addb: self.in o: _817 with obitwidth:16
uint16_t _818 = _817 >> _814;
// created const: const_p1__814$1 with name _814
// lshra: _817 // lshrb: _814 o: _818 with obitwidth:16
uint16_t _819 = _816 - _818;
// suba: _816 // subb: _818 o: _819 with obitwidth:16
// connected _819 to the output port
}

hcompute_r_gr_stencil() {
uint16_t _841 = _r_r_stencil_7 + _r_r_stencil_8;
// _r_r_stencil_7 added as input _r_r_stencil_7
// _r_r_stencil_8 added as input _r_r_stencil_8
// adda: self.in // addb: self.in o: _841 with obitwidth:16
uint16_t _842 = (uint16_t)(1);
uint16_t _843 = _841 >> _842;
// created const: const_p1__842 with name _842
// lshra: _841 // lshrb: _842 o: _843 with obitwidth:16
uint16_t _844 = _g_gr_stencil_6 + _843;
// _g_gr_stencil_6 added as input _g_gr_stencil_6
// adda: self.in // addb: _843 o: _844 with obitwidth:16
uint16_t _845 = _g_r_stencil_8 + _g_r_stencil_9;
// _g_r_stencil_8 added as input _g_r_stencil_8
// _g_r_stencil_9 added as input _g_r_stencil_9
// adda: self.in // addb: self.in o: _845 with obitwidth:16
uint16_t _846 = _845 >> _842;
// created const: const_p1__842$1 with name _842
// lshra: _845 // lshrb: _842 o: _846 with obitwidth:16
uint16_t _847 = _844 - _846;
// suba: _844 // subb: _846 o: _847 with obitwidth:16
// connected _847 to the output port
}

hcompute_demosaicked_1_stencil() {
// _r_gr_stencil_1 added as input _r_gr_stencil_1
// connected _r_gr_stencil_1 to the output port
}

hcompute_demosaicked_1_stencil_1() {
// _g_gr_stencil_7 added as input _g_gr_stencil_7
// connected _g_gr_stencil_7 to the output port
}

hcompute_demosaicked_1_stencil_2() {
// _b_gr_stencil_1 added as input _b_gr_stencil_1
// connected _b_gr_stencil_1 to the output port
}

hcompute_demosaicked_1_stencil_3() {
// _r_b_stencil_1 added as input _r_b_stencil_1
// connected _r_b_stencil_1 to the output port
}

hcompute_demosaicked_1_stencil_4() {
// _g_b_stencil_10 added as input _g_b_stencil_10
// connected _g_b_stencil_10 to the output port
}

hcompute_demosaicked_1_stencil_5() {
// _b_b_stencil_9 added as input _b_b_stencil_9
// connected _b_b_stencil_9 to the output port
}

hcompute_demosaicked_1_stencil_6() {
// _r_r_stencil_9 added as input _r_r_stencil_9
// connected _r_r_stencil_9 to the output port
}

hcompute_demosaicked_1_stencil_7() {
// _g_r_stencil_10 added as input _g_r_stencil_10
// connected _g_r_stencil_10 to the output port
}

hcompute_demosaicked_1_stencil_8() {
// _b_r_stencil_1 added as input _b_r_stencil_1
// connected _b_r_stencil_1 to the output port
}

hcompute_demosaicked_1_stencil_9() {
// _r_gb_stencil_1 added as input _r_gb_stencil_1
// connected _r_gb_stencil_1 to the output port
}

hcompute_demosaicked_1_stencil_10() {
// _g_gb_stencil_7 added as input _g_gb_stencil_7
// connected _g_gb_stencil_7 to the output port
}

hcompute_demosaicked_1_stencil_11() {
// _b_gb_stencil_1 added as input _b_gb_stencil_1
// connected _b_gb_stencil_1 to the output port
}

hcompute_corrected_stencil() {
[cast]uint16_t _938 = (uint16_t)(10000);
uint16_t _939 = _demosaicked_1_stencil_1 <min> _938;
// _demosaicked_1_stencil_1 added as input _demosaicked_1_stencil_1
// created const: const_p10000__938 with name _938
// umina: self.in // uminb: _938 o: _939 with obitwidth:16
int32_t _940 = (int32_t)(_939);
// renaming _939 to _940
// added/modified in wire_set: _940 = _939
int16_t _941 = _940 *m 549;
// created const: const_p549_549 with name 549
// mult_middlea: _940 // mult_middleb: 549 o: _941 with obitwidth:16
[cast]uint16_t _942 = _demosaicked_1_stencil_2 <min> _938;
// _demosaicked_1_stencil_2 added as input _demosaicked_1_stencil_2
// created const: const_p10000__938$1 with name _938
// umina: self.in // uminb: _938 o: _942 with obitwidth:16
int32_t _943 = (int32_t)(_942);
// renaming _942 to _943
// added/modified in wire_set: _943 = _942
int16_t _944 = _943 *m n103;
// created const: const_n103_n103 with name n103
// mult_middlea: _943 // mult_middleb: n103 o: _944 with obitwidth:16
int16_t _945 = _941 + _944;
// adda: _941 // addb: _944 o: _945 with obitwidth:16
[cast]uint16_t _946 = _demosaicked_1_stencil_3 <min> _938;
// _demosaicked_1_stencil_3 added as input _demosaicked_1_stencil_3
// created const: const_p10000__938$2 with name _938
// umina: self.in // uminb: _938 o: _946 with obitwidth:16
int32_t _947 = (int32_t)(_946);
// renaming _946 to _947
// added/modified in wire_set: _947 = _946
int16_t _948 = _947 *m 7;
// created const: const_p7_7 with name 7
// mult_middlea: _947 // mult_middleb: 7 o: _948 with obitwidth:16
int16_t _949 = _945 + _948;
// adda: _945 // addb: _948 o: _949 with obitwidth:16
int16_t _950 = (int16_t)(-40);
int16_t _951 = _949 + _950;
// created const: const_n40__950 with name _950
// adda: _949 // addb: _950 o: _951 with obitwidth:16
[cast]// renaming _939 to _940
// added/modified in wire_set: _940 = _939
[cast]// renaming _942 to _943
// added/modified in wire_set: _943 = _942
[cast]// renaming _946 to _947
// added/modified in wire_set: _947 = _946
// connected _951 to the output port
}

hcompute_corrected_stencil_1() {
[cast]uint16_t _997 = (uint16_t)(10000);
uint16_t _998 = _demosaicked_1_stencil_4 <min> _997;
// _demosaicked_1_stencil_4 added as input _demosaicked_1_stencil_4
// created const: const_p10000__997 with name _997
// umina: self.in // uminb: _997 o: _998 with obitwidth:16
int32_t _999 = (int32_t)(_998);
// renaming _998 to _999
// added/modified in wire_set: _999 = _998
int16_t _1000 = _999 *m n96;
// created const: const_n96_n96 with name n96
// mult_middlea: _999 // mult_middleb: n96 o: _1000 with obitwidth:16
[cast]uint16_t _1001 = _demosaicked_1_stencil_5 <min> _997;
// _demosaicked_1_stencil_5 added as input _demosaicked_1_stencil_5
// created const: const_p10000__997$1 with name _997
// umina: self.in // uminb: _997 o: _1001 with obitwidth:16
int32_t _1002 = (int32_t)(_1001);
// renaming _1001 to _1002
// added/modified in wire_set: _1002 = _1001
int16_t _1003 = _1002 *m 373;
// created const: const_p373_373 with name 373
// mult_middlea: _1002 // mult_middleb: 373 o: _1003 with obitwidth:16
int16_t _1004 = _1000 + _1003;
// adda: _1000 // addb: _1003 o: _1004 with obitwidth:16
[cast]uint16_t _1005 = _demosaicked_1_stencil_6 <min> _997;
// _demosaicked_1_stencil_6 added as input _demosaicked_1_stencil_6
// created const: const_p10000__997$2 with name _997
// umina: self.in // uminb: _997 o: _1005 with obitwidth:16
int32_t _1006 = (int32_t)(_1005);
// renaming _1005 to _1006
// added/modified in wire_set: _1006 = _1005
int16_t _1007 = _1006 *m 62;
// created const: const_p62_62 with name 62
// mult_middlea: _1006 // mult_middleb: 62 o: _1007 with obitwidth:16
int16_t _1008 = _1004 + _1007;
// adda: _1004 // addb: _1007 o: _1008 with obitwidth:16
int16_t _1009 = (int16_t)(-29);
int16_t _1010 = _1008 + _1009;
// created const: const_n29__1009 with name _1009
// adda: _1008 // addb: _1009 o: _1010 with obitwidth:16
[cast]// renaming _998 to _999
// added/modified in wire_set: _999 = _998
[cast]// renaming _1001 to _1002
// added/modified in wire_set: _1002 = _1001
[cast]// renaming _1005 to _1006
// added/modified in wire_set: _1006 = _1005
// connected _1010 to the output port
}

hcompute_corrected_stencil_2() {
[cast]uint16_t _1056 = (uint16_t)(10000);
uint16_t _1057 = _demosaicked_1_stencil_7 <min> _1056;
// _demosaicked_1_stencil_7 added as input _demosaicked_1_stencil_7
// created const: const_p10000__1056 with name _1056
// umina: self.in // uminb: _1056 o: _1057 with obitwidth:16
int32_t _1058 = (int32_t)(_1057);
// renaming _1057 to _1058
// added/modified in wire_set: _1058 = _1057
int16_t _1059 = _1058 *m n31;
// created const: const_n31_n31 with name n31
// mult_middlea: _1058 // mult_middleb: n31 o: _1059 with obitwidth:16
[cast]uint16_t _1060 = _demosaicked_1_stencil_8 <min> _1056;
// _demosaicked_1_stencil_8 added as input _demosaicked_1_stencil_8
// created const: const_p10000__1056$1 with name _1056
// umina: self.in // uminb: _1056 o: _1060 with obitwidth:16
int32_t _1061 = (int32_t)(_1060);
// renaming _1060 to _1061
// added/modified in wire_set: _1061 = _1060
int16_t _1062 = _1061 *m n261;
// created const: const_n261_n261 with name n261
// mult_middlea: _1061 // mult_middleb: n261 o: _1062 with obitwidth:16
int16_t _1063 = _1059 + _1062;
// adda: _1059 // addb: _1062 o: _1063 with obitwidth:16
[cast]uint16_t _1064 = _demosaicked_1_stencil_9 <min> _1056;
// _demosaicked_1_stencil_9 added as input _demosaicked_1_stencil_9
// created const: const_p10000__1056$2 with name _1056
// umina: self.in // uminb: _1056 o: _1064 with obitwidth:16
int32_t _1065 = (int32_t)(_1064);
// renaming _1064 to _1065
// added/modified in wire_set: _1065 = _1064
int16_t _1066 = _1065 *m 883;
// created const: const_p883_883 with name 883
// mult_middlea: _1065 // mult_middleb: 883 o: _1066 with obitwidth:16
int16_t _1067 = _1063 + _1066;
// adda: _1063 // addb: _1066 o: _1067 with obitwidth:16
int16_t _1068 = (int16_t)(-22);
int16_t _1069 = _1067 + _1068;
// created const: const_n22__1068 with name _1068
// adda: _1067 // addb: _1068 o: _1069 with obitwidth:16
[cast]// renaming _1057 to _1058
// added/modified in wire_set: _1058 = _1057
[cast]// renaming _1060 to _1061
// added/modified in wire_set: _1061 = _1060
[cast]// renaming _1064 to _1065
// added/modified in wire_set: _1065 = _1064
// connected _1069 to the output port
}

hcompute_corrected_stencil_3() {
[cast]uint16_t _1115 = (uint16_t)(10000);
uint16_t _1116 = _demosaicked_1_stencil_10 <min> _1115;
// _demosaicked_1_stencil_10 added as input _demosaicked_1_stencil_10
// created const: const_p10000__1115 with name _1115
// umina: self.in // uminb: _1115 o: _1116 with obitwidth:16
int32_t _1117 = (int32_t)(_1116);
// renaming _1116 to _1117
// added/modified in wire_set: _1117 = _1116
int16_t _1118 = _1117 *m 549;
// created const: const_p549_549$1 with name 549
// mult_middlea: _1117 // mult_middleb: 549 o: _1118 with obitwidth:16
[cast]uint16_t _1119 = _demosaicked_1_stencil_11 <min> _1115;
// _demosaicked_1_stencil_11 added as input _demosaicked_1_stencil_11
// created const: const_p10000__1115$1 with name _1115
// umina: self.in // uminb: _1115 o: _1119 with obitwidth:16
int32_t _1120 = (int32_t)(_1119);
// renaming _1119 to _1120
// added/modified in wire_set: _1120 = _1119
int16_t _1121 = _1120 *m n103;
// created const: const_n103_n103$1 with name n103
// mult_middlea: _1120 // mult_middleb: n103 o: _1121 with obitwidth:16
int16_t _1122 = _1118 + _1121;
// adda: _1118 // addb: _1121 o: _1122 with obitwidth:16
[cast]uint16_t _1123 = _demosaicked_1_stencil_12 <min> _1115;
// _demosaicked_1_stencil_12 added as input _demosaicked_1_stencil_12
// created const: const_p10000__1115$2 with name _1115
// umina: self.in // uminb: _1115 o: _1123 with obitwidth:16
int32_t _1124 = (int32_t)(_1123);
// renaming _1123 to _1124
// added/modified in wire_set: _1124 = _1123
int16_t _1125 = _1124 *m 7;
// created const: const_p7_7$1 with name 7
// mult_middlea: _1124 // mult_middleb: 7 o: _1125 with obitwidth:16
int16_t _1126 = _1122 + _1125;
// adda: _1122 // addb: _1125 o: _1126 with obitwidth:16
int16_t _1127 = (int16_t)(-40);
int16_t _1128 = _1126 + _1127;
// created const: const_n40__1127 with name _1127
// adda: _1126 // addb: _1127 o: _1128 with obitwidth:16
[cast]// renaming _1116 to _1117
// added/modified in wire_set: _1117 = _1116
[cast]// renaming _1119 to _1120
// added/modified in wire_set: _1120 = _1119
[cast]// renaming _1123 to _1124
// added/modified in wire_set: _1124 = _1123
// connected _1128 to the output port
}

hcompute_corrected_stencil_4() {
[cast]uint16_t _1175 = (uint16_t)(10000);
uint16_t _1176 = _demosaicked_1_stencil_13 <min> _1175;
// _demosaicked_1_stencil_13 added as input _demosaicked_1_stencil_13
// created const: const_p10000__1175 with name _1175
// umina: self.in // uminb: _1175 o: _1176 with obitwidth:16
int32_t _1177 = (int32_t)(_1176);
// renaming _1176 to _1177
// added/modified in wire_set: _1177 = _1176
int16_t _1178 = _1177 *m n96;
// created const: const_n96_n96$1 with name n96
// mult_middlea: _1177 // mult_middleb: n96 o: _1178 with obitwidth:16
[cast]uint16_t _1179 = _demosaicked_1_stencil_14 <min> _1175;
// _demosaicked_1_stencil_14 added as input _demosaicked_1_stencil_14
// created const: const_p10000__1175$1 with name _1175
// umina: self.in // uminb: _1175 o: _1179 with obitwidth:16
int32_t _1180 = (int32_t)(_1179);
// renaming _1179 to _1180
// added/modified in wire_set: _1180 = _1179
int16_t _1181 = _1180 *m 373;
// created const: const_p373_373$1 with name 373
// mult_middlea: _1180 // mult_middleb: 373 o: _1181 with obitwidth:16
int16_t _1182 = _1178 + _1181;
// adda: _1178 // addb: _1181 o: _1182 with obitwidth:16
[cast]uint16_t _1183 = _demosaicked_1_stencil_15 <min> _1175;
// _demosaicked_1_stencil_15 added as input _demosaicked_1_stencil_15
// created const: const_p10000__1175$2 with name _1175
// umina: self.in // uminb: _1175 o: _1183 with obitwidth:16
int32_t _1184 = (int32_t)(_1183);
// renaming _1183 to _1184
// added/modified in wire_set: _1184 = _1183
int16_t _1185 = _1184 *m 62;
// created const: const_p62_62$1 with name 62
// mult_middlea: _1184 // mult_middleb: 62 o: _1185 with obitwidth:16
int16_t _1186 = _1182 + _1185;
// adda: _1182 // addb: _1185 o: _1186 with obitwidth:16
int16_t _1187 = (int16_t)(-29);
int16_t _1188 = _1186 + _1187;
// created const: const_n29__1187 with name _1187
// adda: _1186 // addb: _1187 o: _1188 with obitwidth:16
[cast]// renaming _1176 to _1177
// added/modified in wire_set: _1177 = _1176
[cast]// renaming _1179 to _1180
// added/modified in wire_set: _1180 = _1179
[cast]// renaming _1183 to _1184
// added/modified in wire_set: _1184 = _1183
// connected _1188 to the output port
}

hcompute_corrected_stencil_5() {
[cast]uint16_t _1235 = (uint16_t)(10000);
uint16_t _1236 = _demosaicked_1_stencil_16 <min> _1235;
// _demosaicked_1_stencil_16 added as input _demosaicked_1_stencil_16
// created const: const_p10000__1235 with name _1235
// umina: self.in // uminb: _1235 o: _1236 with obitwidth:16
int32_t _1237 = (int32_t)(_1236);
// renaming _1236 to _1237
// added/modified in wire_set: _1237 = _1236
int16_t _1238 = _1237 *m n31;
// created const: const_n31_n31$1 with name n31
// mult_middlea: _1237 // mult_middleb: n31 o: _1238 with obitwidth:16
[cast]uint16_t _1239 = _demosaicked_1_stencil_17 <min> _1235;
// _demosaicked_1_stencil_17 added as input _demosaicked_1_stencil_17
// created const: const_p10000__1235$1 with name _1235
// umina: self.in // uminb: _1235 o: _1239 with obitwidth:16
int32_t _1240 = (int32_t)(_1239);
// renaming _1239 to _1240
// added/modified in wire_set: _1240 = _1239
int16_t _1241 = _1240 *m n261;
// created const: const_n261_n261$1 with name n261
// mult_middlea: _1240 // mult_middleb: n261 o: _1241 with obitwidth:16
int16_t _1242 = _1238 + _1241;
// adda: _1238 // addb: _1241 o: _1242 with obitwidth:16
[cast]uint16_t _1243 = _demosaicked_1_stencil_18 <min> _1235;
// _demosaicked_1_stencil_18 added as input _demosaicked_1_stencil_18
// created const: const_p10000__1235$2 with name _1235
// umina: self.in // uminb: _1235 o: _1243 with obitwidth:16
int32_t _1244 = (int32_t)(_1243);
// renaming _1243 to _1244
// added/modified in wire_set: _1244 = _1243
int16_t _1245 = _1244 *m 883;
// created const: const_p883_883$1 with name 883
// mult_middlea: _1244 // mult_middleb: 883 o: _1245 with obitwidth:16
int16_t _1246 = _1242 + _1245;
// adda: _1242 // addb: _1245 o: _1246 with obitwidth:16
int16_t _1247 = (int16_t)(-22);
int16_t _1248 = _1246 + _1247;
// created const: const_n22__1247 with name _1247
// adda: _1246 // addb: _1247 o: _1248 with obitwidth:16
[cast]// renaming _1236 to _1237
// added/modified in wire_set: _1237 = _1236
[cast]// renaming _1239 to _1240
// added/modified in wire_set: _1240 = _1239
[cast]// renaming _1243 to _1244
// added/modified in wire_set: _1244 = _1243
// connected _1248 to the output port
}

hcompute_corrected_stencil_6() {
[cast]uint16_t _1295 = (uint16_t)(10000);
uint16_t _1296 = _demosaicked_1_stencil_19 <min> _1295;
// _demosaicked_1_stencil_19 added as input _demosaicked_1_stencil_19
// created const: const_p10000__1295 with name _1295
// umina: self.in // uminb: _1295 o: _1296 with obitwidth:16
int32_t _1297 = (int32_t)(_1296);
// renaming _1296 to _1297
// added/modified in wire_set: _1297 = _1296
int16_t _1298 = _1297 *m 549;
// created const: const_p549_549$2 with name 549
// mult_middlea: _1297 // mult_middleb: 549 o: _1298 with obitwidth:16
[cast]uint16_t _1299 = _demosaicked_1_stencil_20 <min> _1295;
// _demosaicked_1_stencil_20 added as input _demosaicked_1_stencil_20
// created const: const_p10000__1295$1 with name _1295
// umina: self.in // uminb: _1295 o: _1299 with obitwidth:16
int32_t _1300 = (int32_t)(_1299);
// renaming _1299 to _1300
// added/modified in wire_set: _1300 = _1299
int16_t _1301 = _1300 *m n103;
// created const: const_n103_n103$2 with name n103
// mult_middlea: _1300 // mult_middleb: n103 o: _1301 with obitwidth:16
int16_t _1302 = _1298 + _1301;
// adda: _1298 // addb: _1301 o: _1302 with obitwidth:16
[cast]uint16_t _1303 = _demosaicked_1_stencil_21 <min> _1295;
// _demosaicked_1_stencil_21 added as input _demosaicked_1_stencil_21
// created const: const_p10000__1295$2 with name _1295
// umina: self.in // uminb: _1295 o: _1303 with obitwidth:16
int32_t _1304 = (int32_t)(_1303);
// renaming _1303 to _1304
// added/modified in wire_set: _1304 = _1303
int16_t _1305 = _1304 *m 7;
// created const: const_p7_7$2 with name 7
// mult_middlea: _1304 // mult_middleb: 7 o: _1305 with obitwidth:16
int16_t _1306 = _1302 + _1305;
// adda: _1302 // addb: _1305 o: _1306 with obitwidth:16
int16_t _1307 = (int16_t)(-40);
int16_t _1308 = _1306 + _1307;
// created const: const_n40__1307 with name _1307
// adda: _1306 // addb: _1307 o: _1308 with obitwidth:16
[cast]// renaming _1296 to _1297
// added/modified in wire_set: _1297 = _1296
[cast]// renaming _1299 to _1300
// added/modified in wire_set: _1300 = _1299
[cast]// renaming _1303 to _1304
// added/modified in wire_set: _1304 = _1303
// connected _1308 to the output port
}

hcompute_corrected_stencil_7() {
[cast]uint16_t _1355 = (uint16_t)(10000);
uint16_t _1356 = _demosaicked_1_stencil_22 <min> _1355;
// _demosaicked_1_stencil_22 added as input _demosaicked_1_stencil_22
// created const: const_p10000__1355 with name _1355
// umina: self.in // uminb: _1355 o: _1356 with obitwidth:16
int32_t _1357 = (int32_t)(_1356);
// renaming _1356 to _1357
// added/modified in wire_set: _1357 = _1356
int16_t _1358 = _1357 *m n96;
// created const: const_n96_n96$2 with name n96
// mult_middlea: _1357 // mult_middleb: n96 o: _1358 with obitwidth:16
[cast]uint16_t _1359 = _demosaicked_1_stencil_23 <min> _1355;
// _demosaicked_1_stencil_23 added as input _demosaicked_1_stencil_23
// created const: const_p10000__1355$1 with name _1355
// umina: self.in // uminb: _1355 o: _1359 with obitwidth:16
int32_t _1360 = (int32_t)(_1359);
// renaming _1359 to _1360
// added/modified in wire_set: _1360 = _1359
int16_t _1361 = _1360 *m 373;
// created const: const_p373_373$2 with name 373
// mult_middlea: _1360 // mult_middleb: 373 o: _1361 with obitwidth:16
int16_t _1362 = _1358 + _1361;
// adda: _1358 // addb: _1361 o: _1362 with obitwidth:16
[cast]uint16_t _1363 = _demosaicked_1_stencil_24 <min> _1355;
// _demosaicked_1_stencil_24 added as input _demosaicked_1_stencil_24
// created const: const_p10000__1355$2 with name _1355
// umina: self.in // uminb: _1355 o: _1363 with obitwidth:16
int32_t _1364 = (int32_t)(_1363);
// renaming _1363 to _1364
// added/modified in wire_set: _1364 = _1363
int16_t _1365 = _1364 *m 62;
// created const: const_p62_62$2 with name 62
// mult_middlea: _1364 // mult_middleb: 62 o: _1365 with obitwidth:16
int16_t _1366 = _1362 + _1365;
// adda: _1362 // addb: _1365 o: _1366 with obitwidth:16
int16_t _1367 = (int16_t)(-29);
int16_t _1368 = _1366 + _1367;
// created const: const_n29__1367 with name _1367
// adda: _1366 // addb: _1367 o: _1368 with obitwidth:16
[cast]// renaming _1356 to _1357
// added/modified in wire_set: _1357 = _1356
[cast]// renaming _1359 to _1360
// added/modified in wire_set: _1360 = _1359
[cast]// renaming _1363 to _1364
// added/modified in wire_set: _1364 = _1363
// connected _1368 to the output port
}

hcompute_corrected_stencil_8() {
[cast]uint16_t _1415 = (uint16_t)(10000);
uint16_t _1416 = _demosaicked_1_stencil_25 <min> _1415;
// _demosaicked_1_stencil_25 added as input _demosaicked_1_stencil_25
// created const: const_p10000__1415 with name _1415
// umina: self.in // uminb: _1415 o: _1416 with obitwidth:16
int32_t _1417 = (int32_t)(_1416);
// renaming _1416 to _1417
// added/modified in wire_set: _1417 = _1416
int16_t _1418 = _1417 *m n31;
// created const: const_n31_n31$2 with name n31
// mult_middlea: _1417 // mult_middleb: n31 o: _1418 with obitwidth:16
[cast]uint16_t _1419 = _demosaicked_1_stencil_26 <min> _1415;
// _demosaicked_1_stencil_26 added as input _demosaicked_1_stencil_26
// created const: const_p10000__1415$1 with name _1415
// umina: self.in // uminb: _1415 o: _1419 with obitwidth:16
int32_t _1420 = (int32_t)(_1419);
// renaming _1419 to _1420
// added/modified in wire_set: _1420 = _1419
int16_t _1421 = _1420 *m n261;
// created const: const_n261_n261$2 with name n261
// mult_middlea: _1420 // mult_middleb: n261 o: _1421 with obitwidth:16
int16_t _1422 = _1418 + _1421;
// adda: _1418 // addb: _1421 o: _1422 with obitwidth:16
[cast]uint16_t _1423 = _demosaicked_1_stencil_27 <min> _1415;
// _demosaicked_1_stencil_27 added as input _demosaicked_1_stencil_27
// created const: const_p10000__1415$2 with name _1415
// umina: self.in // uminb: _1415 o: _1423 with obitwidth:16
int32_t _1424 = (int32_t)(_1423);
// renaming _1423 to _1424
// added/modified in wire_set: _1424 = _1423
int16_t _1425 = _1424 *m 883;
// created const: const_p883_883$2 with name 883
// mult_middlea: _1424 // mult_middleb: 883 o: _1425 with obitwidth:16
int16_t _1426 = _1422 + _1425;
// adda: _1422 // addb: _1425 o: _1426 with obitwidth:16
int16_t _1427 = (int16_t)(-22);
int16_t _1428 = _1426 + _1427;
// created const: const_n22__1427 with name _1427
// adda: _1426 // addb: _1427 o: _1428 with obitwidth:16
[cast]// renaming _1416 to _1417
// added/modified in wire_set: _1417 = _1416
[cast]// renaming _1419 to _1420
// added/modified in wire_set: _1420 = _1419
[cast]// renaming _1423 to _1424
// added/modified in wire_set: _1424 = _1423
// connected _1428 to the output port
}

hcompute_corrected_stencil_9() {
[cast]uint16_t _1475 = (uint16_t)(10000);
uint16_t _1476 = _demosaicked_1_stencil_28 <min> _1475;
// _demosaicked_1_stencil_28 added as input _demosaicked_1_stencil_28
// created const: const_p10000__1475 with name _1475
// umina: self.in // uminb: _1475 o: _1476 with obitwidth:16
int32_t _1477 = (int32_t)(_1476);
// renaming _1476 to _1477
// added/modified in wire_set: _1477 = _1476
int16_t _1478 = _1477 *m 549;
// created const: const_p549_549$3 with name 549
// mult_middlea: _1477 // mult_middleb: 549 o: _1478 with obitwidth:16
[cast]uint16_t _1479 = _demosaicked_1_stencil_29 <min> _1475;
// _demosaicked_1_stencil_29 added as input _demosaicked_1_stencil_29
// created const: const_p10000__1475$1 with name _1475
// umina: self.in // uminb: _1475 o: _1479 with obitwidth:16
int32_t _1480 = (int32_t)(_1479);
// renaming _1479 to _1480
// added/modified in wire_set: _1480 = _1479
int16_t _1481 = _1480 *m n103;
// created const: const_n103_n103$3 with name n103
// mult_middlea: _1480 // mult_middleb: n103 o: _1481 with obitwidth:16
int16_t _1482 = _1478 + _1481;
// adda: _1478 // addb: _1481 o: _1482 with obitwidth:16
[cast]uint16_t _1483 = _demosaicked_1_stencil_30 <min> _1475;
// _demosaicked_1_stencil_30 added as input _demosaicked_1_stencil_30
// created const: const_p10000__1475$2 with name _1475
// umina: self.in // uminb: _1475 o: _1483 with obitwidth:16
int32_t _1484 = (int32_t)(_1483);
// renaming _1483 to _1484
// added/modified in wire_set: _1484 = _1483
int16_t _1485 = _1484 *m 7;
// created const: const_p7_7$3 with name 7
// mult_middlea: _1484 // mult_middleb: 7 o: _1485 with obitwidth:16
int16_t _1486 = _1482 + _1485;
// adda: _1482 // addb: _1485 o: _1486 with obitwidth:16
int16_t _1487 = (int16_t)(-40);
int16_t _1488 = _1486 + _1487;
// created const: const_n40__1487 with name _1487
// adda: _1486 // addb: _1487 o: _1488 with obitwidth:16
[cast]// renaming _1476 to _1477
// added/modified in wire_set: _1477 = _1476
[cast]// renaming _1479 to _1480
// added/modified in wire_set: _1480 = _1479
[cast]// renaming _1483 to _1484
// added/modified in wire_set: _1484 = _1483
// connected _1488 to the output port
}

hcompute_corrected_stencil_10() {
[cast]uint16_t _1536 = (uint16_t)(10000);
uint16_t _1537 = _demosaicked_1_stencil_31 <min> _1536;
// _demosaicked_1_stencil_31 added as input _demosaicked_1_stencil_31
// created const: const_p10000__1536 with name _1536
// umina: self.in // uminb: _1536 o: _1537 with obitwidth:16
int32_t _1538 = (int32_t)(_1537);
// renaming _1537 to _1538
// added/modified in wire_set: _1538 = _1537
int16_t _1539 = _1538 *m n96;
// created const: const_n96_n96$3 with name n96
// mult_middlea: _1538 // mult_middleb: n96 o: _1539 with obitwidth:16
[cast]uint16_t _1540 = _demosaicked_1_stencil_32 <min> _1536;
// _demosaicked_1_stencil_32 added as input _demosaicked_1_stencil_32
// created const: const_p10000__1536$1 with name _1536
// umina: self.in // uminb: _1536 o: _1540 with obitwidth:16
int32_t _1541 = (int32_t)(_1540);
// renaming _1540 to _1541
// added/modified in wire_set: _1541 = _1540
int16_t _1542 = _1541 *m 373;
// created const: const_p373_373$3 with name 373
// mult_middlea: _1541 // mult_middleb: 373 o: _1542 with obitwidth:16
int16_t _1543 = _1539 + _1542;
// adda: _1539 // addb: _1542 o: _1543 with obitwidth:16
[cast]uint16_t _1544 = _demosaicked_1_stencil_33 <min> _1536;
// _demosaicked_1_stencil_33 added as input _demosaicked_1_stencil_33
// created const: const_p10000__1536$2 with name _1536
// umina: self.in // uminb: _1536 o: _1544 with obitwidth:16
int32_t _1545 = (int32_t)(_1544);
// renaming _1544 to _1545
// added/modified in wire_set: _1545 = _1544
int16_t _1546 = _1545 *m 62;
// created const: const_p62_62$3 with name 62
// mult_middlea: _1545 // mult_middleb: 62 o: _1546 with obitwidth:16
int16_t _1547 = _1543 + _1546;
// adda: _1543 // addb: _1546 o: _1547 with obitwidth:16
int16_t _1548 = (int16_t)(-29);
int16_t _1549 = _1547 + _1548;
// created const: const_n29__1548 with name _1548
// adda: _1547 // addb: _1548 o: _1549 with obitwidth:16
[cast]// renaming _1537 to _1538
// added/modified in wire_set: _1538 = _1537
[cast]// renaming _1540 to _1541
// added/modified in wire_set: _1541 = _1540
[cast]// renaming _1544 to _1545
// added/modified in wire_set: _1545 = _1544
// connected _1549 to the output port
}

hcompute_corrected_stencil_11() {
[cast]uint16_t _1597 = (uint16_t)(10000);
uint16_t _1598 = _demosaicked_1_stencil_34 <min> _1597;
// _demosaicked_1_stencil_34 added as input _demosaicked_1_stencil_34
// created const: const_p10000__1597 with name _1597
// umina: self.in // uminb: _1597 o: _1598 with obitwidth:16
int32_t _1599 = (int32_t)(_1598);
// renaming _1598 to _1599
// added/modified in wire_set: _1599 = _1598
int16_t _1600 = _1599 *m n31;
// created const: const_n31_n31$3 with name n31
// mult_middlea: _1599 // mult_middleb: n31 o: _1600 with obitwidth:16
[cast]uint16_t _1601 = _demosaicked_1_stencil_35 <min> _1597;
// _demosaicked_1_stencil_35 added as input _demosaicked_1_stencil_35
// created const: const_p10000__1597$1 with name _1597
// umina: self.in // uminb: _1597 o: _1601 with obitwidth:16
int32_t _1602 = (int32_t)(_1601);
// renaming _1601 to _1602
// added/modified in wire_set: _1602 = _1601
int16_t _1603 = _1602 *m n261;
// created const: const_n261_n261$3 with name n261
// mult_middlea: _1602 // mult_middleb: n261 o: _1603 with obitwidth:16
int16_t _1604 = _1600 + _1603;
// adda: _1600 // addb: _1603 o: _1604 with obitwidth:16
[cast]uint16_t _1605 = _demosaicked_1_stencil_36 <min> _1597;
// _demosaicked_1_stencil_36 added as input _demosaicked_1_stencil_36
// created const: const_p10000__1597$2 with name _1597
// umina: self.in // uminb: _1597 o: _1605 with obitwidth:16
int32_t _1606 = (int32_t)(_1605);
// renaming _1605 to _1606
// added/modified in wire_set: _1606 = _1605
int16_t _1607 = _1606 *m 883;
// created const: const_p883_883$3 with name 883
// mult_middlea: _1606 // mult_middleb: 883 o: _1607 with obitwidth:16
int16_t _1608 = _1604 + _1607;
// adda: _1604 // addb: _1607 o: _1608 with obitwidth:16
int16_t _1609 = (int16_t)(-22);
int16_t _1610 = _1608 + _1609;
// created const: const_n22__1609 with name _1609
// adda: _1608 // addb: _1609 o: _1610 with obitwidth:16
[cast]// renaming _1598 to _1599
// added/modified in wire_set: _1599 = _1598
[cast]// renaming _1601 to _1602
// added/modified in wire_set: _1602 = _1601
[cast]// renaming _1605 to _1606
// added/modified in wire_set: _1606 = _1605
// connected _1610 to the output port
}

hcompute_curved_stencil() {
// adding coreir inst curvea0
[cast]int16_t _3693 = (int16_t)(1023);
int16_t _3694 = _corrected_stencil_1 <smin> _3693;
// _corrected_stencil_1 added as input _corrected_stencil_1
// created const: const_p1023__3693 with name _3693
// smina: self.in // sminb: _3693 o: _3694 with obitwidth:16
int16_t _3695 = (int16_t)(0);
int16_t _3696 = _3694 <smax> _3695;
// created const: const_p0__3695 with name _3695
// smaxa: _3694 // smaxb: _3695 o: _3696 with obitwidth:16
uint16_t _3697 = (uint16_t)(_3696);
// renaming _3696 to _3697
// added/modified in wire_set: _3697 = _3696
uint16_t _3698 = ((uint16_t *)_curvea0)[_3697][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0
[cast]// renaming _3696 to _3697
// added/modified in wire_set: _3697 = _3696
// loading from rom curvea0 with gen memory.rom2
// connected _3698 to the output port
}

hcompute_curved_stencil_1() {
// adding coreir inst curvea0
[cast]int16_t _4740 = (int16_t)(1023);
int16_t _4741 = _corrected_stencil_2 <smin> _4740;
// _corrected_stencil_2 added as input _corrected_stencil_2
// created const: const_p1023__4740 with name _4740
// smina: self.in // sminb: _4740 o: _4741 with obitwidth:16
int16_t _4742 = (int16_t)(0);
int16_t _4743 = _4741 <smax> _4742;
// created const: const_p0__4742 with name _4742
// smaxa: _4741 // smaxb: _4742 o: _4743 with obitwidth:16
uint16_t _4744 = (uint16_t)(_4743);
// renaming _4743 to _4744
// added/modified in wire_set: _4744 = _4743
uint16_t _4745 = ((uint16_t *)_curvea0)[_4744][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$1
[cast]// renaming _4743 to _4744
// added/modified in wire_set: _4744 = _4743
// loading from rom curvea0 with gen memory.rom2
// connected _4745 to the output port
}

hcompute_curved_stencil_2() {
// adding coreir inst curvea0
[cast]int16_t _5787 = (int16_t)(1023);
int16_t _5788 = _corrected_stencil_3 <smin> _5787;
// _corrected_stencil_3 added as input _corrected_stencil_3
// created const: const_p1023__5787 with name _5787
// smina: self.in // sminb: _5787 o: _5788 with obitwidth:16
int16_t _5789 = (int16_t)(0);
int16_t _5790 = _5788 <smax> _5789;
// created const: const_p0__5789 with name _5789
// smaxa: _5788 // smaxb: _5789 o: _5790 with obitwidth:16
uint16_t _5791 = (uint16_t)(_5790);
// renaming _5790 to _5791
// added/modified in wire_set: _5791 = _5790
uint16_t _5792 = ((uint16_t *)_curvea0)[_5791][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$2
[cast]// renaming _5790 to _5791
// added/modified in wire_set: _5791 = _5790
// loading from rom curvea0 with gen memory.rom2
// connected _5792 to the output port
}

hcompute_curved_stencil_3() {
// adding coreir inst curvea0
[cast]int16_t _6834 = (int16_t)(1023);
int16_t _6835 = _corrected_stencil_4 <smin> _6834;
// _corrected_stencil_4 added as input _corrected_stencil_4
// created const: const_p1023__6834 with name _6834
// smina: self.in // sminb: _6834 o: _6835 with obitwidth:16
int16_t _6836 = (int16_t)(0);
int16_t _6837 = _6835 <smax> _6836;
// created const: const_p0__6836 with name _6836
// smaxa: _6835 // smaxb: _6836 o: _6837 with obitwidth:16
uint16_t _6838 = (uint16_t)(_6837);
// renaming _6837 to _6838
// added/modified in wire_set: _6838 = _6837
uint16_t _6839 = ((uint16_t *)_curvea0)[_6838][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$3
[cast]// renaming _6837 to _6838
// added/modified in wire_set: _6838 = _6837
// loading from rom curvea0 with gen memory.rom2
// connected _6839 to the output port
}

hcompute_curved_stencil_4() {
// adding coreir inst curvea0
[cast]int16_t _7882 = (int16_t)(1023);
int16_t _7883 = _corrected_stencil_5 <smin> _7882;
// _corrected_stencil_5 added as input _corrected_stencil_5
// created const: const_p1023__7882 with name _7882
// smina: self.in // sminb: _7882 o: _7883 with obitwidth:16
int16_t _7884 = (int16_t)(0);
int16_t _7885 = _7883 <smax> _7884;
// created const: const_p0__7884 with name _7884
// smaxa: _7883 // smaxb: _7884 o: _7885 with obitwidth:16
uint16_t _7886 = (uint16_t)(_7885);
// renaming _7885 to _7886
// added/modified in wire_set: _7886 = _7885
uint16_t _7887 = ((uint16_t *)_curvea0)[_7886][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$4
[cast]// renaming _7885 to _7886
// added/modified in wire_set: _7886 = _7885
// loading from rom curvea0 with gen memory.rom2
// connected _7887 to the output port
}

hcompute_curved_stencil_5() {
// adding coreir inst curvea0
[cast]int16_t _8930 = (int16_t)(1023);
int16_t _8931 = _corrected_stencil_6 <smin> _8930;
// _corrected_stencil_6 added as input _corrected_stencil_6
// created const: const_p1023__8930 with name _8930
// smina: self.in // sminb: _8930 o: _8931 with obitwidth:16
int16_t _8932 = (int16_t)(0);
int16_t _8933 = _8931 <smax> _8932;
// created const: const_p0__8932 with name _8932
// smaxa: _8931 // smaxb: _8932 o: _8933 with obitwidth:16
uint16_t _8934 = (uint16_t)(_8933);
// renaming _8933 to _8934
// added/modified in wire_set: _8934 = _8933
uint16_t _8935 = ((uint16_t *)_curvea0)[_8934][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$5
[cast]// renaming _8933 to _8934
// added/modified in wire_set: _8934 = _8933
// loading from rom curvea0 with gen memory.rom2
// connected _8935 to the output port
}

hcompute_curved_stencil_6() {
// adding coreir inst curvea0
[cast]int16_t _9978 = (int16_t)(1023);
int16_t _9979 = _corrected_stencil_7 <smin> _9978;
// _corrected_stencil_7 added as input _corrected_stencil_7
// created const: const_p1023__9978 with name _9978
// smina: self.in // sminb: _9978 o: _9979 with obitwidth:16
int16_t _9980 = (int16_t)(0);
int16_t _9981 = _9979 <smax> _9980;
// created const: const_p0__9980 with name _9980
// smaxa: _9979 // smaxb: _9980 o: _9981 with obitwidth:16
uint16_t _9982 = (uint16_t)(_9981);
// renaming _9981 to _9982
// added/modified in wire_set: _9982 = _9981
uint16_t _9983 = ((uint16_t *)_curvea0)[_9982][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$6
[cast]// renaming _9981 to _9982
// added/modified in wire_set: _9982 = _9981
// loading from rom curvea0 with gen memory.rom2
// connected _9983 to the output port
}

hcompute_curved_stencil_7() {
// adding coreir inst curvea0
[cast]int16_t _11026 = (int16_t)(1023);
int16_t _11027 = _corrected_stencil_8 <smin> _11026;
// _corrected_stencil_8 added as input _corrected_stencil_8
// created const: const_p1023__11026 with name _11026
// smina: self.in // sminb: _11026 o: _11027 with obitwidth:16
int16_t _11028 = (int16_t)(0);
int16_t _11029 = _11027 <smax> _11028;
// created const: const_p0__11028 with name _11028
// smaxa: _11027 // smaxb: _11028 o: _11029 with obitwidth:16
uint16_t _11030 = (uint16_t)(_11029);
// renaming _11029 to _11030
// added/modified in wire_set: _11030 = _11029
uint16_t _11031 = ((uint16_t *)_curvea0)[_11030][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$7
[cast]// renaming _11029 to _11030
// added/modified in wire_set: _11030 = _11029
// loading from rom curvea0 with gen memory.rom2
// connected _11031 to the output port
}

hcompute_curved_stencil_8() {
// adding coreir inst curvea0
[cast]int16_t _12074 = (int16_t)(1023);
int16_t _12075 = _corrected_stencil_9 <smin> _12074;
// _corrected_stencil_9 added as input _corrected_stencil_9
// created const: const_p1023__12074 with name _12074
// smina: self.in // sminb: _12074 o: _12075 with obitwidth:16
int16_t _12076 = (int16_t)(0);
int16_t _12077 = _12075 <smax> _12076;
// created const: const_p0__12076 with name _12076
// smaxa: _12075 // smaxb: _12076 o: _12077 with obitwidth:16
uint16_t _12078 = (uint16_t)(_12077);
// renaming _12077 to _12078
// added/modified in wire_set: _12078 = _12077
uint16_t _12079 = ((uint16_t *)_curvea0)[_12078][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$8
[cast]// renaming _12077 to _12078
// added/modified in wire_set: _12078 = _12077
// loading from rom curvea0 with gen memory.rom2
// connected _12079 to the output port
}

hcompute_curved_stencil_9() {
// adding coreir inst curvea0
[cast]int16_t _13122 = (int16_t)(1023);
int16_t _13123 = _corrected_stencil_10 <smin> _13122;
// _corrected_stencil_10 added as input _corrected_stencil_10
// created const: const_p1023__13122 with name _13122
// smina: self.in // sminb: _13122 o: _13123 with obitwidth:16
int16_t _13124 = (int16_t)(0);
int16_t _13125 = _13123 <smax> _13124;
// created const: const_p0__13124 with name _13124
// smaxa: _13123 // smaxb: _13124 o: _13125 with obitwidth:16
uint16_t _13126 = (uint16_t)(_13125);
// renaming _13125 to _13126
// added/modified in wire_set: _13126 = _13125
uint16_t _13127 = ((uint16_t *)_curvea0)[_13126][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$9
[cast]// renaming _13125 to _13126
// added/modified in wire_set: _13126 = _13125
// loading from rom curvea0 with gen memory.rom2
// connected _13127 to the output port
}

hcompute_curved_stencil_10() {
// adding coreir inst curvea0
[cast]int16_t _14171 = (int16_t)(1023);
int16_t _14172 = _corrected_stencil_11 <smin> _14171;
// _corrected_stencil_11 added as input _corrected_stencil_11
// created const: const_p1023__14171 with name _14171
// smina: self.in // sminb: _14171 o: _14172 with obitwidth:16
int16_t _14173 = (int16_t)(0);
int16_t _14174 = _14172 <smax> _14173;
// created const: const_p0__14173 with name _14173
// smaxa: _14172 // smaxb: _14173 o: _14174 with obitwidth:16
uint16_t _14175 = (uint16_t)(_14174);
// renaming _14174 to _14175
// added/modified in wire_set: _14175 = _14174
uint16_t _14176 = ((uint16_t *)_curvea0)[_14175][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$10
[cast]// renaming _14174 to _14175
// added/modified in wire_set: _14175 = _14174
// loading from rom curvea0 with gen memory.rom2
// connected _14176 to the output port
}

hcompute_curved_stencil_11() {
// adding coreir inst curvea0
[cast]int16_t _15220 = (int16_t)(1023);
int16_t _15221 = _corrected_stencil_12 <smin> _15220;
// _corrected_stencil_12 added as input _corrected_stencil_12
// created const: const_p1023__15220 with name _15220
// smina: self.in // sminb: _15220 o: _15221 with obitwidth:16
int16_t _15222 = (int16_t)(0);
int16_t _15223 = _15221 <smax> _15222;
// created const: const_p0__15222 with name _15222
// smaxa: _15221 // smaxb: _15222 o: _15223 with obitwidth:16
uint16_t _15224 = (uint16_t)(_15223);
// renaming _15223 to _15224
// added/modified in wire_set: _15224 = _15223
uint16_t _15225 = ((uint16_t *)_curvea0)[_15224][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$11
[cast]// renaming _15223 to _15224
// added/modified in wire_set: _15224 = _15223
// loading from rom curvea0 with gen memory.rom2
// connected _15225 to the output port
}

hcompute_hw_output_glb_stencil() {
// _curved_stencil_1 added as input _curved_stencil_1
// connected _curved_stencil_1 to the output port
}

hcompute_hw_output_glb_stencil_1() {
// _curved_stencil_2 added as input _curved_stencil_2
// connected _curved_stencil_2 to the output port
}

hcompute_hw_output_glb_stencil_2() {
// _curved_stencil_3 added as input _curved_stencil_3
// connected _curved_stencil_3 to the output port
}

hcompute_hw_output_glb_stencil_3() {
// _curved_stencil_4 added as input _curved_stencil_4
// connected _curved_stencil_4 to the output port
}

hcompute_hw_output_glb_stencil_4() {
// _curved_stencil_5 added as input _curved_stencil_5
// connected _curved_stencil_5 to the output port
}

hcompute_hw_output_glb_stencil_5() {
// _curved_stencil_6 added as input _curved_stencil_6
// connected _curved_stencil_6 to the output port
}

hcompute_hw_output_glb_stencil_6() {
// _curved_stencil_7 added as input _curved_stencil_7
// connected _curved_stencil_7 to the output port
}

hcompute_hw_output_glb_stencil_7() {
// _curved_stencil_8 added as input _curved_stencil_8
// connected _curved_stencil_8 to the output port
}

hcompute_hw_output_glb_stencil_8() {
// _curved_stencil_9 added as input _curved_stencil_9
// connected _curved_stencil_9 to the output port
}

hcompute_hw_output_glb_stencil_9() {
// _curved_stencil_10 added as input _curved_stencil_10
// connected _curved_stencil_10 to the output port
}

hcompute_hw_output_glb_stencil_10() {
// _curved_stencil_11 added as input _curved_stencil_11
// connected _curved_stencil_11 to the output port
}

hcompute_hw_output_glb_stencil_11() {
// _curved_stencil_12 added as input _curved_stencil_12
// connected _curved_stencil_12 to the output port
}

hcompute_hw_output_global_wrapper_stencil() {
// _hw_output_glb_stencil_1 added as input _hw_output_glb_stencil_1
// connected _hw_output_glb_stencil_1 to the output port
}

hcompute_hw_output_global_wrapper_stencil_1() {
// _hw_output_glb_stencil_2 added as input _hw_output_glb_stencil_2
// connected _hw_output_glb_stencil_2 to the output port
}

hcompute_hw_output_global_wrapper_stencil_2() {
// _hw_output_glb_stencil_3 added as input _hw_output_glb_stencil_3
// connected _hw_output_glb_stencil_3 to the output port
}

hcompute_hw_output_global_wrapper_stencil_3() {
// _hw_output_glb_stencil_4 added as input _hw_output_glb_stencil_4
// connected _hw_output_glb_stencil_4 to the output port
}

hcompute_hw_output_global_wrapper_stencil_4() {
// _hw_output_glb_stencil_5 added as input _hw_output_glb_stencil_5
// connected _hw_output_glb_stencil_5 to the output port
}

hcompute_hw_output_global_wrapper_stencil_5() {
// _hw_output_glb_stencil_6 added as input _hw_output_glb_stencil_6
// connected _hw_output_glb_stencil_6 to the output port
}

hcompute_hw_output_global_wrapper_stencil_6() {
// _hw_output_glb_stencil_7 added as input _hw_output_glb_stencil_7
// connected _hw_output_glb_stencil_7 to the output port
}

hcompute_hw_output_global_wrapper_stencil_7() {
// _hw_output_glb_stencil_8 added as input _hw_output_glb_stencil_8
// connected _hw_output_glb_stencil_8 to the output port
}

hcompute_hw_output_global_wrapper_stencil_8() {
// _hw_output_glb_stencil_9 added as input _hw_output_glb_stencil_9
// connected _hw_output_glb_stencil_9 to the output port
}

hcompute_hw_output_global_wrapper_stencil_9() {
// _hw_output_glb_stencil_10 added as input _hw_output_glb_stencil_10
// connected _hw_output_glb_stencil_10 to the output port
}

hcompute_hw_output_global_wrapper_stencil_10() {
// _hw_output_glb_stencil_11 added as input _hw_output_glb_stencil_11
// connected _hw_output_glb_stencil_11 to the output port
}

hcompute_hw_output_global_wrapper_stencil_11() {
// _hw_output_glb_stencil_12 added as input _hw_output_glb_stencil_12
// connected _hw_output_glb_stencil_12 to the output port
}

