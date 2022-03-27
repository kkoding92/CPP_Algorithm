#include <iostream>
using namespace std;

int arrA[100];
int arrB[100];
int result[200];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arrA[i];

	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> arrB[i];

	int curIndex = 0;
	int curAIndex = 0;
	int curBIndex = 0;

	while (curIndex < n + m)
	{
		if (curAIndex < n && curBIndex < m)
		{
			if (arrA[curAIndex] <= arrB[curBIndex])
			{
				result[curIndex] = arrA[curAIndex];
				curAIndex++;
			}
			else
			{
				result[curIndex] = arrB[curBIndex];
				curBIndex++;
			}

			curIndex++;
		}
		else
		{
			if (curAIndex >= n)
			{
				result[curIndex] = arrB[curBIndex];
				curBIndex++;

				curIndex++;
			}
			else if (curBIndex >= m)
			{
				result[curIndex] = arrA[curAIndex];
				curAIndex++;

				curIndex++;
			}
		}
	}

	for (int i = 0; i < n + m; ++i)
		cout << result[i] << " ";
}