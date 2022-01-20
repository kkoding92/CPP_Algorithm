#include <iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void QuickSort(int* arr, int start, int end)
{
	// ���Ұ� 1���� ���
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		// �ǹ����� ū �����͸� ã�� ��
		while (left <= end && arr[left] <= arr[pivot]) left++;

		// �ǹ����� ���� �����͸� ã�� ��
		while (right > start && arr[right] >= arr[pivot]) right--;

		//�����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
		if (left > right) swap(arr[right], arr[pivot]);
		//�������� �ʾҴٸ� ���� �����Ϳ� ū ������ ��ü
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
