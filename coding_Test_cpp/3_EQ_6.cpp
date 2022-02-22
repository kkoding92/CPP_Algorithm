#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
int totalCount = 0;

// ��ü ������ ����(N x N)�� �Է¹ޱ�
int graph[50][50];
int unions[50][50];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void process(int x, int y, int index)
{
	// (x, y)�� ��ġ�� ����� ����(����) ������ ��� ����Ʈ
	vector<pair<int, int> > united;
	united.push_back({ x, y });
	// �ʺ� �켱 Ž�� (BFS)�� ���� ť ���̺귯�� ���
	queue<pair<int, int> > q;
	q.push({ x, y });
	unions[x][y] = index; // ���� ������ ��ȣ �Ҵ�
	int summary = graph[x][y]; // ���� ������ ��ü �α� ��
	int count = 1; // ���� ������ ���� ��
	// ť�� �� ������ �ݺ�(BFS)
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// ���� ��ġ���� 4���� ������ Ȯ���ϸ�
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// �ٷ� ���� �ִ� ���� Ȯ���Ͽ�
			if (0 <= nx && nx < n && 0 <= ny && ny < n && unions[nx][ny] == -1) {
				// ���� �ִ� ����� �α� ���̰� L�� �̻�, R�� ���϶��
				int gap = abs(graph[nx][ny] - graph[x][y]);
				if (l <= gap && gap <= r) {
					q.push({ nx, ny });
					// ���տ� �߰��ϱ�
					unions[nx][ny] = index;
					summary += graph[nx][ny];
					count += 1;
					united.push_back({ nx, ny });
				}
			}
		}
	}
	// ���� �������� �α��� �й�
	for (int i = 0; i < united.size(); i++) {
		int x = united[i].first;
		int y = united[i].second;
		graph[x][y] = summary / count;
	}
}

int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> graph[i][j];
	}

	// �� �̻� �α� �̵��� �� �� ���� ������ �ݺ�
	while (true)
	{
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				unions[i][j] = -1;

		int index = 0;
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				if (unions[i][j] == -1) 
				{ // �ش� ���� ���� ó������ �ʾҴٸ�
					process(i, j, index);
					index += 1;
				}
			}
		}

		// ��� �α� �̵��� ���� ���
		if (index == n * n) break;
		totalCount += 1;
	}

	cout << totalCount << '\n';
}