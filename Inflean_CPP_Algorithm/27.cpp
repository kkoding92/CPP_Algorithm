#include <iostream>
using namespace std;

int check[1001];

int main()
{
	int n, temp, j;
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		temp = i;
		j = 2;
		while (1)
		{
			if (temp % j == 0)
			{
				temp = temp / j;
				check[j]++;
			}
			else
				j++;
			if (temp == 1) break;
		}
	}

	cout << n << "! = ";
	for (int i = 2; i <= n; ++i)
	{
		if (check[i] != 0)
			cout << check[i] << " ";
	}

}