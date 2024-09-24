namespace s21 {
template <class T>
deque<T>::deque() {
  size_ = 0;
  head = nullptr;
  tail = nullptr;
}

template <class T>
deque<T>::deque(std::initializer_list<T> const &items) : deque() {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <class T>
deque<T>::deque(const deque &other) : deque() {
  Node *current = other.head;  // Start from the head of the other deque
  while (current) {
    push_back(current->value);  // Copy each element
    current = current->next;    // Move to the next node
  }
}

template <class T>
deque<T>::deque(deque &&other)
    : size_(other.size_), head(other.head), tail(other.tail) {
  other.size_ = 0;
  other.head = nullptr;
  other.tail = nullptr;
}

template <class T>
deque<T>::~deque() {
  while (head) pop_front();
}

template <class T>
void deque<T>::push_back(const_reference data) {
  Node *newNode = new Node(data, nullptr, tail);

  if (tail != nullptr)
    tail->next = newNode;
  else
    head = newNode;
  tail = newNode;
  size_++;
}

template <class T>
void deque<T>::push_front(const_reference data) {
  Node *newNode = new Node(data, head, nullptr);

  if (head != nullptr)
    head->prev = newNode;
  else
    tail = newNode;
  head = newNode;
  size_++;
}

template <class T>
void deque<T>::pop_front() {
  if (!head) throw std::out_of_range("Deque is empty. Cannot pop front.");
  Node *temp = head;
  head = head->next;
  if (head)
    head->prev = nullptr;  // Убираем некорректное обращение к head->prev->prev
  else
    tail = nullptr;
  delete temp;
  size_--;
}

template <class T>
void deque<T>::pop_back() {
  if (!tail) throw std::out_of_range("Deque is empty. Cannot pop back.");
  Node *temp = tail;
  tail = tail->prev;
  if (tail)
    tail->next = nullptr;
  else
    head = nullptr;
  delete temp;
  size_--;
}

template <class T>
void deque<T>::swap(deque &other) {
  std::swap(size_, other.size_);
  std::swap(head, other.head);
  std::swap(tail, other.tail);
}

template <class T>
const T &deque<T>::front() const {
  if (empty()) throw std::out_of_range("conteiner is empty");
  return head->value;
}
template <class T>
const T &deque<T>::back() const {
  if (empty()) throw std::out_of_range("conteiner is empty");
  return tail->value;
}

template <class T>
typename deque<T>::size_type deque<T>::size() const {
  return size_;
}

template <class T>
bool deque<T>::empty() const {
  return head == nullptr;
}

template <class T>
deque<T> &deque<T>::operator=(const deque &other) {
  if (this != &other) {
    while (!empty()) {
      pop_front();
    }
    Node *cur = other.head;
    while (cur) {
      push_back(cur->value);
      cur = cur->next;
    }
  }
  return *this;
}

template <class T>
deque<T> &deque<T>::operator=(deque &&other) noexcept {
  if (this != &other) {
    while (!empty()) {
      pop_front();
    }
    size_ = other.size_;
    head = other.head;
    tail = other.tail;
    other.size_ = 0;
    other.head = nullptr;
    other.tail = nullptr;
  }
  return *this;
}

template <class T>
template <typename... Args>
void deque<T>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

}  // namespace s21