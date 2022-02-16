#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getSum(vector<pair<int, int> > now)
{
	int result = 0;

	for (int i = 0; i < house.size(); ++i)
	{
		int temp = 1e9;

		for (int j = 0; j < now.size(); ++j)
		{
			int length = abs(house[i].first - now[j].first) + abs(house[i].second - now[j].second);
			temp = min(temp, length);
		}
		result += temp;
	}

	return result;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int x;
			cin >> x;
			if (x == 1)
				chicken.push_back({ i, j });
			else if (x == 2)
				house.push_back({ i, j });
		}
	}

	// ��� ġŲ �� �߿��� m���� ġŲ ���� �̴� ���� ���
	vector<bool> binary(chicken.size());
	fill(binary.end() - m, binary.end(), true);

	// ġŲ �Ÿ��� ���� �ּҸ� ã�� ���
	int result = 1e9;

	do {
		vector<pair<int, int> > now;
		for (int i = 0; i < chicken.size(); i++) {
			if (binary[i]) {
				int cx = chicken[i].first;
				int cy = chicken[i].second;
				now.push_back({ cx, cy });
			}
		}
		result = min(result, getSum(now));
		//������ ���ϴ� �Լ�(���� �ٸ� n���� ���ҿ��� r���� �̾� �� �ٷ� ����� ����� ��
	} while (next_permutation(binary.begin(), binary.end()));

	cout << result << '\n';
}