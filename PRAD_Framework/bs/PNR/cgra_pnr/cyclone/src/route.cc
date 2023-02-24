#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include "route.hh"
#include "util.hh"

using std::map;
using std::shared_ptr;
using std::vector;
using std::set;
using std::pair;
using std::runtime_error;
using std::priority_queue;
using std::string;
using std::function;
using std::move;
using std::unordered_map;
using std::unordered_set;


uint64_t Router::net_id_count_ = 0;

Router::Router(const RoutingGraph &g) : graph_(g) {
    // create the look up table for cost analysis
    for (const auto &tile_iter : graph_) {
        const auto &tile = tile_iter.second;
        for (uint32_t side = 0; side < Switch::SIDES; side++) {
            auto &side_sbs = tile.switchbox.get_sbs_by_side(get_side_int(side));
            for (const auto &sb : side_sbs) {
                node_connections_.insert({sb, {}});
                node_history_.insert({sb, {}});
                node_net_ids_.insert({sb, {}});
            }
        }
        for (auto const &port : tile.ports) {
            node_connections_.insert({port.second, {}});
            node_history_.insert({port.second, {}});
            node_net_ids_.insert({port.second, {}});
        }
        for (auto const &reg : tile.registers) {
            node_connections_.insert({reg.second, {}});
            node_history_.insert({reg.second, {}});
            node_net_ids_.insert({reg.second, {}});
        }
        for (auto const &reg_mux: tile.rmux_nodes) {
            node_connections_.insert({reg_mux.second, {}});
            node_history_.insert({reg_mux.second, {}});
            node_net_ids_.insert({reg_mux.second, {}});
        }
    }
}

void
Router::add_net(const ::string &name,
                const ::vector<::pair<::string, ::string>> &net) {
    int net_id = static_cast<int>(net_id_count_++);
    Net n;
    n.id = net_id;
    n.name = name;
    ::set<uint64_t> reg_index;
    for (auto const &entry : net) {
        auto const &[blk_id, port] = entry;
        if (placement_.find(blk_id) == placement_.end())
            throw ::runtime_error("unable to find placement for " + blk_id);
        auto const &[x, y] = placement_[blk_id];
        // FIXME
        // right now uses 'r' as a way to indicate register inputs
        if (blk_id[0] == 'r')
            reg_index.insert(n.size());
        n.add_pin({x, y, blk_id, port});
    }
    // point the pin to the actual node in the graph
    // notice that we will also assign registers at this stage
    for (uint64_t i = 0; i < n.size(); i++) {
        Pin &pin = n[i];
        if (reg_index.find(i) != reg_index.end()) {
            // keyi:
            // this is a design choice
            // assignment happens during the global routing stage while
            // performing the routing negotiation
            pin.node = nullptr;
        } else {
            auto node = get_port(pin.x, pin.y, pin.port);
            if (node == nullptr)
                throw ::runtime_error("unable to find node with given pin");
            pin.node = node;
        }
    }
    netlist_.emplace(net_id, n);
}

void Router::add_placement(const uint32_t &x, const uint32_t &y,
                           const ::string &blk_id) {
    placement_.insert({blk_id, {x, y}});
}

std::vector<std::shared_ptr<Node>>
Router::route_a_star(const std::shared_ptr<Node> &start,
                     const std::shared_ptr<Node> &end,
                     bool ifreg) {
    return route_a_star(start, end, zero_cost, ifreg);
}

std::vector<std::shared_ptr<Node>>
Router::route_a_star(const std::shared_ptr<Node> &start,
                     const std::shared_ptr<Node> &end,
                     ::function<double(const ::shared_ptr<Node> &,
                                         const ::shared_ptr<Node> &)> cost_f,
                                         bool ifreg) {
    auto end_f = [&](const ::shared_ptr<Node> &node) -> bool {
        return node == end;
    };
    return route_a_star(start, end_f, ::move(cost_f), manhattan_distance(end), ifreg);
}

std::vector<std::shared_ptr<Node>>
Router::route_a_star(const std::shared_ptr<Node> &start,
                     const std::pair<uint32_t, uint32_t> &end,
                     ::function<double(const ::shared_ptr<Node> &,
                                         const ::shared_ptr<Node> &)> cost_f,
                                         bool ifreg) {
    return route_a_star(start, end, ::move(cost_f), manhattan_distance(end), ifreg);
}

