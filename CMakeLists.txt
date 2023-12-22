cmake_minimum_required(VERSION 3.27)
project(Casino)

set(CMAKE_CXX_STANDARD 17)

add_executable(Casino main.cpp
        Headers/SlotMachine.h
        Resources/SlotMachine.cpp
        Headers/Craps.h
        Resources/Craps.cpp)
