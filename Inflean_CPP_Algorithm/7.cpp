#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int size = str.size();
	
	for (int i = 0; i < size; ++i)
	{
		if (str[i] != ' ')
		{
			str[i] = tolower(str[i]);
			cout << str[i];
		}
	}
}

