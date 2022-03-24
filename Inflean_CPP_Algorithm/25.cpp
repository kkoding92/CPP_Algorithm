#include <iostream>
using namespace std;

int a[100], b[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i] < a[j])
				b[i]++;
		}
	}

	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
}