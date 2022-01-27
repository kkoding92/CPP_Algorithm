#include <iostream>
#include <cmath>
using namespace std;

#define INF 1e9

int n, m, x, k;
int graph[101][101];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < 101; ++i)
		fill(graph[i], graph[i] + 101, INF);

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (i == j)
				graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cin >> x >> k;

	for (int k = 1; k <= m; ++k)
	{
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= m; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}

	// 수행된 결과를 출력
	int distance = graph[1][k] + graph[k][x];

	if (distance >= INF) {
		cout << "-1" << '\n';
	}
	else {
		cout << distance << '\n';
	}
}