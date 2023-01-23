hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_conv_stencil() {
uint16_t _319 = (uint16_t)(0);
// created const: const_p0__319 with name _319
// connected _319 to the output port
}

hcompute_conv_stencil_1() {
// adding coreir inst kernela0
[cast]int32_t _395 = _conv_s1_z * 9;
// _conv_s1_z added as input _conv_s1_z
// created const: const_p9_9 with name 9
// mula: self.in // mulb: 9 o: _395 with obitwidth:32
int32_t _396 = ((int32_t *)_kernela0)[_395][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0
[cast]int32_t _397 = (int32_t)(_hw_input_global_wrapper_stencil_1);
// renaming _hw_input_global_wrapper_stencil_1 to _397
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// added/modified in wire_set: _397 = _hw_input_global_wrapper_stencil_1
int32_t _398 = _396 * _397;
// mula: _396 // mulb: _397 o: _398 with obitwidth:32
uint16_t _399 = (uint16_t)(_398);
// renaming _398 to _399
// added/modified in wire_set: _399 = _398
uint16_t _400 = _conv_stencil_1 + _399;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _399 o: _400 with obitwidth:16
[cast]int32_t _401 = _395 + 1;
// created const: const_p1_1 with name 1
// adda: _395 // addb: 1 o: _401 with obitwidth:32
int32_t _402 = ((int32_t *)_kernela0)[_401][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$1
[cast]int32_t _403 = (int32_t)(_hw_input_global_wrapper_stencil_2);
// renaming _hw_input_global_wrapper_stencil_2 to _403
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// added/modified in wire_set: _403 = _hw_input_global_wrapper_stencil_2
int32_t _404 = _402 * _403;
// mula: _402 // mulb: _403 o: _404 with obitwidth:32
uint16_t _405 = (uint16_t)(_404);
// renaming _404 to _405
// added/modified in wire_set: _405 = _404
uint16_t _406 = _400 + _405;
// adda: _400 // addb: _405 o: _406 with obitwidth:16
[cast]int32_t _407 = _395 + 2;
// created const: const_p2_2 with name 2
// adda: _395 // addb: 2 o: _407 with obitwidth:32
int32_t _408 = ((int32_t *)_kernela0)[_407][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$2
[cast]int32_t _409 = (int32_t)(_hw_input_global_wrapper_stencil_3);
// renaming _hw_input_global_wrapper_stencil_3 to _409
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// added/modified in wire_set: _409 = _hw_input_global_wrapper_stencil_3
int32_t _410 = _408 * _409;
// mula: _408 // mulb: _409 o: _410 with obitwidth:32
uint16_t _411 = (uint16_t)(_410);
// renaming _410 to _411
// added/modified in wire_set: _411 = _410
uint16_t _412 = _406 + _411;
// adda: _406 // addb: _411 o: _412 with obitwidth:16
[cast]int32_t _413 = _395 + 3;
// created const: const_p3_3 with name 3
// adda: _395 // addb: 3 o: _413 with obitwidth:32
int32_t _414 = ((int32_t *)_kernela0)[_413][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$3
[cast]int32_t _415 = (int32_t)(_hw_input_global_wrapper_stencil_4);
// renaming _hw_input_global_wrapper_stencil_4 to _415
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// added/modified in wire_set: _415 = _hw_input_global_wrapper_stencil_4
int32_t _416 = _414 * _415;
// mula: _414 // mulb: _415 o: _416 with obitwidth:32
uint16_t _417 = (uint16_t)(_416);
// renaming _416 to _417
// added/modified in wire_set: _417 = _416
uint16_t _418 = _412 + _417;
// adda: _412 // addb: _417 o: _418 with obitwidth:16
[cast]int32_t _419 = _395 + 4;
// created const: const_p4_4 with name 4
// adda: _395 // addb: 4 o: _419 with obitwidth:32
int32_t _420 = ((int32_t *)_kernela0)[_419][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$4
[cast]int32_t _421 = (int32_t)(_hw_input_global_wrapper_stencil_5);
// renaming _hw_input_global_wrapper_stencil_5 to _421
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// added/modified in wire_set: _421 = _hw_input_global_wrapper_stencil_5
int32_t _422 = _420 * _421;
// mula: _420 // mulb: _421 o: _422 with obitwidth:32
uint16_t _423 = (uint16_t)(_422);
// renaming _422 to _423
// added/modified in wire_set: _423 = _422
uint16_t _424 = _418 + _423;
// adda: _418 // addb: _423 o: _424 with obitwidth:16
[cast]int32_t _425 = _395 + 5;
// created const: const_p5_5 with name 5
// adda: _395 // addb: 5 o: _425 with obitwidth:32
int32_t _426 = ((int32_t *)_kernela0)[_425][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$5
[cast]int32_t _427 = (int32_t)(_hw_input_global_wrapper_stencil_6);
// renaming _hw_input_global_wrapper_stencil_6 to _427
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// added/modified in wire_set: _427 = _hw_input_global_wrapper_stencil_6
int32_t _428 = _426 * _427;
// mula: _426 // mulb: _427 o: _428 with obitwidth:32
uint16_t _429 = (uint16_t)(_428);
// renaming _428 to _429
// added/modified in wire_set: _429 = _428
uint16_t _430 = _424 + _429;
// adda: _424 // addb: _429 o: _430 with obitwidth:16
[cast]int32_t _431 = _395 + 6;
// created const: const_p6_6 with name 6
// adda: _395 // addb: 6 o: _431 with obitwidth:32
int32_t _432 = ((int32_t *)_kernela0)[_431][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$6
[cast]int32_t _433 = (int32_t)(_hw_input_global_wrapper_stencil_7);
// renaming _hw_input_global_wrapper_stencil_7 to _433
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// added/modified in wire_set: _433 = _hw_input_global_wrapper_stencil_7
int32_t _434 = _432 * _433;
// mula: _432 // mulb: _433 o: _434 with obitwidth:32
uint16_t _435 = (uint16_t)(_434);
// renaming _434 to _435
// added/modified in wire_set: _435 = _434
uint16_t _436 = _430 + _435;
// adda: _430 // addb: _435 o: _436 with obitwidth:16
[cast]int32_t _437 = _395 + 7;
// created const: const_p7_7 with name 7
// adda: _395 // addb: 7 o: _437 with obitwidth:32
int32_t _438 = ((int32_t *)_kernela0)[_437][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$7
[cast]int32_t _439 = (int32_t)(_hw_input_global_wrapper_stencil_8);
// renaming _hw_input_global_wrapper_stencil_8 to _439
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// added/modified in wire_set: _439 = _hw_input_global_wrapper_stencil_8
int32_t _440 = _438 * _439;
// mula: _438 // mulb: _439 o: _440 with obitwidth:32
uint16_t _441 = (uint16_t)(_440);
// renaming _440 to _441
// added/modified in wire_set: _441 = _440
uint16_t _442 = _436 + _441;
// adda: _436 // addb: _441 o: _442 with obitwidth:16
[cast]int32_t _443 = _395 + 8;
// created const: const_p8_8 with name 8
// adda: _395 // addb: 8 o: _443 with obitwidth:32
int32_t _444 = ((int32_t *)_kernela0)[_443][load];
// loading from rom kernela0 with gen memory.rom2
// created rom named rom_kernela0$8
[cast]int32_t _445 = (int32_t)(_hw_input_global_wrapper_stencil_9);
// renaming _hw_input_global_wrapper_stencil_9 to _445
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// added/modified in wire_set: _445 = _hw_input_global_wrapper_stencil_9
int32_t _446 = _444 * _445;
// mula: _444 // mulb: _445 o: _446 with obitwidth:32
uint16_t _447 = (uint16_t)(_446);
// renaming _446 to _447
// added/modified in wire_set: _447 = _446
uint16_t _448 = _442 + _447;
// adda: _442 // addb: _447 o: _448 with obitwidth:16
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_1 to _397
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// added/modified in wire_set: _397 = _hw_input_global_wrapper_stencil_1
// renaming _398 to _399
// added/modified in wire_set: _399 = _398
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_2 to _403
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// added/modified in wire_set: _403 = _hw_input_global_wrapper_stencil_2
// renaming _404 to _405
// added/modified in wire_set: _405 = _404
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_3 to _409
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// added/modified in wire_set: _409 = _hw_input_global_wrapper_stencil_3
// renaming _410 to _411
// added/modified in wire_set: _411 = _410
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_4 to _415
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// added/modified in wire_set: _415 = _hw_input_global_wrapper_stencil_4
// renaming _416 to _417
// added/modified in wire_set: _417 = _416
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_5 to _421
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// added/modified in wire_set: _421 = _hw_input_global_wrapper_stencil_5
// renaming _422 to _423
// added/modified in wire_set: _423 = _422
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_6 to _427
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// added/modified in wire_set: _427 = _hw_input_global_wrapper_stencil_6
// renaming _428 to _429
// added/modified in wire_set: _429 = _428
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_7 to _433
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// added/modified in wire_set: _433 = _hw_input_global_wrapper_stencil_7
// renaming _434 to _435
// added/modified in wire_set: _435 = _434
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_8 to _439
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// added/modified in wire_set: _439 = _hw_input_global_wrapper_stencil_8
// renaming _440 to _441
// added/modified in wire_set: _441 = _440
[cast]// loading from rom kernela0 with gen memory.rom2
[cast]// renaming _hw_input_global_wrapper_stencil_9 to _445
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// added/modified in wire_set: _445 = _hw_input_global_wrapper_stencil_9
// renaming _446 to _447
// added/modified in wire_set: _447 = _446
// connected _448 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_2 added as input _conv_stencil_2
// connected _conv_stencil_2 to the output port
}

