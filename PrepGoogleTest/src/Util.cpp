/* Copyright 2014 Laurie Chan-Lam */
#include "./Util.h"


bool is_sorted(const int *table, int num_elts) {
  for (int index = 1; index < num_elts; ++index)
  if (table[index] < table[index - 1])
    return false;
  return true;
}
