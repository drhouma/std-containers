#include <gtest/gtest.h>

#include "list.h"
using namespace s21;

TEST(List, simple_constructor) {
  List<double> empty;
  ASSERT_EQ(true, empty.empty());
}

TEST(List, push) {
  List<double> test1;
  test1.push_back(0.5);
  ASSERT_EQ(0.5, test1.front());
  test1.push_back(0.7);
  ASSERT_EQ(0.7, test1.back());
  test1.push_front(0.1);
  ASSERT_EQ(0.1, test1.front());
}

TEST(List, iterators_construct) {
  List<char> symbols = {'a', 'b', 'c', 'd'};
  List<char>::ListIterator iter = symbols.begin();
  ASSERT_EQ('a', *iter);
  iter = symbols.end();
  --iter;
  ASSERT_EQ('d', *iter);
}

TEST(List, iterator_list_loop_plus) {
  List<char> symbols = {'a', 'b', 'c', 'd'};
  List<char>::ListIterator iter = symbols.begin();
  ASSERT_EQ('a', *iter);
  ASSERT_EQ('b', *(++iter));
  ASSERT_EQ('c', *(++iter));
  ASSERT_EQ('d', *(++iter));
  ASSERT_EQ(true, (++iter) == symbols.end());
}
TEST(List, iterator_list_loop_minus) {
  List<char> symbols = {'a', 'b', 'c', 'd'};
  List<char>::ListIterator iter = symbols.end();
  ASSERT_EQ('d', *(--iter));
  ASSERT_EQ('c', *(--iter));
  ASSERT_EQ('b', *(--iter));
  ASSERT_EQ('a', *(--iter));
  ASSERT_EQ(true, iter == symbols.begin());
}

TEST(List, constructors) {
  List<char> symbols = {'1', '2', '3', '4'};
  List<char>::ListIterator charIter = symbols.begin();
  ASSERT_EQ('1', *charIter);
  ASSERT_EQ('2', *(++charIter));
  ASSERT_EQ('3', *(++charIter));
  ASSERT_EQ('4', *(++charIter));
  List<char> symbols_copy(symbols);
  List<char>::ListIterator charIter1 = symbols_copy.begin();
  ASSERT_EQ('1', *charIter1);
  ASSERT_EQ('2', *(++charIter1));
  ASSERT_EQ('3', *(++charIter1));
  ASSERT_EQ('4', *(++charIter1));
  List<char> symbols_move = std::move(symbols_copy);
  List<char>::ListIterator charIter2 = symbols_move.begin();
  ASSERT_EQ('1', *charIter2);
  ASSERT_EQ('2', *(++charIter2));
  ASSERT_EQ('3', *(++charIter2));
  ASSERT_EQ('4', *(++charIter2));
  ASSERT_EQ(true, symbols_copy.empty());
  List<int> constrWithSize(5);
  ASSERT_EQ(5, constrWithSize.size());
}

TEST(List, insert) {
  List<char> symbols = {'a', 'b', 'c', 'd'};
  List<char>::ListIterator iter = symbols.begin();
  List<char>::ListIterator iter1 = symbols.insert(iter, 'n');
  ASSERT_EQ('n', *(symbols.begin()));
  ASSERT_EQ('n', symbols.front());
  ASSERT_EQ('n', *iter1);

  iter = iter + 3;
  iter1 = symbols.insert(iter, 'l');

  ASSERT_EQ('l', *iter1);
}

TEST(List, erase) {
  List<char> symbols = {'a', 'b', 'c', 'd'};
  List<char>::ListIterator iter = symbols.begin();
  symbols.erase(iter);
  ASSERT_EQ('b', symbols.front());
  ASSERT_EQ(3, symbols.size());
  iter = symbols.begin();

  symbols.erase(iter + 1);
  ASSERT_EQ('b', *(iter));
  ASSERT_EQ('d', *(iter + 1));
  ASSERT_EQ(2, symbols.size());
  symbols.erase(symbols.begin());
  symbols.erase(symbols.begin());
  ASSERT_EQ(0, symbols.size());
}

