#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "s21_containers.h"
#include "s21_containersplus.h"
#include "s21_test_entry.h"

TEST(listTest, DefaultConstructor) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(listTest, SizeConstructor) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(listTest, InitializerlistConstructor) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, ConstructorCopy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(our_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(listTest, ConstructorMove) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.size(), std_copy.size());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(listTest, OperatorMove) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = std::move(our_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(listTest, Size) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(listTest, PushFront) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, PushBack) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, PopFront) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, PopBack) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, Swap) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.swap(our_list_second);
  std_list_first.swap(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
}

TEST(listTest, IteratorBegin) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
}

TEST(listTest, IteratorBeginPlusAndMinus) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(listTest, IteratorEnd_Last) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  --our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

// TEST(listTest, IteratorEquals) {
//   s21::list<int> first_list = {1, 2, 3};
//   s21::list<int>::iterator our_it_first;
//   our_it_first = first_list.begin();
//   s21::list<int>::iterator our_it_second;
//   our_it_second = first_list.begin();
//   EXPECT_TRUE(our_it_first == our_it_second);
//   EXPECT_TRUE(our_it_first >= our_it_second);
//   EXPECT_TRUE(our_it_first <= our_it_second);
//   ++our_it_second;
//   EXPECT_TRUE(our_it_first != our_it_second);
//   EXPECT_TRUE(our_it_second > our_it_first);
//   EXPECT_TRUE(our_it_second >= our_it_first);
//   EXPECT_TRUE(our_it_first < our_it_second);
//   EXPECT_TRUE(our_it_first <= our_it_second);
// }

TEST(listTest, Insert) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.insert(our_it, 7);
  std_list.insert(std_it, 7);
  our_list.insert(our_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, Erase) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, Splice) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::list<int>::const_iterator our_it = our_list_first.begin();
  std::list<int>::const_iterator std_it = std_list_first.begin();
  our_list_first.splice(our_it, our_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
}

TEST(listTest, Merge) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
}

TEST(listTest, Reverse) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(listTest, Unique) {
  s21::list<int> our_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.unique();
  std_list.unique();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(listTest, Sort) {
  s21::list<int> our_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.sort();
  std_list.sort();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(listTest, InsertMany) {
  s21::list<int> our_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  auto pos_our = std::next(our_list.begin(), 2);
  our_list.insert_many(pos_our, -1, -2, -3);
  auto pos = std::next(std_list.begin(), 2);
  const auto rg = std::vector<int>{-1, -2, -3};
  std_list.insert(pos, rg.cbegin(), rg.cend());

  auto iter = std_list.begin();
  for (auto iter_our = our_list.begin(); iter_our != our_list.end();
       ++iter_our) {
    EXPECT_EQ(*iter_our, *iter++);
  }
}

TEST(ListTest, end_2) {
  s21::list<int> my_list1(4);
  std::list<int> std_list2(4);

  auto my_list_end = my_list1.end();
  auto std_list_end = std_list2.end();

  EXPECT_EQ(my_list1.end() == my_list1.end(),
            std_list2.end() == std_list2.end());

  EXPECT_NE(my_list1.begin(), my_list_end);
  EXPECT_NE(std_list2.begin(), std_list_end);
}

TEST(ListTest, MaxSize) {
  s21::list<size_t> my_list_empty;
  std::list<size_t> std_list_empty;
  EXPECT_EQ(my_list_empty.max_size(), std_list_empty.max_size());
}

TEST(listTest, InsertMany_Back) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.insert_many_back(7, 8, 9);
  const auto tail = std::vector<int>{7, 8, 9};
  std_list.insert(std_list.end(), tail.cbegin(), tail.cend());

  auto iter = std_list.begin();
  for (auto iter_our = our_list.begin(); iter_our != our_list.end();
       ++iter_our) {
    EXPECT_EQ(*iter_our, *iter++);
  }
}

TEST(ListTest, InsertMany_Front) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.insert_many_front(7, 8, 9);
  const auto tail = std::vector<int>{7, 8, 9};
  std_list.insert(std_list.begin(), tail.cbegin(), tail.cend());

  auto iter = std_list.begin();
  for (auto iter_our = our_list.begin(); iter_our != our_list.end();
       ++iter_our) {
    EXPECT_EQ(*iter_our, *iter++);
  }
}

TEST(ListTest, Erase_2_throw) {
  s21::list<int> my_list1{1, 9999, 20000};

  EXPECT_THROW(my_list1.erase(my_list1.end()), std::invalid_argument);
}

TEST(ListTest, Erase_4_throw) {
  s21::list<int> my_list1;

  EXPECT_THROW(my_list1.erase(my_list1.end()--), std::invalid_argument);
}

TEST(List, Constructor_Default) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Size) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Constructor_List) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constructor_Copy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(our_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

// TEST(List, Operator_Copy)
// {
//   s21::list<int> our_list = {1, 2, 3};
//   std::list<int> std_list = {1, 2, 3};
//   s21::list<int> our_copy;
//   our_copy = our_list;
//   std::list<int> std_copy;
//   std_copy = std_list;
//   EXPECT_EQ(our_copy.front(), std_copy.front());
//   EXPECT_EQ(our_copy.back(), std_copy.back());
// }

TEST(List, Constructor_Move) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Operator_Move) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = std::move(our_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Size) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Push_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Push_Back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Pop_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Pop_Back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Iterator_Begin) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_BeginPlusAndMinus) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_End_Last) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  --our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_Equals) {
  s21::list<int> first_list = {1, 2, 3};
  s21::list<int>::iterator our_it_first;
  our_it_first = first_list.begin();
  s21::list<int>::iterator our_it_second;
  our_it_second = first_list.begin();
  EXPECT_TRUE(our_it_first == our_it_second);
  ++our_it_second;
  EXPECT_TRUE(our_it_first != our_it_second);
}

TEST(List, Insert) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.insert(our_it, 7);
  std_list.insert(std_it, 7);
  our_list.insert(our_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Erase) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Splice) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list_first.begin();
  std::list<int>::iterator std_it = std_list_first.begin();
  our_list_first.splice(our_it, our_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
}

TEST(List, Merge) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
}

