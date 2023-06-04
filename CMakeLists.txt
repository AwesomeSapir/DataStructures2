cmake_minimum_required(VERSION 3.21)
project(DataStructures2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructures2 main.cpp Heap.cpp Heap.h Item.cpp Item.h MinMax.cpp MinMax.h MedianHeap.cpp MedianHeap.h InputFunc.cpp InputFunc.h)
