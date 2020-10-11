cmake_minimum_required(VERSION 3.10)

set(MAIN_TARGET "utilsLib")
set(SRCS main.cpp)
add_subdirectory(utils)

cmake_minimum_required(VERSION 3.10)

set(LIBMANE "utils")
project(${LIBMANE} VERSION 1.0.0)

add_library(${LIBMANE} INTERFACE)


target_include_directories(${LIBMANE} INTERFACE
        "${PROJECT_SOURCE_DIR}"
        )