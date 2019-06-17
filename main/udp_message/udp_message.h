#ifndef UDP_MESSAGE
#define UDP_MESSAGE

#include "socket_address.h"
#include "payload.h"

class UDPMessage {
private:
    SocketAddress source;
    SocketAddress destination;
    Payload payload;

public:
    UDPMessage(SocketAddress &source,
               SocketAddress &destination,
               Payload &payload);
    UDPMessage(UDPMessage &&other);
    const SocketAddress &get_source() const;
    const SocketAddress &get_destination() const;
    const Payload &get_payload() const;
    ~UDPMessage();
};

#endif