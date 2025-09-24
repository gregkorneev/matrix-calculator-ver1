cmake_minimum_required(VERSION 3.20)

# Project definition
project(Matrix_Calculator VERSION 0.1 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library target for matrix functions
add_library(matrix_lib src/matrix.cpp)
target_include_directories(matrix_lib PUBLIC include)

# Executable target for demonstration program
add_executable(matrix_calculator src/main.cpp)
target_link_libraries(matrix_calculator PRIVATE matrix_lib)

# Enable and add tests
enable_testing()
add_subdirectory(tests)
