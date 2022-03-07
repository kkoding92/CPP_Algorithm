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
		int root = FindParent(x); // ���� ������� ž�±��� ��Ʈ Ȯ��
		if (root == 0) break; // ���� ��Ʈ�� 0�̶��, ����
		UnionFind(root, root - 1); // �׷��� �ʴٸ� �ٷ� ������ ���հ� ��ġ��
		result += 1;
	}

	cout << result << '\n';
}