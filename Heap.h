#pragma once

#include "Item.h"

#define MAX_SIZE 100

class Heap {
private:
    bool type;
    Item* items[MAX_SIZE];
    int size = 0;

    // Returns the index of the left child of the given index.
    static int Left(int index);

    // Returns the index of the right child of the given index.
    static int Right(int index);

    // Returns the index of the parent of the given index.
    static int Parent(int index);

    // Corrects the heap property at the given index after any modification.
    void fixHeap(int index);

    // Inserts an item at the specified index in the heap.
    void insertAt(Item* item, int indexAt);

    // Updates the position of an item in the heap to a new index.
    void updatePos(Item* item, int newIndex);

public:
    // Constants representing the type of heap.
    static const bool TYPE_MIN = false;
    static const bool TYPE_MAX = true;

    // Constructor that sets the type of the heap.
    Heap(bool type) : type(type) {};

    // Returns the top item of the heap.
    Item* Top();

    // Deletes and returns the top item of the heap.
    Item* DeleteTop();

    // Inserts a new item into the heap.
    void Insert(Item* item);

    // Deletes the item at the given index in the heap.
    void Delete(int index);
};
