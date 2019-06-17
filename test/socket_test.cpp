#include "gtest/gtest.h"
#include "ip_address.h"
#include "raw_udp_socket.h"
#include "socket_address.h"
#include "udp_message.h"
#include "udp_socket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

TEST(SocketTestCase, CreationAndDestruction) {
    RawUDPSocket socket;
}

static int ip_address_bytes_to_int(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4) {
    int result = b1 << 24;
    result |= b2 << 16;
    result |= b3 << 8;
    result |= b4;
    return htonl(result);
}

TEST(SocketTestCase, IPAddressWrapper) {
    IPAddress ip_address("192.168.0.1");
    ASSERT_EQ(ip_address_bytes_to_int(192, 168, 0, 1), (int) ip_address);
}

TEST(SocketTestCase, SocketAddressWrapper) {
    SocketAddress socket_address("192.168.0.1", 80);
    const sockaddr_in &sin = socket_address.get_linux_representation();
    ASSERT_EQ(sin.sin_family, AF_INET);
    ASSERT_EQ(sin.sin_port, htons(80));
    ASSERT_EQ(sin.sin_addr.s_addr, ip_address_bytes_to_int(192, 168, 0, 1));
}

TEST(SocketTestCase, SingleMessage) {
    SocketAddress source_address("8.8.8.8", 5000);
    SocketAddress destination_address("127.0.0.1", 7778);

    RawUDPSocket source_socket;
    UDPSocket destination_socket(destination_address);

    std::string payload_as_string("Mensaje");
    Payload payload(payload_as_string);
    UDPMessage udp_message(source_address, destination_address, payload);
    source_socket.send(udp_message);

    UDPMessage received_message = destination_socket.receive();
    const Payload &received_payload = received_message.get_payload();
    ASSERT_EQ(payload_as_string.length(), received_payload.length());

    std::string internal_string(received_payload.data(), received_payload.length());
    ASSERT_EQ(internal_string, payload_as_string);

    const SocketAddress &received_src_addr= received_message.get_source();
    ASSERT_EQ(received_src_addr.get_port(), source_address.get_port()); 
}
