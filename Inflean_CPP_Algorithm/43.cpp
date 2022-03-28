#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int Count(int s)
{
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sum + v[i] > s)
		{
			cnt++;
			sum = v[i];
		}
		else
			sum = sum + v[i];
	}

	return cnt;
}

int main()
{
	int m, total = 0, start, end, result, maxValue = -987654321;
	cin >> n >> m;

	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		total += v[i];
		if (v[i] > maxValue) maxValue = v[i];
	}

	start = 1;
	end = total;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (mid >= maxValue && Count(mid) <= m)
		{
			result = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	cout << result;
}