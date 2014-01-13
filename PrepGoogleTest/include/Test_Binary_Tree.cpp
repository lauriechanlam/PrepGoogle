/* Copyright 2014 Laurie Chan-Lam */

#include <gtest/gtest.h>
#include <vector>
#include "../../PrepGoogleLib/include/BinaryTree.h"
#include "./Util.h"

TEST(Binary_Tree, Empty) {
}

TEST(Binary_Tree, LeftSide) {
  BinaryTree *tree = new BinaryTree(10);
  for (int i = 9; i > 0; --i)
    tree->insert(i);
  std::vector<int> sorted = tree->sort();
  EXPECT_EQ(10, sorted.size());
  for (int i = 0; i < 10; ++i)
    EXPECT_EQ(i + 1, sorted[i]);
  for (int i = 0; i < 10; ++i)
    EXPECT_TRUE(tree->suppress(i));
  delete tree;
}

TEST(Binary_Tree, RightSide) {
  BinaryTree *tree = new BinaryTree(0);
  for (int i = 1; i < 10; ++i)
    tree->insert(i);
  std::vector<int> sorted = tree->sort();
  for (int i = 0; i < 10; ++i)
    EXPECT_EQ(i + 1, sorted[i]);
  for (int i = 0; i < 10; ++i)
    EXPECT_TRUE(tree->suppress(i));
  delete tree;
}

TEST(Binary_Tree, Random) {
  BinaryTree *tree = new BinaryTree(rand() % 1000);
  for (int i = 0; i < 499; ++i)
    tree->insert(rand() % 1000);  // NOLINT: rand is ok, no multi-threading
  std::vector<int> sorted = tree->sort();
  EXPECT_EQ(500, sorted.size());
  bool test = true;
  for (int i = 1; i < 500; ++i) {
    test = sorted[i - 1] <= sorted[i];
    EXPECT_TRUE(test);
    if (!test)
      break;
  }
  if (!test) {
#ifdef _WIN32
    FILE *fid;
    fopen_s(&fid, "store_binarytree.txt", "wb");
#else
    FILE *fid = fopen("store_binarytree.txt", "wb");
#endif
    int size = static_cast<int>(sorted.size());
    fwrite(&size, sizeof(int), 1, fid);
    fwrite(&sorted[0], sizeof(int), size, fid);
    fclose(fid);
  }
}
