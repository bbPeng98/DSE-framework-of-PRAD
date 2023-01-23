hcompute_padded16_global_wrapper_stencil() {
// _padded16_stencil_1 added as input _padded16_stencil_1
// connected _padded16_stencil_1 to the output port
}

hcompute_grad_x_unclamp_stencil() {
int16_t _264 = (int16_t)(0);
// created const: const_p0__264 with name _264
// connected _264 to the output port
}

hcompute_grad_x_unclamp_stencil_1() {
int16_t _277 = (int16_t)(2);
int16_t _278 = _padded16_global_wrapper_stencil_3 * _277;
// _padded16_global_wrapper_stencil_3 added as input _padded16_global_wrapper_stencil_3
// created const: const_p2__277 with name _277
// mula: self.in // mulb: _277 o: _278 with obitwidth:16
int16_t _279 = _padded16_global_wrapper_stencil_2 + _278;
// _padded16_global_wrapper_stencil_2 added as input _padded16_global_wrapper_stencil_2
// adda: self.in // addb: _278 o: _279 with obitwidth:16
int16_t _280 = _padded16_global_wrapper_stencil_1 + _279;
// _padded16_global_wrapper_stencil_1 added as input _padded16_global_wrapper_stencil_1
// adda: self.in // addb: _279 o: _280 with obitwidth:16
int16_t _281 = _grad_x_unclamp_stencil_1 + _280;
// _grad_x_unclamp_stencil_1 added as input _grad_x_unclamp_stencil_1
// adda: self.in // addb: _280 o: _281 with obitwidth:16
int16_t _282 = _281 - _padded16_global_wrapper_stencil_4;
// _padded16_global_wrapper_stencil_4 added as input _padded16_global_wrapper_stencil_4
// suba: _281 // subb: self.in o: _282 with obitwidth:16
int16_t _283 = _padded16_global_wrapper_stencil_5 * _277;
// _padded16_global_wrapper_stencil_5 added as input _padded16_global_wrapper_stencil_5
// created const: const_p2__277$1 with name _277
// mula: self.in // mulb: _277 o: _283 with obitwidth:16
int16_t _284 = _282 - _283;
// suba: _282 // subb: _283 o: _284 with obitwidth:16
int16_t _285 = _284 - _padded16_global_wrapper_stencil_6;
// _padded16_global_wrapper_stencil_6 added as input _padded16_global_wrapper_stencil_6
// suba: _284 // subb: self.in o: _285 with obitwidth:16
// connected _285 to the output port
}

hcompute_lxx_stencil() {
int16_t _314 = (int16_t)(180);
int16_t _315 = _grad_x_unclamp_stencil_2 <smin> _314;
// _grad_x_unclamp_stencil_2 added as input _grad_x_unclamp_stencil_2
// created const: const_p180__314 with name _314
// smina: self.in // sminb: _314 o: _315 with obitwidth:16
int16_t _316 = (int16_t)(-180);
int16_t _317 = _315 <smax> _316;
// created const: const_n180__316 with name _316
// smaxa: _315 // smaxb: _316 o: _317 with obitwidth:16
int16_t _318 = _317 * _317;
// mula: _317 // mulb: _317 o: _318 with obitwidth:16
uint16_t _319 = (uint16_t)(6);
int16_t _320 = _318 >> _319;
// created const: const_p6__319 with name _319
// ashra: _318 // ashrb: _319 o: _320 with obitwidth:16
// connected _320 to the output port
}

hcompute_lgxx_stencil() {
int16_t _332 = (int16_t)(0);
// created const: const_p0__332 with name _332
// connected _332 to the output port
}