std::vector<std::shared_ptr<Node>>
Router::route_a_star(const std::shared_ptr<Node> &start,
                     const std::pair<uint32_t, uint32_t> &end,
                     ::function<double(const ::shared_ptr<Node> &,
                                         const ::shared_ptr<Node> &)> cost_f,
                     ::function<double(const ::shared_ptr<Node> &)> h_f,
                     bool ifreg) {
    return route_a_star(start, same_loc(end), ::move(cost_f), ::move(h_f), ifreg);
}

std::vector<std::shared_ptr<Node>>
Router::route_a_star(const std::shared_ptr<Node> &start,
                     const std::shared_ptr<Node> &end,
                     ::function<double(const ::shared_ptr<Node> &,
                                         const ::shared_ptr<Node> &)> cost_f,
                     ::function<double(const ::shared_ptr<Node>&)> h_f,
                     bool ifreg) {
    return route_a_star(start, same_node(end), ::move(cost_f), ::move(h_f), ifreg);
}


std::vector<std::shared_ptr<Node>> Router::route_a_star(
        const std::shared_ptr<Node> &start,
        std::function<bool(const std::shared_ptr<Node> &)> end_f,
        std::function<double(const std::shared_ptr<Node> &,
                               const std::shared_ptr<Node> &)> cost_f,
        std::function<double(const ::shared_ptr<Node> &)> h_f,
        bool ifreg) {
    ::unordered_set<::shared_ptr<Node>> visited;
    ::unordered_map<::shared_ptr<Node>, double> g_score = {{start, 0}};

    ::unordered_map<::shared_ptr<Node>, double> f_score = {{start,
                                                            h_f(start)}};
    // std::cout<<"g_score size: "<<g_score.size()<<" "<<g_score[start]<<std::endl;
    // std::cout<<"f_score size: "<<f_score.size()<<" "<<f_score[start]<<std::endl;
    // use cost as a comparator
    auto cost_comp = [&](const ::shared_ptr<Node> &a,
                         const ::shared_ptr<Node> &b) -> bool {
        return f_score.at(a) > f_score.at(b);
    };

    ::priority_queue<::shared_ptr<Node>,
            ::vector<::shared_ptr<Node>>,
            decltype(cost_comp)> working_set(cost_comp);
    working_set.push(start);
    ::unordered_set<::shared_ptr<Node>> open_set;
    open_set.insert(start);

    ::map<::shared_ptr<Node>, ::shared_ptr<Node>> trace;

    // ::map<::shared_ptr<Node>, ::shared_ptr<Node>> pin_trace;
    // ::map<::shared_ptr<Node>, ::vector<::shared_ptr<Node>>> node_stack;


    ::shared_ptr<Node> head = nullptr;

    // ::shared_ptr<Node> pin_node = nullptr;
    // ::vector<::shared_ptr<Node>> pin_spc_routed_path;
    // ::vector<::shared_ptr<Node>> up_pin_spc_routed_path;

    bool testpin = true;
    bool loopagain = false;
    // double pin_score = 0;

    while (!working_set.empty()) {

        // get the one with lowest cost
        head = working_set.top();
        // std::cout<<"working_set.size: "<<working_set.size()<<std::endl;
        // std::cout<<"top head is: "<<head->to_string()<<std::endl;
        // std::cout<<"head type is: "<<head->type<<std::endl;

        // if (end_f(head)){
        // std::cout<<"top head is: "<<head->to_string()<<std::endl;

        //     if (ifreg == true)
        //     {
        //         while (head != start) {
        //             up_pin_spc_routed_path.emplace_back(head);
        //             head = trace.at(head);
        //         }
        //         up_pin_spc_routed_path.emplace_back(head);

        //         for (const auto &iter: up_pin_spc_routed_path){
        //             std::cout<<"up path is: "<<iter->to_string()<<std::endl;
        //         }

        //         for (const auto &iter: up_pin_spc_routed_path){
        //             if (iter->type == NodeType::Generic){
        //                 testpin = true;
        //                 break;
        //             }
        //             else{
        //                 testpin = false;
        //             }
        //         }

        //         std::cout<<"g_score.at[up_pin_spc_routed_path[1]]"<<g_score[up_pin_spc_routed_path[1]]<<std::endl;

        //         if (testpin){
        //             std::cout<<"break! "<<std::endl;
        //             head = working_set.top();
        //             break;
        //         }else{
        //             std::cout<<"failed! "<<std::endl;
        //             working_set.pop();
        //             continue;
        //         }
        //     }
        //     else{
        //         std::cout<<"net[0] is not reg!"<<std::endl;
        //         break;
        //     }
                
        // }
    
                                                          
        if(end_f(head))
            break;

        
        working_set.pop();
        open_set.erase(head);

        if (visited.find(head) != visited.end())
            continue;

        visited.insert(head);

        for (auto const &node : *head) {
            if (visited.find(node.lock()) != visited.end())
                continue;
            // std::cout<<"get_edge_cost: "<<node.lock()->to_string()<<" is"<<head->get_edge_cost(node.lock())<<std::endl;
            // std::cout<<"cost_f head to node: "<<cost_f(head, node.lock())<<std::endl;
            // std::cout<<"node's x is: "<<node.lock()->x<<std::endl;
            // std::cout<<"node's IO is: "<<node.lock()->IO<<std::endl;
            // std::cout<<"node's track is: "<<node.lock()->track<<std::endl;
            // for(auto &iter : node.lock()->to_string()){
            //     std::cout<<"node's part is: "<<iter<<std::endl;
            // }
            // std::cout<<"node's 0 is: "<<node.lock()->to_string().at(0)<<std::endl;
            // std::cout<<"node's size is: "<<node.lock()->to_string().size()<<std::endl;
            // std::cout<<"int(node1->to_string().at(16)): "<<node.lock()->to_string().at(13) - '0'<<std::endl;

            double tentative_score = g_score.at(head)
                                     + head->get_edge_cost(node.lock())
                                     + cost_f(head, node.lock());;
            // std::cout<<"pin_spc_routed_path.size(): "<<pin_spc_routed_path.size()<<std::endl;

            // if(pin_spc_routed_path.size() != 0 && ifreg){
            //     if (head->to_string() == pin_spc_routed_path[2]->to_string()){
            //         std::cout<<"headis:::"<<head->to_string()<<std::endl;
            //         if(node.lock()->to_string() == pin_spc_routed_path[1]->to_string()){
            //             std::cout<<"nodeis:::"<<node.lock()->to_string()<<std::endl;
            //             tentative_score = 0XFFFFFFFFFFFFFFFF;
            //         }else{
            //         tentative_score = g_score.at(head)
            //                             + head->get_edge_cost(node.lock())
            //                             + cost_f(head, node.lock());
            //         }
            //         std::cout<<"tentative_scoreis:::"<<tentative_score<<std::endl;
            //         std::cout<<"node_scoreis:::"<<g_score[node.lock()]<<std::endl;

            //     }
            // }else{
            //     tentative_score = g_score.at(head)
            //                             + head->get_edge_cost(node.lock())
            //                             + cost_f(head, node.lock());
            // }
            
            // std::cout<<"currnet node tentative_score: "<<node.lock()->to_string()<<" "<<tentative_score<<std::endl<<std::endl;

                // pin_node = node.lock();
                // node_stack[pin_node].emplace_back(head);

            if (open_set.find(node.lock()) == open_set.end()) {
                // std::cout<<"have find! "<<std::endl;
                // pin_trace.insert({pin_node, head});
                //check if the result, and keep!
                // if (end_f(pin_node)){
                //     std::cout<<"have detected! "<<pin_node->to_string()<<std::endl;
                //     if (ifreg == true)
                //     {
                //         while (pin_node != start) {
                //             std::cout<<"node "<<pin_node->to_string()<<std::endl;
                //             pin_spc_routed_path.emplace_back(pin_node);
                //             pin_node = pin_trace.at(pin_node);
                //         }
                //         pin_spc_routed_path.emplace_back(pin_node);

                //         for (const auto &iter: pin_spc_routed_path){
                //             std::cout<<"path is: "<<iter->to_string()<<std::endl;
                //         }
                //         for (const auto &iter: pin_spc_routed_path){
                //             if (iter->type == NodeType::Generic){
                //                 testpin = true;
                //                 // pin_score = 0;
                //                 break;
                //             }
                //             else{
                //                 // pin_score = 0XFFFFFFFFFFFFFFFF;
                //                 testpin = false;
                //             }
                //         }
                //         if (!testpin){
                //             std::cout<<"rewrite nodes! "<<std::endl;
                //             // std::cout<<"node_stack size: "<<node_stack[pin_spc_routed_path[1]].size()<<std::endl;
                //             for (const auto &deal_node: *pin_spc_routed_path[2]){//GIB pin to pin in.
                //                 if (deal_node.lock()->to_string() == pin_spc_routed_path[1]->to_string()){//GIB pin out
                //                     std::cout<<"deal_node is: "<<deal_node.lock()->to_string()<<std::endl;
                //                     // double pin_tentative_score = g_score.at(deal_node.lock())
                //                     //                             + deal_node.lock()->get_edge_cost(node.lock())
                //                     //                             + cost_f(deal_node.lock(), node.lock())
                //                     //                             + 0XFFFFFFFFFFFFFFFF;
                //                     // g_score[node.lock()] = pin_tentative_score;
                //                     // f_score[node.lock()] = g_score.at(node.lock())
                //                     //                             + h_f(node.lock());

                //                     g_score[deal_node.lock()] = 0XFFFFFFFFFFFFFFFF;
                //                     f_score[deal_node.lock()] = g_score.at(deal_node.lock())
                //                                                 + h_f(deal_node.lock());
                                    
                //                     for (const auto &nodestack: node_stack[pin_spc_routed_path[1]]){
                //                         std::cout<<"node_stack is: "<<nodestack->to_string()<<std::endl;
                //                         working_set.push(nodestack);
                //                         // open_set.insert(nodestack);
                //                         visited.erase(nodestack);
                //                     }
                //                     // working_set.push(pin_spc_routed_path[2]);
                //                     // open_set.insert(pin_spc_routed_path[2]);
                //                     // visited.erase(pin_spc_routed_path[2]);

                //                     // trace.insert({deal_node.lock(), head});
                //                 }
                //             }
                //             trace.erase(head);
                //             visited.erase(head);
                //             // open_set.insert(head);
                //             // working_set.push(head);

                //             // working_set.push(node.lock());
                //             // open_set.insert(node.lock());
                //             // trace.insert({node.lock(), head});
                //             // continue;
                //         }
                //     }
                        
                // }
                // std::cout<<"current node is: "<<node.lock()->to_string()<<std::endl;
                // tentative_score = g_score.at(head)
                //                      + head->get_edge_cost(node.lock())
                //                      + cost_f(head, node.lock());
                g_score[node.lock()] = tentative_score;
                f_score[node.lock()] = g_score.at(node.lock())
                                       + h_f(node.lock());
                working_set.push(node.lock());
                open_set.insert(node.lock());
            } else if (g_score.find(node.lock()) != g_score.end() &&
                       tentative_score >= g_score.at(node.lock())) {
                continue;
            } else {
                g_score[node.lock()] = tentative_score;
                f_score[node.lock()] = g_score.at(node.lock())
                                       + h_f(node.lock());
                // a duplicated copy
                working_set.push(node.lock());
            }
            // std::cout<<"route head is: "<<head->to_string()<<std::endl;
            // std::cout<<"route node is: "<<node.lock()->to_string()<<"\n"<<std::endl;

            trace.insert({node.lock(), head});
        }

    }
        std::cout<<"result head is: "<<head->to_string()<<" score is: "<<g_score[head]<<"\n"<<std::endl;

    if (!end_f(head))
        throw UnableRouteException("unable to route from "
                                   + start->to_string());

    ::vector<::shared_ptr<Node>> routed_path;
    // back trace the route
    // head is the end
    while (head != start) {
        // std::cout<<"current head is: "<<head->to_string()<<std::endl;
        routed_path.emplace_back(head);
        head = trace.at(head);
        // std::cout<<"after deal, head is: "<<head->to_string()<<std::endl;
    }
    routed_path.emplace_back(head);


    if (ifreg == true){
        //start node is reg, determine whether route again!
        for (const auto &iter: routed_path){
            if (iter->type == NodeType::Generic){
                testpin = true;
                break;
            }
            else{
                testpin = false;
            }
        }
    }

    if (!testpin){
        std::cout<<"There is no reg in routed path! re-route! "<<std::endl;
        // for (const auto &iter: routed_path){
        //     std::cout<<"routed path is: "<<iter->to_string();
        // }
        //clear all elements
        while (!working_set.empty()){
            working_set.pop();
        }
        open_set.clear();
        g_score.clear();
        f_score.clear();
        visited.clear();
        trace.clear();

        working_set.push(start);
        open_set.insert(start);
        g_score = {{start, 0}};
        f_score = {{start, h_f(start)}};
        loopagain = true;
        // std::cout<<"\nworking_set:"<<working_set.size()<<std::endl;
        // std::cout<<"open_set:"<<open_set.size()<<std::endl;       
    }

    while (!working_set.empty() && loopagain) {

        // get the one with lowest cost
        head = working_set.top();                                              
        if(end_f(head))
            break;

        working_set.pop();
        open_set.erase(head);

        if (visited.find(head) != visited.end())
            continue;

        visited.insert(head);

        for (auto const &node : *head) {
            if (visited.find(node.lock()) != visited.end())
                continue;

            double tentative_score = g_score.at(head)
                                     + head->get_edge_cost(node.lock())
                                     + cost_f(head, node.lock());
            
            // std::cout<<"head->to_string(): "<<head->to_string()<<std::endl;
            // std::cout<<"node.lock()->to_string(): "<<node.lock()->to_string()<<std::endl;
            // for (const auto &iter: routed_path){
            //     std::cout<<"path is: "<<iter->to_string()<<std::endl;
            // }
            //wrong node, skip
            if(routed_path.size() < 3){
                if (head->to_string() == routed_path[1]->to_string() && node.lock()->to_string() == routed_path[0]->to_string())
                    continue;
            }else{
                if (head->to_string() == routed_path[2]->to_string() && node.lock()->to_string() == routed_path[1]->to_string())
                // std::cout<<"head is: "<<head->to_string()<<std::endl;
                // std::cout<<"node is: "<<node.lock()->to_string()<<std::endl;
                    continue;
                // tentative_score = 0XFFFFFFFFFFFFFFF;
            }

            // if (head->to_string() == routed_path[2]->to_string() && node.lock()->to_string() == routed_path[1]->to_string()){
            //     // std::cout<<"head is: "<<head->to_string()<<std::endl;
            //     // std::cout<<"node is: "<<node.lock()->to_string()<<std::endl;
            //     continue;
            //     // tentative_score = 0XFFFFFFFFFFFFFFF;
            // }

            if (open_set.find(node.lock()) == open_set.end()) {
                g_score[node.lock()] = tentative_score;
                f_score[node.lock()] = g_score.at(node.lock())
                                       + h_f(node.lock());
                working_set.push(node.lock());
                open_set.insert(node.lock());
            } else if (g_score.find(node.lock()) != g_score.end() &&
                       tentative_score >= g_score.at(node.lock())) {
                continue;
            } else {
                g_score[node.lock()] = tentative_score;
                f_score[node.lock()] = g_score.at(node.lock())
                                       + h_f(node.lock());
                // a duplicated copy
                working_set.push(node.lock());
            }
            trace.insert({node.lock(), head});
        }

    }
    if (loopagain){
        std::cout<<"2nd result head is: "<<head->to_string()<<" score is: "<<g_score[head]<<"\n"<<std::endl;
        if (!end_f(head))
            throw UnableRouteException("unable to route from "
                                    + start->to_string());
        
        routed_path.clear();
        while (head != start) {
            // std::cout<<"current head is: "<<head->to_string()<<std::endl;
            routed_path.emplace_back(head);
            head = trace.at(head);
            // std::cout<<"after deal, head is: "<<head->to_string()<<std::endl;
        }
        routed_path.emplace_back(head);
    }
        
            
    
    
    std::reverse(routed_path.begin(), routed_path.end());
    return routed_path;
}

