#include <vector>
#include <fstream>
#include <math.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;
int N;
vector<int> adj[1000001];
int current = 0;
vector<int> type;

void bfs(int start)
{
	bool visited[100001];
	int before[100001];
	int distance;
	for (int i = 0; i < N; i++)
		visited[i] = false;

	queue<int> q;

	visited[start] = true;
	q.push(start);

	int x;
	int count = 1;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (!visited[adj[x][i]])
			{
				visited[adj[x][i]] = true;
				q.push(adj[x][i]);
			}
		}
	}
}
int main()
{
	ifstream fin("planting.in");
	fin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int x, y;
		fin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	type.resize(N);
	fill(type.begin(), type.end(), 0);

	int maxVal = 0;

	for (int i = 0; i < N; i++)
	{
		int val = type[i];
		bool visited[100001] = { false };
		visited[i] = true;
		for (int j = 0; j < adj[i].size(); j++)
		{
			int adjacent = adj[i][j];
			visited[adjacent] = true;
			if (type[adjacent] == val)
			{
				type[adjacent] = val + 1;
				if (val + 1 > maxVal) maxVal = val + 1;
			}
			for (int k = 0; k < adj[adjacent].size(); k++)
			{
				int adjToAdjacent = adj[adjacent][k];
				if (visited[adjToAdjacent]) continue;
				else
				{
					if (type[adjToAdjacent] == val)
					{
						type[adjToAdjacent] = val + 1;
						if (val + 1 > maxVal) maxVal = val + 1;
					}
				}
			}
		}
		
	}

	ofstream fout("planting.out");
	fout << maxVal + 1 << endl;
	return	0;
}