add_library(raw_udp_socket "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    raw_udp_socket
    PRIVATE
        # Add the source files here
        raw_udp_socket.cpp
        raw_ip_socket.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/raw_ip_socket.h
        ${CMAKE_CURRENT_LIST_DIR}/raw_udp_socket.h
    )

add_subdirectory(protocol)
add_subdirectory(utils)

target_include_directories(
    raw_udp_socket
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/protocol
        ${CMAKE_CURRENT_LIST_DIR}/utils
    )

target_link_libraries(raw_udp_socket protocol utils)
