cmake_minimum_required(VERSION 3.5)

project(SharedPointer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SharedPointer main.cpp
               SharedPointer.cpp
               SharedPointer.h)

install(TARGETS SharedPointer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
