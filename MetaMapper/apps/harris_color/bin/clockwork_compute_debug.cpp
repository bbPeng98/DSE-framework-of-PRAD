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

hcompute_hw_input_global_wrapper_glb_stencil_4() {
// _hw_input_stencil_5 added as input _hw_input_stencil_5
// connected _hw_input_stencil_5 to the output port
}

hcompute_hw_input_global_wrapper_glb_stencil_5() {
// _hw_input_stencil_6 added as input _hw_input_stencil_6
// connected _hw_input_stencil_6 to the output port
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

hcompute_hw_input_global_wrapper_global_wrapper_stencil_4() {
// _hw_input_global_wrapper_glb_stencil_5 added as input _hw_input_global_wrapper_glb_stencil_5
// connected _hw_input_global_wrapper_glb_stencil_5 to the output port
}

hcompute_hw_input_global_wrapper_global_wrapper_stencil_5() {
// _hw_input_global_wrapper_glb_stencil_6 added as input _hw_input_global_wrapper_glb_stencil_6
// connected _hw_input_global_wrapper_glb_stencil_6 to the output port
}

hcompute_gray_stencil() {
[cast]uint16_t _424 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_1);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_1 to _424
// _hw_input_global_wrapper_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_global_wrapper_stencil_1
// added/modified in wire_set: _424 = _hw_input_global_wrapper_global_wrapper_stencil_1
uint16_t _425 = (uint16_t)(150);
uint16_t _426 = _424 * _425;
// created const: const_p150__425 with name _425
// mula: _424 // mulb: _425 o: _426 with obitwidth:16
[cast]uint16_t _427 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_2);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_2 to _427
// _hw_input_global_wrapper_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_global_wrapper_stencil_2
// added/modified in wire_set: _427 = _hw_input_global_wrapper_global_wrapper_stencil_2
uint16_t _428 = (uint16_t)(29);
uint16_t _429 = _427 * _428;
// created const: const_p29__428 with name _428
// mula: _427 // mulb: _428 o: _429 with obitwidth:16
[cast]uint16_t _430 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_3);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_3 to _430
// _hw_input_global_wrapper_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_global_wrapper_stencil_3
// added/modified in wire_set: _430 = _hw_input_global_wrapper_global_wrapper_stencil_3
uint16_t _431 = (uint16_t)(77);
uint16_t _432 = _430 * _431;
// created const: const_p77__431 with name _431
// mula: _430 // mulb: _431 o: _432 with obitwidth:16
uint16_t _433 = _429 + _432;
// adda: _429 // addb: _432 o: _433 with obitwidth:16
uint16_t _434 = _426 + _433;
// adda: _426 // addb: _433 o: _434 with obitwidth:16
uint16_t _435 = (uint16_t)(8);
uint16_t _436 = _434 >> _435;
// created const: const_p8__435 with name _435
// lshra: _434 // lshrb: _435 o: _436 with obitwidth:16
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_1 to _424
// _hw_input_global_wrapper_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_global_wrapper_stencil_1
// added/modified in wire_set: _424 = _hw_input_global_wrapper_global_wrapper_stencil_1
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_2 to _427
// _hw_input_global_wrapper_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_global_wrapper_stencil_2
// added/modified in wire_set: _427 = _hw_input_global_wrapper_global_wrapper_stencil_2
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_3 to _430
// _hw_input_global_wrapper_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_global_wrapper_stencil_3
// added/modified in wire_set: _430 = _hw_input_global_wrapper_global_wrapper_stencil_3
// connected _436 to the output port
}

hcompute_gray_stencil_1() {
[cast]uint16_t _469 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_4);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_4 to _469
// _hw_input_global_wrapper_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_global_wrapper_stencil_4
// added/modified in wire_set: _469 = _hw_input_global_wrapper_global_wrapper_stencil_4
uint16_t _470 = (uint16_t)(150);
uint16_t _471 = _469 * _470;
// created const: const_p150__470 with name _470
// mula: _469 // mulb: _470 o: _471 with obitwidth:16
[cast]uint16_t _472 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_5);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_5 to _472
// _hw_input_global_wrapper_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_global_wrapper_stencil_5
// added/modified in wire_set: _472 = _hw_input_global_wrapper_global_wrapper_stencil_5
uint16_t _473 = (uint16_t)(29);
uint16_t _474 = _472 * _473;
// created const: const_p29__473 with name _473
// mula: _472 // mulb: _473 o: _474 with obitwidth:16
[cast]uint16_t _475 = (uint16_t)(_hw_input_global_wrapper_global_wrapper_stencil_6);
// renaming _hw_input_global_wrapper_global_wrapper_stencil_6 to _475
// _hw_input_global_wrapper_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_global_wrapper_stencil_6
// added/modified in wire_set: _475 = _hw_input_global_wrapper_global_wrapper_stencil_6
uint16_t _476 = (uint16_t)(77);
uint16_t _477 = _475 * _476;
// created const: const_p77__476 with name _476
// mula: _475 // mulb: _476 o: _477 with obitwidth:16
uint16_t _478 = _474 + _477;
// adda: _474 // addb: _477 o: _478 with obitwidth:16
uint16_t _479 = _471 + _478;
// adda: _471 // addb: _478 o: _479 with obitwidth:16
uint16_t _480 = (uint16_t)(8);
uint16_t _481 = _479 >> _480;
// created const: const_p8__480$1 with name _480
// lshra: _479 // lshrb: _480 o: _481 with obitwidth:16
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_4 to _469
// _hw_input_global_wrapper_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_global_wrapper_stencil_4
// added/modified in wire_set: _469 = _hw_input_global_wrapper_global_wrapper_stencil_4
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_5 to _472
// _hw_input_global_wrapper_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_global_wrapper_stencil_5
// added/modified in wire_set: _472 = _hw_input_global_wrapper_global_wrapper_stencil_5
[cast]// renaming _hw_input_global_wrapper_global_wrapper_stencil_6 to _475
// _hw_input_global_wrapper_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_global_wrapper_stencil_6
// added/modified in wire_set: _475 = _hw_input_global_wrapper_global_wrapper_stencil_6
// connected _481 to the output port
}

hcompute_grad_x_unclamp_stencil() {
int16_t _504 = (int16_t)(0);
// created const: const_p0__504 with name _504
// connected _504 to the output port
}

hcompute_grad_x_unclamp_stencil_1() {
int16_t _510 = (int16_t)(0);
// created const: const_p0__510 with name _510
// connected _510 to the output port
}

