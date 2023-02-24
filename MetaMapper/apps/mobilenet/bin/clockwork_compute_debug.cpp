hcompute_hw_filter_dw_global_wrapper_stencil() {
// _hw_filter_dw_stencil_1 added as input _hw_filter_dw_stencil_1
// connected _hw_filter_dw_stencil_1 to the output port
}

hcompute_hw_filter_dw_global_wrapper_stencil_1() {
// _hw_filter_dw_stencil_2 added as input _hw_filter_dw_stencil_2
// connected _hw_filter_dw_stencil_2 to the output port
}

hcompute_hw_filter_dw_global_wrapper_stencil_2() {
// _hw_filter_dw_stencil_3 added as input _hw_filter_dw_stencil_3
// connected _hw_filter_dw_stencil_3 to the output port
}

hcompute_hw_filter_dw_global_wrapper_stencil_3() {
// _hw_filter_dw_stencil_4 added as input _hw_filter_dw_stencil_4
// connected _hw_filter_dw_stencil_4 to the output port
}

hcompute_hw_input_global_wrapper_stencil() {
// _hw_input_stencil_1 added as input _hw_input_stencil_1
// connected _hw_input_stencil_1 to the output port
}

hcompute_hw_input_global_wrapper_stencil_1() {
// _hw_input_stencil_2 added as input _hw_input_stencil_2
// connected _hw_input_stencil_2 to the output port
}

hcompute_hw_input_global_wrapper_stencil_2() {
// _hw_input_stencil_3 added as input _hw_input_stencil_3
// connected _hw_input_stencil_3 to the output port
}

hcompute_hw_input_global_wrapper_stencil_3() {
// _hw_input_stencil_4 added as input _hw_input_stencil_4
// connected _hw_input_stencil_4 to the output port
}

hcompute_dw_conv_stencil() {
int16_t _739 = (int16_t)(0);
// created const: const_p0__739 with name _739
// connected _739 to the output port
}

hcompute_dw_conv_stencil_1() {
int16_t _742 = (int16_t)(0);
// created const: const_p0__742 with name _742
// connected _742 to the output port
}

hcompute_dw_conv_stencil_2() {
int16_t _745 = (int16_t)(0);
// created const: const_p0__745 with name _745
// connected _745 to the output port
}

hcompute_dw_conv_stencil_3() {
int16_t _748 = (int16_t)(0);
// created const: const_p0__748$1 with name _748
// connected _748 to the output port
}

