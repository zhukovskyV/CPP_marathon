cmake_minimum_required(VERSION 3.18.2)

project(libVector LANGUAGES CXX)
add_library(libVector INTERFACE)
target_include_directories(libVector INTERFACE .)