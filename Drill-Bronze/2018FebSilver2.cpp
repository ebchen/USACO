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
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int numberOfTiles;
	int numberOfBoots;
	vector<long long> tiles;
	queue<pair <long long, long long>> boots;
	int state = 0;

public:
	Solution()
	{
		ifstream fin("snowboots.in");
		fin >> numberOfTiles;
		fin >> numberOfBoots;
		for (int i = 0; i < numberOfTiles; i++)
		{
			long long tile;
			fin >> tile;
			tiles.push_back(tile);
		}
		for (int i = 0; i < numberOfBoots; i++)
		{
			long long depth;
			long long step;
			fin >> depth;
			fin >> step;
			pair<long long, long long> boot = { depth, step };
			boots.push(boot);
		}
	}

	void output()
	{
		long long bootCounter = 0;
		long long currentTile = 0;
		while (currentTile < numberOfTiles - 1)
		{
			for (int i = boots.front().second; i >= 0; i--)
			{
				if (i == 0)
				{
					boots.pop();
					bootCounter++;
				}
				while (currentTile + i >= numberOfTiles)
				{
					i--;
				}
				if (tiles[currentTile + i] <= boots.front().first)
				{
					currentTile = currentTile + i;
					break;
				}
			}
		}

		ofstream fout("snowboots.out");
		fout << bootCounter;
	}


};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/* 7 cases

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int numberOfTiles;
	int numberOfBoots;
	vector<int> tiles;
	queue<pair <int, int>> boots;
	int state = 0;

public:
	Solution()
	{
		ifstream fin("snowboots.in");
		fin >> numberOfTiles;
		fin >> numberOfBoots;
		for (int i = 0; i < numberOfTiles; i++)
		{
			int tile;
			fin >> tile;
			tiles.push_back(tile);
		}
		for (int i = 0; i < numberOfBoots; i++)
		{
			int depth;
			int step;
			fin >> depth;
			fin >> step;
			pair<int, int> boot = { depth, step };
			boots.push(boot);
		}
	}

	void output()
	{
		int bootCounter = 0;
		int currentTile = 0;
		while (currentTile < numberOfTiles - 1)
		{
			for (int i = boots.front().second; i >= 0; i--)
			{
				if (i == 0)
				{
					boots.pop();
					bootCounter++;
				}
				while (currentTile + i >= numberOfTiles)
				{
					i--;
				}
				if (tiles[currentTile + i] <= boots.front().first)
				{
					currentTile = currentTile + i;
					break;
				}
			}
		}

		ofstream fout("snowboots.out");
		fout << bootCounter;
	}


};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
*/