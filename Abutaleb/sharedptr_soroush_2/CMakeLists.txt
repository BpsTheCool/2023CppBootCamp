cmake_minimum_required(VERSION 3.5)

project(Shared_ptr2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Shared_ptr2 main.cpp
shared_ptr.h)

install(TARGETS Shared_ptr2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
