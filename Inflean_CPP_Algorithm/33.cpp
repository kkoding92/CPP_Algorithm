#include <iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
	{
		int max_index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[max_index] < arr[j])
				max_index = j;
		}

		swap(arr[i], arr[max_index]);
	}

	int cur_grade = 1;
	int cur_value = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (cur_value != arr[i])
		{
			cur_grade++;
			cur_value = arr[i];
		}

		if (cur_grade == 3)
		{
			cout << cur_value;
			break;
		}
	}

}