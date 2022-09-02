//
// Created by Emery Reva on 3/21/22.
//

#include <gtest/gtest.h>

#include "containerAdaptor.h"

using namespace s21;

TEST(Stack, basic) {
  Stack<int> Kala;
  int k = 5;

  //  empty and size test

  ASSERT_EQ(true, Kala.empty());
  ASSERT_EQ(0, Kala.size());

  //  push and top test

  Kala.push(k);
  ASSERT_EQ(k, Kala.top());
  k = 6;
  Kala.push(k);
  ASSERT_EQ(k, Kala.top());

  Kala.top() = 11;
  ASSERT_EQ(11, Kala.top());

  int& c = Kala.top();
  c = 3;

  ASSERT_EQ(c, Kala.top());

  //  pop test

  Kala.pop();
  ASSERT_EQ(5, Kala.top());

  //  memory test allocation test

  k = 3;
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
  Stack<int> Kala1;
  Kala1.swap(Kala);

  ASSERT_EQ(false, Kala1.empty());
  ASSERT_EQ(7, Kala1.size());
  ASSERT_EQ(3, Kala1.top());

  ASSERT_EQ(true, Kala.empty());
  ASSERT_EQ(0, Kala.size());

  //  move constructor test

  Stack<int> Kala2(std::move(Kala1));

  ASSERT_EQ(false, Kala2.empty());
  ASSERT_EQ(7, Kala2.size());
  ASSERT_EQ(3, Kala2.top());

  ASSERT_EQ(true, Kala1.empty());
  ASSERT_EQ(0, Kala1.size());

  //  copy constructor test

  Stack<int> Kala4(Kala2);

  ASSERT_EQ(false, Kala4.empty());
  ASSERT_EQ(7, Kala4.size());
  ASSERT_EQ(3, Kala4.top());

  //  initialize constructor test

  Stack<int> KalaInit = {1, 5, 4, 3};
  ASSERT_EQ(false, KalaInit.empty());
  ASSERT_EQ(4, KalaInit.size());
  ASSERT_EQ(3, KalaInit.top());

  Stack<int> KalaBad = {};
  ASSERT_EQ(true, KalaBad.empty());
  ASSERT_EQ(0, KalaBad.size());

  //  Operator = test

  Stack<int> Moved(std::move(KalaInit));

  ASSERT_EQ(false, Moved.empty());
  ASSERT_EQ(4, Moved.size());
  ASSERT_EQ(3, Moved.top());

  Moved.emplace_front(1, 6, 8, 1, 4);

  ASSERT_EQ(9, Moved.size());
  ASSERT_EQ(4, Moved.top());
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
