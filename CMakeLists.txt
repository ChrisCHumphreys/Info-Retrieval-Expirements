cmake_minimum_required(VERSION 3.9)
project(myCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(myCode
        Book.cpp
        Book.h
        InvertedIndex.cpp
        InvertedIndex.h
        readIn.cpp
        Term.cpp
        Term.h
        Utils.h)
