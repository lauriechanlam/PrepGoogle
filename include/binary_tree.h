#ifndef PREP_GOOGLE_BINARY_TREE
#define PREP_GOOGLE_BINARY_TREE

#include <string>
#include "datastructure.h"

class BinaryTree: public DataInterface {
public:
	BinaryTree(int value);
	virtual void write() const;
    virtual bool insert(int value);
	virtual void sort(){};
	virtual bool suppress(int value){return false;};
	virtual int find(int value){return -1;};
protected:
	void write(std::string prefix) const;
	int key_;
	BinaryTree* child_left_;
	BinaryTree* child_right_;
};


#endif