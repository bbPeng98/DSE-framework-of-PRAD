hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_brighten_stencil() {
uint16_t _259 = (uint16_t)(2);
uint16_t _260 = _hw_input_global_wrapper_stencil_1 * _259;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p2__259 with name _259
// mula: self.in // mulb: _259 o: _260 with obitwidth:16
// connected _260 to the output port
}

hcompute_blur_stencil() {
uint16_t _265 = (uint16_t)(0);
// created const: const_p0__265 with name _265
// connected _265 to the output port
}

hcompute_blur_stencil_1() {
uint16_t _271 = _brighten_stencil_3 + _brighten_stencil_4;
// _brighten_stencil_3 added as input _brighten_stencil_3
// _brighten_stencil_4 added as input _brighten_stencil_4
// adda: self.in // addb: self.in o: _271 with obitwidth:16
uint16_t _272 = _brighten_stencil_2 + _271;
// _brighten_stencil_2 added as input _brighten_stencil_2
// adda: self.in // addb: _271 o: _272 with obitwidth:16
uint16_t _273 = _blur_stencil_1 + _272;
// _blur_stencil_1 added as input _blur_stencil_1
// adda: self.in // addb: _272 o: _273 with obitwidth:16
uint16_t _274 = _brighten_stencil_1 + _273;
// _brighten_stencil_1 added as input _brighten_stencil_1
// adda: self.in // addb: _273 o: _274 with obitwidth:16
// connected _274 to the output port
}

hcompute_hw_output_stencil() {
uint16_t _288 = (uint16_t)(2);
uint16_t _289 = _blur_stencil_2 >> _288;
// _blur_stencil_2 added as input _blur_stencil_2
// created const: const_p2__288 with name _288
// lshra: self.in // lshrb: _288 o: _289 with obitwidth:16
// connected _289 to the output port
}