hcompute_lgxx_stencil_1() {
int16_t _345 = _lxx_stencil_8 + _lxx_stencil_9;
// _lxx_stencil_8 added as input _lxx_stencil_8
// _lxx_stencil_9 added as input _lxx_stencil_9
// adda: self.in // addb: self.in o: _345 with obitwidth:16
int16_t _346 = _lxx_stencil_7 + _345;
// _lxx_stencil_7 added as input _lxx_stencil_7
// adda: self.in // addb: _345 o: _346 with obitwidth:16
int16_t _347 = _lxx_stencil_6 + _346;
// _lxx_stencil_6 added as input _lxx_stencil_6
// adda: self.in // addb: _346 o: _347 with obitwidth:16
int16_t _348 = _lxx_stencil_5 + _347;
// _lxx_stencil_5 added as input _lxx_stencil_5
// adda: self.in // addb: _347 o: _348 with obitwidth:16
int16_t _349 = _lxx_stencil_4 + _348;
// _lxx_stencil_4 added as input _lxx_stencil_4
// adda: self.in // addb: _348 o: _349 with obitwidth:16
int16_t _350 = _lxx_stencil_3 + _349;
// _lxx_stencil_3 added as input _lxx_stencil_3
// adda: self.in // addb: _349 o: _350 with obitwidth:16
int16_t _351 = _lxx_stencil_2 + _350;
// _lxx_stencil_2 added as input _lxx_stencil_2
// adda: self.in // addb: _350 o: _351 with obitwidth:16
int16_t _352 = _lgxx_stencil_1 + _351;
// _lgxx_stencil_1 added as input _lgxx_stencil_1
// adda: self.in // addb: _351 o: _352 with obitwidth:16
int16_t _353 = _lxx_stencil_1 + _352;
// _lxx_stencil_1 added as input _lxx_stencil_1
// adda: self.in // addb: _352 o: _353 with obitwidth:16
// connected _353 to the output port
}

hcompute_grad_y_unclamp_stencil() {
int16_t _380 = (int16_t)(0);
// created const: const_p0__380 with name _380
// connected _380 to the output port
}

hcompute_grad_y_unclamp_stencil_1() {
int16_t _393 = (int16_t)(2);
int16_t _394 = _padded16_global_wrapper_stencil_9 * _393;
// _padded16_global_wrapper_stencil_9 added as input _padded16_global_wrapper_stencil_9
// created const: const_p2__393 with name _393
// mula: self.in // mulb: _393 o: _394 with obitwidth:16
int16_t _395 = _padded16_global_wrapper_stencil_8 + _394;
// _padded16_global_wrapper_stencil_8 added as input _padded16_global_wrapper_stencil_8
// adda: self.in // addb: _394 o: _395 with obitwidth:16
int16_t _396 = _padded16_global_wrapper_stencil_7 + _395;
// _padded16_global_wrapper_stencil_7 added as input _padded16_global_wrapper_stencil_7
// adda: self.in // addb: _395 o: _396 with obitwidth:16
int16_t _397 = _grad_y_unclamp_stencil_1 + _396;
// _grad_y_unclamp_stencil_1 added as input _grad_y_unclamp_stencil_1
// adda: self.in // addb: _396 o: _397 with obitwidth:16
int16_t _398 = _397 - _padded16_global_wrapper_stencil_10;
// _padded16_global_wrapper_stencil_10 added as input _padded16_global_wrapper_stencil_10
// suba: _397 // subb: self.in o: _398 with obitwidth:16
int16_t _399 = _padded16_global_wrapper_stencil_11 * _393;
// _padded16_global_wrapper_stencil_11 added as input _padded16_global_wrapper_stencil_11
// created const: const_p2__393$1 with name _393
// mula: self.in // mulb: _393 o: _399 with obitwidth:16
int16_t _400 = _398 - _399;
// suba: _398 // subb: _399 o: _400 with obitwidth:16
int16_t _401 = _400 - _padded16_global_wrapper_stencil_12;
// _padded16_global_wrapper_stencil_12 added as input _padded16_global_wrapper_stencil_12
// suba: _400 // subb: self.in o: _401 with obitwidth:16
// connected _401 to the output port
}

