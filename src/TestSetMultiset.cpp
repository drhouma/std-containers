// Copyright 2022 telvina

#include <gtest/gtest.h>

#include <set>

#include "multiset.h"
#include "set.h"

TEST(Test, IterBegin) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 15, 14};
  s21::set<int> mySet(list);
  std::set<int> origSet(list);
  s21::set<int>::iterator myIter;
  std::set<int>::iterator origIter;
  myIter = mySet.begin();
  origIter = origSet.begin();
  ASSERT_EQ(*myIter, *origIter);
}

TEST(Test, FromBeginToEnd) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, string) {
  std::initializer_list<std::string> list{"2321",   "fgdgf",          "a",
                                          "dfdsf4", "d2ueu3eg32e3d2", "......"};
  s21::set<std::string> mySet(list);
  std::set<std::string> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    EXPECT_TRUE(*iter1 == *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, insert) {
  std::initializer_list<double> list{11.3, -4.1, 3231.2, 2.33, 0.9,
                                     1.10, 2.5,  7.25,   6.3,  8.0,
                                     -132, 12.3, 13.4,   -5.15};
  s21::set<double> mySet(list);
  std::set<double> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  mySet.insert(666.777);
  origSet.insert(666.777);
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, erase) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto iter2 = origSet.begin();
  auto rmIter1 = mySet.begin();
  auto rmIter2 = origSet.begin();
  ++rmIter1;
  ++rmIter2;
  mySet.erase(rmIter1);
  origSet.erase(rmIter2);
  while (iter1 != mySet.end() && iter2 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, erase2) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> mySet(list);
  std::set<int> origSet(list);
  auto iter1 = mySet.begin();
  auto rmIter1 = mySet.begin();
  auto rmIter2 = origSet.begin();
  ++rmIter1;
  ++rmIter2;
  mySet.erase(rmIter1);
  origSet.erase(rmIter2);
  auto rmIter11 = mySet.begin();
  auto rmIter22 = origSet.begin();
  mySet.erase(rmIter11);
  origSet.erase(rmIter22);
  iter1 = mySet.begin();
  auto iter22 = origSet.begin();
  while (iter1 != mySet.end() && iter22 != origSet.end()) {
    ASSERT_EQ(*iter1, *iter22);
    ++iter1;
    ++iter22;
  }
}

TEST(Test, emptyTrue) {
  std::set<char> oSet;
  s21::set<char> mSet;
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.empty());
}

TEST(Test, emptyFlase) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::set<int> mSet(list);
  EXPECT_FALSE(oSet.empty());
  EXPECT_FALSE(mSet.empty());
}

TEST(Test, clear) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::set<int> mSet(list);
  oSet.clear();
  mSet.clear();
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.empty());
  oSet.clear();
  mSet.clear();
  EXPECT_TRUE(oSet.empty());
  EXPECT_TRUE(mSet.empty());
}

TEST(Test, swap) {
  std::initializer_list<long double> list{11.3, -4.1, 3231.2, 2.33, 0.9,
                                          1.10, 2.5,  7.25,   6.3,  8.0,
                                          -132, 12.3, 13.4,   -5.15};
  std::set<long double> oSet1(list);
  std::set<long double> oSet2;
  s21::set<long double> mSet1(list);
  s21::set<long double> mSet2;
  oSet1.swap(oSet2);
  mSet1.swap(mSet2);
  EXPECT_TRUE(oSet1.empty());
  EXPECT_FALSE(oSet2.empty());
  EXPECT_TRUE(mSet1.empty());
  EXPECT_FALSE(mSet2.empty());
}

