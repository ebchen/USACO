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
	vector <int> finalOrder;

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
			int id;
			fin >> id;
			finalOrder.push_back(id);
		}
	}

	void outputBeginningOrder()
	{
		vector<int> previous;
		for (int x = 0; x < finalOrder.size(); x++)
		{
			previous.push_back(finalOrder[x]);
		}

		for (int i = 0; i < 3; i++)
		{

			vector <int> prev;
			for (int z = 0; z < previous.size(); z++)
			{
				prev.push_back(0);
			}
			for (int j = 0; j < shuffle.size(); j++)
			{
				int whereItWent = shuffle[j] - 1;
				prev[j] =previous[whereItWent];
			}

			for (int y = 0; y < prev.size(); y++)
			{
				previous[y] = prev[y];
			}
		}

		ofstream fout("shuffle.out");
		for (int a = 0; a < previous.size(); a++)
		{
			fout << previous[a] << endl;
		}
	}
};

int main()
{
	Solution solution;
	solution.outputBeginningOrder();
	return 0;
}