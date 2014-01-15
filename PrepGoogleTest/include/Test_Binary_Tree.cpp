/* Copyright 2014 Laurie Chan-Lam */

#include <gtest/gtest.h>
#include <vector>
#include "../../PrepGoogleLib/include/BinaryTree.h"
#include "./Util.h"

TEST(Binary_Tree, Empty) {
}

TEST(Binary_Tree, LeftSide) {
  BinaryTree tree;
  for (int i = 9; i >= 0; --i)
    tree.insert(2*i);
  std::vector<int> sorted = tree.sort();
  EXPECT_EQ(10, sorted.size());
  for (int i = 0; i < 10; ++i)
    EXPECT_EQ(2*i, sorted[i]);
  for (int i = 0; i < 10; ++i) {
    EXPECT_TRUE(tree.suppress(2*i));
    EXPECT_FALSE(tree.suppress(2*i+1));
  }
}

TEST(Binary_Tree, RightSide) {
  BinaryTree tree;
  for (int i = 0; i < 10; ++i)
    tree.insert(i);
  std::vector<int> sorted = tree.sort();
  EXPECT_EQ(10, sorted.size());
  for (int i = 0; i < 10; ++i)
    EXPECT_EQ(i, sorted[i]);
  for (int i = 0; i < 10; ++i)
    EXPECT_TRUE(tree.suppress(i));
}

TEST(Binary_Tree, Random) {
  BinaryTree tree;

  for (int i = 0; i < 500; ++i)
    tree.insert(rand() % 1000);  // NOLINT: rand is ok, no multi-threading
  std::vector<int> sorted = tree.sort();
  EXPECT_EQ(500, sorted.size());
  for (int i = 1; i < 500; ++i)
    EXPECT_LE(sorted[i - 1], sorted[i]);
  size_t n = 500;
  while (!sorted.empty()) {
    EXPECT_EQ(n, sorted.size());
    if (n != sorted.size())
      break;
    tree.suppress(sorted.back());
    sorted = tree.sort();
    --n;
  }
  EXPECT_TRUE(tree.empty());
}
