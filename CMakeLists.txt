cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_SRC_LIST main.cpp)

set(SORTS_HEADERS_LIST sorts/sorts.h)

add_executable(algorithms ${MAIN_SRC_LIST} ${SORTS_HEADERS_LIST})
