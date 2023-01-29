//根据track，side，sel_width判断地址为多少，进而判断config信号为多少
//pe的1bit，sel_width为2

Net ID: e10 Segment Size: 1
Segment: 0 Size: 5
PORT res_p (0, 1, 1)
SB (1, 0, 1, 0, 1, 1) //配置SB,line1
RMUX 0_1 (0, 1, 1)
SB (1, 1, 1, 2, 0, 1) //不用配置
PORT bit0 (1, 1, 1) //配置CB,line2

Net ID: e12 Segment Size: 1
Segment: 0 Size: 5
PORT res_p (1, 2, 1)
SB (0, 1, 2, 3, 1, 1)   //line3
RMUX 3_0 (1, 2, 1)
SB (0, 1, 1, 1, 0, 1)
PORT bit2 (1, 1, 1)     //line4

Net ID: e14 Segment Size: 1
Segment: 0 Size: 5
PORT res_p (1, 1, 1)
SB (0, 1, 1, 0, 1, 1)
RMUX 0_0 (1, 1, 1)
SB (0, 2, 1, 2, 0, 1)
PORT bit0 (2, 1, 1)

Net ID: e19 Segment Size: 1
Segment: 0 Size: 6
PORT stencil_valid (3, 1, 1)
SB (3, 3, 1, 2, 1, 1)
RMUX 2_3 (3, 1, 1)
SB (3, 2, 1, 0, 0, 1)
SB (3, 2, 1, 2, 1, 1)
REG T3_WEST (3, 2, 1, 1)

Net ID: e2 Segment Size: 1
Segment: 0 Size: 42
REG T3_WEST (3, 2, 1, 1)
RMUX 2_3 (2, 1, 1)
SB (3, 1, 1, 0, 0, 1)
SB (0, 1, 1, 1, 1, 1)
RMUX 1_0 (1, 1, 1)
SB (0, 1, 2, 3, 0, 1)
SB (1, 1, 2, 0, 1, 1)
RMUX 0_1 (1, 2, 1)
SB (1, 2, 2, 2, 0, 1)
SB (4, 2, 2, 3, 1, 1)
RMUX 3_4 (2, 2, 1)
SB (4, 2, 1, 1, 0, 1)
SB (4, 2, 1, 0, 1, 1)
RMUX 0_4 (2, 1, 1)
SB (4, 3, 1, 2, 0, 1)
SB (3, 3, 1, 1, 1, 1)
RMUX 1_3 (3, 1, 1)
SB (3, 3, 2, 3, 0, 1)
SB (2, 3, 2, 2, 1, 1)
RMUX 2_2 (3, 2, 1)
SB (2, 2, 2, 0, 0, 1)
SB (1, 2, 2, 3, 1, 1)
RMUX 3_1 (2, 2, 1)
SB (1, 2, 1, 1, 0, 1)
SB (2, 2, 1, 2, 1, 1)
RMUX 2_2 (2, 1, 1)
SB (2, 1, 1, 0, 0, 1)
SB (1, 1, 1, 1, 1, 1)
RMUX 1_1 (1, 1, 1)
SB (1, 1, 2, 3, 0, 1)
SB (4, 1, 2, 2, 1, 1)
RMUX 2_4 (1, 2, 1)
SB (4, 0, 2, 0, 0, 1)
SB (3, 0, 2, 3, 1, 1)
RMUX 3_3 (0, 2, 1)
SB (3, 0, 1, 1, 0, 1)
SB (0, 0, 1, 0, 1, 1)
RMUX 0_0 (0, 1, 1)
SB (0, 1, 1, 2, 0, 1)
SB (0, 1, 1, 3, 1, 1)
RMUX 3_0 (1, 1, 1)
PORT f2io_1 (1, 0, 1)

