#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Virus
{
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y)
	{
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;
	}

	bool operator < (Virus& other) {
		return this->second < other.second;
	}
};

vector<Virus> v;

int n, k, s, x, y;
int arr[200][200];

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] != 0)
				v.push_back(Virus(arr[i][j], 0, i, j));
		}
	}

	sort(v.begin(), v.end());
	queue<Virus> q;
	for (int i = 0; i < v.size(); ++i)
		q.push(v[i]);

	cin >> s >> x >> y;

	while (!q.empty())
	{
		Virus curVirus = q.front();
		q.pop();

		if (curVirus.second == s) break;

		for (int i = 0; i < 4; ++i)
		{
			int nx = curVirus.x + dx[i];
			int ny = curVirus.y + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) 
			{
				if (arr[nx][ny] == 0)
				{
					arr[nx][ny] = curVirus.index;
					q.push(Virus(curVirus.index, curVirus.second + 1, nx, ny));
				}
			}
		}
	}

	cout << arr[x][y] << '\n';
}