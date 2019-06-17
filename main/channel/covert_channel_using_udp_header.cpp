#include "covert_channel_using_udp_header.h"
#include "socket_address.h"

#include <cstdint>

CovertChannelUsingUDPHeader::CovertChannelUsingUDPHeader(
    SocketAddress &receive_address,
    std::ifstream &dummy_input) 
    : dummy_input(dummy_input)
    , sender_socket()
    , receiver_socket(receive_address) {
}

void CovertChannelUsingUDPHeader::send(const Payload &payload,
                                       SocketAddress &destination) {
    const char *message = payload.data();
    uint16_t length = payload.length();

    int dummy_byte = dummy_input.get();
    if (dummy_byte == EOF) {
        throw FileIsNotEnoughError();
    }
    covert_send(length, dummy_byte, destination);

    for (size_t i = 0; i < length; ++i) {
        uint16_t covert_byte = message[i];
        int dummy_byte = dummy_input.get();
        if (dummy_byte == EOF) {
            throw FileIsNotEnoughError();
        }
        covert_send(covert_byte, dummy_byte, destination);
    }
}

void CovertChannelUsingUDPHeader::covert_send(uint16_t covert_short,
                                              char dummy_byte,
                                              SocketAddress &destination) {
    SocketAddress fake_address("127.0.0.1", covert_short);
    Payload payload(&dummy_byte, 1);
    UDPMessage message(fake_address, destination, payload);
    sender_socket.send(message);
}

Payload CovertChannelUsingUDPHeader::receive() {
    UDPMessage message = receiver_socket.receive();
    const SocketAddress &source = message.get_source();
    uint16_t length = source.get_port();
    Payload payload(length);

    for (int i = 0; i < length; ++i) {
        UDPMessage message = receiver_socket.receive();
        const SocketAddress &fake_source = message.get_source();
        uint16_t actual_byte = fake_source.get_port();
        payload[i] = actual_byte;
    }

    return std::move(payload);
}

CovertChannelUsingUDPHeader::~CovertChannelUsingUDPHeader() {
}
