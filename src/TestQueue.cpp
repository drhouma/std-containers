//
// Created by Emery Reva on 3/21/22.
//

#include <gtest/gtest.h>

#include "containerAdaptor.h"

using namespace s21;

TEST(Queue, basic) {
  Queue<int> Kala;
  int k = 5;

  //  empty and size test

  ASSERT_EQ(true, Kala.empty());
  ASSERT_EQ(0, Kala.size());

  //  push and top test

  Kala.push(k);
  ASSERT_EQ(k, Kala.back());
  k = 6;
  Kala.push(k);
  ASSERT_EQ(k, Kala.back());

  Kala.back() = 11;
  ASSERT_EQ(11, Kala.back());

  int& c = Kala.back();
  c = 3;

  ASSERT_EQ(c, Kala.back());

  ASSERT_EQ(5, Kala.front());

  Kala.front() = 11;
  ASSERT_EQ(11, Kala.front());

  int& d = Kala.front();
  d = 4;

  ASSERT_EQ(d, Kala.front());

  //  pop test
  ASSERT_EQ(3, Kala.back());
  Kala.pop();
  ASSERT_EQ(3, Kala.front());
  ASSERT_EQ(3, Kala.back());

  //  memory test allocation test

  k = 4;

  Kala.push(k);
  Kala.push(k);
  Kala.push(k);
  Kala.push(k);
  Kala.push(k);
  Kala.push(k);

  //  empty and size test

  ASSERT_EQ(false, Kala.empty());
  ASSERT_EQ(7, Kala.size());

  //  swap test
  Queue<int> Kala1;
  Kala1.swap(Kala);

  ASSERT_EQ(false, Kala1.empty());
  ASSERT_EQ(7, Kala1.size());
  ASSERT_EQ(4, Kala1.back());

  ASSERT_EQ(true, Kala.empty());
  ASSERT_EQ(0, Kala.size());

  //  move constructor test

  Queue<int> Kala2(std::move(Kala1));

  ASSERT_EQ(false, Kala2.empty());
  ASSERT_EQ(7, Kala2.size());
  ASSERT_EQ(4, Kala2.back());

  ASSERT_EQ(true, Kala1.empty());
  ASSERT_EQ(0, Kala1.size());

  //  copy constructor test

  Queue<int> Kala4(Kala2);

  ASSERT_EQ(false, Kala4.empty());
  ASSERT_EQ(7, Kala4.size());
  ASSERT_EQ(4, Kala4.back());

  //  initialize constructor test

  Queue<int> KalaInit = {1, 2, 4, 5};
  ASSERT_EQ(false, KalaInit.empty());
  ASSERT_EQ(4, KalaInit.size());
  ASSERT_EQ(5, KalaInit.back());
  ASSERT_EQ(1, KalaInit.front());

  Queue<int> KalaBad = {};
  ASSERT_EQ(true, KalaBad.empty());
  ASSERT_EQ(0, KalaBad.size());

  //  emplace methods

  KalaBad.emplace_back(6, 4, 3, 2);

  ASSERT_EQ(2, KalaBad.back());
  ASSERT_EQ(6, KalaBad.front());

  //  Operator = test

  Queue<int> Moved(std::move(KalaInit));

  ASSERT_EQ(false, Moved.empty());
  ASSERT_EQ(4, Moved.size());
  ASSERT_EQ(5, Moved.back());
  ASSERT_EQ(1, Moved.front());
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
