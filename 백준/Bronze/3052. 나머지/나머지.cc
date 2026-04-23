#include <iostream>

using namespace std;

int main ()
{
    int Answer = 10;
    int Numbers[10] = {0,};
    for (int i = 0; i < 10; ++i)
        cin >> Numbers[i];
    
    for (int i = 0; i < 10; ++i)
        Numbers[i] %= 42;
    
    for (int i = 0; i < 10; ++i)
    {
        if (Numbers[i] == -1)
            continue;
        
        for (int j = i + 1; j < 10; ++j)
            if (Numbers[i] == Numbers[j])
            {
                --Answer;
                Numbers[j] = -1;
            }
    }
        
    
    cout << Answer;
    
    return 0;
}