#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	string name;
	int score;

	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	// 정렬 기준은 '점수가 낮은 순서'
	bool operator <(Student& other)
	{
		return this->score < other.score;
	}
};

int main(void)
{
	int n;
	cin >> n;

	vector<Student> v;

	for (int i = 0; i < n; ++i)
	{
		string inputName;
		int inputScore;

		cin >> inputName >> inputScore;
		v.push_back(Student(inputName, inputScore));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		cout << v[i].name << ' ';
	}
}