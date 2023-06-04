#include "InputFunc.h"

using namespace std;

int InputFunc::getNumOfActions()
{
    int n;
    cin >> n;
    if(n<=0)
    {
        throw invalid_argument("wrong input");
    }
    else
    {
        return n;
    }
}

char InputFunc::getAction(int i, int n)
{
    char c;
    cin >> c;

    if (c < 'a' || c > 'g')
    {
        throw invalid_argument("wrong input");    }
    else if(i == 0 && c != 'e')
    {
        throw invalid_argument("wrong input");
    }
    else if(i != 0 && c == 'e')
    {
        throw invalid_argument("wrong input");
    }
    else if (i == n && c != '\n')
    {
        throw invalid_argument("wrong input");
    }
    else
    {
        return c;
    }
}

void InputFunc::handleAction(MedianHeap* medianHeap, char c) {
    Item *max, *min;
    int priority;
    string value;
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
            medianHeap->CreateEmpty();
            break;
        case 'f':
            cin >> value;
            priority = stoi(value);
            cin.get();
            getline(cin, value);
            medianHeap->Insert(priority, value);
            break;
        case 'g':
            cout << medianHeap->Median()->priority << " " << medianHeap->Median()->data << endl;
            break;
    }
}
