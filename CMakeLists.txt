cmake_minimum_required(VERSION 3.17.1)

set(This MatrixVectorMultiply)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDANT_CODE ON)

enable_testing()
add_subdirectory(googletest)

set(Headers
    MatrixVectorMultiply.hpp
)

set(Sources
    MatrixVectorMultiply.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)