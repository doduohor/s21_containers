#ifndef _S21_TREE_H_
#define _S21_TREE_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename K, typename V>
class AVLTree {
 public:
  class IteratorTree;
  class ConstIteratorTree;

  using iterator = IteratorTree;
  using const_iterator = ConstIteratorTree;
  using size_type = std::size_t;

 protected:
  struct Node {
    K key_;
    V value_;

    Node *parent_;
    Node *right_;
    Node *left_;

    explicit Node(const K &key, const V &value)
        : key_(key),
          value_(value),
          parent_(nullptr),
          right_(nullptr),
          left_(nullptr){};

    explicit Node(const K &key, const V &value, Node *parent)
        : key_(key),
          value_(value),
          parent_(parent),
          right_(nullptr),
          left_(nullptr){};
  };

  Node *root_ = nullptr;
  size_type size_ = 0;
  size_type cnt_duplicate_ = 0;

 public:
  class ConstIteratorTree {
    friend class AVLTree<K, V>;

   public:
    ConstIteratorTree() : current_(nullptr), tree_(nullptr) {}
    ConstIteratorTree(Node *node, AVLTree<K, V> *tree)
        : current_(node), tree_(tree) {}

    bool operator==(const ConstIteratorTree &other) const {
      return this->current_ == other.current_;
    }

    bool operator!=(const ConstIteratorTree &other) const {
      return this->current_ != other.current_;
    }

    V operator*() const { return current_->value_; }

    ConstIteratorTree &operator++() {
      if (current_->right_) {
        current_ = current_->right_;
        current_ = tree_->min(current_);
      } else {
        while (current_->parent_ && current_ == current_->parent_->right_) {
          current_ = current_->parent_;
        }
        current_ = current_->parent_;
      }
      return *this;
    }

    ConstIteratorTree operator++(int) {
      ConstIteratorTree temp = *this;
      ++(*this);  // Используем префиксную версию оператора инкремента
      return temp;
    }

    ConstIteratorTree &operator--() {
      if (current_ == nullptr) {
        current_ = tree_->max(tree_->root_);
      } else if (current_->left_) {
        current_ = current_->left_;
        current_ = tree_->max(current_);
      } else {
        while (current_->parent_ && current_ == current_->parent_->left_) {
          current_ = current_->parent_;
        }
        current_ = current_->parent_;
      }
      return *this;
    }

    ConstIteratorTree operator--(int) {
      ConstIteratorTree temp = *this;
      --(*this);  // Используем префиксную версию оператора декремента
      return temp;
    }

   protected:
    Node *current_ = nullptr;
    s21::AVLTree<K, V> *tree_ = nullptr;
  };

  class IteratorTree : public ConstIteratorTree {
   public:
    IteratorTree() : ConstIteratorTree() {}
    IteratorTree(Node *node, AVLTree<K, V> *tree)
        : ConstIteratorTree(node, tree) {}

    IteratorTree &operator++() {
      ConstIteratorTree::operator++();
      return *this;
    }

    IteratorTree operator++(int) {
      IteratorTree temp = *this;
      ++(*this);  // Используем префиксную версию оператора инкремента
      return temp;
    }

    IteratorTree &operator--() {
      ConstIteratorTree::operator--();
      return *this;
    }

    IteratorTree operator--(int) {
      IteratorTree temp = *this;
      --(*this);  // Используем префиксную версию оператора декремента
      return temp;
    }

    bool operator==(const IteratorTree &other) const {
      return this->current_ == other.current_;
    }

    bool operator!=(const IteratorTree &other) const {
      return this->current_ != other.current_;
    }
  };

  AVLTree() { root_ = nullptr; }

  AVLTree(std::initializer_list<std::pair<K, V>> const &items) {
    for (const auto &item : items) {
      insert(item.first, item.second);
    }
  }

  AVLTree(const AVLTree &t) {
    size_ = t.size_;
    cnt_duplicate_ = t.cnt_duplicate_;
    root_ = copy_tree(t.root_, nullptr);
  }

  AVLTree(AVLTree &&t) { *this = std::move(t); }

