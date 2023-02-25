hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_output_stencil() {
int16_t _271 = (int16_t)(100);
bool _272 = _hw_input_global_wrapper_stencil_1 s< _271;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p100__271 with name _271
// slta: self.in // sltb: _271 o: _272 with obitwidth:1
int16_t _273 = (int16_t)(-16);
bool _274 = _273 s< _hw_input_global_wrapper_stencil_1;
// created const: const_n16__273 with name _273
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// slta: _273 // sltb: self.in o: _274 with obitwidth:1
bool _275 = _272 && _274;
// bitanda: _272 // bitandb: _274 o: _275 with obitwidth:1
int16_t _276 = (int16_t)(42);
bool _277 = _hw_input_global_wrapper_stencil_1 s<= _276;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p42__276 with name _276
// slea: self.in // sleb: _276 o: _277 with obitwidth:1
bool _278 = _275 && _277;
// bitanda: _275 // bitandb: _277 o: _278 with obitwidth:1
int16_t _279 = (int16_t)(-1);
bool _280 = _279 s<= _hw_input_global_wrapper_stencil_1;
// created const: const_n1__279 with name _279
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// slea: _279 // sleb: self.in o: _280 with obitwidth:1
bool _281 = _278 && _280;
// bitanda: _278 // bitandb: _280 o: _281 with obitwidth:1
int16_t _282 = (int16_t)(255);
int16_t _283 = (int16_t)(0);
int16_t _284 = _281 ? _282 : _283;
// created const: const_p255__282 with name _282
// created const: const_p0__283 with name _283
// muxa: _281 // muxb: _282 // muxc: _283 o: _284
// connected _284 to the output port
}

