#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int parent[200001];

vector <pair<int, pair<int, int>>> edge;

int FindParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back({z, {x, y}});
	}

	sort(edge.begin(), edge.end());

	int result = 0;
	int total = 0;
	for (int i = 0; i < edge.size(); ++i)
	{
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		total += cost;

		if (FindParent(a) != FindParent(b))
		{
			UnionParent(a, b);
			result += cost;
		}
	}

	cout << total - result << '\n';
}