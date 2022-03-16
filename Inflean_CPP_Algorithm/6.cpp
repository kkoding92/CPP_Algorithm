#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int iSize = str.size();
	string value = "";

	for (int i = 0; i < iSize; ++i)
	{
		if (isdigit(str[i]))
		{
			if (str[i] - '0' == 0)
			{
				if (value.size() == 0)
					continue;
				else
					value = value + str[i];
			}
			else
				value = value + str[i];
		}
	}

	cout << value << '\n';

	int temp = stoi(value);
	int cnt = 0;
	for (int i = 1; i <= temp; ++i)
	{
		if (temp % i == 0)
			cnt = cnt + 1;
	}

	cout << cnt;
}