hcompute_grad_x_unclamp_stencil_2() {
[cast]int16_t _532 = (int16_t)(_gray_stencil_1);
// renaming _gray_stencil_1 to _532
// _gray_stencil_1 added as input _gray_stencil_1
// added/modified in wire_set: _532 = _gray_stencil_1
int16_t _533 = (int16_t)(2);
int16_t _534 = _532 * _533;
// created const: const_p2__533 with name _533
// mula: _532 // mulb: _533 o: _534 with obitwidth:16
int16_t _535 = _grad_x_unclamp_stencil_1 + _534;
// _grad_x_unclamp_stencil_1 added as input _grad_x_unclamp_stencil_1
// adda: self.in // addb: _534 o: _535 with obitwidth:16
[cast]int16_t _536 = (int16_t)(_gray_stencil_2);
// renaming _gray_stencil_2 to _536
// _gray_stencil_2 added as input _gray_stencil_2
// added/modified in wire_set: _536 = _gray_stencil_2
int16_t _537 = _535 - _536;
// suba: _535 // subb: _536 o: _537 with obitwidth:16
[cast]int16_t _538 = (int16_t)(_gray_stencil_3);
// renaming _gray_stencil_3 to _538
// _gray_stencil_3 added as input _gray_stencil_3
// added/modified in wire_set: _538 = _gray_stencil_3
int16_t _539 = _537 + _538;
// adda: _537 // addb: _538 o: _539 with obitwidth:16
[cast]int16_t _540 = (int16_t)(_gray_stencil_4);
// renaming _gray_stencil_4 to _540
// _gray_stencil_4 added as input _gray_stencil_4
// added/modified in wire_set: _540 = _gray_stencil_4
int16_t _541 = _540 * _533;
// created const: const_p2__533$1 with name _533
// mula: _540 // mulb: _533 o: _541 with obitwidth:16
int16_t _542 = _539 - _541;
// suba: _539 // subb: _541 o: _542 with obitwidth:16
[cast]int16_t _543 = (int16_t)(_gray_stencil_5);
// renaming _gray_stencil_5 to _543
// _gray_stencil_5 added as input _gray_stencil_5
// added/modified in wire_set: _543 = _gray_stencil_5
int16_t _544 = _542 - _543;
// suba: _542 // subb: _543 o: _544 with obitwidth:16
[cast]int16_t _545 = (int16_t)(_gray_stencil_6);
// renaming _gray_stencil_6 to _545
// _gray_stencil_6 added as input _gray_stencil_6
// added/modified in wire_set: _545 = _gray_stencil_6
int16_t _546 = _544 + _545;
// adda: _544 // addb: _545 o: _546 with obitwidth:16
[cast]// renaming _gray_stencil_1 to _532
// _gray_stencil_1 added as input _gray_stencil_1
// added/modified in wire_set: _532 = _gray_stencil_1
[cast]// renaming _gray_stencil_2 to _536
// _gray_stencil_2 added as input _gray_stencil_2
// added/modified in wire_set: _536 = _gray_stencil_2
[cast]// renaming _gray_stencil_3 to _538
// _gray_stencil_3 added as input _gray_stencil_3
// added/modified in wire_set: _538 = _gray_stencil_3
[cast]// renaming _gray_stencil_4 to _540
// _gray_stencil_4 added as input _gray_stencil_4
// added/modified in wire_set: _540 = _gray_stencil_4
[cast]// renaming _gray_stencil_5 to _543
// _gray_stencil_5 added as input _gray_stencil_5
// added/modified in wire_set: _543 = _gray_stencil_5
[cast]// renaming _gray_stencil_6 to _545
// _gray_stencil_6 added as input _gray_stencil_6
// added/modified in wire_set: _545 = _gray_stencil_6
// connected _546 to the output port
}

hcompute_grad_x_unclamp_stencil_3() {
[cast]int16_t _590 = (int16_t)(_gray_stencil_7);
// renaming _gray_stencil_7 to _590
// _gray_stencil_7 added as input _gray_stencil_7
// added/modified in wire_set: _590 = _gray_stencil_7
int16_t _591 = (int16_t)(2);
int16_t _592 = _590 * _591;
// created const: const_p2__591 with name _591
// mula: _590 // mulb: _591 o: _592 with obitwidth:16
int16_t _593 = _grad_x_unclamp_stencil_2 + _592;
// _grad_x_unclamp_stencil_2 added as input _grad_x_unclamp_stencil_2
// adda: self.in // addb: _592 o: _593 with obitwidth:16
[cast]int16_t _594 = (int16_t)(_gray_stencil_8);
// renaming _gray_stencil_8 to _594
// _gray_stencil_8 added as input _gray_stencil_8
// added/modified in wire_set: _594 = _gray_stencil_8
int16_t _595 = _593 - _594;
// suba: _593 // subb: _594 o: _595 with obitwidth:16
[cast]int16_t _596 = (int16_t)(_gray_stencil_9);
// renaming _gray_stencil_9 to _596
// _gray_stencil_9 added as input _gray_stencil_9
// added/modified in wire_set: _596 = _gray_stencil_9
int16_t _597 = _595 + _596;
// adda: _595 // addb: _596 o: _597 with obitwidth:16
[cast]int16_t _598 = (int16_t)(_gray_stencil_10);
// renaming _gray_stencil_10 to _598
// _gray_stencil_10 added as input _gray_stencil_10
// added/modified in wire_set: _598 = _gray_stencil_10
int16_t _599 = _598 * _591;
// created const: const_p2__591$1 with name _591
// mula: _598 // mulb: _591 o: _599 with obitwidth:16
int16_t _600 = _597 - _599;
// suba: _597 // subb: _599 o: _600 with obitwidth:16
[cast]int16_t _601 = (int16_t)(_gray_stencil_11);
// renaming _gray_stencil_11 to _601
// _gray_stencil_11 added as input _gray_stencil_11
// added/modified in wire_set: _601 = _gray_stencil_11
int16_t _602 = _600 - _601;
// suba: _600 // subb: _601 o: _602 with obitwidth:16
[cast]int16_t _603 = (int16_t)(_gray_stencil_12);
// renaming _gray_stencil_12 to _603
// _gray_stencil_12 added as input _gray_stencil_12
// added/modified in wire_set: _603 = _gray_stencil_12
int16_t _604 = _602 + _603;
// adda: _602 // addb: _603 o: _604 with obitwidth:16
[cast]// renaming _gray_stencil_7 to _590
// _gray_stencil_7 added as input _gray_stencil_7
// added/modified in wire_set: _590 = _gray_stencil_7
[cast]// renaming _gray_stencil_8 to _594
// _gray_stencil_8 added as input _gray_stencil_8
// added/modified in wire_set: _594 = _gray_stencil_8
[cast]// renaming _gray_stencil_9 to _596
// _gray_stencil_9 added as input _gray_stencil_9
// added/modified in wire_set: _596 = _gray_stencil_9
[cast]// renaming _gray_stencil_10 to _598
// _gray_stencil_10 added as input _gray_stencil_10
// added/modified in wire_set: _598 = _gray_stencil_10
[cast]// renaming _gray_stencil_11 to _601
// _gray_stencil_11 added as input _gray_stencil_11
// added/modified in wire_set: _601 = _gray_stencil_11
[cast]// renaming _gray_stencil_12 to _603
// _gray_stencil_12 added as input _gray_stencil_12
// added/modified in wire_set: _603 = _gray_stencil_12
// connected _604 to the output port
}

