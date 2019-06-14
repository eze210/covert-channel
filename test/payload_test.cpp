#include "gtest/gtest.h"
#include "payload.h"

TEST(PayloadTest, CreationAndDestruction) {
    std::string a_string("A string");
    Payload payload(a_string);
}

TEST(PayloadTest, CreateWithString) {
    std::string a_string("A string");
    Payload payload(a_string);

    std::string internal_string(payload.data(), payload.length());
    ASSERT_EQ(internal_string, a_string);
}

TEST(PayloadTest, Plus) {
    std::string a_string("A string");
    Payload a_payload(a_string);

    std::string other_string(" and other string");
    Payload other_payload(other_string);

    a_payload += other_payload;
    std::string complete_string = a_string + other_string;

    std::string internal_string(a_payload.data(), a_payload.length());
    ASSERT_EQ(internal_string, complete_string);
}
