cmake_minimum_required(VERSION 3.17)
project(proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj main.cpp cmake-build-debug/Client.cpp cmake-build-debug/Client.h cmake-build-debug/RecicleBin.cpp cmake-build-debug/RecicleBin.h cmake-build-debug/Garbage.cpp cmake-build-debug/Garbage.h cmake-build-debug/Truck.cpp cmake-build-debug/Truck.h)