import argparse


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

def main():
    parser = argparse.ArgumentParser(description='Replace ports')
    parser.add_argument('--packed', type=str, defasult="", dest="packed")
    args = parser.parse_args()

    #bit16 MEM
    replace("input_width_16_num_0","chain_data_in_0",args.packed)
    replace("input_width_16_num_1","chain_data_in_1",args.packed)
    replace("input_width_16_num_2","data_in_0",args.packed)
    replace("input_width_16_num_3","data_in_1",args.packed)

    replace("input_width_16_num_2","addr_in_0",args.packed)
    replace("inMEM5","addr_in_1",args.packed)
    replace("input_width_16_num_0","data_out_0",args.packed)
    replace("input_width_16_num_1","data_out_1",args.packed)

    #bit1 MEM
    replace("inMEM0","flush",args.packed)
    replace("inMEM1","wen_in_0",args.packed)
    replace("inMEM2","wen_in_1",args.packed)
    replace("inMEM3","ren_in_0",args.packed)
    replace("inMEM4","ren_in_1",args.packed)
    replace("outMEM0","empty",args.packed)
    replace("outMEM1","full",args.packed)
    replace("outMEM2","sram_ready_out",args.packed)
    replace("output_width_1_num_3","stencil_valid",args.packed)
    replace("outMEM4","valid_out_0",args.packed)
    replace("outMEM5","valid_out_1",args.packed)
