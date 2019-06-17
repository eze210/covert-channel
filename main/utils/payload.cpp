#include "payload.h"
#include <cstring>

Payload::Payload(const std::string &as_string) {
    len = as_string.length();
    buffer = new char[len];
    strncpy(buffer, as_string.c_str(), len);
}

Payload::Payload(uint16_t length) 
        : buffer(new char[length])
        , len(length) {
}

Payload::Payload(char *buffer, uint16_t length) 
        : buffer(new char[length])
        , len(length) {
    memcpy(this->buffer, buffer, length);
}

Payload::Payload(Payload &&other) {
    this->buffer = other.buffer;
    this->len = other.len;
    other.buffer = nullptr;
    other.len = 0;
}

Payload &Payload::operator=(Payload &&other) {
    this->buffer = other.buffer;
    this->len = other.len;
    other.buffer = nullptr;
    other.len = 0;
}

uint16_t Payload::length() const {
    return len;
}

const char *Payload::data() const {
    return buffer;
}

Payload::~Payload() {
    if (buffer != nullptr) {
        delete[] buffer;
    }
}

Payload &Payload::operator+=(const Payload &other) {
    uint16_t new_size = this->len + other.len;
    char *new_buffer = new char[new_size];
    memcpy(new_buffer, buffer, len);
    memcpy(new_buffer + len, other.buffer, other.len);
    delete[] buffer;
    this->len = new_size;
    this->buffer = new_buffer;
    return *this;
}

