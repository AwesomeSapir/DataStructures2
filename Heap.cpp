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
    Item* top = items[0];
    size--;
    updatePos(items[size], 0);
    fixHeap(0);
    return top;
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
        updatePos(items[top], index);
        updatePos(temp, top);
        fixHeap(top);
    }
}

void Heap::Insert(Item* item) {
    insertAt(item, size);
    size++;
}

void Heap::Delete(int index) {
    size--;
    if(index != size){
        insertAt(items[size], index);
    }
}

void Heap::insertAt(Item *item, int indexAt) {
    int index = indexAt;

    if (type == TYPE_MAX){
        while ((index > 0) && (items[Parent(index)]->priority < item->priority)){
            updatePos(items[Parent(index)], index);
            index = Parent(index);
        }
    } else { //type == TYPE_MIN
        while ((index > 0) && (items[Parent(index)]->priority > item->priority)){
            updatePos(items[Parent(index)], index);
            index = Parent(index);
        }
    }

    updatePos(item, index);
}

void Heap::updatePos(Item* item, int newIndex) {
    items[newIndex] = item;
    if (item != nullptr) {
        if (type == TYPE_MAX) {
            item->indexMax = newIndex;
        } else {
            item->indexMin = newIndex;
        }
    }
}

