/* Copyright 2014 Laurie Chan-Lam */
#ifndef PREPGOOGLE_BINARYTREE_H_
#define PREPGOOGLE_BINARYTREE_H_

#include <vector>
#include <memory>

struct BinaryTreeNode {
  explicit BinaryTreeNode(int value);
  int key;
  std::shared_ptr<BinaryTreeNode> left_child;
  std::shared_ptr<BinaryTreeNode> right_child;
};

class BinaryTree {
 public:
  virtual void insert(int key);
  virtual bool suppress(int key);
  virtual std::shared_ptr<BinaryTreeNode> find(int key) const;
  virtual std::vector<int> sort() const;
 private:
  std::shared_ptr<BinaryTreeNode> node_;
};

#endif  // PREPGOOGLE_BINARYTREE_H_
