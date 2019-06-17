#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include "socket_address.h"
#include "udp_message.h"

class UDPSocket {
private:
    SocketAddress &local_address;
    int file_descriptor;

public:
    UDPSocket(SocketAddress &local_address);
    void send(const UDPMessage &message);
    UDPMessage receive();
    ~UDPSocket();
};

#endif
