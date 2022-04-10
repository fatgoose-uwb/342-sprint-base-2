/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "task_1/matrix.hpp"
#include "task_3/util.hpp"

TEST(task_1, matrix_multiplication) {
    Matrix<int> matrix_a(
            {
                    {7, 2, 9, 4, 3},
                    {1, 6, 8, 5, 10},
                    {3, 9, 2, 7, 4},
                    {5, 4, 1, 6, 8}
            });

    Matrix<int> matrix_b(
            {
                    {4, 2,  8, 5,  7, 3},
                    {6, 9,  1, 10, 3, 2},
                    {5, 3,  7, 2,  4, 8},
                    {1, 10, 6, 4,  9, 7},
                    {2, 8,  3, 6,  5, 1}
            });
    Matrix<int> expected_a_multiple_b(
            {
                    {95,  123, 154, 107, 142, 128},
                    {105, 210, 130, 161, 152, 124},
                    {91,  195, 101, 161, 139, 96},
                    {71,  173, 111, 139, 145, 81}
            });


    /*
     * verify matrix multiply
     */
    Matrix<int> actual = matrix_a * matrix_b;
    ASSERT_EQ(expected_a_multiple_b, actual);

    /*
     * verify exception is thrown when input is wrong (matrix dimensions don't match)
     */
    EXPECT_THROW(matrix_b * matrix_b, std::invalid_argument);
}

TEST(task_1, matrix_addition) {
    Matrix<int> matrix_a(
            {
                    {7, 2, 9, 4, 3},
                    {1, 6, 8, 5, 10},
                    {3, 9, 2, 7, 4},
                    {5, 4, 1, 6, 8}
            });

    Matrix<int> matrix_b(
            {
                    {8, 3,  10, 5, 4},
                    {2, 7,  9,  6, 11},
                    {4, 10, 3,  8, 5},
                    {6, 5,  2,  7, 9}
            });
    Matrix<int> expected_a_add_b(
            {
                    {15, 5,  19, 9,  7},
                    {3,  13, 17, 11, 21},
                    {7,  19, 5,  15, 9},
                    {11, 9,  3,  13, 17}
            });
    Matrix<int> matrix_mismatched_dimension(
            {
                    {95,  123, 154, 107, 142, 128},
                    {105, 210, 130, 161, 152, 124},
                    {91,  195, 101, 161, 139, 96},
                    {71,  173, 111, 139, 145, 81}
            });

    /*
     * verify matrix addition
     */
    Matrix<int> actual = matrix_a + matrix_b;
    ASSERT_EQ(expected_a_add_b, actual);

    /*
     * verify exception is thrown when input is wrong (matrix dimensions don't match)
     */
    EXPECT_THROW(matrix_b + matrix_mismatched_dimension, std::invalid_argument);
}

/*
 * Note: this performance test assumes the matrix multiply function has passed the logic/function tests above.
 */
TEST(task_1, performance_test) {
    /*
     * generate data
     */
    std::vector<Matrix<float>> matrices;
    int dimension = 300;
    generate_random_matrices<float>(2, dimension, dimension, 1.0, 100.0, matrices);

    /*
     * evaluate the formula using the data
     */
    auto start_time = std::chrono::high_resolution_clock::now(); // Start measuring time

    Matrix<float> r2 = matrices[0] * matrices[1];

    auto end_time = std::chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    /*
     * TODO (optional): how long does it take to run this on your computer?
     *  Matrix multiply is widely used, more so in the AI age. So it's very important to make it as
     *  efficient as possible. Do some research to come up with some ideas on how to make it faster.
     *  Here's a classic work in this area: https://users.umiacs.umd.edu/~ramani/cmsc662/Goto_vdGeijn.pdf
     *  And this is one implementation that my PhD advisor Jack Dongarra wrote in
     *  1989: https://www.netlib.org/blas/dgemm.f. Yes it's in Fortran.
     */
    printf("perf: (%d, %d) x (%d, %d). Took %ld ms\n",
           dimension, dimension, dimension, dimension, (long) duration_ms.count());
}