TEST(List, Reverse) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Unique) {
  s21::list<int> our_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.unique();
  std_list.unique();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Sort) {
  s21::list<int> our_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.sort();
  std_list.sort();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Insert_Many) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list.begin();
  ++our_it;
  our_list.insert_many(our_it, 7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

TEST(List, Insert_Many_Back) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_back(7, 8, 9);
  our_it = our_list.end();
  --our_it;
  EXPECT_EQ(*our_it, 9);
  --our_it;
  EXPECT_EQ(*our_it, 8);
  --our_it;
  EXPECT_EQ(*our_it, 7);
  --our_it;
  EXPECT_EQ(*our_it, 5);
  --our_it;
  EXPECT_EQ(*our_it, 4);
}

// template <typename value_type>
// bool compare_lists(s21::list<value_type> my_list,
//                    std::list<value_type> std_list)
// {
//   bool result = true;
//   if (my_list.size() == std_list.size())
//   {
//     auto my_it = my_list.begin();
//     auto std_it = std_list.begin();
//     for (size_t i = 0; i != my_list.size(); ++i)
//     {
//       if (*my_it != *std_it)
//       {
//         result = false;
//         break;
//       }
//       my_it++;
//       std_it++;
//     }
//   }
//   else
//   {
//     result = false;
//   }
//   return result;
// }

// TEST(ListTest, Splice_4)
// {
//   s21::list<int> my_list1;
//   s21::list<int> my_list2;
//   my_list1.splice(my_list1.begin(), my_list2);

//   std::list<int> std_list1;
//   std::list<int> std_list2;
//   std_list1.splice(std_list1.begin(), std_list2);
//   EXPECT_TRUE(compare_lists(my_list1, std_list1));
// }

// TEST(ListTest, Splice_3)
// {
//   s21::list<int> my_list1{1, 9999, 20000};
//   s21::list<int> my_list2;
//   my_list1.splice(my_list1.begin(), my_list2);

//   std::list<int> std_list1{1, 9999, 20000};
//   std::list<int> std_list2;
//   std_list1.splice(std_list1.begin(), std_list2);
//   EXPECT_TRUE(compare_lists(my_list1, std_list1));
// }

#include <stack>

#include "s21_test_entry.h"

TEST(Stack, Constructor_Default) {
  s21::stack<int> our_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(StackTest, Constructor_default_2) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, Constructor_List) {
  s21::stack<int> our_stack = {1, 2, 3};
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, Constructor_Copy) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_copy(our_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}

TEST(Stack, Constructor_Move) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_move(std::move(our_stack));
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(Stack, Operator_Move) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(Stack, Top) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<double> our_stack_double = {1.1f, 2.1f, 3.1f};
  std::stack<double> std_stack_double;
  std_stack_double.push(1.1f);
  std_stack_double.push(2.1f);
  std_stack_double.push(3.1f);
  s21::stack<std::string> our_stack_string = {"abc", "def", "ghf"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("abc");
  std_stack_string.push("def");
  std_stack_string.push("ghf");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(our_stack_string.top(), std_stack_string.top());
}

TEST(Stack, Empty) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}

TEST(Stack, Size) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}

TEST(Stack, Push) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  // До pop()
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();

  // После pop()
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  // Попробуйте добавить pop() до пустого состояния
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  // Здесь не должно быть больше элементов
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), 0);
}

TEST(Stack, Pop) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  our_stack_int.pop();
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(Stack, Swap) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(VectorTest, DefaultConstructor) {
  s21::vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, SizeConstructor) {
  const size_t size = 5;
  s21::vector<int> our_vector(size);
  std::vector<int> std_vector(size);
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VectorTest, SizeConstructorZero) {
  const size_t size = 0;
  s21::vector<int> our_vector(size);
  std::vector<int> std_vector(size);
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, InitializerListEmpty) {
  s21::vector<int> our_vector = {};
  std::vector<int> std_vector = {};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(VectorTest, CopyConstructorEmpty) {
  s21::vector<int> our_vector;
  s21::vector<int> our_vector_copy(our_vector);
  std::vector<int> std_vector;
  std::vector<int> std_vector_copy(std_vector);
  EXPECT_EQ(our_vector_copy.empty(), std_vector_copy.empty());
  EXPECT_EQ(our_vector_copy.size(), std_vector_copy.size());
}

TEST(VectorTest, ConstructorCopy) {
  s21::vector<int> our_vector = {1, 2, 3};
  s21::vector<int> our_vector_copy(our_vector);
  EXPECT_EQ(our_vector_copy.size(), our_vector.size());
  for (size_t i = 0; i < our_vector.size(); ++i) {
    EXPECT_EQ(our_vector_copy[i], our_vector[i]);
  }
}

TEST(VectorTest, MoveConstructorEmpty) {
  s21::vector<int> our_vector;
  s21::vector<int> our_vector_copy(std::move(our_vector));
  EXPECT_TRUE(our_vector_copy.empty());
  EXPECT_EQ(our_vector_copy.size(), (size_t)0);
}

TEST(VectorTest, MoveConstructorNonEmpty) {
  s21::vector<int> our_vector = {1, 2, 3};
  s21::vector<int> our_vector_copy(std::move(our_vector));
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_copy(std::move(std_vector));
  EXPECT_EQ(our_vector_copy.size(), std_vector_copy.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorTest, DestructorEmpty) {
  s21::vector<int> *v = new s21::vector<int>();
  delete v;
}

TEST(VectorTest, DestructorNonEmpty) {
  s21::vector<int> *v = new s21::vector<int>{1, 2, 3};
  delete v;
}

TEST(VectorTest, MoveAssignmentOperatorNonEmptyToEmpty) {
  s21::vector<int> our_vector = {1, 2, 3};
  s21::vector<int> our_vector_move;
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_move;
  our_vector_move = std::move(our_vector);
  std_vector_move = std::move(std_vector);
  EXPECT_EQ(our_vector_move.size(), std_vector_move.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorTest, MoveAssignmentOperatorNonEmptyToNonEmpty) {
  s21::vector<int> our_vector = {1, 2, 3};
  s21::vector<int> our_vector_move = {4, 5, 6};
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_move = {4, 5, 6};
  our_vector_move = std::move(our_vector);
  std_vector_move = std::move(std_vector);
  EXPECT_EQ(our_vector_move.size(), std_vector_move.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorTest, AtValid) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.at(0), std_vector.at(0));
  EXPECT_EQ(our_vector.at(2), std_vector.at(2));
  EXPECT_EQ(our_vector.at(4), std_vector.at(4));
}

TEST(VectorTest, AtInvalid) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  EXPECT_THROW(our_vector.at(5), std::out_of_range);
  EXPECT_THROW(our_vector.at(10), std::out_of_range);
}

TEST(VectorTest, IndexOperatorValid) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[2], std_vector[2]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(VectorTest, ConstIndexOperatorValidI) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[2], std_vector[2]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(VectorTest, FrontConst) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.front(), std_vector.front());
}

