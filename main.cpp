#include <iostream>
#include "MedianHeap.h"
#include "InputFunc.h"

using namespace std;

int main() {
    int i;
    MedianHeap* medianHeap;
    Item* max;
    Item* min;
    int priority;
    string value;

    try{
        int n = InputFunc::getNumOfActions();
        for (i = 0; i < n; i++) {
            char c = InputFunc::getAction(i, n);
            switch (c) {
                case 'a':
                    cout << medianHeap->Max()->priority << " " << medianHeap->Max()->data << endl;
                    break;
                case 'b':
                    max = medianHeap->DeleteMax();
                    cout << max->priority << " " << max->data << endl;
                    delete max;
                    break;
                case 'c':
                    min = medianHeap->Min();
                    cout << min->priority << " " << min->data << endl;
                    break;
                case 'd':
                    min = medianHeap->DeleteMin();
                    cout << min->priority << " " << min->data << endl;
                    delete min;
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
        string finalLine;
        getchar();
        getline(cin, finalLine);
        if(!finalLine.empty()){
            throw invalid_argument("wrong input");
        }
    }
    catch (exception& e) {
        std::cout <<  e.what() << std::endl;
    }
}