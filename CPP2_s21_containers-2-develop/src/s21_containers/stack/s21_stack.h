#ifndef CPP2_S21_CONTAINERS_STACK_H
#define CPP2_S21_CONTAINERS_STACK_H

#include <initializer_list>
#include <iostream>
#include <utility>

#include "../deque/s21_deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  stack(std::initializer_list<T> const &items);
  stack(const stack &other);
  stack(stack &&other) noexcept;
  ~stack();

  stack &operator=(stack &&other) noexcept;

  const_reference top() const;
  size_type size() const;

  bool empty() const;
  void swap(stack &other);

  void push(const_reference value);
  void pop();

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  Container deque_;
};

}  // namespace s21

#include "s21_stack.tpp"

#endif