Net ID: e4 Segment Size: 1
Segment: 0 Size: 12
PORT io2f_1 (0, 0, 1)
SB (1, 0, 1, 3, 0, 1)
SB (2, 0, 1, 0, 1, 1)
RMUX 0_2 (0, 1, 1)
SB (2, 1, 1, 2, 0, 1)
SB (2, 1, 1, 0, 1, 1)
RMUX 0_2 (1, 1, 1)
SB (2, 2, 1, 2, 0, 1)
SB (2, 2, 1, 0, 1, 1)
RMUX 0_2 (2, 1, 1)
SB (2, 3, 1, 2, 0, 1)
PORT flush (3, 1, 1)

Net ID: e1 Segment Size: 1
Segment: 0 Size: 39
REG T0_SOUTH (0, 1, 1, 16)
RMUX 1_0 (1, 1, 16)
SB (0, 1, 2, 3, 0, 16)
SB (0, 1, 2, 2, 1, 16)
RMUX 2_0 (1, 2, 16)
SB (0, 0, 2, 0, 0, 16)
SB (4, 0, 2, 3, 1, 16)
RMUX 3_4 (0, 2, 16)
SB (4, 0, 1, 1, 0, 16)
SB (4, 0, 1, 0, 1, 16)
RMUX 0_4 (0, 1, 16)
SB (4, 1, 1, 2, 0, 16)
SB (3, 1, 1, 1, 1, 16)
RMUX 1_3 (1, 1, 16)
SB (3, 1, 2, 3, 0, 16)
SB (2, 1, 2, 2, 1, 16)
RMUX 2_2 (1, 2, 16)
SB (2, 0, 2, 0, 0, 16)
SB (1, 0, 2, 3, 1, 16)
RMUX 3_1 (0, 2, 16)
SB (1, 0, 1, 1, 0, 16)
SB (2, 0, 1, 0, 1, 16)
RMUX 0_2 (0, 1, 16)
SB (2, 1, 1, 2, 0, 16)
SB (1, 1, 1, 1, 1, 16)
RMUX 1_1 (1, 1, 16)
SB (1, 1, 2, 3, 0, 16)
SB (4, 1, 2, 2, 1, 16)
RMUX 2_4 (1, 2, 16)
SB (4, 0, 2, 0, 0, 16)
SB (3, 0, 2, 3, 1, 16)
RMUX 3_3 (0, 2, 16)
SB (3, 0, 1, 1, 0, 16)
SB (0, 0, 1, 0, 1, 16)
RMUX 0_0 (0, 1, 16)
SB (0, 1, 1, 2, 0, 16)
SB (0, 1, 1, 3, 1, 16)
RMUX 3_0 (1, 1, 16)
PORT f2io_16 (1, 0, 16)

Net ID: e15 Segment Size: 1
Segment: 0 Size: 6
PORT alu_res (2, 1, 16)
SB (3, 2, 1, 2, 1, 16)
RMUX 2_3 (2, 1, 16)
SB (3, 1, 1, 0, 0, 16)
SB (0, 1, 1, 1, 1, 16)
REG T0_SOUTH (0, 1, 1, 16)

Net ID: e5 Segment Size: 1
Segment: 0 Size: 5
PORT alu_res (2, 2, 16)
SB (0, 2, 2, 3, 1, 16)
RMUX 3_0 (2, 2, 16)
SB (0, 2, 1, 1, 0, 16)
PORT data0 (2, 1, 16)

Net ID: e7 Segment Size: 2
Segment: 0 Size: 3
PORT io2f_16 (0, 0, 16)
SB (0, 0, 1, 3, 0, 16)
PORT data0 (0, 1, 16)
Segment: 1 Size: 8
SB (0, 0, 1, 3, 0, 16)
SB (0, 0, 1, 1, 1, 16)
RMUX 1_0 (0, 1, 16)
SB (0, 0, 2, 3, 0, 16)
SB (1, 0, 2, 0, 1, 16)
RMUX 0_1 (0, 2, 16)
SB (1, 1, 2, 2, 0, 16)
PORT data0 (1, 2, 16)

