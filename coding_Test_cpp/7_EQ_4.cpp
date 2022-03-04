#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> graph[20001];
int d[20001];

void djikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (d[curNode] < dist) continue;

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			int cost = dist + graph[curNode][i].second;

			if (cost < d[graph[curNode][i].first])
			{
				d[graph[curNode][i].first] = cost;
				pq.push({ -cost, graph[curNode][i].first });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back({ b, 1 });
		graph[b].push_back({ a, 1 });
	}

	fill_n(d, 20001, 1e9);
	djikstra(1);

	int max_value = 0;
	for (int i = 1; i <= n; ++i)
		max_value = max(max_value, d[i]);

	int index = 1e9;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (d[i] == max_value)
		{
			cnt += 1;
			index = min(index, i);
		}
	}

	cout << index << ' ' << max_value << ' ' << cnt << '\n';
}