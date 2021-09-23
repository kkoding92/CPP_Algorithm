#include <iostream>
#include <Windows.h>
using namespace std;

int cache[50][50];

int combination(int n, int r)
{
	//���� ���
	if (r == 0 || n == r)
		return 1;

	//�̹� ���� ������ ������ �ٷ� ��ȯ
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
	__int64 start = GetTickCount64();

	int lotto = combination(45, 6);

	__int64 end = GetTickCount64();

	cout << end - start << " ms" << endl;
}