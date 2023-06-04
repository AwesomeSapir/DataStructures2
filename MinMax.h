#pragma once

#include "Heap.h"

class MinMax {
private:
    Heap minHeap;
    Heap maxHeap;
    int size = 0;
public:
    // Returns the maximum item in the heap.
    Item *Max();

    // Returns the minimum item in the heap.
    Item *Min();

    // Removes and returns the maximum item in the heap.
    Item *DeleteMax();

    // Removes and returns the minimum item in the heap.
    Item *DeleteMin();

    // Inserts a new item into the heap.
    void Insert(Item *item);

    // Returns the current size of the heap.
    int getSize() const;

    // Constructor to initialize the heap types as minimum and maximum respectively.
    MinMax() : minHeap(Heap::TYPE_MIN), maxHeap(Heap::TYPE_MAX) {};
};
