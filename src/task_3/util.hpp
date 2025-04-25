/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "../task_1/matrix.hpp"
#include <stdexcept>
#include <random>
#include <chrono>

bool containsAsterisk(const std::string &input);

void split_string(const std::string &str, char deliminator, std::vector<std::string> &items);

template<typename T>
void generate_random_matrices(size_t num_of_matrices,
                              size_t rows, size_t cols,
                              T x, T y,
                              std::vector<Matrix<T>> &result) {
    if (x > y) {
        throw std::invalid_argument("Lower bound x must be less than or equal to upper bound y");
    }

    // Initialize random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist(x, y);

    result.clear();

    for (size_t i = 0; i < num_of_matrices; ++i) {
        Matrix<T> matrix(rows, cols);
        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) {
                matrix(r, c) = dist(gen);
            }
        }
        result.push_back(matrix);
    }
}

template<typename T>
bool compare_matrix(const Matrix<T> &mat1, const Matrix<T> &mat2) {
    if (mat1.getRows() != mat2.getRows() || mat1.get_cols() != mat2.get_cols()) {
        return false;
    }

    T epsilon;
    if constexpr (std::is_same_v<T, float>) {
        epsilon = std::numeric_limits<float>::epsilon();
    } else if constexpr (std::is_same_v<T, double>) {
        epsilon = std::numeric_limits<double>::epsilon();
    } else {
        epsilon = T(); // For non-floating point types
    }

    for (size_t i = 0; i < mat1.getRows(); ++i) {
        for (size_t j = 0; j < mat1.get_cols(); ++j) {
            if constexpr (std::is_floating_point_v<T>) {
                if (std::fabs(mat1(i, j) - mat2(i, j)) > epsilon) {
                    return false;
                }
            } else {
                if (mat1(i, j) != mat2(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}