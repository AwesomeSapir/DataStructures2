#include <iostream>
#include <array>
#include "MedianHeap.h"

using namespace std;

int main() {
    MedianHeap* medianHeap;
    int n;
    cin >> n;
    char c;
    Item* max;
    Item* min;
    int priority;
    string value;

    for (int i = 0; i < n; i++) {
        cin >> c;
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
