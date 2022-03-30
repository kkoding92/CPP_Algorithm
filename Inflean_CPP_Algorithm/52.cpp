#include <iostream>
using namespace std;

int arr[1501];

int main()
{
	int n, pt2, pt3, pt5;
	cin >> n;

	arr[1] = 1;
	pt2 = pt3 = pt5 = 1;

	int min = 987654321;
	for (int i = 2; i <= n; ++i)
	{
		if (arr[pt2] * 2 < arr[pt3] * 3) min = arr[pt2] * 2;
		else min = arr[pt3] * 3;

		if (arr[pt5] * 5 < min) min = arr[pt5] * 5;
		
		if (arr[pt2] * 2 == min) pt2++;
		if (arr[pt3] * 3 == min) pt3++;
		if (arr[pt5] * 5 == min) pt5++;
		arr[i] = min;
	}

	cout << arr[n];
}