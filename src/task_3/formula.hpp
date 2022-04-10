/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#pragma once

#include <string>
#include <vector>
#include "node.hpp"
#include "value_node.hpp"
#include "multiplication_node.hpp"
#include "addition_node.hpp"
#include "util.hpp"

template<typename T>
class Formula {
private:
    std::string formula_str;
    Node<T> *formula;
    std::vector<ValueNode<T> *> variables;

public:
    Formula(const std::string &formula_str) : formula_str(formula_str) {
        /*
         * TODO: store the given formula.
         */
    };

    T calculate(const std::vector<T> &values) {
        for (std::size_t i = 0; i < values.size(); i++) {
            variables[i]->setValue(values[i]);
        }
        return formula->evaluate();
    };

    ~Formula() {
        /*
         * TODO: clean up nodes.
         */
    };
};