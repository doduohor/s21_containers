#ifndef _S21_SET_H_
#define _S21_SET_H_

#include "../AVLtree/AVLtree.h"

namespace s21 {
template <typename K>
class set : public AVLTree<K, K> {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename AVLTree<K, K>::iterator;
  using const_iterator = typename AVLTree<K, K>::const_iterator;
  using size_type = size_t;

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &st_);
  set(set &&st_);
  ~set() = default;

  set &operator=(set &&st_);
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
};
}  // namespace s21

#include "s21_set.tpp"

#endif  // _S21_SET_H_