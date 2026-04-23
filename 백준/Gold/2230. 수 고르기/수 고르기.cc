
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> vecNumber;

int main()
{
    int Point[2] = {0,1};
    int Numbers = 0;
    int Minimum = 0;
    
    cin >> Numbers >> Minimum;
    
    int iAnswer = 2000000001;
    
    vecNumber.resize(Numbers, 0);
    
    for(int i = 0; i < Numbers; ++i)
        cin >> vecNumber[i];
        
    sort(vecNumber.begin(), vecNumber.end());
    
    while(Point[1] < vecNumber.size())
    {
        if(vecNumber[Point[1]] - vecNumber[Point[0]] < Minimum)
            ++Point[1];
        else
        {
            iAnswer = min(iAnswer, vecNumber[Point[1]] - vecNumber[Point[0]]);
            ++Point[0];
        }
        
        if(Point[0] == Point[1])
            ++Point[1];
    }
    
    cout << iAnswer;
    
    return 0;
}