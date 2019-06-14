#ifndef RAW_IP_SOCKET_H
#define RAW_IP_SOCKET_H

#include "ip_packet.h"
#include "os_exception.h"
#include <arpa/inet.h>
#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

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