std::shared_ptr<Node> Router::get_port(const uint32_t &x, const uint32_t &y,
                                       const string &port) {
    return graph_.get_port(x, y, port);
}

void Router::group_reg_nets() {
    ::map<::string, int> driven_by;
    // first pass to determine where the reg nets originates.
    for (auto &iter : netlist_) {
        auto const &net = iter.second;
        for (uint32_t i = 1; i < net.size(); i++) {
            auto const &pin = net[i];
            // std::cout<<"pin.port: "<<pin.port<<"pin.name: "<<pin.name<<std::endl;
            
            if (pin.port == REG and pin.name[0] == 'r') {
                // we assume it's already packed
                driven_by.insert({pin.name, net.id});
                // std::cout<<"driven size: "<<driven_by.size()<<std::endl;
            }
        }
    }

    // second pass to create a map from the reg src to sink
    for (auto const &[net_id, net] : netlist_) {
        // std::cout<<"net[0].name: "<<net[0].name<<std::endl;
        if (driven_by.find(net[0].name) != driven_by.end()) {
            // std::cout<<"yes!"<<std::endl;
            // we have found a reg that drives this net
            reg_net_src_.insert({net[0].name, net.id});
            // std::cout<<"net.id: "<<net.id<<std::endl;
        }
    }

    for (const auto &iter : driven_by) {
        ::string name = iter.first;
        int src_id = iter.second;
        while (driven_by.find(name) != driven_by.end()) {
            src_id = driven_by.at(name);
            name = netlist_[driven_by.at(name)][0].name;
        }
        auto squashed = squash_net(src_id);

        reg_net_order_.insert({src_id, squashed});
    }
}

