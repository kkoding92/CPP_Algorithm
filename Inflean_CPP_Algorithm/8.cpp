#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int size = str.size();
	stack<char> st;

	bool clear = true;

	for (int i = 0; i < size; ++i)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (st.empty())
			{
				clear = false;
				break;
			}
			st.pop();
		}
	}

	if (clear && st.empty())
		cout << "YES";
	else if(!clear || !st.empty())
		cout << "NO";
}
