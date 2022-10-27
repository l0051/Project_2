cmake_minimum_required(VERSION 3.13)

project(word_occupancy)

set(CMAKE_CXX_STANDART 14)

add_executable(word_occup ../lib/lib.cpp main.cpp)

include_directories(../lib/)