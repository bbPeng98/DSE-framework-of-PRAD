hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_conv_stencil() {
uint16_t _258 = (uint16_t)(0);
// created const: const_p0__258 with name _258
// connected _258 to the output port
}

hcompute_conv_stencil_1() {
uint16_t _287 = (uint16_t)(11);
uint16_t _288 = _hw_input_global_wrapper_stencil_1 * _287;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p11__287 with name _287
// mula: self.in // mulb: _287 o: _288 with obitwidth:16
uint16_t _289 = (uint16_t)(14);
uint16_t _290 = _hw_input_global_wrapper_stencil_2 * _289;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p14__289 with name _289
// mula: self.in // mulb: _289 o: _290 with obitwidth:16
uint16_t _291 = (uint16_t)(17);
uint16_t _292 = _hw_input_global_wrapper_stencil_3 * _291;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p17__291 with name _291
// mula: self.in // mulb: _291 o: _292 with obitwidth:16
uint16_t _293 = (uint16_t)(12);
uint16_t _294 = _hw_input_global_wrapper_stencil_4 * _293;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// created const: const_p12__293 with name _293
// mula: self.in // mulb: _293 o: _294 with obitwidth:16
uint16_t _295 = (uint16_t)(255);
uint16_t _296 = _hw_input_global_wrapper_stencil_5 * _295;
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// created const: const_p255__295 with name _295
// mula: self.in // mulb: _295 o: _296 with obitwidth:16
uint16_t _297 = (uint16_t)(18);
uint16_t _298 = _hw_input_global_wrapper_stencil_6 * _297;
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// created const: const_p18__297 with name _297
// mula: self.in // mulb: _297 o: _298 with obitwidth:16
uint16_t _299 = (uint16_t)(13);
uint16_t _300 = _hw_input_global_wrapper_stencil_7 * _299;
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// created const: const_p13__299 with name _299
// mula: self.in // mulb: _299 o: _300 with obitwidth:16
uint16_t _301 = (uint16_t)(19);
uint16_t _302 = _hw_input_global_wrapper_stencil_8 * _301;
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// created const: const_p19__301 with name _301
// mula: self.in // mulb: _301 o: _302 with obitwidth:16
uint16_t _303 = (uint16_t)(16);
uint16_t _304 = _hw_input_global_wrapper_stencil_9 * _303;
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// created const: const_p16__303 with name _303
// mula: self.in // mulb: _303 o: _304 with obitwidth:16
uint16_t _305 = _302 + _304;
// adda: _302 // addb: _304 o: _305 with obitwidth:16
uint16_t _306 = _300 + _305;
// adda: _300 // addb: _305 o: _306 with obitwidth:16
uint16_t _307 = _298 + _306;
// adda: _298 // addb: _306 o: _307 with obitwidth:16
uint16_t _308 = _296 + _307;
// adda: _296 // addb: _307 o: _308 with obitwidth:16
uint16_t _309 = _294 + _308;
// adda: _294 // addb: _308 o: _309 with obitwidth:16
uint16_t _310 = _292 + _309;
// adda: _292 // addb: _309 o: _310 with obitwidth:16
uint16_t _311 = _290 + _310;
// adda: _290 // addb: _310 o: _311 with obitwidth:16
uint16_t _312 = _conv_stencil_1 + _311;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _311 o: _312 with obitwidth:16
uint16_t _313 = _288 + _312;
// adda: _288 // addb: _312 o: _313 with obitwidth:16
// connected _313 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_2 added as input _conv_stencil_2
// connected _conv_stencil_2 to the output port
}

