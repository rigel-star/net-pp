#include "../include/interf.hpp"

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

    uint8_t data[STD_ETHER_MTU_SIZE] = {0x41, 0x42, 0x43};
    interf.send(data);
    return 0;
}