hcompute_lxx_stencil() {
int16_t _642 = (int16_t)(180);
int16_t _643 = _grad_x_unclamp_stencil_3 <smin> _642;
// _grad_x_unclamp_stencil_3 added as input _grad_x_unclamp_stencil_3
// created const: const_p180__642 with name _642
// smina: self.in // sminb: _642 o: _643 with obitwidth:16
int16_t _644 = (int16_t)(-180);
int16_t _645 = _643 <smax> _644;
// created const: const_n180__644 with name _644
// smaxa: _643 // smaxb: _644 o: _645 with obitwidth:16
int16_t _646 = _645 * _645;
// mula: _645 // mulb: _645 o: _646 with obitwidth:16
uint16_t _647 = (uint16_t)(6);
int16_t _648 = _646 >> _647;
// created const: const_p6__647 with name _647
// ashra: _646 // ashrb: _647 o: _648 with obitwidth:16
// connected _648 to the output port
}

hcompute_lxx_stencil_1() {
int16_t _667 = (int16_t)(180);
int16_t _668 = _grad_x_unclamp_stencil_4 <smin> _667;
// _grad_x_unclamp_stencil_4 added as input _grad_x_unclamp_stencil_4
// created const: const_p180__667 with name _667
// smina: self.in // sminb: _667 o: _668 with obitwidth:16
int16_t _669 = (int16_t)(-180);
int16_t _670 = _668 <smax> _669;
// created const: const_n180__669 with name _669
// smaxa: _668 // smaxb: _669 o: _670 with obitwidth:16
int16_t _671 = _670 * _670;
// mula: _670 // mulb: _670 o: _671 with obitwidth:16
uint16_t _672 = (uint16_t)(6);
int16_t _673 = _671 >> _672;
// created const: const_p6__672 with name _672
// ashra: _671 // ashrb: _672 o: _673 with obitwidth:16
// connected _673 to the output port
}

hcompute_lgxx_stencil() {
int16_t _688 = (int16_t)(0);
// created const: const_p0__688 with name _688
// connected _688 to the output port
}

hcompute_lgxx_stencil_1() {
int16_t _694 = (int16_t)(0);
// created const: const_p0__694 with name _694
// connected _694 to the output port
}

hcompute_lgxx_stencil_2() {
int16_t _710 = _lxx_stencil_8 + _lxx_stencil_9;
// _lxx_stencil_8 added as input _lxx_stencil_8
// _lxx_stencil_9 added as input _lxx_stencil_9
// adda: self.in // addb: self.in o: _710 with obitwidth:16
int16_t _711 = _lxx_stencil_7 + _710;
// _lxx_stencil_7 added as input _lxx_stencil_7
// adda: self.in // addb: _710 o: _711 with obitwidth:16
int16_t _712 = _lxx_stencil_6 + _711;
// _lxx_stencil_6 added as input _lxx_stencil_6
// adda: self.in // addb: _711 o: _712 with obitwidth:16
int16_t _713 = _lxx_stencil_5 + _712;
// _lxx_stencil_5 added as input _lxx_stencil_5
// adda: self.in // addb: _712 o: _713 with obitwidth:16
int16_t _714 = _lxx_stencil_4 + _713;
// _lxx_stencil_4 added as input _lxx_stencil_4
// adda: self.in // addb: _713 o: _714 with obitwidth:16
int16_t _715 = _lxx_stencil_3 + _714;
// _lxx_stencil_3 added as input _lxx_stencil_3
// adda: self.in // addb: _714 o: _715 with obitwidth:16
int16_t _716 = _lxx_stencil_2 + _715;
// _lxx_stencil_2 added as input _lxx_stencil_2
// adda: self.in // addb: _715 o: _716 with obitwidth:16
int16_t _717 = _lgxx_stencil_1 + _716;
// _lgxx_stencil_1 added as input _lgxx_stencil_1
// adda: self.in // addb: _716 o: _717 with obitwidth:16
int16_t _718 = _lxx_stencil_1 + _717;
// _lxx_stencil_1 added as input _lxx_stencil_1
// adda: self.in // addb: _717 o: _718 with obitwidth:16
// connected _718 to the output port
}

hcompute_lgxx_stencil_3() {
int16_t _754 = _lxx_stencil_17 + _lxx_stencil_18;
// _lxx_stencil_17 added as input _lxx_stencil_17
// _lxx_stencil_18 added as input _lxx_stencil_18
// adda: self.in // addb: self.in o: _754 with obitwidth:16
int16_t _755 = _lxx_stencil_16 + _754;
// _lxx_stencil_16 added as input _lxx_stencil_16
// adda: self.in // addb: _754 o: _755 with obitwidth:16
int16_t _756 = _lxx_stencil_15 + _755;
// _lxx_stencil_15 added as input _lxx_stencil_15
// adda: self.in // addb: _755 o: _756 with obitwidth:16
int16_t _757 = _lxx_stencil_14 + _756;
// _lxx_stencil_14 added as input _lxx_stencil_14
// adda: self.in // addb: _756 o: _757 with obitwidth:16
int16_t _758 = _lxx_stencil_13 + _757;
// _lxx_stencil_13 added as input _lxx_stencil_13
// adda: self.in // addb: _757 o: _758 with obitwidth:16
int16_t _759 = _lxx_stencil_12 + _758;
// _lxx_stencil_12 added as input _lxx_stencil_12
// adda: self.in // addb: _758 o: _759 with obitwidth:16
int16_t _760 = _lxx_stencil_11 + _759;
// _lxx_stencil_11 added as input _lxx_stencil_11
// adda: self.in // addb: _759 o: _760 with obitwidth:16
int16_t _761 = _lgxx_stencil_2 + _760;
// _lgxx_stencil_2 added as input _lgxx_stencil_2
// adda: self.in // addb: _760 o: _761 with obitwidth:16
int16_t _762 = _lxx_stencil_10 + _761;
// _lxx_stencil_10 added as input _lxx_stencil_10
// adda: self.in // addb: _761 o: _762 with obitwidth:16
// connected _762 to the output port
}

