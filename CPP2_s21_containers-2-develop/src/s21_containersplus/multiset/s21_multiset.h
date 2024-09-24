#ifndef _S21_MULTISET_H_
#define _S21_MULTISET_H_

#include "../../s21_containers/AVLtree/AVLtree.h"

namespace s21 {
template <typename K>
class multiset : public AVLTree<K, K> {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename AVLTree<K, K>::iterator;
  using const_iterator = typename AVLTree<K, K>::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &mst_);
  multiset(multiset &&mst_);
  ~multiset() = default;

  multiset &operator=(multiset &&mst_);

  void merge(multiset &other);

  std::pair<iterator, bool> insert(const K &value);
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
};
}  // namespace s21

#include "s21_multiset.tpp"

#endif  // _S21_MULTISET_H_