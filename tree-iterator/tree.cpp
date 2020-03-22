#include "tree.hpp"

// Новый синтаксис объявления функций
// То же самое, что
// tree::iterator& tree::iterator::operator++()
// только меньше повторений
auto tree::iterator::operator++() -> iterator& {
    return *this;
}

auto tree::iterator::operator--() -> iterator& {
    return *this;
}

auto tree::begin() const -> iterator {
    return {root.get()};
}

auto tree::end() const -> iterator {
    return {root.get()};
}

// Можно не менять
auto tree::iterator::operator++(int) -> iterator {
    auto it = *this;
    ++*this;
    return it;
}

auto tree::iterator::operator--(int) -> iterator {
    auto it = *this;
    --*this;
    return it;
}
