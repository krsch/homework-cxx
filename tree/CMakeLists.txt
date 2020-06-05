cmake_minimum_required(VERSION 3.10.0)
project(tree CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(tree tree.cpp tree_test.cpp)
