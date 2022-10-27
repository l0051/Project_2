cmake_minimum_required(VERSION 3.13)

project(postfix_to_infix)

set(CMAKE_CXX_STANDART 14)

add_executable(post_to_inf ../lib/lib.cpp main.cpp)

include_directories(../lib/)