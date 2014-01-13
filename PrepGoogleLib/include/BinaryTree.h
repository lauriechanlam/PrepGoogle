/* Copyright 2014 Laurie Chan-Lam */
#ifndef PREPGOOGLE_BINARYTREE_H_
#define PREPGOOGLE_BINARYTREE_H_

#include <vector>

class BinaryTree {
 public:
  BinaryTree(int key);
  ~BinaryTree();
  virtual void insert(int key);
  virtual bool suppress(int key);
  virtual const BinaryTree *find(int key) const;
  virtual std::vector<int> sort() const;
 private:
   int key_;
   BinaryTree *left_child_;
   BinaryTree *right_child_;
};

#endif  // PREPGOOGLE_BINARYTREE_H_
