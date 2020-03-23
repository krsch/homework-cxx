#include "tree.hpp"

tree::iterator operator+(tree::iterator const &self, ptrdiff_t diff) {
  return self;
}

ptrdiff_t operator-(tree::iterator const &self, tree::iterator other) {
  return 0;
}

auto tree::begin() const -> iterator { return iterator{root.get()}; }

auto tree::end() const -> iterator { return iterator{root.get()}; }