#include <iostream>
#include <queue>
using namespace std;

int t, n;
int graph[125][125], d[125][125];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> graph[i][j];

		for (int i = 0; i < n; ++i)
			fill(d[i], d[i] + 125, 1e9);

		int x = 0, y = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -graph[x][y], {x, y}});
		d[x][y] = graph[x][y];

		while (!pq.empty())
		{
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (d[x][y] < dist) continue;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				int coast = dist + graph[nx][ny];
				if (coast < d[nx][ny])
				{
					d[nx][ny] = coast;
					pq.push({ -coast, {nx, ny} });
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';
	}
}