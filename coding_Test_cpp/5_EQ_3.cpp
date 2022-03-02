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

	int start = 1; //�ּ� �Ÿ�
	int end = v[n - 1] - v[0]; //�ִ� �Ÿ�
	int result = 0;

	while (start <= end)
	{
		// mid�� ���� ������ �� ������ ������ �Ÿ�(gap)�� �ǹ�
		int gap = (start + end) / 2;
		// ù° ������ ������ �����⸦ ��ġ�Ѵٰ� ����
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