#include "../include/interf.hpp"
#include "../include/ipv4.hpp"
#include "../include/host.hpp"

#include <stdint.h>
#include <iostream>

int main(void) {
    uint8_t mac[6] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    uint8_t ip[4] = {192, 168, 1, 10};
    uint8_t sub[4] = {255, 255, 255, 0};
    uint8_t gate[4] = {192, 168, 1, 1};
    Interf interf(mac, ip, sub, gate);
    interf.name = "eth0";
    interf.net_type = Ethernet;

    uint8_t mac2[6] = {0xaa, 0xbb, 0xcc, 0xdd, 0x22, 0xff};
    uint8_t ip2[4] = {192, 168, 1, 11};
    uint8_t sub2[4] = {255, 255, 255, 0};
    uint8_t gate2[4] = {192, 168, 1, 1};
    Interf interf2(mac, ip, sub, gate);
    interf2.name = "eth0";
    interf2.net_type = Ethernet;

    interf.connect(&interf2);
    interf2.connect(&interf);

    std::vector<RoutingTableEntry> rout_table;
    rout_table.push_back(
        RoutingTableEntry(
            IPV4(192, 168, 1, 0),
            IPV4(255, 255, 255, 0),
            IPV4(192, 168, 1, 1),
            "eth0"
        ));
    
    Host host1;
    host1.interfs.push_back(interf);
    host1.config_routing_table(rout_table);
    
    Host host2;
    host2.interfs.push_back(interf2);

    uint8_t data[STD_ETHER_MTU_SIZE] = {0x41, 0x42, 0x43};
    host1.send(data, IPV4(192, 168, 1, 11));
    return 0;
}