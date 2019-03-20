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
	int entries;
	int gallons;
	vector <vector<int>> logbook;
	vector <int> amounts;
public:
	Solution()
	{
		ifstream fin("measurement.in");
		fin >> entries;
		fin >> gallons;
		for (int i = 0; i < entries; i++)
		{
			vector <int> logEntry;
			int day;
			int cowID;
			int change;
			fin >> day;
			fin >> cowID;
			fin >> change;

	
			logEntry.push_back(day);
			logEntry.push_back(cowID);
			logEntry.push_back(change);

			logbook.push_back(logEntry);
		}

		for (int i = 0; i < 1000000000; i++)
		{
			amounts.push_back(gallons);
		}
		

	}

	void outputChanges()
	{
		int changes = 0;
		vector<int>leaders;
		for (int i = 0; i < 100000000; i++)
		{
			leaders.push_back(i);
		}
		vector<int>newLeaders;						
		for (int i = 1; i <= 1000000; i++)				
		{
			for (int j = 0; j < logbook.size(); j++)	
			{
				if (logbook[j][0] == i)	
				{
					amounts[logbook[j][1]] += logbook[j][2];
				}

			}

			
			int max = -1000000000;
			for (int j = 0; j < amounts.size(); j++)	
			{
				if (amounts[j] > max)
				{
					max = amounts[j];
				}
			}

			newLeaders.erase(newLeaders.begin(), newLeaders.begin() + newLeaders.size());

			for (int j = 0; j < amounts.size(); j++)		
			{
				if (amounts[j] == max)
				{
					newLeaders.push_back(j);
				}
			}

			if (leaders.size() != newLeaders.size())
			{
				changes++;
			}
			else
			{
				for (int m = 0; m < leaders.size(); m++)
				{
					if (leaders[m] != newLeaders[m])
					{
						changes++;
						break;
					}
				}
			}

			leaders.erase(leaders.begin(), leaders.begin() + leaders.size());
			for (int n = 0; n < newLeaders.size(); n++)
			{
				leaders.push_back(newLeaders[n]);
			}

		}

		ofstream fout("measurement.out");
		fout << changes << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputChanges();
	return 0;
}