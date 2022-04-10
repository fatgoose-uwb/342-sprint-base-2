#include "problem_1.h"

CompoundResult
Compounder::calculate_without_roundOff(float init_deposit, float monthly_contribution, float length_in_year,
                                       float rate_in_percentage) {
    CompoundResult result;

    /*
     * homework
     */

    return result;
}

CompoundResult
Compounder::calculate(float init_deposit, float monthly_contribution, float length_in_year, float rate_in_percentage) {
    CompoundResult result;

    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        length_in_year <= 0) {
        return result;
    }

    result = calculate_without_roundOff(init_deposit, monthly_contribution, length_in_year, rate_in_percentage);

    result.accumulated = roundOff(result.accumulated);
    return result;
}

// https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
float Compounder::roundOff(float value) {
    int ret = (int) (value * 100 + .5);
    float r = (float) ret / 100;
    return r;
}

CompoundResult
Compounder::calculate(float init_deposit, float monthly_contribution, std::vector<float> interest_rates) {
    CompoundResult result;
    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        interest_rates.empty()) {
        return result;
    }

    result.invested = 0;
    result.accumulated = 0;
    float invested = init_deposit;

    // std::size_t in the loop to prevent comparison warning
    // https://stackoverflow.com/questions/3660901/a-warning-comparison-between-signed-and-unsigned-integer-expressions
    for (std::size_t i = 0; i < interest_rates.size(); i++) {
        float rate = interest_rates[i];
        float deposit = (i == 0) ? init_deposit : result.accumulated;
        result = calculate_without_roundOff(deposit, monthly_contribution, 1, rate);
        invested += monthly_contribution * 12;
    }

    result.invested = invested;
    result.accumulated = roundOff(result.accumulated);

    return result;
}