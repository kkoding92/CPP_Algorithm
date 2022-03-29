#include <iostream>
using namespace std;

int result[10][10];
int frontArr[10];
int rightArr[10];


int main()
{
	int n;
	cin >> n;

	for (int j = 0; j < n; ++j)
		cin >> frontArr[j];
	for (int j = n-1; j >= 0; --j)
		cin >> rightArr[j];


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			result[j][i] = frontArr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (result[i][j] > rightArr[i])
				result[i][j] = rightArr[i];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cnt += result[i][j];

	cout << cnt;
}