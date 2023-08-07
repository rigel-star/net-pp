#ifndef IPV4_H
#define IPV4_H

#define IPV4_LENGTH 4

#include <stdint.h>
#include <string>
#include <bitset>

class IPV4 {
    public:
    uint8_t octets[IPV4_LENGTH];

    IPV4() {

    }

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

    string to_bin_str() {
        string result;
        for(uint8_t octet: octets) 
            result += std::bitset<8>(octet).to_string();
        return result;
    }

    IPV4 operator &(IPV4 ip) {
        return IPV4(
            octets[0] & ip.octets[0], 
            octets[1] & ip.octets[1], 
            octets[2] & ip.octets[2], 
            octets[3] & ip.octets[3] 
        );
    }
    
    IPV4 operator |(IPV4 ip) {
        return IPV4(
            octets[0] | ip.octets[0], 
            octets[1] | ip.octets[1], 
            octets[2] | ip.octets[2], 
            octets[3] | ip.octets[3] 
        );
    }
};

#endif