#include <iostream>
#include <string>

using namespace std;

int d[50][50];
int arr[50][50];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int x, y, dir;

void turn_left()
{
	dir -= 1;
	if (dir == -1)
		dir = 3;
}

int main(void)
{
	int row, col;
	cin >> row >> col;

	cin >> x >> y >> dir;
	d[x][y] = 1;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	int cnt = 1;
	int turn_cnt = 0;
	while (true)
	{
		turn_left();
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 아직 가보지 않은 칸이라면
		if (d[nx][ny] == 0 && arr[nx][ny] == 0)
		{
			d[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt += 1;
			turn_cnt = 0;
			continue;
		}
		else
			turn_cnt++;

		if (turn_cnt == 4)
		{
			int nx = x - dx[dir];
			int ny = y - dy[dir];

			if (arr[nx][ny] == 0)
			{
				x = nx;
				y = ny;
			}
			else
				break;

			turn_cnt = 0;
		}
	}

	cout << cnt << endl;
	return 0;
}