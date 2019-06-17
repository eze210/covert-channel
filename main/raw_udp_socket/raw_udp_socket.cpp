#include "datagram.h"
#include "payload.h"
#include "raw_udp_socket.h"
#include "socket_address.h"

RawUDPSocket::RawUDPSocket() : RawIPSocket() {
}

void RawUDPSocket::send(const UDPMessage &message) {
    const Payload &payload = message.get_payload();
    const SocketAddress &source = message.get_source();
    const SocketAddress &destination = message.get_destination();
    UDPHeader header(source, destination, payload);
    Datagram datagram(header, payload);
    Payload packet_payload(datagram.as_payload());
    RawIPSocket::send(packet_payload, source, destination);
}

RawUDPSocket::~RawUDPSocket() {
}
