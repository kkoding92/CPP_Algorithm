#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[100];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int max = arr[n - 1];
	int cnt = 0;
	for (int i = n - 2; i >= 0; --i)
	{
		if (max < arr[i])
		{
			max = arr[i];
			cnt++;
		}
	}

	cout << cnt;
}