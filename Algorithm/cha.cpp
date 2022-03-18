#include <iostream>
using namespace std;

char firstchar(string str)
{
	char ch[26];
	char temp;

	fill_n(ch, 26, 0);

	int len = str.length();

	for (int i = 0; i < len; ++i)
	{
		temp = str[i];
		int index = temp - 'a';
		ch[index]++;
	}

	for (int i = 0; i < 26; ++i)
	{
		temp = str[i];
		int index = temp - 'a';

		if (ch[index] == 1)
			return temp;
	}

	return NULL;
}

int main()
{
	string str[] = { "niceee", "babbyddas", "a" };

	for (int i = 0; i < 3; ++i)
		cout << firstchar(str[i]) << endl;
}