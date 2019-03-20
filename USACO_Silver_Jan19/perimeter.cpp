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
char grid[1001][1001];
bool visited[1001][1001];
int maxSize = 0;
int minPerimeterOfMaxSize = INT_MAX;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	visited[x][y] = 1;
	q.push({ x,y });
	int count = 1;
	int perimeter = 0;

	while (!q.empty())
	{
		pair<int, int> next = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newX = next.first + dx[i];
			int newY = next.second + dy[i];
			if (newX < 0 || newX >= N || newY < 0 || newY >= N)
			{
				perimeter++;
				continue;
			}
			if (visited[newX][newY] == 0 && grid[newX][newY] == '#')
			{
				visited[newX][newY] = 1;
				count++;
				q.push({ newX,newY });
			}
			else if (grid[newX][newY] == '.')
			{
				perimeter++;
			}
		}
	}
	if (count > maxSize)
	{
		maxSize = count;
		minPerimeterOfMaxSize = perimeter;
	}
	else if (count == maxSize)
	{
		minPerimeterOfMaxSize = min(perimeter, minPerimeterOfMaxSize);
	}
}
int main()
{
	ifstream fin("perimeter.in");
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		string row;
		fin >> row;
		for (int j = 0; j < N; j++)
		{
			grid[i][j] = row[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false && grid[i][j] == '#') bfs(i, j);
		}
	}
	ofstream fout("perimeter.out");
	fout << maxSize << " " << minPerimeterOfMaxSize << endl;
	return 0;
}