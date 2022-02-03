#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
int parent[100001];

int findParent(int x)
{
	if (parent[x] == x) return x;

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
	cin >> n >> m;

	vector<string> result;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	int logic, a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> logic >> a >> b;
		if (logic == 0)
			unionParent(a, b);
		else if (logic == 1)
		{
			if (findParent(a) == findParent(b))
				result.push_back("YES");
			else
				result.push_back("NO");
		}
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << '\n';
}