hcompute_lxy_stencil() {
int16_t _432 = (int16_t)(180);
int16_t _433 = _grad_x_unclamp_stencil_3 <smin> _432;
// _grad_x_unclamp_stencil_3 added as input _grad_x_unclamp_stencil_3
// created const: const_p180__432 with name _432
// smina: self.in // sminb: _432 o: _433 with obitwidth:16
int16_t _434 = (int16_t)(-180);
int16_t _435 = _433 <smax> _434;
// created const: const_n180__434 with name _434
// smaxa: _433 // smaxb: _434 o: _435 with obitwidth:16
int16_t _436 = _grad_y_unclamp_stencil_2 <smin> _432;
// _grad_y_unclamp_stencil_2 added as input _grad_y_unclamp_stencil_2
// created const: const_p180__432$1 with name _432
// smina: self.in // sminb: _432 o: _436 with obitwidth:16
int16_t _437 = _436 <smax> _434;
// created const: const_n180__434$1 with name _434
// smaxa: _436 // smaxb: _434 o: _437 with obitwidth:16
int16_t _438 = _435 * _437;
// mula: _435 // mulb: _437 o: _438 with obitwidth:16
uint16_t _439 = (uint16_t)(6);
int16_t _440 = _438 >> _439;
// created const: const_p6__439 with name _439
// ashra: _438 // ashrb: _439 o: _440 with obitwidth:16
// connected _440 to the output port
}

hcompute_lgxy_stencil() {
int16_t _455 = (int16_t)(0);
// created const: const_p0__455 with name _455
// connected _455 to the output port
}

hcompute_lgxy_stencil_1() {
int16_t _468 = _lxy_stencil_8 + _lxy_stencil_9;
// _lxy_stencil_8 added as input _lxy_stencil_8
// _lxy_stencil_9 added as input _lxy_stencil_9
// adda: self.in // addb: self.in o: _468 with obitwidth:16
int16_t _469 = _lxy_stencil_7 + _468;
// _lxy_stencil_7 added as input _lxy_stencil_7
// adda: self.in // addb: _468 o: _469 with obitwidth:16
int16_t _470 = _lxy_stencil_6 + _469;
// _lxy_stencil_6 added as input _lxy_stencil_6
// adda: self.in // addb: _469 o: _470 with obitwidth:16
int16_t _471 = _lxy_stencil_5 + _470;
// _lxy_stencil_5 added as input _lxy_stencil_5
// adda: self.in // addb: _470 o: _471 with obitwidth:16
int16_t _472 = _lxy_stencil_4 + _471;
// _lxy_stencil_4 added as input _lxy_stencil_4
// adda: self.in // addb: _471 o: _472 with obitwidth:16
int16_t _473 = _lxy_stencil_3 + _472;
// _lxy_stencil_3 added as input _lxy_stencil_3
// adda: self.in // addb: _472 o: _473 with obitwidth:16
int16_t _474 = _lxy_stencil_2 + _473;
// _lxy_stencil_2 added as input _lxy_stencil_2
// adda: self.in // addb: _473 o: _474 with obitwidth:16
int16_t _475 = _lgxy_stencil_1 + _474;
// _lgxy_stencil_1 added as input _lgxy_stencil_1
// adda: self.in // addb: _474 o: _475 with obitwidth:16
int16_t _476 = _lxy_stencil_1 + _475;
// _lxy_stencil_1 added as input _lxy_stencil_1
// adda: self.in // addb: _475 o: _476 with obitwidth:16
// connected _476 to the output port
}

