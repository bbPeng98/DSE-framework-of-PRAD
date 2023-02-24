hcompute_hw_input_global_wrapper_glb_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_glb_stencil_1() {
// _hw_input_stencil_2 added as input _hw_input_stencil_2
// connected _hw_input_stencil_2 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil() {
// _hw_input_global_wrapper_glb_stencil_1 added as input _hw_input_global_wrapper_glb_stencil_1
// connected _hw_input_global_wrapper_glb_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil_1() {
// _hw_input_global_wrapper_glb_stencil_2 added as input _hw_input_global_wrapper_glb_stencil_2
// connected _hw_input_global_wrapper_glb_stencil_2 to the output port
}

hcompute_denoised_1_stencil() {
uint16_t _355 = _hw_input_global_wrapper_global_wrapper_stencil_4 <max> _hw_input_global_wrapper_global_wrapper_stencil_5;
// _hw_input_global_wrapper_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_global_wrapper_stencil_4
// _hw_input_global_wrapper_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_global_wrapper_stencil_5
// umaxa: self.in // umaxb: self.in o: _355 with obitwidth:16
uint16_t _356 = _hw_input_global_wrapper_global_wrapper_stencil_3 <max> _355;
// _hw_input_global_wrapper_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_global_wrapper_stencil_3
// umaxa: self.in // umaxb: _355 o: _356 with obitwidth:16
uint16_t _357 = _hw_input_global_wrapper_global_wrapper_stencil_2 <max> _356;
// _hw_input_global_wrapper_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_global_wrapper_stencil_2
// umaxa: self.in // umaxb: _356 o: _357 with obitwidth:16
uint16_t _358 = _hw_input_global_wrapper_global_wrapper_stencil_1 <min> _357;
// _hw_input_global_wrapper_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_global_wrapper_stencil_1
// umina: self.in // uminb: _357 o: _358 with obitwidth:16
// connected _358 to the output port
}

hcompute_denoised_1_stencil_1() {
uint16_t _379 = _hw_input_global_wrapper_global_wrapper_stencil_9 <max> _hw_input_global_wrapper_global_wrapper_stencil_10;
// _hw_input_global_wrapper_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_global_wrapper_stencil_9
// _hw_input_global_wrapper_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_global_wrapper_stencil_10
// umaxa: self.in // umaxb: self.in o: _379 with obitwidth:16
uint16_t _380 = _hw_input_global_wrapper_global_wrapper_stencil_8 <max> _379;
// _hw_input_global_wrapper_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_global_wrapper_stencil_8
// umaxa: self.in // umaxb: _379 o: _380 with obitwidth:16
uint16_t _381 = _hw_input_global_wrapper_global_wrapper_stencil_7 <max> _380;
// _hw_input_global_wrapper_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_global_wrapper_stencil_7
// umaxa: self.in // umaxb: _380 o: _381 with obitwidth:16
uint16_t _382 = _hw_input_global_wrapper_global_wrapper_stencil_6 <min> _381;
// _hw_input_global_wrapper_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_global_wrapper_stencil_6
// umina: self.in // uminb: _381 o: _382 with obitwidth:16
// connected _382 to the output port
}

hcompute_g_b_stencil() {
[absd] uint16_t _419 = _denoised_1_stencil_1 |-| _denoised_1_stencil_2;
// _denoised_1_stencil_1 added as input _denoised_1_stencil_1
// _denoised_1_stencil_2 added as input _denoised_1_stencil_2
// absda: self.in // absdb: self.in o: _419 with obitwidth:16
[absd] uint16_t _420 = _denoised_1_stencil_3 |-| _denoised_1_stencil_4;
// _denoised_1_stencil_3 added as input _denoised_1_stencil_3
// _denoised_1_stencil_4 added as input _denoised_1_stencil_4
// absda: self.in // absdb: self.in o: _420 with obitwidth:16
bool _421 = _419 < _420;
// ulta: _419 // ultb: _420 o: _421 with obitwidth:1
uint16_t _422 = _denoised_1_stencil_1 + _denoised_1_stencil_2;
// _denoised_1_stencil_1 added as input _denoised_1_stencil_1
// _denoised_1_stencil_2 added as input _denoised_1_stencil_2
// adda: self.in // addb: self.in o: _422 with obitwidth:16
uint16_t _423 = (uint16_t)(1);
uint16_t _424 = _422 >> _423;
// created const: const_p1__423 with name _423
// lshra: _422 // lshrb: _423 o: _424 with obitwidth:16
uint16_t _425 = _denoised_1_stencil_3 + _denoised_1_stencil_4;
// _denoised_1_stencil_3 added as input _denoised_1_stencil_3
// _denoised_1_stencil_4 added as input _denoised_1_stencil_4
// adda: self.in // addb: self.in o: _425 with obitwidth:16
uint16_t _426 = _425 >> _423;
// created const: const_p1__423$1 with name _423
// lshra: _425 // lshrb: _423 o: _426 with obitwidth:16
uint16_t _427 = _421 ? _424 : _426;
// muxa: _421 // muxb: _424 // muxc: _426 o: _427
[absd] [absd] // connected _427 to the output port
}