std::vector<int> Router::squash_net(int src_id) {
    // an algorithm to group the register nets in order
    // using an recursive lambda function, originally written in Python
    ::vector<int> result = {src_id};
    auto &net = netlist_[src_id];
    for (uint32_t index = 1; index < net.size(); index++) {
        auto const &pin = net[index];
        if (pin.name[0] == 'r') {
            // found another one
            auto next_id = reg_net_src_.at(pin.name);
            auto next_result = squash_net(next_id);
            result.insert(result.end(), next_result.begin(), next_result.end());
        }
    }

    return result;
}

std::vector<uint32_t>
Router::reorder_reg_nets() {
    ::vector<uint32_t> result;
    ::set<int32_t> working_set;
    for (auto const &[i, net]: netlist_)
        working_set.emplace(i);

    // we will first sort out the order of reg nets
    // it is ordered by the total number of fan-outs in linked reg lists
    ::vector<uint32_t> reg_nets;
    for (auto const &iter : reg_net_order_) {
        reg_nets.emplace_back(iter.first);
    }

    // partial sort to ensure the deterministic result
    std::stable_sort(reg_nets.begin(), reg_nets.end(),
                     [&](uint32_t id1, uint32_t id2) -> bool {
        uint32_t fan_out_count1 = 0;
        for (auto const &ids : reg_net_order_.at(id1)) {
            auto const & net = netlist_[ids];
            fan_out_count1 += net.size() - 1;
        }
        uint32_t fan_out_count2 = 0;
        for (auto const &ids : reg_net_order_.at(id2)) {
            auto const & net = netlist_[ids];
            fan_out_count2 += net.size() - 1;
        }
        return fan_out_count1 > fan_out_count2;
    });

    // put them into result, in order
    for (auto const &src_id : reg_nets) {
        for (auto const &reg_net_id : reg_net_order_.at(src_id)) {
            result.emplace_back(reg_net_id);
        }
    }

    // remove all the added nets
    for (auto const &id : result)
        working_set.erase(id);

    // change working set into a vector so that we can sort
    ::vector<uint32_t> normal_nets(working_set.begin(), working_set.end());
    std::stable_sort(normal_nets.begin(), normal_nets.end(),
                     [&](uint32_t id1, uint32_t id2) -> bool {
        uint64_t fan_out_count1 = netlist_[id1].size() - 1;
        uint64_t fan_out_count2 = netlist_[id2].size() - 1;
        return fan_out_count1 > fan_out_count2;
    });

    result.insert(result.end(), normal_nets.begin(), normal_nets.end());

    return result;
}

