#include "heap.h"
#include <cstdio>
#include <algorithm>

Heap::Heap():DataStructure() {
}


void Heap::write() const {
    for (int index = 0; index < num_elements_; ++index)
        printf("%d ", table_[index]);

    printf("\n");
}


bool Heap::insert(int value) {
    /* Case in which we can't add more alements */
    if (num_elements_ == MAX_NUM_ELEMENTS)
        return false;

    int index = num_elements_;
    ++num_elements_;
    table_[index] = value;

    /* Case in which we only have one element,
       we do not have the choiche where to put the new value */
    if (num_elements_ == 1)
        return true;

    while(index > 0) {
        int index_father = index >> 1;
        if (table_[index_father] < table_[index])
            std::swap(table_[index_father], table_[index]);
        else
            break;
        index = index_father;
    }

    return true;
}

void Heap::sort() {
    /* Simple cases */
    if (num_elements_ < 2)
        return;

    /* We know the highest value is the root of the heap,
       so we put itat the end of the table, then we make a heap
       out of all other values and go on like this til we have
       no more values to sort*/
    int num_elements_to_sort = num_elements_;

    while (num_elements_to_sort > 1) {
        /* Place the biggest element at the end of the table */
        std::swap(table_[0],table_[num_elements_to_sort - 1]);
        --num_elements_to_sort;

        /* Make a heap out of the other values */
		int index = 0;
		while (index < num_elements_to_sort) {
			int index_child_left = ((index + 1) << 1) - 1;
			int index_child_right = index_child_left + 1;

			/* We stop if we have reached the leaf */
			if (index_child_left >= num_elements_to_sort)
				break;

			/* If we only have one child, we play with this son */
			if (index_child_right >= num_elements_to_sort) {
				if (table_[index] >= table_[index_child_left])
					break;
				std::swap(table_[index], table_[index_child_left]);
				index = index_child_left;
				continue;
			}

			/* If we have two sons we need to check both */
			if (table_[index] >= table_[index_child_left] &&
				table_[index] >= table_[index_child_right])
				break;

			if (table_[index_child_left] > table_[index_child_right]) {
				std::swap(table_[index], table_[index_child_left]);
				index = index_child_left;
			} else {
				std::swap(table_[index], table_[index_child_right]);
				index = index_child_right;
			}
		}
    }

}

bool Heap::suppress(int value) {
    int index = find(value);

    if (index == -1)
        return false;

    std::swap(table_[index], table_[num_elements_-1]);

    --num_elements_;

    while (index > 0) {
        if (table_[index >> 1] < table_[index])
            std::swap(table_[index >> 1], table_[index]);
        else
            return true;
        index >>= 1;
    }

    return true;
}

int Heap::find(int value) {
    return find(value, 0);
}

int Heap::find(int value, int father_index) {
    if (father_index >= num_elements_)
        return -1;

    /* Examinate the case of the father */
    if (value == table_[father_index])
        return father_index;

    if (value > table_[father_index])
        return -1;

    /* Case of the kids */
    int left = find(value, father_index << 1);
    int right = find(value, (father_index << 1) + 1);

    return (left == -1)? right: left;
}

