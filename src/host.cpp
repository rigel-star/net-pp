#include "../include/host.hpp"

#include <iostream>

void Host::send(uint8_t *data, IPV4 dest) {
    string interf_name = "";
    size_t match_len = 1000000;
    for(RoutingTableEntry entry: rout_tbl) {
        IPV4 result = entry.net_mask & dest;
        string bin_str = result.to_bin_str();
        reverse(bin_str.begin(), bin_str.end());
        size_t len = bin_str.find('1');
        if(len < match_len) {
            match_len = len;
            interf_name = entry.iface_name;
        }
    }
    send_through_iface(data, interf_name);
}

void Host::send_through_iface(uint8_t *data, string iface_name) {
    Interf interf = _ifaces.at(iface_name);
    interf.send(data);
}

void Host::config_routing_table(std::vector<RoutingTableEntry> rt) {
    rout_tbl = rt;
    for(RoutingTableEntry entry: rt) {
        for(Interf iface: interfs) {
            if(iface.name == entry.iface_name)
                _ifaces[iface.name] = iface;
        }
    }
}