TEST(VectorTest, BackConst) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.back(), std_vector.back());
}

TEST(VectorTest, Data) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  int *dataPtr = our_vector.data();
  int *dataPtr1 = std_vector.data();
  EXPECT_EQ(*dataPtr, *dataPtr1);
  *dataPtr = 10;
  *dataPtr1 = 10;
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(VectorTest, DataEmpty) {
  s21::vector<int> our_vector;
  int *dataPtr = our_vector.data();
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(VectorTest, Begin) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  auto it = our_vector.begin();
  auto it1 = std_vector.begin();
  EXPECT_EQ(*it, *it1);
  *it = 10;
  *it1 = 10;
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(VectorTest, BeginEmpty) {
  s21::vector<int> our_vector;
  auto it = our_vector.begin();
  EXPECT_EQ(it, our_vector.end());
}

TEST(VectorTest, End) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  auto it = our_vector.end();
  auto beginIt = our_vector.begin();
  EXPECT_NE(it, beginIt);
}

TEST(VectorTest, EndEmpty) {
  s21::vector<int> our_vector;
  auto it = our_vector.end();
  EXPECT_EQ(it, our_vector.begin());
}

TEST(VectorTest, Empty) {
  const s21::vector<int> our_vector;
  const std::vector<int> std_vector;
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorTest, EmptyNonEmptyVector) {
  const s21::vector<int> our_vector = {1, 2, 3};
  const std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorTest, SizeEmpty) {
  const s21::vector<int> our_vector;
  const std::vector<int> std_vector;
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, Size) {
  const s21::vector<int> our_vector = {1, 2, 3};
  const std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, MaxSize) {
  const s21::vector<int> our_vector;
  EXPECT_GT(our_vector.max_size(), 0U);
}

TEST(VectorTest, ReserveIncreaseCapacity) {
  s21::vector<int> our_vector;
  size_t initialCapacity = our_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  our_vector.reserve(newCapacity);
  EXPECT_GE(our_vector.capacity(), newCapacity);
}

TEST(VectorTest, ReserveDecreaseCapacity) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = our_vector.capacity();
  size_t newCapacity = initialCapacity - 2;
  our_vector.reserve(newCapacity);
  EXPECT_LE(our_vector.capacity(), initialCapacity);
  EXPECT_GE(our_vector.capacity(), newCapacity);
}

TEST(VectorTest, CapacityEmpty) {
  const s21::vector<int> our_vector;
  const std::vector<int> std_vector;
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, CapacityNonEmptyVector) {
  const s21::vector<int> our_vector = {1, 2, 3};
  const std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorTest, ShrinkToFitEmptyVector) {
  s21::vector<int> our_vector;
  our_vector.shrink_to_fit();
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(VectorTest, ShrinkToFitNonEmptyVector) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = our_vector.capacity();
  our_vector.pop_back();
  our_vector.shrink_to_fit();
  EXPECT_LE(our_vector.capacity(), our_vector.size());
  EXPECT_LE(our_vector.capacity(), initialCapacity);
}

TEST(VectorTest, ClearEmptyVector) {
  s21::vector<int> our_vector;
  our_vector.clear();
  EXPECT_TRUE(our_vector.empty());
  EXPECT_EQ(our_vector.size(), 0U);
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(VectorTest, ClearNonEmptyVector) {
  s21::vector<int> our_vector = {1, 2, 3, 4, 5};
  our_vector.clear();
  EXPECT_TRUE(our_vector.empty());
  EXPECT_EQ(our_vector.size(), 0U);
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(VectorTest, InsertBeginning) {
  s21::vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.begin(), 1);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.begin(), 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(*it, *it1);
}

TEST(VectorTest, InsertMiddle) {
  s21::vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.begin() + 1, 2);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.begin() + 1, 2);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[1], std_vector[1]);
  EXPECT_EQ(*it, *it1);
}

TEST(VectorTest, InsertEnd) {
  s21::vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.end(), 5);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.end(), 5);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[3], std_vector[3]);
  EXPECT_EQ(*it, *it1);
}

TEST(VectorTest, EraseBeginning) {
  s21::vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.begin());
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.begin());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(VectorTest, EraseMiddle) {
  s21::vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.begin() + 1);
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.begin() + 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[1], std_vector[1]);
}

TEST(VectorTest, EraseEnd) {
  s21::vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.end() - 1);
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.end() - 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[2], std_vector[2]);
}

TEST(VectorTest, PushBackEmptyVector) {
  s21::vector<int> our_vector;
  our_vector.push_back(1);
  std::vector<int> std_vector;
  std_vector.push_back(1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(VectorTest, PushBackNonEmptyVector) {
  s21::vector<int> our_vector = {1, 2, 3};
  our_vector.push_back(4);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.push_back(4);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[3], std_vector[3]);
}

TEST(VectorTest, PopBackNonEmptyVector) {
  s21::vector<int> our_vector = {1, 2, 3};
  our_vector.pop_back();
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.pop_back();
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector.back(), std_vector.back());
}

TEST(VectorTest, PopBackEmptyVector) {
  s21::vector<int> our_vector;
  our_vector.pop_back();
  EXPECT_EQ(our_vector.empty(), 1);
}

TEST(VectorTest, SwapNonEmptyVectors) {
  s21::vector<int> our_vector = {1, 2, 3};
  s21::vector<int> our_vector_swap = {4, 5, 6};
  our_vector.swap(our_vector_swap);
  EXPECT_EQ(our_vector.size(), 3U);
  EXPECT_EQ(our_vector_swap.size(), 3U);
  EXPECT_EQ(our_vector[0], 4);
  EXPECT_EQ(our_vector[2], 6);
  EXPECT_EQ(our_vector_swap[0], 1);
  EXPECT_EQ(our_vector_swap[2], 3);
}

