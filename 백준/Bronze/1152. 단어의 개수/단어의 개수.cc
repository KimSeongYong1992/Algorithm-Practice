#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iCount = 0;
    bool bBlank = true;

    string strInput;

    getline(cin,strInput);

    for (int i = 0; i < strInput.size(); ++i)
    {
        if ((strInput[i] != ' ') && (bBlank == true))
        {
            bBlank = false;
            ++iCount;
        }
        else if ((strInput[i] == ' ') && (bBlank == false))
        {
            bBlank = true;
        }
    }

    cout << iCount;

    return 0;
}