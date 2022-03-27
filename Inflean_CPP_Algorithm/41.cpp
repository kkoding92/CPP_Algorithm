#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int temp = n;
	int cnt = 0, b = 1;

	temp--;
	while (temp > 0)
	{
		b++;
		temp = temp - b;
		if (temp % b == 0)
		{
			int i = 0;
			for (i = 1; i < b; ++i)
				cout << (temp / b) + i << " + ";

			cout << (temp / b) + i << " = " << n << '\n';
			cnt++;
		}
	}

	cout << cnt;
}