hcompute_grad_y_unclamp_stencil() {
int16_t _792 = (int16_t)(0);
// created const: const_p0__792 with name _792
// connected _792 to the output port
}

hcompute_grad_y_unclamp_stencil_1() {
int16_t _798 = (int16_t)(0);
// created const: const_p0__798 with name _798
// connected _798 to the output port
}

hcompute_grad_y_unclamp_stencil_2() {
[cast]int16_t _820 = (int16_t)(_gray_stencil_13);
// renaming _gray_stencil_13 to _820
// _gray_stencil_13 added as input _gray_stencil_13
// added/modified in wire_set: _820 = _gray_stencil_13
int16_t _821 = (int16_t)(2);
int16_t _822 = _820 * _821;
// created const: const_p2__821 with name _821
// mula: _820 // mulb: _821 o: _822 with obitwidth:16
int16_t _823 = _grad_y_unclamp_stencil_1 + _822;
// _grad_y_unclamp_stencil_1 added as input _grad_y_unclamp_stencil_1
// adda: self.in // addb: _822 o: _823 with obitwidth:16
[cast]int16_t _824 = (int16_t)(_gray_stencil_14);
// renaming _gray_stencil_14 to _824
// _gray_stencil_14 added as input _gray_stencil_14
// added/modified in wire_set: _824 = _gray_stencil_14
int16_t _825 = _823 - _824;
// suba: _823 // subb: _824 o: _825 with obitwidth:16
[cast]int16_t _826 = (int16_t)(_gray_stencil_15);
// renaming _gray_stencil_15 to _826
// _gray_stencil_15 added as input _gray_stencil_15
// added/modified in wire_set: _826 = _gray_stencil_15
int16_t _827 = _826 * _821;
// created const: const_p2__821$1 with name _821
// mula: _826 // mulb: _821 o: _827 with obitwidth:16
int16_t _828 = _825 - _827;
// suba: _825 // subb: _827 o: _828 with obitwidth:16
[cast]int16_t _829 = (int16_t)(_gray_stencil_16);
// renaming _gray_stencil_16 to _829
// _gray_stencil_16 added as input _gray_stencil_16
// added/modified in wire_set: _829 = _gray_stencil_16
int16_t _830 = _828 - _829;
// suba: _828 // subb: _829 o: _830 with obitwidth:16
[cast]int16_t _831 = (int16_t)(_gray_stencil_17);
// renaming _gray_stencil_17 to _831
// _gray_stencil_17 added as input _gray_stencil_17
// added/modified in wire_set: _831 = _gray_stencil_17
int16_t _832 = _830 + _831;
// adda: _830 // addb: _831 o: _832 with obitwidth:16
[cast]int16_t _833 = (int16_t)(_gray_stencil_18);
// renaming _gray_stencil_18 to _833
// _gray_stencil_18 added as input _gray_stencil_18
// added/modified in wire_set: _833 = _gray_stencil_18
int16_t _834 = _832 + _833;
// adda: _832 // addb: _833 o: _834 with obitwidth:16
[cast]// renaming _gray_stencil_13 to _820
// _gray_stencil_13 added as input _gray_stencil_13
// added/modified in wire_set: _820 = _gray_stencil_13
[cast]// renaming _gray_stencil_14 to _824
// _gray_stencil_14 added as input _gray_stencil_14
// added/modified in wire_set: _824 = _gray_stencil_14
[cast]// renaming _gray_stencil_15 to _826
// _gray_stencil_15 added as input _gray_stencil_15
// added/modified in wire_set: _826 = _gray_stencil_15
[cast]// renaming _gray_stencil_16 to _829
// _gray_stencil_16 added as input _gray_stencil_16
// added/modified in wire_set: _829 = _gray_stencil_16
[cast]// renaming _gray_stencil_17 to _831
// _gray_stencil_17 added as input _gray_stencil_17
// added/modified in wire_set: _831 = _gray_stencil_17
[cast]// renaming _gray_stencil_18 to _833
// _gray_stencil_18 added as input _gray_stencil_18
// added/modified in wire_set: _833 = _gray_stencil_18
// connected _834 to the output port
}

