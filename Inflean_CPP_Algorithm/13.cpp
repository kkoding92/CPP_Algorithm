#include <iostream>
#include <string>
using namespace std;

int arr[10];
string str;

int main()
{
	cin >> str;

	for(int i = 0; i < str.size(); ++i)
	{
		arr[((str[i]-'0')%10)] ++;
	}

	int max_index = 0;
	int max_value = 0;
	for (int i = 1; i < 10; ++i)
	{
		if (arr[i] >= max_value)
		{
			max_value = arr[i];
			max_index = i;
		}
	}

	cout << max_index;
}