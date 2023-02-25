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
uint16_t _281 = (uint16_t)(11);
uint16_t _282 = _hw_input_global_wrapper_stencil_1 * _281;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p11__281 with name _281
// mula: self.in // mulb: _281 o: _282 with obitwidth:16
uint16_t _283 = (uint16_t)(17);
uint16_t _284 = _hw_input_global_wrapper_stencil_2 * _283;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p17__283 with name _283
// mula: self.in // mulb: _283 o: _284 with obitwidth:16
uint16_t _285 = (uint16_t)(12);
uint16_t _286 = _hw_input_global_wrapper_stencil_3 * _285;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p12__285 with name _285
// mula: self.in // mulb: _285 o: _286 with obitwidth:16
uint16_t _287 = (uint16_t)(18);
uint16_t _288 = _hw_input_global_wrapper_stencil_4 * _287;
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// created const: const_p18__287 with name _287
// mula: self.in // mulb: _287 o: _288 with obitwidth:16
uint16_t _289 = (uint16_t)(13);
uint16_t _290 = _hw_input_global_wrapper_stencil_5 * _289;
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// created const: const_p13__289 with name _289
// mula: self.in // mulb: _289 o: _290 with obitwidth:16
uint16_t _291 = (uint16_t)(19);
uint16_t _292 = _hw_input_global_wrapper_stencil_6 * _291;
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// created const: const_p19__291 with name _291
// mula: self.in // mulb: _291 o: _292 with obitwidth:16
uint16_t _293 = (uint16_t)(16);
uint16_t _294 = _hw_input_global_wrapper_stencil_7 * _293;
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// created const: const_p16__293 with name _293
// mula: self.in // mulb: _293 o: _294 with obitwidth:16
uint16_t _295 = _292 + _294;
// adda: _292 // addb: _294 o: _295 with obitwidth:16
uint16_t _296 = _290 + _295;
// adda: _290 // addb: _295 o: _296 with obitwidth:16
uint16_t _297 = _288 + _296;
// adda: _288 // addb: _296 o: _297 with obitwidth:16
uint16_t _298 = _286 + _297;
// adda: _286 // addb: _297 o: _298 with obitwidth:16
uint16_t _299 = _284 + _298;
// adda: _284 // addb: _298 o: _299 with obitwidth:16
uint16_t _300 = _conv_stencil_1 + _299;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _299 o: _300 with obitwidth:16
uint16_t _301 = _282 + _300;
// adda: _282 // addb: _300 o: _301 with obitwidth:16
// connected _301 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_2 added as input _conv_stencil_2
// connected _conv_stencil_2 to the output port
}

