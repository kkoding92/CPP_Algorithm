#include <iostream>
using namespace std;

int n, arr[11], total = 0;
bool flag = false;

void DFS(int L, int sum)
{
	if (flag == true) return;

	if (L == n + 1)
	{
		if (sum == (total - sum))
			flag = true;
	}
	else
	{
		DFS(L + 1, sum + arr[L]);
		DFS(L + 1, sum);
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		total += arr[i];
	}

	DFS(1, 0);
	if (flag) cout << "YES";
	else cout << "NO";
}