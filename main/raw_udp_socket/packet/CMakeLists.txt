add_library(packet "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    packet
    PRIVATE
        # Add the source files here
        datagram.cpp
        ip_packet.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/datagram.h
        ${CMAKE_CURRENT_LIST_DIR}/ip_packet.h
    )

target_include_directories(
    packet
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../header
        ${CMAKE_CURRENT_LIST_DIR}/../../address
        ${CMAKE_CURRENT_LIST_DIR}/../../utils
    )
