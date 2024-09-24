#ifndef CPP2_S21_CONTAINERS_VECTOR_ITERATOR_H
#define CPP2_S21_CONTAINERS_VECTOR_ITERATOR_H

namespace s21 {

template <typename T, bool Const>
class vectorIterator {
 public:
  using value_type = std::conditional_t<Const, const T, T>;
  using pointer = std::conditional_t<Const, const T *, T *>;
  using reference = std::conditional_t<Const, const T &, T &>;
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  explicit vectorIterator(pointer ptr) : ptr_(ptr) {}

  template <bool OtherConst>
  constexpr vectorIterator(const vectorIterator<T, OtherConst> &other) noexcept
      : ptr_(other.operator->()) {}

  vectorIterator() = default;

  reference operator*() { return *ptr_; }
  pointer operator->() const { return ptr_; }
  reference operator[](int m) { return ptr_[m]; }
  reference value() { return *ptr_; }

  vectorIterator operator++(int);
  vectorIterator operator--(int);
  vectorIterator &operator++();
  vectorIterator &operator--();

  bool operator==(const vectorIterator &other) const;
  bool operator!=(const vectorIterator &other) const;
  bool operator<(const vectorIterator &other) const;
  bool operator>(const vectorIterator &other) const;
  bool operator<=(const vectorIterator &other) const;
  bool operator>=(const vectorIterator &other) const;
  vectorIterator operator+(int n) const;
  vectorIterator operator-(int n) const;
  typename vectorIterator::difference_type operator-(
      const vectorIterator &other) const;

  vectorIterator &operator+=(int n);

 private:
  pointer ptr_;
};

template <typename T, bool Const>
vectorIterator<T, Const> &vectorIterator<T, Const>::operator+=(int n) {
  ptr_ += n;
  return *this;
}

template <typename T, bool Const>
vectorIterator<T, Const> vectorIterator<T, Const>::operator++(int) {
  vectorIterator temp(*this);
  ++ptr_;
  return temp;
}

template <typename T, bool Const>
vectorIterator<T, Const> vectorIterator<T, Const>::operator--(int) {
  vectorIterator temp(*this);
  --ptr_;
  return temp;
}

template <typename T, bool Const>
vectorIterator<T, Const> &vectorIterator<T, Const>::operator++() {
  ++ptr_;
  return *this;
}

template <typename T, bool Const>
vectorIterator<T, Const> &vectorIterator<T, Const>::operator--() {
  --ptr_;
  return *this;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator==(const vectorIterator &other) const {
  return ptr_ == other.ptr_;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator!=(const vectorIterator &other) const {
  return ptr_ != other.ptr_;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator<(const vectorIterator &other) const {
  return ptr_ < other.ptr_;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator>(const vectorIterator &other) const {
  return ptr_ > other.ptr_;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator<=(const vectorIterator &other) const {
  return ptr_ <= other.ptr_;
}

template <typename T, bool Const>
bool vectorIterator<T, Const>::operator>=(const vectorIterator &other) const {
  return ptr_ >= other.ptr_;
}

template <typename T, bool Const>
vectorIterator<T, Const> vectorIterator<T, Const>::operator+(int n) const {
  vectorIterator temp(*this);
  temp.ptr_ += n;
  return temp;
}

template <typename T, bool Const>
vectorIterator<T, Const> vectorIterator<T, Const>::operator-(int n) const {
  vectorIterator temp(*this);
  temp.ptr_ -= n;
  return temp;
}

template <typename T, bool Const>
typename vectorIterator<T, Const>::difference_type
vectorIterator<T, Const>::operator-(const vectorIterator &other) const {
  return ptr_ - other.ptr_;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_VECTOR_ITERATOR_H
