#ifndef CPP2_S21_CONTAINERS_ARRAY_H
#define CPP2_S21_CONTAINERS_ARRAY_H

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array();

  array &operator=(array &&a) noexcept;
  const array &operator=(const array &a);

  const_reference at(size_type pos) const;
  const_reference operator[](size_type pos) const;
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  const_iterator data() const;
  iterator data();

  iterator begin();
  const_iterator begin() const;
  const_iterator end() const;
  iterator end();

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void swap(array &other);
  void fill(const_reference value);

 private:
  T elements[N];
};
}  // namespace s21
#include "s21_array.tpp"
#endif