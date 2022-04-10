/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "unit_test_task_3.hpp"
#include "task_3/formula.hpp"

TEST(task_3, formula_test_int) {
    Formula<int> formula("x1 + x2 * x3 + x4");
    std::vector<int> values = {1, 2, 3, 4};
    int expect = values[0] + values[1] * values[2] + values[3];
    ASSERT_EQ(expect, formula.calculate(values));
}

TEST(task_3, formula_test_float) {
    Formula<float> formula("x1 + x2 * x3 +x4");
    std::vector<float> values = {1, 2, 3, 4};
    float expect = values[0] + values[1] * values[2] + values[3];
    ASSERT_EQ(expect, formula.calculate(values));
}

TEST(task_3, formula_test_matrix_multiply_add) {
    Matrix<int> matrix_a({
                                 {1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}
                         });
    Matrix<int> matrix_b({
                                 {1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}
                         });
    Matrix<int> matrix_c({
                                 {1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}
                         });
    Matrix<int> expect({
                               {31,  38,  45},
                               {70,  86,  102},
                               {109, 134, 159}
                       });

    auto f1 = new Formula<Matrix<int>>("x1 + x2 * x3");
    std::vector<Matrix<int>> values = {matrix_a, matrix_b, matrix_c};

    Matrix<int> actual = f1->calculate(values);

    ASSERT_EQ(expect, actual);

    delete f1;
}

TEST(task_3, recommendation_system_test_multiply_multiply) {
    Matrix<float> matrix_a({
                                   {4.00, 5.00, 2.00, 1.00},
                                   {2.00, 3.00, 5.00, 4.00},
                                   {3.00, 4.00, 1.00, 2.00},
                                   {1.00, 2.00, 3.00, 5.00},
                                   {5.00, 4.00, 3.00, 2.00}
                           });

    Matrix<float> matrix_b({
                                   {0.80, 0.10, 0.30, 0.70, 0.20, 0.40},
                                   {0.30, 0.40, 0.20, 0.90, 0.50, 0.10},
                                   {0.20, 0.50, 0.90, 0.10, 0.30, 0.40},
                                   {0.40, 0.70, 0.10, 0.50, 0.80, 0.30}
                           });

    Matrix<float> matrix_c({
                                   {0.90, 0.40, 0.80, 0.10, 0.60},
                                   {0.50, 0.90, 0.30, 0.60, 0.20},
                                   {0.60, 0.30, 1.00, 0.20, 0.10},
                                   {0.40, 0.60, 0.20, 0.90, 0.80},
                                   {0.30, 0.70, 0.10, 0.80, 1.00},
                                   {0.40, 0.50, 0.30, 0.70, 0.90}
                           });

    Matrix<float> expect({
                                 {15.349999f, 16.809999f, 12.760001f, 17.030001f, 18.510000f},
                                 {17.939999f, 20.629999f, 15.460000f, 19.980000f, 20.760000f},
                                 {12.830001f, 14.630000f, 10.209999f, 14.840000f, 16.080000f},
                                 {14.160000f, 17.180000f, 11.530001f, 16.680000f, 17.280001f},
                                 {18.250000f, 19.690001f, 15.470000f, 19.600000f, 21.480001f}
                         });

    Formula<Matrix<float>> formula("x1 * x2 * x3");
    std::vector<Matrix<float>> matrices = {matrix_a, matrix_b, matrix_c};

    Matrix<float> actual = formula.calculate(matrices);

    ASSERT_EQ(expect, actual);
}

TEST(task_3, recommendation_system_test_1_row) {
    Matrix<float> matrix_a({
                                   {1.00, 2.00, 3.00, 5.00},
                           });

    Matrix<float> matrix_b({
                                   {0.80, 0.10, 0.30, 0.70, 0.20, 0.40},
                                   {0.30, 0.40, 0.20, 0.90, 0.50, 0.10},
                                   {0.20, 0.50, 0.90, 0.10, 0.30, 0.40},
                                   {0.40, 0.70, 0.10, 0.50, 0.80, 0.30}
                           });

    Matrix<float> matrix_c({
                                   {0.90, 0.40, 0.80, 0.10, 0.60},
                                   {0.50, 0.90, 0.30, 0.60, 0.20},
                                   {0.60, 0.30, 1.00, 0.20, 0.10},
                                   {0.40, 0.60, 0.20, 0.90, 0.80},
                                   {0.30, 0.70, 0.10, 0.80, 1.00},
                                   {0.40, 0.50, 0.30, 0.70, 0.90}
                           });

    Matrix<float> expect({
                                 {14.160000f, 17.180000f, 11.530001f, 16.680000f, 17.280001f},
                         });

    Formula<Matrix<float>> formula("x1 * x2 * x3");
    std::vector<Matrix<float>> matrices = {matrix_a, matrix_b, matrix_c};

    Matrix<float> actual = formula.calculate(matrices);

    ASSERT_EQ(expect, actual);
}

/*
 * TODO: The following test, when enabled (by uncommenting the #define line) has a memory related
 *  issue. As an extra credit, explain in this text block what is the root cause of the issue, and
 *  propose a solution. No coding is required for getting this extra credit.
 *  Note: when submitting homework, please keep the #define line UN-commented, otherwise the bot will
 *  fail at this test.
 */

//#define ENABLE_RABBIT_HOLE
#ifdef ENABLE_RABBIT_HOLE

TEST(task_3, thou_shalt_not_shallow_copy) {
    Formula<int> formula_1("x1+x2*x3+x4");
    Formula<int> formula_2 = formula_1;
    std::vector<int> values = {5, 4, 3, 2};

    int actual = formula_1.calculate(values);
    ASSERT_EQ(values[0] + values[1] * values[2] + values[3], actual);

    actual = formula_2.calculate(values);
    ASSERT_EQ(values[0] + values[1] * values[2] + values[3], actual);
}
#endif