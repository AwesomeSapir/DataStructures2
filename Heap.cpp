

#include "Heap.h"

int Heap::Left(int index) {
    return (index*2 + 1);
}

int Heap::Right(int index) {
    return (index*2 + 2);
}

int Heap::Parent(int index) {
    return (index - 1) / 2;
}

Item* Heap::Top() {
    return items[0];
}

Item* Heap::DeleteTop() {
    Item* max = items[0];
    size--;
    items[0] = items[size];
    fixHeap(0);
    return max;
}

void Heap::fixHeap(int index) {
    int top;
    int left = Left(index);
    int right = Right(index);
    if(type == TYPE_MAX){
        if((left < size) && (items[left]->priority > items[index]->priority)){
            top = left;
        } else {
            top = index;
        }

        if((right < size) && (items[right]->priority > items[top]->priority)){
            top = right;
        }
    } else { // type == TYPE_MIN
        if((left < size) && (items[left]->priority < items[index]->priority)){
            top = left;
        } else {
            top = index;
        }

        if((right < size) && (items[right]->priority < items[top]->priority)){
            top = right;
        }
    }

    if(top != index) {
        Item* temp = items[index];
        items[index] = items[top];
        items[top] = temp;
        fixHeap(top);
    }
}

void Heap::Insert(Item* item) {
    int index = size;
    size++;

    while ((index > 0) && (items[Parent(index)]->priority < item->priority)){
        items[index] = items[Parent(index)];
        index = Parent(index);
    }
    items[index] = item;
}
