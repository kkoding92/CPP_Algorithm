#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	char sex;
	int year;

	if (s[7] == '2' || s[7] == '4')
		sex = 'W';
	else if(s[7] == '1' || s[7] == '3')
		sex = 'M';

	if (s[7] == '3' || s[7] == '4')
		year = 2000 + (10 * (s[0] - '0')) + (s[1] - '0');
	else if (s[7] == '1' || s[7] == '2')
		year = 1900 + (10 * (s[0] - '0')) + (s[1] - '0');

	cout << 2019 - year + 1 << " " << sex;
}