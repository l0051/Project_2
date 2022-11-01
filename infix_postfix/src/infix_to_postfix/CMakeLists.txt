cmake_minimum_required(VERSION 3.13)

project(infix_to_postfix)

set(CMAKE_CXX_STANDART 14)

add_executable(inf_to_post ../infix_postfix.cpp main.cpp)

include_directories(../../include/)