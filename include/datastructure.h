#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

const int MAX_NUM_ELEMENTS = 100;

class DataStructure
{
public:
    DataStructure();
    virtual bool insert(int value) = 0;
    virtual void sort() = 0;
    virtual bool suppress(int value) = 0;
    virtual int find(int value) = 0;
protected:
    int table_[MAX_NUM_ELEMENTS];
    int num_elements_;
};

#endif // DATASTRUCTURE_H
