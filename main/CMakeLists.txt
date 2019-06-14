project(covertudp VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(raw_udp_socket)
include_directories(raw_udp_socket)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Wextra -Werror")

add_executable(covertudp main.cpp)

target_link_libraries(
    covertudp
    raw_udp_socket
    protocol
    utils
    )
