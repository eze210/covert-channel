#ifndef UDP_HEADER_H
#define UDP_HEADER_H

#include "socket_address.h"
#include "payload.h"

#include <arpa/inet.h>
#include <cstdint>
#include <netinet/udp.h>  // Provides declarations for udp header

class UDPHeader {
private:
    struct udphdr internal;

public:
    UDPHeader(const SocketAddress &source_address,
              const SocketAddress &destination_address,
              const Payload &payload);

    Payload as_payload() const;

    ~UDPHeader();
};

#endif
