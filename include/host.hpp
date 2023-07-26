#ifndef HOST_H
#define HOST_H

#include "../include/interf.hpp"

#include <string>

struct RoutingTableEntry {
    public:
    string dest;
    string iface;
    string gateway;
};

class Host {
    public:
    Interf interfs[];
};

#endif