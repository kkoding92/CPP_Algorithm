#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int result = 0; // �� �׷��� ��
	int count = 0; // ���� �׷쿡 ���Ե� ���谡�� ��

	for (int i = 0; i < n; i++) { // �������� ���� �ͺ��� �ϳ��� Ȯ���ϸ�
		count += 1; // ���� �׷쿡 �ش� ���谡�� ���Խ�Ű��
		if (count >= arr[i]) { // ���� �׷쿡 ���Ե� ���谡�� ���� ������ ������ �̻��̶��, �׷� �Ἲ
			result += 1; // �� �׷��� �� ������Ű��
			count = 0; // ���� �׷쿡 ���Ե� ���谡�� �� �ʱ�ȭ
		}
	}

	cout << result << '\n';
}