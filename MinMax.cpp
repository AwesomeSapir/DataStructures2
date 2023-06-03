#include "MinMax.h"

Item *MinMax::Max() {
    return maxHeap.Top();
}

Item *MinMax::Min() {
    return minHeap.Top();
}

Item* MinMax::DeleteMax() {
    Item* max = maxHeap.DeleteTop();
    minHeap.Delete(max->indexMin);
    size--;
    return max;
}

Item *MinMax::DeleteMin() {
    Item* min = minHeap.DeleteTop();
    maxHeap.Delete(min->indexMax);
    size--;
    return min;
}

void MinMax::Insert(Item* item) {
    maxHeap.Insert(item);
    minHeap.Insert(item);
    size++;
}

int MinMax::getSize() const {
    return size;
}

void MinMax::setSize(int size) {
    MinMax::size = size;
}
