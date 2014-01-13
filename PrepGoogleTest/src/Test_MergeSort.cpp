/* Copyright 2014 Laurie Chan-Lam */

#include <gtest/gtest.h>
#include <vector>
#include "../../PrepGoogleLib/include/MergeSort.h"
#include "./Util.h"

TEST(MergeSort, Empty) {
  int *table = NULL;
  merge_sort(table, 0);
  EXPECT_TRUE(is_sorted(table, 0));
}

TEST(MergeSort, Sorted) {
  std::vector<int> table(10);
  for (int i = 0; i < 10; ++i)
    table[i] = i;
  merge_sort(&table[0], 10);
  EXPECT_TRUE(is_sorted(&table[0], 10));
}

TEST(MergeSort, ReverseSorted) {
  std::vector<int> table(10);
  for (int i = 0; i < 10; ++i)
    table[i] = 10 - i;
  merge_sort(&table[0], 10);
  EXPECT_TRUE(is_sorted(&table[0], 10));
}

TEST(MergeSort, Random) {
  std::vector<int> table(500);
  for (int i = 0; i < 500; ++i)
    table[i] = rand() % 1000;  // NOLINT: rand is ok, no multi-threading
  std::vector<int> table_copy = table;
  merge_sort(&table[0], 500);
  bool test = is_sorted(&table[0], 500);
  EXPECT_TRUE(test);
  if (!test) {
#ifdef _WIN32
    FILE *fid;
    fopen_s(&fid, "store_mergesort.txt", "wb");
#else
    FILE *fid = fopen("store_mergesort.txt", "wb");
#endif
    int size = static_cast<int>(table.size());
    fwrite(&size, sizeof(int), 1, fid);
    fwrite(&table[0], sizeof(int), size, fid);
    fclose(fid);
  }
}
