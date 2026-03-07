#include <iostream>
#include <set>
#include <string>

using namespace std;

int main ()
{
    int iPeople = 0;
    int iDivide = 0;
    
    char czInput;
    
    cin >> iPeople;
    cin >> czInput;
    
    if (czInput == 'Y') iDivide = 1;
    else if (czInput == 'F') iDivide = 2;
    else if (czInput == 'O') iDivide = 3;
    
    set<string> setPeople;
    
    for(int i = 0; i < iPeople; ++i)
    {
        string strInput = "";
        cin >> strInput;
        
        if (setPeople.find(strInput) == setPeople.end())
            setPeople.insert(strInput);
    }

    cout << (setPeople.size() / iDivide);

    return 0;
}