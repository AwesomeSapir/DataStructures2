#include "InputFunc.h"

using namespace std;

static int getNumOfActions()
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

static char getAction(int i, int n)
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
    else if (i == n-1 && c != '\n')
    {
         throw invalid_argument("wrong input");
    }
     else
    {
        return c;
    }

}