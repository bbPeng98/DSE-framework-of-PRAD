hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_kernel_global_wrapper_stencil() {
// _hw_kernel_stencil_1 added as input _hw_kernel_stencil_1
// connected _hw_kernel_stencil_1 to the output port
}

hcompute_conv_stencil() {
int16_t _672 = (int16_t)(0);
// created const: const_p0__672 with name _672
// connected _672 to the output port
}

hcompute_conv_stencil_1() {
int16_t _675 = (int16_t)(0);
// created const: const_p0__675 with name _675
// connected _675 to the output port
}

hcompute_conv_stencil_2() {
int16_t _678 = (int16_t)(0);
// created const: const_p0__678 with name _678
// connected _678 to the output port
}

hcompute_conv_stencil_3() {
int16_t _696 = _hw_kernel_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
// _hw_kernel_global_wrapper_stencil_1 added as input _hw_kernel_global_wrapper_stencil_1
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// mula: self.in // mulb: self.in o: _696 with obitwidth:16
int16_t _697 = _hw_kernel_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
// _hw_kernel_global_wrapper_stencil_2 added as input _hw_kernel_global_wrapper_stencil_2
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// mula: self.in // mulb: self.in o: _697 with obitwidth:16
int16_t _698 = _hw_kernel_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
// _hw_kernel_global_wrapper_stencil_3 added as input _hw_kernel_global_wrapper_stencil_3
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// mula: self.in // mulb: self.in o: _698 with obitwidth:16
int16_t _699 = _hw_kernel_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
// _hw_kernel_global_wrapper_stencil_4 added as input _hw_kernel_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// mula: self.in // mulb: self.in o: _699 with obitwidth:16
int16_t _700 = _hw_kernel_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
// _hw_kernel_global_wrapper_stencil_5 added as input _hw_kernel_global_wrapper_stencil_5
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// mula: self.in // mulb: self.in o: _700 with obitwidth:16
int16_t _701 = _hw_kernel_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
// _hw_kernel_global_wrapper_stencil_6 added as input _hw_kernel_global_wrapper_stencil_6
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// mula: self.in // mulb: self.in o: _701 with obitwidth:16
int16_t _702 = _hw_kernel_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
// _hw_kernel_global_wrapper_stencil_7 added as input _hw_kernel_global_wrapper_stencil_7
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// mula: self.in // mulb: self.in o: _702 with obitwidth:16
int16_t _703 = _hw_kernel_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
// _hw_kernel_global_wrapper_stencil_8 added as input _hw_kernel_global_wrapper_stencil_8
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// mula: self.in // mulb: self.in o: _703 with obitwidth:16
int16_t _704 = _702 + _703;
// adda: _702 // addb: _703 o: _704 with obitwidth:16
int16_t _705 = _701 + _704;
// adda: _701 // addb: _704 o: _705 with obitwidth:16
int16_t _706 = _700 + _705;
// adda: _700 // addb: _705 o: _706 with obitwidth:16
int16_t _707 = _699 + _706;
// adda: _699 // addb: _706 o: _707 with obitwidth:16
int16_t _708 = _698 + _707;
// adda: _698 // addb: _707 o: _708 with obitwidth:16
int16_t _709 = _697 + _708;
// adda: _697 // addb: _708 o: _709 with obitwidth:16
int16_t _710 = _conv_stencil_1 + _709;
// _conv_stencil_1 added as input _conv_stencil_1
// adda: self.in // addb: _709 o: _710 with obitwidth:16
int16_t _711 = _696 + _710;
// adda: _696 // addb: _710 o: _711 with obitwidth:16
// connected _711 to the output port
}

