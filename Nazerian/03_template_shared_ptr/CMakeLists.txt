cmake_minimum_required(VERSION 3.5)

project(template_shared_ptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(template_shared_ptr main.cpp
                                shared_ptr.h
                                shared_ptr.cpp
               )

install(TARGETS template_shared_ptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
