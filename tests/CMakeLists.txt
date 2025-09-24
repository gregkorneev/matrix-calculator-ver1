enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(matrix_calculator_tests test_matrix.cpp)
target_link_libraries(matrix_calculator_tests matrix_calculator GTest::GTest GTest::Main)

add_test(NAME matrix_calculator_tests COMMAND matrix_calculator_tests)
