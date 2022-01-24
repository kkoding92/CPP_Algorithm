#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<int> v;

bool binarySearch(vector<int>& v, int target, int start, int end)
{
	if (start > end) 
		return false;

	int mid = (start + end) / 2;

	if (v[mid] == target) 
		return true;
	else if (v[mid] > target) 
		return binarySearch(v, target, start, mid - 1);
	else 
		return binarySearch(v, target, mid + 1, end);
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin >> temp;

		string result = binarySearch(v, temp, 0, n - 1) ? "yes" : "no";
		cout << result << ' ';
	}
}
