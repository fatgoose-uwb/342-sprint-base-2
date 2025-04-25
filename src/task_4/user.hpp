/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

#include <string>
#include <vector>
#include "task_1/matrix.hpp"
#include "../task_3/formula.hpp"

class User {
private:
    std::string name;
    std::unordered_map<std::string, float> reviews;

public:
    User(const std::string &name, const std::unordered_map<std::string, float> &reviews) :
            name(name), reviews(reviews) {}

    std::unordered_map<std::string, float> &get_reviews() {
        return reviews;
    }

    std::string &get_name() {
        return name;
    }
};