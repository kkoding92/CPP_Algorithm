#include <iostream>
using namespace std;


int main()
{
	int n, pre, cnt = 1, max_value = -2147000000;

	cin >> n;
	cin >> pre;

	for (int i = 2; i <= n; ++i)
	{
		int now;
		cin >> now;
		if (now >= pre)
		{
			cnt = cnt + 1;
			if (cnt > max_value) max_value = cnt;
		}
		else
			cnt = 1;

		pre = now;
	}

	cout << max_value;
}