hcompute_dw_conv_stencil_4() {
int16_t _768 = _hw_filter_dw_global_wrapper_stencil_1 * _hw_input_global_wrapper_stencil_1;
// _hw_filter_dw_global_wrapper_stencil_1 added as input _hw_filter_dw_global_wrapper_stencil_1
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// mula: self.in // mulb: self.in o: _768 with obitwidth:16
int16_t _769 = _hw_filter_dw_global_wrapper_stencil_2 * _hw_input_global_wrapper_stencil_2;
// _hw_filter_dw_global_wrapper_stencil_2 added as input _hw_filter_dw_global_wrapper_stencil_2
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// mula: self.in // mulb: self.in o: _769 with obitwidth:16
int16_t _770 = _hw_filter_dw_global_wrapper_stencil_3 * _hw_input_global_wrapper_stencil_3;
// _hw_filter_dw_global_wrapper_stencil_3 added as input _hw_filter_dw_global_wrapper_stencil_3
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// mula: self.in // mulb: self.in o: _770 with obitwidth:16
int16_t _771 = _hw_filter_dw_global_wrapper_stencil_4 * _hw_input_global_wrapper_stencil_4;
// _hw_filter_dw_global_wrapper_stencil_4 added as input _hw_filter_dw_global_wrapper_stencil_4
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// mula: self.in // mulb: self.in o: _771 with obitwidth:16
int16_t _772 = _hw_filter_dw_global_wrapper_stencil_5 * _hw_input_global_wrapper_stencil_5;
// _hw_filter_dw_global_wrapper_stencil_5 added as input _hw_filter_dw_global_wrapper_stencil_5
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// mula: self.in // mulb: self.in o: _772 with obitwidth:16
int16_t _773 = _hw_filter_dw_global_wrapper_stencil_6 * _hw_input_global_wrapper_stencil_6;
// _hw_filter_dw_global_wrapper_stencil_6 added as input _hw_filter_dw_global_wrapper_stencil_6
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// mula: self.in // mulb: self.in o: _773 with obitwidth:16
int16_t _774 = _hw_filter_dw_global_wrapper_stencil_7 * _hw_input_global_wrapper_stencil_7;
// _hw_filter_dw_global_wrapper_stencil_7 added as input _hw_filter_dw_global_wrapper_stencil_7
// _hw_input_global_wrapper_stencil_7 added as input _hw_input_global_wrapper_stencil_7
// mula: self.in // mulb: self.in o: _774 with obitwidth:16
int16_t _775 = _hw_filter_dw_global_wrapper_stencil_8 * _hw_input_global_wrapper_stencil_8;
// _hw_filter_dw_global_wrapper_stencil_8 added as input _hw_filter_dw_global_wrapper_stencil_8
// _hw_input_global_wrapper_stencil_8 added as input _hw_input_global_wrapper_stencil_8
// mula: self.in // mulb: self.in o: _775 with obitwidth:16
int16_t _776 = _hw_filter_dw_global_wrapper_stencil_9 * _hw_input_global_wrapper_stencil_9;
// _hw_filter_dw_global_wrapper_stencil_9 added as input _hw_filter_dw_global_wrapper_stencil_9
// _hw_input_global_wrapper_stencil_9 added as input _hw_input_global_wrapper_stencil_9
// mula: self.in // mulb: self.in o: _776 with obitwidth:16
int16_t _777 = _775 + _776;
// adda: _775 // addb: _776 o: _777 with obitwidth:16
int16_t _778 = _774 + _777;
// adda: _774 // addb: _777 o: _778 with obitwidth:16
int16_t _779 = _773 + _778;
// adda: _773 // addb: _778 o: _779 with obitwidth:16
int16_t _780 = _772 + _779;
// adda: _772 // addb: _779 o: _780 with obitwidth:16
int16_t _781 = _771 + _780;
// adda: _771 // addb: _780 o: _781 with obitwidth:16
int16_t _782 = _770 + _781;
// adda: _770 // addb: _781 o: _782 with obitwidth:16
int16_t _783 = _769 + _782;
// adda: _769 // addb: _782 o: _783 with obitwidth:16
int16_t _784 = _dw_conv_stencil_1 + _783;
// _dw_conv_stencil_1 added as input _dw_conv_stencil_1
// adda: self.in // addb: _783 o: _784 with obitwidth:16
int16_t _785 = _768 + _784;
// adda: _768 // addb: _784 o: _785 with obitwidth:16
// connected _785 to the output port
}

