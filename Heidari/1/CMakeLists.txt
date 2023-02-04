cmake_minimum_required(VERSION 3.14)

project(FileManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

include_directories(
    include
)

add_executable(FileManager
  main.cpp
  include/IDrive.h
  include/fileclass.h src/fileclass.cpp
  include/hddinternal.h src/hddinternal.cpp
  include/filemanager.h src/filemanager.cpp
  include/idrivewrapper.h src/idrivewrapper.cpp
  include/DiskType.h
)
target_link_libraries(FileManager Qt${QT_VERSION_MAJOR}::Core)
