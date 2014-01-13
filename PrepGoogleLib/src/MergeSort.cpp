/* Copyright 2014 Laurie Chan-Lam */
#include "./MergeSort.h"
#include <algorithm>
#include <vector>


void merge(int *table, int start, int middle, int end) {
  /* Merge results */
  std::vector<int> out;
  out.reserve(end - start);

  int index_left = start;
  int index_right = middle;

  while (index_left < middle && index_right < end) {
    if (table[index_left] < table[index_right]) {
      out.push_back(table[index_left]);
      ++index_left;
    } else {
      out.push_back(table[index_right]);
      ++index_right;
    }
  }

  while (index_left < middle)
    out.push_back(table[index_left++]);
  while (index_right < end)
    out.push_back(table[index_right++]);

  memcpy(&(table[start]), &(out[0]), (end - start)*sizeof(int));
}


void merge_sort(int *table, int num_elts) {
  if (num_elts < 2)
    return;

  for (int size = 1; size <= num_elts; size <<= 1) {
    for (int start = 0; start < num_elts; start += 2 * size) {
      merge(table, start, start + size, std::min(start + 2 * size, num_elts));
    }
  }
}

