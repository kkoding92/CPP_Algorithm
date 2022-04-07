#include <iostream>
using namespace std;

int n, m, cnt = 0;
int arr[11];

void DFS(int L, int sum)
{
	if (L == n + 1)
	{
		if (sum == m) cnt++;
	}
	else
	{
		DFS(L + 1, sum + arr[L]);
		DFS(L + 1, sum - arr[L]);
		DFS(L + 1, sum);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	DFS(1, 0);

	if (cnt == 0)
		cout << "-1";
	else
		cout << cnt;
}