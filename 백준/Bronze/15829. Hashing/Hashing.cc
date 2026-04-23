#include <iostream>
using namespace std;

int main() {
	int Number = 0;
	string Input = {};
	
	cin >> Number >> Input;
	
	long long Hash = (long long)0;
	long long Mod = (long long)1234567891;
	long long Key = (long long)1;
	
	for(int i = 0; i < Input.size(); ++i)
	{
		long long Index = Input[i] - 'a' + 1;
		Hash += Index * Key;
		Hash %= Mod;
		
		Key *= 31;
		Key %= Mod;
	}
	
	cout << Hash;
	
	return 0;
}