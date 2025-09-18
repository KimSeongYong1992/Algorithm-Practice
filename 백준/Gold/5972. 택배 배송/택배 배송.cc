#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	int iCost = -1;
	vector<pair<int, int>> vecRoute;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<NODE> vecNode;

	priority_queue<pair<int, int>> queueRoute;

	int iNode = 0;
	int iRoute = 0;

	cin >> iNode >> iRoute;

	vecNode.resize(iNode + 1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iInput[3] = { 0, };
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		pair<int, int> New;
		New.first = iInput[2];
		New.second = iInput[1];
		vecNode[iInput[0]].vecRoute.push_back(New);

		New.first = iInput[2];
		New.second = iInput[0];
		vecNode[iInput[1]].vecRoute.push_back(New);
	}

	pair<int, int> Start;
	Start.first = 0;
	Start.second = 1;

	queueRoute.push(Start);

	while (queueRoute.empty() == false)
	{
		pair<int, int> Now = queueRoute.top();
		queueRoute.pop();

		if ((vecNode[Now.second].iCost != -1) && (vecNode[Now.second].iCost < -(Now.first)))
			continue;

		vecNode[Now.second].iCost = -Now.first;

		for (int i = 0; i < vecNode[Now.second].vecRoute.size(); ++i)
		{
			pair<int, int> Next = vecNode[Now.second].vecRoute[i];

			if ((vecNode[Next.second].iCost == -1) || (vecNode[Next.second].iCost > vecNode[Now.second].iCost + Next.first))
			{
				vecNode[Next.second].iCost = vecNode[Now.second].iCost + Next.first;
				Next.first = vecNode[Next.second].iCost * -1;
				queueRoute.push(Next);
			}
		}
	}

	//for (int i = 0; i < vecNode.size(); ++i)
	cout << vecNode[iNode].iCost;
	

	return 0;
}

