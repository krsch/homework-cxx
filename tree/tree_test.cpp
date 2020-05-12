#include "catch.hpp"
#include "tree.hpp"
#include <numeric>


void check_tree(tree_node const &t) {
  if (t.left) {
    CHECK(t.left->value <= t.value);
    check_tree(*t.left);
  }
  if (t.right) {
    CHECK(t.right->value >= t.value);
    check_tree(*t.right);
  }
}

void tree_to_vector(tree_node const &t, std::vector<int> &res) {
  if (t.left)
    tree_to_vector(*t.left, res);
  res.push_back(t.value);
  if (t.right)
    tree_to_vector(*t.right, res);
}

std::vector<int> tree_to_vector(tree const &t) {
  std::vector<int> result;
  if (t.root)
    tree_to_vector(*t.root, result);
  return result;
}

TEST_CASE("Can insert many values") {
  tree t;
  for (int i = 0; i < 17; ++i)
    t.insert(i * 5 % 17);
  REQUIRE(t.root);
  check_tree(*t.root);
  std::vector<int> correct(17);
  std::iota(correct.begin(), correct.end(), 0);
  REQUIRE(tree_to_vector(t) == correct);
}

TEST_CASE("Can remove many values") {
  tree t;
  t.insert(3);
  t.insert(1);
  t.insert(2);
  t.insert(4);
  t.insert(5);
  t.remove(3);
  t.remove(5);
  t.insert(10);
  REQUIRE(t.root);
  check_tree(*t.root);
  REQUIRE(tree_to_vector(t) == std::vector{1, 2, 4, 10});
}

TEST_CASE("correct return values") {
  tree t;
  auto r = t.insert(3);
  REQUIRE(r);
  REQUIRE(r->value == 3);
  r = t.insert(3);
  REQUIRE(r);
  REQUIRE(r->value == 3);
  check_tree(*t.root);
  REQUIRE(t.remove(3));
  REQUIRE(!t.remove(3));
}

constexpr auto TEST_RANGE_MAX = 10;
TEST_CASE("insert many vals and remove elements with only right subtree "
          "(custom range)") {
  tree t;
  std::vector<int> correct(TEST_RANGE_MAX);
  std::iota(correct.begin(), correct.end(), 0);
  for (int i = 0; i < correct.size(); ++i) {
    auto val = static_cast<int>(correct.size()) / 2 +
               ((i % 2) * 2 - 1) * ((i + 1) / 2) - 1;
    auto r = t.insert(val);
    REQUIRE(r);
    REQUIRE(r->value == val);
  }
  REQUIRE(tree_to_vector(t) == correct);
  for (int i = 0; i < TEST_RANGE_MAX; ++i) {
    REQUIRE(t.root);
    check_tree(*t.root);
    // CHECK(
    //    t.remove(i)); // throws exception read access violation on bad
    //    solution.
    // dont know how to catch with REQUIRE statement
    bool check;
    CHECK_NOTHROW(([&] { check = t.remove(i); })());
    CHECK(check);
  }
  CHECK(!t.root);
}

TEST_CASE("insert many same values") {
  tree t;
  t.insert(2);
  t.insert(3);
  t.insert(2);
  t.insert(3);
  t.insert(2);
  check_tree(*t.root);
  REQUIRE(tree_to_vector(t) == std::vector{2, 2, 2, 3, 3});
  REQUIRE(t.remove(2));
  REQUIRE(!t.remove(2));
  REQUIRE(t.root);
  CHECK(tree_to_vector(t) == std::vector{3, 3});
  CHECK(t.remove(3));
  CHECK(!t.root);
}

TEST_CASE("insert, remove then insert again "
          "(custom range)") {
  tree t;
  std::vector<int> correct(TEST_RANGE_MAX);
  std::iota(correct.begin(), correct.end(), 0);
  for (int i = 0; i < correct.size(); ++i) {
    auto val = static_cast<int>(correct.size()) / 2 +
               ((i % 2) * 2 - 1) * ((i + 1) / 2) - 1;
    auto r = t.insert(val);
    REQUIRE(r);
    REQUIRE(r->value == val);
  }
  REQUIRE(tree_to_vector(t) == correct);
  for (int i = 0; i < TEST_RANGE_MAX; ++i) {
    REQUIRE(t.root);
    check_tree(*t.root);
    CHECK(
        t.remove(i)); // throws exception read access violation on bad solution.
                      // dont know how to catch with REQUIRE statement
    // bool check;
    // REQUIRE_NOTHROW(([&]{
    //  check = t.remove(i);})());
    // CHECK(check);
  }
  CHECK(!t.root);
  for (int i = 0; i < correct.size(); ++i) {
    auto val = static_cast<int>(correct.size()) / 2 +
               ((i % 2) * 2 - 1) * ((i + 1) / 2) - 1;
    auto r = t.insert(val);
    REQUIRE(r);
    REQUIRE(r->value == val);
  }
}