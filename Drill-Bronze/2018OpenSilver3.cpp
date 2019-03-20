/*
ID: eric.ch2
PROG: PROGRAM_NAME
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <stack>          
#include <vector>        
#include <deque>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int N;
	vector<vector<int>> board;
	vector < vector<bool>> visited;

public:
	Solution()
	{
		ifstream fin;
		fin.open("multimoo.in");

		
		

		fin >> N;
		for (int i = 0; i < N; i++)
		{
			vector<int> row;
			for (int j = 0; j < N; j++)
			{
				int temp;
				fin >> temp;
				row.push_back(temp);
			}
			board.push_back(row);
		}

		for (int x = 0; x < N; x++)
		{
			vector<bool> row;
			for (int y = 0; y < N; y++)
			{
				row.push_back(false);
			}
			visited.push_back(row);
		}
		fin.close();
	}

	vector<pair<int, int>> findNeighbors(int row, int col, vector<vector<bool>> visitedTemp)
	{
		vector <pair <int, int>> neighbors;
		if (row - 1 >= 0 && visitedTemp[row-1][col] == false)
		{
			pair<int, int> north = { row - 1, col };
			neighbors.push_back(north);
		}

		if (row + 1 <= N - 1 && visitedTemp[row + 1][col] == false)
		{
			pair<int, int> south = { row + 1, col };
			neighbors.push_back(south);
		}

		if (col - 1 >= 0 && visitedTemp[row][col-1] == false)
		{
			pair<int, int> west = { row, col -1 };
			neighbors.push_back(west);
		}

		if (col + 1 <= N-1 && visitedTemp[row][col+1] == false)
		{
			pair<int, int> east = { row, col + 1 };
			neighbors.push_back(east);
		}

		return neighbors;

	}


	int regionSizeSingle(int row, int col)
	{
		int value = board[row][col];
		vector<vector<bool>> visitedTemp;
		for (int x = 0; x < N; x++)
		{
			vector<bool> row;
			for (int y = 0; y < N; y++)
			{
				row.push_back(false);
			}
			visitedTemp.push_back(row);
		}

		int size = 1;
		stack <pair<int, int>> s;
		pair <int, int> cell = { row,col };
		s.push(cell);
		while (!s.empty())
		{
			pair <int,int> cell1 = s.top();
			s.pop();

			if (visitedTemp[cell1.first][cell1.second] == true) continue;
			visitedTemp[cell1.first][cell1.second] = true;
			visited[cell1.first][cell1.second] = true;

			vector<pair<int, int>> listOfNeighbors = findNeighbors(cell1.first, cell1.second, visitedTemp);
			for (int i = 0; i < listOfNeighbors.size(); i++)
			{
				int rowN = listOfNeighbors[i].first;
				int colN = listOfNeighbors[i].second;
				if (board[cell1.first][cell1.second] == board[rowN][colN])
				{
					size++;
					pair <int, int> validNeighbor = listOfNeighbors[i];
					s.push(validNeighbor);
				}
			}
		}

		return size;
	}


	int maxSizeSingle()
	{
		int max = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					int temp = regionSizeSingle(i, j);
					if (temp > max) max = temp;
				}
			}
		}
		return max;
	}

	


	void print()
	{
		int x = maxSizeSingle();
		ofstream fout;
		fout.open("multimoo.out");
		fout << x << endl;
		fout << 2*x << endl;
		fout.close();
	}
	
	
};

int main()
{
	Solution solution;
	solution.print();
	return 0;
}