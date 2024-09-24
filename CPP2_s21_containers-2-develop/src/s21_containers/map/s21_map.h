#ifndef _S21_MAP_H_
#define _S21_MAP_H_

#include "../AVLtree/AVLtree.h"

namespace s21 {
template <typename K, typename V>
class map : public AVLTree<K, V> {
 public:
  class IteratorMap;
  class ConstIteratorMap;

  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename AVLTree<K, V>::iterator;
  using const_iterator = typename AVLTree<K, V>::const_iterator;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &m_);
  map(map &&m_);
  ~map() = default;

  map &operator=(map &&m_);

  class ConstIteratorMap : public AVLTree<K, V>::ConstIteratorTree {
   public:
    friend class map;
    ConstIteratorMap() : AVLTree<K, V>::ConstIteratorTree() {}
    ConstIteratorMap(typename AVLTree<K, V>::Node *node)
        : AVLTree<K, V>::ConstIteratorTree(node) {}

    std::pair<const K, V> operator*() {
      return std::make_pair(AVLTree<K, V>::ConstIteratorTree::current_->key_,
                            AVLTree<K, V>::ConstIteratorTree::current_->value_);
    }
    typename AVLTree<K, V>::ConstIteratorTree &operator=(
        const typename AVLTree<K, V>::ConstIteratorTree &other) {
      AVLTree<K, V>::ConstIteratorTree::operator=(other);
      return *this;
    }
  };

  class IteratorMap : public ConstIteratorMap {
   public:
    IteratorMap() : ConstIteratorMap() {}
    IteratorMap(typename AVLTree<K, V>::Node *node) : ConstIteratorMap(node) {}
    std::pair<const K, V> operator*() { return ConstIteratorMap::operator*(); }
    typename AVLTree<K, V>::ConstIteratorTree &operator=(
        const typename AVLTree<K, V>::ConstIteratorTree &other) {
      ConstIteratorMap::operator=(other);
      return *this;
    }
  };

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
};
}  // namespace s21

#include "s21_map.tpp"

#endif  // _S21_MAP_H_
