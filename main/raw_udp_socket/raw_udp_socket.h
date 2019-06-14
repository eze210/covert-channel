#ifndef RAW_UDP_SOCKET_H
#define RAW_UDP_SOCKET_H

#include "datagram.h"
#include "raw_ip_socket.h"

class RawUDPSocket : public RawIPSocket {
public:
    RawUDPSocket();
    void send(const Payload &message,
              const SocketAddress &source,
              const SocketAddress &destination);
    ~RawUDPSocket();
};

#endif
