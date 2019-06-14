add_library(header "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    header
    PRIVATE
        # Add the source files here
        ip_header.cpp
        udp_header.cpp
        utils.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/ip_header.h
        ${CMAKE_CURRENT_LIST_DIR}/udp_header.h
        ${CMAKE_CURRENT_LIST_DIR}/utils.h
    )

target_include_directories(
    header
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../../address
        ${CMAKE_CURRENT_LIST_DIR}/../../utils
    )
