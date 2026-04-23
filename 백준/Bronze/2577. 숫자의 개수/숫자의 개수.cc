#include <iostream>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A,B,C = 0;
    cin >> A >> B >> C;
    
    int Number = A * B * C;
    
    int Count[10] = {0,};
    
    while(Number > 0)
    {
        ++Count[Number % 10];
        Number /= 10;
    }
    
    for(int i = 0; i < 10; ++i)
        cout << Count[i] <<"\n";
    
    return 0;
}