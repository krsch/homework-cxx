#include "minmax.hpp"

auto minmax(std::vector<int> const &input) -> std::pair<int, int> {
    return {input[0], input[0]};
}