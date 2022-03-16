#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[50001];

	fill_n(arr, 50001, 1);

	for (int i = 2; i <= n; ++i)
	{
		for (int j = i; j <= n; j = j+i)
		{
			arr[j] = arr[j] + 1;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << " ";
}

