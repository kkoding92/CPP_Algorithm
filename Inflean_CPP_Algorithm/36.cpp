#include <iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}