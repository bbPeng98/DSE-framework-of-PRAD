import os
path = os.getcwd()

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

file = path + "\design.route"
print(file)
#预处理文件
replace(search_text=", ",replace_text=",",filename=file)


with open(file, encoding='utf-8') as file_obj:
    lines = file_obj.readlines()

for line in lines:
    line_list = line.split("(")
    if(len(line_list) != 2):
        print("line is not useable: " + line)
        continue
    # print(len(line_list))
    print(line)
    print(line_list[1])