TEST(List, pop) {
  List<char> numbers = {'-', '0', '1', '2', '3', '4', '5', '6', '7'};
  numbers.pop_back();
  ASSERT_EQ('6', numbers.back());
  numbers.pop_back();
  ASSERT_EQ('5', numbers.back());
  List<char>::ListIterator k = numbers.end();
  --k;
  numbers.pop_front();
  ASSERT_EQ('0', numbers.front());
  ASSERT_EQ('5', *k);
}

TEST(List, merge) {
  List<int> elems1 = {1, 2, 3, 4};
  List<int> elems2 = {5, 6, 7, 8};
  elems1.merge(elems2);
  List<int>::ListIterator iter = elems1.begin(), end = elems1.end();
  int sum = 0;
  for (; iter != end; ++iter) {
    sum += *iter;
  }
  ASSERT_EQ(36, sum);
}

TEST(List, reverse) {
  List<int> normal = {1, 2, 3, 4, 5};
  List<int> reverse = {5, 4, 3, 2, 1};
  normal.reverse();
  List<int>::ListIterator iter = normal.begin(), iterCheck = reverse.begin();
  List<int>::ListIterator end = reverse.end();
  for (; iterCheck != end; ++iterCheck, ++iter) {
    ASSERT_EQ(*iter, *iterCheck);
  }
}

TEST(List, unique1) {
  List<int> myList = {1, 1, 1, 1, 1, 1};
  myList.unique();
  List<int>::ListIterator iter = myList.begin();
  ASSERT_EQ(*iter, 1);
  ASSERT_EQ(myList.size(), 1);
}

TEST(List, unique2) {
  List<int> myList = {1, 1, 2, 2, 3, 3, 4, 4};
  myList.unique();
  List<int>::ListIterator iter = myList.begin();
  ASSERT_EQ(*iter, 1);
  ASSERT_EQ(*(++iter), 2);
  ASSERT_EQ(*(++iter), 3);
  ASSERT_EQ(*(++iter), 4);
  ASSERT_EQ(myList.size(), 4);
}

TEST(List, splice) {
  List<int> myList = {1, 2, 3};
  List<int> otherList = {4, 5, 6};
  List<int>::ListIterator iter = myList.begin();
  myList.splice(iter, otherList);
  iter = myList.begin();
  ASSERT_EQ(*iter, 4);
  ASSERT_EQ(*(++iter), 5);
  ASSERT_EQ(*(++iter), 6);
  ASSERT_EQ(*(++iter), 1);
  ASSERT_EQ(*(++iter), 2);
  ASSERT_EQ(*(++iter), 3);
  ASSERT_EQ(myList.size(), 6);
}

TEST(List, emplace) {
  List<int> myList = {1, 2, 3};
  List<int> checkList = {1, 4, 5, 6, 2, 3};
  List<int>::ListIterator iter = myList.begin(), end = myList.end(),
                          iterCheck = checkList.begin();
  myList.emplace(iter + 1, 4, 5, 6);
  for (; iter != end; iter++, iterCheck++) {
    ASSERT_EQ(*iter, *iterCheck);
  }
}

TEST(List, emplace_back) {
  List<int> myList = {1, 2, 3};
  List<int> checkList = {1, 2, 3, 4, 5, 6};
  List<int>::ListIterator iter = myList.begin(), end,
                          iterCheck = checkList.begin();
  myList.emplace_back(4, 5, 6);
  end = myList.end();
  for (; iter != end; iter++, iterCheck++) {
    ASSERT_EQ(*iter, *iterCheck);
  }
}

TEST(List, emplace_front) {
  List<int> myList = {1, 2, 3};
  List<int> checkList = {4, 5, 6, 1, 2, 3};
  List<int>::ListIterator iter = myList.begin(), end,
                          iterCheck = checkList.begin();
  myList.emplace_front(4, 5, 6);
  end = myList.end();
  iter = myList.begin();
  for (; iter != end; iter++, iterCheck++) {
    ASSERT_EQ(*iter, *iterCheck);
  }
}

TEST(List, operator_minus) {
  List<int> myList = {1, 2, 3};
  List<int>::ListIterator iter = myList.end();
  iter = iter - 1;
  ASSERT_EQ(*iter, 3);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}