#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;

	vector<char> result;
	int curValue = 1;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		s.push(x);
		result.push_back('P');
		while (1)
		{
			if (s.empty()) break;
			if (curValue == s.top())
			{
				curValue++;
				s.pop();
				result.push_back('O');
			}
			else
				break;
		}
	}

	if (!s.empty()) cout << "impossible";
	else
	{
		for (int i = 0; i < result.size(); ++i)
			cout << result[i];
	}
}