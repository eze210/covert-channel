#include "ip_address.h"

#include <string>
#include <arpa/inet.h>

IPAddress::IPAddress(const char *address_as_cstr) 
        : as_integer(inet_addr(address_as_cstr)) {
}

IPAddress::IPAddress(int address_as_integer) 
        : as_integer(address_as_integer) {
}

IPAddress::operator int() const {
    return as_integer;
}

IPAddress::~IPAddress() {
}
