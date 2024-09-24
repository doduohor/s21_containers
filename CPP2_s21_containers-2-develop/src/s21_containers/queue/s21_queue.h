#ifndef CPP_S21_QUEUE_H
#define CPP_S21_QUEUE_H

#include <iostream>

#include "../deque/s21_deque.h"

namespace s21 {
template <class T, class Container = s21::deque<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue();
  queue(std::initializer_list<T> const &items);
  queue(const queue &other);
  queue(queue &&other) noexcept;
  ~queue();

  void push(const_reference value);
  void pop();

  const_reference front() const;
  const_reference back() const;

  size_type size() const;

  bool empty() const;
  void swap(queue &other);

  queue &operator=(queue &&other) noexcept;

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  Container deque_;
};
}  // namespace s21
#include "s21_queue.tpp"
#endif

std::initializer_list<int> as_s;