import pandas as pd
import numpy  as np
import json
import subprocess
import scipy as sp
import torch
import matplotlib.pyplot as plt
import time
from pickle import TRUE
from unicodedata import decimal
from xml.sax import make_parser
from click import option
from numpy import *
from hebo.design_space.design_space import DesignSpace
from hebo.optimizers.hebo import HEBO
from pymoo.factory import get_problem
from pymoo.util.plotting import plot
from pymoo.util.dominator import Dominator
from hebo.optimizers.general import GeneralBO


start_time = time.time()

allSample = {}

def obj(params : pd.DataFrame) -> np.ndarray:

    with open('area.txt', 'r') as a:
        area = float(a.read().strip())
    with open('tile_num_pe.txt', 'r') as p:   
        pew = float(p.read().strip())
    with open('parseroute.txt', 'r') as l:   
        sbNum = float(l.read().strip())
    with open('mappingFailureRate.txt', 'r') as m:   
        mappingFailureRate = float(m.read().strip())
    with open('tile_num_mem.txt', 'r') as p:   
        memw = float(p.read().strip())
    with open('tile_num_io.txt', 'r') as p:   
        iow = float(p.read().strip())
    x = 1
    y = 10000000
    z = 100000
    k = 1
    l = 10000000
    q = 10000000
    comprehensive = x*area+y*pew+z*sbNum+k*mappingFailureRate+memw*l+iow*q

    return np.array(comprehensive).reshape(-1, 1)
 

def formResult(spec):
    with open('area.txt', 'r') as a:
        area = float(a.read().strip())
    with open('tile_num_pe.txt', 'r') as p:   
        pew = float(p.read().strip())
    with open('parseroute.txt', 'r') as l:   
        sbNum = float(l.read().strip())
    with open('mappingFailureRate.txt', 'r') as m:   
        mappingFailureRate = float(m.read().strip())
    with open('tile_num_mem.txt', 'r') as p:   
        memw = float(p.read().strip())
    with open('tile_num_io.txt', 'r') as p:   
        iow = float(p.read().strip())
    x = 1
    y = 10000000
    z = 100000
    k = 1
    l = 10000000
    q = 10000000
    key = x*area+y*pew+z*sbNum+k*mappingFailureRate+memw*l+iow*q
    allSample[key] = spec
    restoreResult = [key]
    result = [area,pew,sbNum,mappingFailureRate,memw,iow]
    return (restoreResult,result)


# params = [
#     {'name' : 'num_row',                      'type' : 'int', 'lb' : 4, 'ub' : 24 },
#     {'name' : 'num_colum',                    'type' : 'int', 'lb' : 4, 'ub' : 24 },
#     {'name' : 'num_track_coarse',             'type' : 'int', 'lb' : 1, 'ub' : 6  },
#     {'name' : 'num_track_fine',               'type' : 'int', 'lb' : 1, 'ub' : 6  }, 
#     {'name' : 'PEinputnumCoarse',             'type' : 'int', 'lb' : 2, 'ub' : 3  },
#     {'name' : 'PEinputnumFine',               'type' : 'int', 'lb' : 1, 'ub' : 6  },
#     {'name' : 'num_otrack_per_opin_coarse',   'type' : 'int', 'lb' : 1, 'ub' : 12 },
#     {'name' : 'num_itrack_per_ipin_coarse',   'type' : 'int', 'lb' : 1, 'ub' : 12 },
#     {'name' : 'num_ipin_per_opin_coarse',     'type' : 'int', 'lb' : 1, 'ub' : 6  },
#     {'name' : 'num_otrack_per_opin_fine',     'type' : 'int', 'lb' : 1, 'ub' : 12 },
#     {'name' : 'num_itrack_per_ipin_fine',     'type' : 'int', 'lb' : 1, 'ub' : 12 },
#     {'name' : 'num_ipin_per_opin_fine',       'type' : 'int', 'lb' : 1, 'ub' : 6  },
#     {'name' : 'diag_iopin_connect',           'type' : 'bool'                     }
# ]

