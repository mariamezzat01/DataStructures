cmake_minimum_required(VERSION 3.20)
project(trial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(trial
        main.cpp
        code.h
        )
