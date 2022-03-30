#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
	int n, k;
	cin >> n >> k;

	while (n > 0)
	{
		s.push(n % k);
		n /= k;
	}

	while (!s.empty())
	{
		if (k != 16)
		{
			cout << s.top();
			s.pop();
		}
		else
		{
			int temp = s.top();
			s.pop();

			if (temp >= 10)
			{
				char a = char(temp - 10 + 'A');
				cout << a;
			}
			else
				cout << temp;
		}
	}
}