// Если компилить с 20 стандартом
TEST(Test, merge1) {
  std::initializer_list<int> list1{11, 4, 2, 3,  9,  10, 5,
                                   7,  6, 8, 13, 12, 14, 15};
  std::initializer_list<int> list2{-4, -5, 28, 39};
  std::set<int> oSet1(list1);
  std::set<int> oSet2(list2);
  oSet1.merge(oSet2);
  s21::set<int> mSet1(list1);
  s21::set<int> mSet2(list2);
  mSet1.merge(mSet2);
  std::set<int>::iterator oIt = oSet1.begin();
  s21::set<int>::iterator mIt = mSet1.begin();
  while (oIt != oSet1.end() && mIt != mSet1.end()) {
    ASSERT_EQ(*oIt, *mIt);
    ++oIt;
    ++mIt;
  }
  EXPECT_TRUE(oSet2.empty() && mSet2.empty());
}

TEST(Test, merge2) {
  std::set<int> oSet;
  s21::set<int> mSet;
  oSet.merge(oSet);
  mSet.merge(mSet);
  EXPECT_TRUE(oSet.empty() && mSet.empty());
}

TEST(Test, find1) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet(list);
  s21::set<int> mSet(list);
  std::set<int>::iterator oIter = oSet.find(13);
  s21::set<int>::iterator mIter = mSet.find(13);
  ASSERT_EQ(*oIter, *mIter);
  ++oIter;
  ++mIter;
  ASSERT_EQ(*oIter, *mIter);
}

TEST(Test, find2) {
  s21::set<char> Set;
  s21::set<char>::iterator it;
  it = Set.find('f');
  EXPECT_TRUE(it == Set.end());
}

TEST(Test, contains1) {
  s21::set<char> Set;
  EXPECT_FALSE(Set.contains('f'));
}

TEST(Test, contains2) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> Set(list);
  EXPECT_TRUE(Set.contains(10));
  EXPECT_TRUE(Set.contains(13));
  EXPECT_TRUE(Set.contains(12));
  EXPECT_FALSE(Set.contains(-7));
}

TEST(Test, size1) {
  std::initializer_list<int> list{6,        9,      -2,     43,
                                  21432432, 234324, 412342, 12321};
  s21::set<int> mSet(list);
  std::set<int> oSet(list);
  ASSERT_EQ(mSet.size(), oSet.size());
}

TEST(Test, size2) {
  std::set<int> oSet;
  s21::set<int> mSet;
  ASSERT_EQ(oSet.size(), mSet.size());
}

TEST(Test, move_constructor) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  std::set<int> oSet1(list);
  std::set<int> oSet2(std::move(oSet1));
  s21::set<int> mSet1(list);
  s21::set<int> mSet2(std::move(mSet1));
  EXPECT_TRUE(oSet1.empty() == mSet1.empty());
  EXPECT_TRUE(oSet2.empty() == mSet2.empty());
}

TEST(Test, copy_constructor) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> mSet1(list);
  s21::set<int> mSet2(mSet1);
  s21::set<int>::iterator it1 = mSet1.begin();
  s21::set<int>::iterator it2 = mSet2.begin();
  while (it1 != mSet1.end() || it2 != mSet2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, move_operator) {
  std::initializer_list<int> list{11, 4, 2, 3,  9,  10, 5,
                                  7,  6, 8, 13, 12, 14, 15};
  s21::set<int> mSet1(list);
  s21::set<int> mSet2 = std::move(mSet1);
  ASSERT_TRUE(mSet1.empty());
  ASSERT_FALSE(mSet2.empty());
}

TEST(Test, max_size) {
  s21::set<int> mSet;
  ASSERT_EQ(2305843009213693951, mSet.max_size());
}

