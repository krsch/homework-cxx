#include "deque.hpp"
#include <iostream>

int main() {
    DoubleQueue deque = DoubleQueue();
    deque.pushFirst(1);
    deque.pushFirst(4);
    deque.pushFirst(2);
    deque.pushFirst(3);
    std::cout << "Last element " << deque.popLast() << "\n";
}