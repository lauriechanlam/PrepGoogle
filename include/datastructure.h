#ifndef PREP_GOOGLE_DATASTRUCTURE_H
#define PREP_GOOGLE_DATASTRUCTURE_H

const int MAX_NUM_ELEMENTS = 100;

class DataInterface {
public:
	DataInterface();
	virtual void write() const = 0;
    virtual bool insert(int value) = 0;
    virtual void sort() = 0;
    virtual bool suppress(int value) = 0;
};

class TableInterface: public DataInterface {
public:
    TableInterface();
	virtual void write() const;
    virtual bool insert(int value);
    virtual bool suppress(int value);
    virtual int find(int value);
protected:
    int table_[MAX_NUM_ELEMENTS];
    int num_elements_;
};

#endif // PREP_GOOGLE_DATASTRUCTURE_H
