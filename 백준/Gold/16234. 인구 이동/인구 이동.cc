#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int iSize = 0;
int iMin = 0;
int iMax = 0;

struct NODE
{
	int iHead = -1;
	int iCount = 1;
	int iHuman = 0;
};

vector<NODE> vecNode;

int Find_Head(int iNode)
{
	if (vecNode[iNode].iHead != iNode)
		vecNode[iNode].iHead = Find_Head(vecNode[iNode].iHead);

	return vecNode[iNode].iHead;
}

void Merge_Head(int iFirst, int iSecond)
{
	int iNewHead = min(Find_Head(iFirst), Find_Head(iSecond));
	vecNode[vecNode[iFirst].iHead].iHead = iNewHead;
	vecNode[vecNode[iSecond].iHead].iHead = iNewHead;
}

void Ave_Human()
{
	for (int i = 0; i < vecNode.size(); ++i)
		Find_Head(i);

	for (int i = vecNode.size() - 1; i >= 0; --i)
	{
		if (vecNode[i].iHead != i)
		{
			++vecNode[vecNode[i].iHead].iCount;
			vecNode[vecNode[i].iHead].iHuman += vecNode[i].iHuman;
			vecNode[i].iCount = 1;
		}
		else
		{
			vecNode[i].iHuman /= vecNode[i].iCount;
			vecNode[i].iCount = 1;
		}
	}

	for (int i = 0; i < vecNode.size(); ++i)
		vecNode[i].iHuman = vecNode[vecNode[i].iHead].iHuman;
}

bool Check_Human(int iFirst, int iSecond)
{
	int iDist = abs(vecNode[iFirst].iHuman - vecNode[iSecond].iHuman);
	
	if ((iDist >= iMin) && (iDist <= iMax))
	{
		Merge_Head(iFirst, iSecond);
		return true;
	}
	else
		return false;
}

bool Check_Cell(int iNode)
{
	bool bIsChange = false;

	if ((iNode % iSize) > 0)
		if (Check_Human(iNode, iNode - 1))
			bIsChange = true;

	if ((iNode % iSize) < (iSize - 1))
		if (Check_Human(iNode, iNode + 1))
			bIsChange = true;

	if ((iNode / iSize) > 0)
		if (Check_Human(iNode, iNode - iSize))
			bIsChange = true;

	if ((iNode / iSize) < (iSize - 1))
		if (Check_Human(iNode, iNode + iSize))
			bIsChange = true;

	return bIsChange;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iSize >> iMin >> iMax;

	vecNode.resize(iSize * iSize);

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			cin >> vecNode[(i * iSize) + j].iHuman;

	int iAnswer = 0;
	bool bIsEnd = false;

	

	while (bIsEnd == false)
	{
		for (int i = 0; i < vecNode.size(); ++i)
		{
			vecNode[i].iHead = i;
			vecNode[i].iCount = 1;
		}
			

		bIsEnd = true;
		for (int i = 0; i < vecNode.size(); ++i)
		{
			if (Check_Cell(i) == true)
				bIsEnd = false;
		}

		if (bIsEnd == false)
		{
			++iAnswer;
			Ave_Human();
		}

	}

	cout << iAnswer;

	return 0;
}