#ifndef RAW_IP_SOCKET_H
#define RAW_IP_SOCKET_H

#include "payload.h"
#include "socket_address.h"

class RawIPSocket {
protected:
    int file_descriptor;

public:
    RawIPSocket();
    void send(const Payload &message,
              const SocketAddress &source,
              const SocketAddress &destination);
    virtual ~RawIPSocket();
};

#endif
