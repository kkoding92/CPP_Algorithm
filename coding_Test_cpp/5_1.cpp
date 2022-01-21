#include <iostream>
using namespace std;

int n = 10;
int arr[10] = { 1, 4, 7, 16, 25, 57, 80, 92, 93, 100 };

int binarySearch(int* arr, int target, int start, int end)
{
	if (start > end) return -1;

	int mid = (start + end) / 2;

	if (arr[mid] == target) return mid;

	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);

	else return binarySearch(arr, target, mid + 1, end);
}

int main(void)
{
	int result = binarySearch(arr, 92, 0, n - 1);

	if (result == -1)
		cout << "원소가 존재하지 않습니다." << "\n";
	else
		cout << result + 1 << "\n";
}