hcompute_b_gb_stencil() {
uint16_t _467 = _denoised_1_stencil_6 + _denoised_1_stencil_7;
// _denoised_1_stencil_6 added as input _denoised_1_stencil_6
// _denoised_1_stencil_7 added as input _denoised_1_stencil_7
// adda: self.in // addb: self.in o: _467 with obitwidth:16
uint16_t _468 = (uint16_t)(1);
uint16_t _469 = _467 >> _468;
// created const: const_p1__468 with name _468
// lshra: _467 // lshrb: _468 o: _469 with obitwidth:16
uint16_t _470 = _denoised_1_stencil_5 + _469;
// _denoised_1_stencil_5 added as input _denoised_1_stencil_5
// adda: self.in // addb: _469 o: _470 with obitwidth:16
uint16_t _471 = _g_b_stencil_1 + _g_b_stencil_2;
// _g_b_stencil_1 added as input _g_b_stencil_1
// _g_b_stencil_2 added as input _g_b_stencil_2
// adda: self.in // addb: self.in o: _471 with obitwidth:16
uint16_t _472 = _471 >> _468;
// created const: const_p1__468$1 with name _468
// lshra: _471 // lshrb: _468 o: _472 with obitwidth:16
uint16_t _473 = _470 - _472;
// suba: _470 // subb: _472 o: _473 with obitwidth:16
// connected _473 to the output port
}

hcompute_b_gr_stencil() {
uint16_t _502 = _denoised_1_stencil_9 + _denoised_1_stencil_10;
// _denoised_1_stencil_9 added as input _denoised_1_stencil_9
// _denoised_1_stencil_10 added as input _denoised_1_stencil_10
// adda: self.in // addb: self.in o: _502 with obitwidth:16
uint16_t _503 = (uint16_t)(1);
uint16_t _504 = _502 >> _503;
// created const: const_p1__503 with name _503
// lshra: _502 // lshrb: _503 o: _504 with obitwidth:16
uint16_t _505 = _denoised_1_stencil_8 + _504;
// _denoised_1_stencil_8 added as input _denoised_1_stencil_8
// adda: self.in // addb: _504 o: _505 with obitwidth:16
uint16_t _506 = _g_b_stencil_3 + _g_b_stencil_4;
// _g_b_stencil_3 added as input _g_b_stencil_3
// _g_b_stencil_4 added as input _g_b_stencil_4
// adda: self.in // addb: self.in o: _506 with obitwidth:16
uint16_t _507 = _506 >> _503;
// created const: const_p1__503$1 with name _503
// lshra: _506 // lshrb: _503 o: _507 with obitwidth:16
uint16_t _508 = _505 - _507;
// suba: _505 // subb: _507 o: _508 with obitwidth:16
// connected _508 to the output port
}

hcompute_g_r_stencil() {
[absd] uint16_t _547 = _denoised_1_stencil_11 |-| _denoised_1_stencil_12;
// _denoised_1_stencil_11 added as input _denoised_1_stencil_11
// _denoised_1_stencil_12 added as input _denoised_1_stencil_12
// absda: self.in // absdb: self.in o: _547 with obitwidth:16
[absd] uint16_t _548 = _denoised_1_stencil_13 |-| _denoised_1_stencil_14;
// _denoised_1_stencil_13 added as input _denoised_1_stencil_13
// _denoised_1_stencil_14 added as input _denoised_1_stencil_14
// absda: self.in // absdb: self.in o: _548 with obitwidth:16
bool _549 = _547 < _548;
// ulta: _547 // ultb: _548 o: _549 with obitwidth:1
uint16_t _550 = _denoised_1_stencil_11 + _denoised_1_stencil_12;
// _denoised_1_stencil_11 added as input _denoised_1_stencil_11
// _denoised_1_stencil_12 added as input _denoised_1_stencil_12
// adda: self.in // addb: self.in o: _550 with obitwidth:16
uint16_t _551 = (uint16_t)(1);
uint16_t _552 = _550 >> _551;
// created const: const_p1__551 with name _551
// lshra: _550 // lshrb: _551 o: _552 with obitwidth:16
uint16_t _553 = _denoised_1_stencil_13 + _denoised_1_stencil_14;
// _denoised_1_stencil_13 added as input _denoised_1_stencil_13
// _denoised_1_stencil_14 added as input _denoised_1_stencil_14
// adda: self.in // addb: self.in o: _553 with obitwidth:16
uint16_t _554 = _553 >> _551;
// created const: const_p1__551$1 with name _551
// lshra: _553 // lshrb: _551 o: _554 with obitwidth:16
uint16_t _555 = _549 ? _552 : _554;
// muxa: _549 // muxb: _552 // muxc: _554 o: _555
[absd] [absd] // connected _555 to the output port
}

hcompute_r_gb_stencil() {
uint16_t _595 = _denoised_1_stencil_16 + _denoised_1_stencil_17;
// _denoised_1_stencil_16 added as input _denoised_1_stencil_16
// _denoised_1_stencil_17 added as input _denoised_1_stencil_17
// adda: self.in // addb: self.in o: _595 with obitwidth:16
uint16_t _596 = (uint16_t)(1);
uint16_t _597 = _595 >> _596;
// created const: const_p1__596 with name _596
// lshra: _595 // lshrb: _596 o: _597 with obitwidth:16
uint16_t _598 = _denoised_1_stencil_15 + _597;
// _denoised_1_stencil_15 added as input _denoised_1_stencil_15
// adda: self.in // addb: _597 o: _598 with obitwidth:16
uint16_t _599 = _g_r_stencil_1 + _g_r_stencil_2;
// _g_r_stencil_1 added as input _g_r_stencil_1
// _g_r_stencil_2 added as input _g_r_stencil_2
// adda: self.in // addb: self.in o: _599 with obitwidth:16
uint16_t _600 = _599 >> _596;
// created const: const_p1__596$1 with name _596
// lshra: _599 // lshrb: _596 o: _600 with obitwidth:16
uint16_t _601 = _598 - _600;
// suba: _598 // subb: _600 o: _601 with obitwidth:16
// connected _601 to the output port
}