hcompute_dw_conv_stencil_5() {
int16_t _845 = _hw_filter_dw_global_wrapper_stencil_10 * _hw_input_global_wrapper_stencil_10;
// _hw_filter_dw_global_wrapper_stencil_10 added as input _hw_filter_dw_global_wrapper_stencil_10
// _hw_input_global_wrapper_stencil_10 added as input _hw_input_global_wrapper_stencil_10
// mula: self.in // mulb: self.in o: _845 with obitwidth:16
int16_t _846 = _hw_filter_dw_global_wrapper_stencil_11 * _hw_input_global_wrapper_stencil_11;
// _hw_filter_dw_global_wrapper_stencil_11 added as input _hw_filter_dw_global_wrapper_stencil_11
// _hw_input_global_wrapper_stencil_11 added as input _hw_input_global_wrapper_stencil_11
// mula: self.in // mulb: self.in o: _846 with obitwidth:16
int16_t _847 = _hw_filter_dw_global_wrapper_stencil_12 * _hw_input_global_wrapper_stencil_12;
// _hw_filter_dw_global_wrapper_stencil_12 added as input _hw_filter_dw_global_wrapper_stencil_12
// _hw_input_global_wrapper_stencil_12 added as input _hw_input_global_wrapper_stencil_12
// mula: self.in // mulb: self.in o: _847 with obitwidth:16
int16_t _848 = _hw_filter_dw_global_wrapper_stencil_13 * _hw_input_global_wrapper_stencil_13;
// _hw_filter_dw_global_wrapper_stencil_13 added as input _hw_filter_dw_global_wrapper_stencil_13
// _hw_input_global_wrapper_stencil_13 added as input _hw_input_global_wrapper_stencil_13
// mula: self.in // mulb: self.in o: _848 with obitwidth:16
int16_t _849 = _hw_filter_dw_global_wrapper_stencil_14 * _hw_input_global_wrapper_stencil_14;
// _hw_filter_dw_global_wrapper_stencil_14 added as input _hw_filter_dw_global_wrapper_stencil_14
// _hw_input_global_wrapper_stencil_14 added as input _hw_input_global_wrapper_stencil_14
// mula: self.in // mulb: self.in o: _849 with obitwidth:16
int16_t _850 = _hw_filter_dw_global_wrapper_stencil_15 * _hw_input_global_wrapper_stencil_15;
// _hw_filter_dw_global_wrapper_stencil_15 added as input _hw_filter_dw_global_wrapper_stencil_15
// _hw_input_global_wrapper_stencil_15 added as input _hw_input_global_wrapper_stencil_15
// mula: self.in // mulb: self.in o: _850 with obitwidth:16
int16_t _851 = _hw_filter_dw_global_wrapper_stencil_16 * _hw_input_global_wrapper_stencil_16;
// _hw_filter_dw_global_wrapper_stencil_16 added as input _hw_filter_dw_global_wrapper_stencil_16
// _hw_input_global_wrapper_stencil_16 added as input _hw_input_global_wrapper_stencil_16
// mula: self.in // mulb: self.in o: _851 with obitwidth:16
int16_t _852 = _hw_filter_dw_global_wrapper_stencil_17 * _hw_input_global_wrapper_stencil_17;
// _hw_filter_dw_global_wrapper_stencil_17 added as input _hw_filter_dw_global_wrapper_stencil_17
// _hw_input_global_wrapper_stencil_17 added as input _hw_input_global_wrapper_stencil_17
// mula: self.in // mulb: self.in o: _852 with obitwidth:16
int16_t _853 = _hw_filter_dw_global_wrapper_stencil_18 * _hw_input_global_wrapper_stencil_18;
// _hw_filter_dw_global_wrapper_stencil_18 added as input _hw_filter_dw_global_wrapper_stencil_18
// _hw_input_global_wrapper_stencil_18 added as input _hw_input_global_wrapper_stencil_18
// mula: self.in // mulb: self.in o: _853 with obitwidth:16
int16_t _854 = _852 + _853;
// adda: _852 // addb: _853 o: _854 with obitwidth:16
int16_t _855 = _851 + _854;
// adda: _851 // addb: _854 o: _855 with obitwidth:16
int16_t _856 = _850 + _855;
// adda: _850 // addb: _855 o: _856 with obitwidth:16
int16_t _857 = _849 + _856;
// adda: _849 // addb: _856 o: _857 with obitwidth:16
int16_t _858 = _848 + _857;
// adda: _848 // addb: _857 o: _858 with obitwidth:16
int16_t _859 = _847 + _858;
// adda: _847 // addb: _858 o: _859 with obitwidth:16
int16_t _860 = _846 + _859;
// adda: _846 // addb: _859 o: _860 with obitwidth:16
int16_t _861 = _dw_conv_stencil_2 + _860;
// _dw_conv_stencil_2 added as input _dw_conv_stencil_2
// adda: self.in // addb: _860 o: _861 with obitwidth:16
int16_t _862 = _845 + _861;
// adda: _845 // addb: _861 o: _862 with obitwidth:16
// connected _862 to the output port
}