hcompute_grad_y_unclamp_stencil_3() {
[cast]int16_t _878 = (int16_t)(_gray_stencil_19);
// renaming _gray_stencil_19 to _878
// _gray_stencil_19 added as input _gray_stencil_19
// added/modified in wire_set: _878 = _gray_stencil_19
int16_t _879 = (int16_t)(2);
int16_t _880 = _878 * _879;
// created const: const_p2__879 with name _879
// mula: _878 // mulb: _879 o: _880 with obitwidth:16
int16_t _881 = _grad_y_unclamp_stencil_2 + _880;
// _grad_y_unclamp_stencil_2 added as input _grad_y_unclamp_stencil_2
// adda: self.in // addb: _880 o: _881 with obitwidth:16
[cast]int16_t _882 = (int16_t)(_gray_stencil_20);
// renaming _gray_stencil_20 to _882
// _gray_stencil_20 added as input _gray_stencil_20
// added/modified in wire_set: _882 = _gray_stencil_20
int16_t _883 = _881 - _882;
// suba: _881 // subb: _882 o: _883 with obitwidth:16
[cast]int16_t _884 = (int16_t)(_gray_stencil_21);
// renaming _gray_stencil_21 to _884
// _gray_stencil_21 added as input _gray_stencil_21
// added/modified in wire_set: _884 = _gray_stencil_21
int16_t _885 = _884 * _879;
// created const: const_p2__879$1 with name _879
// mula: _884 // mulb: _879 o: _885 with obitwidth:16
int16_t _886 = _883 - _885;
// suba: _883 // subb: _885 o: _886 with obitwidth:16
[cast]int16_t _887 = (int16_t)(_gray_stencil_22);
// renaming _gray_stencil_22 to _887
// _gray_stencil_22 added as input _gray_stencil_22
// added/modified in wire_set: _887 = _gray_stencil_22
int16_t _888 = _886 - _887;
// suba: _886 // subb: _887 o: _888 with obitwidth:16
[cast]int16_t _889 = (int16_t)(_gray_stencil_23);
// renaming _gray_stencil_23 to _889
// _gray_stencil_23 added as input _gray_stencil_23
// added/modified in wire_set: _889 = _gray_stencil_23
int16_t _890 = _888 + _889;
// adda: _888 // addb: _889 o: _890 with obitwidth:16
[cast]int16_t _891 = (int16_t)(_gray_stencil_24);
// renaming _gray_stencil_24 to _891
// _gray_stencil_24 added as input _gray_stencil_24
// added/modified in wire_set: _891 = _gray_stencil_24
int16_t _892 = _890 + _891;
// adda: _890 // addb: _891 o: _892 with obitwidth:16
[cast]// renaming _gray_stencil_19 to _878
// _gray_stencil_19 added as input _gray_stencil_19
// added/modified in wire_set: _878 = _gray_stencil_19
[cast]// renaming _gray_stencil_20 to _882
// _gray_stencil_20 added as input _gray_stencil_20
// added/modified in wire_set: _882 = _gray_stencil_20
[cast]// renaming _gray_stencil_21 to _884
// _gray_stencil_21 added as input _gray_stencil_21
// added/modified in wire_set: _884 = _gray_stencil_21
[cast]// renaming _gray_stencil_22 to _887
// _gray_stencil_22 added as input _gray_stencil_22
// added/modified in wire_set: _887 = _gray_stencil_22
[cast]// renaming _gray_stencil_23 to _889
// _gray_stencil_23 added as input _gray_stencil_23
// added/modified in wire_set: _889 = _gray_stencil_23
[cast]// renaming _gray_stencil_24 to _891
// _gray_stencil_24 added as input _gray_stencil_24
// added/modified in wire_set: _891 = _gray_stencil_24
// connected _892 to the output port
}

hcompute_lxy_stencil() {
int16_t _932 = (int16_t)(180);
int16_t _933 = _grad_x_unclamp_stencil_5 <smin> _932;
// _grad_x_unclamp_stencil_5 added as input _grad_x_unclamp_stencil_5
// created const: const_p180__932 with name _932
// smina: self.in // sminb: _932 o: _933 with obitwidth:16
int16_t _934 = (int16_t)(-180);
int16_t _935 = _933 <smax> _934;
// created const: const_n180__934 with name _934
// smaxa: _933 // smaxb: _934 o: _935 with obitwidth:16
int16_t _936 = _grad_y_unclamp_stencil_3 <smin> _932;
// _grad_y_unclamp_stencil_3 added as input _grad_y_unclamp_stencil_3
// created const: const_p180__932$1 with name _932
// smina: self.in // sminb: _932 o: _936 with obitwidth:16
int16_t _937 = _936 <smax> _934;
// created const: const_n180__934$1 with name _934
// smaxa: _936 // smaxb: _934 o: _937 with obitwidth:16
int16_t _938 = _935 * _937;
// mula: _935 // mulb: _937 o: _938 with obitwidth:16
uint16_t _939 = (uint16_t)(6);
int16_t _940 = _938 >> _939;
// created const: const_p6__939 with name _939
// ashra: _938 // ashrb: _939 o: _940 with obitwidth:16
// connected _940 to the output port
}

hcompute_lxy_stencil_1() {
int16_t _964 = (int16_t)(180);
int16_t _965 = _grad_x_unclamp_stencil_6 <smin> _964;
// _grad_x_unclamp_stencil_6 added as input _grad_x_unclamp_stencil_6
// created const: const_p180__964 with name _964
// smina: self.in // sminb: _964 o: _965 with obitwidth:16
int16_t _966 = (int16_t)(-180);
int16_t _967 = _965 <smax> _966;
// created const: const_n180__966 with name _966
// smaxa: _965 // smaxb: _966 o: _967 with obitwidth:16
int16_t _968 = _grad_y_unclamp_stencil_4 <smin> _964;
// _grad_y_unclamp_stencil_4 added as input _grad_y_unclamp_stencil_4
// created const: const_p180__964$1 with name _964
// smina: self.in // sminb: _964 o: _968 with obitwidth:16
int16_t _969 = _968 <smax> _966;
// created const: const_n180__966$1 with name _966
// smaxa: _968 // smaxb: _966 o: _969 with obitwidth:16
int16_t _970 = _967 * _969;
// mula: _967 // mulb: _969 o: _970 with obitwidth:16
uint16_t _971 = (uint16_t)(6);
int16_t _972 = _970 >> _971;
// created const: const_p6__971 with name _971
// ashra: _970 // ashrb: _971 o: _972 with obitwidth:16
// connected _972 to the output port
}

hcompute_lgxy_stencil() {
int16_t _990 = (int16_t)(0);
// created const: const_p0__990 with name _990
// connected _990 to the output port
}

hcompute_lgxy_stencil_1() {
int16_t _996 = (int16_t)(0);
// created const: const_p0__996 with name _996
// connected _996 to the output port
}

hcompute_lgxy_stencil_2() {
int16_t _1012 = _lxy_stencil_8 + _lxy_stencil_9;
// _lxy_stencil_8 added as input _lxy_stencil_8
// _lxy_stencil_9 added as input _lxy_stencil_9
// adda: self.in // addb: self.in o: _1012 with obitwidth:16
int16_t _1013 = _lxy_stencil_7 + _1012;
// _lxy_stencil_7 added as input _lxy_stencil_7
// adda: self.in // addb: _1012 o: _1013 with obitwidth:16
int16_t _1014 = _lxy_stencil_6 + _1013;
// _lxy_stencil_6 added as input _lxy_stencil_6
// adda: self.in // addb: _1013 o: _1014 with obitwidth:16
int16_t _1015 = _lxy_stencil_5 + _1014;
// _lxy_stencil_5 added as input _lxy_stencil_5
// adda: self.in // addb: _1014 o: _1015 with obitwidth:16
int16_t _1016 = _lxy_stencil_4 + _1015;
// _lxy_stencil_4 added as input _lxy_stencil_4
// adda: self.in // addb: _1015 o: _1016 with obitwidth:16
int16_t _1017 = _lxy_stencil_3 + _1016;
// _lxy_stencil_3 added as input _lxy_stencil_3
// adda: self.in // addb: _1016 o: _1017 with obitwidth:16
int16_t _1018 = _lxy_stencil_2 + _1017;
// _lxy_stencil_2 added as input _lxy_stencil_2
// adda: self.in // addb: _1017 o: _1018 with obitwidth:16
int16_t _1019 = _lgxy_stencil_1 + _1018;
// _lgxy_stencil_1 added as input _lgxy_stencil_1
// adda: self.in // addb: _1018 o: _1019 with obitwidth:16
int16_t _1020 = _lxy_stencil_1 + _1019;
// _lxy_stencil_1 added as input _lxy_stencil_1
// adda: self.in // addb: _1019 o: _1020 with obitwidth:16
// connected _1020 to the output port
}

