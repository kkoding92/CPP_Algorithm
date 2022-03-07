#include <iostream>
using namespace std;

int g, p;
int parent[100001];

int FindParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

void UnionFind(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> g >> p;

	for (int i = 1; i <= g; i++) 
		parent[i] = i;

	int result = 0;
	for (int i = 0; i < p; ++i)
	{
		int x;
		cin >> x;
		int root = FindParent(x); // 현재 비행기의 탑승구의 루트 확인
		if (root == 0) break; // 현재 루트가 0이라면, 종료
		UnionFind(root, root - 1); // 그렇지 않다면 바로 왼쪽의 집합과 합치기
		result += 1;
	}

	cout << result << '\n';
}