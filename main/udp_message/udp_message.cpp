#include "udp_message.h"

UDPMessage::UDPMessage(SocketAddress &source,
                       SocketAddress &destination,
                       Payload &payload)
    : source(std::move(source))
    , destination(std::move(destination))
    , payload(std::move(payload)) {
}

UDPMessage::UDPMessage(UDPMessage &&other) 
    : source(std::move(other.source))
    , destination(std::move(other.destination))
    , payload(std::move(other.payload)) {
}

const SocketAddress &UDPMessage::get_source() const {
    return source;
}

const SocketAddress &UDPMessage::get_destination() const {
    return destination;
}

const Payload &UDPMessage::get_payload() const {
    return payload;
}

UDPMessage::~UDPMessage() {
}
