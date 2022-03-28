#include <iostream>
using namespace std;

int p[1001];

int main()
{
	int n, k;
	cin >> n >> k;

	int pos = 0, cnt = 0, bp = 0;
	while (1)
	{
		pos++;
		if (pos > n) pos = 1;
		if (p[pos] == 0)
		{
			cnt++;
			if (cnt == k)
			{
				p[pos] = 1;
				cnt = 0;
				bp++;
			}
		}
		if (bp == n - 1) break;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (p[i] == 0)
		{
			cout << i;
			break;
		}
	}
}