/* Copyright 2014 Laurie Chan-Lam */
#ifndef PREPGOOGLE_HEAP_H_
#define PREPGOOGLE_HEAP_H_

#include <vector>

class Heap {
 public:
  Heap();
  void write(const char *filename) const;
  void read(const char *filename);
  void insert(int value);
  bool suppress(int value);
  void sort();
  void heapify();
  bool is_sorted() const;
  bool is_heap() const;

 private:
  int parent(int index) const;
  int left_child(int index) const;
  int right_child(int index) const;

  std::vector<int> table_;
  bool is_sorted_;
  bool is_heap_;
};

#endif  // PREPGOOGLE_HEAP_H_
