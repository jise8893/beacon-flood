#ifndef BEACON_H
#define BEACON_H

#endif // BEACON_H
#include <iostream>
#include <cstdio>
#include <pcap.h>
#include <cstring>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <vector>
#include "radiotap_header.h"
#include "dot11_frame.h"
#include "wireless.h"
#include "tagged_param.h"
#include "rsn.h"
#include "supported.h"
#include "information.h"
#include "dstag.h"

#pragma pack(push,1)
class BeaconPacket{
public:
    BeaconPacket();
    static void Setpacket(BeaconPacket* BeaconPacket);
    static void Ssidtag(uint8_t *data,char *line);
    static void Rsntag(uint8_t *data,uint8_t len);
    static void Supported(uint8_t *data ,uint8_t len);
    static void Dstagset(uint8_t *data,uint8_t len);

    RadiotapHeader radiotapheader;
    Dot11Frame dot11frame;
    FixedParameter fixedparameter;
    SsidParam ssidparam;

};
#pragma pack(pop)
