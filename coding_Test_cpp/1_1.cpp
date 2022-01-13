#include <iostream>
using namespace std;

/*
* 거스름돈
* 당신은 음식점의 계산을 도와주는 점원이다. 카운터에는 거스름돈으로 사용할 500원, 100원, 50원, 10원짜리 동전이 무한히 존재한다.
* 손님에게 거슬러 줘야 할 돈이 N원일 때 거슬러줘야 할 동전의 최소 개수를 구하라.
* 예 ) N = 1260일 때,
*/

void main()
{
	int n = 1260;
	int ccnt = 0;

	int arr[4] = {500, 100, 50, 10};

	for (int i = 0; i < 4; ++i)
	{
		ccnt += n / arr[i];
		n %= arr[i];
	}

	cout << ccnt << endl;
}