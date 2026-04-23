#include <iostream>
#include <map>

using namespace std;

const long long Modula = 1000000007;
map<long long, long long> mapFibo;


long long Divied_Fibo(long long Number)
{
	switch(Number)
	{
		case 0: 
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		case 4:
			return 3;
			break;
		default:
			break;
	}
	
	if (mapFibo.find(Number) != mapFibo.end())
		return mapFibo.find(Number)->second;
	
	long long Return = (long long)0;
	long long NextNum = Number / (long long)2;
	long long Add = Number % (long long)2;
	
	Return = Divied_Fibo(NextNum + 1) * Divied_Fibo(NextNum + Add);
	Return %= Modula;
	Return += Divied_Fibo(NextNum) * Divied_Fibo(NextNum - 1 + Add);
	Return %= Modula;
	
	mapFibo.insert({Number, Return});
	
	return Return;
}

int main() {
	long long Input = (long long)0;
	cin >> Input;
	cout << Divied_Fibo(Input);
	
	return 0;
}