#include <iostream>
using namespace std;

int arr[50][50];

int dx[4] = {1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int curH = arr[i][j];
			bool flag = true;

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				if (curH <= arr[nx][ny])
					flag = false;
			}

			if (flag)
				cnt++;
		}
	}

	cout << cnt;
}