from email import parser
import math
import string
import os
import json
# from turtle import showturtle
import argparse
import time

def heshu(num):
    is_comp = False
    assert num > 2, 'num should bigger than 2'
    for i in range(2,num):
        if num % i == 0:
            is_comp  =  True
            break
    return is_comp

def factor(num):
    factors = []
    for_times = int(math.sqrt(num))
    for i in range(for_times + 1)[1:]:
        if num % i == 0:
            # factors.append(i)
            t = int(num / i)
            factors.append((i,t))
            factors.sort(key=lambda fac: abs(fac[1]-fac[0]))
    return factors



def read_route_file(route_file):
    print('read route file!')
    i = 0
    if os.path.exists(route_file):
        with open(route_file, encoding='utf-8') as file_obj:
            lines = file_obj.readlines()
        for line in lines:
            line_list = line.split(" ")
            if line_list[0] == 'SB':
                # line_list2 = line_list[1].split(',')
                # print(line_list2)
                line_list2 = line_list[-1]
                print(line_list)
                if "16" in line_list2:
                    i = 1
                    print('success generate route')
                    break
            else:
                continue
        # print(i)
        return i
    else:
        print('failed')
        return 0

# def read_route_file_detail(route_file):
#     print('read route file!')
#     coarse = 0
#     fine = 0
#     if os.path.exists(route_file):
#         with open(route_file, encoding='utf-8') as file_obj:
#             lines = file_obj.readlines()
#         for line in lines:
#             line_list = line.split(" ")
#             if line_list[0] == 'GIB':
#                 line_list2 = line_list[1].split(',')
#                 print(line_list2)
#                 if line_list2[-1] == '16\n':
#                     coarse = 1
#                 if line_list2[-1] == '1\n':
#                     fine = 1
#                     print('success generate route')
#                     break
#             else:
#                 continue
#     else:
#         print('failed')
#     return [fine,coarse]


'''
@param state = 0 means failed
@param state = 1 means success
'''
def archExplore():
    parser = argparse.ArgumentParser(description='explore a best PE utilization')
    parser.add_argument('--pe_num', type=int, default=4, dest="pe_num")
    parser.add_argument('--mem_num', type=int, default=4)
    parser.add_argument('--coarse_io', type=int, default=1)  #1
    parser.add_argument('--fine_io', type=int, default=1)    #1  
    parser.add_argument('--app_path',type=str ,dest="app")    #tests/conv_3_3
    args = parser.parse_args()  

    width = 0
    height = 0
    maxWidth = 32
    maxHeight = 32
    pe_num = args.pe_num
    track = 5
    # state = 0
    # state2 = 0
    # state2_extra = 0
    # state3 = 0
    # state4 = 0
    # state5 = 0
    # state6 = 0
    iteratration = 0
    
    app_path = args.app
    route_file = f"/aha/Halide-to-Hardware/apps/hardware_benchmarks/{app_path}/bin/design.route"

    if os.path.exists(route_file):
        os.remove(route_file)



    while 1:
        if pe_num > (maxWidth-maxWidth//4)*maxHeight:    #pe资源不够，
            break

        if heshu(pe_num):       #如果是合数
            fac = factor(pe_num)
            print('factor is: '+str(fac))
            for i in range(len(fac)):    #取其中的一组相乘关系
                width = fac[i][0]
                height = fac[i][1]



                iteratration += 1
                print('Number of iterations is: '+str(iteratration))
                print('current width is: '+str(width))
                print('current height is: '+str(height))

                if(width % 4 != 0) or (width % 2 !=0):
                    print('width must be 2/4 times')
                    continue
                if height == 1 or width == 1:
                    print('impossible')
                    continue

                if width < 4 or width > maxWidth or height > maxHeight or (width - (width//4))*height < args.pe_num or (width//4*height) < args.mem_num or width < args.coarse_io or width < args.fine_io:
                    # width = fac[i][1]
                    # height = fac[i][0]
                    # print('scale is not fit, exchange width and height: ')
                    # print('current width is: '+str(width))
                    # print('current height is: '+str(height))
                    # if width < 4 or width > maxWidth or height > maxHeight or (width - (width//4))*height < args.pe_num or (width//4*height) < args.mem_num or width < args.coarse_io or width < args.fine_io:
                    #     print("resources are mismatch, skip!")
                    #     continue
                    print("invalid width or height")
                    continue

                
                #第一次执行pnr
                os.system(f'aha pipeline {app_path} --width {width} --height {height} --num-tracks {track}')
                state = read_route_file(route_file)   #0 or 1

                # # 如果没有成功 减小track数
                # while state == 0:
                    
                #     if track == 0:
                #         track = 5
                #         break
                    
                #     os.system(f'aha pipeline {app_path} --width {width} --height {height} --num-tracks {track}')
                #     iteratration += 1
                #     print('Number of iterations is: '+str(iteratration))
                #     print('current width is: '+str(width))
                #     print('current height is: '+str(height))
                #     print('num track is:' + str(track))
                #     state = read_route_file(route_file)
                #     track -= 1
                


                #检查结果
                if state == 1:
                    print("successful!")
                    file = open('result',"a+") 
                    file.write(f"success {app_path} : width={width} height={height} track={track}\n")
                    file.close()
                    
                    return 1

                # 如果减小track还没有成功，交换。pnr failed, exchange width and height
                if state == 0:
                    if os.path.exists(route_file):
                        os.remove(route_file)
                    width = fac[i][1]
                    height = fac[i][0]
                    if (width % 4 != 0 ) or (width % 2 != 0):
                        print('width must be 4 times')
                        continue
                    if not (width < 4 or width > maxWidth or height > maxHeight or (width - (width//4))*height < args.pe_num or (width//4*height) < args.mem_num or width < args.coarse_io or width < args.fine_io):
                        
                        os.system(f'aha pipeline {app_path} --width {width} --height {height} --num-tracks {track}')
                        iteratration += 1
                        print('Number of iterations is: '+str(iteratration))
                        print('current width is: '+str(width))
                        print('current height is: '+str(height))
                        state = read_route_file(route_file)
                    else:
                        print("exchange width and height is invalid.")
                        state = 0  # 开始减小track数
                        continue


                # # 交换后的减小track数
                # while state == 0:
                #     if track == 0:
                #         track = 5
                #         break
                #     os.system(f'aha pipeline {app_path} --width {width} --height {height} --num-tracks {track}')
                #     iteratration += 1
                #     print('Number of iterations is: '+str(iteratration))
                #     print('current width is: '+str(width))
                #     print('current height is: '+str(height))
                #     print('num track is:' + str(track))
                #     state = read_route_file(route_file)
                #     track -= 1

                # 如果成功了，写入
                if state == 1:
                    print("successful!")
                    file = open('result',"a+") 
                    file.write(f"success {app_path} : width={width} height={height} track={track}")
                    file.close()
                    
                    return 1

        pe_num += 1



    print('have found the best PE utilization!')
    print('the column is: ' + str(width))
    print('the row is: ' + str(height))
    print("PE's utilization is: " + str((pe_num / ((width-width//4)*height))))
    print("MEM's utilization is: " + str((args.mem_num / ((width//4)*height))))


if __name__ == "__main__":
    time_start = time.perf_counter()
    archExplore()
    time_end = time.perf_counter()
    print('time(s) is: ')
    print((time_end - time_start))