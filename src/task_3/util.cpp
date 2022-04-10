/*
 * DO NOT MAKE ANY CHANGES
 */
#include "util.hpp"

bool containsAsterisk(const std::string &input) {
    return input.find('*') != std::string::npos;
}

void split_string(const std::string &str, char deliminator, std::vector<std::string> &items) {
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, deliminator)) {
        items.push_back(item);
    }
}
