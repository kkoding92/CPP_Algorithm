#include <iostream>
using namespace std;

int n, m;
int graph[501][501];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 501; ++i)
		fill(graph[i], graph[i] + 501, 1e9);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (i == j) graph[i][j] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int a = 1; a <= n; ++a)
		{
			for (int b = 1; b <= n; ++b)
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
		}
	}

	int result = 0;
	for (int a = 1; a <= n; ++a)
	{
		int cnt = 0;
		for (int b = 1; b <= n; ++b)
		{
			if (graph[a][b] != 1e9 || graph[b][a] != 1e9)
				cnt += 1;
		}

		if (cnt == n)
			result += 1;
	}

	cout << result << '\n';
}