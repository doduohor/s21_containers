namespace s21 {
template <typename K>
multiset<K>::multiset() : AVLTree<K, K>() {}

template <typename K>
multiset<K>::multiset(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    AVLTree<K, K>::add_mst(*i, *i);
  }
}

template <typename K>
multiset<K>::multiset(const multiset &mst_) : AVLTree<K, K>(mst_) {}

template <typename K>
multiset<K>::multiset(multiset &&mst_) : AVLTree<K, K>(std::move(mst_)) {}

template <typename K>
multiset<K> &multiset<K>::operator=(multiset &&mst_) {
  if (this != &mst_) {
    AVLTree<K, K>::operator=(std::move(mst_));
  }
  return *this;
}

template <typename K>
std::pair<typename multiset<K>::iterator, bool> multiset<K>::insert(
    const K &value) {
  auto it = this->find(value);
  bool is_inserted = (it == this->end());
  this->add_mst(
      value,
      value);  // Метод добавления элемента в дерево (допускает дубликаты)
  return std::make_pair(this->find(value), is_inserted);
}

template <typename K>
template <class... Args>
std::vector<std::pair<typename multiset<K>::iterator, bool>>
multiset<K>::insert_many(Args &&...args) {
  std::vector<std::pair<typename multiset<K>::iterator, bool>> v;
  (v.push_back(this->insert(std::forward<Args>(args))), ...);
  return v;
}

template <typename K>
void multiset<K>::merge(multiset &other) {
  AVLTree<K, K>::merge_mst(other);
}
}  // namespace s21