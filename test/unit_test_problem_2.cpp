/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_2.h"
#include "unit_test_problem_2.h"

TEST(problem_2, new_array_list_with_capacity) {
    test_new_array_list_size_capacity<ArrayList<int>>();
}

TEST(problem_2, copy_constructor) {
    test_copy_constructor<ArrayList<int>>();
}

TEST(problem_2, push_back) {
    test_push_back<ArrayList<int>>();
}

TEST(problem_2, push_front) {
    test_push_front<ArrayList<int>>();
}

TEST(problem_2, pop_back) {
    test_pop_back<ArrayList<int>>();
}

TEST(problem_2, pop_front) {
    test_pop_front<ArrayList<int>>();
}

TEST(problem_2, merge) {
    test_merge_int<ArrayList<int>>();
    test_merge_string<ArrayList<std::string>>();
    test_merge_float<ArrayList<float>>();
}

TEST(problem_2, remove) {
    test_remove_primitive_number<ArrayList<int>, int>();
    test_remove_primitive_number<ArrayList<float>, float>();
    test_remove_string<ArrayList<std::string>>();
}

TEST(problem_2, equal) {
    test_equal_int<ArrayList<int>>();
    test_equal_string<ArrayList<std::string>>();
}