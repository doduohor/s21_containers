
namespace s21 {
template <class value_type, class Container>
queue<value_type, Container>::queue() : deque_() {}

template <class value_type, class Container>
queue<value_type, Container>::queue(
    std::initializer_list<value_type> const &items)
    : deque_() {
  for (const auto &item : items) push(item);
}

template <class value_type, class Container>
queue<value_type, Container>::queue(const queue &other)
    : deque_(other.deque_) {}

template <class value_type, class Container>
queue<value_type, Container>::queue(queue &&other) noexcept
    : deque_(std::move(other.deque_)) {}

template <class value_type, class Container>
queue<value_type, Container>::~queue() {}

template <class value_type, class Container>
queue<value_type, Container> &queue<value_type, Container>::operator=(
    queue &&other) noexcept {
  if (this != &other) deque_ = std::move(other.deque_);
  return *this;
}

template <class value_type, class Container>
const value_type &queue<value_type, Container>::front() const {
  return deque_.front();
}
template <class value_type, class Container>
const value_type &queue<value_type, Container>::back() const {
  return deque_.back();
}

template <class value_type, class Container>
bool queue<value_type, Container>::empty() const {
  return deque_.empty();
}

template <class value_type, class Container>
typename queue<value_type, Container>::size_type
queue<value_type, Container>::size() const {
  return deque_.size();
}

template <class value_type, class Container>
void queue<value_type, Container>::push(const_reference value) {
  deque_.push_back(value);
}

template <class value_type, class Container>
void queue<value_type, Container>::pop() {
  if (!deque_.empty()) {
    deque_.pop_front();
  }
}

template <class value_type, class Container>
void queue<value_type, Container>::swap(queue &other) {
  std::swap(deque_, other.deque_);
}

template <class value_type, class Container>
template <typename... Args>
void queue<value_type, Container>::insert_many_back(Args &&...args) {
  (push(std::forward<Args>(args)), ...);
}

}  // namespace s21