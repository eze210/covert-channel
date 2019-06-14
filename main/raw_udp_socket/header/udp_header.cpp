#include "udp_header.h"
#include "utils.h"
#include <cstring>
#include <cstdlib>
#include <vector>

static unsigned short calculate_checksum(
        const IPAddress &source_address,
        const IPAddress &destination_address,
        const Payload &payload,
        struct udphdr *udph) {
    struct {
        uint32_t source_address;
        uint32_t dest_address;
        uint8_t placeholder;
        uint8_t protocol;
        uint16_t udp_length;    
    } pseudo_header;

    pseudo_header.source_address = (int) source_address;
    pseudo_header.dest_address = (int) destination_address;
    pseudo_header.placeholder = 0;
    pseudo_header.protocol = IPPROTO_UDP;
    pseudo_header.udp_length = htons(sizeof(struct udphdr) + payload.length());
    
    int psize = sizeof(pseudo_header) + sizeof(struct udphdr) + payload.length();
    std::vector<char> pseudogram(psize);
    
    memcpy(pseudogram.data(), (char*) &pseudo_header, sizeof(pseudo_header));
    memcpy(pseudogram.data() + sizeof(pseudo_header), udph, sizeof(struct udphdr));
    memcpy(pseudogram.data() + sizeof(pseudo_header) + sizeof(struct udphdr), payload.data(), payload.length());
    
    return csum((unsigned short*) pseudogram.data(), psize);
}

UDPHeader::UDPHeader(const SocketAddress &source,
                     const SocketAddress &destination,
                     const Payload &payload) {
    internal.source = htons(source.get_port());
    internal.dest = htons(destination.get_port());
    internal.len = htons(8 + payload.length());
    internal.check = 0;
    internal.check = calculate_checksum(source.get_ip_address(),
                                        destination.get_ip_address(),
                                        payload, &internal);
}

Payload UDPHeader::as_payload() const {
    Payload result((char*) &internal, sizeof(internal));
    return std::move(result);
}

UDPHeader::~UDPHeader() {}
