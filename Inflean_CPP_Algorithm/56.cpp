#include <iostream>
using namespace std;

void Print_Number(int n)
{
	if (n == 1)
	{
		cout << 1 << " ";
		return;
	}

	Print_Number(n - 1);
	cout << n << " ";
}


int main()
{
	int n;
	cin >> n;

	Print_Number(n);
}