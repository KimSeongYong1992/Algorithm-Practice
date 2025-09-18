#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long INF = (long long)100000 * (long long)60000;

struct ROUTE
{
	long long iStart = (long long)0;
	long long iEnd = (long long)0;
	long long iDistance = INF;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iCity = (long long)0;
	long long iRoute = (long long)0;

	cin >> iCity >> iRoute;

	vector<long long> vecDist;
	vecDist.resize(iCity + (long long)1, INF);

	vecDist[1] = (long long)0;


	vector<ROUTE> vecRoute;

	for (long long i = (long long)0; i < iRoute; ++i)
	{
		ROUTE New;
		cin >> New.iStart >> New.iEnd >> New.iDistance;
		vecRoute.push_back(New);
	}

	for (long long i = (long long)0; i < iCity - 1; ++i)
	{
		for (long long j = (long long)0; j < vecRoute.size(); ++j)
		{
			if (vecDist[vecRoute[j].iStart] == INF)
				continue;

			vecDist[vecRoute[j].iEnd] = min(vecDist[vecRoute[j].iEnd], vecDist[vecRoute[j].iStart] + vecRoute[j].iDistance);
		}
	}

	for (long long j = (long long)0; j < vecRoute.size(); ++j)
	{
		if (vecDist[vecRoute[j].iStart] == INF)
			continue;

		if (vecDist[vecRoute[j].iEnd] > vecDist[vecRoute[j].iStart] + vecRoute[j].iDistance)
		{
			cout << -1;
			return 0;
		}
	}

	for (long long j = (long long)2; j < vecDist.size(); ++j)
	{
		if (vecDist[j] < INF)
			cout << vecDist[j] << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}