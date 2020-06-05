cmake_minimum_required (VERSION 3.10)
project(WORDS CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(words words.cpp words_test.cpp)
