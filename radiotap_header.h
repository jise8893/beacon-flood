#ifndef RADIOTAP_HEADER_H
#define RADIOTAP_HEADER_H

#endif // RADIOTAP_HEADER_H
#include <cstdint>

#pragma pack(push,1)
class RadiotapHeader{
public:
    uint8_t it_version=0;
    uint8_t it_pad=0;
    uint16_t it_len=8;
    uint32_t it_present=0x0;

};
#pragma pack(pop)
