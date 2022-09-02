//
// Created by Emery Reva on 3/21/22.
//

#include <gtest/gtest.h>

#include "map.h"
#include "vector.h"

using namespace s21;

TEST(Map, basic) {
  Map<int, int> Kala;

  //  Emptiness check

  ASSERT_EQ(Kala.size(), 0);
  ASSERT_EQ(Kala.max_size(), 0);
  ASSERT_TRUE(Kala.empty());

  //  Pairs initialization
  auto pair_1 = std::make_pair(15, 6);
  auto pair_2 = std::make_pair(1, 2);
  auto pair_3 = std::make_pair(6, 546);
  auto pair_4 = std::make_pair(32, 1);
  auto pair_5 = std::make_pair(2, 5);
  auto pair_6 = std::make_pair(14, 8);
  auto pair_7 = std::make_pair(3, 93);
  auto pair_8 = std::make_pair(16, 7);

  //  Insert check

  auto insert_iter_pair = Kala.insert(pair_1);

  Map<int, int>::iterator iter;
  iter = Kala.end();
  auto check_pair = *iter;
  ASSERT_EQ(check_pair.first, 15);
  ASSERT_EQ(check_pair.second, 6);
  ASSERT_EQ(pair_1, *insert_iter_pair.first);

  Kala.insert(pair_2);

  iter = Kala.end();
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 15);
  ASSERT_EQ(check_pair.second, 6);

  iter = Kala.begin();
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 1);
  ASSERT_EQ(check_pair.second, 2);

  iter = Kala.insert(pair_3).first;

  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 6);
  ASSERT_EQ(check_pair.second, 546);

  --iter;
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 1);
  ASSERT_EQ(check_pair.second, 2);

  ASSERT_TRUE(Kala.contains(1));

  //  Copy constructor check

  Map<int, int> KalaCopied(Kala);

  iter = KalaCopied.begin();
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 1);
  ASSERT_EQ(check_pair.second, 2);

  ++iter;
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 6);
  ASSERT_EQ(check_pair.second, 546);

  ++iter;
  check_pair = *iter;
  ASSERT_EQ(check_pair.first, 15);
  ASSERT_EQ(check_pair.second, 6);

  ASSERT_TRUE(KalaCopied.contains(6));

  --iter;
  check_pair = *iter;

  KalaCopied.erase(iter);

  ASSERT_FALSE(KalaCopied.contains(6));

  //  Initialize constructor check

  Map<int, int> KalaSorted = {pair_2, pair_5, pair_7, pair_3,
                              pair_6, pair_1, pair_8, pair_4};

  ASSERT_EQ(KalaSorted.size(), 8);
  ASSERT_EQ(KalaSorted.max_size(), 8);

  Map<int, int>::iterator sortIterB(KalaSorted.begin());
  Map<int, int>::iterator sortIterE(KalaSorted.end());

  bool sorted{true};
  auto tmp_pair = *sortIterB;

  while (sortIterB <= sortIterE && sorted) {
    check_pair = *sortIterB;
    if (check_pair.first < tmp_pair.first) {
      sorted = false;
    }
    tmp_pair = check_pair;
    ++sortIterB;
  }

  ASSERT_TRUE(sorted);

  KalaSorted.clear();

  ASSERT_EQ(KalaSorted.size(), 0);
  ASSERT_EQ(KalaSorted.max_size(), 0);
  ASSERT_TRUE(KalaSorted.empty());

  Map<int, int> KalaInit = {pair_1, pair_2, pair_3, pair_4,
                            pair_5, pair_6, pair_7, pair_8};

  ASSERT_EQ(KalaInit.size(), 8);
  ASSERT_EQ(KalaInit.max_size(), 8);

  Map<int, int>::iterator sortItersB(KalaInit.begin());
  Map<int, int>::iterator sortItersE(KalaInit.end());

  sorted = true;
  tmp_pair = *sortItersB;

  while (sortItersB <= sortItersE && sorted) {
    check_pair = *sortItersB;
    if (check_pair.first < tmp_pair.first) {
      sorted = false;
    }
    tmp_pair = check_pair;
    ++sortItersB;
  }

  ASSERT_TRUE(sorted);

  ASSERT_EQ(KalaInit.at(1), 2);

  KalaInit.insert_or_assign(std::make_pair(1, 6));

  ASSERT_EQ(KalaInit.at(1), 6);

  pair_1 = std::make_pair(102, 6);
  pair_2 = std::make_pair(23, 2);
  pair_3 = std::make_pair(76, 546);
  pair_4 = std::make_pair(50, 1);
  pair_5 = std::make_pair(150, 5);

  Map<int, int> KalaToMerge = {pair_1, pair_2, pair_3, pair_4, pair_5};

  KalaInit.merge(KalaToMerge);

  ASSERT_EQ(KalaInit.size(), 13);
  ASSERT_EQ(KalaInit.max_size(), 13);

  ASSERT_TRUE(KalaSorted.empty());

  Vector<std::pair<Map<int, int>::MapIterator, bool>> Kod(
      KalaSorted.emplace_back(pair_2, pair_1, pair_3));

  auto iterMap = KalaSorted.begin();
  auto iterVector = Kod.begin();
  auto iter_iter = *iterVector;

  ASSERT_EQ(pair_2, *iterMap);
  ASSERT_EQ(*iterMap, *iter_iter.first);

  ++iterMap;
  ++iterVector;
  ++iterVector;

  iter_iter = *iterVector;

  ASSERT_EQ(pair_3, *iterMap);
  ASSERT_EQ(*iterMap, *iter_iter.first);

  ++iterMap;
  --iterVector;

  iter_iter = *iterVector;

  ASSERT_EQ(pair_1, *iterMap);
  ASSERT_EQ(*iterMap, *iter_iter.first);

  // KalaInit.CheckSorted();
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