hcompute_lgxy_stencil_3() {
int16_t _1056 = _lxy_stencil_17 + _lxy_stencil_18;
// _lxy_stencil_17 added as input _lxy_stencil_17
// _lxy_stencil_18 added as input _lxy_stencil_18
// adda: self.in // addb: self.in o: _1056 with obitwidth:16
int16_t _1057 = _lxy_stencil_16 + _1056;
// _lxy_stencil_16 added as input _lxy_stencil_16
// adda: self.in // addb: _1056 o: _1057 with obitwidth:16
int16_t _1058 = _lxy_stencil_15 + _1057;
// _lxy_stencil_15 added as input _lxy_stencil_15
// adda: self.in // addb: _1057 o: _1058 with obitwidth:16
int16_t _1059 = _lxy_stencil_14 + _1058;
// _lxy_stencil_14 added as input _lxy_stencil_14
// adda: self.in // addb: _1058 o: _1059 with obitwidth:16
int16_t _1060 = _lxy_stencil_13 + _1059;
// _lxy_stencil_13 added as input _lxy_stencil_13
// adda: self.in // addb: _1059 o: _1060 with obitwidth:16
int16_t _1061 = _lxy_stencil_12 + _1060;
// _lxy_stencil_12 added as input _lxy_stencil_12
// adda: self.in // addb: _1060 o: _1061 with obitwidth:16
int16_t _1062 = _lxy_stencil_11 + _1061;
// _lxy_stencil_11 added as input _lxy_stencil_11
// adda: self.in // addb: _1061 o: _1062 with obitwidth:16
int16_t _1063 = _lgxy_stencil_2 + _1062;
// _lgxy_stencil_2 added as input _lgxy_stencil_2
// adda: self.in // addb: _1062 o: _1063 with obitwidth:16
int16_t _1064 = _lxy_stencil_10 + _1063;
// _lxy_stencil_10 added as input _lxy_stencil_10
// adda: self.in // addb: _1063 o: _1064 with obitwidth:16
// connected _1064 to the output port
}

hcompute_lyy_stencil() {
int16_t _1100 = (int16_t)(180);
int16_t _1101 = _grad_y_unclamp_stencil_5 <smin> _1100;
// _grad_y_unclamp_stencil_5 added as input _grad_y_unclamp_stencil_5
// created const: const_p180__1100 with name _1100
// smina: self.in // sminb: _1100 o: _1101 with obitwidth:16
int16_t _1102 = (int16_t)(-180);
int16_t _1103 = _1101 <smax> _1102;
// created const: const_n180__1102 with name _1102
// smaxa: _1101 // smaxb: _1102 o: _1103 with obitwidth:16
int16_t _1104 = _1103 * _1103;
// mula: _1103 // mulb: _1103 o: _1104 with obitwidth:16
uint16_t _1105 = (uint16_t)(6);
int16_t _1106 = _1104 >> _1105;
// created const: const_p6__1105 with name _1105
// ashra: _1104 // ashrb: _1105 o: _1106 with obitwidth:16
// connected _1106 to the output port
}

hcompute_lyy_stencil_1() {
int16_t _1125 = (int16_t)(180);
int16_t _1126 = _grad_y_unclamp_stencil_6 <smin> _1125;
// _grad_y_unclamp_stencil_6 added as input _grad_y_unclamp_stencil_6
// created const: const_p180__1125 with name _1125
// smina: self.in // sminb: _1125 o: _1126 with obitwidth:16
int16_t _1127 = (int16_t)(-180);
int16_t _1128 = _1126 <smax> _1127;
// created const: const_n180__1127 with name _1127
// smaxa: _1126 // smaxb: _1127 o: _1128 with obitwidth:16
int16_t _1129 = _1128 * _1128;
// mula: _1128 // mulb: _1128 o: _1129 with obitwidth:16
uint16_t _1130 = (uint16_t)(6);
int16_t _1131 = _1129 >> _1130;
// created const: const_p6__1130 with name _1130
// ashra: _1129 // ashrb: _1130 o: _1131 with obitwidth:16
// connected _1131 to the output port
}

hcompute_lgyy_stencil() {
int16_t _1146 = (int16_t)(0);
// created const: const_p0__1146 with name _1146
// connected _1146 to the output port
}

hcompute_lgyy_stencil_1() {
int16_t _1152 = (int16_t)(0);
// created const: const_p0__1152 with name _1152
// connected _1152 to the output port
}

hcompute_lgyy_stencil_2() {
int16_t _1168 = _lyy_stencil_8 + _lyy_stencil_9;
// _lyy_stencil_8 added as input _lyy_stencil_8
// _lyy_stencil_9 added as input _lyy_stencil_9
// adda: self.in // addb: self.in o: _1168 with obitwidth:16
int16_t _1169 = _lyy_stencil_7 + _1168;
// _lyy_stencil_7 added as input _lyy_stencil_7
// adda: self.in // addb: _1168 o: _1169 with obitwidth:16
int16_t _1170 = _lyy_stencil_6 + _1169;
// _lyy_stencil_6 added as input _lyy_stencil_6
// adda: self.in // addb: _1169 o: _1170 with obitwidth:16
int16_t _1171 = _lyy_stencil_5 + _1170;
// _lyy_stencil_5 added as input _lyy_stencil_5
// adda: self.in // addb: _1170 o: _1171 with obitwidth:16
int16_t _1172 = _lyy_stencil_4 + _1171;
// _lyy_stencil_4 added as input _lyy_stencil_4
// adda: self.in // addb: _1171 o: _1172 with obitwidth:16
int16_t _1173 = _lyy_stencil_3 + _1172;
// _lyy_stencil_3 added as input _lyy_stencil_3
// adda: self.in // addb: _1172 o: _1173 with obitwidth:16
int16_t _1174 = _lyy_stencil_2 + _1173;
// _lyy_stencil_2 added as input _lyy_stencil_2
// adda: self.in // addb: _1173 o: _1174 with obitwidth:16
int16_t _1175 = _lgyy_stencil_1 + _1174;
// _lgyy_stencil_1 added as input _lgyy_stencil_1
// adda: self.in // addb: _1174 o: _1175 with obitwidth:16
int16_t _1176 = _lyy_stencil_1 + _1175;
// _lyy_stencil_1 added as input _lyy_stencil_1
// adda: self.in // addb: _1175 o: _1176 with obitwidth:16
// connected _1176 to the output port
}

