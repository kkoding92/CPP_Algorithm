#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	// 첫 번째 문자를 숫자로 변경한 값을 대입
	long long result = s[0] - '0';

	for (int i = 1; i < s.length(); i++)
	{
		int num = s[i] - '0';

		if (result <= 1 || num <= 1)
			result += num;
		else
			result *= num;
	}

	cout << result << '\n';
}
