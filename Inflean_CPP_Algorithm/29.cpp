#include <iostream>
using namespace std;

int main()
{
	int n, tmp, cnt = 0, digit;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		tmp = i;
		while (tmp > 0)
		{
			digit = tmp % 10;
			if (digit == 3) cnt++;
			tmp = tmp / 10;
		}
	}
	cout << cnt;
}