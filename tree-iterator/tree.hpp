#include <memory>
#include <cassert>

struct tree_node {
  int value;
  tree_node *up = nullptr;
  std::unique_ptr<tree_node> left{}, right{};

  tree_node(int val) noexcept : value(val) {}
  tree_node(tree_node &&a, int val, tree_node &&b)
      : value(val), left(std::make_unique<tree_node>(std::move(a))),
        right(std::make_unique<tree_node>(std::move(b))) {
    left->up = right->up = this;
  }
  tree_node(tree_node &&other) noexcept
      : value(other.value), up(other.up), left(std::move(other.left)),
        right(std::move(other.right)) {
    assert(up == nullptr);
    if (left) left->up = this;
    if (right) right->up = this;
  }
  tree_node(tree_node const&) = delete;
  tree_node& operator=(tree_node const&) = delete;
  tree_node& operator=(tree_node &&) = delete;
  ~tree_node() = default;
};

struct tree {
  std::unique_ptr<tree_node> root;
  struct iterator {
    // Для того, чтобы реализовать end(), вам скорее всего понадобится ещё одно поле
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