bool Router::overflow() {
    return overflowed_;
}

void Router::assign_net_segment(const ::vector<::shared_ptr<Node>> &segment,
                                int net_id) {
    for (uint32_t i = 1; i < segment.size(); i++) {
        auto &node = segment[i];
        assign_connection(node, segment[i - 1]);
    }
    for (const auto &node : segment) {
        node_net_ids_[node].insert(net_id);
    }
}

void Router::assign_history() {
    for (const auto &[net_id, net] : netlist_) {
        auto segments = current_routes[net.id];
        for (auto &seg_it : segments) {
            auto &segment = seg_it.second;
            for (uint32_t i = 0; i < segment.size(); i++) {
                auto &node = segment[i];
                assign_history(node);
            }
        }
    }
}

::map<::string, ::vector<::vector<::shared_ptr<Node>>>>
Router::realize() const {
    ::map<::string, ::vector<::vector<::shared_ptr<Node>>>>
    result;
    for (const auto &[net_id, net] : netlist_) {
        // std::cout<<"times: "<<std::endl;
        // std::cout<<"net.name: "<<net.name<<std::endl;
        // std::cout<<"net.id: "<<net.id<<std::endl;
        const auto &name = net.name;
        ::vector<::vector<shared_ptr<Node>>> segments;
        auto const &route = current_routes.at(net.id);
        // realize them in the pin order
        for (uint32_t seg_index = 1; seg_index< net.size(); seg_index++) {
            // std::cout<<"seg_index: "<<seg_index<<", "<<net.size()<<std::endl;
            // std::cout<<"net has: "<<net[0].name<<", "<<net[0].id<<std::endl;
            // std::cout<<"net has: "<<net[seg_index].name<<", "<<net[seg_index].id<<std::endl;
            auto const &seg = route.at(net[seg_index].id);
            // std::cout<<"seg: "<<*seg[0]<<std::endl;
            // std::cout<<"seg: "<<*seg[1]<<std::endl;
            // std::cout<<"seg: "<<*seg[2]<<std::endl;
            segments.emplace_back(seg);
        }
        result.insert({name, segments});
    }
    return result;
}

