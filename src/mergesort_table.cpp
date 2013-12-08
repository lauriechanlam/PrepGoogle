#include <math.h>
#include <vector>
#include "mergesort_table.h"


MergeSortTable::MergeSortTable(): TableInterface() {
}

void MergeSortTable::sort() {
	if (num_elements_ < 2)
		return;

	for (int size = 1; size <= num_elements_; size <<= 1) {
		for (int start = 0; start < num_elements_; start += 2*size) {
			merge(start, start + size, std::min(start + 2*size, num_elements_));
		}
	}
}


void MergeSortTable::merge(int start, int middle, int end) {
	/* Merge results */
	std::vector<int> out;
	out.reserve(end-start);

	int index_left = start;
	int index_right = middle;

	while (index_left < middle && index_right < end) {
		if (table_[index_left] < table_[index_right]) {
			out.push_back(table_[index_left]);
			++index_left;
		} else {
			out.push_back(table_[index_right]);
			++index_right;
		}
	}

	while (index_left < middle)
		out.push_back(table_[index_left++]);
	while (index_right < end)
		out.push_back(table_[index_right++]);

	memcpy(&(table_[start]),&(out[0]), (end-start)*sizeof(int));
}