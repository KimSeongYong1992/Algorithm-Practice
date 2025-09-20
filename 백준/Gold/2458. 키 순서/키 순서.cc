#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStudent = 0;
	int iRoute = 0;

	cin >> iStudent >> iRoute;

	vector<vector<int>> vecRoute;
	vecRoute.resize(iStudent + 1);
	for(auto& iter : vecRoute)
		iter.resize(iStudent + 1, -1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iInput[2] = { 0,0 };
		cin >> iInput[0] >> iInput[1];
		vecRoute[iInput[0]][iInput[1]] = 1;
	}

	for (int i = 1; i <= iStudent; ++i)
		vecRoute[i][i] = 0;

	for (int k = 1; k <= iStudent; ++k)
		for (int i = 1; i <= iStudent; ++i)
			for (int j = 1; j <= iStudent; ++j)
			{
				if ((vecRoute[i][k] == -1) || (vecRoute[k][j] == -1))
					continue;

				if ((vecRoute[i][j] == -1) || (vecRoute[i][j] > vecRoute[i][k] + vecRoute[k][j]))
					vecRoute[i][j] = vecRoute[i][k] + vecRoute[k][j];
			}

	int iAnswer = 0;

	/*for (int i = 1; i <= iStudent; ++i)
	{
		for (int j = 1; j <= iStudent; ++j)
		{
			cout << vecRoute[i][j] << " ";
		}
		cout << '\n';
	}*/
		

	for (int k = 1; k <= iStudent; ++k)
	{
		bool bIsOk = true;

		for (int i = 1; i <= iStudent; ++i)
			if ((vecRoute[i][k] == -1) && (vecRoute[k][i] == -1))
				bIsOk = false;

		if (bIsOk == true) ++iAnswer;
	}
		
	cout << iAnswer;









	return 0;
}