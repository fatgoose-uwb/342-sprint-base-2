/*
 * DO NOT TOUCH THIS FILE
 */

#include "problem_1.h"
#include "gtest/gtest.h"

class CompounderTestCase {
public:
    float init_deposit;
    float monthly_contribution;
    float expect_money_invested;
    float expect_money_accumulated;

    CompounderTestCase(float init_deposit, float monthly_contribution, float money_invested, float money_accumulated)
            : init_deposit(init_deposit), monthly_contribution(monthly_contribution),
              expect_money_invested(money_invested),
              expect_money_accumulated(money_accumulated) {}

    virtual void verify(int case_id) = 0;

    void AssertResult(CompoundResult &actual, int case_id) {
        auto failure_msg = "Test case " + std::to_string(case_id) + " failed :(";
        ASSERT_FLOAT_EQ(expect_money_invested, actual.invested) << failure_msg;
        ASSERT_FLOAT_EQ(expect_money_accumulated, actual.accumulated) << failure_msg;
    }
};

class TestCasesConstRate : public CompounderTestCase {
public:
    int length_in_year;
    float interest_rate;

    TestCasesConstRate(float init_deposit, float monthly_contribution, int length_in_year, float interest_rate,
                       float money_invested, float money_accumulated) :
            CompounderTestCase(init_deposit, monthly_contribution,
                               money_invested, money_accumulated),
            length_in_year(length_in_year), interest_rate(interest_rate) {}

    void verify(int case_id) override {
        CompoundResult actual = Compounder::calculate(init_deposit, monthly_contribution,
                                                      length_in_year, interest_rate);
        AssertResult(actual, case_id);
    }
};

class TestCasesVaryingRate : public CompounderTestCase {
public:
    std::vector<float> interest_rates;

    TestCasesVaryingRate(float init_deposit, float monthly_contribution,
                         const std::vector<float> &interest_rates,
                         float money_invested, float money_accumulated) :
            CompounderTestCase(init_deposit, monthly_contribution,
                               money_invested, money_accumulated),
            interest_rates(interest_rates) {}

    void verify(int case_id) override {
        CompoundResult actual = Compounder::calculate(init_deposit, monthly_contribution, interest_rates);
        AssertResult(actual, case_id);
    }
};

#define RUN_TEST_CASES(c)  for (int i=0; i<(c).size(); i++) {(c)[i].verify(i);}