hcompute_r_gr_stencil() {
uint16_t _630 = _denoised_1_stencil_19 + _denoised_1_stencil_20;
// _denoised_1_stencil_19 added as input _denoised_1_stencil_19
// _denoised_1_stencil_20 added as input _denoised_1_stencil_20
// adda: self.in // addb: self.in o: _630 with obitwidth:16
uint16_t _631 = (uint16_t)(1);
uint16_t _632 = _630 >> _631;
// created const: const_p1__631 with name _631
// lshra: _630 // lshrb: _631 o: _632 with obitwidth:16
uint16_t _633 = _denoised_1_stencil_18 + _632;
// _denoised_1_stencil_18 added as input _denoised_1_stencil_18
// adda: self.in // addb: _632 o: _633 with obitwidth:16
uint16_t _634 = _g_r_stencil_3 + _g_r_stencil_4;
// _g_r_stencil_3 added as input _g_r_stencil_3
// _g_r_stencil_4 added as input _g_r_stencil_4
// adda: self.in // addb: self.in o: _634 with obitwidth:16
uint16_t _635 = _634 >> _631;
// created const: const_p1__631$1 with name _631
// lshra: _634 // lshrb: _631 o: _635 with obitwidth:16
uint16_t _636 = _633 - _635;
// suba: _633 // subb: _635 o: _636 with obitwidth:16
// connected _636 to the output port
}

hcompute_demosaicked_1_stencil() {
uint32_t _684 = (uint32_t)(1);
int32_t _685 = _demosaicked_1_s0_y & _684;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__684 with name _684
// anda: self.in // andb: _684 o: _685 with obitwidth:32
bool _686 = _685 == 0;
// created const: const_p0_0 with name 0
// eqa: _685 // eqb: 0 o: _686 with obitwidth:1
[absd] uint16_t _687 = _denoised_1_stencil_21 |-| _denoised_1_stencil_22;
// _denoised_1_stencil_21 added as input _denoised_1_stencil_21
// _denoised_1_stencil_22 added as input _denoised_1_stencil_22
// absda: self.in // absdb: self.in o: _687 with obitwidth:16
[absd] uint16_t _688 = _denoised_1_stencil_23 |-| _denoised_1_stencil_24;
// _denoised_1_stencil_23 added as input _denoised_1_stencil_23
// _denoised_1_stencil_24 added as input _denoised_1_stencil_24
// absda: self.in // absdb: self.in o: _688 with obitwidth:16
bool _689 = _687 < _688;
// ulta: _687 // ultb: _688 o: _689 with obitwidth:1
uint16_t _690 = _denoised_1_stencil_21 + _denoised_1_stencil_22;
// _denoised_1_stencil_21 added as input _denoised_1_stencil_21
// _denoised_1_stencil_22 added as input _denoised_1_stencil_22
// adda: self.in // addb: self.in o: _690 with obitwidth:16
uint16_t _691 = (uint16_t)(1);
uint16_t _692 = _690 >> _691;
// created const: const_p1__691 with name _691
// lshra: _690 // lshrb: _691 o: _692 with obitwidth:16
uint16_t _693 = _g_b_stencil_5 + _692;
// _g_b_stencil_5 added as input _g_b_stencil_5
// adda: self.in // addb: _692 o: _693 with obitwidth:16
uint16_t _694 = _g_r_stencil_5 + _g_r_stencil_6;
// _g_r_stencil_5 added as input _g_r_stencil_5
// _g_r_stencil_6 added as input _g_r_stencil_6
// adda: self.in // addb: self.in o: _694 with obitwidth:16
uint16_t _695 = _694 >> _691;
// created const: const_p1__691$1 with name _691
// lshra: _694 // lshrb: _691 o: _695 with obitwidth:16
uint16_t _696 = _693 - _695;
// suba: _693 // subb: _695 o: _696 with obitwidth:16
uint16_t _697 = _denoised_1_stencil_23 + _denoised_1_stencil_24;
// _denoised_1_stencil_23 added as input _denoised_1_stencil_23
// _denoised_1_stencil_24 added as input _denoised_1_stencil_24
// adda: self.in // addb: self.in o: _697 with obitwidth:16
uint16_t _698 = _697 >> _691;
// created const: const_p1__691$2 with name _691
// lshra: _697 // lshrb: _691 o: _698 with obitwidth:16
uint16_t _699 = _g_b_stencil_5 + _698;
// _g_b_stencil_5 added as input _g_b_stencil_5
// adda: self.in // addb: _698 o: _699 with obitwidth:16
uint16_t _700 = _g_r_stencil_7 + _g_r_stencil_8;
// _g_r_stencil_7 added as input _g_r_stencil_7
// _g_r_stencil_8 added as input _g_r_stencil_8
// adda: self.in // addb: self.in o: _700 with obitwidth:16
uint16_t _701 = _700 >> _691;
// created const: const_p1__691$3 with name _691
// lshra: _700 // lshrb: _691 o: _701 with obitwidth:16
uint16_t _702 = _699 - _701;
// suba: _699 // subb: _701 o: _702 with obitwidth:16
uint16_t _703 = _689 ? _696 : _702;
// muxa: _689 // muxb: _696 // muxc: _702 o: _703
uint16_t _704 = _686 ? _r_gr_stencil_1 : _703;
// _r_gr_stencil_1 added as input _r_gr_stencil_1
// muxa: _686 // muxb: self.in // muxc: _703 o: _704
[absd] [absd] // connected _704 to the output port
}

hcompute_demosaicked_1_stencil_1() {
uint32_t _755 = (uint32_t)(1);
int32_t _756 = _demosaicked_1_s0_y & _755;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__755 with name _755
// anda: self.in // andb: _755 o: _756 with obitwidth:32
bool _757 = _756 == 0;
// created const: const_p0_0$1 with name 0
// eqa: _756 // eqb: 0 o: _757 with obitwidth:1
uint16_t _758 = _757 ? _denoised_1_stencil_25 : _g_b_stencil_6;
// _denoised_1_stencil_25 added as input _denoised_1_stencil_25
// _g_b_stencil_6 added as input _g_b_stencil_6
// muxa: _757 // muxb: self.in // muxc: self.in o: _758
// connected _758 to the output port
}

