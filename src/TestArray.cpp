#include <gtest/gtest.h>

#include "array.h"

using namespace s21;

TEST(Array, default_construct) {
  Array<int, 0> myArr;
  ASSERT_EQ(myArr.size(), 0);
}

TEST(Array, eq_and_not_eq) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  Array<int, 4>::ArrayIterator iter = myArr.begin(), other = myArr.begin();
  ASSERT_EQ(true, other == iter);
  ASSERT_EQ(false, other != iter);
}

TEST(Array, initializer_list_construct) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  ASSERT_EQ(myArr.size(), 4);

  Array<int, 4>::ArrayIterator iter = myArr.begin();
  ASSERT_EQ(1, *iter);
  ASSERT_EQ(2, *(++iter));
  ASSERT_EQ(3, *(++iter));
  ASSERT_EQ(4, *(++iter));
}
TEST(Array, copy_construct) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  Array<int, 4> other = myArr;
  ASSERT_EQ(other[0], 1);
  ASSERT_EQ(other[1], 2);
  ASSERT_EQ(other[2], 3);
  ASSERT_EQ(other[3], 4);
}

TEST(Array, move_construct_and_equating) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  Array<int, 4> move = std::move(myArr);
  Array<int, 4>::ArrayIterator iter = move.begin();
  ASSERT_EQ(true, myArr.empty());
  ASSERT_EQ(1, *iter);
  ASSERT_EQ(2, *(++iter));
  ASSERT_EQ(3, *(++iter));
  ASSERT_EQ(4, *(++iter));

  Array<int, 4> move1;
  move1 = std::move(move);
  iter = move1.begin();
  ASSERT_EQ(true, move.empty());
  ASSERT_EQ(1, *iter);
  ASSERT_EQ(2, *(++iter));
  ASSERT_EQ(3, *(++iter));
  ASSERT_EQ(4, *(++iter));
}

TEST(Array, front_back) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  ASSERT_EQ(1, myArr.front());
  ASSERT_EQ(4, myArr.back());
}

TEST(Array, at) {
  Array<int, 4> myArr = {1, 2, 3, 4};
  ASSERT_EQ(1, myArr.at(0));
  ASSERT_EQ(2, myArr.at(1));
  ASSERT_EQ(3, myArr.at(2));
  ASSERT_EQ(4, myArr.at(3));
}

TEST(Array, fill) {
  Array<double, 5> myArr;
  myArr.fill(0.5);
  Array<double, 5>::ArrayIterator iter = myArr.begin();
  ASSERT_EQ(0.5, *iter);
  ASSERT_EQ(0.5, *(++iter));
  ASSERT_EQ(0.5, *(++iter));
  ASSERT_EQ(0.5, *(++iter));
  ASSERT_EQ(0.5, *(++iter));
}

TEST(Array, swap) {
  Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  Array<int, 5> arr10 = {10, 20, 30, 40, 50, 60};
  arr1.swap(arr10);
  Array<int, 5>::ArrayIterator iter1 = arr10.begin(), iter10 = arr1.begin();
  ASSERT_EQ(1, *iter1);
  ASSERT_EQ(2, *(++iter1));
  ASSERT_EQ(3, *(++iter1));
  ASSERT_EQ(4, *(++iter1));
  ASSERT_EQ(5, *(++iter1));
  ASSERT_EQ(10, *iter10);
  ASSERT_EQ(20, *(++iter10));
  ASSERT_EQ(30, *(++iter10));
  ASSERT_EQ(40, *(++iter10));
  ASSERT_EQ(50, *(++iter10));
}

TEST(Array_iters, plus_plus) {
  Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  Array<int, 5>::ArrayIterator iter = arr1.begin();
  ASSERT_EQ(1, *iter);
  ASSERT_EQ(2, *(iter++));
  ASSERT_EQ(3, *(++iter));
}

TEST(Array_iters, plus) {
  Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  Array<int, 5>::ArrayIterator iter = arr1.begin();
  iter = iter + 1;
  ASSERT_EQ(2, *iter);
  iter = iter + 2;
  ASSERT_EQ(4, *iter);
}

TEST(Array, operator_minusminus) {
  Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  Array<int, 5>::ArrayIterator iter = arr1.end();
  iter--;
  ASSERT_EQ(5, *iter);
  --iter;
  ASSERT_EQ(4, *iter);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}