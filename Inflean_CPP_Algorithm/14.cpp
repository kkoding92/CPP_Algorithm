#include <iostream>
using namespace std;

bool isPrime(int x)
{
	if (x == 1) return false;

	bool flag = true;
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			flag = false;
			break;
		}
	}

	return flag;
}

int reverse(int x)
{
	int temp = x;
	int result = 0;

	while (temp > 0)
	{
		result *= 10;
		result += (temp % 10);
		temp /= 10;
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		x = reverse(x);

		if (isPrime(x))
			cout << x << " ";
	}
}