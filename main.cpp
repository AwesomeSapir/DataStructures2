#include <iostream>
#include <array>
#include "MedianHeap.h"
#include "InputFunc.h"


using namespace std;

int main() {
int i;

try{
    int n = InputFunc::getNumOfActions();
    MedianHeap* medianHeap;
    Item* max;
    Item* min;
    int priority, i = 0;
    string value;
    for (i; i < n; i++) {
        char c = InputFunc::getAction(i, n);
        switch (c) {
            case 'a':
                cout << medianHeap->Max()->priority << " " << medianHeap->Max()->data << endl;
                break;
            case 'b':
                max = medianHeap->DeleteMax();
                cout << max->priority << " " << max->data << endl;
                break;
            case 'c':
                cout << medianHeap->Min()->priority << " " << medianHeap->Min()->data << endl;
                break;
            case 'd':
                min = medianHeap->DeleteMin();
                cout << min->priority << " " << min->data << endl;
                break;
            case 'e':
                medianHeap = new MedianHeap();
                break;
            case 'f':
                cin >> priority;
                cin.get();
                getline(cin, value);
                medianHeap->Insert(priority, value);
                break;
            case 'g':
                cout << medianHeap->Median()->priority << " " << medianHeap->Median()->data << endl;
                break;
        }
    }
    }
    catch (exception& e) {
    
    std::cout <<  e.what() << std::endl;
}

}

