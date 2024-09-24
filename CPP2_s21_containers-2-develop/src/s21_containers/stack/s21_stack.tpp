namespace s21 {
template <class value_type, class Container>
stack<value_type, Container>::stack() : deque_() {}

template <class value_type, class Container>
stack<value_type, Container>::stack(
    std::initializer_list<value_type> const &items)
    : deque_() {
  for (const auto &item : items) push(item);
}

template <class value_type, class Container>
stack<value_type, Container>::stack(const stack &other)
    : deque_(other.deque_) {}

template <class value_type, class Container>
stack<value_type, Container>::stack(stack &&other) noexcept
    : deque_(std::move(other.deque_)) {}

template <class value_type, class Container>
stack<value_type, Container>::~stack() {}

template <class value_type, class Container>
stack<value_type, Container> &stack<value_type, Container>::operator=(
    stack &&other) noexcept {
  if (this != &other) deque_ = std::move(other.deque_);
  return *this;
}

template <class value_type, class Container>
typename stack<value_type, Container>::const_reference
stack<value_type, Container>::top() const {
  if (empty()) throw std::out_of_range("conteiner is empty");
  return deque_.back();
}

template <class value_type, class Container>
bool stack<value_type, Container>::empty() const {
  return deque_.empty();
}

template <class value_type, class Container>
typename stack<value_type, Container>::size_type
stack<value_type, Container>::size() const {
  return deque_.size();
}

template <class value_type, class Container>
void stack<value_type, Container>::push(const_reference value) {
  deque_.push_back(value);
}

template <class value_type, class Container>
void stack<value_type, Container>::pop() {
  if (!deque_.empty()) {
    deque_.pop_back();
  }
}

template <class value_type, class Container>
void stack<value_type, Container>::swap(stack &other) {
  std::swap(deque_, other.deque_);
}

template <class value_type, class Container>
template <typename... Args>
void stack<value_type, Container>::insert_many_back(Args &&...args) {
  (push(std::forward<Args>(args)), ...);
}

}  // namespace s21
