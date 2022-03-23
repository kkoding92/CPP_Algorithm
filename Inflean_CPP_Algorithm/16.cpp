#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;

int main()
{
	cin >> str1;
	cin.ignore();
	cin >> str2;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	for (int i = 0; i < str1.length(); ++i)
	{
		if (str1[i] != str2[i])
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES" << endl;
}