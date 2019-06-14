#include "ip_header.h"
#include "utils.h"

#include <cstring>

IPHeader::IPHeader(const IPAddress &source,
                   const IPAddress &destination,
                   const Payload &payload) {
    internal.ihl = 5;
    internal.version = 4;
    internal.tos = 0;
    internal.tot_len = sizeof(struct iphdr) + payload.length();
    internal.id = htonl(54321);
    internal.frag_off = 0;
    internal.ttl = 255;
    internal.protocol = IPPROTO_UDP;
    internal.check = 0;

    internal.saddr = (int) source;
    internal.daddr = (int) destination;

    char *packet = (char*) malloc(internal.tot_len);
    memcpy(packet, &internal, sizeof(internal));
    memcpy(packet + sizeof(internal), payload.data(), payload.length());

    internal.check = csum((unsigned short*) packet, internal.tot_len);
    free(packet);
}

Payload IPHeader::as_payload() const {
    Payload result((char*) &internal, sizeof(internal));
    return std::move(result);
}

IPHeader::~IPHeader() {
}
