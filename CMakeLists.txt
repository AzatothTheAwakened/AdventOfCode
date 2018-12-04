PROJECT(AdventOfCode CXX)
cmake_minimum_required(VERSION 3.12)

set(YEAR " " CACHE STRING "Which participation year?")
set(DAY " " CACHE STRING "Which event-day?")
set(PART " " CACHE STRING "Which part of the day?")



set(YEAR_DIR ${YEAR})
set(DAY_DIR "Day")
string(APPEND DAY_DIR ${DAY})
set(PART_DIR "Part")
string(APPEND PART_DIR ${PART})

set(MAIN_PATH ${YEAR_DIR})
string(APPEND MAIN_PATH "/" ${DAY_DIR} "/" ${PART_DIR} "/" "main.cpp")

#/${DAY_DIR}/${PART_DIR}/main.cpp")
message("Building ${MAIN_PATH}")

add_executable(solution ${MAIN_PATH})
if(EXISTS "${YEAD_DIR}/CMakeLists.txt")
    add_subdirectory("${YEAR}")
endif()