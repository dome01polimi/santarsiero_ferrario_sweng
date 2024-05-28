cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplication)


include_directories(include)


add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_multiplication test/test_matrix_multiplication.cpp)
target_link_libraries(test_multiplication gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a)


enable_testing()


include(GoogleTest)
gtest_discover_tests(test_multiplication)
