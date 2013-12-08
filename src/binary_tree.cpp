#include <algorithm>
#include <iostream>
#include "binary_tree.h"

BinaryTree::BinaryTree(int value):
	DataInterface(),
	key_(value),
	child_left_(NULL),
	child_right_(NULL) {
}

void BinaryTree::write() const {
	this->write("");
}

void BinaryTree::write(std::string prefix) const {
	

	if (child_left_ != NULL) {
		child_left_->write(std::string("  ")+prefix);
	}

	std::cout << prefix << key_ << std::endl;

	if (child_right_ != NULL) {
		child_right_->write(std::string("  ")+prefix);
	}
}

bool BinaryTree::insert(int value) {
	if (value <= key_) {
		if (child_left_ != NULL) {
			child_left_->insert(value);
			return true;
		}
		child_left_ = new BinaryTree(value);
		return true;
	}
	if (child_right_ != NULL) {
		child_right_->insert(value);
		return true;
	}
	child_right_ = new BinaryTree(value);
	return true;
}
//void BinaryTree::sort() = 0;
//bool BinaryTree::suppress(int value) = 0;
//int BinaryTree::find(int value) = 0;
