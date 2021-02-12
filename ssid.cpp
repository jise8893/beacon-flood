#include "ssid.h"

Ssid::Ssid(uint8_t len){
    free(line);
    line=new uint8_t[len];
}
void Ssid::operator=(char data[]){
    memcpy(line,data,strlen(data));
}
