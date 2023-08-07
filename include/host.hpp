#ifndef HOST_H
#define HOST_H

#include "../include/interf.hpp"
#include "../include/ipv4.hpp"

#include <string>
#include <vector>
#include <map>

struct RoutingTableEntry {
    public:
    IPV4 dest;
    IPV4 net_mask;
    IPV4 gateway;
    string iface_name;

    RoutingTableEntry(IPV4 dst, IPV4 mask, IPV4 gtway, string iface) {
        dest = dst;
        net_mask = mask;
        gateway = gtway;
        iface_name = iface;
    }
};

class Host {
    public:
    std::vector<RoutingTableEntry> rout_tbl;
    std::vector<Interf> interfs;

    void config_routing_table(std::vector<RoutingTableEntry> rt);
    void send(uint8_t *data, IPV4 dest);

    private:
    std::map<string, Interf> _ifaces;

    void send_through_iface(uint8_t *data, string iface_name);
};

#endif