#ifndef PREP_GOOGLE_MERGESORT_H
#define PREP_GOOGLE_MERGESORT_H

#include "datastructure.h"

class MergeSortTable : public DataStructure
{
public:
	MergeSortTable();
	void sort();
private:
	void merge(int start, int middle, int end); /* Merges two sorted partial arrays, [start, middle[ and [middle, end[ */
};

#endif