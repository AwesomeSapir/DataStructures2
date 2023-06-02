#pragma once

#include "Heap.h"

class MinMax {
private:
    Heap minHeap;
    Heap maxHeap;
    int size; //TODO
public:
    Item* Max();
    Item* Min();
    Item* DeleteMax();
    Item* DeleteMin();
    void Insert(Item* item);
};