  AVLTree &operator=(AVLTree &&t) {
    if (this != &t) {
      clear(&this->root_);
      root_ = t.root_;
      size_ = t.size_;
      cnt_duplicate_ = t.cnt_duplicate_;
      t.root_ = nullptr;
      t.size_ = 0;
      t.cnt_duplicate_ = 0;
    }
    return *this;
  }

  ~AVLTree() { clear(); }

  iterator begin() {
    Node *current = root_;
    if (current == nullptr) {
      return iterator(nullptr, this);
    }
    return iterator(min(current), this);
  }

  iterator end() { return iterator(nullptr, this); }

  iterator find(const K &key) { return iterator(find_key(key), this); }

  void add_node(K key, V value) {
    if (find_bool(key))  // Проверка ключа, а не значения
      return;

    Node *cell = new Node(key, value);
    Node *current = root_;
    if (root_ == nullptr) {
      root_ = cell;
      current = cell;
    } else {
      while (true) {
        if (cell->key_ > current->key_) {
          if (current->right_ != nullptr) {
            current = current->right_;
          } else {
            break;
          }
        } else if (cell->key_ < current->key_) {
          if (current->left_ != nullptr) {
            current = current->left_;
          } else {
            break;
          }
        }
      }
      if (cell->key_ > current->key_) {
        current->right_ = cell;
        cell->parent_ = current;
        current = cell;
      } else if (cell->key_ < current->key_) {
        current->left_ = cell;
        cell->parent_ = current;
        current = cell;
      }
    }
    size_++;
  }

  void remove(V value) {
    Node *current = find_value(value);
    if (current == nullptr) return;
    Node *tmp = current;
    int flag = 0;
    if (current->left_ != nullptr && current->right_ != nullptr) {
      tmp = current->right_;
      if (tmp->left_ == nullptr) {
        change_link(current, tmp, flag);
      } else {
        tmp = min(tmp);
        current->value_ = tmp->value_;
        tmp->parent_->left_ = nullptr;
      }
    } else if (current->left_ != nullptr && current->right_ == nullptr) {
      flag = 1;
      tmp = current->left_;
      change_link(current, tmp, flag);
    } else if (current->left_ == nullptr && current->right_ != nullptr) {
      tmp = current->right_;
      change_link(current, tmp, flag);
    } else if (current->left_ == nullptr && current->right_ == nullptr) {
      if (tmp->parent_->left_ == nullptr)
        tmp->parent_->right_ = nullptr;
      else if (tmp->parent_->right_ == nullptr)
        tmp->parent_->left_ = nullptr;
      else if (tmp == tmp->parent_->left_)
        tmp->parent_->left_ = nullptr;
      else if (tmp == tmp->parent_->right_)
        tmp->parent_->right_ = nullptr;
    }
    delete tmp;
    size_--;
  }

  void clear() {
    if (root_ != nullptr) clear(&root_);
    size_ = 0;
    cnt_duplicate_ = 0;
    root_ = nullptr;
  }

  size_type size() { return size_; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(size_type) / 10;
  }

  bool empty() { return root_ == nullptr ? true : false; }

  void erase(iterator pos) { remove(*pos); }

  void swap(AVLTree &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
    std::swap(cnt_duplicate_, other.cnt_duplicate_);
  }

  void merge(AVLTree &other) {
    auto i2 = other.end();
    for (auto i = other.begin(); i != i2; ++i) {
      if (!find_bool(*i)) {
        add_node(*i, *i);
      }
    }
    clear(&other.root_);
  }

  bool contains(const K &key) { return find_bool(key); }

  std::pair<iterator, bool> insert(const V &value) {
    if (find_bool(K(value))) {
      return std::make_pair(find(K(value)), false);
    } else {
      add_node(K(value), value);
      return std::make_pair(find(K(value)), true);
    }
  }

  std::pair<iterator, bool> insert(const K &key, const V &value) {
    if (find_bool(key)) {
      return std::make_pair(find(key), false);
    } else {
      return insert_or_assign(key, value);
    }
  }

  std::pair<iterator, bool> insert_or_assign(const K &key, const V &value) {
    if (!find_bool(key)) {
      add_node(key, value);
      return std::make_pair(find(key), true);
    } else {
      Node *current = find_key(key);
      current->value_ = value;
      return std::make_pair(find(key), false);
    }
  }

