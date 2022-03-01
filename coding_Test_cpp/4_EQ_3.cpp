#include <iostream>
#include <queue>

using namespace std;

int n, result;
priority_queue<int> q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x; 
		cin >> x;
		q.push(-x);
	}

	while (q.size() != 1)
	{
		int one = -q.top();
		q.pop();
		int two = -q.top();
		q.pop();

		int temp = one + two;
		result += temp;
		q.push(-temp);
	}

	cout << result << '\n';
}