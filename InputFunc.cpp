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