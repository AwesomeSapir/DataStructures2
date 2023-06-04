#pragma once

#include "MinMax.h"
#include <stdexcept>

class MedianHeap {
private:
    MinMax minmaxUpper;
    MinMax minmaxLower;
    Item* median;
    int size = 0;
    // Helper function to balance the two heaps and update the median after any insertions or deletions.
    void fix();
public:
    // Returns the maximum item in the heap.
    Item* Max();

    // Returns the minimum item in the heap.
    Item* Min();

    // Returns the median item in the heap.
    Item* Median();

    // Removes and returns the maximum item in the heap.
    Item* DeleteMax();

    // Removes and returns the minimum item in the heap.
    Item* DeleteMin();

    // Creates an empty heap.
    void CreateEmpty();

    // Inserts a new item with the given priority and value into the heap.
    void Insert(int priority, string value);
};
