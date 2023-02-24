hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_kernel_global_wrapper_stencil() {
// _hw_kernel_stencil_1 added as input _hw_kernel_stencil_1
// connected _hw_kernel_stencil_1 to the output port
}

hcompute_conv_stencil() {
uint16_t _667 = (uint16_t)(0);
// created const: const_p0__667 with name _667
// connected _667 to the output port
}

hcompute_conv_stencil_1() {
uint16_t _670 = (uint16_t)(0);
// created const: const_p0__670 with name _670
// connected _670 to the output port
}

hcompute_conv_stencil_2() {
uint16_t _673 = (uint16_t)(0);
// created const: const_p0__673 with name _673
// connected _673 to the output port
}

hcompute_conv_stencil_3() {
uint16_t _683 = _hw_kernel_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
// _hw_kernel_global_wrapper_stencil_1 added as input _hw_kernel_global_wrapper_stencil_1
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// mula: self.in // mulb: self.in o: _683 with obitwidth:16
uint16_t _684 = _hw_kernel_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
// _hw_kernel_global_wrapper_stencil_2 added as input _hw_kernel_global_wrapper_stencil_2
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// mula: self.in // mulb: self.in o: _684 with obitwidth:16
uint16_t _685 = _hw_kernel_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
// _hw_kernel_global_wrapper_stencil_3 added as input _hw_kernel_global_wrapper_stencil_3
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// mula: self.in // mulb: self.in o: _685 with obitwidth:16
uint16_t _686 = _hw_kernel_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
// _hw_kernel_global_wrapper_stencil_4 added as input _hw_kernel_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// mula: self.in // mulb: self.in o: _686 with obitwidth:16
uint16_t _687 = _685 + _686;
// adda: _685 // addb: _686 o: _687 with obitwidth:16
uint16_t _688 = _684 + _687;
// adda: _684 // addb: _687 o: _688 with obitwidth:16
uint16_t _689 = _conv_stencil_1 + _688;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _688 o: _689 with obitwidth:16
uint16_t _690 = _683 + _689;
// adda: _683 // addb: _689 o: _690 with obitwidth:16
// connected _690 to the output port
}

hcompute_conv_stencil_4() {
uint16_t _718 = _hw_kernel_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
// _hw_kernel_global_wrapper_stencil_5 added as input _hw_kernel_global_wrapper_stencil_5
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// mula: self.in // mulb: self.in o: _718 with obitwidth:16
uint16_t _719 = _hw_kernel_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
// _hw_kernel_global_wrapper_stencil_6 added as input _hw_kernel_global_wrapper_stencil_6
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// mula: self.in // mulb: self.in o: _719 with obitwidth:16
uint16_t _720 = _hw_kernel_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
// _hw_kernel_global_wrapper_stencil_7 added as input _hw_kernel_global_wrapper_stencil_7
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// mula: self.in // mulb: self.in o: _720 with obitwidth:16
uint16_t _721 = _hw_kernel_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
// _hw_kernel_global_wrapper_stencil_8 added as input _hw_kernel_global_wrapper_stencil_8
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// mula: self.in // mulb: self.in o: _721 with obitwidth:16
uint16_t _722 = _720 + _721;
// adda: _720 // addb: _721 o: _722 with obitwidth:16
uint16_t _723 = _719 + _722;
// adda: _719 // addb: _722 o: _723 with obitwidth:16
uint16_t _724 = _conv_stencil_2 + _723;
// _conv_stencil_2 added as input _conv_stencil_2
// adda: self.in // addb: _723 o: _724 with obitwidth:16
uint16_t _725 = _718 + _724;
// adda: _718 // addb: _724 o: _725 with obitwidth:16
// connected _725 to the output port
}

hcompute_conv_stencil_5() {
uint16_t _753 = _hw_kernel_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
// _hw_kernel_global_wrapper_stencil_9 added as input _hw_kernel_global_wrapper_stencil_9
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// mula: self.in // mulb: self.in o: _753 with obitwidth:16
uint16_t _754 = _hw_kernel_global_wrapper_stencil_10 * _hw_input_global_wrapper_stencil_10;
// _hw_kernel_global_wrapper_stencil_10 added as input _hw_kernel_global_wrapper_stencil_10
// _hw_input_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_stencil_10
// mula: self.in // mulb: self.in o: _754 with obitwidth:16
uint16_t _755 = _hw_kernel_global_wrapper_stencil_11 * _hw_input_global_wrapper_stencil_11;
// _hw_kernel_global_wrapper_stencil_11 added as input _hw_kernel_global_wrapper_stencil_11
// _hw_input_global_wrapper_stencil_11 added as input _hw_input_global_wrapper_stencil_11
// mula: self.in // mulb: self.in o: _755 with obitwidth:16
uint16_t _756 = _hw_kernel_global_wrapper_stencil_12 * _hw_input_global_wrapper_stencil_12;
// _hw_kernel_global_wrapper_stencil_12 added as input _hw_kernel_global_wrapper_stencil_12
// _hw_input_global_wrapper_stencil_12 added as input _hw_input_global_wrapper_stencil_12
// mula: self.in // mulb: self.in o: _756 with obitwidth:16
uint16_t _757 = _755 + _756;
// adda: _755 // addb: _756 o: _757 with obitwidth:16
uint16_t _758 = _754 + _757;
// adda: _754 // addb: _757 o: _758 with obitwidth:16
uint16_t _759 = _conv_stencil_3 + _758;
// _conv_stencil_3 added as input _conv_stencil_3
// adda: self.in // addb: _758 o: _759 with obitwidth:16
uint16_t _760 = _753 + _759;
// adda: _753 // addb: _759 o: _760 with obitwidth:16
// connected _760 to the output port
}

hcompute_hw_output_stencil() {
// _conv_stencil_4 added as input _conv_stencil_4
// connected _conv_stencil_4 to the output port
}

hcompute_hw_output_stencil_1() {
// _conv_stencil_5 added as input _conv_stencil_5
// connected _conv_stencil_5 to the output port
}

hcompute_hw_output_stencil_2() {
// _conv_stencil_6 added as input _conv_stencil_6
// connected _conv_stencil_6 to the output port
}

