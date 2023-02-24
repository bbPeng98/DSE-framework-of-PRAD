#代码用于生成alu_enum模板，放置路径：aha/lassen/lassen/gen_alu_enum_code.py
import os
# from lassen.my_alu import my_ALU_t
import sys
import json


def gen_alu_enum_code ():
    dirpath = os.path.dirname(__file__)

    file = open(dirpath+"/my_alu.py","w") 
    file.write("from hwtypes.adt import Enum\n")
    file.write("from hwtypes import BitVector, Bit as BitPy\n")
    with open(f"{dirpath}/args.json",encoding='utf-8') as f:
        op = json.load(f).get("op")
    f.close()
    file.write("class my_ALU_t(Enum):\n")
    i = 0
    for each_op in op:
        file.write(f"    {each_op} = {i}\n")
        i += 1
    file.close()
    
   
  
    

def main():
    gen_alu_enum_code()

if __name__ == "__main__":
    main()

