//
// Created by Emery Reva on 3/21/22.
//

#include <gtest/gtest.h>

#include <vector>

#include "vector.h"

using namespace s21;

TEST(Vector, basic) {
  Vector<int> Kala;

  //  Emptiness check

  ASSERT_EQ(Kala.size(), 0);
  ASSERT_EQ(Kala.max_size(), 0);
  ASSERT_TRUE(Kala.empty());

  // ASSERT_EQ(Kala.front(), 0);
  // ASSERT_EQ(Kala.back(), 0);

  //  Push check

  Kala.push_back(3);

  ASSERT_EQ(Kala.front(), 3);
  ASSERT_EQ(Kala.back(), 3);

  Kala.push_back(5);

  ASSERT_EQ(Kala.front(), 3);
  ASSERT_EQ(Kala.back(), 5);

  //  Pop check

  Kala.pop_back();

  ASSERT_EQ(Kala.front(), 3);
  ASSERT_EQ(Kala.back(), 3);

  //  Memory allocation check

  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);
  Kala.push_back(3);

  ASSERT_EQ(Kala.size(), 10);
  ASSERT_EQ(Kala.max_size(), 10);

  //  Shrink_to_fit_check

  Kala.pop_back();
  Kala.pop_back();
  Kala.pop_back();
  Kala.pop_back();

  ASSERT_EQ(Kala.size(), 6);
  ASSERT_EQ(Kala.max_size(), 10);
  ASSERT_EQ(Kala.capacity(), 4);

  Kala.push_back(3);
  ASSERT_EQ(Kala.size(), 7);
  ASSERT_EQ(Kala.max_size(), 10);
  ASSERT_EQ(Kala.capacity(), 3);

  Kala.shrink_to_fit();

  ASSERT_EQ(Kala.size(), 7);
  ASSERT_EQ(Kala.max_size(), 7);

  //  Reserve check

  Kala.reserve(50);

  ASSERT_EQ(Kala.size(), 7);
  ASSERT_EQ(Kala.max_size(), 57);

  Kala.push_back(9);
  ASSERT_EQ(Kala.size(), 8);
  ASSERT_EQ(Kala.max_size(), 57);
  ASSERT_EQ(Kala.capacity(), 49);
  ASSERT_EQ(Kala.back(), 9);

  //  Parametrized size constructor check

  Vector<int> KalaSize(15);

  ASSERT_EQ(KalaSize.size(), 0);
  ASSERT_EQ(KalaSize.max_size(), 15);

  KalaSize.push_back(3);
  KalaSize.push_back(6);
  KalaSize.push_back(7);

  ASSERT_EQ(KalaSize.front(), 3);
  ASSERT_EQ(KalaSize.back(), 7);

  Vector<int> KalaEmpty;

  KalaSize.swap(KalaEmpty);

  ASSERT_EQ(KalaEmpty.size(), 3);
  ASSERT_EQ(KalaEmpty.max_size(), 15);
  ASSERT_EQ(KalaEmpty.front(), 3);
  ASSERT_EQ(KalaEmpty.back(), 7);

  ASSERT_EQ(KalaSize.size(), 0);
  ASSERT_EQ(KalaSize.max_size(), 0);

  //  Copy constructor check

  Vector<int> KalaCopied(KalaEmpty);

  ASSERT_EQ(KalaCopied.size(), 3);
  ASSERT_EQ(KalaCopied.max_size(), 15);
  ASSERT_EQ(KalaCopied.front(), 3);
  ASSERT_EQ(KalaCopied.back(), 7);

  //  Initialize constructor check

  Vector<int> KalaInit = {1, 7, 2, 8, 9};

  ASSERT_EQ(KalaInit.size(), 5);
  ASSERT_EQ(KalaInit.max_size(), 5);
  ASSERT_EQ(KalaInit.front(), 1);
  ASSERT_EQ(KalaInit.back(), 9);

  //  Move constructor check

  Vector<int> KalaMoved(std::move(KalaInit));

  ASSERT_EQ(KalaMoved.size(), 5);
  ASSERT_EQ(KalaMoved.max_size(), 5);
  ASSERT_EQ(KalaMoved.front(), 1);
  ASSERT_EQ(KalaMoved.back(), 9);

  ASSERT_EQ(KalaInit.size(), 0);
  ASSERT_EQ(KalaInit.max_size(), 0);
  ASSERT_TRUE(KalaInit.empty());

  // ASSERT_EQ(KalaInit.front(), 0);
  // ASSERT_EQ(KalaInit.back(), 0);

  //  Erase check

  Vector<int>::VectorIterator iter(KalaMoved.begin());

  ASSERT_EQ(KalaMoved.at(2), 2);
  ASSERT_EQ(KalaMoved[1], 7);

  KalaMoved.erase(iter);

  ASSERT_EQ(KalaMoved.at(2), 8);
  ASSERT_EQ(KalaMoved[1], 2);

  iter.Advance(2);

  ASSERT_EQ(iter.GetPosition(), 2);
  ASSERT_EQ(*iter, 8);

  KalaMoved.erase(iter);

  ASSERT_EQ(*iter, 9);
  ASSERT_EQ(KalaMoved.size(), 3);
  ASSERT_EQ(KalaMoved.max_size(), 5);
  ASSERT_EQ(KalaMoved.front(), 7);
  ASSERT_EQ(KalaMoved.back(), 9);

  //  Insert check

  int ins = 8;
  iter = KalaMoved.insert(iter, ins);
  ASSERT_EQ(iter.GetPosition(), 2);
  ASSERT_EQ(*iter, 8);

  ASSERT_EQ(KalaMoved.size(), 4);
  ASSERT_EQ(KalaMoved.max_size(), 5);
  ASSERT_EQ(KalaMoved.front(), 7);
  ASSERT_EQ(KalaMoved.back(), 9);

  //  Clear check

  KalaCopied.clear();

  ASSERT_EQ(KalaCopied.size(), 0);
  ASSERT_EQ(KalaCopied.max_size(), 0);

  KalaCopied.emplace_back(6, 7, 15, 3);

  ASSERT_EQ(KalaCopied.front(), 6);
  ASSERT_EQ(KalaCopied.back(), 3);

  auto it = KalaCopied.begin();

  it.Advance(2);

  ASSERT_EQ(*it, 15);

  auto new_it = KalaCopied.emplace(it, 5, 13);

  auto check_it = KalaCopied.begin();

  check_it.Advance(2);

  ASSERT_EQ(*check_it, 13);

  check_it.Advance(1);

  ASSERT_EQ(*check_it, 5);

  check_it.Advance(1);

  ASSERT_EQ(*check_it, 15);

  ASSERT_EQ(*new_it, 13);

  Vector<int[5]> ooo{};
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
