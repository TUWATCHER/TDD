cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("gtest")

enable_testing()
add_subdirectory(googletest)
add_executable(test_app main.cpp)
target_link_libraries(test_app gtest_main gmock_main)