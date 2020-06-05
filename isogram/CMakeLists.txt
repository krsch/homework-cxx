cmake_minimum_required (VERSION 3.10)
project(ISOGRAM CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(isogram isogram.cpp isogram_test.cpp)