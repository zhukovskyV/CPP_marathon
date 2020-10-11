cmake_minimum_required (VERSION  3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set (BIN "inventory")

set (SRC "main.cpp"
        "src/countargs.cpp"
        "src/empty.cpp"
        "src/exit.cpp"
        "src/insert.cpp"
        "src/remove.cpp"
        "src/show.cpp"
        "src/util.cpp")

project (inventory)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable (${BIN} ${SRC})