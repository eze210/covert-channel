#ifndef IP_HEADER_H
#define IP_HEADER_H

#include "socket_address.h"
#include "payload.h"

#include <netinet/ip.h>

class IPHeader {
private:
    struct iphdr internal;

public:
    IPHeader(const IPAddress &source,
             const IPAddress &destination,
             const Payload &payload);
    ~IPHeader();
    Payload as_payload() const;
};

#endif
