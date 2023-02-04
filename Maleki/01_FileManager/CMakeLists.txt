cmake_minimum_required(VERSION 3.14)

project(FileManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(gandzadi
  main.cpp
  file.h
  file.cpp
  MessageAndErrors.h
  storages.h
  storages.cpp
  flashmemory.h
  flashmemory.cpp
  filemanager.h
  filemanager.cpp
  cdrom.h
  cdrom.cpp
)
target_link_libraries(gandzadi Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS gandzadi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
