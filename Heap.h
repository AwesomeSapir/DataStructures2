#pragma once

#include "Item.h"

#define MAX_SIZE 100

class Heap {
private:
    bool type;
    Item* items[MAX_SIZE];
    int size = 0;

    static int Left(int index);
    static int Right(int index);
    static int Parent(int index);

    void fixHeap(int index);
    void insertAt(Item* item, int indexAt);
    void updatePos(Item* item, int newIndex);

public:
    static const bool TYPE_MIN = false;
    static const bool TYPE_MAX = true;

    Heap(bool type) : type(type) {};

    Item* Top();
    Item* DeleteTop();
    void Insert(Item* item);
    void Delete(int index);
};
