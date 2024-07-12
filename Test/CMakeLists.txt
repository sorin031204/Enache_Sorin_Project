cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 11)

add_subdirectory(lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp)
add_executable(runNoteTests ${TEST_SOURCE_FILES})
target_link_libraries(runNoteTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)