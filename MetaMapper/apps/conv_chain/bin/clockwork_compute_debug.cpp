hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_conv0_stencil() {
uint16_t _258 = (uint16_t)(0);
// created const: const_p0__258 with name _258
// connected _258 to the output port
}

hcompute_conv0_stencil_1() {
uint16_t _286 = (uint16_t)(17);
uint16_t _287 = _hw_input_global_wrapper_stencil_1 * _286;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p17__286 with name _286
// mula: self.in // mulb: _286 o: _287 with obitwidth:16
uint16_t _288 = (uint16_t)(7);
uint16_t _289 = _hw_input_global_wrapper_stencil_2 * _288;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p7__288 with name _288
// mula: self.in // mulb: _288 o: _289 with obitwidth:16
uint16_t _290 = (uint16_t)(5);
uint16_t _291 = _hw_input_global_wrapper_stencil_3 * _290;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p5__290 with name _290
// mula: self.in // mulb: _290 o: _291 with obitwidth:16
uint16_t _292 = (uint16_t)(4);
uint16_t _293 = _hw_input_global_wrapper_stencil_4 * _292;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// created const: const_p4__292 with name _292
// mula: self.in // mulb: _292 o: _293 with obitwidth:16
uint16_t _294 = (uint16_t)(19);
uint16_t _295 = _hw_input_global_wrapper_stencil_5 * _294;
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// created const: const_p19__294 with name _294
// mula: self.in // mulb: _294 o: _295 with obitwidth:16
uint16_t _296 = (uint16_t)(21);
uint16_t _297 = _hw_input_global_wrapper_stencil_6 * _296;
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// created const: const_p21__296 with name _296
// mula: self.in // mulb: _296 o: _297 with obitwidth:16
uint16_t _298 = (uint16_t)(6);
uint16_t _299 = _hw_input_global_wrapper_stencil_7 * _298;
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// created const: const_p6__298 with name _298
// mula: self.in // mulb: _298 o: _299 with obitwidth:16
uint16_t _300 = (uint16_t)(15);
uint16_t _301 = _hw_input_global_wrapper_stencil_8 * _300;
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// created const: const_p15__300 with name _300
// mula: self.in // mulb: _300 o: _301 with obitwidth:16
uint16_t _302 = _hw_input_global_wrapper_stencil_9 * _292;
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// created const: const_p4__292$1 with name _292
// mula: self.in // mulb: _292 o: _302 with obitwidth:16
uint16_t _303 = _301 + _302;
// adda: _301 // addb: _302 o: _303 with obitwidth:16
uint16_t _304 = _299 + _303;
// adda: _299 // addb: _303 o: _304 with obitwidth:16
uint16_t _305 = _297 + _304;
// adda: _297 // addb: _304 o: _305 with obitwidth:16
uint16_t _306 = _295 + _305;
// adda: _295 // addb: _305 o: _306 with obitwidth:16
uint16_t _307 = _293 + _306;
// adda: _293 // addb: _306 o: _307 with obitwidth:16
uint16_t _308 = _291 + _307;
// adda: _291 // addb: _307 o: _308 with obitwidth:16
uint16_t _309 = _289 + _308;
// adda: _289 // addb: _308 o: _309 with obitwidth:16
uint16_t _310 = _conv0_stencil_1 + _309;
// _conv0_stencil_1 added as input _conv0_stencil_1
// adda: self.in // addb: _309 o: _310 with obitwidth:16
uint16_t _311 = _287 + _310;
// adda: _287 // addb: _310 o: _311 with obitwidth:16
// connected _311 to the output port
}

hcompute_conv1_stencil() {
uint16_t _353 = (uint16_t)(0);
// created const: const_p0__353 with name _353
// connected _353 to the output port
}

hcompute_conv1_stencil_1() {
uint16_t _381 = (uint16_t)(17);
uint16_t _382 = _conv0_stencil_2 * _381;
// _conv0_stencil_2 added as input _conv0_stencil_2
// created const: const_p17__381 with name _381
// mula: self.in // mulb: _381 o: _382 with obitwidth:16
uint16_t _383 = (uint16_t)(7);
uint16_t _384 = _conv0_stencil_3 * _383;
// _conv0_stencil_3 added as input _conv0_stencil_3
// created const: const_p7__383 with name _383
// mula: self.in // mulb: _383 o: _384 with obitwidth:16
uint16_t _385 = (uint16_t)(5);
uint16_t _386 = _conv0_stencil_4 * _385;
// _conv0_stencil_4 added as input _conv0_stencil_4
// created const: const_p5__385 with name _385
// mula: self.in // mulb: _385 o: _386 with obitwidth:16
uint16_t _387 = (uint16_t)(4);
uint16_t _388 = _conv0_stencil_5 * _387;
// _conv0_stencil_5 added as input _conv0_stencil_5
// created const: const_p4__387 with name _387
// mula: self.in // mulb: _387 o: _388 with obitwidth:16
uint16_t _389 = (uint16_t)(19);
uint16_t _390 = _conv0_stencil_6 * _389;
// _conv0_stencil_6 added as input _conv0_stencil_6
// created const: const_p19__389 with name _389
// mula: self.in // mulb: _389 o: _390 with obitwidth:16
uint16_t _391 = (uint16_t)(21);
uint16_t _392 = _conv0_stencil_7 * _391;
// _conv0_stencil_7 added as input _conv0_stencil_7
// created const: const_p21__391 with name _391
// mula: self.in // mulb: _391 o: _392 with obitwidth:16
uint16_t _393 = (uint16_t)(6);
uint16_t _394 = _conv0_stencil_8 * _393;
// _conv0_stencil_8 added as input _conv0_stencil_8
// created const: const_p6__393 with name _393
// mula: self.in // mulb: _393 o: _394 with obitwidth:16
uint16_t _395 = (uint16_t)(15);
uint16_t _396 = _conv0_stencil_9 * _395;
// _conv0_stencil_9 added as input _conv0_stencil_9
// created const: const_p15__395 with name _395
// mula: self.in // mulb: _395 o: _396 with obitwidth:16
uint16_t _397 = _conv0_stencil_10 * _387;
// _conv0_stencil_10 added as input _conv0_stencil_10
// created const: const_p4__387$1 with name _387
// mula: self.in // mulb: _387 o: _397 with obitwidth:16
uint16_t _398 = _396 + _397;
// adda: _396 // addb: _397 o: _398 with obitwidth:16
uint16_t _399 = _394 + _398;
// adda: _394 // addb: _398 o: _399 with obitwidth:16
uint16_t _400 = _392 + _399;
// adda: _392 // addb: _399 o: _400 with obitwidth:16
uint16_t _401 = _390 + _400;
// adda: _390 // addb: _400 o: _401 with obitwidth:16
uint16_t _402 = _388 + _401;
// adda: _388 // addb: _401 o: _402 with obitwidth:16
uint16_t _403 = _386 + _402;
// adda: _386 // addb: _402 o: _403 with obitwidth:16
uint16_t _404 = _384 + _403;
// adda: _384 // addb: _403 o: _404 with obitwidth:16
uint16_t _405 = _conv1_stencil_1 + _404;
// _conv1_stencil_1 added as input _conv1_stencil_1
// adda: self.in // addb: _404 o: _405 with obitwidth:16
uint16_t _406 = _382 + _405;
// adda: _382 // addb: _405 o: _406 with obitwidth:16
// connected _406 to the output port
}

