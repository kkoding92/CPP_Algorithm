#include <iostream>
using namespace std;

int digit_sum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum = sum + (x % 10);
		x = x / 10;
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;

	int maxDigit = 0;
	int maxValue = 0;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		int digitSum = digit_sum(x);
		if (maxDigit == digitSum)
		{
			if (maxValue > x)
				maxValue = maxValue;
			else
				maxValue = x;
		}
		else
		{
			if (maxDigit < digitSum)
			{
				maxDigit = digitSum;
				maxValue = x;
			}
		}
	}

	cout << maxValue;
}

