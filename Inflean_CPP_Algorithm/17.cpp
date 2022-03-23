#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		int sum = 0;
		for (int j = 1; j <= x; ++j)
			sum += j;

		if (sum == y)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}