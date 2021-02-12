#ifndef RSN_H
#define RSN_H

#endif // RSN_H
#include <cstdint>
#include <string>
#pragma pack(push,1)
class Rsn{
public:
    uint8_t tagnumber;
    uint8_t taglen;
    uint16_t rsnver;
    uint32_t gcs;
    uint16_t pcsc;
    uint32_t pcsl;
    uint16_t akmsc;
    uint32_t akmk;
    uint16_t capab;
};
#pragma pack(pop)
