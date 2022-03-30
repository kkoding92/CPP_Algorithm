#include <iostream>
using namespace std;

int arr[50][50];

int main()
{
	int h, w, myH, myW;
	cin >> h >> w;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> arr[i][j];

	cin >> myH >> myW;

	int maxValue = 0;

	for (int i = 0; i <= (h - myH); ++i)
	{
		for (int j = 0; j <= (w - myW); ++j)
		{
			int sum = 0;
			for (int k = i; k < (i + myH); ++k)
				for (int l = j; l < (j + myW); ++l)
					sum += arr[k][l];

			maxValue = max(maxValue, sum);
		}
	}

	cout << maxValue;
}