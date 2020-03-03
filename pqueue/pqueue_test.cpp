#include "pqueue.hpp"
#include "catch.hpp"

TEST_CASE("simple tests") {
    pqueue queue;
    auto i3 = queue.insert(3, "third");
    auto i1 = queue.insert(1, "first");
    auto i2 = queue.insert(2, "second");
    REQUIRE(queue.size() == 3);
    CHECK(queue.get(i1) == "first");
    CHECK(queue.get(i2) == "second");
    CHECK(queue.get(i3) == "third");
    CHECK(queue.get_priority(i1) == 1);
    CHECK(queue.get_priority(i2) == 2);
    CHECK(queue.get_priority(i3) == 3);
    queue.erase(i1);
    REQUIRE(queue.size() == 2);
    CHECK(queue.get(i2) == "second");
    CHECK(queue.get(i3) == "third");
    CHECK(queue.get_priority(i2) == 2);
    CHECK(queue.get_priority(i3) == 3);
    queue.erase(i2);
    REQUIRE(queue.size() == 1);
    CHECK(queue.get(i3) == "third");
    CHECK(queue.get_priority(i3) == 3);
}

TEST_CASE("update_priority tests") {
    pqueue queue;
    auto i3 = queue.insert(3, "third");
    auto i1 = queue.insert(1, "first");
    auto i2 = queue.insert(2, "second");
    queue.update_priority(i1, 4);
    CHECK(queue.get(i1) == "first");
    CHECK(queue.get(i2) == "second");
    CHECK(queue.get(i3) == "third");
    CHECK(queue.get_priority(i1) == 4);
    CHECK(queue.get_priority(i2) == 2);
    CHECK(queue.get_priority(i3) == 3);
    REQUIRE(queue.size() == 3);
    queue.update_priority(i1, 1);
    CHECK(queue.get(i1) == "first");
    CHECK(queue.get(i2) == "second");
    CHECK(queue.get(i3) == "third");
    CHECK(queue.get_priority(i1) == 1);
    CHECK(queue.get_priority(i2) == 2);
    CHECK(queue.get_priority(i3) == 3);
    REQUIRE(queue.size() == 3);
}

TEST_CASE("extract_min tests") {
    pqueue queue;
    queue.insert(3, "third");
    auto i1 = queue.insert(1, "first");
    auto i2 = queue.insert(2, "second");
    queue.update_priority(i1, 4);
    CHECK(queue.extract_min() == "second");
    CHECK(queue.extract_min() == "third");
    i2 = queue.insert(7, "two again");
    queue.insert(5, "last");
    queue.update_priority(i2, 2);
    CHECK(queue.extract_min() == "two again");
    CHECK(queue.extract_min() == "first");
    CHECK(queue.extract_min() == "last");
    REQUIRE(queue.size() == 0);
}


TEST_CASE("extract_min tests 2") {
    pqueue queue;
    auto i3 = queue.insert(3, "third");
    auto i1 = queue.insert(1, "first");
    queue.insert(2, "second");
    queue.insert(4, "4");
    queue.insert(5, "5");
    queue.insert(6, "6");
    queue.erase(i1);
    CHECK(queue.extract_min() == "second");
    queue.erase(i3);
    CHECK(queue.extract_min() == "4");
    CHECK(queue.extract_min() == "5");
    REQUIRE(queue.size() == 1);
}