TEST(Test, multi_fromStartToEnd) {
  s21::multiset<int> mMulti;
  std::multiset<int> oMulti;
  mMulti.insert(1);
  oMulti.insert(1);
  mMulti.insert(1);
  oMulti.insert(1);
  mMulti.insert(2);
  oMulti.insert(2);
  mMulti.insert(3);
  oMulti.insert(3);
  mMulti.insert(3);
  oMulti.insert(3);
  auto it1 = mMulti.begin();
  auto it2 = oMulti.begin();
  while (it1 != mMulti.end() && it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, multi_initlist) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti(list);
  std::multiset<int> oMulti(list);
  auto it1 = mMulti.begin();
  auto it2 = oMulti.begin();
  while (it1 != mMulti.end() && it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, multi_copy) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti1(list);
  std::multiset<int> oMulti1(list);
  s21::multiset<int> mMulti2(mMulti1);
  std::multiset<int> oMulti2(oMulti1);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, multi_move) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti1(list);
  std::multiset<int> oMulti1(list);
  s21::multiset<int> mMulti2(std::move(mMulti1));
  std::multiset<int> oMulti2(std::move(oMulti1));
  EXPECT_TRUE(mMulti1.empty());
  EXPECT_TRUE(oMulti1.empty());
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, multi_eq) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti1(list);
  std::multiset<int> oMulti1(list);
  s21::multiset<int> mMulti2 = std::move(mMulti1);
  std::multiset<int> oMulti2 = std::move(oMulti1);
  EXPECT_TRUE(mMulti1.empty());
  EXPECT_TRUE(oMulti1.empty());
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, size) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.size(), oMulti2.size());
}

TEST(Test, max_size_int) {
  s21::multiset<int> mMulti;
  ASSERT_EQ(2305843009213693951, mMulti.max_size());
}

TEST(Test, multi_clear) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti(list);
  mMulti.clear();
  ASSERT_TRUE(mMulti.empty());
}

TEST(Test, multi_erase) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto rit1 = mMulti2.begin();
  auto rit2 = oMulti2.begin();
  ++rit2;
  ++rit1;
  mMulti2.erase(rit1);
  oMulti2.erase(rit2);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.size(), oMulti2.size());
}

TEST(Test, multi_erase2) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti2(list);
  std::multiset<int> oMulti2(list);
  auto rit1 = mMulti2.begin();
  auto rit2 = oMulti2.begin();
  mMulti2.erase(rit1);
  oMulti2.erase(rit2);
  auto it1 = mMulti2.begin();
  auto it2 = oMulti2.begin();
  while (it1 != mMulti2.end() && it2 != oMulti2.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  ASSERT_EQ(mMulti2.size(), oMulti2.size());
}

TEST(Test, multi_swap) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti1(list);
  s21::multiset<int> mMulti2;
  mMulti1.swap(std::move(mMulti2));
  EXPECT_TRUE(mMulti1.empty());
  EXPECT_FALSE(mMulti2.empty());
}

TEST(Test, multi_merge) {
  std::initializer_list<int> list = {1, 2, 3, 3, 4, 5, 5, 6};
  s21::multiset<int> mMulti1(list);
  s21::multiset<int> mMulti2(list);
  std::multiset<int> oMulti1(list);
  std::multiset<int> oMulti2(list);
  mMulti1.merge(mMulti2);
  oMulti1.merge(oMulti2);
  EXPECT_TRUE(oMulti2.empty());
  EXPECT_TRUE(mMulti2.empty());
  auto it1 = mMulti1.begin();
  auto it2 = oMulti1.begin();
  while (it1 != mMulti1.end() || it2 != oMulti1.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, find) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti(list);
  std::multiset<int> oMulti(list);
  auto it1 = mMulti.find(3);
  auto it2 = oMulti.find(3);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, contains) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  s21::multiset<int> mMulti(list);
  EXPECT_TRUE(mMulti.contains(-3));
  EXPECT_FALSE(mMulti.contains(-10));
}

TEST(Test, count) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2, 3,  3, 5,
                                     6, -1, -1, 6, 7, 9, 22, 0, -3};
  std::multiset<int> oMulti(list);
  s21::multiset<int> mMulti(list);
  ASSERT_EQ(oMulti.count(1), mMulti.count(1));
  ASSERT_EQ(oMulti.count(2), mMulti.count(2));
  ASSERT_EQ(oMulti.count(0), mMulti.count(0));
  ASSERT_EQ(oMulti.count(73), mMulti.count(73));
}

