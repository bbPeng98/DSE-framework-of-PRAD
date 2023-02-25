import sys
import glob, os
from lassen.my_alu import my_ALU_t
from scripts.my_solve_rewrite_rules import my_solve_rules

from lassen.gen_PE_code import gen_PE_code

import json

# if input("This will delete all saved rewrite rules, only do this if you are changing the PE hardware, are you sure you want to continue? (y/n)") != "y":
#         exit()



dir_path = os.path.dirname(os.path.realpath(__file__))
with open(f"{dir_path}/../lassen/args.json") as f:
    attr = json.load(f)
    has_3input = attr["has_3input"]
    lut_n = attr["lut_n"]

gen_PE_code(has_3input,lut_n)  

dir_path = os.path.dirname(os.path.realpath(__file__))
rr_path_alu = f'{dir_path}/../lassen/rewrite_rules/rewrite_rules_alu'

rrule_files = []
rrule_peak_files = []
rrule_files = glob.glob(f'{rr_path_alu}/../*.json')
remove_file = glob.glob(f"{rr_path_alu}/*pipelined.py")

if has_3input == 0:
    with open(f"{dir_path}/../lassen/op2.json",encoding='utf-8') as f:
        op_class = json.load(f)
elif has_3input == 1:
    with open(f"{dir_path}/../lassen/op3.json",encoding='utf-8') as f:
        op_class = json.load(f)
f.close


for op_name in my_ALU_t.__dict__:
    if op_name in op_class.keys():
        print(op_name)
        for op_rr in op_class[op_name]: 
            #rrule_files.append(f"{rr_path_alu}/.json")
            rrule_peak_files.append(f"{rr_path_alu}/{op_rr}.py")


rrule_peak_files_bit = glob.glob(f"{rr_path_alu}/b*.py")
rrule_peak_files.extend(rrule_peak_files_bit)


print("Removing saved rewrite rules")                    
for file_ in rrule_files:
    os.remove(file_)

# for file_ in rrule_peak_files:
#     print("???111"+file_)
#     if str("pipelined") in str(file_):
#         os.remove(file_)
#         #rrule_peak_file = rrule_peak_files.remove(file_)


#remove_file = rrule_peak_files
for re in remove_file:
    if str("pipelined") in str(re):
        try:
            rrule_peak_files.remove(re)
            os.remove(re)
        except:
            continue


my_solve_rules(rrule_peak_files,has_3input)

print("Generating pipelined rules")


i = 0
for file_ in rrule_peak_files:
    #print(f"{i:3}: {file_}")
    i=i+1

for file_ in rrule_peak_files:
        #print(f"{file_} : ", end="")
    
        op = os.path.basename(file_).split(".")[0]
        file_name = os.path.basename(file_).split(".")[0]
        new_filename = f"{os.path.dirname(file_)}/{file_name}_pipelined.py"
        
        
        fin = open(file_, "r")
        fout = open(new_filename, "w")
        fin_lines = fin.readlines()
        reg_line = False
        for line in fin_lines:
            write_line = line
            write_line = write_line.replace(f" {op}_fc", f" {op}_pipelined_fc")
            write_line = write_line.replace(f" {op}(Peak", f" {op}_pipelined(Peak")
            write_line = write_line.replace(f"return {op}", f"return {op}_pipelined")
            fout.write(write_line)

        json_file_ = f"{os.path.dirname(file_)}/../{file_name}.json"
        new_filename = f"{os.path.dirname(file_)}/../{file_name}_pipelined.json"
         
        try:
            fin = open(json_file_, "r")           
        except:
            print("\nno such file\n")
            continue
        fin = open(json_file_, "r")  
        fin = open(json_file_, "r")
        fout = open(new_filename, "w")
        fin_lines = fin.readlines()
        reg_line = False
        for line in fin_lines:
            write_line = line
            if '"width": 2,' in line:
                reg_line = True
            else:
                if reg_line:
                    write_line = write_line.replace('"value": 2', '"value": 3')
                reg_line = False

            fout.write(write_line)

       # print(f"Generated {file_name}_pipelined")
