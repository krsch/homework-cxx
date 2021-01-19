#include <doctest.h>
#include <maxlen.hpp>

namespace doctest {
template <> struct StringMaker<std::pair<int, int>> {
    static String convert(const std::pair<int, int> &value) {
        return String("{") + toString(value.first) + String(", ") +
               toString(value.second) + String("}");
    }
};
} // namespace doctest

TEST_CASE("Single") { REQUIRE(maxlen({1}) == 1); }
TEST_CASE("Reverse") { REQUIRE(maxlen({3, 2, 1}) == 1); }
TEST_CASE("Long") { REQUIRE(maxlen({1, 1, 1, 1, 2, 3, 4}) == 4); }
TEST_CASE("Double") { REQUIRE(maxlen({1, 2, 3, 4, 3, 2, 1, 2, 3}) == 4); }
TEST_CASE("Same") { REQUIRE(maxlen({1, 1, 1, 1, 1}) == 1); }
TEST_CASE("Empty") { REQUIRE(maxlen({}) == 0); }
TEST_CASE("Shifted") { REQUIRE(maxlen({3, 4, 5, 0}) == 3); }
TEST_CASE("Non-ordered") { REQUIRE(maxlen({3, 4, 2, 5}) == 2); }
