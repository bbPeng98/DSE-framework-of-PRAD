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

hcompute_gray_stencil() {
uint16_t _409 = (uint16_t)(150);
uint16_t _410 = _hw_input_global_wrapper_stencil_1 * _409;
// _hw_input_global_wrapper_stencil_1 added as input _hw_input_global_wrapper_stencil_1
// created const: const_p150__409 with name _409
// mula: self.in // mulb: _409 o: _410 with obitwidth:16
uint16_t _411 = (uint16_t)(29);
uint16_t _412 = _hw_input_global_wrapper_stencil_2 * _411;
// _hw_input_global_wrapper_stencil_2 added as input _hw_input_global_wrapper_stencil_2
// created const: const_p29__411 with name _411
// mula: self.in // mulb: _411 o: _412 with obitwidth:16
uint16_t _413 = (uint16_t)(77);
uint16_t _414 = _hw_input_global_wrapper_stencil_3 * _413;
// _hw_input_global_wrapper_stencil_3 added as input _hw_input_global_wrapper_stencil_3
// created const: const_p77__413 with name _413
// mula: self.in // mulb: _413 o: _414 with obitwidth:16
uint16_t _415 = _412 + _414;
// adda: _412 // addb: _414 o: _415 with obitwidth:16
uint16_t _416 = _410 + _415;
// adda: _410 // addb: _415 o: _416 with obitwidth:16
uint16_t _417 = (uint16_t)(8);
uint16_t _418 = _416 >> _417;
// created const: const_p8__417 with name _417
// lshra: _416 // lshrb: _417 o: _418 with obitwidth:16
// connected _418 to the output port
}

hcompute_reciprocal_stencil() {
// adding coreir inst rom_div_lookupa0
[cast]uint16_t _949 = (uint16_t)(1);
uint16_t _950 = _gray_stencil_1 <max> _949;
// _gray_stencil_1 added as input _gray_stencil_1
// created const: const_p1__949 with name _949
// umaxa: self.in // umaxb: _949 o: _950 with obitwidth:16
int32_t _951 = (int32_t)(_950);
// renaming _950 to _951
// added/modified in wire_set: _951 = _950
int32_t _952 = _951 + n1;
// created const: const_n1_n1 with name n1
// adda: _951 // addb: n1 o: _952 with obitwidth:32
uint16_t _953 = ((uint16_t *)_rom_div_lookupa0)[_952][load];
// loading from rom rom_div_lookupa0 with gen memory.rom2
// created rom named rom_rom_div_lookupa0
[cast]// renaming _950 to _951
// added/modified in wire_set: _951 = _950
// loading from rom rom_div_lookupa0 with gen memory.rom2
// connected _953 to the output port
}

hcompute_blur_unnormalized_stencil() {
uint16_t _963 = (uint16_t)(0);
// created const: const_p0__963 with name _963
// connected _963 to the output port
}

