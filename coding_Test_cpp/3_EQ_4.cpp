#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int add, sub, mul, divi;

int minValue = 1e9;
int maxValue = -1e9;

void dfs(int i, int now)
{
	if (i == n)
	{
		minValue = min(minValue, now);
		maxValue = max(maxValue, now);
	}
	else
	{
		if (add > 0)
		{
			add -= 1;
			dfs(i+1, now + v[i]);
			add += 1;
		}
		if (sub > 0)
		{
			sub -= 1;
			dfs(i + 1, now - v[i]);
			sub += 1;
		}
		if (mul > 0)
		{
			mul -= 1;
			dfs(i + 1, now * v[i]);
			mul += 1;
		}
		if (divi > 0)
		{
			divi -= 1;
			dfs(i + 1, now / v[i]);
			divi += 1;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	cin >> add >> sub >> mul >> divi;

	// DFS 메서드 호출
	dfs(1, v[0]);

	// 최댓값과 최솟값 차례대로 출력
	cout << maxValue << '\n' << minValue << '\n';
}