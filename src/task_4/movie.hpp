/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

#include <string>
#include <vector>
#include "task_1/matrix.hpp"
#include "../task_3/formula.hpp"

class Movie {
private:
    std::string name;
    std::unordered_map<std::string, float> features;

public:
    Movie(const std::string &name, const std::unordered_map<std::string, float> &features) :
            name(name), features(features) {}

    Movie(const Movie &other)
            : name(other.name), features(other.features) {}

    std::unordered_map<std::string, float> &get_features() {
        return features;
    }

    bool operator==(const Movie &another_movie) const {
        return this->name == another_movie.name;
    }

    std::string &get_name() {
        return name;
    }
};