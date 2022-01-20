#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> a, b;

	for (int j = 0; j < n; ++j)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int j = 0; j < n; ++j)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < k; ++i)
	{
		if (a[i] < b[i])
			swap(a[i], b[i]);
		else
			break;
	}

	int sum = 0;
	for (int j = 0; j < n; ++j)
		sum += a[j];

	cout << sum << "\n";
}