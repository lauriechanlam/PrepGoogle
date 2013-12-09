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
	if (child_left_ != NULL)
		child_left_->write(std::string("  ")+prefix);

	std::cout << prefix << key_ << std::endl;

	if (child_right_ != NULL)
		child_right_->write(std::string("  ")+prefix);
}

bool BinaryTree::insert(int value) {
	BinaryTree *root = this;

	while (root != NULL) {
		if (value <= root->key_)
			root = root->child_left_;
		else
			root = root->child_right_;
	}

	root = new BinaryTree(value);
	return true;
}
void BinaryTree::sort() {
	/* You just need to read the tree in order */
	std::vector<int> table;

	BinaryTree* parent = NULL;
	BinaryTree* root = this;

	while (root != NULL) {
		if (root->child_left_ != NULL) {
			parent = root;
			root = root->child_left_;
		}
	}

	sort(child_right_,table);
	
}

bool BinaryTree::suppress(int value) {
	return false;
}

int BinaryTree::find(int value) {
	return -1;
}
