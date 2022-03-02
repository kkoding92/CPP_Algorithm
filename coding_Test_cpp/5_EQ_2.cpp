#include <iostream>
using namespace std;

int n;
int arr[1000000];

int binary_search(int* arr, int start, int end)
{
	if (start > end) return -1;

	int mid = (start + end) / 2;
	if (arr[mid] == mid)
		return mid;
	else if (arr[mid] > mid) return binary_search(arr, start, mid - 1);
	else return binary_search(arr, mid + 1, end);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int index = binary_search(arr, 0, n - 1);
	cout << index << '\n';
}
