#ifndef IP_ADDRESS_H
#define IP_ADDRESS_H

class IPAddress {
private:
    const int as_integer;

public:
    IPAddress(const char *address_as_cstr);
    IPAddress(int address_as_integer);
    operator int() const;
    ~IPAddress();
};

#endif
