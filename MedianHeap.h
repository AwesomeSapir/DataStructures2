#pragma once

#include "MinMax.h"

class MedianHeap {
private:
    MinMax minmaxUpper;
    MinMax minmaxLower;
    Item* median;
    int size = 0;
public:
    Item* Max();
    Item* Min();
    Item* Median();
    Item* DeleteMax();
    Item* DeleteMin();
    void CreateEmpty();
    void Insert(int priority, string value);
};
