cmake_minimum_required(VERSION 3.5)

project(shared_ptr_int LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr_int main.cpp
                              shared_ptr_int.h
                              shared_ptr_int.cpp )

install(TARGETS shared_ptr_int
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
