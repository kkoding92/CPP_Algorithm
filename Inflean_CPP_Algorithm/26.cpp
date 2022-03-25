#include <iostream>
using namespace std;

int ran[1000];

int main()
{
	int n;
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = i; j >= 0; --j)
		{
			if (arr[j] >= arr[i])
				cnt = cnt + 1;
		}

		ran[i] = cnt;
	}

	for (int i = 0; i < n; ++i)
		cout << ran[i] << " ";
}
