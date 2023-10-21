cmake_minimum_required(VERSION 3.26)
project(ADS_Assignment_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADS_Assignment_3 main.cpp
        cmake-build-debug/KeyAndData.cpp
        cmake-build-debug/KeyAndData.h
        cmake-build-debug/BinaryTree.cpp
        cmake-build-debug/BinaryTree.h)
