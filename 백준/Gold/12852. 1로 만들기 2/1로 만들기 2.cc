
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int,int>> vecDP;

void MakeDp(int Num)
{
    vecDP.resize(Num+1);
    vecDP[0].first = 0; vecDP[0].second = 0;
    vecDP[1].first = 0; vecDP[1].second = 1;
    
    for(int i = 2; i <= Num; ++i)
    {
        vecDP[i].first = vecDP[i - 1].first + 1;
        vecDP[i].second = 1;
        if((i % 2 == 0) && (vecDP[i].first > vecDP[i / 2].first + 1))
        {
            vecDP[i].first = vecDP[i / 2].first + 1;
            vecDP[i].second = 2;
        }
        if((i % 3 == 0) && (vecDP[i].first > vecDP[i / 3].first + 1))
        {
            vecDP[i].first = vecDP[i / 3].first + 1;
            vecDP[i].second = 3;
        }
    }
}

void PrintAnswer(int Num)
{
    cout << vecDP[Num].first << "\n";
    
    while(Num > 0)
    {
        cout << Num << " ";
        
        if (vecDP[Num].second == 1)
            --Num;
        else 
            Num /= vecDP[Num].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int Number = 0;
    cin >> Number;
    
    MakeDp(Number);
    PrintAnswer(Number);
    
    return 0;
}