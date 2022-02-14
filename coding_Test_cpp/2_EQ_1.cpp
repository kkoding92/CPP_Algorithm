#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	int summary = 0;
	cin >> s;

	for (int i = 0; i < s.size() / 2; ++i)
		summary += s[i] - '0';

	for (int i = s.size() / 2; i < s.size(); ++i)
		summary -= s[i] - '0';

	if (summary == 0)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';
}
