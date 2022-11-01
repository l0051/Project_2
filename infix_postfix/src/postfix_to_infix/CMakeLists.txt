cmake_minimum_required(VERSION 3.13)

project(postfix_to_infix)

set(CMAKE_CXX_STANDART 14)

add_executable(post_to_inf ../infix_postfix.cpp main.cpp)

include_directories(../../include/)