TEST(VectorTest, SwapEmptyAndNonEmptyVectors) {
  s21::vector<int> our_vector;
  s21::vector<int> our_vector_swap = {1, 2, 3};
  our_vector.swap(our_vector_swap);
  EXPECT_EQ(our_vector.size(), 3U);
  EXPECT_FALSE(our_vector.empty());
  EXPECT_EQ(our_vector_swap.size(), 0U);
  EXPECT_TRUE(our_vector_swap.empty());
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> our_vector = {1, 2, 3, 7, 8};
  std::vector<int> std_vector = {1, 2, 3, 7, 8};
  auto pos_std = std::next(std_vector.begin(), 3);
  const auto pos_our = std::next(our_vector.begin(), 3);
  const auto rg_std = std::list<int>{4, 5, 6};
  std_vector.insert(pos_std, rg_std.cbegin(), rg_std.cend());
  our_vector.insert_many(pos_our, 4, 5, 6);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  for (std::size_t i = 0; i < our_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> our_vector = {1, 2, 3, 4};
  our_vector.insert_many_back(5, 6, 7);
  EXPECT_EQ(our_vector.size(), 7U);
  for (std::size_t i = 0; i < our_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], (int)i + 1);
  }
}

TEST(MapConstructors, Default) {
  s21::map<int, int> our_map;
  std::map<int, int> std_map;
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapConstructors, Initmap) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map.begin();
  std::map<int, int>::iterator std_it = std_map.begin();
  for (; std_it != std_map.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapConstructors, Copy) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int> our_map2(our_map);

  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map2(std_map);

  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapConstructors, Move) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int> our_map2(std::move(our_map));

  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map2(std::move(std_map));

  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapOperator, Move) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int> our_map2 = std::move(our_map);

  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map2 = std::move(std_map);

  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapFunctions, At) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  EXPECT_EQ(our_map.at(1), std_map.at(1));
  EXPECT_ANY_THROW(our_map.at(5));
  EXPECT_ANY_THROW(std_map.at(5));
}

TEST(MapOperator, Pos) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  EXPECT_EQ(our_map[1], std_map[1]);
  EXPECT_EQ(our_map[5], std_map[5]);
}

TEST(MapFunctions, Size) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  EXPECT_EQ(our_map.size(), std_map.size());
}

TEST(MapFunctions, KingSize) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  EXPECT_EQ(our_map.max_size(), std_map.max_size());
}

TEST(MapFunctions, Clear) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  our_map.clear();
  std_map.clear();
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapFunctions, Insert) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'a'}, {4, 'c'}, {5, 'k'}});

  our_map.insert(6, 'k');
  std_map.insert({6, 'k'});
  EXPECT_EQ(our_map[6], std_map[6]);

  our_map.insert(3, 'k');
  std_map.insert({3, 'k'});
  EXPECT_EQ(our_map[3], std_map[3]);
}

TEST(MapFunctions, Erase) {
  s21::map<int, int> our_map({{1, 142}, {2, 2543}, {3, 3214}});
  std::map<int, int> std_map({{1, 142}, {2, 2543}, {3, 3214}});
  s21::map<int, int>::IteratorMap our_it;
  our_map.erase(our_map.begin());
  our_it = our_map.begin();
  std_map.erase(std_map.begin());
  EXPECT_EQ(*our_it, *std_map.begin());
}

TEST(MapFunctions, Swap) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int> our_map2;
  our_map2.swap(our_map);

  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map2;
  std_map2.swap(std_map2);

  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapFunctions, Merge) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  s21::map<int, int> our_map2({{4, 4}, {5, 5}});
  our_map.merge(our_map2);

  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map2({{4, 4}, {5, 5}});
  std_map.merge(std_map2);

  s21::map<int, int>::IteratorMap our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapFunctions, Contains) {
  s21::map<int, int> our_map({{1, 2}, {2, 9}, {3, 4}});
  std::map<int, int> std_map({{1, 2}, {2, 9}, {3, 4}});
  EXPECT_EQ(our_map.contains(2), true);
  EXPECT_EQ(our_map.contains(4), false);
}

TEST(SetConstructors, Default) {
  s21::set<int> our_set;
  std::set<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetConstructors, Initset) {
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetConstructors, Copy) {
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetConstructors, Move) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set1(std::move(our_set));

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set1(std::move(std_set));

  s21::set<int>::iterator our_it = our_set1.begin();
  std::set<int>::iterator std_it = std_set1.begin();
  for (; std_it != std_set1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetOperator, Move) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set1 = std::move(our_set);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set1 = std::move(std_set);

  s21::set<int>::iterator our_it = our_set1.begin();
  std::set<int>::iterator std_it = std_set1.begin();
  for (; std_it != std_set1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Empty) {
  s21::set<int> our_set;
  std::set<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, UnEmpty) {
  s21::set<int> our_set({2, 3});
  std::set<int> std_set({2, 3});
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, Size) {
  s21::set<int> our_set({2, 3, 4, 5, 723, 436, 1});
  std::set<int> std_set({2, 3, 4, 5, 723, 436, 1});
  EXPECT_EQ(our_set.size(), std_set.size());
}

TEST(SetFunctions, KingSize) {
  s21::set<float> our_set({2, 3, 4, 5, 723.392042390, 436, 1});
  std::set<float> std_set({2, 3, 4, 5, 723.392042390, 436, 1});
  EXPECT_EQ(our_set.max_size(), std_set.max_size());
}

TEST(SetFunctions, Clear) {
  s21::set<float> our_set({2, 3, 4, 5, 723.392042390, 436, 1});
  std::set<float> std_set({2, 3, 4, 5, 723.392042390, 436, 1});
  our_set.clear();
  std_set.clear();
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, Insert) {
  s21::set<int> our_set;
  std::set<int> std_set;
  our_set.insert(2);
  s21::set<int>::iterator itr = our_set.begin();
  std_set.insert(2);
  std::set<int>::iterator itr2 = std_set.begin();
  EXPECT_EQ(*itr, *itr2);
}

TEST(SetFunctions, Erase) {
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  our_set.erase(our_set.begin());
  s21::set<int>::iterator itr = our_set.begin();
  std_set.erase(std_set.begin());
  std::set<int>::iterator itr2 = std_set.begin();
  EXPECT_EQ(*itr, *itr2);
}

