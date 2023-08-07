#ifndef INTERF_H
#define INTERF_H

#include <stdint.h>
#include <stdio.h>
#include <string>

#define STD_ETHER_MTU_SIZE 1500

using namespace std;

enum NetworkType {
    Ethernet
};

class Interf {
    private:
    Interf *_ether_conn;

    public:
    uint8_t ip_addr[4];
    uint8_t mac_addr[6];
    uint8_t gat_addr[4];
    uint8_t sub_mask[4];
    uint16_t addr_fam;
    NetworkType net_type;
    uint32_t mtu;
    string name;

    Interf() {

    }

    Interf(
        uint8_t mac[6], 
        uint8_t ip[4], 
        uint8_t subnet[4], 
        uint8_t gateway[4]
    );

    void connect(Interf *interf);

    void send(uint8_t data[STD_ETHER_MTU_SIZE]);

    void receive(uint8_t data[STD_ETHER_MTU_SIZE]);

    private:
    void send_ether(uint8_t data[STD_ETHER_MTU_SIZE]);
};

#endif