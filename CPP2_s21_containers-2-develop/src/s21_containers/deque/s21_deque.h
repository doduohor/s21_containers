#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_DEQUE_DEQUE_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_DEQUE_DEQUE_H_

#include <iostream>

namespace s21 {

template <class T>
class deque {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  deque();
  ~deque();
  deque(std::initializer_list<value_type> const &items);
  deque(const deque &other);
  deque(deque &&other);

  void push_front(const_reference data);
  void pop_front();
  void push_back(const_reference data);
  void pop_back();

  const_reference front() const;
  const_reference back() const;

  bool empty() const;
  size_type size() const;

  void swap(deque &other);

  void clear();

  deque &operator=(const deque &other);
  deque &operator=(deque &&other) noexcept;

  template <typename... Args>
  void insert_many_back(Args &&...args);

 protected:
  struct Node {
    T value;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(T val = T(), Node *next_node = nullptr, Node *prev_node = nullptr)
        : value(val), next(next_node), prev(prev_node) {}
  };
  size_t size_ = 0;
  Node *head = nullptr;
  Node *tail = nullptr;
};
}  // namespace s21

#include "s21_deque.tpp"
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_DEQUE_DEQUE_H_