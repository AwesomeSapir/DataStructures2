#include <iostream>
#include "MedianHeap.h"
#include "InputFunc.h"

using namespace std;

int main() {
    int i;
    MedianHeap* medianHeap = new MedianHeap();

    try{
        int n = InputFunc::getNumOfActions();
        for (i = 0; i < n; i++) {
            char c = InputFunc::getAction(i, n);
            InputFunc::handleAction(medianHeap, c);
        }
        string finalLine;
        getchar();
        getline(cin, finalLine);
        if(!finalLine.empty()){
            throw invalid_argument("");
        }
    }
    catch (exception& e) {
        std::cout <<  "wrong input" << std::endl;
    }
}