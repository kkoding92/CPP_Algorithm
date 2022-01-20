#include <iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void QuickSort(int* arr, int start, int end)
{
	// 원소가 1개인 경우
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		// 피벗보다 큰 데이터를 찾을 때
		while (left <= end && arr[left] <= arr[pivot]) left++;

		// 피벗보다 작은 데이터를 찾을 때
		while (right > start && arr[right] >= arr[pivot]) right--;

		//엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) swap(arr[right], arr[pivot]);
		//엇갈리지 않았다면 작은 데이터와 큰 데이터 교체
		else swap(arr[right], arr[left]);
	}

	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);
}

int main(void)
{
	QuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}
