#include "os_exception.h"
#include "udp_socket.h"

#include <cstring>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

UDPSocket::UDPSocket(SocketAddress &local_address) 
    : local_address(local_address)
    , file_descriptor(-1) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;      /* IPv4 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    char service[32] = "";
    snprintf(service, 31, "%hu", local_address.get_port());
    int s = getaddrinfo(NULL, service, &hints, &result);

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        file_descriptor = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (file_descriptor == -1)
            continue;

        if (bind(file_descriptor, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success */

        close(file_descriptor);
    }

    if (rp == NULL) {
        throw OSException();
    }

    freeaddrinfo(result);
}

UDPMessage UDPSocket::receive() {
    std::vector<char> v(256);
    struct sockaddr_in src_addr;
    socklen_t addrlen = sizeof(src_addr);
    ssize_t length = recvfrom(file_descriptor,
                              v.data(), 256, 0,
                              (struct sockaddr*) &src_addr, &addrlen);

    SocketAddress source(src_addr);
    Payload received_payload(v.data(), length);

    UDPMessage message(source, local_address, received_payload);
    return std::move(message);
}

UDPSocket::~UDPSocket() {
    if (file_descriptor != -1) {
        close(file_descriptor);
    }
}
