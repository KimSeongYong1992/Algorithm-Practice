#include <iostream>
#include <vector>

using namespace std;

string Patton = {};
string Text = {};

vector<int> vecFail;

void Fail_func()
{
	vecFail.resize(Patton.size(),0);
	int Index[2] = {0,};
	Index[1] = 1;
	
	while(Index[0] + Index[1] < Patton.size())
	{
		if(Patton[Index[0] + Index[1]] == Patton[Index[0]])
		{
			++Index[0];
			vecFail[Index[0] + Index[1] - 1] = Index[0];
		}
		else if (Index[0] == 0)
		{
			++Index[1];
		}
		else
		{
			Index[1] += Index[0] - vecFail[Index[0] - 1];
			Index[0] = vecFail[Index[0] - 1];
		}
	}
}

vector<int> vecAnswer;

void Find_answer()
{
	int Index[2] = {0,};
	
	while(Index[1] + Index[0] < Text.size())
	{
		if (Text[Index[1] + Index[0]] == Patton[Index[0]])
		{
			++Index[0];
		}
		else if (Index[0] == 0)
		{
			++Index[1];
		}
		else 
		{
			Index[1] += Index[0] - vecFail[Index[0] - 1];
			Index[0] = vecFail[Index[0] - 1];
		}
		
		if (Index[0] >= Patton.size())
		{
			vecAnswer.push_back(Index[1] + 1);
			Index[1] += Index[0] - vecFail[Index[0] - 1];
			Index[0] = vecFail[Index[0] - 1];
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
	getline(cin, Text);
	getline(cin, Patton);
	
	Fail_func();
	Find_answer();
	
	cout << vecAnswer.size() << "\n";
	for(auto& iter : vecAnswer)
		cout << iter << " ";
	
	return 0;
}