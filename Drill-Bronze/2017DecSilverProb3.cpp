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
	int numberOfCows;
	vector<int> shuffle;
	vector<vector<int>> isReferencedBy;

public:
	Solution()
	{
		ifstream fin("shuffle.in");
		fin >> numberOfCows;
		for (int i = 0; i < numberOfCows; i++)
		{
			int position;
			fin >> position;
			shuffle.push_back(position);
		}
		for (int i = 0; i < numberOfCows; i++)
		{
			vector<int> v;
			isReferencedBy.push_back(v);
		}
		for (int i = 0; i < numberOfCows; i++)
		{
			isReferencedBy[shuffle[i]-1].push_back(i);
		}
	}

	bool isReferenced(int index)
	{
		if (isReferencedBy[index].size() == 0) return false;
		for (int i = 0; i < isReferencedBy[index].size(); i++)
		{

		}
	}
	void outputNumberOfPositionsWithCows()
	{
		for (int i = 0; i < isReferencedBy.size(); i++)
		{
			for (int j = 0; j < isReferencedBy[i].size(); j++)
			{
				isReferencedBy[i][j]
			}
		}

		int counter = 0;
		for (int i = 0; i < isReferencedBy.size(); i++)
		{
			if (isReferencedBy[i].size() != 0)
				counter++;
		}

		ofstream fout("shuffle.out");
		fout << counter << endl;

	}
};

int main()
{
	Solution solution;
	solution.outputNumberOfPositionsWithCows();
	return 0;
}