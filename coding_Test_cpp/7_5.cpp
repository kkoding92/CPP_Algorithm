#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int n, m, start;

vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); ++i)
		{
			int cost = dist + graph[now][i].second;

			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push({-cost, graph[now][i].first});
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	fill(d, d + 30001, INF);

	dijkstra(start);

	// 도달할 수 있는 노드의 개수
	int count = 0;
	// 도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리
	int maxDistance = 0;
	for (int i = 1; i <= n; i++) {
		// 도달할 수 있는 노드인 경우
		if (d[i] != INF) {
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	// 시작 노드는 제외해야 하므로 count - 1을 출력
	cout << count - 1 << ' ' << maxDistance << '\n';
}