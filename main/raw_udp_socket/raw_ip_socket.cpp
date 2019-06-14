#include "raw_ip_socket.h"

#include <iostream>

RawIPSocket::RawIPSocket() : file_descriptor(socket (AF_INET, SOCK_RAW, IPPROTO_RAW)) {
    if (file_descriptor == -1) {
        throw OSException();
    }

    // broadcast permissions because of... things...
    int on = 1;
    setsockopt(file_descriptor, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
}

void RawIPSocket::send(const Payload &message,
                       const SocketAddress &source,
                       const SocketAddress &destination) {
    IPHeader header(source.get_ip_address(), destination.get_ip_address(), message);
    IPPacket packet(header, message);
    Payload to_send(packet.as_payload());

    const struct sockaddr_in &sin = destination.get_linux_representation();
    int rv = sendto(file_descriptor,
                    to_send.data(), to_send.length(), 0,
                    (struct sockaddr *) &sin, sizeof (struct sockaddr_in));
    if (rv == -1) {
        throw OSException();
    }
}

RawIPSocket::~RawIPSocket() {
    if (file_descriptor != -1) {
        close(file_descriptor);
    }
}