hcompute_demosaicked_1_stencil_2() {
uint32_t _773 = (uint32_t)(1);
int32_t _774 = _demosaicked_1_s0_y & _773;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__773 with name _773
// anda: self.in // andb: _773 o: _774 with obitwidth:32
bool _775 = _774 == 0;
// created const: const_p0_0$2 with name 0
// eqa: _774 // eqb: 0 o: _775 with obitwidth:1
uint16_t _776 = _775 ? _b_gr_stencil_1 : _denoised_1_stencil_26;
// _b_gr_stencil_1 added as input _b_gr_stencil_1
// _denoised_1_stencil_26 added as input _denoised_1_stencil_26
// muxa: _775 // muxb: self.in // muxc: self.in o: _776
// connected _776 to the output port
}

hcompute_demosaicked_1_stencil_3() {
uint32_t _790 = (uint32_t)(1);
int32_t _791 = _demosaicked_1_s0_y & _790;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__790 with name _790
// anda: self.in // andb: _790 o: _791 with obitwidth:32
bool _792 = _791 == 0;
// created const: const_p0_0$3 with name 0
// eqa: _791 // eqb: 0 o: _792 with obitwidth:1
uint16_t _793 = _792 ? _denoised_1_stencil_27 : _r_gb_stencil_1;
// _denoised_1_stencil_27 added as input _denoised_1_stencil_27
// _r_gb_stencil_1 added as input _r_gb_stencil_1
// muxa: _792 // muxb: self.in // muxc: self.in o: _793
// connected _793 to the output port
}

hcompute_demosaicked_1_stencil_4() {
uint32_t _808 = (uint32_t)(1);
int32_t _809 = _demosaicked_1_s0_y & _808;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__808 with name _808
// anda: self.in // andb: _808 o: _809 with obitwidth:32
bool _810 = _809 == 0;
// created const: const_p0_0$4 with name 0
// eqa: _809 // eqb: 0 o: _810 with obitwidth:1
uint16_t _811 = _810 ? _g_r_stencil_9 : _denoised_1_stencil_28;
// _g_r_stencil_9 added as input _g_r_stencil_9
// _denoised_1_stencil_28 added as input _denoised_1_stencil_28
// muxa: _810 // muxb: self.in // muxc: self.in o: _811
// connected _811 to the output port
}

hcompute_demosaicked_1_stencil_5() {
uint32_t _852 = (uint32_t)(1);
int32_t _853 = _demosaicked_1_s0_y & _852;
// _demosaicked_1_s0_y added as input _demosaicked_1_s0_y
// created const: const_p1__852 with name _852
// anda: self.in // andb: _852 o: _853 with obitwidth:32
bool _854 = _853 == 0;
// created const: const_p0_0$5 with name 0
// eqa: _853 // eqb: 0 o: _854 with obitwidth:1
[absd] uint16_t _855 = _denoised_1_stencil_29 |-| _denoised_1_stencil_30;
// _denoised_1_stencil_29 added as input _denoised_1_stencil_29
// _denoised_1_stencil_30 added as input _denoised_1_stencil_30
// absda: self.in // absdb: self.in o: _855 with obitwidth:16
[absd] uint16_t _856 = _denoised_1_stencil_31 |-| _denoised_1_stencil_32;
// _denoised_1_stencil_31 added as input _denoised_1_stencil_31
// _denoised_1_stencil_32 added as input _denoised_1_stencil_32
// absda: self.in // absdb: self.in o: _856 with obitwidth:16
bool _857 = _855 < _856;
// ulta: _855 // ultb: _856 o: _857 with obitwidth:1
uint16_t _858 = _denoised_1_stencil_29 + _denoised_1_stencil_30;
// _denoised_1_stencil_29 added as input _denoised_1_stencil_29
// _denoised_1_stencil_30 added as input _denoised_1_stencil_30
// adda: self.in // addb: self.in o: _858 with obitwidth:16
uint16_t _859 = (uint16_t)(1);
uint16_t _860 = _858 >> _859;
// created const: const_p1__859 with name _859
// lshra: _858 // lshrb: _859 o: _860 with obitwidth:16
uint16_t _861 = _g_r_stencil_10 + _860;
// _g_r_stencil_10 added as input _g_r_stencil_10
// adda: self.in // addb: _860 o: _861 with obitwidth:16
uint16_t _862 = _g_b_stencil_7 + _g_b_stencil_8;
// _g_b_stencil_7 added as input _g_b_stencil_7
// _g_b_stencil_8 added as input _g_b_stencil_8
// adda: self.in // addb: self.in o: _862 with obitwidth:16
uint16_t _863 = _862 >> _859;
// created const: const_p1__859$1 with name _859
// lshra: _862 // lshrb: _859 o: _863 with obitwidth:16
uint16_t _864 = _861 - _863;
// suba: _861 // subb: _863 o: _864 with obitwidth:16
uint16_t _865 = _denoised_1_stencil_31 + _denoised_1_stencil_32;
// _denoised_1_stencil_31 added as input _denoised_1_stencil_31
// _denoised_1_stencil_32 added as input _denoised_1_stencil_32
// adda: self.in // addb: self.in o: _865 with obitwidth:16
uint16_t _866 = _865 >> _859;
// created const: const_p1__859$2 with name _859
// lshra: _865 // lshrb: _859 o: _866 with obitwidth:16
uint16_t _867 = _g_r_stencil_10 + _866;
// _g_r_stencil_10 added as input _g_r_stencil_10
// adda: self.in // addb: _866 o: _867 with obitwidth:16
uint16_t _868 = _g_b_stencil_9 + _g_b_stencil_10;
// _g_b_stencil_9 added as input _g_b_stencil_9
// _g_b_stencil_10 added as input _g_b_stencil_10
// adda: self.in // addb: self.in o: _868 with obitwidth:16
uint16_t _869 = _868 >> _859;
// created const: const_p1__859$3 with name _859
// lshra: _868 // lshrb: _859 o: _869 with obitwidth:16
uint16_t _870 = _867 - _869;
// suba: _867 // subb: _869 o: _870 with obitwidth:16
uint16_t _871 = _857 ? _864 : _870;
// muxa: _857 // muxb: _864 // muxc: _870 o: _871
uint16_t _872 = _854 ? _871 : _b_gb_stencil_1;
// _b_gb_stencil_1 added as input _b_gb_stencil_1
// muxa: _854 // muxb: _871 // muxc: self.in o: _872
[absd] [absd] // connected _872 to the output port
}

