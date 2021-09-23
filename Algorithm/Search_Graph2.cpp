#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{

};

vector<Vertex> verties;
vector<vector<int>> adjacent;
//발견 여부
vector<bool> discovered;

void CreateGraph()
{
	verties.resize(6);

	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

	////인접 행렬
	//adjacent = vector<vector<int>>
	//{
	//	{0,1,0,1,0,0,},
	//	{1,0,1,1,0,0,},
	//	{0,0,0,0,0,0,},
	//	{0,0,0,0,1,0,},
	//	{0,0,0,0,0,0,},
	//	{0,0,0,0,1,0,},
	//};
}

void Bfs(int here)
{
	// 누구에 의해 발견 되었는지?
	vector<int> parent(6, -1);
	// 시작점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited : " << here << endl;

		for (int there : adjacent[here])
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}

		//for (int there = 0; there < 6; ++there)
		//{
		//	if (adjacent[here][there] == 0)
		//		continue;

		//	if (discovered[there])
		//		continue;

		//	q.push(there);
		//	discovered[there] = true;

		//	parent[there] = here;
		//	distance[there] = distance[here] + 1;
		//}
	}
}

int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);

	Bfs(0);
}