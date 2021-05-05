cmake_minimum_required(VERSION 3.17)
project(proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj main.cpp Client.cpp Client.h Garbage.cpp Garbage.h Bin.cpp Bin.h Truck.cpp Truck.h Algorithms.h)