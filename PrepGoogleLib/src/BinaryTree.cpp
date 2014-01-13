/* Copyright 2014 Laurie Chan-Lam */
#include "./BinaryTree.h"
#include <stack>


BinaryTree::BinaryTree(int key) {
  key_ = key;
  left_child_ = NULL;
  right_child_ = NULL;
}

BinaryTree::~BinaryTree() {
  //if (left_child_ != NULL)
  //  delete left_child_;
  //if (right_child_ != NULL)
  //  delete right_child_;
}


void BinaryTree::insert(int key) {
  BinaryTree *parent = this;
  BinaryTree *node = this;
  while (node) {
    parent = node;
    if (node->key_ > key)
      node = node->left_child_;
    else
      node = node->right_child_;
  }

  BinaryTree *new_node = new BinaryTree(key);
  if (parent->key_ > key)
    parent->left_child_= new_node;
  else
    parent->right_child_ = new_node;
}


bool BinaryTree::suppress(int key) {
  BinaryTree *node = const_cast<BinaryTree *>(find(key));
  if (node == NULL)
    return false;

  if (node->left_child_ == NULL) {
    if (node->right_child_ == NULL) {
      delete node;
      node = NULL;
    } else {
      BinaryTree *right_child = node->right_child_;
      delete node;
      node = right_child;
    }
  } else {
    BinaryTree *left_child = node->left_child_;
    delete node;
    node = left_child;
  }
  return true;
}


const BinaryTree *BinaryTree::find(int key) const {
  const BinaryTree *node = this;
  while (node) {
    if (node->key_ == key)
      return node;
    node = (node->key_ > key)
      ? node->left_child_
      : node->right_child_;
  }
  return node;
}


std::vector<int> BinaryTree::sort() const {
  std::vector<int> sorted;
  std::stack<const BinaryTree *> todo;
  todo.push(this);
  const BinaryTree *node = this;
  while (!todo.empty() || node != NULL) {
    if (node != NULL) {
      todo.push(node);
      node = node->left_child_;
    } else {
      node = todo.top();
      todo.pop();
      sorted.push_back(node->key_);
      node = node->right_child_;
    }
  }
  return sorted;
}
