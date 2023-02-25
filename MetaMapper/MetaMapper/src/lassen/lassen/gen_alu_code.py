#代码用于生成alu模板，放置路径：aha/lassen/lassen/gen_alu_code.py
import os
from lassen.my_alu import my_ALU_t
import sys


def gen_alu_code (has_3input):
    dirpath = os.path.dirname(__file__)
    if(has_3input == 0):
        file1 = open(dirpath+"/template_alu_2input.py","w") 
        file2 = open(dirpath+"/lib_template_alu_2input.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()
            
        template_alu_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/template_alu_2input.py","a")
        print("打开了2input文件\n")
    else:
        file1 = open(dirpath+"/template_alu_3input.py","w") 
        file2 = open(dirpath+"/lib_template_alu_3input.py","r")
        s = file2.read()
        w = file1.write(s)
        
        file1.close()
        file2.close()

        template_alu_file = open("/home/dai-dirk/MetaMapper/MetaMapper/src/lassen/lassen/template_alu_3input.py","a")
        print("打开了文件\n")


    if("Sub" in my_ALU_t.__dict__.keys()):
        template_alu_file.write("            if(alu == my_ALU_t.Sub):\n")
        template_alu_file.write("                b = ~b \n")
        template_alu_file.write("                Cin = Bit(1)\n\n")
        
    if("Sbc" in my_ALU_t.__dict__.keys()):
        template_alu_file.write("            if(alu == my_ALU_t.Sbc):\n")
        template_alu_file.write("                b = ~b \n")
        template_alu_file.write("                Cin = d\n\n")
        
    if("Adc" in my_ALU_t.__dict__.keys()):
        template_alu_file.write("            if(alu == my_ALU_t.Adc):\n")
        template_alu_file.write("                Cin = d\n\n")

    if(has_3input == 0):
        template_alu_file.write("            adder_res, adder_C = UData(a).adc(UData(b), Cin)\n\n")

        if("Add" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Add):\n")
            template_alu_file.write("                res, C = adder_res, adder_C\n")
            template_alu_file.write("                V = overflow(a, b, res)\n")
            template_alu_file.write("                res_p = C\n")

        if("Sub" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Sub):\n")
            template_alu_file.write("                res, C = adder_res, adder_C\n")
            template_alu_file.write("                V = overflow(a, b, res)\n")
            template_alu_file.write("                res_p = C\n")

        if("Adc" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Adc):\n")
            template_alu_file.write("                res, C = adder_res, adder_C\n")
            template_alu_file.write("                V = overflow(a, b, res)\n")
            template_alu_file.write("                res_p = C\n")

        if("Sbc" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Sbc):\n")
            template_alu_file.write("                res, C = adder_res, adder_C\n")
            template_alu_file.write("                V = overflow(a, b, res)\n")
            template_alu_file.write("                res_p = C\n")

        if("Mult0" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult0):\n")
            template_alu_file.write("                res, C, V = mul[:16], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")

        if("Mult1" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult1):\n")
            template_alu_file.write("                res, C, V = mul[8:24], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")

        if("Mult2" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult2):\n")
            template_alu_file.write("                res, C, V = mul[16:32], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")

        if("GTE_Max" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.GTE_Max):\n")
            template_alu_file.write("                res, res_p = max_ab, gte_pred\n")

        if("LTE_Min" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.LTE_Min):\n")
            template_alu_file.write("                res, res_p = min_ab, lte_pred\n")

        if("Abs" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Abs):\n")
            template_alu_file.write("                res, res_p = abs_pred.ite(a, UInt[16](-SInt[16](a))), Bit(a[-1])\n")

        if("Sel" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Sel):\n")
            template_alu_file.write("                res, res_p = d.ite(a, b), Bit(0)\n")

        if("And" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.And):\n")
            template_alu_file.write("                res, res_p = a & b, Bit(0)\n")

        if("Or" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Or):\n")
            template_alu_file.write("                res, res_p = a | b, Bit(0)\n")

        if("XOr" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.XOr):\n")
            template_alu_file.write("                res, res_p = a ^ b, Bit(0)\n")

        if("SHR" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.SHR):\n")
            template_alu_file.write("                res, res_p = shr, Bit(0)\n")

        if("SHL" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.SHL):\n")
            template_alu_file.write("                res, res_p = a << b, Bit(0)\n")

        template_alu_file.write("            N = Bit(res[-1])\n")
        template_alu_file.write("            Z = (res == SData(0))\n")
        template_alu_file.write("            return res, res_p, Z, N, C, V\n\n")
        template_alu_file.write("    return my_ALU\n")
        template_alu_file.close()
    else:
            
        if("TSA" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.TSA):\n")
            template_alu_file.write("                b = ~b\n")
            template_alu_file.write("                Cin = Bit(1)\n")
        if("TSS" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.TSS):\n")
            template_alu_file.write("                b = ~b\n")
            template_alu_file.write("                Cin = Bit(1)\n")
            
        template_alu_file.write("            adder_res, adder_C = UData(a).adc(UData(b), Cin)\n")
            
        template_alu_file.write("            adder2_in0 = mul[:16]\n")
        for st0 in ["TAA","TAS","TSA","TSS"]:
            if(st0 in my_ALU_t.__dict__.keys()):
                template_alu_file.write("            if(alu == my_ALU_t."+st0+"):\n")
                template_alu_file.write("                adder2_in0 = adder_res\n")
            

            # if("TAA" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TAA):\n")
            # template_alu_file.write("               adder2_in0 = adder_res\n")
            #     flag = 1
            # if("TAS" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TAS):\n")
            # template_alu_file.write("               adder2_in0 = adder_res\n")
            #     flag = 1
            # if("TSA" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TSA):\n")
            # template_alu_file.write("               adder2_in0 = adder_res\n")
            #     flag = 1
            # if("TSS" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TSS):\n")
            # template_alu_file.write("               adder2_in0 = adder_res\n")
            #     flag = 1
            # if(flag == 1):
            # template_alu_file.write("           else:\n")
            # template_alu_file.write("               adder2_in0 = mul[:16]\n")
            # else:
            # template_alu_file.write("           adder2_in0 = mul[:16]")

            # flag1 = 0 
        template_alu_file.write("            adder2_in1 = c\n")
        template_alu_file.write("            Cin2 = Bit(0)\n")
        for st1 in ["MULSUB","TAS","TSS"]:
            if(st1 in my_ALU_t.__dict__.keys()):
                template_alu_file.write("            if(alu == my_ALU_t."+st1+"):\n")
                template_alu_file.write("                adder2_in1 = ~c\n")
                template_alu_file.write("                Cin2 = Bit(1)\n")

            

            # if("MULSUB" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.MULSUB):\n")
            # template_alu_file.write("               adder2_in1 = ~c\n")
            # template_alu_file.write("               Cin2 = Bit(1)\n")
            #     flag1 = 1
            # if("TAS" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TAS):\n")
            # template_alu_file.write("               adder2_in1 = ~c\n")
            # template_alu_file.write("               Cin2 = Bit(1)\n")
            #     flag1 = 1
            # if("TSS" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t_3.TSS):\n")
            # template_alu_file.write("               adder2_in1 = ~c\n")
            # template_alu_file.write("               Cin2 = Bit(1)\n")
            #     flag1 = 1
            # if(flag1 == 1):
            # template_alu_file.write("           else:\n")
            # template_alu_file.write("               adder2_in1 = c\n")
            # template_alu_file.write("               Cin2 = Bit(0)\n")
            # else:
            # template_alu_file.write("           adder2_in1 = c\n")
            # template_alu_file.write("           Cin2 = Bit(0)\n")
            
        template_alu_file.write("            adder2_res, adder2_C = UData(adder2_in0).adc(adder2_in1, Cin2)\n")

        for st2 in ["Add","Sub","Adc","Sbc"]:
            if(st2 in my_ALU_t.__dict__.keys()):
                template_alu_file.write("            if(alu == my_ALU_t."+st2+"):\n")
                template_alu_file.write("                res, C = adder_res, adder_C\n")
                template_alu_file.write("                V = overflow(a, b, res)\n")
                template_alu_file.write("                res_p = C\n")
            
        if("Mult0" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult0):\n")
            template_alu_file.write("                res, C, V = mul[:16], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")
        if("Mult1" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult1):\n")
            template_alu_file.write("                res, C, V = mul[8:24], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")
        if("Mult2" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Mult2):\n")
            template_alu_file.write("                res, C, V = mul[16:32], Bit(0), Bit(0)  # wrong C, V\n")
            template_alu_file.write("                res_p = C\n")
        if("GTE_Max" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.GTE_Max):\n")
            template_alu_file.write("                res, res_p = max_ab, gte_pred\n")

        if("LTE_Min" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.LTE_Min):\n")
            template_alu_file.write("                res, res_p = min_ab, lte_pred\n")
        
        if("Abs" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Abs):\n")
            template_alu_file.write("                res, res_p = abs_pred.ite(a, UInt[16](-SInt[16](a))), Bit(a[-1])\n")

        if("Sel" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Sel):\n")
            template_alu_file.write("                res, res_p = d.ite(a, b), Bit(0)\n")

        if("And" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.And):\n")
            template_alu_file.write("                res, res_p = a & b, Bit(0)\n")

        if("Or" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.Or):\n")
            template_alu_file.write("                res, res_p = a | b, Bit(0)\n")
            
        if("XOr" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.XOr):\n")
            template_alu_file.write("                res, res_p = a ^ b, Bit(0)\n")

        if("SHR" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.SHR):\n")
            template_alu_file.write("                res, res_p = shr, Bit(0)\n")

        if("SHL" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.SHL):\n")
            template_alu_file.write("                res, res_p = a << b, Bit(0)\n")
            
        for st3 in ["MULADD","MULSUB","TAA","TSA","TAS","TSS"]:
            if(st3 in my_ALU_t.__dict__.keys()):
                template_alu_file.write("            if(alu == my_ALU_t."+st3+"):\n")
                template_alu_file.write("                res, res_p = adder2_res, Bit(0)\n")

            # if("MULADD" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t.MULADD):\n")
            # template_alu_file.write("               res, res_p = adder2_res, Bit(0)\n")
            # if("MULSUB" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t.MULSUB):\n")
            # template_alu_file.write("               res, res_p = adder2_res, Bit(0)\n")
            # if("SHR" in my_ALU_t.__dict__.keys()):
            # template_alu_file.write("           if(alu == my_ALU_t.SHR):\n")
            # template_alu_file.write("               res, res_p = shr, Bit(0)\n")

        if("CROP" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.CROP):\n")
            template_alu_file.write("                res, res_p = crop_abc, Bit(0)\n")
        if("MULSHR" in my_ALU_t.__dict__.keys()):
            template_alu_file.write("            if(alu == my_ALU_t.MULSHR):\n")
            template_alu_file.write("                res, res_p = mulshift, Bit(0)\n")
    
        template_alu_file.write("            N = Bit(res[-1])\n")
        template_alu_file.write("            Z = (res == SData(0))\n")
        template_alu_file.write("            return res, res_p, Z, N, C, V\n")
        template_alu_file.write("    return my_ALU_3\n")
        template_alu_file.close()
        print("-----------打印完成----------------------\n")
  
    

def main(has_3input):
    gen_alu_code(has_3input)

if __name__ == "__main__":
    main(int(sys.argv[1]))