hcompute_blur_unnormalized_stencil_1() {
uint16_t _1054 = (uint16_t)(2);
uint16_t _1055 = _gray_stencil_3 * _1054;
// _gray_stencil_3 added as input _gray_stencil_3
// created const: const_p2__1054 with name _1054
// mula: self.in // mulb: _1054 o: _1055 with obitwidth:16
uint16_t _1056 = _gray_stencil_4 * _1054;
// _gray_stencil_4 added as input _gray_stencil_4
// created const: const_p2__1054$1 with name _1054
// mula: self.in // mulb: _1054 o: _1056 with obitwidth:16
uint16_t _1057 = _gray_stencil_5 * _1054;
// _gray_stencil_5 added as input _gray_stencil_5
// created const: const_p2__1054$2 with name _1054
// mula: self.in // mulb: _1054 o: _1057 with obitwidth:16
uint16_t _1058 = (uint16_t)(3);
uint16_t _1059 = _gray_stencil_8 * _1058;
// _gray_stencil_8 added as input _gray_stencil_8
// created const: const_p3__1058 with name _1058
// mula: self.in // mulb: _1058 o: _1059 with obitwidth:16
uint16_t _1060 = (uint16_t)(6);
uint16_t _1061 = _gray_stencil_9 * _1060;
// _gray_stencil_9 added as input _gray_stencil_9
// created const: const_p6__1060 with name _1060
// mula: self.in // mulb: _1060 o: _1061 with obitwidth:16
uint16_t _1062 = (uint16_t)(7);
uint16_t _1063 = _gray_stencil_10 * _1062;
// _gray_stencil_10 added as input _gray_stencil_10
// created const: const_p7__1062 with name _1062
// mula: self.in // mulb: _1062 o: _1063 with obitwidth:16
uint16_t _1064 = _gray_stencil_11 * _1060;
// _gray_stencil_11 added as input _gray_stencil_11
// created const: const_p6__1060$1 with name _1060
// mula: self.in // mulb: _1060 o: _1064 with obitwidth:16
uint16_t _1065 = _gray_stencil_12 * _1058;
// _gray_stencil_12 added as input _gray_stencil_12
// created const: const_p3__1058$1 with name _1058
// mula: self.in // mulb: _1058 o: _1065 with obitwidth:16
uint16_t _1066 = _gray_stencil_14 * _1054;
// _gray_stencil_14 added as input _gray_stencil_14
// created const: const_p2__1054$3 with name _1054
// mula: self.in // mulb: _1054 o: _1066 with obitwidth:16
uint16_t _1067 = _gray_stencil_15 * _1060;
// _gray_stencil_15 added as input _gray_stencil_15
// created const: const_p6__1060$2 with name _1060
// mula: self.in // mulb: _1060 o: _1067 with obitwidth:16
uint16_t _1068 = (uint16_t)(12);
uint16_t _1069 = _gray_stencil_16 * _1068;
// _gray_stencil_16 added as input _gray_stencil_16
// created const: const_p12__1068 with name _1068
// mula: self.in // mulb: _1068 o: _1069 with obitwidth:16
uint16_t _1070 = (uint16_t)(15);
uint16_t _1071 = _gray_stencil_17 * _1070;
// _gray_stencil_17 added as input _gray_stencil_17
// created const: const_p15__1070 with name _1070
// mula: self.in // mulb: _1070 o: _1071 with obitwidth:16
uint16_t _1072 = _gray_stencil_18 * _1068;
// _gray_stencil_18 added as input _gray_stencil_18
// created const: const_p12__1068$1 with name _1068
// mula: self.in // mulb: _1068 o: _1072 with obitwidth:16
uint16_t _1073 = _gray_stencil_19 * _1060;
// _gray_stencil_19 added as input _gray_stencil_19
// created const: const_p6__1060$3 with name _1060
// mula: self.in // mulb: _1060 o: _1073 with obitwidth:16
uint16_t _1074 = _gray_stencil_20 * _1054;
// _gray_stencil_20 added as input _gray_stencil_20
// created const: const_p2__1054$4 with name _1054
// mula: self.in // mulb: _1054 o: _1074 with obitwidth:16
uint16_t _1075 = _gray_stencil_21 * _1054;
// _gray_stencil_21 added as input _gray_stencil_21
// created const: const_p2__1054$5 with name _1054
// mula: self.in // mulb: _1054 o: _1075 with obitwidth:16
uint16_t _1076 = _gray_stencil_22 * _1062;
// _gray_stencil_22 added as input _gray_stencil_22
// created const: const_p7__1062$1 with name _1062
// mula: self.in // mulb: _1062 o: _1076 with obitwidth:16
uint16_t _1077 = _gray_stencil_23 * _1070;
// _gray_stencil_23 added as input _gray_stencil_23
// created const: const_p15__1070$1 with name _1070
// mula: self.in // mulb: _1070 o: _1077 with obitwidth:16
uint16_t _1078 = (uint16_t)(18);
uint16_t _1079 = _gray_stencil_24 * _1078;
// _gray_stencil_24 added as input _gray_stencil_24
// created const: const_p18__1078 with name _1078
// mula: self.in // mulb: _1078 o: _1079 with obitwidth:16
uint16_t _1080 = _gray_stencil_25 * _1070;
// _gray_stencil_25 added as input _gray_stencil_25
// created const: const_p15__1070$2 with name _1070
// mula: self.in // mulb: _1070 o: _1080 with obitwidth:16
uint16_t _1081 = _gray_stencil_26 * _1062;
// _gray_stencil_26 added as input _gray_stencil_26
// created const: const_p7__1062$2 with name _1062
// mula: self.in // mulb: _1062 o: _1081 with obitwidth:16
uint16_t _1082 = _gray_stencil_27 * _1054;
// _gray_stencil_27 added as input _gray_stencil_27
// created const: const_p2__1054$6 with name _1054
// mula: self.in // mulb: _1054 o: _1082 with obitwidth:16
uint16_t _1083 = _gray_stencil_28 * _1054;
// _gray_stencil_28 added as input _gray_stencil_28
// created const: const_p2__1054$7 with name _1054
// mula: self.in // mulb: _1054 o: _1083 with obitwidth:16
uint16_t _1084 = _gray_stencil_29 * _1060;
// _gray_stencil_29 added as input _gray_stencil_29
// created const: const_p6__1060$4 with name _1060
// mula: self.in // mulb: _1060 o: _1084 with obitwidth:16
uint16_t _1085 = _gray_stencil_30 * _1068;
// _gray_stencil_30 added as input _gray_stencil_30
// created const: const_p12__1068$2 with name _1068
// mula: self.in // mulb: _1068 o: _1085 with obitwidth:16
uint16_t _1086 = _gray_stencil_31 * _1070;
// _gray_stencil_31 added as input _gray_stencil_31
// created const: const_p15__1070$3 with name _1070
// mula: self.in // mulb: _1070 o: _1086 with obitwidth:16
uint16_t _1087 = _gray_stencil_32 * _1068;
// _gray_stencil_32 added as input _gray_stencil_32
// created const: const_p12__1068$3 with name _1068
// mula: self.in // mulb: _1068 o: _1087 with obitwidth:16
uint16_t _1088 = _gray_stencil_33 * _1060;
// _gray_stencil_33 added as input _gray_stencil_33
// created const: const_p6__1060$5 with name _1060
// mula: self.in // mulb: _1060 o: _1088 with obitwidth:16
uint16_t _1089 = _gray_stencil_34 * _1054;
// _gray_stencil_34 added as input _gray_stencil_34
// created const: const_p2__1054$8 with name _1054
// mula: self.in // mulb: _1054 o: _1089 with obitwidth:16
uint16_t _1090 = _gray_stencil_36 * _1058;
// _gray_stencil_36 added as input _gray_stencil_36
// created const: const_p3__1058$2 with name _1058
// mula: self.in // mulb: _1058 o: _1090 with obitwidth:16
uint16_t _1091 = _gray_stencil_37 * _1060;
// _gray_stencil_37 added as input _gray_stencil_37
// created const: const_p6__1060$6 with name _1060
// mula: self.in // mulb: _1060 o: _1091 with obitwidth:16
uint16_t _1092 = _gray_stencil_38 * _1062;
// _gray_stencil_38 added as input _gray_stencil_38
// created const: const_p7__1062$3 with name _1062
// mula: self.in // mulb: _1062 o: _1092 with obitwidth:16
uint16_t _1093 = _gray_stencil_39 * _1060;
// _gray_stencil_39 added as input _gray_stencil_39
// created const: const_p6__1060$7 with name _1060
// mula: self.in // mulb: _1060 o: _1093 with obitwidth:16
uint16_t _1094 = _gray_stencil_40 * _1058;
// _gray_stencil_40 added as input _gray_stencil_40
// created const: const_p3__1058$3 with name _1058
// mula: self.in // mulb: _1058 o: _1094 with obitwidth:16
uint16_t _1095 = _gray_stencil_43 * _1054;
// _gray_stencil_43 added as input _gray_stencil_43
// created const: const_p2__1054$9 with name _1054
// mula: self.in // mulb: _1054 o: _1095 with obitwidth:16
uint16_t _1096 = _gray_stencil_44 * _1054;
// _gray_stencil_44 added as input _gray_stencil_44
// created const: const_p2__1054$10 with name _1054
// mula: self.in // mulb: _1054 o: _1096 with obitwidth:16
uint16_t _1097 = _gray_stencil_46 * _1054;
// _gray_stencil_46 added as input _gray_stencil_46
// created const: const_p2__1054$11 with name _1054
// mula: self.in // mulb: _1054 o: _1097 with obitwidth:16
uint16_t _1098 = _gray_stencil_45 + _1097;
// _gray_stencil_45 added as input _gray_stencil_45
// adda: self.in // addb: _1097 o: _1098 with obitwidth:16
uint16_t _1099 = _1096 + _1098;
// adda: _1096 // addb: _1098 o: _1099 with obitwidth:16
uint16_t _1100 = _1095 + _1099;
// adda: _1095 // addb: _1099 o: _1100 with obitwidth:16
uint16_t _1101 = _gray_stencil_42 + _1100;
// _gray_stencil_42 added as input _gray_stencil_42
// adda: self.in // addb: _1100 o: _1101 with obitwidth:16
uint16_t _1102 = _gray_stencil_41 + _1101;
// _gray_stencil_41 added as input _gray_stencil_41
// adda: self.in // addb: _1101 o: _1102 with obitwidth:16
uint16_t _1103 = _1094 + _1102;
// adda: _1094 // addb: _1102 o: _1103 with obitwidth:16
uint16_t _1104 = _1093 + _1103;
// adda: _1093 // addb: _1103 o: _1104 with obitwidth:16
uint16_t _1105 = _1092 + _1104;
// adda: _1092 // addb: _1104 o: _1105 with obitwidth:16
uint16_t _1106 = _1091 + _1105;
// adda: _1091 // addb: _1105 o: _1106 with obitwidth:16
uint16_t _1107 = _1090 + _1106;
// adda: _1090 // addb: _1106 o: _1107 with obitwidth:16
uint16_t _1108 = _gray_stencil_35 + _1107;
// _gray_stencil_35 added as input _gray_stencil_35
// adda: self.in // addb: _1107 o: _1108 with obitwidth:16
uint16_t _1109 = _1089 + _1108;
// adda: _1089 // addb: _1108 o: _1109 with obitwidth:16
uint16_t _1110 = _1088 + _1109;
// adda: _1088 // addb: _1109 o: _1110 with obitwidth:16
uint16_t _1111 = _1087 + _1110;
// adda: _1087 // addb: _1110 o: _1111 with obitwidth:16
uint16_t _1112 = _1086 + _1111;
// adda: _1086 // addb: _1111 o: _1112 with obitwidth:16
uint16_t _1113 = _1085 + _1112;
// adda: _1085 // addb: _1112 o: _1113 with obitwidth:16
uint16_t _1114 = _1084 + _1113;
// adda: _1084 // addb: _1113 o: _1114 with obitwidth:16
uint16_t _1115 = _1083 + _1114;
// adda: _1083 // addb: _1114 o: _1115 with obitwidth:16
uint16_t _1116 = _1082 + _1115;
// adda: _1082 // addb: _1115 o: _1116 with obitwidth:16
uint16_t _1117 = _1081 + _1116;
// adda: _1081 // addb: _1116 o: _1117 with obitwidth:16
uint16_t _1118 = _1080 + _1117;
// adda: _1080 // addb: _1117 o: _1118 with obitwidth:16
uint16_t _1119 = _1079 + _1118;
// adda: _1079 // addb: _1118 o: _1119 with obitwidth:16
uint16_t _1120 = _1077 + _1119;
// adda: _1077 // addb: _1119 o: _1120 with obitwidth:16
uint16_t _1121 = _1076 + _1120;
// adda: _1076 // addb: _1120 o: _1121 with obitwidth:16
uint16_t _1122 = _1075 + _1121;
// adda: _1075 // addb: _1121 o: _1122 with obitwidth:16
uint16_t _1123 = _1074 + _1122;
// adda: _1074 // addb: _1122 o: _1123 with obitwidth:16
uint16_t _1124 = _1073 + _1123;
// adda: _1073 // addb: _1123 o: _1124 with obitwidth:16
uint16_t _1125 = _1072 + _1124;
// adda: _1072 // addb: _1124 o: _1125 with obitwidth:16
uint16_t _1126 = _1071 + _1125;
// adda: _1071 // addb: _1125 o: _1126 with obitwidth:16
uint16_t _1127 = _1069 + _1126;
// adda: _1069 // addb: _1126 o: _1127 with obitwidth:16
uint16_t _1128 = _1067 + _1127;
// adda: _1067 // addb: _1127 o: _1128 with obitwidth:16
uint16_t _1129 = _1066 + _1128;
// adda: _1066 // addb: _1128 o: _1129 with obitwidth:16
uint16_t _1130 = _gray_stencil_13 + _1129;
// _gray_stencil_13 added as input _gray_stencil_13
// adda: self.in // addb: _1129 o: _1130 with obitwidth:16
uint16_t _1131 = _1065 + _1130;
// adda: _1065 // addb: _1130 o: _1131 with obitwidth:16
uint16_t _1132 = _1064 + _1131;
// adda: _1064 // addb: _1131 o: _1132 with obitwidth:16
uint16_t _1133 = _1063 + _1132;
// adda: _1063 // addb: _1132 o: _1133 with obitwidth:16
uint16_t _1134 = _1061 + _1133;
// adda: _1061 // addb: _1133 o: _1134 with obitwidth:16
uint16_t _1135 = _1059 + _1134;
// adda: _1059 // addb: _1134 o: _1135 with obitwidth:16
uint16_t _1136 = _gray_stencil_7 + _1135;
// _gray_stencil_7 added as input _gray_stencil_7
// adda: self.in // addb: _1135 o: _1136 with obitwidth:16
uint16_t _1137 = _gray_stencil_6 + _1136;
// _gray_stencil_6 added as input _gray_stencil_6
// adda: self.in // addb: _1136 o: _1137 with obitwidth:16
uint16_t _1138 = _1057 + _1137;
// adda: _1057 // addb: _1137 o: _1138 with obitwidth:16
uint16_t _1139 = _1056 + _1138;
// adda: _1056 // addb: _1138 o: _1139 with obitwidth:16
uint16_t _1140 = _1055 + _1139;
// adda: _1055 // addb: _1139 o: _1140 with obitwidth:16
uint16_t _1141 = _blur_unnormalized_stencil_1 + _1140;
// _blur_unnormalized_stencil_1 added as input _blur_unnormalized_stencil_1
// adda: self.in // addb: _1140 o: _1141 with obitwidth:16
uint16_t _1142 = _gray_stencil_2 + _1141;
// _gray_stencil_2 added as input _gray_stencil_2
// adda: self.in // addb: _1141 o: _1142 with obitwidth:16
// connected _1142 to the output port
}

