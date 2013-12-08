#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "quicksort_table.h"
#include "mergesort_table.h"
#include "binary_tree.h"


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

int main_tree(int argc, char** argv) {
	BinaryTree *tree = NULL;
	for(int index = 1; index < argc; ++index) {
        int value = atoi(argv[index]);
		if (tree != NULL)
			tree->insert(value);
		else
			tree = new BinaryTree(value);
    }
	tree->write();

	return 0;
}


int main(int argc, char** argv) {
 //   main_sort<Heap>(argc, argv);
	//main_sort<QuickSortTable>(argc, argv);
	//main_sort<MergeSortTable>(argc, argv);
	main_tree(argc, argv);

	return 0;
}


