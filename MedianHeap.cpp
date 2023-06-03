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
    Item* max;
    if(minmaxUpper.getSize() == 0){
        max = median;
        median = nullptr;
    } else {
        max = minmaxUpper.DeleteMax();
    }
    size--;
    fix();
    return max;
}

Item *MedianHeap::DeleteMin() {
    Item* min;
    if(minmaxLower.getSize() == 0){
        min = median;
        median = nullptr;
    } else {
        min = minmaxLower.DeleteMin();
    }
    size--;
    fix();
    return min;
}

void MedianHeap::CreateEmpty() {

}

void MedianHeap::Insert(int priority, string value) {
    Item* item = new Item(priority, value);
    if(median == nullptr){
        median = item;
    } else if(priority < median->priority){
        minmaxLower.Insert(item);
    } else {
        minmaxUpper.Insert(item);
    }
    fix();
    size++;
}

void MedianHeap::fix() {
    if(minmaxLower.getSize() > minmaxUpper.getSize()){
        minmaxUpper.Insert(median);
        median = minmaxLower.DeleteMax();
    } else if (minmaxLower.getSize()+1 < minmaxUpper.getSize()){
        minmaxLower.Insert(median);
        median = minmaxUpper.DeleteMin();
    } else if (minmaxLower.getSize() == 0 && median == nullptr){
        median = minmaxUpper.DeleteMin();
    }
}