hcompute_sharpen_stencil() {
[cast][cast]int16_t _1303 = (int16_t)(_gray_stencil_47);
// renaming _gray_stencil_47 to _1303
// _gray_stencil_47 added as input _gray_stencil_47
// added/modified in wire_set: _1303 = _gray_stencil_47
int16_t _1304 = (int16_t)(2);
int16_t _1305 = _1303 * _1304;
// created const: const_p2__1304 with name _1304
// mula: _1303 // mulb: _1304 o: _1305 with obitwidth:16
[cast][cast]uint16_t _1306 = (uint16_t)(8);
uint16_t _1307 = _blur_unnormalized_stencil_2 >> _1306;
// _blur_unnormalized_stencil_2 added as input _blur_unnormalized_stencil_2
// created const: const_p8__1306$1 with name _1306
// lshra: self.in // lshrb: _1306 o: _1307 with obitwidth:16
uint8_t _1308 = (uint8_t)(_1307);
// renaming _1307 to _1308
// added/modified in wire_set: _1308 = _1307
int16_t _1309 = (int16_t)(_1308);
// renaming _1308 to _1309
// added/modified in wire_set: _1309 = _1308
int16_t _1310 = _1305 - _1309;
// suba: _1305 // subb: _1309 o: _1310 with obitwidth:16
int16_t _1311 = (int16_t)(255);
int16_t _1312 = _1310 <smin> _1311;
// created const: const_p255__1311 with name _1311
// smina: _1310 // sminb: _1311 o: _1312 with obitwidth:16
int16_t _1313 = (int16_t)(0);
int16_t _1314 = _1312 <smax> _1313;
// created const: const_p0__1313 with name _1313
// smaxa: _1312 // smaxb: _1313 o: _1314 with obitwidth:16
uint16_t _1315 = (uint16_t)(_1314);
// renaming _1314 to _1315
// added/modified in wire_set: _1315 = _1314
[cast][cast]// renaming _gray_stencil_47 to _1303
// _gray_stencil_47 added as input _gray_stencil_47
// added/modified in wire_set: _1303 = _gray_stencil_47
[cast][cast]// renaming _1307 to _1308
// added/modified in wire_set: _1308 = _1307
// renaming _1308 to _1309
// added/modified in wire_set: _1309 = _1308
// renaming _1314 to _1315
// added/modified in wire_set: _1315 = _1314
// connected _1315 to the output port
}

