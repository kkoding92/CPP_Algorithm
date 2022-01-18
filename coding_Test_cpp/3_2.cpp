#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int arr[200][200];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int Bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (arr[nx][ny] == 0)
				continue;

			if (arr[nx][ny] == 1)
			{
				arr[nx][ny] = arr[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return arr[n - 1][m - 1];
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

	cout << Bfs(0, 0) << endl;
}