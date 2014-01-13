/* Copyright 2014 Laurie Chan-Lam */
#include "./QuickSort.h"
#include <stack>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>

int partition(int *table, int start, int end) {
  assert(end - start > 1);
  int pivot = table[start];
  int i = start + 1;
  int j = end - 1;
  while (i <= j) {
    if (table[i] <= pivot) {
      ++i;
    } else if (table[j] > pivot) {
      --j;
    } else {
      std::swap(table[i], table[j]);
      i++;
      --j;
    }
  }

  if (i == start + 1)
    return start;

  if (j == end - 1) {
    std::swap(table[start], table[j]);
    return j;
  }

  if (i - j == 1) {
    std::swap(table[start], table[j]);
    return j;
  }

  assert(false);
  return i;
}

void quick_sort(int *table, int num_elts) {
  if (num_elts < 2)
    return;
  std::stack<std::pair<int, int>> todo;
  todo.push(std::pair<int, int>(0, num_elts));
  while (!todo.empty()) {
    std::pair<int, int> task = todo.top();
    todo.pop();
    int middle = partition(table, task.first, task.second);
    if (middle - task.first > 1)
      todo.push(std::pair<int, int>(task.first, middle));
    if (task.second - middle > 2)
      todo.push(std::pair<int, int>(middle + 1, task.second));
  }
}