  Node *min(Node *node) {
    while (node->left_ != nullptr) {
      node = node->left_;
    }
    return node;
  }

  Node *max(Node *node) {
    while (node->right_ != nullptr) {
      node = node->right_;
    }
    return node;
  }

  size_type count(const K &key) {
    if (find_bool(key))
      return (cnt_duplicate_);
    else
      return 0;
  }

  iterator lower_bound(const K &key) {
    Node *current = root_;
    Node *result = nullptr;

    while (current != nullptr) {
      if (current->key_ < key) {
        current = current->right_;
      } else {
        result = current;
        current = current->left_;
      }
    }
    return iterator(result, this);
  }

  iterator upper_bound(const K &key) {
    Node *current = root_;
    Node *result = nullptr;

    while (current != nullptr) {
      if (current->key_ <= key) {
        current = current->right_;
      } else {
        result = current;
        current = current->left_;
      }
    }
    return iterator(result, this);
  }

  std::pair<iterator, iterator> equal_range(const K &key) {
    return {lower_bound(key), upper_bound(key)};
  }

  V &at(const K &key) {
    if (find_bool(key)) {
      Node *current = find_key(key);
      return current->value_;
    } else
      throw std::out_of_range("K not found");
  }

  V &operator[](const K &key) {
    if (find_bool(key)) {
      Node *current = find_key(key);
      return current->value_;
    } else {
      add_node(key, V());
      Node *current = find_key(key);
      return current->value_;
    }
  }

 protected:
  void merge_mst(AVLTree &other) {
    if (this == &other) return;

    for (auto it = other.begin(); it != other.end(); ++it) {
      add_mst(*it, *it);
    }
    other.clear();
  }

  void add_mst(K key, V value) {
    Node *current = root_;
    Node *parent = nullptr;

    while (current != nullptr) {
      parent = current;
      if (key > current->key_) {
        current = current->right_;
      } else if (key < current->key_) {
        current = current->left_;
      } else {
        Node *cell = new Node(key, value);
        while (current->right_ != nullptr) {
          current = current->right_;
        }
        current->right_ = cell;
        cell->parent_ = current;
        size_++;
        cnt_duplicate_++;
        return;
      }
    }

    Node *cell = new Node(key, value, parent);
    if (parent == nullptr) {
      root_ = cell;
    } else if (key < parent->key_) {
      parent->left_ = cell;
    } else {
      parent->right_ = cell;
    }
    size_++;
  }

 private:
  Node *copy_tree(Node *node, Node *parent) {
    if (node == nullptr) return nullptr;
    Node *new_node = new Node(node->key_, node->value_, parent);
    new_node->left_ = copy_tree(node->left_, new_node);
    new_node->right_ = copy_tree(node->right_, new_node);
    return new_node;
  }

  AVLTree create_tmp_tree() { return AVLTree(*this); }

  void change_link(Node *current, Node *tmp, int flag) {
    current->value_ = tmp->value_;
    current->key_ = tmp->key_;
    if (flag) {
      current->left_ = tmp->left_;
    } else {
      current->right_ = tmp->right_;
    }
    tmp->parent_ = current;
  }

  bool find_bool(K key) {
    Node *current = root_;
    while (current != nullptr) {
      if (key > current->key_) {
        current = current->right_;
      } else if (key < current->key_) {
        current = current->left_;
      } else {
        return true;
      }
    }
    return false;
  }

  Node *find_value(V value) {
    Node *current = root_;
    while (current != nullptr) {
      if (value > current->value_) {
        current = current->right_;
      } else if (value < current->value_) {
        current = current->left_;
      } else if (value == current->value_) {
        return current;
      }
    }
    return nullptr;
  }

  Node *find_key(K key) {
    Node *current = root_;
    while (current != nullptr) {
      if (key > current->key_) {
        current = current->right_;
      } else if (key < current->key_) {
        current = current->left_;
      } else if (key == current->key_) {
        return current;
      }
    }
    return nullptr;
  }

  void clear(Node **node) {
    if (*node != nullptr) {
      clear(&((*node)->left_));
      clear(&(*node)->right_);
      delete *node;
      *node = nullptr;
    }
  }
};
}  // namespace s21

#endif  // _S21_TREE_H_