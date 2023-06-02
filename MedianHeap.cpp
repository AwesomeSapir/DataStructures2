#include "MedianHeap.h"

Item *MedianHeap::Max() {
    return minmaxUpper.Max();
}

Item *MedianHeap::Min() {
    return minmaxLower.Min();
}

Item *MedianHeap::Median() {
    return median;
}

Item *MedianHeap::DeleteMax() {
    return nullptr;
}

Item *MedianHeap::DeleteMin() {
    return nullptr;
}

void MedianHeap::CreateEmpty() {

}

void MedianHeap::Insert(int priority, string value) {
    Item* item = new Item(priority, value);
    if(item->priority )
}
