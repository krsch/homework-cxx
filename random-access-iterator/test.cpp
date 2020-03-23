#include "tree.hpp"
#include <catch.hpp>

TEST_CASE("can iterate", "[random access]") {
  tree t{{{1, 2, 3}, 4, {5, 6, 7}}};
  int v = 1;
  for (int i : t) {
    CHECK(i == v++);
  }
  REQUIRE(v == 8);
}

TEST_CASE("can reverse iterate", "[random access]") {
  tree t{{{1, 2, 3}, 4, {5, 6, 7}}};
  int v = 7;
  std::for_each(std::make_reverse_iterator(t.end()),
                std::make_reverse_iterator(t.begin()),
                [&v](int i) { CHECK(i == v--); });
  REQUIRE(v == 0);
}

TEST_CASE("operator[]" "[random access]") {
  tree t{{{1, 2, 3}, 4, {5, 6, 7}}};
  for (int i=0; i<7; ++i)
    CHECK(t[i] == i + 1);
}
