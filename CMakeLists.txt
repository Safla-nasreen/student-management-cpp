cmake_minimum_required(VERSION 3.16)
project(StudentManagement CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp StudentManager.cpp)

find_package(GTest REQUIRED)
add_executable(tests test_student.cpp StudentManager.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main)