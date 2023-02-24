def parseroute(route_file, out_file):
    netlist = {}
    SB_num = 0
    MaxSB = 0
    SB_sum = 0
    visit = {}
    with open(route_file, 'r' ) as f:
        for line in f:
            if'Segment:' in line:
                seg_idx = len(netlist)
                SB_num = 0
                visit.clear()
                #print('one seg')
            if'GIB' in line:
                flag = 0
                track = line[4]
                if line[8] != ',':
                    x = line[7] + line[8]
                else:
                    x = line[7]
                if len(x) == 1:
                    if line[11] != ',':
                        y = line[10] + line[11]
                    else:
                        y = line[10]
                else:
                    if line[12] != ',':
                        y = line[11] + line[12]
                    else:
                        y = line[11]
                curSB_Node = tuple((track, x, y))
                #print(x + ',' + y)
                if len(visit) == 0:
                    pre_x = ''
                    pre_y = ''
                else:
                    pre_x = visit[len(visit) - 1][1]
                    pre_y = visit[len(visit) - 1][2]
                if x == pre_x:
                    if y == pre_y:
                        flag = 1
                if flag == 0:
                    SB_num = SB_num + 1
                    visit[len(visit)] = curSB_Node
                    netlist[seg_idx] = SB_num
    for (key, value) in netlist.items():
        #print('numbers of wire: ')
        #print(value)
        if value > MaxSB:
            MaxSB = value
        SB_sum = value + SB_sum
    print(f.closed)
    print('Wire_num: ')
    print(len(netlist))
    print('total GIB usage:')
    print(SB_sum)
    print('Maximum GIB usage: ')
    print(MaxSB)
    print('Average GIB usage:')
    print(SB_sum / len(netlist))

    with open(out_file, 'w' ) as f:
        f.write(str(SB_sum))
        # f.write('Wire_num: ' + str(len(netlist)) + '\n')
        # f.write(len(netlist))
        # f.write('total GIB usage: ' + str(SB_sum) + '\n')
        # f.write('Maximum GIB usage: ' + str(MaxSB) + '\n')
        # f.write('Average GIB usage: ' + str(SB_sum / len(netlist)) + '\n')

parseroute("./design.route", "./parseroute.txt")

