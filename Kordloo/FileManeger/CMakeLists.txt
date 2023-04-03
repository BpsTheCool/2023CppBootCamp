cmake_minimum_required(VERSION 3.5)

project(FileManeger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FileManeger main.cpp
Hdd.h Hdd.cpp
Cd.h Cd.cpp
FelashMemory.h FelashMemory.cpp
ExternalHdd.h ExternalHdd.cpp
Divice.h Divice.cpp
File.h File.cpp
Filemaneger.h Filemaneger.cpp
)

install(TARGETS FileManeger
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