hcompute_corrected_stencil() {
[cast]uint16_t _941 = (uint16_t)(10000);
uint16_t _942 = _demosaicked_1_stencil_1 <min> _941;
// _demosaicked_1_stencil_1 added as input _demosaicked_1_stencil_1
// created const: const_p10000__941 with name _941
// umina: self.in // uminb: _941 o: _942 with obitwidth:16
int32_t _943 = (int32_t)(_942);
// renaming _942 to _943
// added/modified in wire_set: _943 = _942
int16_t _944 = _943 *m 549;
// created const: const_p549_549 with name 549
// mult_middlea: _943 // mult_middleb: 549 o: _944 with obitwidth:16
[cast]uint16_t _945 = _demosaicked_1_stencil_2 <min> _941;
// _demosaicked_1_stencil_2 added as input _demosaicked_1_stencil_2
// created const: const_p10000__941$1 with name _941
// umina: self.in // uminb: _941 o: _945 with obitwidth:16
int32_t _946 = (int32_t)(_945);
// renaming _945 to _946
// added/modified in wire_set: _946 = _945
int16_t _947 = _946 *m n103;
// created const: const_n103_n103 with name n103
// mult_middlea: _946 // mult_middleb: n103 o: _947 with obitwidth:16
int16_t _948 = _944 + _947;
// adda: _944 // addb: _947 o: _948 with obitwidth:16
[cast]uint16_t _949 = _demosaicked_1_stencil_3 <min> _941;
// _demosaicked_1_stencil_3 added as input _demosaicked_1_stencil_3
// created const: const_p10000__941$2 with name _941
// umina: self.in // uminb: _941 o: _949 with obitwidth:16
int32_t _950 = (int32_t)(_949);
// renaming _949 to _950
// added/modified in wire_set: _950 = _949
int16_t _951 = _950 *m 7;
// created const: const_p7_7 with name 7
// mult_middlea: _950 // mult_middleb: 7 o: _951 with obitwidth:16
int16_t _952 = _948 + _951;
// adda: _948 // addb: _951 o: _952 with obitwidth:16
int16_t _953 = (int16_t)(-40);
int16_t _954 = _952 + _953;
// created const: const_n40__953 with name _953
// adda: _952 // addb: _953 o: _954 with obitwidth:16
[cast]// renaming _942 to _943
// added/modified in wire_set: _943 = _942
[cast]// renaming _945 to _946
// added/modified in wire_set: _946 = _945
[cast]// renaming _949 to _950
// added/modified in wire_set: _950 = _949
// connected _954 to the output port
}

hcompute_corrected_stencil_1() {
[cast]uint16_t _999 = (uint16_t)(10000);
uint16_t _1000 = _demosaicked_1_stencil_4 <min> _999;
// _demosaicked_1_stencil_4 added as input _demosaicked_1_stencil_4
// created const: const_p10000__999 with name _999
// umina: self.in // uminb: _999 o: _1000 with obitwidth:16
int32_t _1001 = (int32_t)(_1000);
// renaming _1000 to _1001
// added/modified in wire_set: _1001 = _1000
int16_t _1002 = _1001 *m 549;
// created const: const_p549_549$1 with name 549
// mult_middlea: _1001 // mult_middleb: 549 o: _1002 with obitwidth:16
[cast]uint16_t _1003 = _demosaicked_1_stencil_5 <min> _999;
// _demosaicked_1_stencil_5 added as input _demosaicked_1_stencil_5
// created const: const_p10000__999$1 with name _999
// umina: self.in // uminb: _999 o: _1003 with obitwidth:16
int32_t _1004 = (int32_t)(_1003);
// renaming _1003 to _1004
// added/modified in wire_set: _1004 = _1003
int16_t _1005 = _1004 *m n103;
// created const: const_n103_n103$1 with name n103
// mult_middlea: _1004 // mult_middleb: n103 o: _1005 with obitwidth:16
int16_t _1006 = _1002 + _1005;
// adda: _1002 // addb: _1005 o: _1006 with obitwidth:16
[cast]uint16_t _1007 = _demosaicked_1_stencil_6 <min> _999;
// _demosaicked_1_stencil_6 added as input _demosaicked_1_stencil_6
// created const: const_p10000__999$2 with name _999
// umina: self.in // uminb: _999 o: _1007 with obitwidth:16
int32_t _1008 = (int32_t)(_1007);
// renaming _1007 to _1008
// added/modified in wire_set: _1008 = _1007
int16_t _1009 = _1008 *m 7;
// created const: const_p7_7$1 with name 7
// mult_middlea: _1008 // mult_middleb: 7 o: _1009 with obitwidth:16
int16_t _1010 = _1006 + _1009;
// adda: _1006 // addb: _1009 o: _1010 with obitwidth:16
int16_t _1011 = (int16_t)(-40);
int16_t _1012 = _1010 + _1011;
// created const: const_n40__1011 with name _1011
// adda: _1010 // addb: _1011 o: _1012 with obitwidth:16
[cast]// renaming _1000 to _1001
// added/modified in wire_set: _1001 = _1000
[cast]// renaming _1003 to _1004
// added/modified in wire_set: _1004 = _1003
[cast]// renaming _1007 to _1008
// added/modified in wire_set: _1008 = _1007
// connected _1012 to the output port
}

