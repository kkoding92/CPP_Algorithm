#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int dp[16];
int maxValue = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t, p;
		cin >> t >> p;
		v.push_back({t, p});
	}

	for (int i = n - 1; i >= 0; --i)
	{
		int time = v[i].first + i;

		if (time <= n)
		{
			dp[i] = max(v[i].second + dp[time], maxValue);
			maxValue = dp[i];
		}
		else
			dp[i] = maxValue;
	}

	cout << maxValue << '\n';
}