TEST(SetFunctions, Swap) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set2({3, 2, 1});
  our_set.swap(our_set2);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set2({3, 2, 1});
  std_set.swap(std_set2);

  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Merge) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set2({3, 4, 5});
  our_set.merge(our_set2);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set2({3, 4, 5});
  std_set.merge(std_set2);

  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  std::set<int>::iterator std_it2 = std_set2.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it, ++std_it2) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Find) {
  s21::set<int> our_set({1, 2, 3});

  std::set<int> std_set({1, 2, 3});

  s21::set<int>::iterator our_it = our_set.find(2);
  std::set<int>::iterator std_it = std_set.find(2);
  EXPECT_EQ(*(our_it), *(std_it));
}

TEST(SetFunctions, Contains) {
  s21::set<int> our_set({1, 2, 3});
  EXPECT_EQ(our_set.contains(2), true);
  EXPECT_EQ(our_set.contains(4), false);
}

TEST(MultisetConstructors, Default) {
  s21::multiset<int> our_set;
  std::multiset<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(MultisetConstructors, Init) {
  s21::multiset<int> our_multiset({1, 2, 3, 4, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4});
  s21::multiset<int>::iterator our_it = our_multiset.begin();
  std::multiset<int>::iterator std_it = std_multiset.begin();
  for (; std_it != std_multiset.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  };
}

TEST(MultisetConstructors, Copy) {
  s21::multiset<int> our_multiset({1, 2, 3, 4, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4});
  s21::multiset<int>::iterator our_it = our_multiset.begin();
  std::multiset<int>::iterator std_it = std_multiset.begin();
  for (; std_it != std_multiset.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetConstructors, Move) {
  s21::multiset<int> our_multiset({1, 2, 3, 4, 4, 4});
  s21::multiset<int> our_multiset1(std::move(our_multiset));

  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4});
  std::multiset<int> std_multiset1(std::move(std_multiset));

  s21::multiset<int>::iterator our_it = our_multiset1.begin();
  std::multiset<int>::iterator std_it = std_multiset1.begin();
  for (; std_it != std_multiset1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetOperator, Move) {
  s21::multiset<int> our_multiset({1, 2, 3, 4, 4, 4});
  s21::multiset<int> our_multiset1 = std::move(our_multiset);

  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4});
  std::multiset<int> std_multiset1 = std::move(std_multiset);

  s21::multiset<int>::iterator our_it = our_multiset1.begin();
  std::multiset<int>::iterator std_it = std_multiset1.begin();
  for (; std_it != std_multiset1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetFunctions, Empty) {
  s21::multiset<int> our_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(our_multiset.empty(), std_multiset.empty());
}

TEST(MultisetFunctions, UnEmpty) {
  s21::multiset<int> our_multiset({2, 3});
  std::multiset<int> std_multiset({2, 3});
  EXPECT_EQ(our_multiset.empty(), std_multiset.empty());
}

TEST(MultisetFunctions, Count) {
  s21::multiset<int> our_multiset({1, 2, 9, 2, 9, 3});
  std::multiset<int> std_multiset({1, 2, 9, 2, 9, 3});
  EXPECT_EQ(our_multiset.count(2), std_multiset.count(2));
  EXPECT_EQ(our_multiset.count(4), std_multiset.count(4));
}

TEST(MultisetFunctions, LowerBound) {
  s21::multiset<int> our_multiset({1, 2, 9, 2, 9, 3});
  std::multiset<int> std_multiset({1, 2, 9, 2, 9, 3});
  EXPECT_EQ(*our_multiset.lower_bound(2), *std_multiset.lower_bound(2));
}

TEST(MultisetFunctions, UpperBound) {
  s21::multiset<int> our_multiset({1, 2, 9, 2, 9, 3});
  std::multiset<int> std_multiset({1, 2, 9, 2, 9, 3});
  EXPECT_EQ(*our_multiset.upper_bound(2), *std_multiset.upper_bound(2));
}

template <typename value_type>
bool compare_queues(s21::queue<value_type> my_queue,
                    std::queue<value_type> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CompareQueues_2) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(100);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  s21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, Pushmany) {
  s21::queue<int> my_queue{0, 1, 2};

  my_queue.insert_many_back(3, 4, 5, 6);
  for (size_t i = 0; i < my_queue.size(); i++) {
    EXPECT_EQ(my_queue.front(), i);
    my_queue.pop();
  }
}

TEST(QueueTest, Pop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, Swap) {
  s21::queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  s21::queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> arr;
  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that all elements are initialized to their default value (0 for int)
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 0);
  }
}

TEST(ArrayTest, InitListConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that each element is initialized correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, CopyConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrCopy(arr);

  // Check that the size is correct
  EXPECT_EQ(arrCopy.size(), 5);

  // Check that the elements are copied correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arrCopy[i], arr[i]);
  }
}

TEST(ArrayTest, MoveConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrMoved(std::move(arr));

  // Check that the size is correct
  EXPECT_EQ(arrMoved.size(), 5);

  // Check that the elements are moved correctly
  for (size_t i = 0; i < arrMoved.size(); ++i) {
    EXPECT_EQ(arrMoved[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Begin) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.begin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the array is updated
  *it = 10;
  EXPECT_EQ(arr[0], 10);
}

TEST(ArrayTest, End) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.end();
  // end() iterator should not be dereferenced; comparing it to another iterator
  // should work
  auto beginIt = arr.begin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, CBegin) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.begin();
  EXPECT_EQ(*it, 1);
  // Attempting to modify data through a const_iterator should result in a
  // compilation error Uncommenting the following line should result in a
  // compilation error. *it = 10;
}

TEST(ArrayTest, CEnd) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.end();
  // cend() iterator should not be dereferenced; comparing it to another
  // iterator should work
  auto beginIt = arr.begin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, At_ValidIndex) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, At_OutOfBounds) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  // Attempting to access an out-of-bounds index using at() should throw an
  // exception
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, ConstAt_ValidIndex) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr[2];
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, ConstAt_OutOfBounds) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  // Attempting to access an out-of-bounds index using const at() should throw
  // an exception
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, Front) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, Back) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, ConstFront) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, ConstBack) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, Empty_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_FALSE(arr.empty());
}

TEST(ArrayTest, Empty_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, Size_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, Size_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 5> arr;
  // The max size of an array with a specified size is the same as its declared
  // size
  EXPECT_EQ(arr.max_size(), 5);
}

