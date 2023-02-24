hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_weight_global_wrapper_stencil() {
// _hw_weight_stencil_1 added as input _hw_weight_stencil_1
// connected _hw_weight_stencil_1 to the output port
}

hcompute_conv_stencil() {
uint16_t _393 = (uint16_t)(0);
// created const: const_p0__393 with name _393
// connected _393 to the output port
}

hcompute_conv_stencil_1() {
uint16_t _413 = _hw_weight_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
// _hw_weight_global_wrapper_stencil_1 added as input _hw_weight_global_wrapper_stencil_1
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// mula: self.in // mulb: self.in o: _413 with obitwidth:16
uint16_t _414 = _hw_weight_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
// _hw_weight_global_wrapper_stencil_2 added as input _hw_weight_global_wrapper_stencil_2
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// mula: self.in // mulb: self.in o: _414 with obitwidth:16
uint16_t _415 = _hw_weight_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
// _hw_weight_global_wrapper_stencil_3 added as input _hw_weight_global_wrapper_stencil_3
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// mula: self.in // mulb: self.in o: _415 with obitwidth:16
uint16_t _416 = _hw_weight_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
// _hw_weight_global_wrapper_stencil_4 added as input _hw_weight_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// mula: self.in // mulb: self.in o: _416 with obitwidth:16
uint16_t _417 = _hw_weight_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
// _hw_weight_global_wrapper_stencil_5 added as input _hw_weight_global_wrapper_stencil_5
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// mula: self.in // mulb: self.in o: _417 with obitwidth:16
uint16_t _418 = _hw_weight_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
// _hw_weight_global_wrapper_stencil_6 added as input _hw_weight_global_wrapper_stencil_6
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// mula: self.in // mulb: self.in o: _418 with obitwidth:16
uint16_t _419 = _hw_weight_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
// _hw_weight_global_wrapper_stencil_7 added as input _hw_weight_global_wrapper_stencil_7
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// mula: self.in // mulb: self.in o: _419 with obitwidth:16
uint16_t _420 = _hw_weight_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
// _hw_weight_global_wrapper_stencil_8 added as input _hw_weight_global_wrapper_stencil_8
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// mula: self.in // mulb: self.in o: _420 with obitwidth:16
uint16_t _421 = _hw_weight_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
// _hw_weight_global_wrapper_stencil_9 added as input _hw_weight_global_wrapper_stencil_9
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// mula: self.in // mulb: self.in o: _421 with obitwidth:16
uint16_t _422 = _420 + _421;
// adda: _420 // addb: _421 o: _422 with obitwidth:16
uint16_t _423 = _419 + _422;
// adda: _419 // addb: _422 o: _423 with obitwidth:16
uint16_t _424 = _418 + _423;
// adda: _418 // addb: _423 o: _424 with obitwidth:16
uint16_t _425 = _417 + _424;
// adda: _417 // addb: _424 o: _425 with obitwidth:16
uint16_t _426 = _416 + _425;
// adda: _416 // addb: _425 o: _426 with obitwidth:16
uint16_t _427 = _415 + _426;
// adda: _415 // addb: _426 o: _427 with obitwidth:16
uint16_t _428 = _414 + _427;
// adda: _414 // addb: _427 o: _428 with obitwidth:16
uint16_t _429 = _conv_stencil_1 + _428;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _428 o: _429 with obitwidth:16
uint16_t _430 = _413 + _429;
// adda: _413 // addb: _429 o: _430 with obitwidth:16
// connected _430 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_2 added as input _conv_stencil_2
// connected _conv_stencil_2 to the output port
}

