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
uint16_t _269 = (uint16_t)(11);
uint16_t _270 = _hw_input_global_wrapper_stencil_1 * _269;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p11__269 with name _269
// mula: self.in // mulb: _269 o: _270 with obitwidth:16
uint16_t _271 = (uint16_t)(12);
uint16_t _272 = _hw_input_global_wrapper_stencil_2 * _271;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p12__271 with name _271
// mula: self.in // mulb: _271 o: _272 with obitwidth:16
uint16_t _273 = (uint16_t)(14);
uint16_t _274 = _hw_input_global_wrapper_stencil_3 * _273;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p14__273 with name _273
// mula: self.in // mulb: _273 o: _274 with obitwidth:16
uint16_t _275 = _272 + _274;
// adda: _272 // addb: _274 o: _275 with obitwidth:16
uint16_t _276 = _conv_stencil_1 + _275;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _275 o: _276 with obitwidth:16
uint16_t _277 = _270 + _276;
// adda: _270 // addb: _276 o: _277 with obitwidth:16
// connected _277 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_2 added as input _conv_stencil_2
// connected _conv_stencil_2 to the output port
}

