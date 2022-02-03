#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int parent[100001];

vector<pair<int, pair<int, int>>> edge;

int findParent(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	int result = 0;
	cin >> v >> e;

	for (int i = 1; i <= v; ++i)
		parent[i] = i;

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}

	sort(edge.begin(), edge.end());
	int last = 0; // �ּ� ���� Ʈ���� ���ԵǴ� ���� �߿��� ���� ����� ū ����

	for (int i = 0; i < edge.size(); ++i)
	{
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			result += cost;
			last = cost;
		}
	}

	cout << result - last << '\n';
}