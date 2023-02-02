cmake_minimum_required(VERSION 3.5)

project(shared-ptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared-ptr main.cpp
                            Sharedptr.cpp
                            Sharedptr.h
                            Test.h
                            Test.cpp
                        )

install(TARGETS shared-ptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
