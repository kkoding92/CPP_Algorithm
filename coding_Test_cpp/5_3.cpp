#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int start = 0;
	int end = *max_element(v.begin(), v.end());

	int result = 0;
	while (start <= end)
	{
		long long total = 0;

		int mid = (start + end) / 2;

		for (int i = 0; i < n; ++i)
		{
			if (v[i] > mid)
				total += (v[i] - mid);
		}

		if (total < m)
			end = mid - 1;
		else
		{
			result = mid;
			start = mid + 1;
		}
	}

	cout << result;
}