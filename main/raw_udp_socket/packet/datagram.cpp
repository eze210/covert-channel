#include "datagram.h"

#include <cstring>
#include <utility>

Datagram::Datagram(const UDPHeader &header,
                   const Payload &payload) 
        : payload(payload)
        , header(header) {
}

Payload Datagram::as_payload() const {
    Payload result(header.as_payload());
    result += payload;
    return std::move(result);
}

Datagram::~Datagram() {
}
