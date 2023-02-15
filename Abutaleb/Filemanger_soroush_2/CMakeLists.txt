cmake_minimum_required(VERSION 3.5)

project(Filemanger_05 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Filemanger_05 main.cpp
Filemanger.h Filemanger.cpp
Device.h Device.cpp
Iplugable.h Iplugable.cpp
Hdd.h Hdd.cpp
Ssd.h Ssd.cpp)

install(TARGETS Filemanger_05
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
