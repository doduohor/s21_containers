namespace s21 {
template <typename K, typename V>
map<K, V>::map() : AVLTree<K, V>() {}

template <typename K, typename V>
map<K, V>::map(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) {
    AVLTree<K, V>::insert(item.first, item.second);
  }
}

template <typename K, typename V>
map<K, V>::map(const map &m_) : AVLTree<K, V>(m_) {}

template <typename K, typename V>
map<K, V>::map(map &&m_) : AVLTree<K, V>(std::move(m_)) {}

template <typename K, typename V>
map<K, V> &map<K, V>::operator=(map &&m_) {
  if (this != &m_) {
    AVLTree<K, V>::operator=(std::move(m_));
  }
  return *this;
}

template <typename K, typename V>
template <class... Args>
std::vector<std::pair<typename map<K, V>::iterator, bool>>
map<K, V>::insert_many(Args &&...args) {
  std::vector<std::pair<typename map<K, V>::iterator, bool>> v;
  (v.push_back(AVLTree<K, V>::insert(args.first, args.second)), ...);
  return v;
}

}  // namespace s21