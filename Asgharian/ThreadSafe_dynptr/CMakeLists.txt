cmake_minimum_required(VERSION 3.5)

project(ThreadSafe_dynptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ThreadSafe_dynptr main.cpp)

install(TARGETS ThreadSafe_dynptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
