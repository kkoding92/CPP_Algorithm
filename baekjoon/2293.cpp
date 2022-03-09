#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	vector<int> coin(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	dp[0] = 1;
	for (int i = 0; i < coin.size(); ++i)
	{
		for (int j = coin[i]; j <= k; ++j)
			dp[j] = dp[j] + dp[j - coin[i]];
	}

	cout << dp[k] << '\n';
}
