cmake_minimum_required(VERSION 3.10.0)

project(Homework CXX)
include(cmake/StandardProjectSettings.cmake)
include(cmake/Catch.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_20)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)

enable_testing()
add_subdirectory(external/catch2)
add_subdirectory(tree)
add_subdirectory(tree-iterator)
add_subdirectory(random-access-iterator)
add_subdirectory(pqueue)
add_subdirectory(words)
add_subdirectory(isogram)
