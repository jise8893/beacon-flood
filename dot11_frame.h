#ifndef DOT11_FRAME_H
#define DOT11_FRAME_H

#endif // DOT11_FRAME_H
#include "frame_control.h"
#include "mac.h"
#pragma pack(push,1)
class Dot11Frame {
public:
    FrameControl framecontrol;//check frame to ds or from ds
    uint16_t duration_id;
    Mac address_1=Mac("ff:ff:ff:ff:ff:ff"); //receiver address or destination
    Mac address_2=Mac("70:5d:cc:04:2b:a2"); //transmitter or source address
    Mac address_3=Mac("70:5d:cc:04:2b:a2"); // bssid address
    uint16_t sequence_control=0x6ca0;


   typedef enum {
        CLASS3_FRAME_RECIEVED_FROM_NONASSOCIATED_STA=0x0007,

    }TYPE;

};
#pragma pack(pop)
