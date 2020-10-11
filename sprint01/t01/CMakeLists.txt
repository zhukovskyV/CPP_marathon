cmake_minimum_required (VERSION  3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "moveAlong")

set (SRC "main.cpp"
        "src/moveAlong")

project (MOVE_ALONG)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})