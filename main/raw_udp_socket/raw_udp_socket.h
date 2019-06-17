#ifndef RAW_UDP_SOCKET_H
#define RAW_UDP_SOCKET_H

#include "raw_ip_socket.h"
#include "udp_message.h"

class RawUDPSocket : public RawIPSocket {
public:
    RawUDPSocket();
    void send(const UDPMessage &message);
    ~RawUDPSocket();
};

#endif
