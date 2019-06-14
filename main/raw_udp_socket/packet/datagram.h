#ifndef UDP_DATAGRAM_H
#define UDP_DATAGRAM_H

#include "udp_header.h"
#include "payload.h"

class Datagram {
private:
    const Payload &payload;
    const UDPHeader &header;

public:
    Datagram(const UDPHeader &header,
             const Payload &payload);
    Payload as_payload() const;
    ~Datagram();
};

#endif
