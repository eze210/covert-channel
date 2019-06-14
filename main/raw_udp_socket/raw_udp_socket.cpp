#include "raw_udp_socket.h"

RawUDPSocket::RawUDPSocket() : RawIPSocket() {
}

void RawUDPSocket::send(const Payload &message,
                        const SocketAddress &source,
                        const SocketAddress &destination) {
    UDPHeader header(source, destination, message);
    Datagram datagram(header, message);
    Payload packet_payload(datagram.as_payload());
    RawIPSocket::send(packet_payload, source, destination);
}

RawUDPSocket::~RawUDPSocket() {
}
