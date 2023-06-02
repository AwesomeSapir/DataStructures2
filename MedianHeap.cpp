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
    if(minmaxLower.getSize() == minmaxUpper.getSize()){ //Odd total size including median
        minmaxUpper.Insert(median);
        median = minmaxLower.DeleteMax();
    }
    size--;
    return minmaxUpper.DeleteMax();
}

Item *MedianHeap::DeleteMin() {
    if(minmaxLower.getSize() != minmaxUpper.getSize()){ //Even total size including median
        minmaxLower.Insert(median);
        median = minmaxUpper.DeleteMin();
    }
    size--;
    return minmaxLower.DeleteMin();
}

void MedianHeap::CreateEmpty() {

}

void MedianHeap::Insert(int priority, string value) {
    Item* item = new Item(priority, value);
    if(size == 0){
        median = item;
    } else if (size == 1){
        if(median->priority < item->priority){
            minmaxUpper.Insert(item);
        } else {
            minmaxUpper.Insert(median);
            median = item;
        }
    } else if (size == 2){

    }


    if(minmaxLower.getSize() == minmaxUpper.getSize()){ //Odd total size including median
        if(priority > median->priority){
            minmaxUpper.Insert(item);
        } else {
            minmaxUpper.Insert(median);
            if (priority > minmaxLower.Max()->priority){
                median = item;
            } else {
                median = minmaxLower.DeleteMax();
                minmaxLower.Insert(item);
            }
        }

    } else { //Even total size including median
        if(priority < median->priority){
            minmaxLower.Insert(item);
        } else {
            minmaxLower.Insert(median);
            if(priority < minmaxUpper.Min()->priority){
                median = item;
            } else {
                median = minmaxUpper.DeleteMin();
                minmaxUpper.Insert(item);
            }
        }
    }
    size++;
}
