cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "stdAlgoV1")

set (SRC "main.cpp"
        "src/errors.cpp"
        "src/pars.cpp"
        "src/print.cpp")

add_compile_options(
        -pipe
        -Wall
        -Wextra
        -Werror
        -Wpedantic
)

project (stdAlgoV1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})

