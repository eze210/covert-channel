#include "socket_address.h"

SocketAddress::SocketAddress(const char *ip_address, uint16_t port)
        : ip_address(ip_address)
        , port(port) {
    internet_socket_address.sin_family = AF_INET;
    internet_socket_address.sin_port = htons(this->port);
    internet_socket_address.sin_addr.s_addr = (int) this->ip_address;
}

SocketAddress::SocketAddress(struct sockaddr_in &sockaddr_in) 
    : ip_address(sockaddr_in.sin_addr.s_addr)
    , port(ntohs(sockaddr_in.sin_port)) {
    internet_socket_address = sockaddr_in;    
}

const struct sockaddr_in &SocketAddress::get_linux_representation() const {
    return internet_socket_address;
}

const IPAddress &SocketAddress::get_ip_address() const {
    return ip_address;
}

uint16_t SocketAddress::get_port() const {
    return port;
}

SocketAddress::~SocketAddress() {
}
