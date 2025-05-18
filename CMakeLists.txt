cmake_minimum_required(VERSION 3.9.1)
project(conditional)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(target conditional)
 
set(files main.cpp conditional.hpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
add_executable(${target} ${files})