#include "common.hpp"

auto product(std::pair<int, int> p) { return p.first * p.second; }

auto max_product(std::vector<std::pair<int, int>> array)
    -> std::pair<int, int> {
    auto max = array[0];
    for (auto elem : array)
        // if (max.first * max.second < product(elem))
        if (product(max) < product(elem))
            max = elem;
    return max;
}