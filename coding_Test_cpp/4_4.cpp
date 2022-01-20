#include <iostream>
#define MAX_VALUE 9

using namespace std;

int n = 15;
int arr[15] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };

int main(void)
{
	int arrCount[MAX_VALUE + 1] = {};

	for (int i = 0; i < n; ++i)
		arrCount[arr[i]]++;

	for (int i = 0; i <= MAX_VALUE; ++i)
	{
		for (int j = 0; j < arrCount[i]; ++j)
			cout << i << ' ';
	}
}