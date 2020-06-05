cmake_minimum_required(VERSION 3.10.0)
project(PRIORITY_QUEUE CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(pqueue pqueue.cpp pqueue_test.cpp)
