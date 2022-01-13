#include <iostream>

using namespace std;

int main()
{
	int n, k;
	int result = 0;

	cin >> n >> k;

    while (true) {
        // N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
        int target = (n / k) * k;
        result += (n - target);
        n = target;

        // N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
        if (n < k) 
            break;

        // K로 나누기
        result += 1;
        n /= k;
    }

    // 마지막으로 남은 수에 대하여 1씩 빼기
    result += (n - 1);
    cout << result << '\n';

	return 0;
}