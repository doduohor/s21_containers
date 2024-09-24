namespace s21 {
template <typename K>
set<K>::set() : AVLTree<K, K>() {}

template <typename K>
set<K>::set(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    AVLTree<K, K>::add_node(*i, *i);
  }
}

template <typename K>
set<K>::set(const set &st_) : AVLTree<K, K>(st_) {}

template <typename K>
set<K>::set(set &&st_) : AVLTree<K, K>(std::move(st_)) {}

template <typename K>
set<K> &set<K>::operator=(set &&st_) {
  if (this != &st_) {
    AVLTree<K, K>::operator=(std::move(st_));
  }
  return *this;
}

template <typename Key>
template <class... Args>
std::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args &&...args) {
  std::vector<std::pair<typename set<Key>::iterator, bool>> v;
  for (const auto &arg : {args...}) {
    v.push_back(AVLTree<Key, Key>::insert(arg));
  }
  return v;
}

}  // namespace s21