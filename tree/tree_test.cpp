#include "tree.hpp"
/* #define CATCH_CONFIG_MAIN */
#include "catch.hpp"
#include <numeric>

void check_tree(tree_node const& t) {
    if (t.left) {
        CHECK(t.left->value < t.value);
        check_tree(*t.left);
    }
    if (t.right) {
        CHECK(t.right->value > t.value);
        check_tree(*t.right);
    }
}

void tree_to_vector(tree_node const& t, std::vector<int> & res) {
    if (t.left) tree_to_vector(*t.left, res);
    res.push_back(t.value);
    if (t.right) tree_to_vector(*t.right, res);
}

std::vector<int> tree_to_vector(tree const& t) {
    std::vector<int> result;
    if (t.root)
        tree_to_vector(*t.root, result);
    return result;
}

TEST_CASE("Can insert many values") {
    tree t;
    for (int i=0; i<17; ++i)
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
    REQUIRE(t.root);
    check_tree(*t.root);
    REQUIRE(tree_to_vector(t) == std::vector{1,2,4});
}

TEST_CASE("correct return values") {
    tree t;
    auto r = t.insert(3);
    REQUIRE(r);
    REQUIRE(r->value == 3);
    r = t.insert(3);
    REQUIRE(r);
    REQUIRE(r->value == 3);
    REQUIRE(t.remove(3));
    REQUIRE(!t.remove(3));
}
