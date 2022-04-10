/*
 * DO NOT TOUCH THIS FILE
 */

#include <vector>

/*
 * based on https://www.investor.gov/financial-tools-calculators/calculators/compound-interest-calculator
 */

struct CompoundResult {
public:
    float invested;
    float accumulated;

    CompoundResult(const CompoundResult &another_compound_result) :
            invested(another_compound_result.invested), accumulated(another_compound_result.accumulated) {}

    CompoundResult() : invested(0), accumulated(0) {}
};

class Compounder {
public:
    static CompoundResult calculate(float init_deposit,
                                    float monthly_contribution,
                                    float length_in_year,
                                    float rate_in_percentage);

    static CompoundResult calculate(float init_deposit,
                                    float monthly_contribution,
                                    std::vector<float> interest_rates);

private:
    static CompoundResult calculate_without_roundOff(float init_deposit,
                                                     float monthly_contribution,
                                                     float length_in_year,
                                                     float rate_in_percentage);

    static float roundOff(float value);
};