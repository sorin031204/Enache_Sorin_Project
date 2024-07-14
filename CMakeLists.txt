cmake_minimum_required(VERSION 3.26)
project(Enache_Sorin_Project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)
set(SOURCE_FILES main.cpp Note.h
        Note.cpp
        Collection.h
        Collection.cpp
        Observer.h
        Subject.h
        Display.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} core)


