#ifndef CHANNEL_H
#define CHANNEL_H

#include "payload.h"
#include "socket_address.h"

class Channel {
public:
    virtual void send(const Payload &payload,
                      SocketAddress &destination) = 0;
    virtual Payload receive() = 0;
    virtual ~Channel() = default;
};

#endif
