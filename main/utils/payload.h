#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <string>
#include <cstdint>

class Payload {
private:
    char *buffer;
    uint16_t len;

    Payload &operator=(const Payload &other) = delete;
    Payload(const Payload &other) = delete;

public:
    Payload(const std::string &as_string);
    Payload(uint16_t length = 0);
    Payload(char *buffer, uint16_t length);
    Payload(Payload &&other);
    ~Payload();
    
    Payload &operator=(Payload &&other);
    Payload &operator+=(const Payload &other);
    uint16_t length() const;
    const char *data() const;
};

#endif
