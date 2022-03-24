#include <iostream>
#include <cstdlib>
using namespace std;

int arr[100];

int main()
{
	int n, pre;
	cin >> n;
	cin >> pre;

	for (int i = 1; i < n; ++i)
	{
		int now;
		cin >> now;

		int index = abs(pre - now);
		if (index > 0 && index < n && arr[index] == 0) arr[index] = 1;
		else
		{
			cout << "NO";
			return 0;
		}

		pre = now;
	}
	cout << "YES";
}