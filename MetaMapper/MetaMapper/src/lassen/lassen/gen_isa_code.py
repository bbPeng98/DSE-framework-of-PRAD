#代码用于生成isa模板，放置路径：aha/lassen/lassen/gen_PE_code.py
import os
from lassen.my_alu import my_ALU_t
import sys


def gen_isa_code (has_3input,lut_n):
    dirpath = os.path.dirname(__file__)
    if(has_3input == 0):
        file1 = open(dirpath+"/my_isa.py","w") 
        file2 = open(dirpath+"/lib_my_isa.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()
            
        template_isa_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/my_isa.py","a")

    else:
        file1 = open(dirpath+"/my_isa_3.py","w") 
        file2 = open(dirpath+"/lib_my_isa_3.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()

        template_isa_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/my_isa_3.py","a")
  


    #template_PE_file.write("            ra, ra_rdata = self.rega(inst.rega, inst.data0, data0, clk_en)\n")
    #template_PE_file.write("            rb, rb_rdata = self.regb(inst.regb, inst.data1, data1, clk_en)\n\n")

    if(lut_n >= 1):
        template_isa_file.write("        regd= Mode_t\n")
        template_isa_file.write("        bit0= Bit\n")
    if(lut_n >= 2):
        template_isa_file.write("        rege= Mode_t\n")
        template_isa_file.write("        bit1= Bit\n")
        
    if(lut_n >= 3):
        template_isa_file.write("        regf= Mode_t\n")
        template_isa_file.write("        bit2= Bit\n")
        
    if(lut_n >= 4):
        template_isa_file.write("        regg= Mode_t\n")
        template_isa_file.write("        bit3= Bit\n")
        
    if(lut_n >= 5):
        template_isa_file.write("        regh= Mode_t\n")
        template_isa_file.write("        bit4= Bit\n")
        
    if(lut_n >= 6):
        template_isa_file.write("        regi= Mode_t\n")
        template_isa_file.write("        bit5= Bit\n")
        
    
    
    if(has_3input == 0):
        template_isa_file.write("    return my_Inst\n")  
    elif(has_3input == 1):
        template_isa_file.write("    return my_Inst_3\n")
    template_isa_file.close()
    print("-----------success----------------------\n")
  
    

def main(has_3input,lut_n):
    gen_isa_code(has_3input,lut_n)

if __name__ == "__main__":
    main(int(sys.argv[1]),int(sys.argv[2]))
