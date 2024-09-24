#ifndef CPP2_S21_CONTAINERS_LIST_H
#define CPP2_S21_CONTAINERS_LIST_H

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <utility>

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  struct Node {
    Node *prev;
    Node *next;
    value_type data_;
    Node(value_type data = value_type())
        : prev(nullptr), next(nullptr), data_(data) {}
  };

  template <bool Const>
  class listIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = std::conditional_t<Const, std::add_const_t<T>, T>;
    using node_pointer = std::conditional_t<Const, Node const *, Node *>;
    using difference_type = std::ptrdiff_t;
    using pointer = std::conditional_t<Const, const T *, T *>;
    using reference = std::conditional_t<Const, const T &, T &>;

    listIterator() : node_(nullptr) {}
    explicit listIterator(node_pointer node) : node_(node) {}

    template <bool OtherConst>
    constexpr listIterator(const listIterator<OtherConst> &other) noexcept
        : node_(const_cast<node_pointer>(other.node_)) {}

    reference operator*() const { return node_->data_; }
    pointer operator->() const { return &(node_->data_); }

    listIterator &operator++() {
      node_ = node_->next;
      return *this;
    }

    listIterator operator++(int) {
      listIterator temp = *this;
      node_ = node_->next;
      return temp;
    }

    listIterator &operator--() {
      node_ = node_->prev;
      return *this;
    }

    listIterator operator--(int) {
      listIterator temp = *this;
      node_ = node_->prev;
      return temp;
    }

    bool operator==(const listIterator &other) const {
      return node_ == other.node_;
    }
    bool operator!=(const listIterator &other) const {
      return node_ != other.node_;
    }

    node_pointer get_node() const { return node_; }

   private:
    template <bool OtherConst>
    friend class listIterator;

    node_pointer node_;
  };

  using iterator = listIterator<false>;
  using const_iterator = listIterator<true>;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l) noexcept;
  ~list();
  list &operator=(list &&l) noexcept;

  const_reference front() const;
  const_reference back() const;

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other) noexcept;
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse() noexcept;
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);
  template <class... Args>
  void insert_many_front(Args &&...args);

 protected:
  Node *head_;
  size_type size_;

  Node *merge_sort(Node *head);
  Node *merge_sorted(Node *left, Node *right);
};

template <class value_type>
list<value_type>::list() : size_(0U) {
  Node *ptr = new Node(value_type());
  head_ = ptr;
  head_->next = ptr;
  head_->prev = ptr;
}

template <typename value_type>
list<value_type>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (const auto &it : items) {
    push_back(it);
  }
}

template <typename value_type>
list<value_type>::list(const list &l) : list() {
  if (l.head_ != nullptr) {
    Node *current = l.head_->next;
    Node *last = head_;
    while (current != l.head_) {
      Node *new_node = new Node(current->data_);
      last->next = new_node;
      new_node->prev = last;
      last = new_node;
      current = current->next;
      ++size_;
    }
    last->next = head_;
    head_->prev = last;
  }
}

template <typename value_type>
list<value_type>::list(list &&l) noexcept : head_(l.head_), size_(l.size_) {
  l.head_ = new Node();
  l.head_->next = l.head_;
  l.head_->prev = l.head_;
  l.size_ = 0;
}

template <typename value_type>
list<value_type>::~list() {
  clear();
  delete head_;
}

