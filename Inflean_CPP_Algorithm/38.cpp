#include <iostream>
using namespace std;

int arr[101];
int result[101];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	int pos;
	for (int value = n; value >= 1; --value)
	{
		pos = value;
		for (int i = 1; i <= arr[value]; ++i)
		{
			result[pos] = result[pos + 1];
			pos++;
		}
		result[pos] = value;
	}

	for (int i = 1; i <= n; ++i)
		cout << result[i] << " ";
}