params = [
    {'name' : 'num_row',                      'type' : 'int', 'lb' : 4, 'ub' : 24 },
    {'name' : 'num_colum',                    'type' : 'int', 'lb' : 4, 'ub' : 24 },
    {'name' : 'num_track_coarse',             'type' : 'int', 'lb' : 1,  'ub' : 6  },
    {'name' : 'num_track_fine',               'type' : 'int', 'lb' : 1,  'ub' : 6  }, 
    {'name' : 'PEinputnumCoarse',             'type' : 'int', 'lb' : 3,  'ub' : 3  },
    {'name' : 'PEinputnumFine',               'type' : 'int', 'lb' : 3,  'ub' : 3  },
    {'name' : 'num_otrack_per_opin_coarse',   'type' : 'int', 'lb' : 2,  'ub' : 12 },
    {'name' : 'num_itrack_per_ipin_coarse',   'type' : 'int', 'lb' : 2,  'ub' : 12 },
    {'name' : 'num_ipin_per_opin_coarse',     'type' : 'int', 'lb' : 2,  'ub' : 6  },
    {'name' : 'num_otrack_per_opin_fine',     'type' : 'int', 'lb' : 2,  'ub' : 12 },
    {'name' : 'num_itrack_per_ipin_fine',     'type' : 'int', 'lb' : 2,  'ub' : 12 },
    {'name' : 'num_ipin_per_opin_fine',       'type' : 'int', 'lb' : 2,  'ub' : 6  }
    #{'name' : 'diag_iopin_connect',           'type' : 'bool'                      }
]
# params = [
#     {'name' : 'num_row',                      'type' : 'int', 'lb' : 11, 'ub' : 11},
#     {'name' : 'num_colum',                    'type' : 'int', 'lb' : 4, 'ub' : 4},
#     {'name' : 'num_track_coarse',             'type' : 'int', 'lb' : 2,  'ub' : 2},
#     {'name' : 'num_track_fine',               'type' : 'int', 'lb' : 1,  'ub' : 1}, 
#     {'name' : 'PEinputnumCoarse',             'type' : 'int', 'lb' : 3,  'ub' : 3  },
#     {'name' : 'PEinputnumFine',               'type' : 'int', 'lb' : 3,  'ub' : 3  },
#     {'name' : 'num_otrack_per_opin_coarse',   'type' : 'int', 'lb' : 6,  'ub' :6 },
#     {'name' : 'num_itrack_per_ipin_coarse',   'type' : 'int', 'lb' : 6,  'ub' :6 },
#     {'name' : 'num_ipin_per_opin_coarse',     'type' : 'int', 'lb' : 4,  'ub' : 4  },
#     {'name' : 'num_otrack_per_opin_fine',     'type' : 'int', 'lb' : 2,  'ub' : 2 },
#     {'name' : 'num_itrack_per_ipin_fine',     'type' : 'int', 'lb' : 2,  'ub' : 2 },
#     {'name' : 'num_ipin_per_opin_fine',       'type' : 'int', 'lb' : 4,  'ub' :  4  }
#     #{'name' : 'diag_iopin_connect',           'type' : 'bool'                      }
# ]

op = {  "diag_iopin_connect"        : True,
        "track_reged_mode"          : 2,
        "data_width"                : 16,
        "cfg_data_width"            : 32,
        "cfg_addr_width"            : 32,
        "cfg_addr_width_Unit"       : 8,
        "cfg_blk_offset"            : 4,
        "functionSelect"            : 1,
        "interconnect_output_ports" : 2,
        "mem_width"                 : 64,
        "mem_depth"                 : 512,
        "use_sram_stub"             : 0,
        "iterator_support"          : 6,
        "config_width"              : 16,
        "interconnect_input_ports"  : 2,
        "agg_addr_width"            : 4,
        "agg_iter_support"          : 6,
        "agg_range_width"           : 16,
        "tb_range_width"            : 16,
        "tb_addr_width"             : 4,
        "banks"                     : 1,
        "tb_height"                 : 2,
        "agg_height"                : 4,
        "agg_rd_addr_gen_width"     : 8,
        "operations" : {"Add" : 0,
        "Sub" : 1 ,
        "Adc" : 2 ,
        "Sbc" : 3 ,
        "Abs" : 4 ,
        "GTE_Max" : 5,
        "LTE_Min" : 6,
        "Sel" :7,
        "Mult0" :8,
        "Mult1" :9,
        "Mult2" :10,
        "SHR" :11,
        "SHL" :12,
        "Or" :13,
        "And" :14,
        "XOr" :15,
        "MULADD" :16,
        "MULSUB" :17,
        "TAA" :18,
        "TAS" :19,
        "TSA" :20,
        "TSS" :21,
        "CROP" :22,
        "MULSHR" :23 }
    }