hcompute_lyy_stencil() {
int16_t _509 = (int16_t)(180);
int16_t _510 = _grad_y_unclamp_stencil_3 <smin> _509;
// _grad_y_unclamp_stencil_3 added as input _grad_y_unclamp_stencil_3
// created const: const_p180__509 with name _509
// smina: self.in // sminb: _509 o: _510 with obitwidth:16
int16_t _511 = (int16_t)(-180);
int16_t _512 = _510 <smax> _511;
// created const: const_n180__511 with name _511
// smaxa: _510 // smaxb: _511 o: _512 with obitwidth:16
int16_t _513 = _512 * _512;
// mula: _512 // mulb: _512 o: _513 with obitwidth:16
uint16_t _514 = (uint16_t)(6);
int16_t _515 = _513 >> _514;
// created const: const_p6__514 with name _514
// ashra: _513 // ashrb: _514 o: _515 with obitwidth:16
// connected _515 to the output port
}

hcompute_lgyy_stencil() {
int16_t _527 = (int16_t)(0);
// created const: const_p0__527 with name _527
// connected _527 to the output port
}

hcompute_lgyy_stencil_1() {
int16_t _540 = _lyy_stencil_8 + _lyy_stencil_9;
// _lyy_stencil_8 added as input _lyy_stencil_8
// _lyy_stencil_9 added as input _lyy_stencil_9
// adda: self.in // addb: self.in o: _540 with obitwidth:16
int16_t _541 = _lyy_stencil_7 + _540;
// _lyy_stencil_7 added as input _lyy_stencil_7
// adda: self.in // addb: _540 o: _541 with obitwidth:16
int16_t _542 = _lyy_stencil_6 + _541;
// _lyy_stencil_6 added as input _lyy_stencil_6
// adda: self.in // addb: _541 o: _542 with obitwidth:16
int16_t _543 = _lyy_stencil_5 + _542;
// _lyy_stencil_5 added as input _lyy_stencil_5
// adda: self.in // addb: _542 o: _543 with obitwidth:16
int16_t _544 = _lyy_stencil_4 + _543;
// _lyy_stencil_4 added as input _lyy_stencil_4
// adda: self.in // addb: _543 o: _544 with obitwidth:16
int16_t _545 = _lyy_stencil_3 + _544;
// _lyy_stencil_3 added as input _lyy_stencil_3
// adda: self.in // addb: _544 o: _545 with obitwidth:16
int16_t _546 = _lyy_stencil_2 + _545;
// _lyy_stencil_2 added as input _lyy_stencil_2
// adda: self.in // addb: _545 o: _546 with obitwidth:16
int16_t _547 = _lgyy_stencil_1 + _546;
// _lgyy_stencil_1 added as input _lgyy_stencil_1
// adda: self.in // addb: _546 o: _547 with obitwidth:16
int16_t _548 = _lyy_stencil_1 + _547;
// _lyy_stencil_1 added as input _lyy_stencil_1
// adda: self.in // addb: _547 o: _548 with obitwidth:16
// connected _548 to the output port
}

hcompute_cim_stencil() {
uint16_t _586 = (uint16_t)(6);
int16_t _587 = _lgxx_stencil_2 >> _586;
// _lgxx_stencil_2 added as input _lgxx_stencil_2
// created const: const_p6__586 with name _586
// ashra: self.in // ashrb: _586 o: _587 with obitwidth:16
int16_t _588 = _lgyy_stencil_2 >> _586;
// _lgyy_stencil_2 added as input _lgyy_stencil_2
// created const: const_p6__586$1 with name _586
// ashra: self.in // ashrb: _586 o: _588 with obitwidth:16
int16_t _589 = _587 * _588;
// mula: _587 // mulb: _588 o: _589 with obitwidth:16
int16_t _590 = _lgxy_stencil_2 >> _586;
// _lgxy_stencil_2 added as input _lgxy_stencil_2
// created const: const_p6__586$2 with name _586
// ashra: self.in // ashrb: _586 o: _590 with obitwidth:16
int16_t _591 = _590 * _590;
// mula: _590 // mulb: _590 o: _591 with obitwidth:16
int16_t _592 = _589 - _591;
// suba: _589 // subb: _591 o: _592 with obitwidth:16
int16_t _593 = _587 + _588;
// adda: _587 // addb: _588 o: _593 with obitwidth:16
int16_t _594 = _593 * _593;
// mula: _593 // mulb: _593 o: _594 with obitwidth:16
uint16_t _595 = (uint16_t)(4);
int16_t _596 = _594 >> _595;
// created const: const_p4__595 with name _595
// ashra: _594 // ashrb: _595 o: _596 with obitwidth:16
int16_t _597 = _592 - _596;
// suba: _592 // subb: _596 o: _597 with obitwidth:16
// connected _597 to the output port
}

