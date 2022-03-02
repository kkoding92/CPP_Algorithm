#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> v;

int binarySearch(vector<int>& v, int leftValue, int rightValue)
{
	auto rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	auto leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;
		v.push_back(value);
	}

	int cnt = binarySearch(v, x, x);

	if (cnt == 0)
		cout << -1 << '\n';
	else
		cout << cnt << '\n';
}
