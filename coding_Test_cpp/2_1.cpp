#include <iostream>
#include <string>

using namespace std;

struct POINT
{
	int x, y;
};

POINT curPoint = { 1, 1 };

void main()
{
	int input;
	string plan;

	cin >> input;
	cin.ignore();
	getline(cin, plan);

	for (int i = 0; i < plan.size(); ++i)
	{
		POINT movePoint = { 0, 0 };
		POINT tempPoint;

		switch (plan[i])
		{
		case 'L':
			movePoint = { 0, -1 };
			break;
		case 'R':
			movePoint = { 0, 1 };
			break;
		case 'U':
			movePoint = { -1, 0 };
			break;
		case 'D':
			movePoint = { 1, 0 };
			break;
		}

		tempPoint.x = curPoint.x + movePoint.x;
		tempPoint.y = curPoint.y + movePoint.y;

		if (tempPoint.x < 1 || tempPoint.x > input || tempPoint.y < 1 || tempPoint.y > input)
			continue;

		curPoint.x = tempPoint.x;
		curPoint.y = tempPoint.y;
	}

	cout << curPoint.x << " " << curPoint.y << endl;
}
