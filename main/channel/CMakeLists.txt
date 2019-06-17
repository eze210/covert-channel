add_library(channel "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    channel
    PRIVATE
        # Add the source files here
        covert_channel_using_udp_header.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/channel.h
        ${CMAKE_CURRENT_LIST_DIR}/covert_channel_using_udp_header.h
    )

target_include_directories(
    channel
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../address
        ${CMAKE_CURRENT_LIST_DIR}/../raw_udp_socket
        ${CMAKE_CURRENT_LIST_DIR}/../regular_udp_socket
        ${CMAKE_CURRENT_LIST_DIR}/../regular_udp_socket/packet
        ${CMAKE_CURRENT_LIST_DIR}/../udp_message
        ${CMAKE_CURRENT_LIST_DIR}/../utils
    )
