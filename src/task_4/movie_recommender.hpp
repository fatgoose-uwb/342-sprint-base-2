/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#pragma once

#include <string>
#include <vector>
#include "task_1/matrix.hpp"
#include "../task_3/formula.hpp"
#include "movie.hpp"
#include "user.hpp"

class MovieRecommender {
private:
    Matrix<float> genre_feature;
    Formula<Matrix<float>> *ranking_algorithm;
    std::vector<Movie> movies;

public:
    MovieRecommender(Formula<Matrix<float>> *algorithm_formula, const std::vector<Movie> &movies) :
            genre_feature(
                    {
                            // rows: [documentary, drama, comedy, noir]
                            // columns: [historical, excitement, humor, emotional, mystery, action]
                            {1.0,  0.20, 0.10, 0.70, 0.10, 0.20},
                            {0.20, 0.70, 0.20, 0.90, 0.40, 0.40},
                            {0.20, 0.70, 1.0,  0.50, 0.20, 0.20},
                            {0.30, 0.50, 0.10, 0.60, 0.8,  0.30}
                    }), ranking_algorithm(algorithm_formula), movies(movies) {}

    Movie recommend(User &user) {
        /*
         * assemble the "user vs genre" matrix
         */
        Matrix<float> user_genre(
                {
                        {user.get_reviews()["documentary"],
                         user.get_reviews()["drama"],
                         user.get_reviews()["comedy"],
                         user.get_reviews()["noir"],
                        }
                });

        /*
         * assemble the "feature vs movie" matrix
         */
        std::vector<std::string> features = {
                "historical", "excitement", "humor", "emotional", "mystery", "action"};

        Matrix<float> feature_movie(features.size(), movies.size());
        for (int i = 0; i < features.size(); i++) {
            for (int j = 0; j < movies.size(); ++j) {
                feature_movie(i, j) = movies[j].get_features()[features[i]];
            }
        }

        /*
         * generate the result matrix
         */
        std::vector<Matrix<float>> matrices = {user_genre, genre_feature, feature_movie};
        Matrix<float> ranking = ranking_algorithm->calculate(matrices);

        /*
         * TODO: find the largest value in ranking, and return the corresponding movie as a recommendation
         */
        return movies[0]; // TODO: placeholder. Replace it with your own code.
    }
};