#include <cstdio>
#include "problem_1.h"
#include "problem_2.h"

/*
 * This file is run through memory check.
 * However, any changes in this file will be ignored for grading, EXCEPT its memory leak
 * Meaning, if there's memory leak from this file, there will be points penalty
 */
void foo(std::vector<int> &vec);

int main(int argc, char **argv) {
    ArrayList<float> list1(3);
    list1.push_back(-0.2);
    list1.push_back(3.3);
    list1.push_back(9.2);

    ArrayList<float> list2(2);
    list2.push_back(1.2);
    list2.push_back(8);

    list1.merge(list2);
    for (size_t i = 0; i < list1.size(); i++) {
        printf("list1[%zu] = %.1f\n", i, list1[i]);
    }
    printf("list1.size = %zu, list1.capacity = %zu\n", list1.size(), list1.capacity());
}