void Router::rip_up_net(int net_id) {
    if (current_routes.find(net_id) == current_routes.end())
        return;
    auto const &route = current_routes.at(net_id);
    for (const auto &segment : route) {
        auto nodes = segment.second;
        // remove it from the presence cost
        for (uint32_t i = 1; i < nodes.size(); i++) {
            auto const &node = nodes[i];
            auto const &pre_node = nodes[i - 1];
            node_connections_.at(node).erase(pre_node);
        }
        // also remove it from node_net_ids;
        for (const auto &node : nodes) {
            auto &lst = node_net_ids_.at(node);
            if (lst.find(net_id) != lst.end())
                lst.erase(net_id);
        }
    }
    // remove it from current_routes
    current_routes.erase(net_id);
}


bool Router::node_owned_net(int net_id, std::shared_ptr<Node> node) {
    if (node_net_ids_.at(node).empty()) {
        return true;
    }
    if (node_net_ids_.at(node).size() == 1) {
        return net_id == *node_net_ids_.at(node).begin();
    }
    return false;
}

void Router::assign_connection(const std::shared_ptr<Node> &node,
                               const std::shared_ptr<Node> &pre_node) {
    node_connections_.at(node).insert(pre_node);
    if (!overflowed_ && node_connections_[node].size() > 1)
        overflowed_ = true;

}

