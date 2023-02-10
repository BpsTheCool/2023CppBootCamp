cmake_minimum_required(VERSION 3.5)

project(Filemanger3_soroush LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Filemanger3_soroush main.cpp
                                Filemanger.h
                                Filemanger.cpp
                                Device.h
                                Device.cpp
                                Drive.h
                                Drive.cpp
                                File.h
                                File.cpp
                                )


install(TARGETS Filemanger3_soroush
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
