#include <memory>

struct tree_node {
  int value;
  tree_node *up = nullptr;
  std::unique_ptr<tree_node> left{}, right{};
  int subtree_size = 1; // нужно будет для задания №2

  tree_node(int val) : value(val) {}
  tree_node(tree_node &&a, int val, tree_node &&b)
      : value(val), left(std::make_unique<tree_node>(std::move(a))),
        right(std::make_unique<tree_node>(std::move(b))),
        subtree_size(1 + left->subtree_size + right->subtree_size) {
    left->up = right->up = this;
  }
};

struct tree {
  std::unique_ptr<tree_node> root;
  struct iterator {
    tree_node *p;
    iterator operator++(int); // post-increment
    iterator operator--(int); // post-decrement
    int const &operator*() const { return p->value; }
    int const *operator->() const { return &p->value; }
    bool operator==(iterator const &other) const { return p == other.p; }
    bool operator!=(iterator const &other) const { return p != other.p; }
    // Это всё нужно реализовать
    iterator& operator++(); // pre-increment
    iterator& operator--(); // pre-decrement

    // Начиная с C++20 следующие 5 строк генерируются автоматически
    using difference_type = ptrdiff_t;
    using value_type = int;
    using pointer = int const *;
    using reference = int const &;
    using iterator_category = std::bidirectional_iterator_tag;
  };

  explicit tree(tree_node &&a)
      : root(std::make_unique<tree_node>(std::move(a))) {
    root->up = nullptr;
  }
  // И эти две функции тоже
  iterator begin() const;
  iterator end() const;
};
