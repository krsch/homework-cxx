#include "common.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::istringstream ss(s);

    std::vector<std::pair<int, int>> input;
    int i;
    int j;
    while (ss >> i && ss >> j)
        input.emplace_back(i, j);
    auto [min, max] = max_product(input);
    std::cout << min << ", " << max << "\n";
}
