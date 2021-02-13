#include "beacon.h"
void BeaconPacket::Setpacket(BeaconPacket* BeaconPacket){
    BeaconPacket->radiotapheader.it_len=8;
    BeaconPacket->dot11frame.framecontrol.protocol=0;
    BeaconPacket->dot11frame.framecontrol.type=FrameControl::Type::Management;
    BeaconPacket->dot11frame.framecontrol.subtype=FrameControl::Management::Beacon;
    BeaconPacket->dot11frame.framecontrol.to_ds=0;
    BeaconPacket->dot11frame.framecontrol.from_ds=0;
    BeaconPacket->dot11frame.framecontrol.more_flag=0;
    BeaconPacket->dot11frame.framecontrol.retry=0;
    BeaconPacket->dot11frame.framecontrol.powermgmt=0;
    BeaconPacket->dot11frame.framecontrol.more_data=0;
    BeaconPacket->dot11frame.framecontrol.protected_frame=0;
    BeaconPacket->dot11frame.framecontrol.order=0;
    BeaconPacket->dot11frame.address_1=Mac("FF:FF:FF:FF:FF:FF");
    BeaconPacket->dot11frame.address_2=Mac("11:22:33:44:55:66");
    BeaconPacket->dot11frame.address_3=Mac("11:22:33:44:55:66");

}
void BeaconPacket::Ssidtag(uint8_t*data ,char * line){
    BeaconPacket* bp;
    bp=(BeaconPacket*)data;
    bp->ssidparam.taglen=strlen(line);
    memcpy(data+sizeof(BeaconPacket),line,strlen(line));
}
void BeaconPacket::Rsntag(uint8_t *data,uint8_t len){
  Rsn *rsn;
  rsn=(Rsn *)(data+len);
  rsn->tagnumber=48;
  rsn->taglen=20;
  rsn->rsnver=1;
  rsn->gcs=0x4ac0f00;
  rsn->pcsc=1;
  rsn->pcsl=0x4ac0f00;
  rsn->akmsc=1;
  rsn->akmk=0x4ac0f00;
  rsn->capab=0;

}
void BeaconPacket::Supported(uint8_t *data ,uint8_t len){
    Supportag * sp;
    sp=(Supportag *)(data+len);
    sp->tagnum=1;
    sp->taglen=8;
    sp->supportedrate1=0x82;
    sp->supportedrate2=0x84;
    sp->supportedrate3=0x8b;
    sp->supportedrate4=0x96;
    sp->supportedrate5=0x0c;
    sp->supportedrate6=0x12;
    sp->supportedrate7=0x18;
    sp->supportedrate8=0x24;
}
void BeaconPacket::Dstagset(uint8_t *data,uint8_t len){
    Dstag * dt;
    dt=(Dstag *)(data+len);
    dt->tagnum=3;
    dt->taglen=1;
    dt->channel=1;
}
