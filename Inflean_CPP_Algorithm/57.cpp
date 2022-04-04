#include <iostream>
using namespace std;

void Binary(int value)
{
	if (value < 1)
		return;

	Binary(value / 2);
	int temp = value % 2;
	cout << temp;
}

int main()
{
	int n;
	cin >> n;

	Binary(n);
}