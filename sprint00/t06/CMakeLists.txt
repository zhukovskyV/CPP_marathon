cmake_minimum_required (VERSION  3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "meadSong")

set (SRC "main.cpp"
        "meadSong.cpp")

project (MEADSONG)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})