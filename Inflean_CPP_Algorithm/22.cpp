#include <iostream>
using namespace std;

int arr[100000];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int sum = 0;
	for (int i = 0; i < k; ++i)
		sum += arr[i];

	int max_value = sum;
	for (int i = k; i < n; ++i)
	{
		sum = sum + (arr[i] - arr[i - k]);
		max_value = max(max_value, sum);
	}

	cout << max_value;
}

