#pragma once
#include <exception>
#include <iostream>
#include "MedianHeap.h"
#include "Item.h"

class InputFunc{
public:
    // Returns the character representing the action to be taken at the ith step, where 'n' is the total number of actions.
    static char getAction(int i, int n);

    // Returns the total number of actions to be performed.
    static int getNumOfActions();

    // Executes the action specified by character 'c' on the given MedianHeap.
    static void handleAction(MedianHeap* heap, char c);
};