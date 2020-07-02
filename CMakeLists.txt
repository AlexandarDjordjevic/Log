cmake_minimum_required(VERSION 3.5)

set (this Log)

project(${this})

set (src 
    src/Log.cpp 
    main.cpp
)

set (inc 
    include/Log.hpp
)

add_executable(${this} ${src} ${inc})

target_include_directories(${this} PUBLIC include)