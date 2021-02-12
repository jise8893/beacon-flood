#ifndef WIRELESS_H
#define WIRELESS_H

#endif // WIRELESS_H
#include <cstdint>
#include <string>
#pragma pack(push,1)
class FixedParameter{
public:
    uint8_t timestamp[8];
    uint16_t BeaconInterval=0x0;
    uint16_t CapabilityInformation=0x0001;


};
#pragma pack(pop)
