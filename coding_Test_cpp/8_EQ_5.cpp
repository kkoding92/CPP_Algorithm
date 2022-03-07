#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int testCase, n, m;
// ��� ��忡 ���� ���������� 0���� �ʱ�ȭ
int indegree[501];
// �� ��忡 ����� ���� ������ ��� ���� �迭 �ʱ�ȭ
bool graph[501][501];

int main()
{
	cin >> testCase;
	for (int tc = 0; tc < testCase; ++tc)
	{
		fill(indegree, indegree + 501, 0);
		for (int i = 0; i < 501; i++) {
			fill(graph[i], graph[i] + 501, false);
		}
		
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

        // ���� �׷����� ���� ���� �ʱ�ȭ
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[v[i]][v[j]] = true;
                indegree[v[j]] += 1;
            }
        }

        // ���� ����� ���� ���� �Է�
        cin >> m;
        for (int i = 0; i < m; i++) 
        {
            int a, b;
            cin >> a >> b;
            // ������ ���� ������
            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                indegree[a] += 1;
                indegree[b] -= 1;
            }
            else {
                graph[a][b] = true;
                graph[b][a] = false;
                indegree[a] -= 1;
                indegree[b] += 1;
            }
        }

        // ���� ����(Topology Sort) ����
        vector<int> result; // �˰��� ���� ����� ���� ����Ʈ
        queue<int> q; // ť ���̺귯�� ���

        // ó�� ������ ���� ���������� 0�� ��带 ť�� ����
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        bool certain = true; // ���� ���� ����� ���� �ϳ������� ����
        bool cycle = false; // �׷��� �� ����Ŭ�� �����ϴ��� ����

        // ��Ȯ�� ����� ������ŭ �ݺ�
        for (int i = 0; i < n; i++) {
            // ť�� ��� �ִٸ� ����Ŭ�� �߻��ߴٴ� �ǹ�
            if (q.size() == 0) {
                cycle = true;
                break;
            }
            // ť�� ���Ұ� 2�� �̻��̶�� ������ ���� ����� ���� ����� �ǹ�
            if (q.size() >= 2) {
                certain = false;
                break;
            }
            // ť���� ���� ������
            int now = q.front();
            q.pop();
            result.push_back(now);
            // �ش� ���ҿ� ����� ������ ������������ 1 ����
            for (int j = 1; j <= n; j++) {
                if (graph[now][j]) {
                    indegree[j] -= 1;
                    // ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
                    if (indegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }

        // ����Ŭ�� �߻��ϴ� ���(�ϰ����� ���� ���)
        if (cycle) cout << "IMPOSSIBLE" << '\n';
        // ���� ���� ����� ���� ���� ���
        else if (!certain) cout << "?" << '\n';
        // ���� ������ ������ ��� ���
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
	}
}