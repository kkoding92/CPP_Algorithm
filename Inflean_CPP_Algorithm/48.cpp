#include <iostream>
#include <cmath>
using namespace std;

int arr[9][9];
int avg[9];

int main()
{
	int n = 9;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
			avg[i] += arr[i][j];
		}

		avg[i] = static_cast<int>(round((static_cast<float>(avg[i]) / 9.0f)));
	}

	for (int i = 0; i < n; ++i)
	{
		int min_dis = 987654321;
		int minValue = 0;

		for (int j = 0; j < n; ++j)
		{
			int temp = abs(avg[i] - arr[i][j]);
			if (min_dis > temp)
			{
				min_dis = temp;
				minValue = arr[i][j];
			}
			else if (min_dis == temp)
				minValue = max(arr[i][j], minValue);
		}

		cout << avg[i] << " " << minValue << '\n';
	}
}