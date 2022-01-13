#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void main()
{
	vector<int> value;
	int N, M, K;
	int result = 0;

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		int temp = 0;
		cin >> temp;
		value.push_back(temp);
	}

	sort(value.begin(), value.end());
	int iFirst = value[N - 1];
	int iSecond = value[N - 2];


	////1锅 规过
	//for (int i = 1; i <= M; ++i)
	//{
	//	if(i % K == 0)
	//		result += iSecond;
	//	else
	//		result += iFirst;
	//}

	//cout << result << endl;


	//2锅 规过
	int firstCalCnt = int(M / (K + 1)) * K;
	firstCalCnt += M % (K + 1);

	result += firstCalCnt * iFirst;
	result += (M - firstCalCnt) * iSecond;

	cout << result << endl;
}
