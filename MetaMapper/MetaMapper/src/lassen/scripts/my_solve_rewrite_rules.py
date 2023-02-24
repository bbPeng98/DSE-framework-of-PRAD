import sys

import json
import glob
import os
sys.path.append("/home/pengbb/Documents/aha_rr")
#sys.path.append(os.path.abspath(__file__))
#curPath = os.path.abspath(os.path.dirname(__file__))
#rootPath = os.path.split(curPath)[0]
#sys.path.append(rootPath)
import importlib
from pathlib import Path
import multiprocessing
from functools import partial
#from gen_alu_code import gen_alu_code

#import metamapper.coreir_util as cutil
#from metamapper.irs.coreir import gen_CoreIRNodes
#from metamapper import CoreIRContext
from peak.mapper.mapper import ArchMapper
from lassen.sim import PE_fc

#from pysmt.logics import QF_BV

def my_solve_rule(has_3input,rrule):                                        
    dir_path = os.path.dirname(os.path.realpath(__file__))
    rr_path = f'{dir_path}/../lassen/rewrite_rules'
    #is_2input = 1
    from lassen.my_PE_2input import my_PE_fc_2input
    from lassen.my_PE_3input import my_PE_fc_3input
    if(has_3input == 1):
        #print("测试: 现在是3输入")
        arch_mapper = ArchMapper(my_PE_fc_3input)         
    elif(has_3input == 0):
        #print("测试: 现在是2输入")
        arch_mapper = ArchMapper(my_PE_fc_2input)    
    elif(has_3input == 2):
        print("PE_Org")
        arch_mapper = ArchMapper(PE_fc)
    op = Path(rrule).stem     #rrule = '{rr_path}/add.py'  , op = add
    path = Path(f'{rr_path}/{op}.json')

    if not path.is_file():         
        if "pipelined" in op:
            print("Can't solve for pipelined rewrite rules")
            return


        peak_eq = importlib.import_module(f"lassen.rewrite_rules.rewrite_rules_alu.{op}")       

        ir_fc = getattr(peak_eq, op + "_fc")
        #simp_formula = "fp_" in op            
        simp_formula = True            
        ir_mapper = arch_mapper.process_ir_instruction(ir_fc, simple_formula=True)   
        
        print(f"Searching for {op}", flush=True)

        if simp_formula:
            rewrite_rule = ir_mapper.solve('z3')
        #else:
            #rewrite_rule = ir_mapper.solve('btor', logic=QF_BV, external_loop=True, itr_limit=200)
        
        if rewrite_rule is  None:
            print(f"No rewrite rule found for {op}")
        else:
            print(f"\tFound rewrite rule for {op}", flush=True)
            serialized_rr = rewrite_rule.serialize_bindings()
            with open(f'{rr_path}/{op}.json', "w") as write_file:
                json.dump(serialized_rr, write_file, indent=2)
                
    else:                                        
        print("Rewrite rule already found for", op)

def my_solve_rules(rrule_peak_file,has_3input = 0):                              
    dir_path = os.path.dirname(os.path.realpath(__file__))
    print(dir_path)
    rr_path = f'{dir_path}/../lassen/rewrite_rules'
    print(rr_path)
    rrules = glob.glob(f'{rr_path}/[a|m|c|l]*.py')   

    if len(rrule_peak_file) == 0:
        raise ValueError("No rewrite rule peak specifications found")

    pool = multiprocessing.Pool(16)       
    func = partial(my_solve_rule,has_3input)

    # for i in rrule_peak_file:
    #     print(i)
    pool.map(func, rrule_peak_file)


def main(rrule_file,has_3input):                                
    my_solve_rules(rrule_file,has_3input)

if __name__ == '__main__':
    main()
