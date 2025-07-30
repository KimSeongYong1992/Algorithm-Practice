#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vecNum;


vector<string> vecDp;

int iCount = 0;
string strMin = {};
string strMax = {};

void Make_Answer(bool bIsMin)
{
	vecDp.resize(iCount + 1);

	for (int i = 2; i <= iCount; ++i)
	{
		string strAnswerNow = {};

		for (int j = 2; j <= i; ++j)
		{
			int iRemain = i - j;
			int intAdd = 0;

			if (iRemain == 1)
				continue;

			string strTemp = {};
				
			if (j == 2)
				strTemp = to_string(1) + vecDp[iRemain];
			else if (j == 3)
				strTemp = to_string(7) + vecDp[iRemain];
			else if (j == 4)
				strTemp = to_string(4) + vecDp[iRemain];
			else if (j == 5)
			{
				if (bIsMin == true)
					strTemp = to_string(2) + vecDp[iRemain];
				else 
					strTemp = to_string(5) + vecDp[iRemain];
			}
			else if (j == 6)
			{
				if ((bIsMin == true) && (i != iCount))
					strTemp = to_string(0) + vecDp[iRemain];
				else if ((bIsMin == true) && (i == iCount))
					strTemp = to_string(6) + vecDp[iRemain];
				else
					strTemp = to_string(9) + vecDp[iRemain];
			}
			else if (j == 7)
				strTemp = to_string(8) + vecDp[iRemain];

			if (strTemp.empty() == true)
				continue;
			else if ((i == iCount) && (strTemp[0] == '0'))
				continue;
			else if (strAnswerNow.empty() == true)
				strAnswerNow = strTemp;
			else if (bIsMin == true)
			{
				if (strAnswerNow.size() > strTemp.size())
					strAnswerNow = strTemp;
				else if ((strAnswerNow.size() == strTemp.size()) && (strAnswerNow > strTemp))
					strAnswerNow = strTemp;
			}
			else
			{
				if (strAnswerNow.size() < strTemp.size())
					strAnswerNow = strTemp;
				else if ((strAnswerNow.size() == strTemp.size()) && (strAnswerNow < strTemp))
					strAnswerNow = strTemp;
			}
		}
		//cout << strAnswerNow << "\n";
		vecDp[i] = strAnswerNow;
	}

	if (bIsMin == true)
		strMin = vecDp.back();
	else 
		strMax = vecDp.back();

	vecDp.clear();
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*vecNum.push_back({ 2,1 });

	vecNum.push_back({ 3,7 });

	vecNum.push_back({ 4,4 });

	vecNum.push_back({ 5,2 });
	vecNum.push_back({ 5,5 });

	vecNum.push_back({ 6,6 });
	vecNum.push_back({ 6,9 });
	vecNum.push_back({ 6,0 });

	vecNum.push_back({ 7,8 });*/

	int iCase = 0;

	cin >> iCase;

	for (int k = 0; k < iCase; ++k)
	{
		cin >> iCount;

		//iCount = k;

		Make_Answer(true);

		Make_Answer(false);

		cout << strMin << " " << strMax << "\n";
	}

	return 0;
}