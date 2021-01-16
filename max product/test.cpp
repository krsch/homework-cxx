#include "common.hpp"
#include <doctest.h>

namespace doctest {
template <> struct StringMaker<std::pair<int, int>> {
    static String convert(const std::pair<int, int> &value) {
        return String("{") + toString(value.first) + String(", ") +
               toString(value.second) + String("}");
    }
};
template <> struct StringMaker<std::vector<std::pair<int, int>>> {
    static String convert(const std::vector<std::pair<int, int>> &value) {
        String result("{");
        for (auto p : value)
            result += String("{") + toString(p.first) + String(", ") +
                      toString(p.second) + String("}");
        result += "}";
        return result;
    }
};
} // namespace doctest
TEST_CASE("Single") { REQUIRE(max_product({{1, 1}}) == std::pair{1, 1}); }
TEST_CASE("Two values") {
    REQUIRE(max_product({{1, 1}, {1, 2}}) == std::pair{1, 2});
}