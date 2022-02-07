#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> coin;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}

	sort(coin.begin(), coin.end());

	int target = 1;
	for (int i = 0; i < n; ++i)
	{
		if (target < coin[i])
			break;

		target += coin[i];
	}
	
	cout << target << '\n';
}