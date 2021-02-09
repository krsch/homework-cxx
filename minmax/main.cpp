#include "minmax.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <deque>

struct ListElement {
    int value;
    std::shared_ptr<ListElement> next;
    std::weak_ptr<ListElement> prev;
    ListElement(int v) : value(v) {}
};

struct DoubleQueue {
    std::shared_ptr<ListElement> first;
    std::shared_ptr<ListElement> last;

    DoubleQueue() {};

    bool isEmpty() const {
        return (first==nullptr);
    }

    int popFirst() {
        first = (*first).next;
        return (*first).value;
    }

    int popLast() {
        return (*last).value;
    }

    void pushFirst(int value) {
        first = std::make_shared<ListElement>(value);
    }

    void pushLast(int value) {
        last = std::make_shared<ListElement>(value);
    }

    void clear() {
        first = nullptr;
        last = nullptr;
    }
};


int main() {
    std::deque<int> d = {7, 5, 16, 8};

    std::string s;
    std::getline(std::cin, s);
    std::istringstream ss(s);

    std::vector<int> input;
    int i;
    while (ss >> i)
        input.emplace_back(i);
    auto [min, max] = minmax(input);
    std::cout << min << ", " << max << "\n";
}