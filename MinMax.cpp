#include "MinMax.h"

Item *MinMax::Max() {
    return maxHeap.Top();
}

Item *MinMax::Min() {
    return minHeap.Top();
}

Item *MinMax::DeleteMax() {
    Item* max = maxHeap.DeleteTop();
    minHeap.Delete(max->indexMin);
    return max;
}

Item *MinMax::DeleteMin() {
    Item* min = minHeap.DeleteTop();
    minHeap.Delete(min->indexMax);
    return min;
}

void MinMax::Insert(Item* item) {
    maxHeap.Insert(item);
    minHeap.Insert(item);
}
