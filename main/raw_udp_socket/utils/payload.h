#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <string>

class Payload {
private:
    char *buffer;
    size_t len;

    Payload &operator=(const Payload &other) = delete;
    Payload(const Payload &other) = delete;

public:
    Payload(const std::string &as_string);
    Payload(size_t length = 0);
    Payload(char *buffer, size_t length);
    Payload(Payload &&other);
    ~Payload();
    
    Payload &operator=(Payload &&other);
    Payload &operator+=(const Payload &other);
    size_t length() const;
    const char *data() const;
};

#endif