TEST(ArrayTest, Swap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1.swap(arr2);

  // Check that the elements of arr1 are now from arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }

  // Check that the elements of arr2 are now from arr1
  for (size_t i = 0; i < arr2.size(); ++i) {
    EXPECT_EQ(arr2[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 5> arr;
  arr.fill(10);

  // Check that all elements are filled with the specified value
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 10);
  }
}

TEST(ArrayTest, CopyAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1 = arr2;

  // Check that arr1 now contains the same elements as arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], arr2[i]);
  }
}

TEST(ArrayTest, MoveAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1 = std::move(arr2);

  // Check that arr1 now contains the same elements as arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }
}

TEST(ArrayTest, OperatorBracket) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that elements can be accessed using the [] operator
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }

  // Modify an element using the [] operator and check if the array is updated
  arr[2] = 10;
  EXPECT_EQ(arr[2], 10);
}

TEST(ArrayTest, NonConstData) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int *data_ptr = arr.data();
  ASSERT_NE(data_ptr, nullptr);
  EXPECT_EQ(data_ptr[0], 1);
  EXPECT_EQ(data_ptr[1], 2);
  EXPECT_EQ(data_ptr[2], 3);
  EXPECT_EQ(data_ptr[3], 4);
  EXPECT_EQ(data_ptr[4], 5);
}

TEST(ArrayTest, ConstData) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  const int *data_ptr = arr.data();
  ASSERT_NE(data_ptr, nullptr);
  EXPECT_EQ(data_ptr[0], 1);
  EXPECT_EQ(data_ptr[1], 2);
  EXPECT_EQ(data_ptr[2], 3);
  EXPECT_EQ(data_ptr[3], 4);
  EXPECT_EQ(data_ptr[4], 5);
}

TEST(ArrayTest, ModifyThroughNonConstData) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int *data_ptr = arr.data();
  data_ptr[0] = 10;
  data_ptr[1] = 20;
  EXPECT_EQ(arr.data()[0], 10);
  EXPECT_EQ(arr.data()[1], 20);
}

TEST(ArrayTest, EmptyArray) {
  s21::array<int, 0> arr;
  int *data_ptr = arr.data();
  EXPECT_NE(data_ptr, nullptr);
  EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, DoubleArrayData) {
  s21::array<double, 3> arr = {1.1, 2.2, 3.3};
  double *data_ptr = arr.data();
  EXPECT_DOUBLE_EQ(data_ptr[0], 1.1);
  EXPECT_DOUBLE_EQ(data_ptr[1], 2.2);
  EXPECT_DOUBLE_EQ(data_ptr[2], 3.3);
}

TEST(MultisetTest, CopyConstructor) {
  s21::multiset<int> original = {1, 2, 3};
  s21::multiset<int> copy(original);

  EXPECT_EQ(copy.size(), original.size());

  auto it1 = original.begin();
  auto it2 = copy.begin();
  auto it1_end = original.end();
  auto it2_end = copy.end();

  while (it1 != it1_end && it2 != it2_end) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetTest, MoveConstructor) {
  s21::multiset<int> original = {1, 2, 3};
  s21::multiset<int> moved(std::move(original));

  EXPECT_EQ(moved.size(), 3);
  EXPECT_EQ(original.size(), 0);
}

TEST(MultisetTest, MoveAssignmentOperator) {
  s21::multiset<int> original = {1, 2, 3};
  s21::multiset<int> assigned;
  assigned = std::move(original);

  EXPECT_EQ(assigned.size(), 3);
  EXPECT_EQ(original.size(), 0);
}

TEST(MultisetTest, Merge) {
  s21::multiset<int> set1 = {1, 2, 3};
  s21::multiset<int> set2 = {3, 4, 5};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), 6);  // 1, 2, 3, 3, 4, 5
  EXPECT_EQ(set2.size(), 0);

  std::vector<int> expected_values = {1, 2, 3, 3, 4, 5};
  auto it = set1.begin();
  for (const auto &val : expected_values) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(IteratorTreeTest, DecrementOperator) {
  s21::AVLTree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);
  tree.insert(15, 15);
  tree.insert(3, 3);
  tree.insert(7, 7);

  auto it = tree.end();
  --it;
  EXPECT_EQ(*it, 15);

  --it;
  EXPECT_EQ(*it, 10);

  --it;
  EXPECT_EQ(*it, 7);

  --it;
  EXPECT_EQ(*it, 5);

  --it;
  EXPECT_EQ(*it, 3);

  EXPECT_EQ(it, tree.begin());
}

TEST(ConstIteratorTreeTest, EqualityOperator) {
  s21::AVLTree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);
  tree.insert(15, 15);

  auto it1 = tree.begin();
  auto it2 = tree.begin();

  EXPECT_TRUE(it1 == it2);  // Проверяем, что итераторы равны

  ++it1;
  EXPECT_FALSE(it1 == it2);  // Теперь итераторы должны быть неравны

  ++it2;
  EXPECT_TRUE(it1 == it2);  // Теперь итераторы снова должны быть равны
}

TEST(AVLTreeTest, InitializerListConstructor) {
  s21::AVLTree<int, int> tree{{10, 10}, {5, 5}, {15, 15}, {3, 3}, {7, 7}};
  std::vector<int> expected_values = {3, 5, 7, 10, 15};

  auto it = tree.begin();
  for (const auto &value : expected_values) {
    EXPECT_EQ(*it, value);
    ++it;
  }

  EXPECT_EQ(it, tree.end());  // Убедимся, что итератор доходит до конца дерева
}

TEST(AVLTreeTest, EqualRange) {
  s21::AVLTree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);
  tree.insert(15, 15);
  tree.insert(5, 50);
  tree.insert(10, 100);

  auto range = tree.equal_range(10);

  auto it = range.first;
  EXPECT_EQ(*it, 10);
  ++it;
  EXPECT_EQ(it, range.second);
}

TEST(DequeTest, InitializerListConstructor) {
  s21::deque<int> d = {1, 2, 3, 4, 5};

  EXPECT_EQ(d.size(), 5);
  EXPECT_EQ(d.front(), 1);
  EXPECT_EQ(d.back(), 5);

  d.pop_front();
  EXPECT_EQ(d.front(), 2);
  EXPECT_EQ(d.size(), 4);

  d.pop_back();
  EXPECT_EQ(d.back(), 4);
  EXPECT_EQ(d.size(), 3);

  d.pop_front();
  d.pop_front();
  d.pop_front();

  EXPECT_TRUE(d.empty());  // Убедитесь, что deque пуст
  EXPECT_THROW(
      d.pop_back(),
      std::out_of_range);  // Попробуйте удалить элемент из пустого deque
}