hcompute_corrected_stencil_2() {
[cast]uint16_t _1058 = (uint16_t)(10000);
uint16_t _1059 = _demosaicked_1_stencil_7 <min> _1058;
// _demosaicked_1_stencil_7 added as input _demosaicked_1_stencil_7
// created const: const_p10000__1058 with name _1058
// umina: self.in // uminb: _1058 o: _1059 with obitwidth:16
int32_t _1060 = (int32_t)(_1059);
// renaming _1059 to _1060
// added/modified in wire_set: _1060 = _1059
int16_t _1061 = _1060 *m n96;
// created const: const_n96_n96 with name n96
// mult_middlea: _1060 // mult_middleb: n96 o: _1061 with obitwidth:16
[cast]uint16_t _1062 = _demosaicked_1_stencil_8 <min> _1058;
// _demosaicked_1_stencil_8 added as input _demosaicked_1_stencil_8
// created const: const_p10000__1058$1 with name _1058
// umina: self.in // uminb: _1058 o: _1062 with obitwidth:16
int32_t _1063 = (int32_t)(_1062);
// renaming _1062 to _1063
// added/modified in wire_set: _1063 = _1062
int16_t _1064 = _1063 *m 373;
// created const: const_p373_373 with name 373
// mult_middlea: _1063 // mult_middleb: 373 o: _1064 with obitwidth:16
int16_t _1065 = _1061 + _1064;
// adda: _1061 // addb: _1064 o: _1065 with obitwidth:16
[cast]uint16_t _1066 = _demosaicked_1_stencil_9 <min> _1058;
// _demosaicked_1_stencil_9 added as input _demosaicked_1_stencil_9
// created const: const_p10000__1058$2 with name _1058
// umina: self.in // uminb: _1058 o: _1066 with obitwidth:16
int32_t _1067 = (int32_t)(_1066);
// renaming _1066 to _1067
// added/modified in wire_set: _1067 = _1066
int16_t _1068 = _1067 *m 62;
// created const: const_p62_62 with name 62
// mult_middlea: _1067 // mult_middleb: 62 o: _1068 with obitwidth:16
int16_t _1069 = _1065 + _1068;
// adda: _1065 // addb: _1068 o: _1069 with obitwidth:16
int16_t _1070 = (int16_t)(-29);
int16_t _1071 = _1069 + _1070;
// created const: const_n29__1070 with name _1070
// adda: _1069 // addb: _1070 o: _1071 with obitwidth:16
[cast]// renaming _1059 to _1060
// added/modified in wire_set: _1060 = _1059
[cast]// renaming _1062 to _1063
// added/modified in wire_set: _1063 = _1062
[cast]// renaming _1066 to _1067
// added/modified in wire_set: _1067 = _1066
// connected _1071 to the output port
}

