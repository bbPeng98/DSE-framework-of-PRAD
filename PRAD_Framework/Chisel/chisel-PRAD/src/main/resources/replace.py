
def replace(search_text,replace_text,filename):

    # 使用 open() 函数以只读模式打开我们的文本文件
    with open(filename, 'r+',encoding='UTF-8') as file:
        data = file.read()
        file.seek(0)
        data = data.replace(search_text, replace_text)
        file.truncate(0)
        file.write(data)

    # # 以只写模式打开我们的文本文件以写入替换的内容
    # with open(newFileName, 'w',encoding='UTF-8') as file:
    #     file.write(data)

    # 打印finish
    print("finish")
# 16bit PE
replace("inPE0","data0","16bit.graph")
replace("inPE1","data1","16bit.graph")
replace("inPE2","data2","16bit.graph")
replace("outPE0","res","16bit.graph")

#16bit MEM
replace("inMEM0","input_width_16_num_0","16bit.graph")
replace("inMEM1","input_width_16_num_1","16bit.graph")
replace("inMEM2","input_width_16_num_2","16bit.graph")
replace("inMEM3","input_width_16_num_3","16bit.graph")
# replace("inMEM4","addr_in_0","16bit.graph")
# replace("inMEM5","addr_in_1","16bit.graph")
replace("outMEM0","output_width_16_num_0","16bit.graph")
replace("outMEM1","output_width_16_num_1","16bit.graph")

#1bit PE
replace("inPE0","bit0","1bit.graph")
replace("inPE1","bit1","1bit.graph")
replace("inPE2","bit2","1bit.graph")
replace("outPE0","res_p","1bit.graph")

#1bit MEM
replace("inMEM0","input_width_1_num_0","1bit.graph")
replace("inMEM1","input_width_1_num_1","1bit.graph")
# replace("inMEM2","wen_in_1","1bit.graph")
# replace("inMEM3","ren_in_0","1bit.graph")
# replace("inMEM4","ren_in_1","1bit.graph")
replace("outMEM0","output_width_1_num_0","1bit.graph")
replace("outMEM1","output_width_1_num_1","1bit.graph")
replace("outMEM2","output_width_1_num_2","1bit.graph")
replace("outMEM3","output_width_1_num_3","1bit.graph")
# replace("outMEM4","valid_out_0","1bit.graph")
# replace("outMEM5","valid_out_1","1bit.graph")



