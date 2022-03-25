#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int CIndex = 1, HIndex = 0;
	string CTemp = "", HTemp = "";
	bool flag = false;

	while (1)
	{
		if (str[CIndex] != 'H')
		{
			CTemp += str[CIndex];
			CIndex++;
		}
		else
		{
			if (CIndex == 1)
				CTemp = "1";

			CIndex++;
			break;
		}
	}

	HIndex = CIndex;
	while (1)
	{
		if (str[HIndex] != '\0')
		{
			HTemp += str[HIndex];
			HIndex++;
		}
		else
		{
			if (HIndex == CIndex)
				HTemp = "1";

			HIndex++;
			break;
		}
	}

	cout << 12 * stoi(CTemp) + stoi(HTemp);
}