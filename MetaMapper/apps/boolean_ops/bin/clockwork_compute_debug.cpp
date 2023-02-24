hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_output_stencil() {
uint16_t _266 = (uint16_t)(64);
bool _267 = _hw_input_global_wrapper_stencil_1 < _266;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p64__266 with name _266
// ulta: self.in // ultb: _266 o: _267 with obitwidth:1
uint16_t _268 = (uint16_t)(128);
bool _269 = _268 <= _hw_input_global_wrapper_stencil_1;
// created const: const_p128__268 with name _268
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// ulea: _268 // uleb: self.in o: _269 with obitwidth:1
bool _270 = _267 || _269;
// bitora: _267 // bitorb: _269 o: _270 with obitwidth:1
bool _271 = _270 ^ _269;
// bitxora: _270 // bitxorb: _269 o: _271 with obitwidth:1
int16_t _272 = (int16_t)(200);
int16_t _273 = (int16_t)(0);
int16_t _274 = _271 ? _272 : _273;
// created const: const_p200__272 with name _272
// created const: const_p0__273 with name _273
// muxa: _271 // muxb: _272 // muxc: _273 o: _274
// connected _274 to the output port
}

