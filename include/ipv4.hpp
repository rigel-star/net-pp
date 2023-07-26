#ifndef IPV$_H
#define IPV$_H

#define IPV4_LENGTH 4

#include <stdint.h>
#include <string>

class IPV4 {
    public:
    uint8_t octets[IPV4_LENGTH];

    IPV4(uint8_t octet1, uint8_t octet2, uint8_t octet3, uint8_t octet4) {
        octets[0] = octet1;
        octets[1] = octet2;
        octets[2] = octet3;
        octets[3] = octet4;
    }

    string tostring() {
        return 
            std::to_string(octets[0]) + "." + 
            std::to_string(octets[1]) + "." + 
            std::to_string(octets[2]) + "." + 
            std::to_string(octets[3]);
    }
};

#endif