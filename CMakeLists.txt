# Gotten from
# https://github.com/snikulov/google-test-examples
# http://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake

cmake_minimum_required(VERSION 2.8)
project(rezone)

find_package(Threads REQUIRED)

# add_definitions(-Wall -ansi -Wno-deprecated -pthread)

# GTest
enable_testing()
add_subdirectory(ext/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Tests
file(GLOB files_src_test test/main/*.cpp)
add_executable(testMain ${files_src_test})
set_property(TARGET testMain PROPERTY OUTPUT_NAME test)
target_link_libraries(testMain mainLib gtest gtest_main pthread)
add_test(test test)  # so that ctest finds the tests

# MainLib
file(GLOB files_src_main src/main/*.cpp)
add_library(mainLib STATIC ${files_src_main})
target_include_directories(mainLib INTERFACE "src/main")

# Main
add_executable(main src/Main.cpp)
target_link_libraries(main mainLib)
set_property(TARGET main PROPERTY OUTPUT_NAME rezone)
