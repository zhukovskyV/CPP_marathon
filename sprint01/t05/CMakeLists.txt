cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "stdAlgoV2")

set (SRC "main.cpp"
        "src/createNameNewFile.cpp"
        "src/errors.cpp"
        "src/parseAndPrint.cpp")

add_compile_options(
        -pipe
        -Wall
        -Wextra
        -Werror
        -Wpedantic
)

project (stdAlgoV2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})