hcompute_lgyy_stencil_3() {
int16_t _1212 = _lyy_stencil_17 + _lyy_stencil_18;
// _lyy_stencil_17 added as input _lyy_stencil_17
// _lyy_stencil_18 added as input _lyy_stencil_18
// adda: self.in // addb: self.in o: _1212 with obitwidth:16
int16_t _1213 = _lyy_stencil_16 + _1212;
// _lyy_stencil_16 added as input _lyy_stencil_16
// adda: self.in // addb: _1212 o: _1213 with obitwidth:16
int16_t _1214 = _lyy_stencil_15 + _1213;
// _lyy_stencil_15 added as input _lyy_stencil_15
// adda: self.in // addb: _1213 o: _1214 with obitwidth:16
int16_t _1215 = _lyy_stencil_14 + _1214;
// _lyy_stencil_14 added as input _lyy_stencil_14
// adda: self.in // addb: _1214 o: _1215 with obitwidth:16
int16_t _1216 = _lyy_stencil_13 + _1215;
// _lyy_stencil_13 added as input _lyy_stencil_13
// adda: self.in // addb: _1215 o: _1216 with obitwidth:16
int16_t _1217 = _lyy_stencil_12 + _1216;
// _lyy_stencil_12 added as input _lyy_stencil_12
// adda: self.in // addb: _1216 o: _1217 with obitwidth:16
int16_t _1218 = _lyy_stencil_11 + _1217;
// _lyy_stencil_11 added as input _lyy_stencil_11
// adda: self.in // addb: _1217 o: _1218 with obitwidth:16
int16_t _1219 = _lgyy_stencil_2 + _1218;
// _lgyy_stencil_2 added as input _lgyy_stencil_2
// adda: self.in // addb: _1218 o: _1219 with obitwidth:16
int16_t _1220 = _lyy_stencil_10 + _1219;
// _lyy_stencil_10 added as input _lyy_stencil_10
// adda: self.in // addb: _1219 o: _1220 with obitwidth:16
// connected _1220 to the output port
}

hcompute_cim_stencil() {
uint16_t _1261 = (uint16_t)(6);
int16_t _1262 = _lgxx_stencil_3 >> _1261;
// _lgxx_stencil_3 added as input _lgxx_stencil_3
// created const: const_p6__1261 with name _1261
// ashra: self.in // ashrb: _1261 o: _1262 with obitwidth:16
int16_t _1263 = _lgyy_stencil_3 >> _1261;
// _lgyy_stencil_3 added as input _lgyy_stencil_3
// created const: const_p6__1261$1 with name _1261
// ashra: self.in // ashrb: _1261 o: _1263 with obitwidth:16
int16_t _1264 = _1262 * _1263;
// mula: _1262 // mulb: _1263 o: _1264 with obitwidth:16
int16_t _1265 = _lgxy_stencil_3 >> _1261;
// _lgxy_stencil_3 added as input _lgxy_stencil_3
// created const: const_p6__1261$2 with name _1261
// ashra: self.in // ashrb: _1261 o: _1265 with obitwidth:16
int16_t _1266 = _1265 * _1265;
// mula: _1265 // mulb: _1265 o: _1266 with obitwidth:16
int16_t _1267 = _1264 - _1266;
// suba: _1264 // subb: _1266 o: _1267 with obitwidth:16
int16_t _1268 = _1262 + _1263;
// adda: _1262 // addb: _1263 o: _1268 with obitwidth:16
int16_t _1269 = _1268 * _1268;
// mula: _1268 // mulb: _1268 o: _1269 with obitwidth:16
uint16_t _1270 = (uint16_t)(4);
int16_t _1271 = _1269 >> _1270;
// created const: const_p4__1270 with name _1270
// ashra: _1269 // ashrb: _1270 o: _1271 with obitwidth:16
int16_t _1272 = _1267 - _1271;
// suba: _1267 // subb: _1271 o: _1272 with obitwidth:16
// connected _1272 to the output port
}

hcompute_cim_stencil_1() {
uint16_t _1303 = (uint16_t)(6);
int16_t _1304 = _lgxx_stencil_4 >> _1303;
// _lgxx_stencil_4 added as input _lgxx_stencil_4
// created const: const_p6__1303 with name _1303
// ashra: self.in // ashrb: _1303 o: _1304 with obitwidth:16
int16_t _1305 = _lgyy_stencil_4 >> _1303;
// _lgyy_stencil_4 added as input _lgyy_stencil_4
// created const: const_p6__1303$1 with name _1303
// ashra: self.in // ashrb: _1303 o: _1305 with obitwidth:16
int16_t _1306 = _1304 * _1305;
// mula: _1304 // mulb: _1305 o: _1306 with obitwidth:16
int16_t _1307 = _lgxy_stencil_4 >> _1303;
// _lgxy_stencil_4 added as input _lgxy_stencil_4
// created const: const_p6__1303$2 with name _1303
// ashra: self.in // ashrb: _1303 o: _1307 with obitwidth:16
int16_t _1308 = _1307 * _1307;
// mula: _1307 // mulb: _1307 o: _1308 with obitwidth:16
int16_t _1309 = _1306 - _1308;
// suba: _1306 // subb: _1308 o: _1309 with obitwidth:16
int16_t _1310 = _1304 + _1305;
// adda: _1304 // addb: _1305 o: _1310 with obitwidth:16
int16_t _1311 = _1310 * _1310;
// mula: _1310 // mulb: _1310 o: _1311 with obitwidth:16
uint16_t _1312 = (uint16_t)(4);
int16_t _1313 = _1311 >> _1312;
// created const: const_p4__1312 with name _1312
// ashra: _1311 // ashrb: _1312 o: _1313 with obitwidth:16
int16_t _1314 = _1309 - _1313;
// suba: _1309 // subb: _1313 o: _1314 with obitwidth:16
// connected _1314 to the output port
}

