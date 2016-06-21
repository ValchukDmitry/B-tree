cmake_minimum_required(VERSION 3.2)
project(B_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BTree/BTree.cpp BTree/BTree.h)
add_executable(B_tree ${SOURCE_FILES})