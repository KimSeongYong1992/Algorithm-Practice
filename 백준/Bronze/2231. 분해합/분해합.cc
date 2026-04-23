#include <iostream>
using namespace std;
int main ()
{
    int Number = 0;
    cin >> Number;
    
    for(int i = 1; i <= Number; ++i)
    {
        int NowNum = i;
        int SumNum = NowNum;
        
        while(NowNum > 0)
        {
            SumNum += NowNum % 10;
            NowNum /= 10;
        }
        
        if (Number == SumNum)
        {
            cout << i;
            break;
        }
        
        if (i == Number)
            cout << 0;
    }
    
    return 0;
}