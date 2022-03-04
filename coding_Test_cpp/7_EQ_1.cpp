#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[101][101];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 101; ++i)
		fill_n(graph, graph[i] + 101, 1e9);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (i == j) graph[i][j] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(graph[a][b] > c) graph[a][b] = c;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int a = 1; a <= n; ++a)
		{
			for (int b = 1; b <= n; ++b)
				graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
		}
	}

	for (int a = 1; a <= n; ++a)
	{
		for (int b = 1; b <= n; ++b)
		{
			if (graph[a][b] == 1e9)
				cout << 0 << ' ';
			else
				cout << graph[a][b] << ' ';
		}
		cout << '\n';
	}
}
