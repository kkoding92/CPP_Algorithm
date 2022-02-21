#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char board[6][6];
bool found;

vector<pair<int, int> > teachers; // 모든 선생님 위치 정보
vector<pair<int, int> > spaces; // 모든 빈 공간 위치 정보

// 특정 방향으로 감시를 진행 (학생 발견: true, 학생 미발견: false)
bool watch(int x, int y, int direction) {
    // 왼쪽 방향으로 감시
    if (direction == 0) {
        while (y >= 0) {
            if (board[x][y] == 'S') { // 학생이 있는 경우
                return true;
            }
            if (board[x][y] == 'O') { // 장애물이 있는 경우
                return false;
            }
            y -= 1;
        }
    }
    // 오른쪽 방향으로 감시
    if (direction == 1) {
        while (y < n) {
            if (board[x][y] == 'S') { // 학생이 있는 경우
                return true;
            }
            if (board[x][y] == 'O') { // 장애물이 있는 경우
                return false;
            }
            y += 1;
        }
    }
    // 위쪽 방향으로 감시
    if (direction == 2) {
        while (x >= 0) {
            if (board[x][y] == 'S') { // 학생이 있는 경우
                return true;
            }
            if (board[x][y] == 'O') { // 장애물이 있는 경우
                return false;
            }
            x -= 1;
        }
    }
    // 아래쪽 방향으로 감시
    if (direction == 3) {
        while (x < n) {
            if (board[x][y] == 'S') { // 학생이 있는 경우
                return true;
            }
            if (board[x][y] == 'O') { // 장애물이 있는 경우
                return false;
            }
            x += 1;
        }
    }
    return false;
}

bool process()
{
    for (int i = 0; i < teachers.size(); i++) {
        int x = teachers[i].first;
        int y = teachers[i].second;

        for (int i = 0; i < 4; i++) {
            if (watch(x, y, i)) 
                return true;
        }
    }
    return false;
}

int main()
{
	cin >> n;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> board[i][j];
            if (board[i][j] == 'T') 
                teachers.push_back({ i, j });
            
            if (board[i][j] == 'X') 
                spaces.push_back({ i, j });
        }
    }

    // 빈 공간에서 3개를 뽑는 모든 조합을 확인
    vector<bool> binary(spaces.size());
    fill(binary.end() - 3, binary.end(), true);

    do {
        // 장애물들을 설치해보기
        for (int i = 0; i < spaces.size(); i++) {
            if (binary[i]) {
                int x = spaces[i].first;
                int y = spaces[i].second;
                board[x][y] = 'O';
            }
        }
        // 학생이 한 명도 감지되지 않는 경우
        if (!process()) {
            // 원하는 경우를 발견한 것임
            found = true;
            break;
        }

        // 설치된 장애물을 다시 없애기
        for (int i = 0; i < spaces.size(); i++) {
            if (binary[i]) {
                int x = spaces[i].first;
                int y = spaces[i].second;
                board[x][y] = 'X';
            }
        }
    } while (next_permutation(binary.begin(), binary.end()));

    if (found) 
        cout << "YES" << '\n';
    else 
        cout << "NO" << '\n';
}