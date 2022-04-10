/*
 * DO NOT MAKE ANY CHANGES
 */

#include <vector>
#include <cmath>
#include "../task_3/formula.hpp"

/*
 * based on https://www.investor.gov/financial-tools-calculators/calculators/compound-interest-calculator
 */
struct CompoundResult;

class Compounder {
public:
    CompoundResult calculate(double init_deposit,
                             double monthly_contribution,
                             int length_in_year,
                             double rate_in_percentage);

    CompoundResult calculate(double init_deposit,
                             double monthly_contribution,
                             std::vector<double> interest_rates);

    Compounder(Formula<double> *formula) : formula(formula) {}

private:
    Formula<double> *formula;

    CompoundResult calculate_without_roundoff(double init_deposit,
                                              double monthly_contribution,
                                              int length_in_year,
                                              double interest_rate_in_percentage);


    static double roundOff(double value);
};


/*
 * TODO: what's the difference between struct and class?
 */
struct CompoundResult {
public:
    double invested;
    double accumulated;

    CompoundResult(const CompoundResult &another_compound_result) : invested(another_compound_result.invested),
                                                                    accumulated(another_compound_result.accumulated) {}

    CompoundResult() : invested(0), accumulated(0) {}
};
