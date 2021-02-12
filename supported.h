#ifndef SUPPORTED_H
#define SUPPORTED_H

#endif // SUPPORTED_H
#include <cstdint>
#include <string>
#pragma pack(push,1)
class Supportag{
public:
    uint8_t tagnum;
    uint8_t taglen;
    uint8_t supportedrate1;
    uint8_t supportedrate2;
    uint8_t supportedrate3;
    uint8_t supportedrate4;
    uint8_t supportedrate5;
    uint8_t supportedrate6;
    uint8_t supportedrate7;
    uint8_t supportedrate8;
};
#pragma pack(pop)
