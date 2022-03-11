#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) 
		answer = max(answer, dp[i]);

	cout << answer << '\n';
}
