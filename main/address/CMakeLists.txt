add_library(address "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    address
    PRIVATE
        # Add the source files here
        socket_address.cpp
        ip_address.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/socket_address.h
        ${CMAKE_CURRENT_LIST_DIR}/ip_address.h
    )

target_include_directories(
    address
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
