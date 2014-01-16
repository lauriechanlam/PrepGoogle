/* Copyright 2014 Laurie Chan-Lam */
#include "./BinaryTree.h"
#include <stack>
#include <vector>


BinaryTreeNode::BinaryTreeNode(int value) {
  key = value;
  left_child = NULL;
  right_child = NULL;
}


bool BinaryTree::empty() const {
  return node_ == NULL;
}


void BinaryTree::insert(int key) {
  if (node_ == NULL) {
    node_.reset(new BinaryTreeNode(key));
    return;
  }

  std::shared_ptr<BinaryTreeNode> parent = node_;
  std::shared_ptr<BinaryTreeNode> node = node_;
  while (node != NULL) {
    parent = node;
    if (node->key > key)
      node = node->left_child;
    else
      node = node->right_child;
  }

  std::shared_ptr<BinaryTreeNode> new_node =
    std::shared_ptr<BinaryTreeNode>(new BinaryTreeNode(key));
  if (parent->key > key)
    parent->left_child = new_node;
  else
    parent->right_child = new_node;
}


bool BinaryTree::suppress(int key) {
  std::shared_ptr<BinaryTreeNode> parent = NULL;
  std::shared_ptr<BinaryTreeNode> node = node_;
  bool is_left_child = true;
  while (node != NULL) {
    if (node->key == key)
      break;
    parent = node;
    is_left_child = (node->key > key);
    node = is_left_child
      ? node->left_child
      : node->right_child;
  }
  if (node == NULL)
    return false;

  std::shared_ptr<BinaryTreeNode> left = node->left_child;
  std::shared_ptr<BinaryTreeNode> right = node->right_child;

  if (left != NULL) {
    if (left->right_child == NULL) {  // simply by-pass
      if (parent != NULL)
        parent->left_child = left;
      else
        node_ = left;
    } else {
      parent = node;
      while (left->right_child != NULL) {
        parent = left;
        left = left->right_child;
      }
      node->key = left->key;
      parent->right_child = NULL;
    }
  } else if (right != NULL) {
    if (right->left_child == NULL) {
      if (parent != NULL)
        parent->right_child = right;
      else
        node_ = right;
    } else {
      parent = node;
      while (right->left_child != NULL) {
        parent = right;
        right = right->left_child;
      }
      node->key = right->key;
      parent->left_child = NULL;
    }
  } else {
    if (parent == NULL)
      node_ = NULL;
    else if (parent->left_child == node)
      parent->left_child = NULL;
    else
      parent->right_child = NULL;
  }

  return true;
}


std::shared_ptr<BinaryTreeNode> BinaryTree::find(int key) const {
  std::shared_ptr<BinaryTreeNode> node = node_;
  while (node) {
    if (node->key == key)
      return node;
    node = (node->key > key)
      ? node->left_child
      : node->right_child;
  }
  return node;
}


std::vector<int> BinaryTree::sort() const {
  std::vector<int> sorted;
  std::stack<const std::shared_ptr<BinaryTreeNode>> todo;
  std::shared_ptr<BinaryTreeNode> node = node_;
  while (!todo.empty() || node != NULL) {
    if (node != NULL) {
      todo.push(node);
      node = node->left_child;
    } else {
      node = todo.top();
      todo.pop();
      sorted.push_back(node->key);
      node = node->right_child;
    }
  }
  return sorted;
}
