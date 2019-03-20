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
	vector <vector<int>> logbook;
	vector <string> namesToNumbers;
	vector <int> amounts;
public:
	Solution()
	{
		ifstream fin("measurement.in");
		fin >> entries;

		for (int i = 0; i < entries; i++)
		{
			vector <int> logEntry;
			int day;
			string name;
			int nameToNumber;
			int change;
			fin >> day;
			fin >> name;
			fin >> change;

			bool found = false;
			int index = -1;
			for (int j = 0; j < namesToNumbers.size(); j++)
			{
				if (namesToNumbers[j] == name)
				{
					found = true;
					index = j;
				}
			}
			if (found == true)
			{
				nameToNumber = index;
			}
			else
			{
				nameToNumber = namesToNumbers.size();
				namesToNumbers.push_back(name);
			}

			logEntry.push_back(day);
			logEntry.push_back(nameToNumber);
			logEntry.push_back(change);

			logbook.push_back(logEntry);
		}

		for (int i = 0; i < 3; i++)
		{
			amounts.push_back(7);
		}
		/*
		for (int i = 0; i < logbook.size(); i++)
		{
			for (int j = 0; j < logbook[i].size(); j++)
			{
				cout << logbook[i][j] << "  ";
			}
			cout << endl;
		}*/
		
	}

	void outputChanges()
	{
		int changes = 0;
		int currentLeaderOutput = -1;
		vector<int>leaders{ 0,1,2 };					//holds the leader
		vector<int> newLeaders;				//holds the leaders for each loop, comapred to leaders
		for (int i = 1; i <= 100; i++)		//loops through each day
		{
			for (int j = 0; j < logbook.size(); j++)	//loops throught logbook
			{
				if (logbook[j][0] == i)		//checks to see if it is an entry for the day
				{
					amounts[logbook[j][1]] += logbook[j][2];	//if the days match, implements the change;
				}

			}

			/*
			finds the new leaders
			*/
			int max = -1000000000;
			for (int j = 0; j < amounts.size(); j++)		//finds the largestCurrentOutput
			{
				if (amounts[j] > max)
				{
					max = amounts[j];
				}
			}
			currentLeaderOutput = max;			
			
			newLeaders.erase(newLeaders.begin(), newLeaders.begin() + newLeaders.size()); // deletes everything in newLeaders

			for (int j = 0; j < amounts.size(); j++)		//loops through the amounts to see which cows are leaders
			{
				if (amounts[j] == currentLeaderOutput)
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
		fout << changes  << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputChanges();
	return 0;
}