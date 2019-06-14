#ifndef SOCKET_ADDRESS_H
#define SOCKET_ADDRESS_H

#include "ip_address.h"
#include <arpa/inet.h>
#include <cstdint>
#include <sys/socket.h>

class SocketAddress {
private:
    IPAddress ip_address;
    uint16_t port;
    struct sockaddr_in internet_socket_address;

public:
    SocketAddress(const char *ip_address, uint16_t port);
    const struct sockaddr_in &get_linux_representation() const;
    const IPAddress &get_ip_address() const;
    uint16_t get_port() const;
    ~SocketAddress();
};

#endif
