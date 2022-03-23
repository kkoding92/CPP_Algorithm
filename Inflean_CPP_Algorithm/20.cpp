#include <iostream>
using namespace std;

int A[100];
int B[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> A[i];

	for (int i = 0; i < n; ++i)
		cin >> B[i];

	for (int i = 0; i < n; ++i)
	{
		if (A[i] == B[i])
			cout << "D" << '\n';
		else if ((A[i] == 1 && B[i] == 3) || (A[i] == 2 && B[i] == 1) || (A[i] == 3 && B[i] == 2))
			cout << "A" << '\n';
		else
			cout << "B" << '\n';
	}
}