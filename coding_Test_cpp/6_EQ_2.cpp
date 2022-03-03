#include <iostream>
using namespace std;

int n;

int arr[500][500];
int dp[500][500];

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> dp[i][j];
		}
	}

	int index = 0;
	for (int i = 1; i < n; ++i)
	{
		index += 1;
		for (int j = 0; j < index; ++j)
		{
			int upLeft, upRight;
			if (j == 0)
			{
				upLeft = 0;
				upRight = dp[i - 1][j];
			}
			else if (j == index - 1)
			{
				upLeft = dp[i - 1][j - 1];
				upRight = 0;
			}
			else
			{
				upLeft = dp[i - 1][j];
				upRight = dp[i - 1][j - 1];
			}

			dp[i][j] = dp[i][j] + max(upLeft, upRight);
		}
	}

	int result = 0;
	for (int i = 0; i < n; ++i)
		result = max(result, dp[n - 1][i]);

	cout << result << '\n';
}
