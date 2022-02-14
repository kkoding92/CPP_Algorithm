#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int sum = 0;
vector<char> v;

int main()
{
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
			v.push_back(str[i]);
		else
			sum += str[i] - '0';
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
		cout << v[i];

	cout << sum << '\n';
}
