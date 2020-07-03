cmake_minimum_required(VERSION 3.5)

set (this Log)

project(${this})

set (CMAKE_CXX_STANDARD 11)

add_executable(${this} main.cpp)

target_include_directories(${this} PUBLIC include)