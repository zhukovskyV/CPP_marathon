cmake_minimum_required(VERSION 3.18.2)

file(GLOB CPPS "*.cpp")
add_library(lib ${CPPS})
target_include_directories(lib INTERFACE
        .
        )