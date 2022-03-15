//진약수 : 자기 자신을 제외한 양의 약수
#include <iostream>
using namespace std;

int main()
{
	int n, sum = 1;
	cin >> n;

	cout << "1";
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			cout << " + " << i;
			sum = sum + i;
		}
	}

	cout << " = " << sum;
}