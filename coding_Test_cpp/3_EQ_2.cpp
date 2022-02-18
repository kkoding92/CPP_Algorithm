#include <iostream>
using namespace std;

int n, m;
int arr[8][8];
int d[8][8];

int result;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int get_score()
{
	int score = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (d[i][j] == 0)
				score += 1;
		}

	return score;
}

void virus(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (d[nx][ny] == 0)
		{
			d[nx][ny] = 2;
			virus(nx, ny);
		}
	}
}

void dfs(int count)
{
	if (count == 3)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				d[i][j] = arr[i][j];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (d[i][j] == 2)
					virus(i, j);
			}

		result = max(result, get_score());
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == 0)
			{
				count += 1;
				arr[i][j] = 1;
				dfs(count);
				arr[i][j] = 0;
				count -= 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	dfs(0);
	cout << result << '\n';
}