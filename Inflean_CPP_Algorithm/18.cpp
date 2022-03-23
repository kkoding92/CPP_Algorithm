#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int cnt = 0;
	int maxCnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;

		if (x > m)
		{
			cnt += 1;
			maxCnt = max(cnt, maxCnt);
		}
		else
			cnt = 0;
	}

	cout << maxCnt;
}