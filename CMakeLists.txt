cmake_minimum_required(VERSION 3.26)
project(Enache_Sorin_Project)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Enache_Sorin_Project main.cpp
        Note.h
        Note.cpp
        Collection.h
        Collection.cpp
        Observer.h
        Subject.h)
target_link_libraries(Enache_Sorin_Project ${CURSES_LIBRARIES})


