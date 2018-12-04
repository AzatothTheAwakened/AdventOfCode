cmake_minimum_required(VERSION 3.12)

file(GLOB 2018_LIB_SRC "lib/src/*.cpp")
add_library(2018_lib ${2018_LIB_SRC})
target_include_directories(PUBLIC 2018_lib "include")