#include "minmax.hpp"
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
    auto [min, max] = minmax(input);
    std::cout << min << ", " << max << "\n";
}