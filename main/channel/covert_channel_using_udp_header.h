#ifndef COVERT_CHANNEL_USING_UDP_HEADER
#define COVERT_CHANNEL_USING_UDP_HEADER

#include "channel.h"
#include "raw_udp_socket.h"
#include "socket_address.h"
#include "udp_socket.h"

#include <exception>
#include <fstream>

class CovertChannelUsingUDPHeader : public Channel {
private:
    std::ifstream &dummy_input;
    RawUDPSocket sender_socket;
    UDPSocket receiver_socket;
    void covert_send(uint16_t covert_short,
                     char dummy_byte,
                     SocketAddress &destination);

public:
    CovertChannelUsingUDPHeader(SocketAddress &receive_address,
                                std::ifstream &dummy_input);
    void send(const Payload &payload,
              SocketAddress &destination) override;
    Payload receive() override;
    ~CovertChannelUsingUDPHeader();

    class FileIsNotEnoughError : public std::exception {
    public:
        const char *what() const throw() {
            return "File is not enough";
        }    
    };
};

#endif
