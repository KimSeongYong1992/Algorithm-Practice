#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; ++i)
	{
		int iType = 0;
		int iHalf = 0;
		cin >> iType;

		vector<int> vecCheck;
		vecCheck.resize(100001, 0);
		vecCheck[0] = 1;

		for (int j = 2; j < iType + 2; ++j)
		{
			int iInput[2] = { 0,0 };
			cin >> iInput[0] >> iInput[1];
			iHalf += (iInput[0] * iInput[1]);

			for (int k = 0; k <= 100000; ++k)
			{
				if ((vecCheck[k] > 0) && (vecCheck[k] < j))
					for (int x = 1; x <= iInput[1]; ++x)
						if (vecCheck[k + (iInput[0] * x)] == 0)
							vecCheck[k + (iInput[0] * x)] = j;
			}
		}

		if (iHalf % 2 == 1)
			cout << 0 << '\n';
		else if (iHalf == 0)
			cout << 0 << '\n';
		else
		{
			iHalf /= 2;
			cout << (vecCheck[iHalf] > 0) << '\n';
		}

		
	}

	return 0;
}