argsjson = {
        "op" : ["Add", "Sub", "Adc", "Abs", "GTE_Max", "LTE_Min", "Sbc", "Sel",
                "Mult0", "Mult1", "Mult2", "SHR", "SHL", "Or", "And", "XOr", 
                "MULADD", "MULSUB", "TAA", "TAS", "TSA", "TSS", "CROP", "MULSHR"]
    }


def formatSpec(sample : dict) -> dict:
    connect_flexibility_coarse = {
        'num_otrack_per_opin' : sample['num_otrack_per_opin_coarse'],
        'num_itrack_per_ipin' : sample['num_itrack_per_ipin_coarse'],
        'num_ipin_per_opin' : sample['num_ipin_per_opin_coarse']
    }
    del sample['num_otrack_per_opin_coarse']
    del sample['num_itrack_per_ipin_coarse']
    del sample['num_ipin_per_opin_coarse']
    sample['connect_flexibility_coarse'] = connect_flexibility_coarse

    connect_flexibility_fine = {
        'num_otrack_per_opin' : sample['num_otrack_per_opin_fine'],
        'num_itrack_per_ipin' : sample['num_itrack_per_ipin_fine'],
        'num_ipin_per_opin' : sample['num_ipin_per_opin_fine']
    }
    del sample['num_otrack_per_opin_fine']
    del sample['num_itrack_per_ipin_fine']
    del sample['num_ipin_per_opin_fine']
    sample['connect_flexibility_fine'] = connect_flexibility_fine

    lut_n = sample['PEinputnumFine']
    sample['lut_n'] = lut_n

    has_3input = sample['PEinputnumCoarse'] - 2
    sample['has_3input'] = has_3input

    PEinputnum = [sample['PEinputnumCoarse'],sample['PEinputnumFine']]
    del sample['PEinputnumCoarse']
    del sample['PEinputnumFine']
    sample['PEinputnum'] = PEinputnum

    return sample

#select benchmark
def run_cgra():
    detect1 = subprocess.run('cd ../ && ./pnr_new.sh "conv_2input"', shell=True).returncode
    detect2 = subprocess.run('cp ../Chisel/chisel-AHA9.0/area.txt .',shell=True).returncode
    detect3 = subprocess.run('rm ../Chisel/chisel-AHA9.0/area.txt',shell=True).returncode
    detect4 = subprocess.run('cp ../benchmarks/conv_2input/parseroute.txt .',shell=True).returncode
    detect5 = subprocess.run('rm ../benchmarks/conv_2input/parseroute.txt',shell=True).returncode
    detect6 = subprocess.run('cp ../benchmarks/tile_num_pe.txt .',shell=True).returncode
    detect7 = subprocess.run('rm ../benchmarks/tile_num_pe.txt',shell=True).returncode
    detect8 = subprocess.run('cp ../benchmarks/tile_num_mem.txt .',shell=True).returncode
    detect9 = subprocess.run('rm ../benchmarks/tile_num_mem.txt',shell=True).returncode
    detect10 = subprocess.run('cp ../benchmarks/tile_num_io.txt .',shell=True).returncode
    detect11 = subprocess.run('rm ../benchmarks/tile_num_io.txt',shell=True).returncode
    if (detect1==1 or detect2==1 or detect3==1 or detect4==1 or detect5==1 or detect6==1 or detect7==1 or detect8==1 or detect9==1 or detect10==1 or detect11==1): raise TypeError


space = DesignSpace().parse(params)

opt   = HEBO(space)

print('  <<<<< design space exploration begin >>>>>')


result = []
    
y = []
keyAndSignleValue = []

