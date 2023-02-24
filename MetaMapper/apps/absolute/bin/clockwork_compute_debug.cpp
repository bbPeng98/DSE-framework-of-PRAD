hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_output_stencil() {
[absd] [cast][abs] int16_t _273 = (int16_t)(-100);
int16_t _274 = _hw_input_global_wrapper_stencil_1 + _273;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_n100__273 with name _273
// adda: self.in // addb: _273 o: _274 with obitwidth:16
uint16_t _275 = abs(_274);
// absa: _274 o: _275 with bitwidth:16
int16_t _276 = (int16_t)(_275);
// renaming _275 to _276
// added/modified in wire_set: _276 = _275
int16_t _277 = (int16_t)(30);
uint16_t _278 = _276 |-| _277;
// created const: const_p30__277 with name _277
// absda: _276 // absdb: _277 o: _278 with obitwidth:16
[absd] [cast][abs] // renaming _275 to _276
// added/modified in wire_set: _276 = _275
// connected _278 to the output port
}

