#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int count0 = 0;
	int count1 = 0;

    // 첫 번째 원소에 대해서 처리
    if (str[0] == '1') 
        count0 += 1;
    else 
        count1 += 1;
    
    // 두 번째 원소부터 모든 원소를 확인하며
    for (int i = 0; i < str.size() - 1; i++) 
    {
        if (str[i] != str[i + 1]) 
        {
            // 다음 수에서 1로 바뀌는 경우
            if (str[i + 1] == '1') count0 += 1;
            // 다음 수에서 0으로 바뀌는 경우
            else count1 += 1;
        }
    }

	cout << min(count1, count0) << '\n';
}
