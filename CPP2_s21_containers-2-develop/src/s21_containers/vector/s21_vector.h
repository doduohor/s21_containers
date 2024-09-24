#ifndef CPP2_S21_CONTAINERS_VECTOR_H
#define CPP2_S21_CONTAINERS_VECTOR_H

#include "s21_vector_iterations.h"

namespace s21 {

template <typename T>
class vector {
 public:
  using value_type = T;
  using size_type = size_t;
  using reference = T &;
  using const_reference = const T &;
  using iterator = vectorIterator<T, false>;
  using const_iterator = vectorIterator<T, true>;
  using iterator_pointer = T *;

  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<T> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();
  vector &operator=(vector &&v) noexcept;

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator_pointer data() noexcept;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);

  void removing();
  void zeroing();

 private:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;
};

template <typename value_type>
vector<value_type>::vector() : data_(nullptr), size_(0U), capacity_(0U) {}

template <typename value_type>
vector<value_type>::vector(size_type n)
    : data_(nullptr), size_(0U), capacity_(0U) {
  if (n == 0U) return;
  if (max_size() < n) {
    throw std::out_of_range("cannot create s21::vector larger than max_size()");
  }

  data_ = new value_type[n];
  size_ = n;
  capacity_ = n;

  try {
    std::uninitialized_fill_n(data_, n, value_type());
  } catch (...) {
    removing();
    throw;
  }
}

template <typename value_type>
vector<value_type>::vector(std::initializer_list<value_type> const &items)
    : data_(nullptr), size_(0U), capacity_(0U) {
  if (items.size() == 0U) return;

  try {
    size_ = items.size();
    capacity_ = size_;
    data_ = new value_type[capacity_];
    std::uninitialized_copy(items.begin(), items.end(), data_);
  } catch (...) {
    removing();
    throw;
  }
}

template <typename value_type>
vector<value_type>::vector(const vector &v)
    : data_(nullptr), size_(0U), capacity_(0U) {
  if (v.size_ == 0U) return;

  data_ = new value_type[v.capacity_];
  size_ = v.size_;
  capacity_ = v.capacity_;
  std::uninitialized_copy(v.data_, v.data_ + size_, data_);
}

template <typename value_type>
vector<value_type>::vector(vector &&v) noexcept
    : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
  v.zeroing();
}

template <typename T>
vector<T>::~vector() {
  removing();
}

template <class value_type>
typename s21::vector<value_type> &vector<value_type>::operator=(
    vector &&v) noexcept {
  if (this != &v) {
    removing();
    size_ = v.size_;
    capacity_ = v.capacity_;
    data_ = v.data_;
    v.zeroing();
  }
  return *this;
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("AtError: Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::operator[](
    size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::front() const {
  if (empty()) {
    throw std::out_of_range("FrontError: vector is empty");
  }
  return data_[0U];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::back() const {
  if (empty()) {
    throw std::out_of_range("BackError: vector is empty");
  }
  return data_[size_ - 1];
}

template <typename value_type>
typename vector<value_type>::iterator_pointer
vector<value_type>::data() noexcept {
  return data_;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return iterator(data_);
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return iterator(data_ + size_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::cbegin() const {
  return const_iterator(data_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename value_type>
bool vector<value_type>::empty() const {
  return size_ == 0U;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T>
void vector<T>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }
  if (new_capacity > max_size()) {
    throw std::out_of_range("ReserveError: new capacity exceeds max_size");
  }

  iterator_pointer new_data = static_cast<iterator_pointer>(
      ::operator new(new_capacity * sizeof(value_type)));
  try {
    std::uninitialized_copy(data_, data_ + size_, new_data);
  } catch (...) {
    ::operator delete(new_data);
    throw;
  }

  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename value_type>
typename vector<value_type>::size_type vector<value_type>::capacity() const {
  return capacity_;
}

template <typename value_type>
void vector<value_type>::shrink_to_fit() {
  if (size_ < capacity_) {
    iterator_pointer new_data = new value_type[size_];
    try {
      std::uninitialized_copy(data_, data_ + size_, new_data);
    } catch (...) {
      delete[] new_data;
      throw;
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename value_type>
void vector<value_type>::clear() noexcept {
  size_ = 0U;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();

  if (index > size_) {
    throw std::out_of_range("Index out ot range");
  }
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }

  iterator new_pos = begin() + index;
  std::copy_backward(new_pos, end(), end() + 1);
  *new_pos = value;
  ++size_;
  return new_pos;
}

template <class value_type>
template <class... Args>
typename vector<value_type>::iterator vector<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  size_type index = pos - cbegin();
  size_type count = sizeof...(args);

  if (size_ + count > capacity_) {
    reserve(size_ + count);
  }

  iterator insert_pos = begin() + index;
  std::move_backward(insert_pos, end(), end() + count);

  ((*(insert_pos++) = std::forward<Args>(args)), ...);

  size_ += count;
  return begin() + index;
}

template <class value_type>
template <class... Args>
void vector<value_type>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

template <typename value_type>
void vector<value_type>::erase(iterator pos) {
  size_type index = pos - iterator(data_);
  if (index >= size_) {
    throw std::out_of_range("Index out ot range");
  }

  for (size_type i = index + 1; i < size_; ++i) {
    data_[i - 1] = data_[i];
  }
  --size_;
}

template <typename value_type>
void vector<value_type>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_++] = std::move(value);
}

template <typename value_type>
void vector<value_type>::pop_back() {
  if (size_ > 0U) {
    --size_;
    data_[size_].~value_type();
  }
}

template <typename value_type>
void vector<value_type>::swap(vector<value_type> &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename value_type>
void vector<value_type>::removing() {
  if (data_) delete[] data_;
  data_ = nullptr;
  size_ = 0U;
  capacity_ = 0U;
}

template <typename value_type>
void vector<value_type>::zeroing() {
  data_ = nullptr;
  size_ = 0U;
  capacity_ = 0U;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_VECTOR_H
