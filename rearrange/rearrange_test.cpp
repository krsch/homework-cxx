#include <doctest.h>
#include <rearrange.hpp>

TEST_CASE("Empty") { REQUIRE(rearrange({}) == std::vector<int>{}); }
TEST_CASE("One pair") { REQUIRE(rearrange({1, 2}) == std::vector{1, 2}); }
TEST_CASE("Two pairs") { REQUIRE(rearrange({1, 2, 3, 4}) == std::vector{1, 3, 2, 4}); }
TEST_CASE("Duplicates") { REQUIRE(rearrange({1, 1, 1, 1, 1, 1}) == std::vector{1, 1, 1, 1, 1, 1}); }
TEST_CASE("Long") { REQUIRE(rearrange({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == std::vector{1, 6, 2, 7, 3, 8, 4, 9, 5, 10}); }
