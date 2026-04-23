#include <iostream>
using namespace std;

int main() {
	int Number = 0;
	string Input = {};
	
	cin >> Number >> Input;
	
	int Hash = 0;
	int Mod = 1234567891;
	int Key = 1;
	
	for(int i = 0; i < Input.size(); ++i)
	{
		int Index = Input[i] - 'a' + 1;
		Hash += Index * Key;
		Hash %= Mod;
		
		Key *= 31;
		Key %= Mod;
	}
	
	cout << Hash;
	
	return 0;
}