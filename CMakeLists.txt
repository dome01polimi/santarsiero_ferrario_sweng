cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplication)

# Find MPI
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

# Include directories
include_directories(include)

# Add Google Test
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Source files
set(SOURCES src/main.cpp src/multiply_matrices_without_errors.cpp)

# Main executable
add_executable(main ${SOURCES})
target_link_libraries(main ${MPI_LIBRARIES})

# Test executable
add_executable(test_multiplication test/test_matrix_multiplication.cpp)
target_link_libraries(test_multiplication gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a ${MPI_LIBRARIES})

# Add MPI compile definitions
if (MPI_COMPILE_FLAGS)
  set_target_properties(main PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
  set_target_properties(test_multiplication PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif ()

if (MPI_LINK_FLAGS)
  set_target_properties(main PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
  set_target_properties(test_multiplication PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif ()

# Enable testing
enable_testing()

# Add test
include(GoogleTest)
gtest_discover_tests(test_multiplication)
