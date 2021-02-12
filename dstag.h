#ifndef DSTAG_H
#define DSTAG_H

#endif // DSTAG_H
#include <cstdint>
#include <string>
#pragma pack(push,1)
class Dstag{
public:
    uint8_t tagnum;
    uint8_t taglen;
    uint8_t channel;
};
#pragma pack(pop)