hcompute_dw_conv_stencil_6() {
int16_t _922 = _hw_filter_dw_global_wrapper_stencil_19 * _hw_input_global_wrapper_stencil_19;
// _hw_filter_dw_global_wrapper_stencil_19 added as input _hw_filter_dw_global_wrapper_stencil_19
// _hw_input_global_wrapper_stencil_19 added as input _hw_input_global_wrapper_stencil_19
// mula: self.in // mulb: self.in o: _922 with obitwidth:16
int16_t _923 = _hw_filter_dw_global_wrapper_stencil_20 * _hw_input_global_wrapper_stencil_20;
// _hw_filter_dw_global_wrapper_stencil_20 added as input _hw_filter_dw_global_wrapper_stencil_20
// _hw_input_global_wrapper_stencil_20 added as input _hw_input_global_wrapper_stencil_20
// mula: self.in // mulb: self.in o: _923 with obitwidth:16
int16_t _924 = _hw_filter_dw_global_wrapper_stencil_21 * _hw_input_global_wrapper_stencil_21;
// _hw_filter_dw_global_wrapper_stencil_21 added as input _hw_filter_dw_global_wrapper_stencil_21
// _hw_input_global_wrapper_stencil_21 added as input _hw_input_global_wrapper_stencil_21
// mula: self.in // mulb: self.in o: _924 with obitwidth:16
int16_t _925 = _hw_filter_dw_global_wrapper_stencil_22 * _hw_input_global_wrapper_stencil_22;
// _hw_filter_dw_global_wrapper_stencil_22 added as input _hw_filter_dw_global_wrapper_stencil_22
// _hw_input_global_wrapper_stencil_22 added as input _hw_input_global_wrapper_stencil_22
// mula: self.in // mulb: self.in o: _925 with obitwidth:16
int16_t _926 = _hw_filter_dw_global_wrapper_stencil_23 * _hw_input_global_wrapper_stencil_23;
// _hw_filter_dw_global_wrapper_stencil_23 added as input _hw_filter_dw_global_wrapper_stencil_23
// _hw_input_global_wrapper_stencil_23 added as input _hw_input_global_wrapper_stencil_23
// mula: self.in // mulb: self.in o: _926 with obitwidth:16
int16_t _927 = _hw_filter_dw_global_wrapper_stencil_24 * _hw_input_global_wrapper_stencil_24;
// _hw_filter_dw_global_wrapper_stencil_24 added as input _hw_filter_dw_global_wrapper_stencil_24
// _hw_input_global_wrapper_stencil_24 added as input _hw_input_global_wrapper_stencil_24
// mula: self.in // mulb: self.in o: _927 with obitwidth:16
int16_t _928 = _hw_filter_dw_global_wrapper_stencil_25 * _hw_input_global_wrapper_stencil_25;
// _hw_filter_dw_global_wrapper_stencil_25 added as input _hw_filter_dw_global_wrapper_stencil_25
// _hw_input_global_wrapper_stencil_25 added as input _hw_input_global_wrapper_stencil_25
// mula: self.in // mulb: self.in o: _928 with obitwidth:16
int16_t _929 = _hw_filter_dw_global_wrapper_stencil_26 * _hw_input_global_wrapper_stencil_26;
// _hw_filter_dw_global_wrapper_stencil_26 added as input _hw_filter_dw_global_wrapper_stencil_26
// _hw_input_global_wrapper_stencil_26 added as input _hw_input_global_wrapper_stencil_26
// mula: self.in // mulb: self.in o: _929 with obitwidth:16
int16_t _930 = _hw_filter_dw_global_wrapper_stencil_27 * _hw_input_global_wrapper_stencil_27;
// _hw_filter_dw_global_wrapper_stencil_27 added as input _hw_filter_dw_global_wrapper_stencil_27
// _hw_input_global_wrapper_stencil_27 added as input _hw_input_global_wrapper_stencil_27
// mula: self.in // mulb: self.in o: _930 with obitwidth:16
int16_t _931 = _929 + _930;
// adda: _929 // addb: _930 o: _931 with obitwidth:16
int16_t _932 = _928 + _931;
// adda: _928 // addb: _931 o: _932 with obitwidth:16
int16_t _933 = _927 + _932;
// adda: _927 // addb: _932 o: _933 with obitwidth:16
int16_t _934 = _926 + _933;
// adda: _926 // addb: _933 o: _934 with obitwidth:16
int16_t _935 = _925 + _934;
// adda: _925 // addb: _934 o: _935 with obitwidth:16
int16_t _936 = _924 + _935;
// adda: _924 // addb: _935 o: _936 with obitwidth:16
int16_t _937 = _923 + _936;
// adda: _923 // addb: _936 o: _937 with obitwidth:16
int16_t _938 = _dw_conv_stencil_3 + _937;
// _dw_conv_stencil_3 added as input _dw_conv_stencil_3
// adda: self.in // addb: _937 o: _938 with obitwidth:16
int16_t _939 = _922 + _938;
// adda: _922 // addb: _938 o: _939 with obitwidth:16
// connected _939 to the output port
}