it = 80
validNum = 0
for i in range(it):
    rec = opt.suggest(n_suggestions=1)
    sample = rec.to_dict('records')[0]
    spec = formatSpec(sample)
    spec.update(**op)

    track_coarse = spec['num_track_coarse']
    if(spec["connect_flexibility_coarse"]["num_itrack_per_ipin"] <= 2*track_coarse):
        if(spec["connect_flexibility_coarse"]["num_itrack_per_ipin"]%2 != 0):
            spec["connect_flexibility_coarse"]["num_itrack_per_ipin"] = spec["connect_flexibility_coarse"]["num_itrack_per_ipin"] - 1
    else:
        spec["connect_flexibility_coarse"]["num_itrack_per_ipin"] = 2*track_coarse

    if(spec["connect_flexibility_coarse"]["num_otrack_per_opin"] <= 2*track_coarse):
        if(spec["connect_flexibility_coarse"]["num_otrack_per_opin"]%2 != 0):
            spec["connect_flexibility_coarse"]["num_otrack_per_opin"] = spec["connect_flexibility_coarse"]["num_otrack_per_opin"] - 1
    else:
        spec["connect_flexibility_coarse"]["num_otrack_per_opin"] = 2*track_coarse

    
    track_fine = spec['num_track_fine']
    if(spec["connect_flexibility_fine"]["num_itrack_per_ipin"] <= 2*track_fine):
        if(spec["connect_flexibility_fine"]["num_itrack_per_ipin"]%2 != 0):
            spec["connect_flexibility_fine"]["num_itrack_per_ipin"] = spec["connect_flexibility_fine"]["num_itrack_per_ipin"] - 1
    else:
        spec["connect_flexibility_fine"]["num_itrack_per_ipin"] = 2*track_fine

    if(spec["connect_flexibility_fine"]["num_otrack_per_opin"] <= 2*track_fine):
        if(spec["connect_flexibility_fine"]["num_otrack_per_opin"]%2 != 0):
            spec["connect_flexibility_fine"]["num_otrack_per_opin"] = spec["connect_flexibility_fine"]["num_otrack_per_opin"] - 1
    else:
        spec["connect_flexibility_fine"]["num_otrack_per_opin"] = 2*track_fine
   
    if(spec["connect_flexibility_coarse"]["num_ipin_per_opin"]%2 != 0):
        spec["connect_flexibility_coarse"]["num_ipin_per_opin"] = spec["connect_flexibility_coarse"]["num_ipin_per_opin"] -1

    if(spec["connect_flexibility_fine"]["num_ipin_per_opin"]%2 != 0):
        spec["connect_flexibility_fine"]["num_ipin_per_opin"] = spec["connect_flexibility_fine"]["num_ipin_per_opin"] -1
    
    argsjson["lut_n"] = spec["lut_n"]
    argsjson["has_3input"] = spec["has_3input"]

    # num_itrack_per_ipin_l = spec["num_itrack_per_ipin_l"] if (spec["num_itrack_per_ipin_l"] <= 2*track) else 2*track
    # num_otrack_per_opin_l = spec["num_otrack_per_opin_l"] if (spec["num_otrack_per_opin_l"] <= 2*track) else 2*track
    # fclist_l = []
    # fclist_l.append(num_itrack_per_ipin_l)
    # fclist_l.append(num_otrack_per_opin_l)
    # fclist_l.append(spec["num_ipin_per_opin_l"])


    with open('../../MetaMapper/MetaMapper/src/lassen/lassen/args.json', 'w') as a:
        json.dump(argsjson, a, indent=4)

    with open('cgra_spec.json', 'w') as f:
        json.dump(spec, f, indent=4)

    subprocess.run('cp cgra_spec.json ../Chisel/chisel-AHA9.0/src/main/resources/', shell=True)
        
    try:
        run_cgra()
    except TypeError:
        print("RUNNING ERROR")
        # with open('area.txt', 'w') as a:
        #     a.write("10000000")
        with open('tile_num_pe.txt', 'w') as p:   
            p.write("1")
        with open('parseroute.txt', 'w') as l:   
            l.write("800")
        with open('mappingFailureRate.txt', 'w') as m:   
            m.write("1")
        with open('tile_num_mem.txt', 'w') as p:   
            p.write("1")
        with open('tile_num_io.txt', 'w') as p:   
            p.write("1")
    
        opt.observe(rec, obj(rec))

        restoreResult = formResult(spec)[0]
        
        if(i==0):
            y.append(restoreResult[0])
            keyAndSignleValue.append(formResult(spec))
        elif(restoreResult[0] < opt.y.min()):
            y.append(restoreResult[0])
            keyAndSignleValue.append(formResult(spec))
        else:
            y.append( opt.y.min() )
        
        continue

    
    opt.observe(rec, obj(rec))

    restoreResult = formResult(spec)[0]
    
    if(i==0):
        y.append(restoreResult[0])
        keyAndSignleValue.append(formResult(spec))
    elif(restoreResult[0] < opt.y.min()):
        y.append(restoreResult[0])
        keyAndSignleValue.append(formResult(spec))
    else:
        y.append( opt.y.min() )
    
    print('After %d iterations, best obj is %.2f' % (i, opt.y.min()))
    keyAndSignleValue.append(formResult(spec))
    validNum += 1


