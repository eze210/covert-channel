add_library(utils "")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

target_sources(
    utils
    PRIVATE
        # Add the source files here
        payload.cpp

    PUBLIC
        # Add headers here
        ${CMAKE_CURRENT_LIST_DIR}/os_exception.h
        ${CMAKE_CURRENT_LIST_DIR}/payload.h
    )

target_include_directories(
    utils
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
