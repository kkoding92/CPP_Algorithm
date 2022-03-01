#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class Student
{
public:
	string name;
	int ko;
	int en;
	int math;

	Student(string name, int ko, int en, int math)
	{
		this->name = name;
		this->ko = ko;
		this->en = en;
		this->math = math;
	}

	bool operator < (Student& Other)
	{
		if (this->ko == Other.ko && this->en == Other.en && this->math == Other.math)
			return this->name < Other.name;
		if (this->ko == Other.ko && this->en == Other.en)
			return this->math > Other.math;
		if (this->ko == Other.ko)
			return this->en < Other.en;
		
		return this->ko > Other.ko;
	}
};

int n;
vector<Student> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		int ko, en, math;
		cin >> name >> ko >> en >> math;
		v.push_back(Student(name, ko, en, math));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].name << '\n';
}