#include <algorithm>
#include <vector>
#include "quicksort_table.h"

QuickSortTable::QuickSortTable(): DataStructure() {
}


void QuickSortTable::sort() {
	std::vector< std::pair<int, int> > todo;
	todo.push_back(std::pair<int, int>(0, num_elements_));

	while (!todo.empty()) {
		std::pair<int, int> range = todo.back();
		todo.pop_back();
		int range_min = range.first;
		int range_max = range.second;

		if (range_max - range_min < 2)
			continue;

		int pivot = table_[range_min];

		/* Put small values on the left of the table and high values on the right */
		int i = range_min+1;
		int j = range_max-1;
		while (j > i) {
			if (table_[i] <= pivot)
				++i;
			else if (table_[j] > pivot)
				--j;
			else
				std::swap(table_[i], table_[j]);
		}
		/* Put the pivot at the right place */
		std::swap(table_[range_min], table_[i-1]);

		write();

		todo.push_back(std::pair<int, int>(range_min, i-1));
		todo.push_back(std::pair<int, int>(i, range_max));
	}
}