hcompute_ratio_stencil() {
uint16_t _1334 = _sharpen_stencil_1 * _reciprocal_stencil_1;
// _sharpen_stencil_1 added as input _sharpen_stencil_1
// _reciprocal_stencil_1 added as input _reciprocal_stencil_1
// mula: self.in // mulb: self.in o: _1334 with obitwidth:16
// connected _1334 to the output port
}

hcompute_hw_output_stencil() {
[cast]int32_t _1343 = (int32_t)(_ratio_stencil_1);
// renaming _ratio_stencil_1 to _1343
// _ratio_stencil_1 added as input _ratio_stencil_1
// added/modified in wire_set: _1343 = _ratio_stencil_1
[cast]int32_t _1344 = (int32_t)(_hw_input_global_wrapper_stencil_4);
// renaming _hw_input_global_wrapper_stencil_4 to _1344
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// added/modified in wire_set: _1344 = _hw_input_global_wrapper_stencil_4
int16_t _1345 = _1343 *m _1344;
// mult_middlea: _1343 // mult_middleb: _1344 o: _1345 with obitwidth:16
[cast]// renaming _ratio_stencil_1 to _1343
// _ratio_stencil_1 added as input _ratio_stencil_1
// added/modified in wire_set: _1343 = _ratio_stencil_1
[cast]// renaming _hw_input_global_wrapper_stencil_4 to _1344
// _hw_input_global_wrapper_stencil_4 added as input _hw_input_global_wrapper_stencil_4
// added/modified in wire_set: _1344 = _hw_input_global_wrapper_stencil_4
// connected _1345 to the output port
}

