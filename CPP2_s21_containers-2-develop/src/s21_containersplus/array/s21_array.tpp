namespace s21 {
template <typename value_type, std::size_t N>
array<value_type, N>::array() {
  for (size_type i = 0; i < N; i++) elements[i] = value_type();
}

template <typename value_type, std::size_t N>
array<value_type, N>::array(std::initializer_list<value_type> const& items)
    : array() {
  size_type i = 0;
  for (const auto& item : items) {
    if (i < N)
      elements[i++] = item;
    else
      throw std::out_of_range("Initializer list exceeds array size");
  }
  for (; i < N; ++i) elements[i] = value_type();
}

template <typename value_type, std::size_t N>
array<value_type, N>::array(const array& a) {
  for (size_type i = 0; i < N; i++) {
    elements[i] = a.elements[i];
  }
}

template <typename value_type, std::size_t N>
array<value_type, N>::array(array&& a) noexcept {
  for (size_type i = 0; i < N; i++) elements[i] = std::move(a.elements[i]);
}

template <typename value_type, std::size_t N>
array<value_type, N>::~array() {}

template <typename value_type, std::size_t N>
value_type& array<value_type, N>::at(std::size_t pos) {
  if (pos >= N) throw std::out_of_range("out of Index array");
  return elements[pos];
}

template <typename value_type, std::size_t N>
const value_type& array<value_type, N>::at(std::size_t pos) const {
  if (pos >= N) throw std::out_of_range("out of Index array");
  return elements[pos];
}

template <typename value_type, std::size_t N>
value_type& array<value_type, N>::operator[](size_type pos) {
  return this->elements[pos];
}
template <typename value_type, std::size_t N>
const value_type& array<value_type, N>::operator[](size_type pos) const {
  return this->elements[pos];
}

template <typename value_type, std::size_t N>
const value_type& array<value_type, N>::front() const {
  return elements[0];
}

template <typename value_type, std::size_t N>
const value_type& array<value_type, N>::back() const {
  return elements[N - 1];
}

template <typename value_type, std::size_t N>
array<value_type, N>& array<value_type, N>::operator=(array&& a) noexcept {
  if (this != &a) {
    for (size_type i = 0; i < N; i++) elements[i] = std::move(a.elements[i]);
  }
  return *this;
}

template <typename value_type, std::size_t N>
const array<value_type, N>& array<value_type, N>::operator=(const array& a) {
  if (this != &a) {
    std::copy(a.elements, a.elements + N, elements);
  }
  return *this;
}

template <typename value_type, std::size_t N>
value_type* array<value_type, N>::data() {
  return elements;
}

template <typename value_type, std::size_t N>
const value_type* array<value_type, N>::data() const {
  return elements;
}

template <typename value_type, std::size_t N>
value_type* array<value_type, N>::begin() {
  return elements;
}

template <typename value_type, std::size_t N>
const value_type* array<value_type, N>::begin() const {
  return elements;
}

template <typename value_type, std::size_t N>
const value_type* array<value_type, N>::end() const {
  return elements + N;
}

template <typename value_type, std::size_t N>
value_type* array<value_type, N>::end() {
  return elements + N;
}

template <typename value_type, std::size_t N>
bool array<value_type, N>::empty() const {
  return N == 0;
}

template <typename value_type, std::size_t N>
std::size_t array<value_type, N>::size() const {
  return N;
}

template <typename value_type, std::size_t N>
std::size_t array<value_type, N>::max_size() const {
  return N;
}

template <typename value_type, std::size_t N>
void array<value_type, N>::swap(array& other) {
  std::swap(elements, other.elements);
}

template <typename value_type, std::size_t N>
void array<value_type, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; i++) elements[i] = value;
}

}  // namespace s21