hcompute_corrected_stencil_3() {
[cast]uint16_t _1116 = (uint16_t)(10000);
uint16_t _1117 = _demosaicked_1_stencil_10 <min> _1116;
// _demosaicked_1_stencil_10 added as input _demosaicked_1_stencil_10
// created const: const_p10000__1116 with name _1116
// umina: self.in // uminb: _1116 o: _1117 with obitwidth:16
int32_t _1118 = (int32_t)(_1117);
// renaming _1117 to _1118
// added/modified in wire_set: _1118 = _1117
int16_t _1119 = _1118 *m n96;
// created const: const_n96_n96$1 with name n96
// mult_middlea: _1118 // mult_middleb: n96 o: _1119 with obitwidth:16
[cast]uint16_t _1120 = _demosaicked_1_stencil_11 <min> _1116;
// _demosaicked_1_stencil_11 added as input _demosaicked_1_stencil_11
// created const: const_p10000__1116$1 with name _1116
// umina: self.in // uminb: _1116 o: _1120 with obitwidth:16
int32_t _1121 = (int32_t)(_1120);
// renaming _1120 to _1121
// added/modified in wire_set: _1121 = _1120
int16_t _1122 = _1121 *m 373;
// created const: const_p373_373$1 with name 373
// mult_middlea: _1121 // mult_middleb: 373 o: _1122 with obitwidth:16
int16_t _1123 = _1119 + _1122;
// adda: _1119 // addb: _1122 o: _1123 with obitwidth:16
[cast]uint16_t _1124 = _demosaicked_1_stencil_12 <min> _1116;
// _demosaicked_1_stencil_12 added as input _demosaicked_1_stencil_12
// created const: const_p10000__1116$2 with name _1116
// umina: self.in // uminb: _1116 o: _1124 with obitwidth:16
int32_t _1125 = (int32_t)(_1124);
// renaming _1124 to _1125
// added/modified in wire_set: _1125 = _1124
int16_t _1126 = _1125 *m 62;
// created const: const_p62_62$1 with name 62
// mult_middlea: _1125 // mult_middleb: 62 o: _1126 with obitwidth:16
int16_t _1127 = _1123 + _1126;
// adda: _1123 // addb: _1126 o: _1127 with obitwidth:16
int16_t _1128 = (int16_t)(-29);
int16_t _1129 = _1127 + _1128;
// created const: const_n29__1128 with name _1128
// adda: _1127 // addb: _1128 o: _1129 with obitwidth:16
[cast]// renaming _1117 to _1118
// added/modified in wire_set: _1118 = _1117
[cast]// renaming _1120 to _1121
// added/modified in wire_set: _1121 = _1120
[cast]// renaming _1124 to _1125
// added/modified in wire_set: _1125 = _1124
// connected _1129 to the output port
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
int16_t _1178 = _1177 *m n31;
// created const: const_n31_n31 with name n31
// mult_middlea: _1177 // mult_middleb: n31 o: _1178 with obitwidth:16
[cast]uint16_t _1179 = _demosaicked_1_stencil_14 <min> _1175;
// _demosaicked_1_stencil_14 added as input _demosaicked_1_stencil_14
// created const: const_p10000__1175$1 with name _1175
// umina: self.in // uminb: _1175 o: _1179 with obitwidth:16
int32_t _1180 = (int32_t)(_1179);
// renaming _1179 to _1180
// added/modified in wire_set: _1180 = _1179
int16_t _1181 = _1180 *m n261;
// created const: const_n261_n261 with name n261
// mult_middlea: _1180 // mult_middleb: n261 o: _1181 with obitwidth:16
int16_t _1182 = _1178 + _1181;
// adda: _1178 // addb: _1181 o: _1182 with obitwidth:16
[cast]uint16_t _1183 = _demosaicked_1_stencil_15 <min> _1175;
// _demosaicked_1_stencil_15 added as input _demosaicked_1_stencil_15
// created const: const_p10000__1175$2 with name _1175
// umina: self.in // uminb: _1175 o: _1183 with obitwidth:16
int32_t _1184 = (int32_t)(_1183);
// renaming _1183 to _1184
// added/modified in wire_set: _1184 = _1183
int16_t _1185 = _1184 *m 883;
// created const: const_p883_883 with name 883
// mult_middlea: _1184 // mult_middleb: 883 o: _1185 with obitwidth:16
int16_t _1186 = _1182 + _1185;
// adda: _1182 // addb: _1185 o: _1186 with obitwidth:16
int16_t _1187 = (int16_t)(-22);
int16_t _1188 = _1186 + _1187;
// created const: const_n22__1187 with name _1187
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
[cast]uint16_t _1233 = (uint16_t)(10000);
uint16_t _1234 = _demosaicked_1_stencil_16 <min> _1233;
// _demosaicked_1_stencil_16 added as input _demosaicked_1_stencil_16
// created const: const_p10000__1233 with name _1233
// umina: self.in // uminb: _1233 o: _1234 with obitwidth:16
int32_t _1235 = (int32_t)(_1234);
// renaming _1234 to _1235
// added/modified in wire_set: _1235 = _1234
int16_t _1236 = _1235 *m n31;
// created const: const_n31_n31$1 with name n31
// mult_middlea: _1235 // mult_middleb: n31 o: _1236 with obitwidth:16
[cast]uint16_t _1237 = _demosaicked_1_stencil_17 <min> _1233;
// _demosaicked_1_stencil_17 added as input _demosaicked_1_stencil_17
// created const: const_p10000__1233$1 with name _1233
// umina: self.in // uminb: _1233 o: _1237 with obitwidth:16
int32_t _1238 = (int32_t)(_1237);
// renaming _1237 to _1238
// added/modified in wire_set: _1238 = _1237
int16_t _1239 = _1238 *m n261;
// created const: const_n261_n261$1 with name n261
// mult_middlea: _1238 // mult_middleb: n261 o: _1239 with obitwidth:16
int16_t _1240 = _1236 + _1239;
// adda: _1236 // addb: _1239 o: _1240 with obitwidth:16
[cast]uint16_t _1241 = _demosaicked_1_stencil_18 <min> _1233;
// _demosaicked_1_stencil_18 added as input _demosaicked_1_stencil_18
// created const: const_p10000__1233$2 with name _1233
// umina: self.in // uminb: _1233 o: _1241 with obitwidth:16
int32_t _1242 = (int32_t)(_1241);
// renaming _1241 to _1242
// added/modified in wire_set: _1242 = _1241
int16_t _1243 = _1242 *m 883;
// created const: const_p883_883$1 with name 883
// mult_middlea: _1242 // mult_middleb: 883 o: _1243 with obitwidth:16
int16_t _1244 = _1240 + _1243;
// adda: _1240 // addb: _1243 o: _1244 with obitwidth:16
int16_t _1245 = (int16_t)(-22);
int16_t _1246 = _1244 + _1245;
// created const: const_n22__1245 with name _1245
// adda: _1244 // addb: _1245 o: _1246 with obitwidth:16
[cast]// renaming _1234 to _1235
// added/modified in wire_set: _1235 = _1234
[cast]// renaming _1237 to _1238
// added/modified in wire_set: _1238 = _1237
[cast]// renaming _1241 to _1242
// added/modified in wire_set: _1242 = _1241
// connected _1246 to the output port
}

