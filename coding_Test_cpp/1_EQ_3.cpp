#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int count0 = 0;
	int count1 = 0;

    // ù ��° ���ҿ� ���ؼ� ó��
    if (str[0] == '1') 
        count0 += 1;
    else 
        count1 += 1;
    
    // �� ��° ���Һ��� ��� ���Ҹ� Ȯ���ϸ�
    for (int i = 0; i < str.size() - 1; i++) 
    {
        if (str[i] != str[i + 1]) 
        {
            // ���� ������ 1�� �ٲ�� ���
            if (str[i + 1] == '1') count0 += 1;
            // ���� ������ 0���� �ٲ�� ���
            else count1 += 1;
        }
    }

	cout << min(count1, count0) << '\n';
}