TEST(IteratorTreeTest, DefaultConstructor) {
  s21::AVLTree<int, int>::IteratorTree it;
  s21::AVLTree<int, int>::IteratorTree default_it;
  EXPECT_TRUE(it == default_it);  // Проверяем, что итератор, созданный по
                                  // умолчанию, равен другому такому же
}

TEST(DequeTest, PushFront) {
  s21::deque<int> d;

  d.push_front(10);
  EXPECT_EQ(d.front(), 10);
  EXPECT_EQ(d.back(), 10);

  d.push_front(20);
  EXPECT_EQ(d.front(), 20);
  EXPECT_EQ(d.back(), 10);

  d.push_front(30);
  EXPECT_EQ(d.front(), 30);
  EXPECT_EQ(d.back(), 10);

  EXPECT_EQ(d.size(), 3);
}

TEST(DequeTest, Swap) {
  s21::deque<int> d1 = {1, 2, 3};
  s21::deque<int> d2 = {4, 5, 6, 7};

  d1.swap(d2);

  EXPECT_EQ(d1.size(), 4);
  EXPECT_EQ(d1.front(), 4);
  EXPECT_EQ(d1.back(), 7);

  EXPECT_EQ(d2.size(), 3);
  EXPECT_EQ(d2.front(), 1);
  EXPECT_EQ(d2.back(), 3);
}

TEST(DequeTest, AssignmentOperator) {
  s21::deque<int> d1 = {1, 2, 3};
  s21::deque<int> d2;

  d2 = d1;

  EXPECT_EQ(d2.size(), 3);
  EXPECT_EQ(d2.front(), 1);
  EXPECT_EQ(d2.back(), 3);

  d1.push_back(4);
  EXPECT_EQ(d2.size(), 3);  // Проверка, что изменения в d1 не влияют на d2
  EXPECT_EQ(d2.back(), 3);
}

TEST(DequeTest, InsertManyBack) {
  s21::deque<int> d;

  d.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(d.size(), 5);
  EXPECT_EQ(d.front(), 1);
  EXPECT_EQ(d.back(), 5);

  d.pop_back();
  EXPECT_EQ(d.back(), 4);
}

TEST(ListTest, CBeginCendEmptyList) {
  s21::list<int> lst;

  auto cbegin = lst.cbegin();
  auto cend = lst.cend();

  EXPECT_EQ(cbegin, cend);
}

TEST(ListTest, CBeginCendNonEmptyList) {
  s21::list<int> lst = {1, 2, 3};

  auto cbegin = lst.cbegin();
  auto cend = lst.cend();

  EXPECT_NE(cbegin, cend);
  EXPECT_EQ(*cbegin, 1);

  ++cbegin;
  EXPECT_EQ(*cbegin, 2);

  ++cbegin;
  EXPECT_EQ(*cbegin, 3);

  ++cbegin;
  EXPECT_EQ(cbegin, cend);
}

TEST(ListTest, CBeginCendConstCorrectness) {
  const s21::list<int> lst = {10, 20, 30};

  auto cbegin = lst.cbegin();
  auto cend = lst.cend();

  EXPECT_EQ(*cbegin, 10);
  ++cbegin;
  EXPECT_EQ(*cbegin, 20);
  ++cbegin;
  EXPECT_EQ(*cbegin, 30);

  ++cbegin;
  EXPECT_EQ(cbegin, cend);
}

TEST(MapTest, MoveAssignmentOperator) {
  s21::map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> map2;

  map2 = std::move(map1);

  EXPECT_EQ(map2.size(), 3);
  EXPECT_EQ(map2[1], "one");
  EXPECT_EQ(map2[2], "two");
  EXPECT_EQ(map2[3], "three");

  EXPECT_EQ(map1.size(), 0);
}

TEST(MapTest, InsertMany) {
  s21::map<int, std::string> map;

  auto result = map.insert_many(std::make_pair(1, std::string("one")),
                                std::make_pair(2, std::string("two")),
                                std::make_pair(3, std::string("three")));

  EXPECT_EQ(result.size(), 3);
  EXPECT_TRUE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_TRUE(result[2].second);

  EXPECT_EQ(map.size(), 3);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
}

TEST(MapTest, InsertManyWithDuplicates) {
  s21::map<int, std::string> map;

  map.insert(1, std::string("one"));
  auto result = map.insert_many(std::make_pair(1, std::string("uno")),
                                std::make_pair(2, std::string("two")),
                                std::make_pair(3, std::string("three")));

  EXPECT_EQ(result.size(), 3);
  EXPECT_FALSE(
      result[0]
          .second);  // 1, "uno" should not be inserted because 1 already exists
  EXPECT_TRUE(result[1].second);  // 2, "two" should be inserted
  EXPECT_TRUE(result[2].second);  // 3, "three" should be inserted

  EXPECT_EQ(map.size(), 3);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
}

TEST(MapTest, InsertManyEmpty) {
  s21::map<int, std::string> map;

  auto result = map.insert_many();

  EXPECT_EQ(result.size(), 0);
  EXPECT_TRUE(map.empty());
}

TEST(QueueTest, MoveAssignmentOperatorWithNonEmptyQueue) {
  s21::queue<int> queue1;
  queue1.push(10);
  queue1.push(20);

  s21::queue<int> queue2;
  queue2.push(30);
  queue2.push(40);

  queue2 = std::move(queue1);

  ASSERT_EQ(queue2.size(), 2);
  EXPECT_EQ(queue2.front(), 10);
  queue2.pop();
  EXPECT_EQ(queue2.front(), 20);
  queue2.pop();

  EXPECT_TRUE(queue1.empty());
}

TEST(QueueTest, MoveAssignmentOperatorWithEmptyQueue) {
  s21::queue<int> queue1;
  s21::queue<int> queue2;

  queue2 = std::move(queue1);

  EXPECT_TRUE(queue2.empty());
  EXPECT_TRUE(queue1.empty());
}

TEST(QueueTest, MoveAssignmentOperatorSelfAssignment) {
  s21::queue<int> queue1;
  queue1.push(1);
  queue1.push(2);

  queue1 = std::move(queue1);

  ASSERT_EQ(queue1.size(), 2);
  EXPECT_EQ(queue1.front(), 1);
  queue1.pop();
  EXPECT_EQ(queue1.front(), 2);
  queue1.pop();

  EXPECT_TRUE(queue1.empty());
}

