#include "../include/interf.hpp"

#include <iostream>

Interf::Interf(
    uint8_t mac[6], 
    uint8_t ip[4], 
    uint8_t subnet[4], 
    uint8_t gateway[4]
){
    memcpy(ip_addr, ip, 4);
    memcpy(mac_addr, mac, 6);
    memcpy(sub_mask, subnet, 4);
    memcpy(gat_addr, gateway, 4);
}

void Interf::connect(Interf *i) {
    _ether_conn = i;
}

void Interf::send(uint8_t data[STD_ETHER_MTU_SIZE]) {
    if(net_type == Ethernet) {
        send_ether(data);
    }
}

void Interf::receive(uint8_t data[STD_ETHER_MTU_SIZE]) {
    std::cout << "R Ethernet: " << data << std::endl;
}

void Interf::send_ether(uint8_t data[STD_ETHER_MTU_SIZE]) {
    _ether_conn->receive(data);
}