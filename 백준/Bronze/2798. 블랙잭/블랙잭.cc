#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Answer = 0;
    vector<int> vecNumber;
    
    int Count = 0;
    int Number = 0;
    
    cin >> Count >> Number;
    
    vecNumber.resize(Count);
    
    for(int i = 0; i < Count; ++i)
        cin>> vecNumber[i];
    
    for(int i = 0; i < Count; ++i)
        for(int j = i + 1; j < Count; ++j)
            for(int k = j + 1; k < Count; ++k)
            {
                int Sum = vecNumber[i] + vecNumber[j] + vecNumber[k];
                if ((Sum <= Number) && (Answer < Sum))
                    Answer = Sum;
            }
    
    cout << Answer;
    
    return 0;
}