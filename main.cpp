#include "beacon.h"
void usage(){
    std::cout<<"syntx : beacon-flood <interface> <ssid-list-file>"<<std::endl;
    std::cout<<"sample : beacon-flood wlan0 ssid-list.txt";
}

int main(int argc, char *argv[])
{
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    FILE * desc;

    char line[SsidMax];
    std::vector<Information> vec;

    switch(argc){
        case 3:
            desc=fopen(argv[2],"r");
            while(!feof(desc))
            {
                fgets(line,SsidMax,desc);
                line[strlen(line)-1]='\0';
                Information information;
                strncpy(information.line,line,SsidMax);
                information.size=strlen(line);
                vec.push_back(information);

            }

            fclose(desc);

            vec.pop_back();
            dev=argv[1];
            handle= pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
            if (handle == nullptr) {
                 fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
                 return -1;
            }

            while(1){
                for(auto itr=vec.begin(); itr!=vec.end(); itr++){
                    printf("%s :%d\n",itr->line,itr->size);
                    BeaconPacket * Bp;
                    uint8_t *data=new uint8_t[sizeof(BeaconPacket)+itr->size+sizeof(Rsn)+sizeof(Supportag)+sizeof(Dstag)];
                    Bp=(BeaconPacket *)(data);
                    BeaconPacket::setpacket(Bp);
                    BeaconPacket::Ssidtag(data,itr->line);
                    BeaconPacket::Supported(data,sizeof(BeaconPacket)+itr->size);
                    BeaconPacket::Dstagset(data,sizeof(BeaconPacket)+itr->size+sizeof(Supportag));
                    BeaconPacket::Rsntag(data,sizeof(BeaconPacket)+itr->size+sizeof(Supportag)+sizeof(Dstag));


                    int res=pcap_sendpacket(handle,reinterpret_cast<const u_char*>(data),sizeof(BeaconPacket)+itr->size+sizeof(Rsn)+sizeof(Supportag)+sizeof(Dstag));
                    if(res!=0){
                        fprintf(stderr,"pcap_send packet return %d error=%s\n",res,pcap_geterr(handle));
                        return -1;
                    }
                    free(data);

                }
            }
            break;
      default:
        usage();
        break;
    }
}
