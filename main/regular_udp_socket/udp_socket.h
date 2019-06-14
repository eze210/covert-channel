#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include "payload.h"
#include "socket_address.h"

class UDPSocket {
public:
    UDPSocket();
    void send(const Payload &message,
              const SocketAddress &destination);
    ~UDPSocket();
};

#endif
