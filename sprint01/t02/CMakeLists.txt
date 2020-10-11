cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "visitAll")

set (SRC "main.cpp"
        "src/parseTown.cpp"
        "src/validator.cpp"
        "src/printf.cpp"
        "src/insert.cpp"
        "src/parseNum.cpp"
        "src/parseName.cpp")

project (visitAll)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})