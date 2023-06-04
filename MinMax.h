#pragma once

#include "Heap.h"

class MinMax {
private:
    Heap minHeap;
    Heap maxHeap;
    int size = 0;
public:
    Item *Max();

    Item *Min();

    Item *DeleteMax();

    Item *DeleteMin();

    void Insert(Item *item);

    int getSize() const;

    MinMax() : minHeap(Heap::TYPE_MIN), maxHeap(Heap::TYPE_MAX) {};
};