TEST(Test, lower1) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oMulti(list);
  s21::multiset<int> mMulti(list);
  ASSERT_EQ(*mMulti.lower_bound(77), *oMulti.lower_bound(77));
  auto it1 = mMulti.lower_bound(1);
  auto it2 = oMulti.lower_bound(1);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, upper) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oMulti(list);
  s21::multiset<int> mMulti(list);
  ASSERT_EQ(*mMulti.upper_bound(22), *oMulti.upper_bound(22));
  auto it1 = mMulti.upper_bound(1);
  auto it2 = oMulti.upper_bound(1);
  while (it1 != mMulti.end() || it2 != oMulti.end()) {
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Test, xtreme_upANDlow) {
  std::initializer_list<double> list = {22.3, 17.9, 323.2};
  std::multiset<double> oSet(list);
  s21::multiset<double> mSet(list);
  ASSERT_DOUBLE_EQ(*oSet.upper_bound(1.3), *mSet.upper_bound(1.3));
  ASSERT_DOUBLE_EQ(*oSet.lower_bound(1.3), *mSet.lower_bound(1.3));
}

TEST(Test, range) {
  std::initializer_list<int> list = {1, 1,  1,  2, 2, 2,  3, 3, 5,
                                     6, -1, -1, 6, 7, 22, 9, 0, -3};
  std::multiset<int> oSet(list);
  s21::multiset<int> mSet(list);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> p1;
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> p2;
  p1 = oSet.equal_range(2);
  p2 = mSet.equal_range(2);
  ASSERT_EQ(*p1.first, *p2.first);
  ASSERT_EQ(*p1.second, *p2.second);
}

TEST(Tets, set_emplace) {
  std::initializer_list<double> list = {1.2, 3.7, 3.14, 8.9};
  std::set<double> set1(list);
  s21::set<double> set2(list);
  set1.emplace(1.2);
  set1.emplace(3.7);
  set1.emplace(9.9);
  auto v2 = set2.emplace(1.2, 3.7, 9.9);
  auto it2 = v2.begin();
  for (int i = 0; i < 3; i++, ++it2) {
    if (i == 2) {
      ASSERT_TRUE((*it2).second);
    } else {
      ASSERT_FALSE((*it2).second);
    }
  }
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, set_emplace_empty) {
  std::initializer_list<int> list = {1, 3, 3, 8, 17};
  s21::set<int> set1(list);
  std::set<int> set2(list);
  auto v1 = set1.emplace();
  auto it1 = v1.begin();
  ASSERT_EQ(*(*it1).first, 0);
  ASSERT_FALSE((*it1).second);
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, multi_emplace) {
  std::initializer_list<double> list = {1.2, 3.7, 3.14, 8.9};
  std::multiset<double> set1(list);
  s21::multiset<double> set2(list);
  set1.emplace(1.2);
  set1.emplace(3.7);
  set1.emplace(9.9);
  auto v2 = set2.emplace(1.2, 3.7, 9.9);
  auto it2 = v2.begin();
  for (int i = 0; i < 3; i++, ++it2) {
    ASSERT_TRUE((*it2).second);
  }
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_DOUBLE_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

TEST(Test, multi_emplce_empty) {
  std::initializer_list<int> list = {1, 3, 3, 8, 17};
  s21::multiset<int> set1(list);
  std::multiset<int> set2(list);
  auto v1 = set1.emplace();
  auto it1 = v1.begin();
  ASSERT_EQ(*(*it1).first, 0);
  ASSERT_FALSE((*it1).second);
  auto iter1 = set1.begin();
  auto iter2 = set2.begin();
  while (iter1 != set1.end() || iter2 != set2.end()) {
    ASSERT_EQ(*iter1, *iter2);
    ++iter1;
    ++iter2;
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
