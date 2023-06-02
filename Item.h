#pragma once
#include <string>

using namespace std;

class Item {
private:
public:
    Item(int priority, const string &data) : priority(priority), data(data) {} ;
    int priority;
    string data;
    int indexMin;
    int indexMax;
};