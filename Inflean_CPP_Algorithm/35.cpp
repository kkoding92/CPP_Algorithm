#include <iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > 0 && arr[j + 1] < 0)
				swap(arr[j], arr[j+1]);
		}
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}