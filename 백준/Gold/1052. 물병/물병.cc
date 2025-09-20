#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iGoal = 0;

	cin >> iNum >> iGoal;

	int iAnswer = 0;

	while (1)
	{
		int iTemp_Num = iNum + iAnswer;
		int iCount = 0;
		while (iTemp_Num > 0)
		{
			if ((iTemp_Num & 1) == 1)
				++iCount;

			iTemp_Num = (iTemp_Num >> 1);
		}

		if (iCount <= iGoal)
			break;

		++iAnswer;
	}

	cout << iAnswer;

	return 0;
}