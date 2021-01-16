#include <doctest.h>
#include <minmax.hpp>

namespace doctest {
template <> struct StringMaker<std::pair<int, int>> {
    static String convert(const std::pair<int, int> &value) {
        return String("{") + toString(value.first) + String(", ") +
               toString(value.second) + String("}");
    }
};
} // namespace doctest
TEST_CASE("Single") { REQUIRE(minmax({1}) == std::pair{1, 1}); }
TEST_CASE("3") { REQUIRE(minmax({1, 2, 3}) == std::pair{1, 3}); }
TEST_CASE("Duplicates") { REQUIRE(minmax({1, 2, 1}) == std::pair{1, 2}); }