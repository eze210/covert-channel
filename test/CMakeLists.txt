set(CMAKE_CXX_FLAGS "-Wl,--wrap=listen ${CMAKE_CXX_FLAGS}")

add_executable(
    unit_tests
    socket_test_case.cpp
    payload_test.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    raw_udp_socket
    regular_udp_socket
    utils
    address
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )