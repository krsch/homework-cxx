cmake_minimum_required(VERSION 3.10.0)
project(random-access-iterator CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(random-access random-access.cpp random-access_test.cpp)
