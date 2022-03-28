#include <iostream>
using namespace std;

int arr[2001];

int main()
{
	int n, k, pos = 0, cnt = 0, time = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	cin >> k;

	while (1)
	{
		pos++;
		if (pos > n) pos = 1;

		if (time < k)
		{
			if (arr[pos] != 0)
			{
				arr[pos]--;
				time++;
			}
		}
		else
		{
			if (arr[pos] != 0)
			{
				cout << pos;
				break;
			}
			else
			{
				cnt++;
				if (cnt >= k)
				{
					cout << "-1";
					break;
				}
			}
		}
	}
}