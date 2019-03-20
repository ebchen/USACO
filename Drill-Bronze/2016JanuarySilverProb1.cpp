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
#include <algorithm>
using namespace std;

class Solution
{
private:
	int numberOfBales;
	int numberOfShots;
	int lastPosition;
	int maxRadius;
	vector<int> field;

public:
	Solution()
	{
		ifstream fin("angry.in");
		fin >> numberOfBales;
		fin >> numberOfShots;
		for (int i = 0; i < numberOfBales; i++)
		{
			int balePosition;
			fin >> balePosition;
			field.push_back(balePosition);
		}
		sort(field.begin(), field.end());
		lastPosition = field[field.size() - 1];
		maxRadius = (lastPosition + 1)/ 2;
	}

	void findR()
	{
		int radius;
		for (int r = 0; r < maxRadius; r++)
		{
			int numberExploded = 0;
			bool allExploded = false;
			int counter = 0;
			int kCounter = 0;
			while (!allExploded)
			{
				for (int i = counter; counter < )
				int leftBound = field[counter];
				int rightBound = field[counter] + 2 * r;

				kCounter++;
				counter = rightBound + 1;
			}
		}
	}
};

int main()
{
	Solution solution;
	return 0;
}