#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int arr[1000][1000];

bool DFS(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;

	//방문하지 않았다면
	if (arr[x][y] == 0)
	{
		// 방문처리
		arr[x][y] = 1;

		DFS(x + 1, y);
		DFS(x - 1, y);
		DFS(x, y + 1);
		DFS(x, y - 1);

		return true;
	}

	return false;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}

	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (DFS(i, j))
				result += 1;
		}
	}

	cout << result << endl;
}