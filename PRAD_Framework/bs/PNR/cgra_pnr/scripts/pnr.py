import os
import subprocess
import argparse

def pnr(placer_path="",router_path="", packed_file="", layout_filename="",graph_path="", placement_filename="", route_filename=""):
    
    routed = False
    pnr_placer_exp = 1
    if "PNR_PLACER_EXP" in os.environ and os.environ["PNR_PLACER_EXP"].isnumeric():
        pnr_placer_exp = int(os.environ["PNR_PLACER_EXP"])
        
    while not routed and (pnr_placer_exp < 30):
        # do the place and route
        os.environ["PNR_PLACER_EXP"] = str(pnr_placer_exp)
        print("Trying placement with PnR placer exp:", os.environ["PNR_PLACER_EXP"])
        place(placer_path,packed_file, layout_filename, placement_filename, False)
        # making sure the placement result is there
        if not os.path.isfile(placement_filename):
            print("Unable to PnR. Sorry! Please check the log")

        wave_filename = None
        max_frequency = None
        shift_registers = False
        try:
            route(router_path, packed_file, placement_filename, graph_path, route_filename,
                    max_frequency, layout_filename, wave_info=wave_filename,
                    shift_registers=shift_registers)
            # sweep the PNR_PLACER_EXP if the flag is on
            routed = "SWEEP_PNR_PLACER_EXP" not in os.environ
            if not routed:
            #     if "PIPELINED" in os.environ and os.environ["PIPELINED"] == "1":
            #         pe_cycles = 1
            #     else:
            #         pe_cycles = 0
            #     if "IO_DELAY" in os.environ and os.environ["IO_DELAY"] == "0":
            #         io_cycles = 0
            #     else:
            #         io_cycles = 1
                # placement_result = pycyclone.io.load_placement(placement_filename)
                # routing_result = load_routing_result(route_filename)
                # graph = construct_graph(
                #     placement_result,
                #     routing_result,
                #     id_to_name,
                #     input_netlist[0],
                #     pe_latency=pe_cycles,
                #     pond_latency=0,
                #     io_latency=io_cycles,
                # )
                # curr_freq, crit_path, crit_nets = sta(graph)
                # if curr_freq > max_freq:
                #     max_freq = curr_freq
                #     opt_pnr_placer_exp = pnr_placer_exp
                # print("\nCurrent maximum frequency:", max_freq, "MHz")
                # print("Current optimal PNR_PLACER_EXP:", opt_pnr_placer_exp, "\n")
                pnr_placer_exp += 1
        except:
            pnr_placer_exp += 1


def place(placer_path: str, packed_filename: str, layout_filename: str, placement_filename: str,
          fixed: bool = False):
    path = placer_path
    placer_binary = os.path.join(path, "placer")
    assert os.path.isfile(placer_binary), placer_binary + " not found"
    if fixed:
        subprocess.check_call([placer_binary, "-f", layout_filename,
                               packed_filename,
                               placement_filename])
    else:
        subprocess.check_call([placer_binary, layout_filename,
                               packed_filename, placement_filename])

def route(router_path: str, packed_filename: str, placement_filename,
          graph_paths: str, route_result: str,
          max_frequency, layout=None, wave_info=None,
          shift_registers=False):
    # check input
    tokens = graph_paths.split()
    assert len(tokens) % 2 == 0
    # input checking
    graph_flags = []
    for idx in range(0, len(tokens), 2):
        assert tokens[idx].isdigit()
        graph_path = tokens[idx + 1]
        assert os.path.isfile(graph_path)
        graph_flags += ["-g", graph_path]

    path = router_path
    router_binary = os.path.join(path, "router")
    assert os.path.isfile(router_binary), router_binary + "not found"
    args = [router_binary, "-p", packed_filename, "-P", placement_filename] + graph_flags + \
           ["-o", route_result]
    # timing
    if max_frequency is not None:
        assert os.path.exists(layout)
        # need to load layout as well
        args += ["-f", str(max_frequency), "-t", "default", "-l", layout]
        if wave_info is not None:
            args += ["-w", wave_info]
    elif shift_registers:
        assert os.path.exists(layout)
        args += ["-t", "register", "-l", layout]
    subprocess.check_call(args)


def main():
    parser = argparse.ArgumentParser(description='Garnet CGRA')
    parser.add_argument("--placer-path", type=str, default="", dest="placer_path")
    parser.add_argument("--router-path", type=str, default="", dest="router_path")
    parser.add_argument("--packed-file", type=str, default="", dest="packed_file")
    parser.add_argument("--layout-filename", type=str, default="", dest="layout_filename")
    parser.add_argument("--graph-path", type=str, default="", dest="graph_path")
    parser.add_argument("--placement-filename", type=str, default="", dest="placement_filename")
    parser.add_argument("--route-filename", type=str, default="", dest="route_filename")
    args = parser.parse_args()

    pnr(placer_path=args.placer_path,
        router_path=args.router_path, 
        packed_file=args.packed_file, 
        layout_filename=args.layout_filename,
        graph_path=args.graph_path, 
        placement_filename=args.placement_filename, 
        route_filename=args.route_filename)

if __name__ == "__main__":
    main()