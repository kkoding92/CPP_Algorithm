#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int d[100];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	d[0] = v[0];
	d[1] = max(v[0], v[1]);
	for (int i = 2; i < n; ++i)
		d[i] = max(d[i - 1], d[i - 2] + v[i]);

	cout << d[n - 1] << '\n';
}