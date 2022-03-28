#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int>& arr, int start, int end, int target)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return BinarySearch(arr, start, mid - 1, target);
	else BinarySearch(arr, mid +1, end, target);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	cout << BinarySearch(v, 0, n - 1, m) + 1;
}