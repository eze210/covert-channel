#include "gtest/gtest.h"
#include "covert_channel_using_udp_header.h"

#include <fstream>

TEST(CovertChannelTest, CovertChannelTest) {
    SocketAddress source("127.0.0.1", 7777);
    SocketAddress destination("127.0.0.1", 7778);
    
    std::ifstream dummy_input("../test/lorem_ipsum.txt");
    ASSERT_TRUE(dummy_input.good());

    CovertChannelUsingUDPHeader covert_source(source, dummy_input);
    CovertChannelUsingUDPHeader covert_destination(destination, dummy_input);

    std::string message("The message");
    Payload sent_payload(message);
    covert_source.send(sent_payload, destination);

    Payload received_payload = covert_destination.receive();
    std::string received_string(received_payload.data(), received_payload.length());

    ASSERT_EQ(message, received_string);
}
