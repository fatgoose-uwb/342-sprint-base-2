/*
 * DO NOT MAKE ANY CHANGES
 */

#include "unit_test_problem_1.h"

TEST(problem_1, negative_inputs_constant_rate) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(-2, 20, 1, 10, 0, 0),
            TestCasesConstRate(100, -1, 1, 10, 0, 0),
            TestCasesConstRate(100, 20, -1, 10, 0, 0),
            // interest rate can be negative
            TestCasesConstRate(100, 20, 1, -5, 340, 335),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, different_years) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(100, 20, 1, 10, 340, 350),
            TestCasesConstRate(100, 20, 2, 10, 580, 625),
            TestCasesConstRate(100, 20, 5, 10, 1300.00, 1626.28),
            TestCasesConstRate(100, 20, 10, 10, 2500, 4084.36),
            TestCasesConstRate(100, 40, 10, 10, 4900, 7909.34),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, different_interest_rate) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(100, 40, 10, 10, 4900, 7909.34),
            TestCasesConstRate(100, 40, 10, 20, 4900, 13079.34),
            TestCasesConstRate(100, 40, 10, 30, 4900, 21835.94),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, different_init_deposit) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(100, 500, 10, 20, 60100, 156371.27),
            TestCasesConstRate(1000, 500, 10, 20, 61000, 161943.83),
            TestCasesConstRate(5000, 500, 10, 20, 65000, 186710.77),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, different_monthly_contribute) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(1000, 1000, 10, 20, 121000, 317695.92),
            TestCasesConstRate(1000, 2000, 10, 20, 241000, 629200.11),
            TestCasesConstRate(1000, 3000, 10, 20, 361000, 940704.29),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, millionaire_in_10_years) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(7000, 4000, 10, 15, 487000, 1002897.38),
    };
    RUN_TEST_CASES(test_cases);
}

// it took 10 years to get to 1m, but only 5 years to 2m from 1m
TEST(problem_1, from_1m_to_2m) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(1002897.38, 4000, 5, 15, 1242897.38, 2340819.15),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, negative_inputs_varying_rate) {
    std::vector<TestCasesVaryingRate> test_cases = {
            TestCasesVaryingRate(-1, 20,
                                 std::vector<float>{10},
                                 0, 0),
            TestCasesVaryingRate(100, -2,
                                 std::vector<float>{10},
                                 0, 0),
            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{-5},
                                 340, 335),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, differnt_number_of_rates) {
    std::vector<TestCasesVaryingRate> test_cases = {
            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{10},
                                 340, 350),

            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{10, 10},
                                 580, 625),
            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{10, 20, -5},
                                 820, 867),
            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{-5, -10, 15},
                                 820, 862.73),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(problem_1, real_sp500_rates) {
    std::vector<TestCasesVaryingRate> test_cases = {
            // actual S&P 500 rates from 2013 to 2021
            // https://www.macrotrends.net/2526/sp-500-historical-annual-returns
            TestCasesVaryingRate(100, 20,
                                 std::vector<float>{29.6, 11.39, -0.73, 9.54, 19.42, -6.24, 28.88, 16.26, 26.89},
                                 2260, 4361.90),
    };
    RUN_TEST_CASES(test_cases);
}