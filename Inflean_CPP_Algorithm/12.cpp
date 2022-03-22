#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0, c = 1, d = 9, res = 0;
	cin >> n;

	while (sum + d < n)
	{
		res = res + (c * d);
		sum = sum + d;
		c = c + 1;
		d = d * 10;
	}

	res = res + ((n - sum) * c);
	cout << res; 
}
