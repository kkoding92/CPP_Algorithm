#include <iostream>

using namespace std;

int main()
{
	int n, k;
	int result = 0;

	cin >> n >> k;

    //1�� ���
    //while (true)
    //{
    //    if (n == 1)
    //        break;

    //    if (n % k == 0)
    //        n /= k;
    //    else
    //        n--;

    //    result++;
    //}

    //2�� ��� - N�� Ŀ�� ��� ��� 1�� ���� ���� �ð��� ���� �ɸ��⿡ 
    while (true) {
        // N�� K�� ������ �������� ���� �� �������� 1�� ����
        int target = (n / k) * k;
        result += (n - target);
        n = target;

        // N�� K���� ���� �� (�� �̻� ���� �� ���� ��) �ݺ��� Ż��
        if (n < k) 
            break;

        // K�� ������
        result += 1;
        n /= k;
    }

    // ���������� ���� ���� ���Ͽ� 1�� ����
    result += (n - 1);
    cout << result << '\n';

	return 0;
}