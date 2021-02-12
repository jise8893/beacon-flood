#ifndef SETTING_H
#define SETTING_H

#endif // SETTING_H
#include <iostream>
#include <cstdio>
#include <pcap.h>
#include <cstring>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <vector>
#include "beacon.h"
#include "information.h"
#include "rsn.h"
#include "supported.h"
#include "dstag.h"
void setpacket(BeaconPacket* BeaconPacket);
void Ssidtag(uint8_t *data,char *line);
void Rsntag(uint8_t *data,uint8_t len);
void Supported(uint8_t *data ,uint8_t len);
void Dstagset(uint8_t *data,uint8_t len);
