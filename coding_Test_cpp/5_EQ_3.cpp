#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int start = 1; //최소 거리
	int end = v[n - 1] - v[0]; //최대 거리
	int result = 0;

	while (start <= end)
	{
		// mid는 가장 인접한 두 공유기 사이의 거리(gap)을 의미
		int gap = (start + end) / 2;
		// 첫째 집에는 무조건 공유기를 설치한다고 가정
		int value = v[0];
		int  cnt = 1;

		for (int i = 1; i < n; ++i)
		{
			if (v[i] >= value + gap)
			{
				value = v[i];
				cnt += 1;
			}
		}

		if (cnt >= c)
		{
			start = gap + 1;
			result = gap;
		}
		else
			end = gap - 1;
	}

	cout << result << '\n';
}