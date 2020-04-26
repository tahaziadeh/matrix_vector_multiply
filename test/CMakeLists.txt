cmake_minimum_required(VERSION 3.17.1)

set(This MatrixVectorMultiplyTests)

set(Sources
    MatrixVectorMultiplyTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    MatrixVectorMultiply
)

add_test(
    NAME ${This}
    COMMAND ${This}
)