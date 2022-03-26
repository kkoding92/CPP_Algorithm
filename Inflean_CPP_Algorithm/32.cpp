#include <iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
	{
		int min_index = i;
		for (int j = i+1; j < n; ++j)
		{
			if (arr[min_index] > arr[j])
				min_index = j;
		}

		swap(arr[i], arr[min_index]);
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}