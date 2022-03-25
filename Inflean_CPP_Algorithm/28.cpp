#include <iostream>
#include <string>
using namespace std;

int factorial(int n)
{
	if (n == 1) return 1;

	return n * factorial(n - 1);
}

int main()
{
	string str;
	int n;
	cin >> n;

	str = to_string(factorial(n));

	int size = str.size();

	int cnt = 0;
	int maxCnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (str[i] - '0' == 0)
		{
			cnt = cnt + 1;
			maxCnt = max(cnt, maxCnt);
		}
		else
			cnt = 0;
	}

	cout << maxCnt;
}