resultKey = opt.y.min()
if(resultKey.size!=0):
    print(allSample[resultKey.astype(np.float)])
    for j in range(len(keyAndSignleValue)):
        if(keyAndSignleValue[j][0]==resultKey):
            print(keyAndSignleValue[j][1])
        else:
            continue
else:
    print("no valid arch reached")

print('\n the number of valid para iters are:%d' %validNum)


print('\n <<<<< start optimizing >>>>>')
optIter = 0
finalArea = 0.0
finalPEw = 0.0
finalSbNum = 0.0
finalMappingFailureRate = 0.0
finalMEMw = 0.0
finalIOw = 0.0
beforeOpt = allSample[resultKey.astype(np.float)]
if(resultKey.size!=0):
    while(1):
        beforeOpt['num_row'] = beforeOpt['num_row'] - 1
        with open('cgra_spec.json', 'w') as f:
            json.dump(beforeOpt, f, indent=4)
        subprocess.run('cp cgra_spec.json ../Chisel/chisel-AHA9.0/src/main/resources/', shell=True)

        argsjson["lut_n"] = beforeOpt["lut_n"]
        argsjson["has_3input"] = beforeOpt["has_3input"]
        with open('../../MetaMapper/MetaMapper/src/lassen/lassen/args.json', 'w') as a:
            json.dump(argsjson, a, indent=4)

        try:
            run_cgra()
            with open('area.txt', 'r') as a:
                finalArea = float(a.read().strip())
            with open('tile_num_pe.txt', 'r') as p:   
                finalPEw = float(p.read().strip())
            with open('tile_num_mem.txt', 'r') as p:   
                finalMEMw = float(p.read().strip())
            with open('tile_num_io.txt', 'r') as p:   
                finalIOw = float(p.read().strip())
            with open('parseroute.txt', 'r') as l:   
                finalSbNum = float(l.read().strip())
            with open('mappingFailureRate.txt', 'r') as m:   
                finalMappingFailureRate = float(m.read().strip())
            optIter += 1
            
        except TypeError:
            beforeOpt['num_row'] = beforeOpt['num_row'] + 1
            break
    
    while(1):
        beforeOpt['num_colum'] = beforeOpt['num_colum'] - 1
        with open('cgra_spec.json', 'w') as f:
            json.dump(beforeOpt, f, indent=4)
        subprocess.run('cp cgra_spec.json ../Chisel/chisel-AHA9.0/src/main/resources/', shell=True)

        argsjson["lut_n"] = beforeOpt["lut_n"]
        argsjson["has_3input"] = beforeOpt["has_3input"]
        with open('../../MetaMapper/MetaMapper/src/lassen/lassen/args.json', 'w') as a:
            json.dump(argsjson, a, indent=4)

        try:
            run_cgra()
            with open('area.txt', 'r') as a:
                finalArea = float(a.read().strip())
            with open('tile_num_pe.txt', 'r') as p:   
                finalPEw = float(p.read().strip())
            with open('tile_num_mem.txt', 'r') as p:   
                finalMEMw = float(p.read().strip())
            with open('tile_num_io.txt', 'r') as p:   
                finalIOw = float(p.read().strip())
            with open('parseroute.txt', 'r') as l:   
                finalSbNum = float(l.read().strip())
            with open('mappingFailureRate.txt', 'r') as m:   
                finalMappingFailureRate = float(m.read().strip())
            optIter += 1
        except TypeError:
            beforeOpt['num_colum'] = beforeOpt['num_colum'] + 1
            break

    while(1):
        beforeOpt['num_track_coarse'] = beforeOpt['num_track_coarse'] - 1
        with open('cgra_spec.json', 'w') as f:
            json.dump(beforeOpt, f, indent=4)
        subprocess.run('cp cgra_spec.json ../Chisel/chisel-AHA9.0/src/main/resources/', shell=True)

        argsjson["lut_n"] = beforeOpt["lut_n"]
        argsjson["has_3input"] = beforeOpt["has_3input"]
        with open('../../MetaMapper/MetaMapper/src/lassen/lassen/args.json', 'w') as a:
            json.dump(argsjson, a, indent=4)

        try:
            run_cgra()
            with open('area.txt', 'r') as a:
                finalArea = float(a.read().strip())
            with open('tile_num_pe.txt', 'r') as p:   
                finalPEw = float(p.read().strip())
            with open('tile_num_mem.txt', 'r') as p:   
                finalMEMw = float(p.read().strip())
            with open('tile_num_io.txt', 'r') as p:   
                finalIOw = float(p.read().strip())
            with open('parseroute.txt', 'r') as l:   
                finalSbNum = float(l.read().strip())
            with open('mappingFailureRate.txt', 'r') as m:   
                finalMappingFailureRate = float(m.read().strip())
            optIter += 1
        except TypeError:
            beforeOpt['num_track_coarse'] = beforeOpt['num_track_coarse'] + 1
            break

    while(1):
        beforeOpt['num_track_fine'] = beforeOpt['num_track_fine'] - 1
        with open('cgra_spec.json', 'w') as f:
            json.dump(beforeOpt, f, indent=4)
        subprocess.run('cp cgra_spec.json ../Chisel/chisel-AHA9.0/src/main/resources/', shell=True)

        argsjson["lut_n"] = beforeOpt["lut_n"]
        argsjson["has_3input"] = beforeOpt["has_3input"]
        with open('../../MetaMapper/MetaMapper/src/lassen/lassen/args.json', 'w') as a:
            json.dump(argsjson, a, indent=4)

        try:
            run_cgra()
            with open('area.txt', 'r') as a:
                finalArea = float(a.read().strip())
            with open('tile_num_pe.txt', 'r') as p:   
                finalPEw = float(p.read().strip())
            with open('tile_num_mem.txt', 'r') as p:   
                finalMEMw = float(p.read().strip())
            with open('tile_num_io.txt', 'r') as p:   
                finalIOw = float(p.read().strip())
            with open('parseroute.txt', 'r') as l:   
                finalSbNum = float(l.read().strip())
            with open('mappingFailureRate.txt', 'r') as m:   
                finalMappingFailureRate = float(m.read().strip())
            optIter += 1
        except TypeError:
            beforeOpt['num_track_fine'] = beforeOpt['num_track_fine'] + 1
            break

    if(optIter!=0):
        print('\nThe optimal parameters are as follows:')
        track_coarse = beforeOpt['num_track_coarse']
        if(beforeOpt["connect_flexibility_coarse"]["num_itrack_per_ipin"] >= 2*track_coarse):
            beforeOpt["connect_flexibility_coarse"]["num_itrack_per_ipin"] = 2*track_coarse
        if(beforeOpt["connect_flexibility_coarse"]["num_otrack_per_opin"] >= 2*track_coarse):
            beforeOpt["connect_flexibility_coarse"]["num_otrack_per_opin"] = 2*track_coarse

        track_fine = beforeOpt['num_track_fine']
        if(beforeOpt["connect_flexibility_fine"]["num_itrack_per_ipin"] >= 2*track_fine):
            beforeOpt["connect_flexibility_fine"]["num_itrack_per_ipin"] = 2*track_fine
        if(beforeOpt["connect_flexibility_fine"]["num_otrack_per_opin"] >= 2*track_fine):
            beforeOpt["connect_flexibility_fine"]["num_otrack_per_opin"] = 2*track_fine
        
        print(beforeOpt)
        print('the area is: %f'%finalArea)
        print('the PE usage is: %f'%(1-finalPEw))
        print('the MEM usage is: %f'%(1-finalMEMw))
        print('the IO usage is: %f'%(1-finalIOw))
        print('the SB num is: %f'%finalSbNum)
        print('the success rate is:%f'%(1-finalMappingFailureRate))
    else:
        print('\nThe optimal parameters are as follows:')
        print(allSample[resultKey.astype(np.float)])
        for j in range(len(keyAndSignleValue)):
            if(keyAndSignleValue[j][0]==resultKey):
                print('the area is: %f'%keyAndSignleValue[j][1][0])
                print('the PE usage is: %f'%(1-keyAndSignleValue[j][1][1]))
                print('the MEM usage is: %f'%(1-keyAndSignleValue[j][1][4]))
                print('the IO usage is: %f'%(1-keyAndSignleValue[j][1][5]))
                print('the SB num is: %f'%keyAndSignleValue[j][1][2])
                print('the success rate is:%f'%(1-keyAndSignleValue[j][1][3]))
            else:
                continue
else:
    print("no valid arch reached, optimization failed")



print('\n <<<<< design space exploration finished >>>>>')
end_time = time.time()
print('\n Total Time = '+str(end_time-start_time)+'\n')


