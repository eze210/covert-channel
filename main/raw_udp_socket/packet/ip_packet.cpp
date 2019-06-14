#include "ip_packet.h"
#include <utility>

IPPacket::IPPacket(const IPHeader &header,
                   const Payload &payload) 
        : header(header)
        , payload(payload) {
}

Payload IPPacket::as_payload() const {
    Payload result(header.as_payload());
    result += payload;
    return std::move(result);
}

IPPacket::~IPPacket() {
}
