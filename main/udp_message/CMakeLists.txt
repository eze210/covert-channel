add_library(udp_message "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    udp_message
    PRIVATE
        # Add the source files here
        udp_message.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/udp_message.h
    )

target_include_directories(
    udp_message
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../address
        ${CMAKE_CURRENT_LIST_DIR}/../utils
    )

target_link_libraries(udp_message address utils)
