#include <iostream>
using namespace std;

int n;

int main()
{
	int sum = 0;
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		int temp = i;
		while (temp > 0)
		{
			temp /= 10;
			sum += 1;
		}
	}

	cout << sum;
}