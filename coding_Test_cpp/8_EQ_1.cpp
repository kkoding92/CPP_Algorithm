#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[501];

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

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;
			if (x == 1)
				UnionParent(i + 1, j + 1);
		}
	}

	vector<int> plan;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		plan.push_back(x);
	}

	bool result = true;
	for (int i = 1; i < m - 1; ++i)
	{
		if (FindParent(plan[i]) != FindParent(plan[i + 1]))
			result = false;
	}

	if (result) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}