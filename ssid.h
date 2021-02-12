#ifndef SSID_H
#define SSID_H

#endif // SSID_H
#include <cstdint>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#pragma pack(push,1)
class Ssid{
public:
    Ssid(uint8_t len);
    void operator=(char data[]);

};
#pragma pack(pop)