hcompute_conv_stencil_4() {
int16_t _763 = _hw_kernel_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
// _hw_kernel_global_wrapper_stencil_9 added as input _hw_kernel_global_wrapper_stencil_9
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// mula: self.in // mulb: self.in o: _763 with obitwidth:16
int16_t _764 = _hw_kernel_global_wrapper_stencil_10 * _hw_input_global_wrapper_stencil_10;
// _hw_kernel_global_wrapper_stencil_10 added as input _hw_kernel_global_wrapper_stencil_10
// _hw_input_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_stencil_10
// mula: self.in // mulb: self.in o: _764 with obitwidth:16
int16_t _765 = _hw_kernel_global_wrapper_stencil_11 * _hw_input_global_wrapper_stencil_11;
// _hw_kernel_global_wrapper_stencil_11 added as input _hw_kernel_global_wrapper_stencil_11
// _hw_input_global_wrapper_stencil_11 added as input _hw_input_global_wrapper_stencil_11
// mula: self.in // mulb: self.in o: _765 with obitwidth:16
int16_t _766 = _hw_kernel_global_wrapper_stencil_12 * _hw_input_global_wrapper_stencil_12;
// _hw_kernel_global_wrapper_stencil_12 added as input _hw_kernel_global_wrapper_stencil_12
// _hw_input_global_wrapper_stencil_12 added as input _hw_input_global_wrapper_stencil_12
// mula: self.in // mulb: self.in o: _766 with obitwidth:16
int16_t _767 = _hw_kernel_global_wrapper_stencil_13 * _hw_input_global_wrapper_stencil_13;
// _hw_kernel_global_wrapper_stencil_13 added as input _hw_kernel_global_wrapper_stencil_13
// _hw_input_global_wrapper_stencil_13 added as input _hw_input_global_wrapper_stencil_13
// mula: self.in // mulb: self.in o: _767 with obitwidth:16
int16_t _768 = _hw_kernel_global_wrapper_stencil_14 * _hw_input_global_wrapper_stencil_14;
// _hw_kernel_global_wrapper_stencil_14 added as input _hw_kernel_global_wrapper_stencil_14
// _hw_input_global_wrapper_stencil_14 added as input _hw_input_global_wrapper_stencil_14
// mula: self.in // mulb: self.in o: _768 with obitwidth:16
int16_t _769 = _hw_kernel_global_wrapper_stencil_15 * _hw_input_global_wrapper_stencil_15;
// _hw_kernel_global_wrapper_stencil_15 added as input _hw_kernel_global_wrapper_stencil_15
// _hw_input_global_wrapper_stencil_15 added as input _hw_input_global_wrapper_stencil_15
// mula: self.in // mulb: self.in o: _769 with obitwidth:16
int16_t _770 = _hw_kernel_global_wrapper_stencil_16 * _hw_input_global_wrapper_stencil_16;
// _hw_kernel_global_wrapper_stencil_16 added as input _hw_kernel_global_wrapper_stencil_16
// _hw_input_global_wrapper_stencil_16 added as input _hw_input_global_wrapper_stencil_16
// mula: self.in // mulb: self.in o: _770 with obitwidth:16
int16_t _771 = _769 + _770;
// adda: _769 // addb: _770 o: _771 with obitwidth:16
int16_t _772 = _768 + _771;
// adda: _768 // addb: _771 o: _772 with obitwidth:16
int16_t _773 = _767 + _772;
// adda: _767 // addb: _772 o: _773 with obitwidth:16
int16_t _774 = _766 + _773;
// adda: _766 // addb: _773 o: _774 with obitwidth:16
int16_t _775 = _765 + _774;
// adda: _765 // addb: _774 o: _775 with obitwidth:16
int16_t _776 = _764 + _775;
// adda: _764 // addb: _775 o: _776 with obitwidth:16
int16_t _777 = _conv_stencil_2 + _776;
// _conv_stencil_2 added as input _conv_stencil_2
// adda: self.in // addb: _776 o: _777 with obitwidth:16
int16_t _778 = _763 + _777;
// adda: _763 // addb: _777 o: _778 with obitwidth:16
// connected _778 to the output port
}

