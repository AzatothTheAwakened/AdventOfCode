cmake_minimum_required(VERSION 3.12)

if(EXISTS "${DAY_DIR}/CMakeLists.txt")
    add_subdirectory("Day${DAY}")
endif()
add_subdirectory("lib")
target_include_directories(solution "lib/include")
target_link_libraries(solution 2018_lib)