TEST(SetTest, CopyConstructor) {
  s21::set<int> original_set = {1, 2, 3, 4};
  s21::set<int> copied_set(original_set);

  EXPECT_EQ(copied_set.size(), original_set.size());

  auto it_orig = original_set.begin();
  auto it_copy = copied_set.begin();
  while (it_orig != original_set.end()) {
    EXPECT_EQ(*it_orig, *it_copy);
    ++it_orig;
    ++it_copy;
  }
}

TEST(SetTest, InsertManySingleElements) {
  s21::set<int> my_set;

  auto results = my_set.insert_many(1, 2, 3);

  // Проверка, что все элементы были вставлены
  EXPECT_EQ(results.size(), 3);
  EXPECT_TRUE(results[0].second);  // Вставка 1
  EXPECT_TRUE(results[1].second);  // Вставка 2
  EXPECT_TRUE(results[2].second);  // Вставка 3

  // Проверка, что элементы находятся в контейнере
  EXPECT_EQ(*results[0].first, 1);
  EXPECT_EQ(*results[1].first, 2);
  EXPECT_EQ(*results[2].first, 3);

  // Проверка размера множества
  EXPECT_EQ(my_set.size(), 3);
}

TEST(SetTest, InsertManyWithDuplicates) {
  s21::set<int> my_set;
  my_set.insert(1);  // Вставка начального значения

  auto results = my_set.insert_many(1, 2, 2, 3, 1);

  // Проверка, что элементы с дубликатами были вставлены правильно
  EXPECT_EQ(results.size(), 5);
  EXPECT_FALSE(results[0].second);  // Дубликат 1
  EXPECT_TRUE(results[1].second);   // Вставка 2
  EXPECT_FALSE(results[2].second);  // Дубликат 2
  EXPECT_TRUE(results[3].second);   // Вставка 3
  EXPECT_FALSE(results[4].second);  // Дубликат 1

  // Проверка, что элементы находятся в контейнере
  EXPECT_EQ(*results[0].first, 1);
  EXPECT_EQ(*results[1].first, 2);
  EXPECT_EQ(*results[2].first, 2);
  EXPECT_EQ(*results[3].first, 3);
  EXPECT_EQ(*results[4].first, 1);

  // Проверка размера множества (ожидается 3 уникальных элемента)
  EXPECT_EQ(my_set.size(), 3);
}

TEST(StackTest, InsertManyBackSingleElements) {
  s21::stack<int> my_stack;

  my_stack.insert_many_back(1, 2, 3);

  // Проверка, что элементы вставлены в правильном порядке
  EXPECT_EQ(my_stack.top(), 3);
  my_stack.pop();
  EXPECT_EQ(my_stack.top(), 2);
  my_stack.pop();
  EXPECT_EQ(my_stack.top(), 1);
  my_stack.pop();

  // Проверка, что стек пуст после извлечения всех элементов
  EXPECT_TRUE(my_stack.empty());
}

TEST(StackTest, InsertManyBackWithDifferentTypes) {
  s21::stack<std::string> my_stack;

  my_stack.insert_many_back("first", "second", "third");

  // Проверка, что элементы вставлены в правильном порядке
  EXPECT_EQ(my_stack.top(), "third");
  my_stack.pop();
  EXPECT_EQ(my_stack.top(), "second");
  my_stack.pop();
  EXPECT_EQ(my_stack.top(), "first");
  my_stack.pop();

  // Проверка, что стек пуст после извлечения всех элементов
  EXPECT_TRUE(my_stack.empty());
}

TEST(VectorIteratorTest, PostfixDecrement) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it = vec.end();
  --it;  // Указываем на последний элемент (5)
  auto it2 = it--;
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*it2, 5);
}

TEST(VectorIteratorTest, PrefixIncrement) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it = vec.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorIteratorTest, LessThanOperator) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it1 = vec.begin();
  auto it2 = vec.begin() + 2;
  EXPECT_TRUE(it1 < it2);
  EXPECT_FALSE(it2 < it1);
}

TEST(VectorIteratorTest, GreaterThanOperator) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it1 = vec.begin();
  auto it2 = vec.begin() + 2;
  EXPECT_TRUE(it2 > it1);
  EXPECT_FALSE(it1 > it2);
}

TEST(VectorIteratorTest, LessThanOrEqualOperator) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it1 = vec.begin();
  auto it2 = vec.begin() + 2;
  EXPECT_TRUE(it1 <= it2);
  EXPECT_TRUE(it1 <= it1);
  EXPECT_FALSE(it2 <= it1);
}

TEST(VectorIteratorTest, GreaterThanOrEqualOperator) {
  s21::vector<int> vec = {1, 2, 3, 4, 5};
  auto it1 = vec.begin();
  auto it2 = vec.begin() + 2;
  EXPECT_TRUE(it2 >= it1);
  EXPECT_TRUE(it1 >= it1);
  EXPECT_FALSE(it1 >= it2);
}

TEST(MultisetTest, InsertManyUniqueElements) {
  s21::multiset<int> ms;
  auto result = ms.insert_many(1, 2, 3, 4, 5);

  EXPECT_EQ(ms.size(), 5);
  EXPECT_TRUE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_TRUE(result[2].second);
  EXPECT_TRUE(result[3].second);
  EXPECT_TRUE(result[4].second);
}

TEST(MultisetTest, InsertManyWithDuplicates) {
  s21::multiset<int> ms;
  ms.insert_many(1, 2, 3);

  auto result = ms.insert_many(3, 4, 5, 1, 2);

  EXPECT_EQ(ms.size(), 8);
  EXPECT_FALSE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_TRUE(result[2].second);
  EXPECT_FALSE(result[3].second);
  EXPECT_FALSE(result[4].second);
}

TEST(MultisetTest, InsertManyEmpty) {
  s21::multiset<int> ms;
  auto result = ms.insert_many();

  EXPECT_EQ(ms.size(), 0);
  EXPECT_TRUE(result.empty());
}

TEST(MultisetTest, InsertManySameElementMultipleTimes) {
  s21::multiset<int> ms;
  auto result = ms.insert_many(42, 42, 42);

  EXPECT_EQ(ms.size(), 3);
  EXPECT_TRUE(result[0].second);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}