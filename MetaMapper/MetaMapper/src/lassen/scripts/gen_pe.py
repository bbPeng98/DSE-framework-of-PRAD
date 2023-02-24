
from lassen.gen_alu_enum_code import gen_alu_enum_code
import sys
from lassen.gen_alu_code import gen_alu_code
from lassen.gen_isa_code import gen_isa_code
import json
import os

dir_path = os.path.dirname(os.path.realpath(__file__))
with open(f"{dir_path}/../lassen/args.json") as f:
    attr = json.load(f)
    has_3input = attr["has_3input"]
    lut_n = attr["lut_n"]

gen_isa_code(has_3input, lut_n)   
gen_alu_code(has_3input)          
