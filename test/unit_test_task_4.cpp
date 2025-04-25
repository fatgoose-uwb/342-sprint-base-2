/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "unit_test_task_3.hpp"
#include "task_3/formula.hpp"
#include "task_4/movie_recommender.hpp"

TEST(task_4, movie_recommendation) {
    Formula<Matrix<float>> formula("x1 * x2 * x3");
    std::vector<Movie> movies = {
            Movie("movie 1 - The West by Ken Burn",
                  {
                          {"historical", 1},
                          {"excitement", 0.4},
                          {"humor",      0.2},
                          {"emotional",  0.8},
                          {"mystery",    0.3},
                          {"action",     0.4},
                  }),

            Movie("movie 2 - Jason Bourne",
                  {
                          {"historical", 0.2},
                          {"excitement", 1},
                          {"humor",      0.2},
                          {"emotional",  0.4},
                          {"mystery",    0.5},
                          {"action",     1},
                  }),
            Movie("movie 3 - Titanic",
                  {
                          {"historical", 0.8},
                          {"excitement", 0.4},
                          {"humor",      0.3},
                          {"emotional",  1.0},
                          {"mystery",    0.2},
                          {"action",     0.3},
                  }),
            Movie("movie 4 Toy Story",
                  {
                          {"historical", 0.1},
                          {"excitement", 0.5},
                          {"humor",      0.5},
                          {"emotional",  0.8},
                          {"mystery",    0.4},
                          {"action",     0.6},
                  }),
            Movie("movie 5 - Seinfeld",
                  {
                          {"historical", 0.2},
                          {"excitement", 0.5},
                          {"humor",      1},
                          {"emotional",  0.7},
                          {"mystery",    0.2},
                          {"action",     0.2},
                  })
    };
    MovieRecommender recommender(
            &formula,
            movies);

    User user1("user 1, who loves comedy",
               {
                       {"documentary", 0.5},
                       {"drama",       0.5},
                       {"comedy",      5.0},
                       {"noir",        0.5},
               });

    Movie actual = recommender.recommend(user1);
    ASSERT_EQ(movies[4], actual);

    User user2("user 2, who really enjoys documentary",
               {
                       {"documentary", 5},
                       {"drama",       0.5},
                       {"comedy",      0.5},
                       {"noir",        0.5},
               });

    actual = recommender.recommend(user2);
    ASSERT_EQ(movies[0], actual);

    User user3("user 3, who enjoys drama with a bit laughter",
               {
                       {"documentary", 0},
                       {"drama",       3},
                       {"comedy",      1},
                       {"noir",        0.3},
               });

    actual = recommender.recommend(user3);
    ASSERT_EQ(movies[1], actual);

    User user4("user 4, who breathes drama but needs a bit reality factors",
               {
                       {"documentary", 1},
                       {"drama",       5},
                       {"comedy",      0.1},
                       {"noir",        0.1},
               });
    actual = recommender.recommend(user4);
    ASSERT_EQ(movies[2], actual);
}
