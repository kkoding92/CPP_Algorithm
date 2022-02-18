#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ������ ����, ������ ����, �Ÿ� ����, ��� ���� ��ȣ
int n, m, k, x;
vector<int> graph[300001];
// ��� ���ÿ� ���� �ִ� �Ÿ� �ʱ�ȭ
vector<int> d(300001, -1);

int main(void) {
    cin >> n >> m >> k >> x;

    // ��� ���� ���� �Է� �ޱ�
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    // ��� ���ñ����� �Ÿ��� 0���� ����
    d[x] = 0;

    // �ʺ� �켱 Ž��(BFS) ����
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        // ���� ���ÿ��� �̵��� �� �ִ� ��� ���ø� Ȯ��
        for (int i = 0; i < graph[now].size(); i++) {
            int nextNode = graph[now][i];
            // ���� �湮���� ���� ���ö��
            if (d[nextNode] == -1) {
                // �ִ� �Ÿ� ����
                d[nextNode] = d[now] + 1;
                q.push(nextNode);
            }
        }
    }

    // �ִ� �Ÿ��� K�� ��� ������ ��ȣ�� ������������ ���
    bool check = false;
    for (int i = 1; i <= n; i++) {
        if (d[i] == k) {
            cout << i << '\n';
            check = true;
        }
    }

    // ���� �ִ� �Ÿ��� K�� ���ð� ���ٸ�, -1 ���
    if (!check) cout << -1 << '\n';
}