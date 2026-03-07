#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string strInput = "";
	stack<char> stackText;

	cin >> strInput;

	for (int i = 0; i < strInput.size(); ++i)
	{
		if ((strInput[i] >= 'A') && (strInput[i] <= 'Z'))
		{
			cout << strInput[i];
			continue;
		}
		else if ((strInput[i] == '-') || (strInput[i] == '+') || (strInput[i] == ')'))
		{
			while (stackText.empty() == false)
			{
				char Top = stackText.top();
				if ((Top == '(') && (strInput[i] == ')'))
				{
					stackText.pop();
					break;
				}
				else if ((Top == '(') && (strInput[i] != ')'))
				{
					break;
				}
				else
				{
					stackText.pop();
					cout << Top;
				}
			}
		}
		else if ((strInput[i] == '*') || (strInput[i] == '/'))
		{
			if (stackText.empty() == false)
			{
				char Top = stackText.top();
				if ((Top == '*') || (Top == '/'))
				{
					cout << Top;
					stackText.pop();
				}
			}
		}
		if (strInput[i] != ')')
			stackText.push(strInput[i]);
	}

	while (stackText.empty() == false)
	{
		if (stackText.top() != ')')
			cout << stackText.top();;
		stackText.pop();
	}

	return 0;
}