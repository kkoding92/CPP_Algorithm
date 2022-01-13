#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int result = 0;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int min_value = 10001;

		for (int j = 0; j < m; ++j)
		{
			int value = 0;
			cin >> value;
			min_value = min(value, min_value);
		}

		result = max(result, min_value);
	}

	cout << result << endl;

	return 0;
}
