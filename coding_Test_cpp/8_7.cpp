#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v;
// 모든 노드에 대한 진입차수는 0으로 초기화
int indegree[501];
vector<int> graph[501];
// 각 강의 시간을 0으로 초기화
int times[501];

void topologySort()
{
    vector<int> result(501); // 알고리즘 수행 결과를 담을 리스트 
    for (int i = 1; i <= v; i++) {
        result[i] = times[i];
    }
    queue<int> q; // 큐 라이브러리 사용

    // 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        // 큐에서 원소 꺼내기
        int now = q.front();
        q.pop();
        result.push_back(now);

        // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for (int i = 0; i < graph[now].size(); i++) {
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
            indegree[graph[now][i]] -= 1;
            // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
            }
        }
    }

    // 위상 정렬을 수행한 결과 출력
    for (int i = 1; i <= v; i++) {
        cout << result[i] << '\n';
    }
}


int main(void) {
    cin >> v ;

    for (int i = 1; i <= v; i++) {
        int x;
        cin >> x;
        times[i] = x;

        while (true)
        {
            cin >> x;
            if (x == -1) break;

            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }

    topologySort();
}
