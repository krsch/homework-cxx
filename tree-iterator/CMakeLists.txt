cmake_minimum_required(VERSION 3.10.0)
project(tree-iterator CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(iterator iterator.cpp iterator_test.cpp)
