#include <iostream>
using namespace std;

int arrA[10];
int arrB[10];

int main()
{
	for (int i = 0; i < 10; ++i)
		cin >> arrA[i];

	for (int i = 0; i < 10; ++i)
		cin >> arrB[i];

	int sumA = 0, sumB = 0;
	int flagLastWin = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (arrA[i] > arrB[i])
		{
			sumA += 3;
			flagLastWin = 0;
		}
		else if (arrA[i] == arrB[i])
		{
			sumA += 1;
			sumB += 1;
		}
		else if (arrA[i] < arrB[i])
		{
			sumB += 3;
			flagLastWin = 1;
		}
	}

	cout << sumA << " " << sumB << '\n';
	if (sumA > sumB)
		cout << "A";
	else if (sumA < sumB)
		cout << "B";
	else if (sumA == sumB)
	{
		if (flagLastWin == -1)
			cout << "D";
		else if (flagLastWin == 0)
			cout << "A";
		else if(flagLastWin == 1)
			cout << "B";
	}
}