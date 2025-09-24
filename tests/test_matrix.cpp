#include "gtest/gtest.h"
#include "matrix.h"

TEST(MatrixTest, Add) {
    // Setup test matrices and expected results
    Matrix a = matrix_from_array((double[]){1,2,3,4},2,2);
    Matrix b = matrix_from_array((double[]){5,6,7,8},2,2);
    Matrix expected = matrix_from_array((double[]){6,8,10,12},2,2);

    // Operation
    Matrix result = matrix_add(a,b);

    // Assertions
    ASSERT_EQ(expected.rows, result.rows);
    ASSERT_EQ(expected.cols, result.cols);
    for(int i = 0; i < result.rows; ++i) {
        for(int j = 0; j < result.cols; ++j) {
            ASSERT_DOUBLE_EQ(expected.data[i][j], result.data[i][j]);
        }
    }

    // Clean up
    free_matrix(a);
    free_matrix(b);
    free_matrix(expected);
    free_matrix(result);
}

TEST(MatrixTest, Multiply) {
    Matrix a = matrix_from_array((double[]){1,2,3,4},2,2);
    Matrix b = matrix_from_array((double[]){5,6,7,8},2,2);
    Matrix expected = matrix_from_array((double[]){19,22,43,50},2,2);

    Matrix result = matrix_multiply(a,b);

    ASSERT_EQ(expected.rows, result.rows);
    ASSERT_EQ(expected.cols, result.cols);
    for(int i = 0; i < result.rows; ++i) {
        for(int j = 0; j < result.cols; ++j) {
            ASSERT_DOUBLE_EQ(expected.data[i][j], result.data[i][j]);
        }
    }
    free_matrix(a);
    free_matrix(b);
    free_matrix(expected);
    free_matrix(result);
}

TEST(MatrixTest, Transpose) {
    Matrix a = matrix_from_array((double[]){1,2,3,4,5,6},2,3);
    Matrix expected = matrix_from_array((double[]){1,3,5,2,4,6},3,2);

    Matrix result = transpose(a);

    ASSERT_EQ(expected.rows, result.rows);
    ASSERT_EQ(expected.cols, result.cols);
    for(int i = 0; i < result.rows; ++i) {
        for(int j = 0; j < result.cols; ++j) {
            ASSERT_DOUBLE_EQ(expected.data[i][j], result.data[i][j]);
        }
    }
    free_matrix(a);
    free_matrix(expected);
    free_matrix(result);
}

TEST(MatrixTest, MatrixSum) {
    Matrix a = matrix_from_array((double[]){1,2,3,4},2,2);
    double sum = matrix_sum(a);
    ASSERT_DOUBLE_EQ(sum, 10.0);
    free_matrix(a);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
