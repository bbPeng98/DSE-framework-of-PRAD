from hwtypes.adt import Enum
from hwtypes import BitVector, Bit as BitPy
class my_ALU_t(Enum):
    Add = 0
    Sub = 1
    Adc = 2
    Abs = 3
    GTE_Max = 4
    LTE_Min = 5
    Sbc = 6
    Sel = 7
    Mult0 = 8
    Mult1 = 9
    Mult2 = 10
    SHR = 11
    SHL = 12
    Or = 13
    And = 14
    XOr = 15
    MULADD = 16
    MULSUB = 17
    TAA = 18
    TAS = 19
    TSA = 20
    TSS = 21
    CROP = 22
    MULSHR = 23