hcompute_cim_output_stencil() {
[cast]bool _635 = _cim_stencil_1 s< _cim_stencil_2;
// _cim_stencil_1 added as input _cim_stencil_1
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _635 with obitwidth:1
bool _636 = _cim_stencil_3 s< _cim_stencil_2;
// _cim_stencil_3 added as input _cim_stencil_3
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _636 with obitwidth:1
bool _637 = _635 && _636;
// bitanda: _635 // bitandb: _636 o: _637 with obitwidth:1
bool _638 = _cim_stencil_4 s< _cim_stencil_2;
// _cim_stencil_4 added as input _cim_stencil_4
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _638 with obitwidth:1
bool _639 = _637 && _638;
// bitanda: _637 // bitandb: _638 o: _639 with obitwidth:1
bool _640 = _cim_stencil_5 s< _cim_stencil_2;
// _cim_stencil_5 added as input _cim_stencil_5
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _640 with obitwidth:1
bool _641 = _639 && _640;
// bitanda: _639 // bitandb: _640 o: _641 with obitwidth:1
bool _642 = _cim_stencil_6 s< _cim_stencil_2;
// _cim_stencil_6 added as input _cim_stencil_6
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _642 with obitwidth:1
bool _643 = _641 && _642;
// bitanda: _641 // bitandb: _642 o: _643 with obitwidth:1
bool _644 = _cim_stencil_7 s< _cim_stencil_2;
// _cim_stencil_7 added as input _cim_stencil_7
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _644 with obitwidth:1
bool _645 = _643 && _644;
// bitanda: _643 // bitandb: _644 o: _645 with obitwidth:1
bool _646 = _cim_stencil_8 s< _cim_stencil_2;
// _cim_stencil_8 added as input _cim_stencil_8
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _646 with obitwidth:1
bool _647 = _645 && _646;
// bitanda: _645 // bitandb: _646 o: _647 with obitwidth:1
bool _648 = _cim_stencil_9 s< _cim_stencil_2;
// _cim_stencil_9 added as input _cim_stencil_9
// _cim_stencil_2 added as input _cim_stencil_2
// slta: self.in // sltb: self.in o: _648 with obitwidth:1
bool _649 = _647 && _648;
// bitanda: _647 // bitandb: _648 o: _649 with obitwidth:1
int16_t _650 = (int16_t)(1);
bool _651 = _650 s<= _cim_stencil_2;
// created const: const_p1__650 with name _650
// _cim_stencil_2 added as input _cim_stencil_2
// slea: _650 // sleb: self.in o: _651 with obitwidth:1
bool _652 = _649 && _651;
// bitanda: _649 // bitandb: _651 o: _652 with obitwidth:1
int32_t _653 = _652 ? 255 : 0;
// created const: const_p255_255 with name 255
// created const: const_p0_0 with name 0
// muxa: _652 // muxb: 255 // muxc: 0 o: _653
int16_t _654 = (int16_t)(_653);
// renaming _653 to _654
// added/modified in wire_set: _654 = _653
[cast]// renaming _653 to _654
// added/modified in wire_set: _654 = _653
// connected _654 to the output port
}

hcompute_hw_output_stencil() {
// _cim_output_stencil_1 added as input _cim_output_stencil_1
// connected _cim_output_stencil_1 to the output port
}