hcompute_conv_stencil_5() {
int16_t _830 = _hw_kernel_global_wrapper_stencil_17 * _hw_input_global_wrapper_stencil_17;
// _hw_kernel_global_wrapper_stencil_17 added as input _hw_kernel_global_wrapper_stencil_17
// _hw_input_global_wrapper_stencil_17 added as input _hw_input_global_wrapper_stencil_17
// mula: self.in // mulb: self.in o: _830 with obitwidth:16
int16_t _831 = _hw_kernel_global_wrapper_stencil_18 * _hw_input_global_wrapper_stencil_18;
// _hw_kernel_global_wrapper_stencil_18 added as input _hw_kernel_global_wrapper_stencil_18
// _hw_input_global_wrapper_stencil_18 added as input _hw_input_global_wrapper_stencil_18
// mula: self.in // mulb: self.in o: _831 with obitwidth:16
int16_t _832 = _hw_kernel_global_wrapper_stencil_19 * _hw_input_global_wrapper_stencil_19;
// _hw_kernel_global_wrapper_stencil_19 added as input _hw_kernel_global_wrapper_stencil_19
// _hw_input_global_wrapper_stencil_19 added as input _hw_input_global_wrapper_stencil_19
// mula: self.in // mulb: self.in o: _832 with obitwidth:16
int16_t _833 = _hw_kernel_global_wrapper_stencil_20 * _hw_input_global_wrapper_stencil_20;
// _hw_kernel_global_wrapper_stencil_20 added as input _hw_kernel_global_wrapper_stencil_20
// _hw_input_global_wrapper_stencil_20 added as input _hw_input_global_wrapper_stencil_20
// mula: self.in // mulb: self.in o: _833 with obitwidth:16
int16_t _834 = _hw_kernel_global_wrapper_stencil_21 * _hw_input_global_wrapper_stencil_21;
// _hw_kernel_global_wrapper_stencil_21 added as input _hw_kernel_global_wrapper_stencil_21
// _hw_input_global_wrapper_stencil_21 added as input _hw_input_global_wrapper_stencil_21
// mula: self.in // mulb: self.in o: _834 with obitwidth:16
int16_t _835 = _hw_kernel_global_wrapper_stencil_22 * _hw_input_global_wrapper_stencil_22;
// _hw_kernel_global_wrapper_stencil_22 added as input _hw_kernel_global_wrapper_stencil_22
// _hw_input_global_wrapper_stencil_22 added as input _hw_input_global_wrapper_stencil_22
// mula: self.in // mulb: self.in o: _835 with obitwidth:16
int16_t _836 = _hw_kernel_global_wrapper_stencil_23 * _hw_input_global_wrapper_stencil_23;
// _hw_kernel_global_wrapper_stencil_23 added as input _hw_kernel_global_wrapper_stencil_23
// _hw_input_global_wrapper_stencil_23 added as input _hw_input_global_wrapper_stencil_23
// mula: self.in // mulb: self.in o: _836 with obitwidth:16
int16_t _837 = _hw_kernel_global_wrapper_stencil_24 * _hw_input_global_wrapper_stencil_24;
// _hw_kernel_global_wrapper_stencil_24 added as input _hw_kernel_global_wrapper_stencil_24
// _hw_input_global_wrapper_stencil_24 added as input _hw_input_global_wrapper_stencil_24
// mula: self.in // mulb: self.in o: _837 with obitwidth:16
int16_t _838 = _836 + _837;
// adda: _836 // addb: _837 o: _838 with obitwidth:16
int16_t _839 = _835 + _838;
// adda: _835 // addb: _838 o: _839 with obitwidth:16
int16_t _840 = _834 + _839;
// adda: _834 // addb: _839 o: _840 with obitwidth:16
int16_t _841 = _833 + _840;
// adda: _833 // addb: _840 o: _841 with obitwidth:16
int16_t _842 = _832 + _841;
// adda: _832 // addb: _841 o: _842 with obitwidth:16
int16_t _843 = _831 + _842;
// adda: _831 // addb: _842 o: _843 with obitwidth:16
int16_t _844 = _conv_stencil_3 + _843;
// _conv_stencil_3 added as input _conv_stencil_3
// adda: self.in // addb: _843 o: _844 with obitwidth:16
int16_t _845 = _830 + _844;
// adda: _830 // addb: _844 o: _845 with obitwidth:16
// connected _845 to the output port
}

hcompute_hw_output_stencil() {
int16_t _883 = (int16_t)(0);
int16_t _884 = _conv_stencil_4 <smax> _883;
// _conv_stencil_4 added as input _conv_stencil_4
// created const: const_p0__883 with name _883
// smaxa: self.in // smaxb: _883 o: _884 with obitwidth:16
// connected _884 to the output port
}

