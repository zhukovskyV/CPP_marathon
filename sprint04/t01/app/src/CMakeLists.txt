cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(src)

add_library(src STATIC
        Axe.cpp
        ImperialSoldier.cpp
        StormcloakSoldier.cpp
        Sword.cpp
        )