template <typename value_type>
list<value_type> &list<value_type>::operator=(list &&v) noexcept {
  if (this != &v) {
    clear();
    head_ = v.head_;
    size_ = v.size_;
    v.head_ = nullptr;
    v.size_ = 0;
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() const {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  return head_->next->data_;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() const {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  return head_->prev->data_;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() noexcept {
  return iterator(head_->next);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() noexcept {
  return iterator(head_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin()
    const noexcept {
  return const_iterator(head_->next);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend()
    const noexcept {
  return const_iterator(head_);
}

template <typename value_type>
bool list<value_type>::empty() const noexcept {
  return size_ == 0;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() const noexcept {
  return size_;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size()
    const noexcept {
  return std::allocator<Node>().max_size();
}

template <typename value_type>
void list<value_type>::clear() noexcept {
  while (size_ > 0) {
    pop_front();
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node *new_node = new Node(value);
  Node *next_node = pos.get_node();
  new_node->prev = next_node->prev;
  new_node->next = next_node;
  next_node->prev->next = new_node;
  next_node->prev = new_node;
  ++size_;
  return iterator(new_node);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos == end()) {
    throw std::invalid_argument("Cannot erase end iterator.");
  }

  Node *to_erase = pos.get_node();
  to_erase->prev->next = to_erase->next;
  to_erase->next->prev = to_erase->prev;
  delete to_erase;
  --size_;
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename value_type>
void list<value_type>::pop_back() {
  erase(--end());
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename value_type>
void list<value_type>::pop_front() {
  erase(begin());
}

template <typename value_type>
void list<value_type>::swap(list &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

template <typename value_type>
void list<value_type>::merge(list &other) {
  if (this != &other) {
    iterator this_iter = begin();
    iterator other_iter = other.begin();
    while (!other.empty()) {
      if (this->empty() || this_iter == end() || *this_iter > *other_iter) {
        insert(this_iter, *other_iter);
        other.erase(other_iter++);
      } else {
        ++this_iter;
      }
    }
  }
}

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list &other) {
  if (other.empty()) return;

  Node *previous = pos.get_node()->prev;
  Node *current = const_cast<Node *>(pos.get_node());
  Node *other_first = other.begin().get_node();
  Node *other_last = (--other.end()).get_node();

  current->prev = other_last;
  other_last->next = current;
  previous->next = other_first;
  other_first->prev = previous;

  other.head_->next = other.head_;
  other.head_->prev = other.head_;
  size_ += other.size_;
  other.size_ = 0;
}

template <typename value_type>
void list<value_type>::reverse() noexcept {
  Node *current = head_;
  do {
    std::swap(current->next, current->prev);
    current = current->prev;
  } while (current != head_);
}

template <typename value_type>
void list<value_type>::unique() {
  if (size_ > 1) {
    iterator current = begin();
    iterator next = current;
    ++next;
    while (next != end()) {
      if (*current == *next) {
        erase(next);
        next = current;
        ++next;
      } else {
        current = next;
        ++next;
      }
    }
  }
}

template <class value_type>
template <class... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  iterator index = pos;
  iterator first_inserted = index;
  bool is_first = true;

  ((index = insert(index, std::forward<Args>(args)),
    is_first ? first_inserted = index : index, is_first = false, ++index),
   ...);

  return first_inserted;
}

template <class value_type>
template <class... Args>
void list<value_type>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

template <class value_type>
template <class... Args>
void list<value_type>::insert_many_front(Args &&...args) {
  list<value_type> tmp{std::forward<Args>(args)...};
  tmp.reverse();
  for (const auto &item : tmp) {
    push_front(item);
  }
}

template <typename value_type>
void list<value_type>::sort() {
  if (size_ > 1) {
    Node *first_node = head_->next;
    Node *last_node = (--end()).get_node();
    Node *head = head_;

    first_node->prev = nullptr;
    last_node->next = nullptr;

    first_node = merge_sort(first_node);
    first_node->prev = head;
    head_->next = first_node;

    Node *temp = head_;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = head_;
    head_->prev = temp;
  }
}

template <typename value_type>
typename list<value_type>::Node *list<value_type>::merge_sort(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *slow = head;
  Node *fast = head->next;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *second_half = slow->next;
  slow->next = nullptr;
  Node *left = merge_sort(head);
  Node *right = merge_sort(second_half);
  return merge_sorted(left, right);
}

template <typename value_type>
typename list<value_type>::Node *list<value_type>::merge_sorted(Node *left,
                                                                Node *right) {
  if (left == nullptr) {
    return right;
  }
  if (right == nullptr) {
    return left;
  }
  Node *result = nullptr;
  if (left->data_ <= right->data_) {
    result = left;
    result->next = merge_sorted(left->next, right);
    if (result->next) {
      result->next->prev = result;
    }
  } else {
    result = right;
    result->next = merge_sorted(left, right->next);
    if (result->next) {
      result->next->prev = result;
    }
  }
  return result;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_LIST_H
