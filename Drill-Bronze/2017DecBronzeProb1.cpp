/*
ID: echen
PROG:
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int firstX1, firstY1, firstX2, firstY2, secondX1, secondY1, secondX2, secondY2, truckX1, truckY1, truckX2, truckY2;

public:
	Solution()
	{
		ifstream fin("billboard.in");
		fin >> firstX1;
		fin >> firstY1;
		fin >> firstX2;
		fin >> firstY2;
		fin >> secondX1;
		fin >> secondY1;
		fin >> secondX2;
		fin >> secondY2;
		fin >> truckX1;
		fin >> truckY1;
		fin >> truckX2;
		fin >> truckY2;

		
	}

	void outputArea()
	{
		/*
		int firstArea = (firstX2 - firstX1) * (firstY2 - firstY1);
		int secondArea = (secondX2 - secondX1) * (secondY2 - secondY1);
		int truckArea = (truckX2 - truckX1) * (truckY2 - truckY1);
		int sum = firstArea + secondArea;

		if ((truckX1 >= firstX1) && (truckX1 <= firstX2) && (truckY1 >= firstY1) && (truckY1 <= firstY2))
		{
			sum = sum - truckArea;
		}

		else if ((truckX1 >= secondX1) && (truckX1 <= secondX2) && (truckY1 >= secondY1) && (truckY1 <= secondY2))
		{
			sum = sum - truckArea;
		}

		else if ()
		*/

		bool grid[2001][2001] = { false };

		for (int i = firstX1; i < firstX2; i++)
		{
			for (int j = firstY1; j < firstY2; j++)
			{
				grid[i+1000][j+1000] = true;
			}
		}

		for (int i = secondX1; i < secondX2; i++)
		{
			for (int j = secondY1; j < secondY2; j++)
			{
				grid[i+1000][j+1000] = true;
			}
		}

		for (int i = truckX1; i < truckX2; i++)
		{
			for (int j = truckY1; j < truckY2; j++)
			{
				grid[i+1000][j+1000] = false;
			}
		}

		int counter = 0;
		for (int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++)
		{
			for (int j = 0; j < sizeof(grid[i]) / sizeof(grid[i][j]); j++)
			{
				if (grid[i][j] == true)
					counter++;
			}
		}
		
		ofstream fout("billboard.out");
		fout << counter << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputArea();
	return 0;
}