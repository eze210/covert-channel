#include "covert_channel_using_udp_header.h"

#include <iostream>
#include <string>

int send_mode(std::string dummy_file_name) {
    SocketAddress source("127.0.0.1", 7777);
    SocketAddress destination("127.0.0.1", 7778);
    
    std::ifstream dummy_input(dummy_file_name);
    CovertChannelUsingUDPHeader covert_source(source, dummy_input);

    std::string line;
    while (std::getline(std::cin, line)) {
        Payload payload(line);
        covert_source.send(payload, destination);
    }
    return 0;
}

int recv_mode() {
    SocketAddress source("127.0.0.1", 7777);
    SocketAddress destination("127.0.0.1", 7778);
    
    std::ifstream dummy_input("");
    CovertChannelUsingUDPHeader covert_destination(destination, dummy_input);

    while (true) {
        Payload received_payload = covert_destination.receive();
        std::string received_string(received_payload.data(), received_payload.length());
        std::cout << received_string << std::endl;
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    if (argc == 2) {
        return send_mode(argv[1]);
    } else if (argc == 1) {
        return recv_mode();
    }
    std::cerr << "Wrong parameters" << std::endl;
    return 1;
}
