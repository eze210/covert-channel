#ifndef IP_PACKET
#define IP_PACKET

#include "ip_header.h"
#include "payload.h"

class IPPacket {
private:
    const IPHeader &header;
    const Payload &payload;

public:
    IPPacket(const IPHeader &header,
             const Payload &payload);
    Payload as_payload() const;
    ~IPPacket();
};

#endif
