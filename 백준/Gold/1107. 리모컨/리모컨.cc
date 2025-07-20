#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> vecNum;

int iDest = 0;
int iNow = 0;
int iAnswer = 5000000;
int iNumbers = 0;
int iNowNumbers = 0;
bool bIsFirst = false;

void Backtraking_Func()
{
	if ((iNowNumbers > 0) && (iNumbers - 1 <= iNowNumbers))
	{
		int iDiff = abs(iDest - iNow);

		int iCountNum = 0;
		int iCheck = iNow;
		while (iCheck > 0)
		{
			++iCountNum;
			iCheck /= 10;
		}
		if (iCountNum == 0)
			iCountNum = 1;

		iAnswer = min(iAnswer, (iDiff + iCountNum));
	}

	if (iNumbers < iNowNumbers)
		return;

	iNow *= 10;

	for (int i = 0; i < 10; ++i)
	{
		if (vecNum[i] == false)
			continue;

		iNow += i;
		++iNowNumbers;
		Backtraking_Func();
		iNow -= i;
		--iNowNumbers;
	}

	iNow /= 10;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vecNum.resize(10, true);

	cin >> iDest;

	iAnswer = min(iAnswer, abs(iDest - 100));
	iNow = 0;

	int iCount = 0;
	cin >> iCount;

	int iCheck = iDest;
	while (iCheck > 0)
	{
		++iNumbers;
		iCheck /= 10;
	}
	if (iNumbers == 0)
		iNumbers = 1;


	for (int i = 0; i < iCount; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecNum[iInput] = false;
	}

	Backtraking_Func();

	cout << iAnswer;


	return 0;
}