hcompute_hw_output_glb_stencil() {
bool _1355 = _cim_stencil_1 s< _cim_stencil_2;
// _cim_stencil_1 added as input _cim_stencil_1
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1355 with obitwidth:1
bool _1356 = _cim_stencil_3 s< _cim_stencil_2;
// _cim_stencil_3 added as input _cim_stencil_3
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1356 with obitwidth:1
bool _1357 = _1355 && _1356;
// bitanda: _1355 // bitandb: _1356 o: _1357 with obitwidth:1
bool _1358 = _cim_stencil_4 s< _cim_stencil_2;
// _cim_stencil_4 added as input _cim_stencil_4
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1358 with obitwidth:1
bool _1359 = _1357 && _1358;
// bitanda: _1357 // bitandb: _1358 o: _1359 with obitwidth:1
bool _1360 = _cim_stencil_5 s< _cim_stencil_2;
// _cim_stencil_5 added as input _cim_stencil_5
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1360 with obitwidth:1
bool _1361 = _1359 && _1360;
// bitanda: _1359 // bitandb: _1360 o: _1361 with obitwidth:1
bool _1362 = _cim_stencil_6 s< _cim_stencil_2;
// _cim_stencil_6 added as input _cim_stencil_6
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1362 with obitwidth:1
bool _1363 = _1361 && _1362;
// bitanda: _1361 // bitandb: _1362 o: _1363 with obitwidth:1
bool _1364 = _cim_stencil_7 s< _cim_stencil_2;
// _cim_stencil_7 added as input _cim_stencil_7
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1364 with obitwidth:1
bool _1365 = _1363 && _1364;
// bitanda: _1363 // bitandb: _1364 o: _1365 with obitwidth:1
bool _1366 = _cim_stencil_8 s< _cim_stencil_2;
// _cim_stencil_8 added as input _cim_stencil_8
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1366 with obitwidth:1
bool _1367 = _1365 && _1366;
// bitanda: _1365 // bitandb: _1366 o: _1367 with obitwidth:1
bool _1368 = _cim_stencil_9 s< _cim_stencil_2;
// _cim_stencil_9 added as input _cim_stencil_9
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _1368 with obitwidth:1
bool _1369 = _1367 && _1368;
// bitanda: _1367 // bitandb: _1368 o: _1369 with obitwidth:1
int16_t _1370 = (int16_t)(1);
bool _1371 = _1370 s<= _cim_stencil_2;
// created const: const_p1__1370 with name _1370
// _cim_stencil_2 added as input _cim_stencil_2
// slea: _1370 // sleb: self.in o: _1371 with obitwidth:1
bool _1372 = _1369 && _1371;
// bitanda: _1369 // bitandb: _1371 o: _1372 with obitwidth:1
int16_t _1373 = (int16_t)(255);
int16_t _1374 = (int16_t)(0);
int16_t _1375 = _1372 ? _1373 : _1374;
// created const: const_p255__1373 with name _1373
// created const: const_p0__1374 with name _1374
// muxa: _1372 // muxb: _1373 // muxc: _1374 o: _1375
// connected _1375 to the output port
}

hcompute_hw_output_glb_stencil_1() {
bool _1432 = _cim_stencil_10 s< _cim_stencil_11;
// _cim_stencil_10 added as input _cim_stencil_10
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1432 with obitwidth:1
bool _1433 = _cim_stencil_12 s< _cim_stencil_11;
// _cim_stencil_12 added as input _cim_stencil_12
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1433 with obitwidth:1
bool _1434 = _1432 && _1433;
// bitanda: _1432 // bitandb: _1433 o: _1434 with obitwidth:1
bool _1435 = _cim_stencil_13 s< _cim_stencil_11;
// _cim_stencil_13 added as input _cim_stencil_13
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1435 with obitwidth:1
bool _1436 = _1434 && _1435;
// bitanda: _1434 // bitandb: _1435 o: _1436 with obitwidth:1
bool _1437 = _cim_stencil_14 s< _cim_stencil_11;
// _cim_stencil_14 added as input _cim_stencil_14
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1437 with obitwidth:1
bool _1438 = _1436 && _1437;
// bitanda: _1436 // bitandb: _1437 o: _1438 with obitwidth:1
bool _1439 = _cim_stencil_15 s< _cim_stencil_11;
// _cim_stencil_15 added as input _cim_stencil_15
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1439 with obitwidth:1
bool _1440 = _1438 && _1439;
// bitanda: _1438 // bitandb: _1439 o: _1440 with obitwidth:1
bool _1441 = _cim_stencil_16 s< _cim_stencil_11;
// _cim_stencil_16 added as input _cim_stencil_16
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1441 with obitwidth:1
bool _1442 = _1440 && _1441;
// bitanda: _1440 // bitandb: _1441 o: _1442 with obitwidth:1
bool _1443 = _cim_stencil_17 s< _cim_stencil_11;
// _cim_stencil_17 added as input _cim_stencil_17
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1443 with obitwidth:1
bool _1444 = _1442 && _1443;
// bitanda: _1442 // bitandb: _1443 o: _1444 with obitwidth:1
bool _1445 = _cim_stencil_18 s< _cim_stencil_11;
// _cim_stencil_18 added as input _cim_stencil_18
// _cim_stencil_11 added as input _cim_stencil_11
// slta: self.in // sltb: self.in o: _1445 with obitwidth:1
bool _1446 = _1444 && _1445;
// bitanda: _1444 // bitandb: _1445 o: _1446 with obitwidth:1
int16_t _1447 = (int16_t)(1);
bool _1448 = _1447 s<= _cim_stencil_11;
// created const: const_p1__1447 with name _1447
// _cim_stencil_11 added as input _cim_stencil_11
// slea: _1447 // sleb: self.in o: _1448 with obitwidth:1
bool _1449 = _1446 && _1448;
// bitanda: _1446 // bitandb: _1448 o: _1449 with obitwidth:1
int16_t _1450 = (int16_t)(255);
int16_t _1451 = (int16_t)(0);
int16_t _1452 = _1449 ? _1450 : _1451;
// created const: const_p255__1450 with name _1450
// created const: const_p0__1451 with name _1451
// muxa: _1449 // muxb: _1450 // muxc: _1451 o: _1452
// connected _1452 to the output port
}

hcompute_hw_output_global_wrapper_stencil() {
// _hw_output_glb_stencil_1 added as input _hw_output_glb_stencil_1
// connected _hw_output_glb_stencil_1 to the output port
}

hcompute_hw_output_global_wrapper_stencil_1() {
// _hw_output_glb_stencil_2 added as input _hw_output_glb_stencil_2
// connected _hw_output_glb_stencil_2 to the output port
}