hcompute_dw_conv_stencil_7() {
int16_t _999 = _hw_filter_dw_global_wrapper_stencil_28 * _hw_input_global_wrapper_stencil_28;
// _hw_filter_dw_global_wrapper_stencil_28 added as input _hw_filter_dw_global_wrapper_stencil_28
// _hw_input_global_wrapper_stencil_28 added as input _hw_input_global_wrapper_stencil_28
// mula: self.in // mulb: self.in o: _999 with obitwidth:16
int16_t _1000 = _hw_filter_dw_global_wrapper_stencil_29 * _hw_input_global_wrapper_stencil_29;
// _hw_filter_dw_global_wrapper_stencil_29 added as input _hw_filter_dw_global_wrapper_stencil_29
// _hw_input_global_wrapper_stencil_29 added as input _hw_input_global_wrapper_stencil_29
// mula: self.in // mulb: self.in o: _1000 with obitwidth:16
int16_t _1001 = _hw_filter_dw_global_wrapper_stencil_30 * _hw_input_global_wrapper_stencil_30;
// _hw_filter_dw_global_wrapper_stencil_30 added as input _hw_filter_dw_global_wrapper_stencil_30
// _hw_input_global_wrapper_stencil_30 added as input _hw_input_global_wrapper_stencil_30
// mula: self.in // mulb: self.in o: _1001 with obitwidth:16
int16_t _1002 = _hw_filter_dw_global_wrapper_stencil_31 * _hw_input_global_wrapper_stencil_31;
// _hw_filter_dw_global_wrapper_stencil_31 added as input _hw_filter_dw_global_wrapper_stencil_31
// _hw_input_global_wrapper_stencil_31 added as input _hw_input_global_wrapper_stencil_31
// mula: self.in // mulb: self.in o: _1002 with obitwidth:16
int16_t _1003 = _hw_filter_dw_global_wrapper_stencil_32 * _hw_input_global_wrapper_stencil_32;
// _hw_filter_dw_global_wrapper_stencil_32 added as input _hw_filter_dw_global_wrapper_stencil_32
// _hw_input_global_wrapper_stencil_32 added as input _hw_input_global_wrapper_stencil_32
// mula: self.in // mulb: self.in o: _1003 with obitwidth:16
int16_t _1004 = _hw_filter_dw_global_wrapper_stencil_33 * _hw_input_global_wrapper_stencil_33;
// _hw_filter_dw_global_wrapper_stencil_33 added as input _hw_filter_dw_global_wrapper_stencil_33
// _hw_input_global_wrapper_stencil_33 added as input _hw_input_global_wrapper_stencil_33
// mula: self.in // mulb: self.in o: _1004 with obitwidth:16
int16_t _1005 = _hw_filter_dw_global_wrapper_stencil_34 * _hw_input_global_wrapper_stencil_34;
// _hw_filter_dw_global_wrapper_stencil_34 added as input _hw_filter_dw_global_wrapper_stencil_34
// _hw_input_global_wrapper_stencil_34 added as input _hw_input_global_wrapper_stencil_34
// mula: self.in // mulb: self.in o: _1005 with obitwidth:16
int16_t _1006 = _hw_filter_dw_global_wrapper_stencil_35 * _hw_input_global_wrapper_stencil_35;
// _hw_filter_dw_global_wrapper_stencil_35 added as input _hw_filter_dw_global_wrapper_stencil_35
// _hw_input_global_wrapper_stencil_35 added as input _hw_input_global_wrapper_stencil_35
// mula: self.in // mulb: self.in o: _1006 with obitwidth:16
int16_t _1007 = _hw_filter_dw_global_wrapper_stencil_36 * _hw_input_global_wrapper_stencil_36;
// _hw_filter_dw_global_wrapper_stencil_36 added as input _hw_filter_dw_global_wrapper_stencil_36
// _hw_input_global_wrapper_stencil_36 added as input _hw_input_global_wrapper_stencil_36
// mula: self.in // mulb: self.in o: _1007 with obitwidth:16
int16_t _1008 = _1006 + _1007;
// adda: _1006 // addb: _1007 o: _1008 with obitwidth:16
int16_t _1009 = _1005 + _1008;
// adda: _1005 // addb: _1008 o: _1009 with obitwidth:16
int16_t _1010 = _1004 + _1009;
// adda: _1004 // addb: _1009 o: _1010 with obitwidth:16
int16_t _1011 = _1003 + _1010;
// adda: _1003 // addb: _1010 o: _1011 with obitwidth:16
int16_t _1012 = _1002 + _1011;
// adda: _1002 // addb: _1011 o: _1012 with obitwidth:16
int16_t _1013 = _1001 + _1012;
// adda: _1001 // addb: _1012 o: _1013 with obitwidth:16
int16_t _1014 = _1000 + _1013;
// adda: _1000 // addb: _1013 o: _1014 with obitwidth:16
int16_t _1015 = _dw_conv_stencil_4 + _1014;
// _dw_conv_stencil_4 added as input _dw_conv_stencil_4
// adda: self.in // addb: _1014 o: _1015 with obitwidth:16
int16_t _1016 = _999 + _1015;
// adda: _999 // addb: _1015 o: _1016 with obitwidth:16
// connected _1016 to the output port
}

