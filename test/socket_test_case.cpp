#include "gtest/gtest.h"
#include "ip_address.h"
#include "raw_udp_socket.h"
#include "socket_address.h"

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
    std::string payload_as_string("Mensaje");
    Payload payload(payload_as_string);

    SocketAddress source_address("8.8.8.8", 5000);
    SocketAddress destination_address("127.0.0.1", 7778);

    RawUDPSocket source_socket;
    source_socket.send(payload, source_address, destination_address);
}
