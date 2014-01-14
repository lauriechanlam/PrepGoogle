/* Copyright 2014 Laurie Chan-Lam */
#include "./BinaryTree.h"
#include <stack>
#include <vector>


BinaryTreeNode::BinaryTreeNode(int value) {
  key = value;
  left_child = NULL;
  right_child = NULL;
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
  std::shared_ptr<BinaryTreeNode> parent = node_;
  std::shared_ptr<BinaryTreeNode> node = node_;
  bool is_left_child = true;
  while (node) {
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

  if (node == node_) {
    node.reset();  // Actually erasing the wanted node
    if (left != NULL) {
      node_ = left;
      while (left->right_child != NULL)
        left = left->right_child;
      left->right_child = right;
    } else if (right != NULL) {
      node_ = right;
    }
  } else {  // node != node_, we do not need to erase the root
    node.reset();  // Actually erasing the wanted node
    if (left != NULL) {
      if (is_left_child)
        parent->left_child = left;
      else
        parent->right_child = left;
      while (left->right_child != NULL)
        left = left->right_child;
      left->right_child = right;
    } else if (right != NULL) {
      if (is_left_child)
        parent->left_child = right;
      else
        parent->right_child = right;
    }
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
