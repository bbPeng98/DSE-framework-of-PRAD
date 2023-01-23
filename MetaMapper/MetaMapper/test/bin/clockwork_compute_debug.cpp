hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_conv1_stencil() {
uint16_t _258 = (uint16_t)(0);
// created const: const_p0__258 with name _258
// connected _258 to the output port
}

hcompute_conv1_stencil_1() {
uint16_t _276 = (uint16_t)(2);
uint16_t _277 = _hw_input_global_wrapper_stencil_2 * _276;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p2__276 with name _276
// mula: self.in // mulb: _276 o: _277 with obitwidth:16
uint16_t _278 = _hw_input_global_wrapper_stencil_4 * _276;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// created const: const_p2__276$1 with name _276
// mula: self.in // mulb: _276 o: _278 with obitwidth:16
uint16_t _279 = (uint16_t)(4);
uint16_t _280 = _hw_input_global_wrapper_stencil_5 * _279;
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// created const: const_p4__279 with name _279
// mula: self.in // mulb: _279 o: _280 with obitwidth:16
uint16_t _281 = _hw_input_global_wrapper_stencil_6 * _276;
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// created const: const_p2__276$2 with name _276
// mula: self.in // mulb: _276 o: _281 with obitwidth:16
uint16_t _282 = _hw_input_global_wrapper_stencil_9 * _276;
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// created const: const_p2__276$3 with name _276
// mula: self.in // mulb: _276 o: _282 with obitwidth:16
uint16_t _283 = _hw_input_global_wrapper_stencil_8 + _282;
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// adda: self.in // addb: _282 o: _283 with obitwidth:16
uint16_t _284 = _hw_input_global_wrapper_stencil_7 + _283;
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// adda: self.in // addb: _283 o: _284 with obitwidth:16
uint16_t _285 = _281 + _284;
// adda: _281 // addb: _284 o: _285 with obitwidth:16
uint16_t _286 = _280 + _285;
// adda: _280 // addb: _285 o: _286 with obitwidth:16
uint16_t _287 = _278 + _286;
// adda: _278 // addb: _286 o: _287 with obitwidth:16
uint16_t _288 = _hw_input_global_wrapper_stencil_3 + _287;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// adda: self.in // addb: _287 o: _288 with obitwidth:16
uint16_t _289 = _277 + _288;
// adda: _277 // addb: _288 o: _289 with obitwidth:16
uint16_t _290 = _conv1_stencil_1 + _289;
// _conv1_stencil_1 added as input _conv1_stencil_1
// adda: self.in // addb: _289 o: _290 with obitwidth:16
uint16_t _291 = _hw_input_global_wrapper_stencil_1 + _290;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// adda: self.in // addb: _290 o: _291 with obitwidth:16
// connected _291 to the output port
}

hcompute_conv1_shift_stencil() {
uint16_t _324 = (uint16_t)(4);
uint16_t _325 = _conv1_stencil_2 >> _324;
// _conv1_stencil_2 added as input _conv1_stencil_2
// created const: const_p4__324 with name _324
// lshra: self.in // lshrb: _324 o: _325 with obitwidth:16
// connected _325 to the output port
}

hcompute_conv2_stencil() {
uint16_t _330 = (uint16_t)(0);
// created const: const_p0__330 with name _330
// connected _330 to the output port
}

hcompute_conv2_stencil_1() {
uint16_t _348 = (uint16_t)(2);
uint16_t _349 = _conv1_shift_stencil_2 * _348;
// _conv1_shift_stencil_2 added as input _conv1_shift_stencil_2
// created const: const_p2__348 with name _348
// mula: self.in // mulb: _348 o: _349 with obitwidth:16
uint16_t _350 = _conv1_shift_stencil_4 * _348;
// _conv1_shift_stencil_4 added as input _conv1_shift_stencil_4
// created const: const_p2__348$1 with name _348
// mula: self.in // mulb: _348 o: _350 with obitwidth:16
uint16_t _351 = (uint16_t)(4);
uint16_t _352 = _conv1_shift_stencil_5 * _351;
// _conv1_shift_stencil_5 added as input _conv1_shift_stencil_5
// created const: const_p4__351 with name _351
// mula: self.in // mulb: _351 o: _352 with obitwidth:16
uint16_t _353 = _conv1_shift_stencil_6 * _348;
// _conv1_shift_stencil_6 added as input _conv1_shift_stencil_6
// created const: const_p2__348$2 with name _348
// mula: self.in // mulb: _348 o: _353 with obitwidth:16
uint16_t _354 = _conv1_shift_stencil_9 * _348;
// _conv1_shift_stencil_9 added as input _conv1_shift_stencil_9
// created const: const_p2__348$3 with name _348
// mula: self.in // mulb: _348 o: _354 with obitwidth:16
uint16_t _355 = _conv1_shift_stencil_8 + _354;
// _conv1_shift_stencil_8 added as input _conv1_shift_stencil_8
// adda: self.in // addb: _354 o: _355 with obitwidth:16
uint16_t _356 = _conv1_shift_stencil_7 + _355;
// _conv1_shift_stencil_7 added as input _conv1_shift_stencil_7
// adda: self.in // addb: _355 o: _356 with obitwidth:16
uint16_t _357 = _353 + _356;
// adda: _353 // addb: _356 o: _357 with obitwidth:16
uint16_t _358 = _352 + _357;
// adda: _352 // addb: _357 o: _358 with obitwidth:16
uint16_t _359 = _350 + _358;
// adda: _350 // addb: _358 o: _359 with obitwidth:16
uint16_t _360 = _conv1_shift_stencil_3 + _359;
// _conv1_shift_stencil_3 added as input _conv1_shift_stencil_3
// adda: self.in // addb: _359 o: _360 with obitwidth:16
uint16_t _361 = _349 + _360;
// adda: _349 // addb: _360 o: _361 with obitwidth:16
uint16_t _362 = _conv2_stencil_1 + _361;
// _conv2_stencil_1 added as input _conv2_stencil_1
// adda: self.in // addb: _361 o: _362 with obitwidth:16
uint16_t _363 = _conv1_shift_stencil_1 + _362;
// _conv1_shift_stencil_1 added as input _conv1_shift_stencil_1
// adda: self.in // addb: _362 o: _363 with obitwidth:16
// connected _363 to the output port
}

hcompute_hw_output_stencil() {
uint16_t _396 = (uint16_t)(4);
uint16_t _397 = _conv2_stencil_2 >> _396;
// _conv2_stencil_2 added as input _conv2_stencil_2
// created const: const_p4__396 with name _396
// lshra: self.in // lshrb: _396 o: _397 with obitwidth:16
// connected _397 to the output port
}

