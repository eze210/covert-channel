add_library(regular_udp_socket "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    regular_udp_socket
    PRIVATE
        # Add the source files here
        udp_socket.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/udp_socket.h
    )

target_include_directories(
    regular_udp_socket
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../udp_message
        ${CMAKE_CURRENT_LIST_DIR}/../utils
        ${CMAKE_CURRENT_LIST_DIR}/../address
    )

target_link_libraries(regular_udp_socket address utils)
