#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int iSize = str.size();
	int value = 0;

	for (int i = 0; i < iSize; ++i)
	{
		if (isdigit(str[i]))
			value = value * 10 + (str[i] - '0');
	}

	cout << value << '\n';

	int cnt = 0;
	for (int i = 1; i <= value; ++i)
	{
		if (value % i == 0)
			cnt = cnt + 1;
	}

	cout << cnt;
}