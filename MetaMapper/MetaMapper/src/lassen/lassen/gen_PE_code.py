#代码用于生成PE模板，放置路径：aha/lassen/lassen/gen_PE_code.py
import os
import sys


def gen_PE_code (has_3input,lut_n):
    dirpath = os.path.dirname(__file__)
    if(has_3input == 0):
        file1 = open(dirpath+"/my_PE_2input.py","w") 
        file2 = open(dirpath+"/lib_my_PE_2input.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()
        line_num0 = 54
        line_num = line_num0 + 18 + 1
        line_num1 = line_num+13
        with open(dirpath+"/my_PE_2input.py",encoding ="UTF-8") as f:
            lines = []
            for line in f.readlines():
                lines.append(line)
        #template_PE_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/my_PE_2input.py","a")
   
    else:
        file1 = open(dirpath+"/my_PE_3input.py","w") 
        file2 = open(dirpath+"/lib_my_PE_3input.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()
        line_num0 = 67
        line_num = line_num0 + 22 +1
        line_num1 = line_num+18
        with open(dirpath+"/my_PE_3input.py",encoding ="UTF-8") as f:
            lines = []
            for line in f.readlines():
                lines.append(line)
        #template_PE_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/my_PE_3input.py","a")
     


    #template_PE_file.write("            ra, ra_rdata = self.rega(inst.rega, inst.data0, data0, clk_en)\n")
    #template_PE_file.write("            rb, rb_rdata = self.regb(inst.regb, inst.data1, data1, clk_en)\n\n")


    f.close()
    if(lut_n == 1):
        lines.insert(line_num0,"    LUT = LUT1_fc(family)\n")
    if(lut_n == 2):
        lines.insert(line_num0,"    LUT = LUT2_fc(family)\n")
    if(lut_n == 3):
        lines.insert(line_num0,"    LUT = LUT3_fc(family)\n")
    if(lut_n == 4):
        lines.insert(line_num0,"    LUT = LUT4_fc(family)\n")
    if(lut_n == 5):
        lines.insert(line_num0,"    LUT = LUT5_fc(family)\n")
    if(lut_n == 6):
        lines.insert(line_num0,"    LUT = LUT6_fc(family)\n")

    if(lut_n >= 1):
        lines.insert(line_num,"            self.regd: BitReg = BitReg()\n")
        lines.insert(line_num1+1,"            bit0: Bit = Bit(0), \\\n")
    if(lut_n >= 2):
        lines.insert(line_num+1,"            self.rege: BitReg = BitReg()\n")
        lines.insert(line_num1+3,"            bit1: Bit = Bit(0), \\\n")
    if(lut_n >= 3):
        lines.insert(line_num+2,"            self.regf: BitReg = BitReg()\n")
        lines.insert(line_num1+5,"            bit2: Bit = Bit(0), \\\n")
    if(lut_n >= 4):
        lines.insert(line_num+3,"            self.regg: BitReg = BitReg()\n")
        lines.insert(line_num1+7,"            bit3: Bit = Bit(0), \\\n")
    if(lut_n >= 5):
        lines.insert(line_num+4,"            self.regh: BitReg = BitReg()\n")
        lines.insert(line_num1+9,"            bit4: Bit = Bit(0), \\\n")
    if(lut_n >= 6):
        lines.insert(line_num+5,"            self.regi: BitReg = BitReg()\n")
        lines.insert(line_num1+11,"            bit5: Bit = Bit(0), \\\n")




    if(has_3input == 0):
        s=''.join(lines)
        f = open(dirpath+"/my_PE_2input.py","w")
        f.write(s)
        f.close()
        template_PE_file = open(dirpath+"/my_PE_2input.py","a")
    else:
        s=''.join(lines)
        f = open(dirpath+"/my_PE_3input.py","w")
        f.write(s)
        f.close()
        template_PE_file = open(dirpath+"/my_PE_3input.py","a")

    del lines[:]
    
    if(lut_n >= 1):
        template_PE_file.write("            rd, rd_rdata = self.regd(inst.regd, inst.bit0, bit0, clk_en)\n")
    if(lut_n >= 2):
        template_PE_file.write("            re, re_rdata = self.rege(inst.rege, inst.bit1, bit1, clk_en)\n")
    if(lut_n >= 3):
        template_PE_file.write("            rf, rf_rdata = self.regf(inst.regf, inst.bit2, bit2, clk_en)\n")
    if(lut_n >= 4):
        template_PE_file.write("            rg, rg_rdata = self.regg(inst.regg, inst.bit3, bit3, clk_en)\n")
    if(lut_n >= 5):
        template_PE_file.write("            rh, rh_rdata = self.regf(inst.regh, inst.bit4, bit4, clk_en)\n")
    if(lut_n >= 6):
        template_PE_file.write("            ri, ri_rdata = self.regf(inst.regi, inst.bit5, bit5, clk_en)\n")
    
    
    if(has_3input == 0):
        template_PE_file.write("            res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rd)\n")
    elif(has_3input == 1):
        template_PE_file.write("            res, alu_res_p, Z, N, C, V = self.alu(inst.alu, inst.signed, ra, rb, rc, rd)\n")


    if(lut_n == 1):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd)\n")
    if(lut_n == 2):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd, re)\n")
    if(lut_n == 3):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd, re, rf)\n")
    if(lut_n == 4):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd, re, rf, rg)\n")
    if(lut_n == 5):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd, re, rf, rg, rh)\n")
    if(lut_n == 6):
        template_PE_file.write("            lut_res = self.lut(inst.lut, rd, re, rf, rg, rh ,ri)\n")

    template_PE_file.write("            res_p = self.cond(inst.cond, alu_res_p, lut_res, Z, N, C, V)\n")
    template_PE_file.write("            return res, res_p\n\n") 
    if(has_3input == 0):
        template_PE_file.write("    return my_PE_2input")  
    elif(has_3input == 1):
        template_PE_file.write("    return my_PE_3input")
    template_PE_file.close()
    print("-----------success----------------------\n")
  
    

def main(has_3input,lut_n):
    gen_PE_code(has_3input,lut_n)

if __name__ == "__main__":
    main(int(sys.argv[1]),int(sys.argv[2]))