hcompute_hw_filter_pw_global_wrapper_stencil() {
// _hw_filter_pw_stencil_1 added as input _hw_filter_pw_stencil_1
// connected _hw_filter_pw_stencil_1 to the output port
}

hcompute_pw_conv_reduction_stencil() {
int16_t _1060 = (int16_t)(0);
// created const: const_p0__1060 with name _1060
// connected _1060 to the output port
}

hcompute_pw_conv_reduction_stencil_1() {
int16_t _1063 = (int16_t)(0);
// created const: const_p0__1063 with name _1063
// connected _1063 to the output port
}

hcompute_pw_conv_reduction_stencil_2() {
int16_t _1066 = (int16_t)(0);
// created const: const_p0__1066 with name _1066
// connected _1066 to the output port
}

hcompute_pw_conv_reduction_stencil_3() {
int16_t _1076 = _hw_filter_pw_global_wrapper_stencil_1 * _dw_conv_stencil_5;
// _hw_filter_pw_global_wrapper_stencil_1 added as input _hw_filter_pw_global_wrapper_stencil_1
// _dw_conv_stencil_5 added as input _dw_conv_stencil_5
// mula: self.in // mulb: self.in o: _1076 with obitwidth:16
int16_t _1077 = _hw_filter_pw_global_wrapper_stencil_2 * _dw_conv_stencil_6;
// _hw_filter_pw_global_wrapper_stencil_2 added as input _hw_filter_pw_global_wrapper_stencil_2
// _dw_conv_stencil_6 added as input _dw_conv_stencil_6
// mula: self.in // mulb: self.in o: _1077 with obitwidth:16
int16_t _1078 = _hw_filter_pw_global_wrapper_stencil_3 * _dw_conv_stencil_7;
// _hw_filter_pw_global_wrapper_stencil_3 added as input _hw_filter_pw_global_wrapper_stencil_3
// _dw_conv_stencil_7 added as input _dw_conv_stencil_7
// mula: self.in // mulb: self.in o: _1078 with obitwidth:16
int16_t _1079 = _hw_filter_pw_global_wrapper_stencil_4 * _dw_conv_stencil_8;
// _hw_filter_pw_global_wrapper_stencil_4 added as input _hw_filter_pw_global_wrapper_stencil_4
// _dw_conv_stencil_8 added as input _dw_conv_stencil_8
// mula: self.in // mulb: self.in o: _1079 with obitwidth:16
int16_t _1080 = _1078 + _1079;
// adda: _1078 // addb: _1079 o: _1080 with obitwidth:16
int16_t _1081 = _1077 + _1080;
// adda: _1077 // addb: _1080 o: _1081 with obitwidth:16
int16_t _1082 = _pw_conv_reduction_stencil_1 + _1081;
// _pw_conv_reduction_stencil_1 added as input _pw_conv_reduction_stencil_1
// adda: self.in // addb: _1081 o: _1082 with obitwidth:16
int16_t _1083 = _1076 + _1082;
// adda: _1076 // addb: _1082 o: _1083 with obitwidth:16
// connected _1083 to the output port
}

