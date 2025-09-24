#pragma once

/**
 * @brief Simple dynamic matrix type.
 *
 * This structure stores a two‑dimensional array of doubles along with
 * the number of rows and columns. Memory for the data must be
 * allocated manually using create_matrix() and freed with
 * free_matrix().
 */
typedef struct {
    double** data; /**< Pointer to a 2‑D array of matrix elements */
    int rows;      /**< Number of rows */
    int cols;      /**< Number of columns */
} Matrix;

// Basic matrix management

/**
 * @brief Allocate a new matrix of the given size.
 *
 * @param rows Number of rows (must be positive)
 * @param cols Number of columns (must be positive)
 * @return Newly created Matrix with all elements initialised to zero.
 * @throws std::invalid_argument if rows or cols is non‑positive.
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Free the memory associated with a matrix.
 *
 * Passing a matrix with a null data pointer is safe and does nothing.
 * Each matrix should only be freed once.
 *
 * @param m Matrix to free
 */
void free_matrix(Matrix m);

/**
 * @brief Add two matrices elementwise.
 *
 * Both matrices must have the same dimensions.
 *
 * @param a First matrix
 * @param b Second matrix
 * @return Matrix representing the sum of a and b
 * @throws std::invalid_argument if the dimensions do not match
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Multiply two matrices.
 *
 * The number of columns of the first matrix must equal the number of
 * rows of the second matrix.
 *
 * @param a Left matrix
 * @param b Right matrix
 * @return Matrix product of a and b
 * @throws std::invalid_argument if the dimensions are not compatible
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Transpose a matrix.
 *
 * @param m Matrix to transpose
 * @return New matrix which is the transpose of m
 */
Matrix matrix_transpose(Matrix m);

// Helper functions

/**
 * @brief Print a matrix to stdout in a human‑readable format.
 *
 * @param m Matrix to print
 */
void print_matrix(Matrix m);

/**
 * @brief Create a matrix from a contiguous array of doubles.
 *
 * Elements are read in row‑major order from the provided array.
 *
 * @param data Pointer to an array of length rows*cols
 * @param rows Number of rows
 * @param cols Number of columns
 * @return Matrix containing the provided data
 */
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Compute the sum of all elements in a matrix.
 *
 * If the matrix is uninitialised or has zero dimensions the sum is 0.0.
 *
 * @param m Matrix for which to compute the sum
 * @return Sum of all elements
 */
double matrix_sum(Matrix m);
