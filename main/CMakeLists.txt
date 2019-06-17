project(covertudp VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(address)
add_subdirectory(channel)
add_subdirectory(raw_udp_socket)
add_subdirectory(regular_udp_socket)
add_subdirectory(udp_message)
add_subdirectory(utils)
include_directories(address)
include_directories(channel)
include_directories(raw_udp_socket)
include_directories(regular_udp_socket)
include_directories(utils)
include_directories(udp_message)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Wextra -Werror")

add_executable(covertudp main.cpp)

target_link_libraries(
    covertudp
    address
    channel
    raw_udp_socket
    regular_udp_socket
    udp_message
    utils
    )
