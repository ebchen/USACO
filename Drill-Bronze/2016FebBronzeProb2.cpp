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
	int numberOfRooms;
	vector<int>rooms;
public:
	Solution()
	{
		ifstream fin("cbarn.in");
		int room;
		fin >> numberOfRooms;
		for (int i = 0; i < numberOfRooms; i++)
		{
			fin >> room;
			rooms.push_back(room);
		}
	}

	void outputMinimum()
	{
		int minimum = 100000000;
		for (int i = 0; i < rooms.size(); i++)
		{
			int counter;
			if (i == rooms.size() - 1)
			{
				counter = 0;
			}
			else
			{
				counter = i + 1;
			}
			
			int sum = 0;
			while (counter != i)
			{
				int total;
				if (counter < i)
				{
					total = (rooms.size() - i + counter) * rooms[counter];
				}
				else total = (counter - i) * rooms[counter];
				sum += total;
				if (counter == rooms.size() - 1)
				{
					counter = 0;
				}
				else
					counter++;
			}

			if (sum < minimum)
			{
				minimum = sum;
			}
		}

		ofstream fout("cbarn.out");
		fout << minimum;
	}
};

int main()
{
	Solution solution;
	solution.outputMinimum();
	return 0;
}