hcompute_curved_stencil() {
// adding coreir inst curvea0
[cast]int16_t _3327 = (int16_t)(1023);
int16_t _3328 = _corrected_stencil_1 <smin> _3327;
// _corrected_stencil_1 added as input _corrected_stencil_1
// created const: const_p1023__3327 with name _3327
// smina: self.in // sminb: _3327 o: _3328 with obitwidth:16
int16_t _3329 = (int16_t)(0);
int16_t _3330 = _3328 <smax> _3329;
// created const: const_p0__3329 with name _3329
// smaxa: _3328 // smaxb: _3329 o: _3330 with obitwidth:16
uint16_t _3331 = (uint16_t)(_3330);
// renaming _3330 to _3331
// added/modified in wire_set: _3331 = _3330
uint16_t _3332 = ((uint16_t *)_curvea0)[_3331][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0
[cast]// renaming _3330 to _3331
// added/modified in wire_set: _3331 = _3330
// loading from rom curvea0 with gen memory.rom2
// connected _3332 to the output port
}

hcompute_curved_stencil_1() {
// adding coreir inst curvea0
[cast]int16_t _4373 = (int16_t)(1023);
int16_t _4374 = _corrected_stencil_2 <smin> _4373;
// _corrected_stencil_2 added as input _corrected_stencil_2
// created const: const_p1023__4373 with name _4373
// smina: self.in // sminb: _4373 o: _4374 with obitwidth:16
int16_t _4375 = (int16_t)(0);
int16_t _4376 = _4374 <smax> _4375;
// created const: const_p0__4375 with name _4375
// smaxa: _4374 // smaxb: _4375 o: _4376 with obitwidth:16
uint16_t _4377 = (uint16_t)(_4376);
// renaming _4376 to _4377
// added/modified in wire_set: _4377 = _4376
uint16_t _4378 = ((uint16_t *)_curvea0)[_4377][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$1
[cast]// renaming _4376 to _4377
// added/modified in wire_set: _4377 = _4376
// loading from rom curvea0 with gen memory.rom2
// connected _4378 to the output port
}

hcompute_curved_stencil_2() {
// adding coreir inst curvea0
[cast]int16_t _5420 = (int16_t)(1023);
int16_t _5421 = _corrected_stencil_3 <smin> _5420;
// _corrected_stencil_3 added as input _corrected_stencil_3
// created const: const_p1023__5420 with name _5420
// smina: self.in // sminb: _5420 o: _5421 with obitwidth:16
int16_t _5422 = (int16_t)(0);
int16_t _5423 = _5421 <smax> _5422;
// created const: const_p0__5422 with name _5422
// smaxa: _5421 // smaxb: _5422 o: _5423 with obitwidth:16
uint16_t _5424 = (uint16_t)(_5423);
// renaming _5423 to _5424
// added/modified in wire_set: _5424 = _5423
uint16_t _5425 = ((uint16_t *)_curvea0)[_5424][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$2
[cast]// renaming _5423 to _5424
// added/modified in wire_set: _5424 = _5423
// loading from rom curvea0 with gen memory.rom2
// connected _5425 to the output port
}

hcompute_curved_stencil_3() {
// adding coreir inst curvea0
[cast]int16_t _6466 = (int16_t)(1023);
int16_t _6467 = _corrected_stencil_4 <smin> _6466;
// _corrected_stencil_4 added as input _corrected_stencil_4
// created const: const_p1023__6466 with name _6466
// smina: self.in // sminb: _6466 o: _6467 with obitwidth:16
int16_t _6468 = (int16_t)(0);
int16_t _6469 = _6467 <smax> _6468;
// created const: const_p0__6468 with name _6468
// smaxa: _6467 // smaxb: _6468 o: _6469 with obitwidth:16
uint16_t _6470 = (uint16_t)(_6469);
// renaming _6469 to _6470
// added/modified in wire_set: _6470 = _6469
uint16_t _6471 = ((uint16_t *)_curvea0)[_6470][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$3
[cast]// renaming _6469 to _6470
// added/modified in wire_set: _6470 = _6469
// loading from rom curvea0 with gen memory.rom2
// connected _6471 to the output port
}

hcompute_curved_stencil_4() {
// adding coreir inst curvea0
[cast]int16_t _7513 = (int16_t)(1023);
int16_t _7514 = _corrected_stencil_5 <smin> _7513;
// _corrected_stencil_5 added as input _corrected_stencil_5
// created const: const_p1023__7513 with name _7513
// smina: self.in // sminb: _7513 o: _7514 with obitwidth:16
int16_t _7515 = (int16_t)(0);
int16_t _7516 = _7514 <smax> _7515;
// created const: const_p0__7515 with name _7515
// smaxa: _7514 // smaxb: _7515 o: _7516 with obitwidth:16
uint16_t _7517 = (uint16_t)(_7516);
// renaming _7516 to _7517
// added/modified in wire_set: _7517 = _7516
uint16_t _7518 = ((uint16_t *)_curvea0)[_7517][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$4
[cast]// renaming _7516 to _7517
// added/modified in wire_set: _7517 = _7516
// loading from rom curvea0 with gen memory.rom2
// connected _7518 to the output port
}

hcompute_curved_stencil_5() {
// adding coreir inst curvea0
[cast]int16_t _8559 = (int16_t)(1023);
int16_t _8560 = _corrected_stencil_6 <smin> _8559;
// _corrected_stencil_6 added as input _corrected_stencil_6
// created const: const_p1023__8559 with name _8559
// smina: self.in // sminb: _8559 o: _8560 with obitwidth:16
int16_t _8561 = (int16_t)(0);
int16_t _8562 = _8560 <smax> _8561;
// created const: const_p0__8561 with name _8561
// smaxa: _8560 // smaxb: _8561 o: _8562 with obitwidth:16
uint16_t _8563 = (uint16_t)(_8562);
// renaming _8562 to _8563
// added/modified in wire_set: _8563 = _8562
uint16_t _8564 = ((uint16_t *)_curvea0)[_8563][load];
// loading from rom curvea0 with gen memory.rom2
// created rom named rom_curvea0$5
[cast]// renaming _8562 to _8563
// added/modified in wire_set: _8563 = _8562
// loading from rom curvea0 with gen memory.rom2
// connected _8564 to the output port
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

