#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int aIndex = 0;
	int bIndex = 0;

	while (true)
	{
		if (a[aIndex] < b[bIndex])
			aIndex++;
		else if (a[aIndex] > b[bIndex])
			bIndex++;
		else
		{
			cout << a[aIndex] << " ";
			aIndex++;
			bIndex++;
		}

		if (aIndex >= n || bIndex >= m)
			break;
	}
}