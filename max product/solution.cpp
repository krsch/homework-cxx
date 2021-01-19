#include "common.hpp"

auto product(std::pair<int, int> p) { return p.first * p.second; }

auto max_product(std::vector<std::pair<int, int>> array)
    -> std::pair<int, int> {
    auto max = array[0];
    auto max_product = product(max);
//    auto new_product = max_product;
    for (auto elem : array) {
        auto new_product = product(elem);
        if (max_product < new_product) {
            max = elem;
            max_product = new_product;
        }
    }
    return max;
}