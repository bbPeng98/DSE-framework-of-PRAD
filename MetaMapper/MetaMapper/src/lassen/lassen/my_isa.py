from lassen.cond import Cond_t
from lassen.mode import Mode_t
from lassen.lut import LUT_t_fc
from lassen.lut_1 import LUT1_t_fc
from lassen.lut_2 import LUT2_t_fc
from lassen.lut_3 import LUT3_t_fc
from lassen.lut_4 import LUT4_t_fc
from lassen.lut_5 import LUT5_t_fc
from lassen.lut_6 import LUT6_t_fc
from lassen.my_alu import my_ALU_t
from lassen.template_alu_2input import Signed_t
from lassen.my_alu_3 import my_ALU_t_3
from lassen.float.fpu import FPU_t
from lassen.float.float_custom import FPCustom_t
from lassen.common import DATAWIDTH
from peak.peak import Const
from peak.features import family_closure
from hwtypes.adt import Product, TaggedUnion
import json
import os


# class Op_t(TaggedUnion):
#     alu=ALU_t
#     fpu=FPU_t
#     fp_custom=FPCustom_t

"""
https://github.com/StanfordAHA/CGRAGenerator/wiki/PE-Spec
"""
@family_closure
def my_Inst_fc(family):
    Data = family.BitVector[DATAWIDTH]
    Bit = family.Bit
    dir_path = os.path.dirname(os.path.realpath(__file__))
    with open(f"{dir_path}/args.json") as f:
        lut_n = json.load(f).get("lut_n")
    
    if(lut_n == 1):
        LUT_t_fc_ = LUT1_t_fc
    elif(lut_n == 2):
        LUT_t_fc_ = LUT2_t_fc
    elif(lut_n == 3):
        LUT_t_fc_ = LUT3_t_fc
    elif(lut_n == 4):
        LUT_t_fc_ = LUT4_t_fc
    elif(lut_n == 5):
        LUT_t_fc_ = LUT5_t_fc
    elif(lut_n == 6):
        LUT_t_fc_ = LUT6_t_fc

    LUT_t, _ = LUT_t_fc_(family)
    
    class my_Inst(Product):
        alu= my_ALU_t       
        signed= Signed_t     # unsigned or signed
        lut= LUT_t          # LUT operation as a 3-bit LUT
        cond= Cond_t        # Condition code (see cond.py)
        rega= Mode_t        # RegA mode (see mode.py)
        data0= Data         # RegA constant (16-bits)
        regb= Mode_t        # RegB mode
        data1= Data         # RegB constant (16-bits)
        regd= Mode_t
        bit0= Bit
        rege= Mode_t
        bit1= Bit
        regf= Mode_t
        bit2= Bit
    return my_Inst