hcompute_hw_output_stencil_1() {
[cast]int32_t _1360 = (int32_t)(_ratio_stencil_2);
// renaming _ratio_stencil_2 to _1360
// _ratio_stencil_2 added as input _ratio_stencil_2
// added/modified in wire_set: _1360 = _ratio_stencil_2
[cast]int32_t _1361 = (int32_t)(_hw_input_global_wrapper_stencil_5);
// renaming _hw_input_global_wrapper_stencil_5 to _1361
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// added/modified in wire_set: _1361 = _hw_input_global_wrapper_stencil_5
int16_t _1362 = _1360 *m _1361;
// mult_middlea: _1360 // mult_middleb: _1361 o: _1362 with obitwidth:16
[cast]// renaming _ratio_stencil_2 to _1360
// _ratio_stencil_2 added as input _ratio_stencil_2
// added/modified in wire_set: _1360 = _ratio_stencil_2
[cast]// renaming _hw_input_global_wrapper_stencil_5 to _1361
// _hw_input_global_wrapper_stencil_5 added as input _hw_input_global_wrapper_stencil_5
// added/modified in wire_set: _1361 = _hw_input_global_wrapper_stencil_5
// connected _1362 to the output port
}

hcompute_hw_output_stencil_2() {
[cast]int32_t _1377 = (int32_t)(_ratio_stencil_3);
// renaming _ratio_stencil_3 to _1377
// _ratio_stencil_3 added as input _ratio_stencil_3
// added/modified in wire_set: _1377 = _ratio_stencil_3
[cast]int32_t _1378 = (int32_t)(_hw_input_global_wrapper_stencil_6);
// renaming _hw_input_global_wrapper_stencil_6 to _1378
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// added/modified in wire_set: _1378 = _hw_input_global_wrapper_stencil_6
int16_t _1379 = _1377 *m _1378;
// mult_middlea: _1377 // mult_middleb: _1378 o: _1379 with obitwidth:16
[cast]// renaming _ratio_stencil_3 to _1377
// _ratio_stencil_3 added as input _ratio_stencil_3
// added/modified in wire_set: _1377 = _ratio_stencil_3
[cast]// renaming _hw_input_global_wrapper_stencil_6 to _1378
// _hw_input_global_wrapper_stencil_6 added as input _hw_input_global_wrapper_stencil_6
// added/modified in wire_set: _1378 = _hw_input_global_wrapper_stencil_6
// connected _1379 to the output port
}

