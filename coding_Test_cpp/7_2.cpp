#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9 
using namespace std;

int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[100001];
// 최단 거리 테이블 만들기
int d[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		// 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
		int dist = -pq.top().first; // 현재 노드까지의 비용
		int now = pq.top().second; // 현재 노드
		pq.pop();
		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[now] < dist) continue;

		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < graph[now].size(); ++i)
		{
			int cost = dist + graph[now][i].second;
			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push({-cost, graph[now][i].first});
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill_n(d, 100001, INF);

	dijkstra(start);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == INF)
			cout << "INFINITY" << '\n';
		else
			cout << d[i] << '\n';
	}
}