cmake_minimum_required(VERSION 3.5)

project(Dynamic_pointer_ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Dynamic_pointer_
    main.cpp
    Dynamicptr.h
    Dynamicptr.cpp)

install(TARGETS Dynamic_pointer_
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
