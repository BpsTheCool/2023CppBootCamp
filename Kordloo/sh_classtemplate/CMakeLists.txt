cmake_minimum_required(VERSION 3.5)

project(sh_classtemplate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sh_classtemplate main.cpp
Shared_Ptr.h)

install(TARGETS sh_classtemplate
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
