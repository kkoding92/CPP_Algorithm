#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int board[101][101];

vector<pair<int, char>> path;

// µ¿, ³², ¼­, ºÏ
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int Turn(int dir, char c)
{
	if (c == 'L')
		dir = (dir == 0) ? 3 : dir - 1;
	else
		dir = (dir + 1) % 4;

	return dir;
}

int Simulation()
{
	int x = 1, y = 1;
	board[x][y] = 2;
	int dir = 0;
	int timer = 0;
	int index = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && board[nx][ny] != 2)
		{
			if (board[nx][ny] == 0)
			{
				board[nx][ny] = 2;
				q.push({ nx, ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				board[px][py] = 0;
			}

			if (board[nx][ny] == 1)
			{
				board[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
		else
		{
			timer += 1;
			break;
		}

		x = nx;
		y = ny;
		timer += 1;

		if (index < l && timer == path[index].first)
		{
			dir = Turn(dir, path[index].second);
			index += 1;
		}
	}

	return timer;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		int x;
		char c;
		cin >> x >> c;
		path.push_back({ x, c });
	}

	cout << Simulation() << '\n';
}