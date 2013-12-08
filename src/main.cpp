#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "quicksort_table.h"
#include "mergesort_table.h"

int main_heap(int argc, char** argv) {
	Heap heap;

    for(int index = 1; index < argc; ++index) {
        int value = atoi(argv[index]);
        heap.insert(value);
        heap.write();
    }
    heap.sort();
    heap.write();

    return 0;
}

template<class SortTable>
int main_sort(int argc, char** argv) {
	SortTable table;

    for(int index = 1; index < argc; ++index) {
        int value = atoi(argv[index]);
        table.insert(value);
        table.write();
    }
    table.sort();
    table.write();

    return 0;
}

int main(int argc, char** argv) {
    return main_sort<MergeSortTable>(argc, argv);
}