void Router::assign_history(std::shared_ptr<Node> &end) {
    node_history_.at(end)++;
}

uint32_t Router::get_history_cost(const std::shared_ptr<Node> &node) {
    uint32_t result = node_history_.at(node);
    return result;
}

double Router::get_presence_cost(const std::shared_ptr<Node> &node,
                                 const std::shared_ptr<Node> &pre_node) {
    auto const &start_connection = node_connections_.at(node);
    if (start_connection.find(pre_node) == start_connection.end())
        return start_connection.size();
    else
        return (start_connection.size() - 1);
}


bool Router::has_net(int net_id) const {
    return std::any_of(netlist_.begin(), netlist_.end(), [net_id](const auto &iter) {
        return iter.second.id == net_id;
    });
}


std::unordered_map<int, RoutedGraph> Router::get_routed_graph() const {
    std::unordered_map<int, RoutedGraph> result;
    for (auto const &[net_id, segments]: current_routes) {
        // need to get in the pin form
        std::map<const Pin*, std::vector<std::shared_ptr<Node>>> route;
        auto const &net = netlist_.at(net_id);
        for (auto const &[index, seg]: segments) {
            route.emplace(&net[index], seg);
        }
        result.emplace(net_id, RoutedGraph(route));
    }

    return result;
}

void Router::update_net_route(int net_id, std::map<uint32_t, std::vector<std::shared_ptr<Node>>> &routes) {
    if (current_routes.find(net_id) != current_routes.end()) {
        current_routes[net_id] = routes;
    }
}

