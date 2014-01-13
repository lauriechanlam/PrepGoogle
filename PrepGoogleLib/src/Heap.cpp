/* Copyright 2014 Laurie Chan-Lam */
#include "./Heap.h"
#include <cassert>
#include <algorithm>
#include <vector>


Heap::Heap() {
  is_sorted_ = true;
  is_heap_ = true;
}


void Heap::read(const char *filename) {
#ifdef _WIN32
  FILE *fid;
  fopen_s(&fid, filename, "rb");
#else
  FILE *fid = fopen(filename, "rb");
#endif
  int size;
  fread(&size, sizeof(int), 1, fid);
  table_.resize(size);
  fread(&table_[0], sizeof(int), size, fid);
  fclose(fid);
  is_sorted_ = false;
  is_heap_ = false;
}


void Heap::write(const char *filename) const {
#ifdef _WIN32
  FILE *fid;
  fopen_s(&fid, filename, "wb");
#else
  FILE *fid = fopen(filename, "wb");
#endif
  int size = static_cast<int>(table_.size());
  fwrite(&size, sizeof(int), 1, fid);
  fwrite(&table_[0], sizeof(int), table_.size(), fid);
  fclose(fid);
}


void Heap::insert(int value) {
  table_.push_back(value);
  is_sorted_ = false;
  is_heap_ = false;
}


bool Heap::suppress(int value) {
  /* Treat corner cases */
  if (table_.empty())
    return false;
  if (table_.size() == 1) {
    if (table_[0] == value) {
      table_.clear();
      return true;
    } else {
      return false;
    }
  }

  /* Usual case */
  if (!is_sorted_) {
    heapify();
    sort();
  }
  for (std::vector<int>::iterator it = table_.begin();
    it != table_.end(); ++it) {
    if (*it == value) {
      table_.erase(it, it + 1);
      return true;
    }
    if (*it > value)
      return false;
  }
  return true;  // In order to avoid warning, will never be called
}


void Heap::sort() {
  if (is_sorted_)
    return;

  heapify();
  is_sorted_ = true;

  int num_elts = static_cast<int>(table_.size());
  if (num_elts < 2)
    return;

  for (int N = num_elts - 1; N > 0; --N) {
    std::swap(table_[0], table_[N]);

    int index = 0;
    while (left_child(index) < N) {
      int left  = left_child(index);
      int right = right_child(index);
      int child = index;
      if (table_[child] < table_[left])
        child = left;
      if (right < N && table_[child] < table_[right])
        child = right;
      if (child == index)
        break;
      std::swap(table_[index], table_[child]);
      index = child;
    }
  }  // for N
}



/* Heapify:
It consists of making a heap of [0, N-1] adding a value at each iteration.
If [0, N-1] is a heap, then, in order to make a heap out of [0, N], we need to
swap N with his father if he is bigger and iterate taht to the top of the heap.
*/
void Heap::heapify() {
  if (is_heap_)
    return;
  is_heap_ = true;
  int num_elts = static_cast<int>(table_.size());

  if (num_elts < 2)
    return;

  for (int N = 1; N < num_elts; ++N) {
    int index = N;
    while (index > 0 && table_[index] > table_[parent(index)]) {
      std::swap(table_[index], table_[parent(index)]);
      index = parent(index);
    }
  }
}


bool Heap::is_sorted() const {
  int num_elts = static_cast<int>(table_.size());
  if (num_elts < 2)
    return true;
  for (int index = 1; index < num_elts; ++index)
    if (table_[index - 1] > table_[index])
      return false;
  return true;
}


bool Heap::is_heap() const {
  int num_elts = static_cast<int>(table_.size());
  if (num_elts < 2)
    return true;
  for (int index = 1; index < num_elts; ++index)
    if (table_[index] > table_[parent(index)])
      return false;
  return true;
}


int Heap::parent(int index) const {
  return (index - 1) >> 1;
}


int Heap::left_child(int index) const {
  return (index << 1) | 1;
}


int Heap::right_child(int index) const {
  return (index << 1) + 2;
}
