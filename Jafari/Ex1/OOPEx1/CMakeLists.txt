cmake_minimum_required(VERSION 3.14)

project(OOPEx1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(OOPEx1
  main.cpp
  InterfaceDevice.cpp
  includes/InterfaceDevice.h
  CoolDisk.cpp
  includes/CoolDisk.h
  Flash.cpp
  includes/Flash.h
  HDDex.cpp
  includes/HDDex.h
)
target_link_libraries(OOPEx1 Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS OOPEx1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
