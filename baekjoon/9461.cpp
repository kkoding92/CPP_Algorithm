#include <iostream>
using namespace std;

int tc;
long long dp[101];

int main()
{
	cin >> tc;
	for (int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;

		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 3] + dp[i - 2];

		cout << dp[n] << '\n';
	}
}