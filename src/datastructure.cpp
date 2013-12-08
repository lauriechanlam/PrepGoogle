#include <stdio.h>
#include "datastructure.h"

DataInterface::DataInterface() {
}

TableInterface::TableInterface(): DataInterface(),
    num_elements_(0) {
}

void TableInterface::write() const {
    for (int index = 0; index < num_elements_; ++index)
        printf("%d ", table_[index]);

    printf("\n");
}

bool TableInterface::insert(int value) {
	if (num_elements_ == MAX_NUM_ELEMENTS)
		return false;
	table_[num_elements_] = value;
	++num_elements_;
}

bool TableInterface::suppress(int value) {
	int index_value = find(value);

	if (index_value == -1)
		return false;

	for (int index = index_value + 1; index < num_elements_; ++index) {
		table_[index - 1] = table_[index];
	}

	--num_elements_;

	return true;
}

int TableInterface::find(int value) {
	if (num_elements_ == 0)
		return -1;

	int index = 0;
	while(table_[index] != value && index < num_elements_) {
		++index;
	}

	return (index < num_elements_) ? index: -1;
}
