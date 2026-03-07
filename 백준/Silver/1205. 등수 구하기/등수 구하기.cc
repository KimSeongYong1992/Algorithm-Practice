#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int iNumber = 0;
    long long iMyScore = (long long)0;
    int iLimit = 0;

    vector<long long> vecScores;

    cin >> iNumber >> iMyScore >> iLimit;

    for (int i = 0; i < iNumber; ++i)
    {
        long long llInput = 0;
        cin >> llInput;
        vecScores.push_back(llInput);
    }

    vecScores.push_back(iMyScore);

    sort(vecScores.begin(), vecScores.end(), greater<>());

    int iIndex = 0;
    int iRank = 1;

    for (int i = 0; i < vecScores.size(); ++i)
    {
        if (vecScores[i] < iMyScore)
            break;

        iIndex = i + 1;

        if (i > 0 && vecScores[i] < vecScores[i - 1])
            iRank = i + 1;
    }

    if (iIndex > iLimit)
        cout << -1;
    else
        cout << iRank;

    return 0;
}