hcompute_pw_conv_reduction_stencil_4() {
int16_t _1109 = _hw_filter_pw_global_wrapper_stencil_5 * _dw_conv_stencil_9;
// _hw_filter_pw_global_wrapper_stencil_5 added as input _hw_filter_pw_global_wrapper_stencil_5
// _dw_conv_stencil_9 added as input _dw_conv_stencil_9
// mula: self.in // mulb: self.in o: _1109 with obitwidth:16
int16_t _1110 = _hw_filter_pw_global_wrapper_stencil_6 * _dw_conv_stencil_10;
// _hw_filter_pw_global_wrapper_stencil_6 added as input _hw_filter_pw_global_wrapper_stencil_6
// _dw_conv_stencil_10 added as input _dw_conv_stencil_10
// mula: self.in // mulb: self.in o: _1110 with obitwidth:16
int16_t _1111 = _hw_filter_pw_global_wrapper_stencil_7 * _dw_conv_stencil_11;
// _hw_filter_pw_global_wrapper_stencil_7 added as input _hw_filter_pw_global_wrapper_stencil_7
// _dw_conv_stencil_11 added as input _dw_conv_stencil_11
// mula: self.in // mulb: self.in o: _1111 with obitwidth:16
int16_t _1112 = _hw_filter_pw_global_wrapper_stencil_8 * _dw_conv_stencil_12;
// _hw_filter_pw_global_wrapper_stencil_8 added as input _hw_filter_pw_global_wrapper_stencil_8
// _dw_conv_stencil_12 added as input _dw_conv_stencil_12
// mula: self.in // mulb: self.in o: _1112 with obitwidth:16
int16_t _1113 = _1111 + _1112;
// adda: _1111 // addb: _1112 o: _1113 with obitwidth:16
int16_t _1114 = _1110 + _1113;
// adda: _1110 // addb: _1113 o: _1114 with obitwidth:16
int16_t _1115 = _pw_conv_reduction_stencil_2 + _1114;
// _pw_conv_reduction_stencil_2 added as input _pw_conv_reduction_stencil_2
// adda: self.in // addb: _1114 o: _1115 with obitwidth:16
int16_t _1116 = _1109 + _1115;
// adda: _1109 // addb: _1115 o: _1116 with obitwidth:16
// connected _1116 to the output port
}

hcompute_pw_conv_reduction_stencil_5() {
int16_t _1142 = _hw_filter_pw_global_wrapper_stencil_9 * _dw_conv_stencil_13;
// _hw_filter_pw_global_wrapper_stencil_9 added as input _hw_filter_pw_global_wrapper_stencil_9
// _dw_conv_stencil_13 added as input _dw_conv_stencil_13
// mula: self.in // mulb: self.in o: _1142 with obitwidth:16
int16_t _1143 = _hw_filter_pw_global_wrapper_stencil_10 * _dw_conv_stencil_14;
// _hw_filter_pw_global_wrapper_stencil_10 added as input _hw_filter_pw_global_wrapper_stencil_10
// _dw_conv_stencil_14 added as input _dw_conv_stencil_14
// mula: self.in // mulb: self.in o: _1143 with obitwidth:16
int16_t _1144 = _hw_filter_pw_global_wrapper_stencil_11 * _dw_conv_stencil_15;
// _hw_filter_pw_global_wrapper_stencil_11 added as input _hw_filter_pw_global_wrapper_stencil_11
// _dw_conv_stencil_15 added as input _dw_conv_stencil_15
// mula: self.in // mulb: self.in o: _1144 with obitwidth:16
int16_t _1145 = _hw_filter_pw_global_wrapper_stencil_12 * _dw_conv_stencil_16;
// _hw_filter_pw_global_wrapper_stencil_12 added as input _hw_filter_pw_global_wrapper_stencil_12
// _dw_conv_stencil_16 added as input _dw_conv_stencil_16
// mula: self.in // mulb: self.in o: _1145 with obitwidth:16
int16_t _1146 = _1144 + _1145;
// adda: _1144 // addb: _1145 o: _1146 with obitwidth:16
int16_t _1147 = _1143 + _1146;
// adda: _1143 // addb: _1146 o: _1147 with obitwidth:16
int16_t _1148 = _pw_conv_reduction_stencil_3 + _1147;
// _pw_conv_reduction_stencil_3 added as input _pw_conv_reduction_stencil_3
// adda: self.in // addb: _1147 o: _1148 with obitwidth:16
int16_t _1149 = _1142 + _1148;
// adda: _1142 // addb: _1148 o: _1149 with obitwidth:16
// connected _1149 to the output port
}

hcompute_hw_output_stencil() {
// _pw_conv_reduction_stencil_4 added as input _pw_conv_reduction_stencil_4
// connected _pw_conv_reduction_stencil_4 to the output port
}

hcompute_hw_output_stencil_1() {
// _pw_conv_reduction_stencil_5 added as input _pw_conv_reduction_stencil_5
// connected _pw_conv_reduction_stencil_5 to the output port
}

hcompute_hw_output_stencil_2() {
// _pw_conv_reduction_stencil_6 added as input _pw_conv_reduction_stencil_6
// connected _pw_conv_reduction_stencil_6 to the output port
}

