cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "countUniqueWords")

set (SRC "main.cpp"
        "src/countUniqueWords.cpp"
        "src/newNameFile.cpp")


add_compile_options(
        -pipe
        -Wall
        -Wextra
        -Werror
        -Wpedantic
)

project (COUNT_UNIQUE_WORDS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})