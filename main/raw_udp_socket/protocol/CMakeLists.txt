add_library(protocol "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

include_directories(../utils)

target_sources(
    protocol
    PRIVATE
        # Add the source files here
        datagram.cpp
        ip_address.cpp
        ip_header.cpp
        ip_packet.cpp
        socket_address.cpp
        udp_header.cpp
        utils.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/datagram.h
        ${CMAKE_CURRENT_LIST_DIR}/ip_address.h
        ${CMAKE_CURRENT_LIST_DIR}/ip_header.h
        ${CMAKE_CURRENT_LIST_DIR}/ip_packet.h
        ${CMAKE_CURRENT_LIST_DIR}/socket_address.h
        ${CMAKE_CURRENT_LIST_DIR}/udp_header.h
        ${CMAKE_CURRENT_LIST_DIR}/utils.h
    )

target_include_directories(
    protocol
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
