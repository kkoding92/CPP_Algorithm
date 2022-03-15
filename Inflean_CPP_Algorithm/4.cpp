#include <iostream>
using namespace std;

int main()
{
	int n, maxValue = 0, minValue = 9e1;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		if (x < minValue)
			minValue = x;
		if (x > maxValue)
			maxValue = x;
	}

	cout << maxValue - minValue;
}