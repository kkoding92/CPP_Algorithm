#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	// 한 번 계산된 결과를 저장하기 위한 DP 테이블 초기화
	vector<int> d(m + 1, 10001);

	d[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= m; ++j)
		{
			if (d[j - arr[i]] != 10001)
				d[j] = min(d[j], d[j - arr[i]] + 1);
		}
	}

	if (d[m] == 10001)
		cout << -1 << '\n';
	else
		cout << d[m] << "\n";
}