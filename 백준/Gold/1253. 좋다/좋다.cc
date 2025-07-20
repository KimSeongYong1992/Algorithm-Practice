#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecNumber;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumbers = 0;
	int iAnswer = 0;
	cin >> iNumbers;

	for (int i = 0; i < iNumbers; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecNumber.push_back(iInput);
	}

	sort(vecNumber.begin(), vecNumber.end());

	for (int i = 0; i < iNumbers; ++i)
	{
		for (int j = 0; j < iNumbers; ++j)
		{
			if (i == j)
				continue;

			int iIndex = lower_bound(vecNumber.begin(), vecNumber.end(), vecNumber[i] - vecNumber[j]) - vecNumber.begin();

			if (iIndex == iNumbers)
				continue;

			while ((vecNumber[iIndex] == vecNumber[i] - vecNumber[j]) && ((iIndex == i) || (iIndex == j)))
			{
				++iIndex;
				if (iIndex == iNumbers)
					break;
			}
				
			if (iIndex == iNumbers)
				continue;
			

			if (vecNumber[iIndex] == vecNumber[i] - vecNumber[j])
			{
				++iAnswer;
				break;
			}
		}
	}

	cout << iAnswer;

	return 0;
}