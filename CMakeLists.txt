cmake_minimum_required(VERSION 3.15)
project(ACO)

set(CMAKE_CXX_STANDARD 20)

add_executable(ACO main.cpp Matrix.cpp Matrix.h AntAlgorithm.cpp AntAlgorithm.h Ant.h Ant.cpp)