hcompute_conv2_stencil() {
uint16_t _448 = (uint16_t)(0);
// created const: const_p0__448 with name _448
// connected _448 to the output port
}

hcompute_conv2_stencil_1() {
uint16_t _476 = (uint16_t)(17);
uint16_t _477 = _conv1_stencil_2 * _476;
// _conv1_stencil_2 added as input _conv1_stencil_2
// created const: const_p17__476 with name _476
// mula: self.in // mulb: _476 o: _477 with obitwidth:16
uint16_t _478 = (uint16_t)(7);
uint16_t _479 = _conv1_stencil_3 * _478;
// _conv1_stencil_3 added as input _conv1_stencil_3
// created const: const_p7__478 with name _478
// mula: self.in // mulb: _478 o: _479 with obitwidth:16
uint16_t _480 = (uint16_t)(5);
uint16_t _481 = _conv1_stencil_4 * _480;
// _conv1_stencil_4 added as input _conv1_stencil_4
// created const: const_p5__480 with name _480
// mula: self.in // mulb: _480 o: _481 with obitwidth:16
uint16_t _482 = (uint16_t)(4);
uint16_t _483 = _conv1_stencil_5 * _482;
// _conv1_stencil_5 added as input _conv1_stencil_5
// created const: const_p4__482 with name _482
// mula: self.in // mulb: _482 o: _483 with obitwidth:16
uint16_t _484 = (uint16_t)(19);
uint16_t _485 = _conv1_stencil_6 * _484;
// _conv1_stencil_6 added as input _conv1_stencil_6
// created const: const_p19__484 with name _484
// mula: self.in // mulb: _484 o: _485 with obitwidth:16
uint16_t _486 = (uint16_t)(21);
uint16_t _487 = _conv1_stencil_7 * _486;
// _conv1_stencil_7 added as input _conv1_stencil_7
// created const: const_p21__486 with name _486
// mula: self.in // mulb: _486 o: _487 with obitwidth:16
uint16_t _488 = (uint16_t)(6);
uint16_t _489 = _conv1_stencil_8 * _488;
// _conv1_stencil_8 added as input _conv1_stencil_8
// created const: const_p6__488 with name _488
// mula: self.in // mulb: _488 o: _489 with obitwidth:16
uint16_t _490 = (uint16_t)(15);
uint16_t _491 = _conv1_stencil_9 * _490;
// _conv1_stencil_9 added as input _conv1_stencil_9
// created const: const_p15__490 with name _490
// mula: self.in // mulb: _490 o: _491 with obitwidth:16
uint16_t _492 = _conv1_stencil_10 * _482;
// _conv1_stencil_10 added as input _conv1_stencil_10
// created const: const_p4__482$1 with name _482
// mula: self.in // mulb: _482 o: _492 with obitwidth:16
uint16_t _493 = _491 + _492;
// adda: _491 // addb: _492 o: _493 with obitwidth:16
uint16_t _494 = _489 + _493;
// adda: _489 // addb: _493 o: _494 with obitwidth:16
uint16_t _495 = _487 + _494;
// adda: _487 // addb: _494 o: _495 with obitwidth:16
uint16_t _496 = _485 + _495;
// adda: _485 // addb: _495 o: _496 with obitwidth:16
uint16_t _497 = _483 + _496;
// adda: _483 // addb: _496 o: _497 with obitwidth:16
uint16_t _498 = _481 + _497;
// adda: _481 // addb: _497 o: _498 with obitwidth:16
uint16_t _499 = _479 + _498;
// adda: _479 // addb: _498 o: _499 with obitwidth:16
uint16_t _500 = _conv2_stencil_1 + _499;
// _conv2_stencil_1 added as input _conv2_stencil_1
// adda: self.in // addb: _499 o: _500 with obitwidth:16
uint16_t _501 = _477 + _500;
// adda: _477 // addb: _500 o: _501 with obitwidth:16
// connected _501 to the output port
}

hcompute_hw_output_stencil() {
// _conv2_stencil_2 added as input _conv2_stencil_2
// connected _conv2_stencil_2 to the output port
}

