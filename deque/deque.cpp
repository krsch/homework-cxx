#include "deque.hpp"

bool DoubleQueue::isEmpty() const { return (first == nullptr); };

int DoubleQueue::popFirst() {
    first = (*first).next;
    return (*first).value;
}

int DoubleQueue::popLast() { return (*last).value; }

void DoubleQueue::pushFirst(int value) {
    first = std::make_shared<ListElement>(value);
}

void DoubleQueue::pushLast(int value) {
    last = std::make_shared<ListElement>(value);
}

void DoubleQueue::clear() {
    first = nullptr;
    last = nullptr;
}
