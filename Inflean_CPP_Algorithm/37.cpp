#include <iostream>
#include <list>
using namespace std;

int s, n;
list<int> l;

bool CheckChacheMiss(int x)
{
	for(auto iter : l)
	{ 
		if (iter == x)
		{
			l.remove(iter);
			l.push_front(x);
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> s >> n;
	

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		if (l.size() < s)
			l.push_front(x);
		else
		{
			if (!CheckChacheMiss(x))
			{
				l.pop_back();
				l.push_front(x);
			}
		}
	}
	for (auto iter : l)
		cout << iter << " ";
}