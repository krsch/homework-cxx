#include "maxlen.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::istringstream ss(s);

    std::vector<int> input;
    int i;
    while (ss >> i)
        input.emplace_back(i);
    auto maxlength = maxlen(input);
    std::cout << maxlength << "\n";
}