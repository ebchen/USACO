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
	int numberOfCows;
	vector<int> ids;
public:
	Solution()
	{
		ifstream fin("div7.in");
		fin >> numberOfCows;
		for (int i = 0; i < numberOfCows; i++)
		{
			int id;
			fin >> id;
			ids.push_back(id);
		}
	}
	
	void outputMax()
	{
		int maxSize = 0;
		for (int startingPoint = 0; startingPoint < numberOfCows; startingPoint++)
		{
			long long sum = 0;
			int size = 0;
			for (int numberOfIncrease = 0; numberOfIncrease < numberOfCows - startingPoint; numberOfIncrease++)
			{
				sum += ids[startingPoint + numberOfIncrease];
				size++;
				if (sum % 7 == 0)
				{
					if (size > maxSize) maxSize = size;
				}
				else if (sum == 0 && size > 0)
				{
				}
			}
		}

		ofstream fout("div7.out");
		cout << maxSize;
		fout << maxSize;
	}
};

int main()
{
	Solution solution;
	solution.outputMax();
	return 0;
}