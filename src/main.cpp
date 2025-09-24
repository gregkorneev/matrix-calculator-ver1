#include <iostream>
#include "matrix.h"

/**
 * @brief Entry point for the demonstration program.
 *
 * The program creates two small matrices, performs a set of operations on
 * them, and prints the results. It also demonstrates the individual
 * assignment function to compute the sum of all elements in a matrix.
 */
int main() {
    try {
        // Create test matrices
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        // Fill matrix A
        A.data[0][0] = 1;
        A.data[0][1] = 2;
        A.data[1][0] = 3;
        A.data[1][1] = 4;

        // Fill matrix B
        B.data[0][0] = 5;
        B.data[0][1] = 6;
        B.data[1][0] = 7;
        B.data[1][1] = 8;

        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);

        std::cout << "\nMatrix B:" << std::endl;
        print_matrix(B);

        // Addition
        Matrix C = matrix_add(A, B);
        std::cout << "\nA + B:" << std::endl;
        print_matrix(C);

        // Multiplication
        Matrix D = matrix_multiply(A, B);
        std::cout << "\nA * B:" << std::endl;
        print_matrix(D);

        // Transpose
        Matrix E = matrix_transpose(A);
        std::cout << "\nTranspose of A:" << std::endl;
        print_matrix(E);

        // Individual assignment: sum of elements
        double total_sum = matrix_sum(A);
        std::cout << "\nSum of all elements in matrix A: " << total_sum
                  << std::endl;

        // Free allocated matrices (each matrix should be freed once)
        free_matrix(A);
        free_matrix(B);
        free_matrix(C);
        free_matrix(D);
        free_matrix(E);

        std::cout << "\nAll operations completed successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
