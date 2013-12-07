#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char** argv)
{
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


