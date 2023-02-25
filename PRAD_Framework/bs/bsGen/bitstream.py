from ctypes.wintypes import PINT
import os
import json
from typing import Tuple
from unittest import result
from webbrowser import get
from math import ceil
import argparse

# track_fine = 5
# track_coarse = 5

def replace(search_text,replace_text,filename):
    with open(filename, 'r+',encoding='UTF-8') as file:
        data = file.read()
        file.seek(0)
        data = data.replace(search_text, replace_text)
        file.truncate(0)
        file.write(data)

    print("replace finish")


def get_data_common(index_low, num):
    if index_low > 31:
        index_low = index_low % 32
    return (num << index_low)

def get_data_spec(index_high, index_low, num):
    if index_high > 31:
        index = index_high % 32
    num = num >> (index_high - index_low - index)
    return num

def get_data_correct(data):
    if (len(bin(data)[2:]) > 32):
        print('before deal: '+ bin(data))
        print('after deal: '+'0b'+bin(data)[2+len(bin(data)[2:])-32:])
        print(int(bin(data)[2+len(bin(data)[2:])-32:],2))
        return int(bin(data)[2+len(bin(data)[2:])-32:],2)
    else:
        print('bin data is: '+bin(data))
        print(data)
        return data


"""
1st: generate PNR's bitstream
2nd: generate mapped's bitstream
"""
def get_route_bs(GIB_fine_jsonfile, GIB_coarse_jsonfile, GIB_routefile, track_file):
    if(os.path.exists('./out/config.bs')):
        os.remove('./out/config.bs')
    cfg_addr_data = {}
    portwithaddr = {
        'data0' : 11,
        'data1' : 12,
        'data2' : 13,
        'bit0' : 14,
        'bit1' : 15,
        'bit2' : 16,
        'bit3' : 17,
        'bit4' : 18,
        'bit5' : 19,
        'bit6' : 20,
        'bit7' : 21,
        'chain_data_in_0' : 100,
        'chain_data_in_1' : 101,
        'data_in_0' : 102,
        'data_in_1' : 103,
        'addr_in_0' : 104,
        'addr_in_1' : 105,
        'flush' : 106,
        'wen_in_0' : 107,
        'wen_in_1' : 108,
        'ren_in_0' : 109,
        'ren_in_1' : 110,
    }
    sidewithsel = {
        '4' : 0,
        '5' : 1,
        '6' : 2,
        '7' : 3,
    }
    with open(track_file) as f:
        cgra_ifo = json.load(f)
    track_fine = cgra_ifo['num_track_fine']
    track_coarse = cgra_ifo['num_track_coarse']
    print('track_fine: '+str(track_fine))
    print('track_coarse: '+str(track_coarse))

    with open(GIB_fine_jsonfile) as f:
        GIB_fine = json.load(f)
    with open(GIB_coarse_jsonfile) as f:
        GIB_coarse = json.load(f)
    with open(GIB_routefile, encoding='utf-8') as file_obj:
        lines = file_obj.readlines()

    current_node = []
    last_node = []


    for line in lines:
        line_list = line.split(" ")
        if((len(line_list) != 2) and (len(line_list) != 3)):
            last_node = []
            # print("line is not useable: " + line + "length= " + str(len(line_list)))
            continue
        current_node = line_list
        if len(last_node) == 0:
            last_node = ["PORT"]

        if last_node[0] ==  "GIB" and current_node[0] == "GIB":
            cn = current_node[1].split(",")
            ln = last_node[1].split(",")
            if (cn[-1] == "1\n"):
                src_list = GIB_fine[str((int(cn[1]),int(cn[2]),1)).replace(', ',',')][str((int(cn[3]),int(cn[0]))).replace(', ',',')][0]
                cfg_list = GIB_fine[str((int(cn[1]),int(cn[2]),1)).replace(', ',',')][str((int(cn[3]),int(cn[0]))).replace(', ',',')][1]
                for i in range(len(src_list)):
                    if int(ln[3]) == src_list[i][1] and int(ln[0]) == src_list[i][2]:
                        if (cfg_list[0]//32) == (cfg_list[1]//32):
                            addr_high = cfg_list[0]//32
                            addr = int(cn[2]) + int(cn[1])*(16**2) + 1*(16**4) + addr_high*(16**6)
                            data = get_data_common(cfg_list[1],i)
                            if addr in cfg_addr_data.keys():
                                cfg_addr_data[addr] = data | cfg_addr_data[addr]
                            else:
                                cfg_addr_data[addr] = data
                        else:
                            addr_high1 = cfg_list[1]//32
                            addr_high2 = cfg_list[0]//32
                            addr1 = int(cn[2]) + int(cn[1])*(16**2) + 1*(16**4) + addr_high1*(16**6)
                            addr2 = int(cn[2]) + int(cn[1])*(16**2) + 1*(16**4) + addr_high2*(16**6)
                            data1 = get_data_common(cfg_list[1],i)
                            data1 = get_data_correct(data1)
                            data2 = get_data_spec(cfg_list[0],cfg_list[1],i)
                            if addr1 in cfg_addr_data.keys():
                                cfg_addr_data[addr1] = data1 | cfg_addr_data[addr1]
                            else:
                                cfg_addr_data[addr1] = data1
                            if addr2 in cfg_addr_data.keys():
                                cfg_addr_data[addr2] = data2 | cfg_addr_data[addr2]
                            else:
                                cfg_addr_data[addr2] = data2
            else:
                src_list = GIB_coarse[str((int(cn[1]),int(cn[2]),16)).replace(', ',',')][str((int(cn[3]),int(cn[0]))).replace(', ',',')][0]
                cfg_list = GIB_coarse[str((int(cn[1]),int(cn[2]),16)).replace(', ',',')][str((int(cn[3]),int(cn[0]))).replace(', ',',')][1]
                for i in range(len(src_list)):
                    # src_list[i].pop(0)
                    if int(ln[3]) == src_list[i][1] and int(ln[0]) == src_list[i][2]:
                        if (cfg_list[0]//32) == (cfg_list[1]//32):
                            addr_high = cfg_list[0]//32
                            addr = int(cn[2]) + int(cn[1])*(16**2) + 0*(16**4) + addr_high*(16**6)
                            data = get_data_common(cfg_list[1],i)
                            if addr in cfg_addr_data.keys():
                                cfg_addr_data[addr] = data | cfg_addr_data[addr]
                            else:
                                cfg_addr_data[addr] = data
                        else:
                            addr_high1 = cfg_list[1]//32
                            addr_high2 = cfg_list[0]//32
                            addr1 = int(cn[2]) + int(cn[1])*(16**2) + 0*(16**4) + addr_high1*(16**6)
                            addr2 = int(cn[2]) + int(cn[1])*(16**2) + 0*(16**4) + addr_high2*(16**6)
                            data1 = get_data_common(cfg_list[1],i)
                            data1 = get_data_correct(data1)
                            data2 = get_data_spec(cfg_list[0],cfg_list[1],i)
                            if addr1 in cfg_addr_data.keys():
                                cfg_addr_data[addr1] = data1 | cfg_addr_data[addr1]
                            else:
                                cfg_addr_data[addr1] = data1
                            if addr2 in cfg_addr_data.keys():
                                cfg_addr_data[addr2] = data2 | cfg_addr_data[addr2]
                            else:
                                cfg_addr_data[addr2] = data2
            last_node = line_list
        elif last_node[0] ==  "REG" and current_node[0] == "RMUX":
            cn = current_node[2].split(",")
            ln = last_node[2].split(",")
            RMUX_list = current_node[1].split('_')
            #1-bit
            if (cn[-1] == "1\n"):
                addr = int(cn[1]) + int(cn[0])*(16**2) + 1*(16**4) + 10*(16**6) 
                # print('index_low: ',int(RMUX_list[0])*track+int(RMUX_list[1]))
                data = get_data_common(int(RMUX_list[0])*track_fine+int(RMUX_list[1]),1)
                if addr in cfg_addr_data.keys():
                    cfg_addr_data[addr] = data | cfg_addr_data[addr]
                else:
                    cfg_addr_data[addr] = data
            else:
                addr = int(cn[1]) + int(cn[0])*(16**2) + 0*(16**4) + 10*(16**6)
                data = get_data_common(int(RMUX_list[0])*track_coarse+int(RMUX_list[1]),1)
                if addr in cfg_addr_data.keys():
                    cfg_addr_data[addr] = data | cfg_addr_data[addr]
                else:
                    cfg_addr_data[addr] = data
            # print(RMUX_list)
            last_node = line_list
        elif last_node[0] ==  "GIB" and current_node[0] == "PORT" and current_node[1][:2] != 'f2':
            ln = last_node[1].split(",")
            cn = current_node[2].split(",")
            addr = int(cn[1]) + int(cn[0])*(16**2) + 0*(16**4) + portwithaddr[current_node[1]]*(16**6)
            data = sidewithsel[ln[3]]
            cfg_addr_data[addr] = data
            # print(current_node[1][:3])
            # print(last_node)
            # print(current_node)
            # print('GIB + port:      '+current_node[0]+current_node[1]+current_node[2])
        else:
            # print(last_node[0]+' '+current_node[0])
            # print("just update node")
            last_node = line_list
    with open("./out/route.json", "w", encoding='utf-8') as f:
        # json.dump(dict_, f)
        json.dump(cfg_addr_data, f, indent=2, sort_keys=False, ensure_ascii=False) 

    for item in cfg_addr_data.items():
        int1 = int(item[0])
        str1 = hex(int1)[2:].rjust(8,'0')
        int2 = int(item[1])
        str2 = hex(int2)[2:].rjust(8,'0')
        # print(str1)
        with open("./out/config.bs",'a') as f:
            f.write(str1+' '+str2+'\n')


def get_mapped_bs(mapped_file:json,place_file):
    namewithcoord = {}
    idwithname = {}
    idwithvalue = {}
    idwithcoord = {}
    idlist = []
    bs_dict = {}
    #read place file
    with open(place_file,'r',encoding='utf-8') as f:
        data = f.readlines()
    for line in data:
        if line[-4] == 'p' or line[-3] == 'p':
            name,x,y,id = line.split()
            useless,pe_name = name.split("$inner_compute$")
            namewithcoord[pe_name] = int(x)*16*16+int(y)
            # print(namewithcoord)

        # print(line[-4])


    with open(mapped_file) as f:
        bs = json.load(f)

    key_ifo = bs["namespaces"]["global"]["modules"]
    for iter in key_ifo.keys():
        for iter_instance in key_ifo[iter].keys():
            if iter_instance == "instances":
                bs_ifo = key_ifo[iter][iter_instance]
                for iter_id in bs_ifo.keys():
                    for iter_const in bs_ifo[iter_id].keys():
                        if iter_const == "modargs":
                            idlist.append(iter_id+'__'+iter)
                            pebs_width = bs_ifo[iter_id][iter_const]["value"][0][1]
                            pebs_value = bs_ifo[iter_id][iter_const]["value"][1]
                            idwithvalue[iter_id+'__'+iter] = (pebs_width,pebs_value)
                            # addr_num = ceil(pebs_width/32)
                            # for i in range(addr_num):
                            #     addr =
                            #     bs_dict[]
            if iter_instance == 'connections':
                for id in idlist:
                    for aa in key_ifo[iter][iter_instance]:
                        if id.split('__')[0] in aa[-1]:
                            idwithname[id],useless = aa[0].split('.')
                        if id.split('__')[0] in aa[0]:
                            idwithname[id],useless = aa[-1].split('.')
    print(len(namewithcoord))
    print(len(idwithname))
    print(len(idwithvalue))

    # print(namewithcoord)
    # print(idwithname)
    # print(idwithvalue)

    for key in idwithname.keys():
        # print(key)
        # print(idwithname[key])
        idwithcoord[key] = namewithcoord[idwithname[key]]



    for key in idwithcoord:
        addr_num = ceil(idwithvalue[key][0]/32)
        for i in range(addr_num):
            # print(i)
            addr = i*(16**6)+0*(16**4)+idwithcoord[key]
            value = idwithvalue[key][1][4:][::-1]
            # print(value)
            # print(value[8*i:8*(i+1)][::-1])
            # # print(idwithvalue[key][1][4:][:-8*(i+1)-1])
            data = int(value[8*i:8*(i+1)][::-1],16)
            # print(hex(addr))
            # print(hex(data))
            bs_dict[addr] = data


    # print(bs_dict)
    # print(len(namewithcoord))

    with open("./out/mapped.json", "w", encoding='utf-8') as f:
        # json.dump(dict_, f) 
        json.dump(bs_dict, f, indent=2, sort_keys=False, ensure_ascii=False)

    for item in bs_dict.items():
        int1 = int(item[0])
        str1 = hex(int1)[2:].rjust(8,'0')
        int2 = int(item[1])
        str2 = hex(int2)[2:].rjust(8,'0')
        # print(str1)
        with open("./out/config.bs",'a') as f:
            f.write(str1+' '+str2+'\n')


def place_to_dirc(filename):
    replace('\t',' ',filename)
    replace('#','',filename)
    place_dirc = {}
    result = {}
    with open(filename, "r", encoding='utf-8') as f:
        place = f.readlines()

    for line in place:
        place_list = line.split(' ')
        while '' in place_list:
            place_list.remove('')
        if (len(place_list) == 1 or len(place_list) == 6):
            continue
        place_list[-1] = place_list[-1][:-1]
        place_dirc[str(place_list[-1])] = (int(place_list[-3]),int(place_list[-2]))

        keys = sorted(place_dirc.keys())
        for key in keys:
            result[key] = place_dirc[key]
        # print(result)

    with open("./out/place.json", "w", encoding='utf-8') as f:
    # json.dump(dict_, f) 
        json.dump(place_dirc, f, sort_keys=True, ensure_ascii=False)
    return result

def match(dict1:dict,dict2:dict):
    result = {}
    for key in dict1.keys():
        result[str(dict1[key])] = dict2[key]
    # print(result)
    with open("./out/match.json", "w", encoding='utf-8') as f:
    # json.dump(dict_, f) 
        json.dump(result, f, sort_keys=True, ensure_ascii=False) 


'''------------------------for aha docker-------------------------------'''
def json_to_list(filename):
    bs = []
    with open(filename) as f:
        routing = json.load(f)
    for i,j in routing.items():
        bs.append((int(i),j))
    return bs


def main():
    parser = argparse.ArgumentParser(description='Generate bs file')
    parser.add_argument('--mapped-file', type=str, default="", dest="mapped_file")
    parser.add_argument('--track-file', type=str, default="", dest="track_file")
    args = parser.parse_args()

    replace(search_text=", ",replace_text=",",filename="./input/design.route")
    replace(search_text="(",replace_text="",filename="./input/design.route")
    replace(search_text=")",replace_text="",filename="./input/design.route")

    get_route_bs('./input/GIB1.json', './input/GIB16.json', './input/design.route', args.track_file)
    get_mapped_bs(args.mapped_file,"./input/design.place")

if __name__ == "__main__":
    main()
