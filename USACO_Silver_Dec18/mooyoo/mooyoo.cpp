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

class Solution
{
public:
	int minSize;
	int height;
	vector<vector<char>> board;
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };
	Solution()
	{
		ifstream fin("mooyomooyo.in");
		fin >> height;
		fin >> minSize;

		for (int i = 0; i < height; i++)
		{
			string row;
			fin >> row;
			vector<char> r;
			for (int j = 0; j < 10; j++)
			{
				r.push_back(row[j]);
			}
			board.push_back(r);
		}
	}

	void output()
	{
		bool cont = true;
		for (int a = 0 ; a < 1000; a++)
		{
			vector<vector<int>> visited; // 0 not visited, 1 visited but not falling, 2 falling
			for (int i = 0; i < height; i++)
			{
				vector<int> r;
				r.resize(10);
				visited.push_back(r);
			}
			bool once = false;
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < 10; j++) {
					if (visited[i][j] == 0 && board[i][j] != '0')
					{
						if (bfs(i, j, board[i][j], visited)) once = true;
					}
				}
			}
			if (!once)
			{
				break;
			}

			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < 10; j++) {
					if (visited[i][j] == 2)
					{
						board[i][j] = '0';
					}
				}
			}
			for (int a = 0; a < height; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					if (a == 4 && b == 0) cout << "*";
					else cout << visited[a][b];
				}
				cout << endl;
			}
			//moving it down
			for (int i = board.size() - 1; i >= 0; i--) {
				for (int j = 0; j < 10; j++) {
					if (board[i][j] == '0')
					{
						int lowestNonZero = -1;
						for (int k = i-1; k >= 0; k--)
						{
							if (k == -1) break;
							if (board[k][j] != '0')
							{
								lowestNonZero = k;
								break;
							}
						}
						if (lowestNonZero != -1)
						{
							board[i][j] = board[lowestNonZero][j];
							board[lowestNonZero][j] = '0';
						}
					}
				}
			}

			cout << endl;
			for (int a = 0; a < height; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			
		}
		ofstream fout("mooyomooyo.out");
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fout << board[i][j];
			}
			fout << endl;
		}
	}
	bool bfs(int x, int y, char type, vector<vector<int>>& visited)
	{
		queue<pair<int,int>> q;
		vector<pair<int, int>> hit;
		visited[x][y] = 1;
		q.push({ x,y });
		hit.push_back({ x,y });
		int count = 1;

		while (!q.empty())
		{
			pair<int,int> next = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int newX = next.first + dx[i];
				int newY = next.second + dy[i];
				if (newX < 0 || newX >= height || newY < 0 || newY >= 10) continue;
				if (visited[newX][newY] == 0 && board[newX][newY] == type)
				{
					visited[newX][newY] = 1;
					hit.push_back({ newX, newY });
					count++;
					q.push({ newX,newY });
				}
			}
		}
		if (count >= minSize)
		{
			for (int i = 0; i < hit.size(); i++)
			{
				visited[hit[i].first][ hit[i].second] = 2;
			}
			return true;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}